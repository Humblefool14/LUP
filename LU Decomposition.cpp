#include<iostream>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
#define MAX 100
void LUdecomposition( float A[MAX][MAX],float L[MAX][MAX],float U[MAX][MAX],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i<j){U[i][j]=0;}  // Upper diagonal matrix
            if(i>j){L[i][j]=0;}  // Lower diagonal matrix
        }}
    for(int k=0;k<n;k++){
        U[k][k] = A[k][k];
        for(int i=k+1;i<n;i++){
            L[i][k]=A[i][k]/U[k][k];
            U[k][i] = A[k][i];
        }
        for(int i=k+1;i<n;i++){
            for(int j=k+1;j<n;j++){
                A[i][j] = A[i][j]-L[i][j]*(U[i][j]);
            }
        }
    }
}
int main(){
    float A[MAX][MAX], L[MAX][MAX],U[MAX][MAX];
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> A[i][j];
        }
    } // Input matrix
    float B[MAX];
    for(int i=0;i<n;i++){
        cin >> B[i];
    }
    LUdecomposition(A,L,U,n);
    cout << "L Matrix" << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << L[i][j] << " ";
        }
        cout << endl;
    }
    cout << "U Matrix" << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << U[i][j] << " " ;
        }
        cout << endl;
    }
    float x[n],y[n];
    memset(y,0,sizeof(y));
    memset(x,0,sizeof(y));
    for(int i=0;i<n;i++){
        float sum=0;
        for(int j=0;j<=i-1;j++){
            sum +=L[i][j]*y[j];
        }
        y[i]= B[i]-sum;
    } // Forward substitution
    for(int i=n-1;i!=-1;i--){
        float sum=0;
         for(int j=i+1;j<n;j++){
             sum+= U[i][j]*x[j];
         }
         x[i] = (y[i]-sum)/U[i][i];
    }
    // print(x);
    // print(y); void functions.
    // x matrix
    for(int i=0;i<n;i++){
        cout << x[i] << endl;
    }
    // y matrix
    for(int i=0;i<n;i++){
        cout << y[i] << endl;
    }

return 0;
}
