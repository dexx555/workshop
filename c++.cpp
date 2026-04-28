#include <iostream>
using namespace std;
class operation {
    protected:
     int a, b;
    public:
        operation(int x ,int y) : a(x) , b(y){}
        virtual void executer(){
        cout << "operation inconnue" << endl;
    }
};
class addition : public operation {
public:
    addition(int x ,int y) : operation(x,y){}
    void executer(){
        cout << "x + y = " << a+b << endl;
    }
};
class multiplication : public operation {
    public:
    multiplication(int x ,int y) : operation(x,y){}
    void executer(){
        cout << "x1 * y2" << a*b << endl;
    }
};
int main() {
  operation* x = new addition(2,3);
  x->executer();
    return 0;
}

/*cout == console output*/
/*endl == end line*/
 /*using namespace std; this line allows us to use cout and endl without the std:: prefix*/
 /*cin == console input*/
 /*cerr == console error output*/
 /* const complexe& ==  */
 