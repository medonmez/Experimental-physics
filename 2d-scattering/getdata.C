{
	// Defining a Canvas
	TCanvas* c1 = new TCanvas();
	c1->SetWindowSize(900, 600);

	// Defining the graph object with error bars. Read from a txt file.
	TGraphErrors* mygraph = new TGraphErrors("dndata.txt");


	// Setting the title of the graph
	mygraph->SetTitle("dN vs sin(#theta/2)");

	// Drawing the graph
	mygraph->Draw("A*");

	// Naming the axes
	mygraph->GetXaxis()->SetTitle("sin(#theta/2)");
	mygraph->GetYaxis()->SetTitle("dN");

	TF1 *fnew = new TF1("fnew","[0]*x+[1]",0,2);
  	fnew->SetParameters(3.1416,2.7182); // arbitrary starting parameters
  	mygraph->Fit(fnew);
    gStyle->SetOptFit(1111);
	}
