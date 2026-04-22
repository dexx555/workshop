#include <iostream>
using namespace std;
class complexe {
    private:
        int reel_a;
        int imag_b;
        static int cmp;
    public:
    complexe(){
           reel_a=0;
           imag_b=0;
    }
    complexe(int a , int b){
           reel_a=a;
           imag_b=b; 
    }
    complexe( const complexe& c){
        reel_a = c.reel_a;
        imag_b = c.imag_b;
    }
    ~complexe(){
        cout << "destruction de l'objet"<<endl;
    }
}
int main() {
  
    return 0;
}
/*cout == console output*/
/*endl == end line*/
 /*using namespace std; this line allows us to use cout and endl without the std:: prefix*/
 /*cin == console input*/
 /*cerr == console error output*/
 /* const complexe& ==  */
 