#include<iostream>
#include<string>
using namespace std;

inline void OutPutAnswer(int wScore, int lScore)
{
    cout<<wScore<<':'<<lScore<<endl;
}

int main(){
    char input;
    string races;
    while(!cin.fail()){
        cin>>input;
        if(input>='A'&&input<='Z'){
            races+=input;
        }
        if(input=='E'){
            break;
        }
    }
    cin.clear();

    int wScore=0,lScore=0;
    int rounds=0;
    //11
    for(auto race:races){
        if(race=='E'){
            OutPutAnswer(wScore,lScore);
        }
        if(race=='W')wScore++;
        if(race=='L')lScore++;
        if((wScore>=11||lScore>=11)&&abs(wScore-lScore)>=2){
            OutPutAnswer(wScore,lScore);
            wScore=lScore=0;
            rounds++;
        }
    }
    puts("");
    //21
    wScore=0;lScore=0;
    rounds=0;
    for(auto race:races){
        if(race=='E'){
            if(wScore!=0||lScore!=0||rounds==0){
                OutPutAnswer(wScore,lScore);
            }else{
                break;
            }
        }
        if(race=='W')wScore++;
        if(race=='L')lScore++;
        if((wScore>=21||lScore>=21)&&abs(wScore-lScore)>=2){
            OutPutAnswer(wScore,lScore);
            wScore=lScore=0;
            rounds++;
        }
    }
    return 0;
}