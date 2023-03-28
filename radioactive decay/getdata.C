{
	// Defining a Canvas
	TCanvas* c1 = new TCanvas();
	c1->SetWindowSize(900, 600);

	// Defining the graph object with error bars. Read from a txt file.
	TGraphErrors* mygraph = new TGraphErrors("5sfixed.txt");


	// Setting the title of the graph
	mygraph->SetTitle("5 squeezes fixed");

	// Drawing the graph
	mygraph->Draw("A*");

	// Naming the axes
	mygraph->GetXaxis()->SetTitle("Voltage(kV)");
	mygraph->GetYaxis()->SetTitle("lambda(1/s)");

	// Setting the limits of "x-axis" if required for visibility
	mygraph->GetXaxis()->SetLimits(2, 4.5);

	// Setting the limits of "y-axis" if required for visibility
	mygraph->SetMinimum(0.009);
	mygraph->SetMaximum(0.015);

	}
