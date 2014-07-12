//try to make a toy monte carlo
//waste calculation
void simpleProfitPrediction(){

    gBenchmark->Start("htrang");
    TH1 *hprofit = new TH1F("hprofit","hprofit",100,-2000,6000);
    Int_t numUnit;
    Float_t rentUnit=500;
    Float_t monthlyExpense;
    Float_t profit;
    gRandom->SetSeed();
    //condition to print
    const Int_t kUPDATE = 1000;
    //number of iteration
    const Int_t kIteration = 100000;
    TSlider *slider = 0;
    TCanvas *c1 = new TCanvas("c1","c1",800,800);
    gStyle->SetOptStat(0);
    gStyle->SetLineWidth(2);
    hprofit->SetFillColor(kRed);
    TString titleString;
    for ( Int_t i=0; i<kIteration; i++) {
        numUnit = gRandom->Uniform(30,40);
        monthlyExpense = gRandom->Gaus(15000,1000);
        profit = numUnit*rentUnit-monthlyExpense;
        hprofit->Fill(profit);
        if (i && (i%kUPDATE) == 0) {
          // if (i == kUPDATE) {
            titleString.Form("Iteration = %d",i);
            hprofit->SetTitle(titleString);
                hprofit->Draw("histsame");
               c1->Update();
               
           // }
        }
    }

    
    gBenchmark->Show("htrang");
}