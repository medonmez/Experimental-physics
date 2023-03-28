
{
	TCanvas* c1 = new TCanvas();
	c1->SetWindowSize(900, 600);
	
	TH1F *histo = new TH1F("histo","Histogram",11,87,141.001 );
  
  std::ifstream file("C:/Users/mert9/phys442/Poisson/Cs-440V-10s.txt");
 
  float datum;
  while (file>>datum) histo->Fill(datum);
  histo->Draw();
  histo->SetTitle("Cs-133 for 10 seconds");
  histo->GetXaxis()->SetTitle("Counts");
  histo->GetYaxis()->SetTitle("Number of Counts");

 TF1* poisson_fit = new TF1("poisson_fit", "[0]*TMath::Poisson(x,[1])", 87, 142);

  poisson_fit->SetParameters(500, 100);
  // Cosmetics
  poisson_fit->SetLineColor(kGreen);
  poisson_fit->SetLineWidth(3);
  // Fitting to "mygraph" object in the "given range" defined in gauss_fit
  // Try deleting "R"     
  histo->Fit(poisson_fit, "R+");


  TF1* gauss_fit = new TF1("gauss_fit", "[0]*TMath::Gaus(x,[1],[2])", 87, 142);
  gauss_fit->SetParameters(500, 100, 11);
  // Cosmetics
  gauss_fit->SetLineColor(kRed);
  gauss_fit->SetLineWidth(3);
  // Fitting to "mygraph" object in the "given range" defined in gauss_fit
  // Try deleting "R"     
  histo->Fit(gauss_fit, "R+");
  gStyle->SetOptFit(1111);

 
}

