{
	// Defining a Canvas
	TCanvas* c1 = new TCanvas();
	c1->SetWindowSize(900, 600);

	// Defining the graph object with error bars. Read from a txt file.
	TGraphErrors* mygraph = new TGraphErrors("Geiger-Muller-Plato.txt");


	// Setting the title of the graph
	mygraph->SetTitle("Geiger-Muller Plato Graph");

	// Drawing the graph
	mygraph->Draw("A*");

	// Naming the axes
	mygraph->GetXaxis()->SetTitle("Applied Voltage(V)");
	mygraph->GetYaxis()->SetTitle("Counts");



	// Setting the limits of "x-axis" if required for visibility
	//mygraph->GetXaxis()->SetLimits(2, 4.5);

	// Setting the limits of "y-axis" if required for visibility
	//mygraph->SetMinimum(0.009);
	//mygraph->SetMaximum(0.015);

	}
