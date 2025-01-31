#include <fstream>

using namespace std;

ifstream cin("pelican.in");
ofstream cout("pelican.out");
struct rata
{
    int ln,cl,dir;
};

const int P =1e4;

rata v[P+1];
int main()
{
    int n,p,k;

    cin>>n>>p>>k;

    for (int i = 1; i<=p; i++)
    {
        cin>>v[i].ln>>v[i].cl>>v[i].dir;
    }

    int ln=0, cl=0,dir = 1;
    int dcol = -1, dln = -1;

    for (int i = 1; i<=k; i++)
    {
        char inst;
        int nr;
        cin>>inst>>nr;
        if(inst == 'A')
        {
            if(dir==1)
            {
                ln-=nr;
            }
            if(dir==2)
            {
                cl+=nr;
            }
            if(dir==3)
            {
                ln+=nr;
            }
            if(dir==4)
            {
                cl-=nr;
            }
        }
        if(inst=='R')
        {
            dir+=nr;
            dir=dir%4;
            if(dir==0)
                dir=4;
        }
        if(inst == 'Z')
        {
            dcol = nr % n;
            dln = nr / n;
            ln=0;
            cl = 0;
        }
    }



    for (int i = 1; i<=p; i++)
    {
        if(dcol!=-1)
        {
            v[i].ln = dln;
            v[i].cl = dcol;
        }
        if(v[i].dir==1)
        {
            v[i].ln+=ln;
            v[i].cl+=cl;

        }


        if(v[i].dir==2)
        {
            v[i].ln+=cl;
            v[i].cl-=ln;

        }

        if(v[i].dir==3)
        {
            v[i].ln-=ln;
            v[i].cl-=cl;

        }


        if(v[i].dir==4)
        {
            v[i].ln-=cl;
            v[i].cl+=ln;

        }


        if(v[i].ln<0)
        {
            v[i].ln=n+(v[i].ln%n);
        }
        v[i].ln%=n;
        if(v[i].cl<0)
        {
            v[i].cl=n+(v[i].cl%n);
        }
        v[i].cl%=n;
        cout<<v[i].ln<<' '<<v[i].cl<<'\n';
    }


    return 0;
}
