#include<iostream>

using namespace std;

struct process
{
    int id;
    int bt;
    int prio;
};

void sortProcess(process p[])
{
    for(int i=0;i<4;i++)
    {
        for(int j=i;j<4;j++)
        {
            if(p[i].prio>p[j].prio)
            {
                int temp = p[i].prio;
                p[i].prio=p[j].prio;
                p[j].prio = temp;

                temp = p[i].id;
                p[i].id=p[j].id;
                p[j].id = temp;

                temp = p[i].bt;
                p[i].bt=p[j].bt;
                p[j].bt = temp;
            }
        }
    }
}

int main()
{
  //  freeopen("r","input.txt",stdin);
    process p[4];

    for(int i=0;i<4;i++)
    {
        cout << "Enter process "<< i+1<<" id : " ;
        cin >> p[i].id;
        cout << "Enter process" <<i+1 << " Burst time : ";
        cin >> p[i].bt;
        cout << "Enter process" <<i+1 << " priority : ";
        cin >> p[i].prio;
    }

    sortProcess(p);

    int w[4],turn[4];
    double sW=0,sT=0;
    w[0] = 0;
    turn[0] = p[0].bt;
    for(int i=1;i<4;i++)
    {
        w[i] = turn[i-1];
        turn[i] = turn[i-1]+p[i].bt;

        sW=sW+w[i];
        sT=sT+turn[i];
    }

    cout << "\nPid     wt      tat \n\n";
    for(int i=0;i<4;i++)
    cout << p[i].id << "      " << w[i] << "         " << turn[i] << " ""\n";
cout << endl <<   "avgW     avgT\n\n"<< sW/4.0<< "   " << sT/4.0 <<endl;
}
