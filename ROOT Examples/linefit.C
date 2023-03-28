// Line fitting macro written for ROOT
{
  const int ndata = 6;

  float x[ndata] = {     0,  1.2000,  2.4000,  3.6000,  4.8000,  6.0000};
  float y[ndata] = {5.1511,  2.5335,  0.1766, -2.0675, -4.4292, -7.1095};
  float sy[ndata]= {0.2442,  0.1050,  0.1809,  0.2716,  0.2643,  0.1667};

  float weight = 0;
  float totw = 0; // Total weight
  float xybar = 0, xbar = 0, ybar = 0, x2bar = 0; // weighted averages

  for (int i=0; i<ndata; ++i) {
    weight = 1./(sy[i]*sy[i]);
    totw += weight;
    xybar += (x[i]*y[i]*weight);
    xbar += (x[i]*weight);
    ybar += (y[i]*weight);
    x2bar += (x[i]*x[i]*weight);
  }

  xybar /= totw;
  xbar /= totw;
  ybar /= totw;
  x2bar /= totw;

  float sy2bar = ndata / totw; // weighted average error squared
  float slope = (xybar - xbar*ybar) / (x2bar - xbar*xbar);
  float itcpt = ybar - slope * xbar;
  float slopeerr = sqrt ( sy2bar / (ndata * (x2bar - xbar*xbar) ) );
  float itcpterr = sqrt ( x2bar ) * slopeerr;
  cout << "slope of fit line = " << slope << " +- " << slopeerr << endl;
  cout << "intercept of fit line = " << itcpt << " +- " << itcpterr << endl;

  TGraphErrors *mygraph = new TGraphErrors(ndata,x,y,0,sy);
  mygraph->Draw("A*");

  gStyle->SetOptFit(1111);
  
  TF1 *ffitline = new TF1("ffitline","[0]*x+[1]",0,6);
  ffitline->SetParameter(0,slope);
  ffitline->SetParameter(1,itcpt);
  ffitline->SetLineColor(kBlue); // draw in blue color
  ffitline->SetLineStyle(2); // draw dotted line
  ffitline->Draw("same");

  // let's also try the same with ROOT's own fitter
  TF1 *fnew = new TF1("fnew","[0]*x+[1]",0,6);
  fnew->SetParameters(3.1416,2.7182); // arbitrary starting parameters
  mygraph->Fit(fnew);
  
}
