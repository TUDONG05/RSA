#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long power(long long a, long long b, long long p)
{
    long long f =1;
    a =a%p;
    while (b>0)
    {
        if(b&1)
            f=(f*a)%p;
        a = (a*a)%p;
        b=b/2;
    }
    return f;
}

long long nghich(long long a, long long n)
{
    for(int i=2;i<n;i++)
        if((a*i)%n==1)
            return i;
    return -1;
}

bool check_snt(long long a)
{
    if(a<2)
        return false;
    else
    {
        for(int i=2;i<=sqrt(a);i++)
            if(a%i==0)
                return false;
        return true;
    }

}

void taoKhoa(long long &e, long long &d ,long long p, long long q)
{
    long long phi_n =(p-1)*(q-1);
    for(e =2;e<phi_n;e++)
        if(__gcd(e,phi_n)==1)
            break;

    d = nghich(e,phi_n);


}
long long maHoa(long long m, long long e, long long n)
{
    return power(m,e,n);
}

long long giaiMa(long long c,long long d, long long n)
{
    return power(c,d,n);
}

int main()
{

    long long p,  q;
    do
    {
    cout<<"nhap so nguyen to p:";
    cin>>p;

    cout<<"nhap so nguyen to q:";
    cin>>q;
    }
    while(!check_snt(p) || !check_snt(q) ||(p==q));

    long long n = p*q;

    long long e,d;
    taoKhoa(e,d,p,q);

    string s;
    cin.ignore();
    cout<<"nhap thong diep:";
    getline(cin,s);

    vector <long long> mess;
    vector <long long> banMo;
    vector <long long> banRo;
    for(char m:s)
        mess.push_back((long long)m);
    for(long long m:mess)
    {
        long long c = maHoa(m,e,n);
        banMo.push_back(c);

        long long banro = giaiMa(c,d,n);
        banRo.push_back(banro);

    }
    cout<<"ban mo:";
    for(long long c:banMo)
        cout<<char(c);
    cout<<endl;

    cout<<"ban giai ma:";
    for(long long z :banRo)
        cout<<char(z);
    cout<<endl;


}
