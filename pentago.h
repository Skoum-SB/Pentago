typedef struct plateau plateau;
struct plateau{
  int grille[6][6];
  int joueur;
};

int vict[]={00,10,20,30,40,
	    	10,20,30,40,50,
		    01,11,21,31,41,
	    	11,21,31,41,51,
		    02,12,22,32,42,
		    12,22,32,42,52,
		    03,13,23,33,43,
		    13,23,33,43,53,
		    04,14,24,34,44,
		    14,24,34,44,54,
		    05,15,25,35,45,
			15,25,35,45,55,
		    00,01,02,03,04,
		    01,02,03,04,05,
		    10,11,12,13,14,
		    11,12,13,14,15,
	  		20,21,22,23,24,
	 	   	21,22,23,24,25,
	 	  	30,31,32,33,34,
	    	31,32,33,34,35,
	    	40,41,42,43,44,
	    	41,42,43,44,45,
	    	50,51,52,53,54,
	    	51,52,53,54,55,
	    	10,21,32,43,54,
	    	00,11,22,33,44,
	    	11,22,33,44,55,
	    	01,12,23,34,45,
	    	04,13,22,31,40,
	    	05,14,23,32,41,
	    	14,23,32,41,50,
	    	15,24,33,42,51};

void initp(plateau *plat);

void affp(plateau plat);

void jouerplat(plateau *plat, int p ,int s);

int testv(plateau plat, int v[]);

void jouerhum(plateau *plat, int vict[]);

void chjoueur(plateau *plat);

void jouerhpion(plateau *plat);

int jouerhplat();

void hvsh();

void hvso();

int alea();

int palea();

int salea();
