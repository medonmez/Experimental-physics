{
	TCanvas* c1 = new TCanvas();
	c1->SetWindowSize(900, 600);
	
	TH1F *histo = new TH1F("","Histogram",17,10,350 );
  
  std::ifstream file("2dscat.txt");
 
  float datum;
  while (file>>datum) histo->Fill(datum);

  histo->Draw();
  histo->SetTitle("Number of hits for each section");
  histo->GetXaxis()->SetTitle("Degrees");
  histo->GetYaxis()->SetTitle("Number of Hits");

}