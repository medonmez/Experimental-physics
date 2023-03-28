{
	// Defining a Canvas
	TCanvas* c1 = new TCanvas();
	c1->SetWindowSize(900, 600);

	// Defining the graph object with error bars. Read from a txt file.
	TGraphErrors* mygraph = new TGraphErrors("cavendish.txt");


	// Setting the title of the graph
	mygraph->SetTitle("Raw Data");

	// Drawing the graph
	mygraph->Draw("");

	// Naming the axes
	mygraph->GetXaxis()->SetTitle("Time(sec)");
	mygraph->GetYaxis()->SetTitle("Voltage(V)");



	// Setting the limits of "x-axis" if required for visibility
	//mygraph->GetXaxis()->SetLimits(0, 4500);

	// Setting the limits of "y-axis" if required for visibility
	//mygraph->SetMinimum(-0.010);
	//mygraph->SetMaximum(0.020);

	}
