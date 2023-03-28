
{
  TH1F *histo = new TH1F("histo","Histogram",30, 20, 50);
  
  float data[15] = {32,34,36,38,35,35,35,31,39,37,41,41,30,27,25};
  for (int i=0; i<15; i++) histo->Fill(data[i]);
  histo->Draw();

}
