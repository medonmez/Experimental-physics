// Line fit with errors
{
  TGraphErrors gr("2500,2sq.txt");
  gr.Draw("AP*");
  gr.SetTitle("Line Fit Example; x data ; y data");
  gr.SetMinimum(0);
  gr.SetMaximum(30);
}
