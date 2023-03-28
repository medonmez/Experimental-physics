
{
  TH1F *histo = new TH1F("histo","Histogram",10, 30, 40);
  
  std::ifstream file("data.txt");
  ///std::ifstream file("C:/root_v6.26.06/macros/data.txt");
  float datum;
  while (file>>datum) histo->Fill(datum);
  histo->Draw();
}

