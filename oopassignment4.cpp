#include <iostream>
#include <string.h>
using namespace std ;
template <typename t>class receipt; 
class library{
    protected:
        char name[30];
        char author[30];
        int bookcode;
        float bookcost;
    public:
        library(){
            cout<<"enter bookname :";
            cin>>name;
            cout<<"enter author name :";
            cin>>author;
            cout<<"enter book code";
            cin>>bookcode;
            cout<<"enter cost of book";
            cin>>bookcost;
            try{
             if(bookcost<=0){
                throw 65;
            }
            }
            catch(int num){
                cout<<"vector has 3 dimentions";
                cin>>bookcost;
            }
        }
};
class genre:virtual public library{
    private:
        char g[30];
    public:
        genre(){
            cout<<"enter genre";
            cin>>g;
        }
};
class bookshape:virtual public library{
    private:
        string shape;
    public:
        int length , width ;
    
    float bookarea(int length , int bredth ){
        return length *bredth;
    }
    float bookarea(int length){
        return length*length;
    }
    bookshape(){
        cout<<"enter book shape";
        cin>>shape;
        cout<<"\n";
        if (shape =="square"){
            int a ;
            cout<<"enter width";
            cin>>a;
            cout<< bookarea(a);
            if (bookarea(a)>20){
                cout<<"you can find the book in top shelf"<<endl;
            }
            else if (bookarea(a)>15||bookarea(a)<10){
                cout<<"you can find the book in middle shelf"<<endl;
            }
            else cout<<"you can find the book in the bottom shelf"<<endl;
        }
        else if (shape =="rectangle"){
            int a;int b;
            cout<<"enter length and bredth";
            cin>>a>>b;
            cout<< bookarea(a,b);
            if (bookarea(a)>20){
                cout<<"you can find the book in top shelf"<<endl;
            }
            else if (bookarea(a)>15||bookarea(a)<10){
                cout<<"you can find the book in middle shelf"<<endl;
            }
            else cout<<"you can find the book in the bottom shelf"<<endl;
            
        }
    }
    

};
template<typename t>class receipt:public genre,public bookshape{
    private:
        t cost ;
        float quantity;
    public:
        receipt(){
            cout<<"enter quantity";
            cin>>quantity;
        }
        void calc(){
            cost = quantity*bookcost;
        }
        void operator +(receipt b)
        {
            this->cost+=b.cost;
            this->quantity+=b.quantity;
        }

        void show(){
            cout<<"\n\nbook receipt :\n"<<"quantity purchased = "<<quantity<<"\t"<<"total cost = "<<cost;
        }
};
int main (){
    receipt<float>r;
    receipt<float>s;
    r.calc();
    s.calc();
    s.show();
    s+(r);
    s.show();
    return 0 ;
}









// #include <iostream>
// using namespace std;
 
// template <class t>
// class vectors
// {
//     public:
//         t *a;
//         int size;
//         vectors(){
//             cout<<"enter size";
//             cin>>size;
//             try{
//             if(size!=3){
//                 throw 65;
//             }
//             }
//             catch(65){
//                 cout<<"vector has 3 dimentions";
//                 cin<<size;
//             }
            
//         }
//         vectors(int s)
//         {
//             if (s==0||s<1){
//                 throw "array size too low ";
//             }
//             size = s;
//             a = new T[size];
//         }
// };
// template <class t>class functions:public virtual vectors{
//     public:
//     t dotProduct(vectors &v){
//         t d=0;
//         for (int i = 0; i < size; i++)
//         {
//             d+=this->a[i]*v.a[i];
//         }
//         return d;
        
//     }
    
// };
// template <class t>class operatoroverloading:public virtual vectors{
//     public:
//         operatoroverloading operator + (vectors &v)
//         {
//             this.a[0]=this.a[0]+v.a[0];
//         }
// };
// template<class t>class show:public operatoroverloading , public:vector
// int main()
// {
//     vector<float> v1(3); 
//     v1.a[0] = 1.4;
//     v1.a[1] = 3.3;
//     v1.a[2] = 0.1;
//     vector<float> v2(3); 
//     v2.a[0]=0.1;
//     v2.a[1]=1.90;
//     v2.a[2]=4.1;
//     float b= v1.dotProduct(v2);
//     cout<<a<<endl;
//     return 0;
// }