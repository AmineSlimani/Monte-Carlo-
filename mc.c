#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {

    srand(time(NULL));

    int L = 4 ;

    while(L<=32) {
	    
	    FILE *fichier;

	    
	    if(L == 4) {
		fichier = fopen("mc4.dat", "w");
	    }
	    else if(L == 8) {
		fichier = fopen("mc8.dat", "w");
	    }
	    else if(L == 16) {
		fichier = fopen("mc16.dat", "w");
	    }
	    else if(L == 32) {
		fichier = fopen("mc32.dat", "w");
	    }
	    else{
		fichier = fopen("mc.dat", "w");
	    }
	     
	    printf("\n \n \n L = %d \n \n \n", L);

	    int N = L * L * L;
	    int MCDISC =1000 , MCTEPS = 10000;
	    double s[L][L][L], T, KB = 1.0, J = 1.0;
	    int mc, i, j, k;
	    int ip, im, jp, jm, kp, km;
	    double sp, nv_sp, sommevoisins, r, p,pr, aim, delaE, aim_moy, aim_moy2, aim_moy4, X, U, E, E_moy, E_moy2, CV, Tpas;


	    for (i = 0; i < L; i++) {
		for (j = 0; j < L; j++) {
		    for (k = 0; k < L; k++) {
		        s[i][j][k] = 1.0;
		    }
		}
	    }

	    aim = 1.0 * N;
	    E = J * N/2.0;

	    Tpas = 0.5;

	    for (T = 0.1; T <= 2; T += Tpas) {
	    

		aim_moy = 0.0;
		aim_moy2 = 0.0;
		aim_moy4 = 0.0;
		E_moy = 0.0;
		E_moy2 = 0.0;

		for (mc = 1; mc <= MCTEPS; mc++) {
		    for (i = 0; i < L; i++) {
		        for (j = 0; j < L; j++) {
		            for (k = 0; k < L; k++) {
		                sp = s[i][j][k];

	                        pr = (double)rand() / RAND_MAX;
	                        
	                        if (pr <= 1.0 / 5.0) {
	                            nv_sp = -2.0;
	                        } else if (pr > 1.0 / 5.0 && pr <= 2.0 / 5.0) {
	                            nv_sp = -1.0;
	                        } else if (pr > 2.0 / 5.0 && pr <= 3.0 / 5.0) {
	                            nv_sp = 0.0;
	                        } else if (pr > 3.0 / 5.0 && pr <= 4.0 / 5.0) {
	                            nv_sp = 1.0;
	                        } else if (pr > 4.0 / 5.0 && pr <= 1.0) {
	                            nv_sp = 2.0;
	                        }



         			 
         	                kp = k + 1;
		                km = k - 1;
		                
		                if(k==L-1){ 
		                    kp=0;
		                }
         			if(k==0){
         			    km=L-1;
         			 }

		                sommevoisins = s[i][j][km] + s[i][j][kp];
		                delaE = -J * (nv_sp - sp) * sommevoisins;

		                if (delaE <= 0 || exp(-delaE / (KB * T)) > rand() / (double)RAND_MAX) {
		                    s[i][j][k] = nv_sp;
		                    aim = aim + nv_sp - sp;
		                    E += delaE;
		                }
		            }
		        }
		    }

		    if (mc > MCDISC) {
		        aim_moy += fabs(aim);
		        aim_moy2 += aim * aim;
		        aim_moy4 += aim * aim * aim * aim;
		        E_moy += E;
		        E_moy2 += E * E;
		    }
		}

		aim_moy /= (MCTEPS - MCDISC);
		aim_moy2 /= (MCTEPS - MCDISC);
		aim_moy4 /= (MCTEPS - MCDISC);
		E_moy /= (MCTEPS - MCDISC);
		E_moy2 /= (MCTEPS - MCDISC);

		X = (1.0 / (KB * T)) * (aim_moy2 - aim_moy * aim_moy);
		U = 1.0 - (aim_moy4 / (3.0 * aim_moy2 * aim_moy2));
		CV = (1.0 / (KB * T * T)) * (E_moy2 - E_moy * E_moy);

		printf("%.3lf \t %.3lf \t %.3lf \t %.3lf \t %.3lf\t \n", T, aim_moy / N, X / N, CV / N, U);
		fprintf(fichier, "%.3lf \t %.3lf \t %.3lf \t %.3lf\t %.3lf\t \n", T, aim_moy / N, X / N, CV / N, U);
		

	    }
	   

	    fclose(fichier);
	    L = 2*L;		    
	}

    return 0;
}

