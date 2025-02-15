/// \file
/// \ingroup tutorial_graphs
/// \notebook
/// Create and draw a polar graph with PI axis
///
/// \macro_image
/// \macro_code
///
/// \author Olivier Couet

void graphpolar2()
{
   auto CPol = new TCanvas("CPol", "TGraphPolar Example", 500, 500);

   Double_t theta[8];
   Double_t radius[8];
   Double_t etheta[8];
   Double_t eradius[8];

   for (int i = 0; i < 8; i++) {
      theta[i] = (i + 1) * (TMath::Pi() / 4.);
      radius[i] = (i + 1) * 0.05;
      etheta[i] = TMath::Pi() / 8.;
      eradius[i] = 0.05;
   }

   auto grP1 = new TGraphPolar(8, theta, radius, etheta, eradius);
   grP1->SetTitle("");

   grP1->SetMarkerStyle(20);
   grP1->SetMarkerSize(2.);
   grP1->SetMarkerColor(4);
   grP1->SetLineColor(2);
   grP1->SetLineWidth(3);
   grP1->Draw("RPE"); // R - radian, P - markers, E - errors
}
