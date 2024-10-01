#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double logL,logM,logX,logCv;
    int i=0;

    double L[] = { 4.0, 8.0 , 32.0};
    double M[] = {  0.378, 0.209  , 0.068};
    double X[] = {3.917 ,9.660, 171.928};
    double Cv[] = { 0.807 ,1.017, 1.490};


    FILE* fichier = fopen("exp.dat", "w");
    
    for (i = 0; i <=2; i+= 1) {
    
    	logL = log(L[i]);
    	logM = log(M[i]);
     	logX = log(X[i]);
     	logCv = log(Cv[i]);

        
        fprintf(fichier,"%.5f\t %.5f \t %.5f\t %.5f\t \n",logL,logM,logX,logCv);  
    }

    fclose(fichier);
    return 0;
} // By Amine Slimani


