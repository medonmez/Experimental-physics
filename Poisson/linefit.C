// Line fitting macro written for ROOT
{
  TCanvas* c1 = new TCanvas();
	c1->SetWindowSize(900, 600);

  TGraph *mygraph = new TGraph("mean-std.txt");
  mygraph->Draw("A*");

  gStyle->SetOptFit(1);
  mygraph->SetTitle("#sqrt{#mu}/#sigma vs #mu");
  mygraph->GetXaxis()->SetTitle("#mu");
  mygraph->GetYaxis()->SetTitle("#sqrt{#mu}/#sigma");

  // let's also try the same with ROOT's own fitter
  TF1 *fnew = new TF1("fnew","[0]*x+[1]",0,6);
  fnew->SetParameters(0,1); // arbitrary starting parameters
  fnew->SetLineColor(kBlue); // draw in blue color
  fnew->SetLineStyle(2); // draw dotted line
  mygraph->Fit(fnew);
  
}
