{
	// Defining a Canvas
	TCanvas* c1 = new TCanvas();
	c1->SetWindowSize(900, 600);

	// Defining the graph object with error bars. Read from a txt file.
	TGraphErrors* mygraph = new TGraphErrors("energy.txt");


	// Setting the title of the graph
	mygraph->SetTitle("Energy vs frequency");

	// Drawing the graph
	mygraph->Draw("A*");

	// Naming the axes
	mygraph->GetXaxis()->SetTitle("frequency(Hzx10^{18})");
	mygraph->GetYaxis()->SetTitle("Energy(eV)");

	TF1 *fnew = new TF1("fnew","[0]*x+[1]",0,2);
  	fnew->SetParameters(33,250); // arbitrary starting parameters
  	mygraph->Fit(fnew);
    gStyle->SetOptFit(1111);
	}