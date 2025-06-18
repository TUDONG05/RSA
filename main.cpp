#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int power(int a, int b, int m)
{
    int f = 1;
    a = a%m; //rut gon cho so a cho mod m
    while(b>0)
    {
        if(b %2==1)
            f = (f*a*1LL)%m;
        a = (a*a*1LL)%m;
        b=b/2;
    }
    return f;


}

//tim nghich dao cua e trong truong mod n
int e_nghich(int e, int phi)
{
    for(int d = 2;d<phi;d++)
        if((d*e)%phi==1)
            return d;
    return -1;
}

//tao khoa RSA
void taoKhoa(int &e, int &d, int p, int q)
{
    int phi_n = (p-1)*(q-1);

    //chon e sao cho 1<e<phi_n va gcd(e,phi_n)=1
    for(e =2 ;e<phi_n;e++)
    {
        if(__gcd(e,phi_n)==1)
            break;
    }

    //tim d la nghich dao cua e trong mod phi_n
    d = e_nghich(e,phi_n);
}

int maHoa(int m, int e, int n)
{
    return power(m,e,n);
}

int giaiMa(int c, int d, int n)
{
    return power(c,d,n);
}

bool isPrime(int n)
{
    if(n<2)
        return false;
    else
    {
        for(int i=2;i<=sqrt(n);i++)
            if(n%i==0)
                return false;
        return true;
    }
}

int main()
{
    int p, q;
    do
    {
    cout<<"nhap so nguyen to p:";
    cin>>p;

    cout<<"nhap so nguyen to q:";
    cin>>q;
    }
    while(!isPrime(p) || !isPrime(q) ||(p==q));

    int n=p*q;


    int e,d;
    taoKhoa(e,d,p,q);

    cout<<"khoa cong khai (e="<<e<<",n="<<n<<")"<<endl;
    cout<<"khoa bi mat (d="<<d<<",n="<<n<<")"<<endl;

    int m;

    do
    {
        cout<<"nhap ban ro m<"<<n<<":";
        cin>>m;
    }
    while (m>=n);

    int c=maHoa(m,e,n);
    int banRo =giaiMa(c,d,n);
    cout<<"ban ro goc:"<<m<<endl;
    cout<<"Ma hoa:"<<c<<endl;
    cout<<"Giai ma:"<<banRo<<endl;

}
