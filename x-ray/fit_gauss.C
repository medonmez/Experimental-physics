{
	// Defining a Canvas
	TCanvas* c1 = new TCanvas();
	c1->SetWindowSize(900, 600);

	// Defining the graph object with error bars. Read from a txt file.
	TGraphErrors* mygraph = new TGraphErrors("35kV-calibration.txt");


	// Setting the title of the graph
	mygraph->SetTitle("Raw Data");

	// Drawing the graph
	mygraph->Draw("");

	// Naming the axes
	mygraph->GetXaxis()->SetTitle("theta(degrees)");
	mygraph->GetYaxis()->SetTitle("Intensity(imp/s)");

	TF1 *gauss_fit = new TF1("gauss_fit","[0]*TMath::Gaus(x,[1],[2])",7.50,7.95);
   // Starting parameters for the search of [0], [1] and [2].
   // Choices here are sometimes important for optimization.
   // Try (150, 10, 2) instead of (150,100,20)
   gauss_fit->SetParameters(900,7.5,0.1);
   // Cosmetics
   gauss_fit->SetLineColor(kGreen);
   gauss_fit->SetLineWidth(3);
   // Fitting to "mygraph" object in the "given range" defined in gauss_fit
   // Try deleting "R"     
   mygraph->Fit(gauss_fit,"R");

	TF1 *gauss_fit_2 = new TF1("gauss_fit","[0]*TMath::Gaus(x,[1],[2])",13.1,13.7);
	gauss_fit_2->SetParameters(350,13.5,0.1);
   // Cosmetics
   gauss_fit_2->SetLineColor(kRed);
   gauss_fit_2->SetLineWidth(3);
   // Fitting to "mygraph" object in the "given range" defined in gauss_fit
   // Try deleting "R"     
   mygraph->Fit(gauss_fit_2,"R+");

   TF1 *gauss_fit_3 = new TF1("gauss_fit","[0]*TMath::Gaus(x,[1],[2])",14.8,15.3);
	gauss_fit_3->SetParameters(800,15,0.1);
   // Cosmetics
   gauss_fit_3->SetLineColor(kGreen);
   gauss_fit_3->SetLineWidth(3);
   // Fitting to "mygraph" object in the "given range" defined in gauss_fit
   // Try deleting "R"     
   mygraph->Fit(gauss_fit_3,"R+");

   TF1 *gauss_fit_4 = new TF1("gauss_fit","[0]*TMath::Gaus(x,[1],[2])",19.9,20.3);
	gauss_fit_4->SetParameters(120,20.1,0.1);
   // Cosmetics
   gauss_fit_4->SetLineColor(kRed);
   gauss_fit_4->SetLineWidth(3);
   // Fitting to "mygraph" object in the "given range" defined in gauss_fit
   // Try deleting "R"     
   mygraph->Fit(gauss_fit_4,"R+");

    TF1 *gauss_fit_5 = new TF1("gauss_fit","[0]*TMath::Gaus(x,[1],[2])",22.3,23);
	gauss_fit_5->SetParameters(200,22.5,0.1);
   // Cosmetics
   gauss_fit_5->SetLineColor(kGreen);
   gauss_fit_5->SetLineWidth(3);
   // Fitting to "mygraph" object in the "given range" defined in gauss_fit
   // Try deleting "R"     
   mygraph->Fit(gauss_fit_5,"R+");

    TF1 *gauss_fit_6 = new TF1("gauss_fit","[0]*TMath::Gaus(x,[1],[2])",30.4,31);
	gauss_fit_6->SetParameters(100,30.8,0.1);
   // Cosmetics
   gauss_fit_6->SetLineColor(kGreen);
   gauss_fit_6->SetLineWidth(3);
   // Fitting to "mygraph" object in the "given range" defined in gauss_fit
   // Try deleting "R"     
   mygraph->Fit(gauss_fit_6,"R+");

	// Setting the limits of "x-axis" if required for visibility
	mygraph->GetXaxis()->SetLimits(0, 32);
	gStyle->SetOptFit(1111);


	}
