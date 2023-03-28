{
   // Defining a Canvas
   TCanvas *c1 = new TCanvas();
   c1->SetWindowSize(900, 600);

   // Defining the graph object with error bars. Read from a txt file.
   TGraphErrors *mygraph = new TGraphErrors("4000,5sq.txt");

   // Setting the title of the graph
   mygraph->SetTitle("V=4.0kV, 5 squeezes");

   // Drawing the graph
   mygraph->Draw("A*");
   gStyle->SetOptFit(1);
   
   // Defining and fitting an exponential function in a given range
   TF1* expo_fit = new TF1("expo_fit", "[0]*exp(-[1]*x)", 0, 325);
   expo_fit->SetParameters(0.30, 0.012);
   expo_fit->SetLineColor(kRed);
   expo_fit->SetLineWidth(3);

   // Fitting and plotting
   mygraph->Fit(expo_fit);

   // Naming the axes
   mygraph->GetXaxis()->SetTitle("T(s)");
   mygraph->GetYaxis()->SetTitle("1/s(t)");

   // Setting the limits of "x-axis" if required for visibility
   mygraph->GetXaxis()->SetLimits(0, 325);

   // Setting the limits of "y-axis" if required for visibility
   mygraph->SetMinimum(0);
   mygraph->SetMaximum(0.6);
}
