{
	// Defining a Canvas
	TCanvas* c1 = new TCanvas();
	c1->SetWindowSize(900, 600);

	// Defining the graph object with error bars. Read from a txt file.
	TGraphErrors* mygraph = new TGraphErrors("dump.txt");


	// Setting the title of the graph
	mygraph->SetTitle("Free Decay Mode");

	// Drawing the graph
	mygraph->Draw("");

	// Naming the axes
	mygraph->GetXaxis()->SetTitle("Time(sec)");
	mygraph->GetYaxis()->SetTitle("Voltage(V)");

    // Defining and fitting an exponential function in a given range
   TF1* expo_fit = new TF1("expo_fit", "[0]*exp(-[1]*x)*sin([2]*x +[3]) + [4]", 3000, 5000);
   expo_fit->SetParameters(0,0.001, 0.03,2,0.1);
   expo_fit->SetLineColor(kRed);
   expo_fit->SetLineWidth(3);
   gStyle->SetOptFit(1);
   // Fitting and plotting
   mygraph->Fit(expo_fit);

}