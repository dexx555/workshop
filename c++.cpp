#include <stdexcept>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
// Conj
// Hypothèse : N > 0
{
long int N;
cout << "Entrer Un Nombre : ";
cin >> N;
while (N != 1)
{
if (N%2 == 0){
N = N/2;
cout << "N paire ==  "<< N << endl;
}
else  {
N = 3*N+1;
cout << "N impaire ==  "<< N << endl;
}
}
cout << N << endl; //Imprime 1
}
/*cout == console output*/
/*endl == end line*/
 /*using namespace std; this line allows us to use cout and endl without the std:: prefix*/
 /*cin == console input*/
 /*cerr == console error output*/
 /* const complexe& ==   */
 /*template == allows us to create functions and classes that can work with any data type. 
  It is a powerful feature of C++ that enables us to write generic programming code.
  template <typename T>
void any(T val){
    cout << val<< endl;
}
int main() {
    any(5);
    any("hiiiiiiii");
    any(5.23);
    return 0;
} 
  In the example above, we have defined a template function called "any" that takes a parameter of type T. 
  This means that we can call this function with any data type, such as int, float, or string, and it will work correctly.*/
  /*const int* a == This is a pointer to a constant integer. 
  It means that the value pointed to by the pointer cannot be modified through that pointer
   but the pointer itself can point to different integers.*/
   /* int* const* a == This is a pointer to a constant pointer. 
   It means that the pointer itself cannot be modified to point to a different memory location 
   but the value it points to can be modified.*/
  /*int fonction() const {} == This is a member function declaration in C++. 
  The "const" keyword indicates that the function does not modify the state of the object it belongs to.*/
  
 /*fonction (const classe& a) == */