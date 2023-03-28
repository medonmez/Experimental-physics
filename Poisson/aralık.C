{
	TCanvas* c1 = new TCanvas();
	c1->SetWindowSize(900, 600);
	
	TH1F *histo = new TH1F("histo","Histogram",15,2,111.001 );
  
  std::ifstream file("C:/Users/mert9/phys442/Poisson/n1values.txt");
 
  float datum;
  while (file>>datum) histo->Fill(datum);
  histo->Draw();
  histo->SetTitle("n=1");
  histo->GetXaxis()->SetTitle("Time interval of successive pulses");
  histo->GetYaxis()->SetTitle("Number of Counts");
  gStyle->SetOptFit(1111);
TF1 *expo_fit = new TF1("expo_fit","[0]*exp(-[1]*x)",0,111);
   expo_fit->SetParameters(100,1);
   expo_fit->SetLineColor(kRed);
   expo_fit->SetLineWidth(3);
   // Fitting and plotting on the same graph with the previous fit requires "R+" option
   // Try deleting the plus sign
   histo->Fit(expo_fit,"R");

}