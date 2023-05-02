{
	// Defining a Canvas
	TCanvas* c1 = new TCanvas();
	c1->SetWindowSize(900, 600);

	// Defining the graph object with error bars. Read from a txt file.
	TGraphErrors* mygraph = new TGraphErrors("30kv.txt");


	// Setting the title of the graph
	mygraph->SetTitle("30kV");

	// Drawing the graph
	mygraph->Draw("");

	// Naming the axes)
	mygraph->GetXaxis()->SetTitle("lambda(nm)");
	mygraph->GetYaxis()->SetTitle("intensity(imp/s)");


	TF1 *fnew = new TF1("fnew","[0]*x+[1]",0.04,0.05);
  	fnew->SetParameters(3.1416,2.7182); // arbitrary starting parameters
	fnew->SetLineColor(kGreen);
    fnew->SetLineWidth(5);
  	mygraph->Fit(fnew,"R");
    gStyle->SetOptFit(1111);

	// Setting the limits of "x-axis" if required for visibility
	// mygraph->GetXaxis()->SetLimits(2, 4.5);

	// Setting the limits of "y-axis" if required for visibility
	// mygraph->SetMinimum(0.009);
	// mygraph->SetMaximum(0.015);

	}
