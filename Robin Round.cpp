#include<iostream>

using namespace std;

struct process
{
    int id;
    int bt;
    bool ch;
};

bool check(process p[])
{
    for(int i=0; i<4; i++)
    {
        if(p[i].ch==true)
            ;
        else
            return false;
    }
    return true;
}

int main()
{
    process p[4];
    int tq=4;

    for(int i=0; i<4; i++)
    {
        cout << "Enter process "<< i+1<<" id : " ;
        cin >> p[i].id;
        cout << "Enter process" <<i+1 << " Burst time : ";
        cin >> p[i].bt;
        p[i].ch=false;
    }
    int w[4],turn[4],lf[4],tot=0;
    double sW=0,sT=0;
    for(int i=0; i<4; i++)
        lf[i]=p[i].bt;
    bool cal[4]= {false,false,false,false};
    while(true)
    {
        for(int i=0; i<4; i++)
        {
            if(p[i].bt>=tq)
            {
                p[i].bt = p[i].bt - tq;
                tot = tot +tq;
            }
            else if(p[i].bt<tq)
            {
                tot = tot + p[i].bt;
                p[i].bt=0;
                p[i].ch=true;

            }

            if(p[i].bt==0)
            {
                if(cal[i]==false)
                {
                    turn[i] = tot;
                    sT = sT + turn[i];
                    w[i] = turn[i]-lf[i];
                    sW = sW + w[i];
                    cal[i] = true;

                    //cout << "\n  " << turn[i];
                }

            }

        }
        if(check(p))
            break;
    }

    cout << "Avg waiting time : "<< sW/4.0 << "\n   Avg turn arround time : " << sT/4.0;

}
