
{
  TH1F *histo = new TH1F("histo","Histogram",10, 30, 40);
  
  float data[10] = {32,34,36,38,35,35,35,31,39,37};
  for (int i=0; i<10; i++) histo->Fill(data[i]);
  histo->Draw();

}
