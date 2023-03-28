// gauss macro written for ROOT
{
  TF1 *gaus = new TF1("gauss","TMath::Gaus(x,15,1)",0,30);
  gauss->Draw();
  
  float sum=0;
  TH1F *histo = new TH1F("histo","Average value of 100 trials", 100, 14,16);
  for (int j=0; j<500; j++){
    sum=0; cout << j  << endl;
    for (int i=0; i<100; i++){
      sum += gauss->GetRandom();
    }
    histo->Fill(sum/100);
  }
  histo->Draw();
  
}
