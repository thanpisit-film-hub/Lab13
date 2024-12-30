#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double _C[], int _A, double B[]){
      double _Sum, _SumAM, _Sd, _SumforGm = 1, _SumforHm1, _SumforHm2, _Max = _C[0], _Min = _C[0];
      for(int i = 0; i < _A; i++){
          _Sum += _C[i];
      }
      _SumAM = _Sum/_A;
      B[0] = _SumAM;
   
      for(int j = 0; j < _A; j++){
           _Sd += pow(_C[j] - _SumAM, 2);
      }
      B[1] = sqrt(_Sd / _A);
      
      for(int k = 0; k < _A; k++){
          _SumforGm *= _C[k];
      }
      B[2] = pow(_SumforGm, 1.0/_A);
      
      for(int x = 0; x < _A; x++){
          _SumforHm1 += 1/_C[x];
      }
      _SumforHm2 = _A/_SumforHm1;
      B[3] = _SumforHm2;
      
      for(int y = 1; y < _A; y++){
          if(_C[y] < _Min){
              _Min = _C[y];
          }
          if(_C[y] > _Max){
              _Max = _C[y];
          }
      }
      B[4] = _Max;
      B[5] = _Min;
}
