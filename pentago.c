#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "pentago.h"

int main (){
  srand(time(NULL));
  int s=1;
  int m;
  while(s==1){
    printf("Quel type de partie voulez-vous créer ? (1 = Joueur contre joueur / 2 = Joueur contre ordinateur)\n");
    scanf("%d",&m);
    while(m!=1 && m!=2){
      printf("Valeurs incorrectes, veuillez saisir de nouveau\n");
      scanf("%d",&m);
    }
    if(m==1){
      hvsh();
    }
    else{
      hvso();
    }
    printf("Voulez vous faire une nouvelle partie ? (1 = oui / 0 = non)\n");
    scanf("%d",&s);
    while(s!=0 && s!=1){
      printf("Valeurs incorrectes, veuillez saisir de nouveau\n");
      scanf("%d",&s);
    }
  }
  exit(1);
}

void hvsh(){
  plateau plateau1;
  initp(&plateau1);
  affp(plateau1);
  int t=0;
  int g=0;
  int a,b,n;
  while(t<36){
    jouerhpion(&plateau1);
    affp(plateau1);
    g=testv(plateau1,vict);
    if(g==1){
      return;
    }
    n = jouerhplat();
    a = n / 10;
    b = n % 10;
    jouerplat(&plateau1,a,b);
    affp(plateau1);
    g=testv(plateau1,vict);
    if(g==1){
      return;
    }
    chjoueur(&plateau1);
    t++;
  }
  printf("Egalité !!!\n");
}

void hvso(){
  plateau plateau1;
  initp(&plateau1);
  affp(plateau1);
  int t=0;
  int g=0;
  int a,b,n;
  while(t<36){
    jouerhpion(&plateau1);
    affp(plateau1);
    g=testv(plateau1,vict);
    if(g==1){
      return;
    }
    n = jouerhplat();
    a = n / 10;
    b = n % 10;
    jouerplat(&plateau1,a,b);
    affp(plateau1);
    g=testv(plateau1,vict);
    if(g==1){
      return;
    }
    int l=alea();
    int c=alea();
    while(plateau1.grille[l][c]!=0){
      l=alea();
      c=alea();
    }
    plateau1.grille[l][c]=2;
    int p=palea();
    int s=salea();
    jouerplat(&plateau1,p+1,s);
    affp(plateau1);
    printf("L'ordinateur a joué en %d / %d et a tourné le plateau %d dans le sens ",l+1,c+1,p+1);
    if(s==0){
      printf("horaire.\n");}
    else{
      printf("trigo.\n");}
    t=t+2;
  }
  printf("Egalité !!!\n");
}

void chjoueur(plateau *plat){
  if((*plat).joueur==1){
    (*plat).joueur=2;
  }
  else{
    (*plat).joueur=1;
  }
}

void initp(plateau *plat){
  int i,j;
  for (i=0 ; i<6 ; i++){
    for (j=0 ; j<6 ; j++){
      (*plat).grille[i][j]=0;
    }
  }
  (*plat).joueur=1;
}

void affp(plateau plat){
  int i,j;
  printf("\n------------------------\n");
  for (i=0 ; i<6 ; i++){
    for (j=0 ; j<6 ; j++){
      printf(" %d |",plat.grille[i][j]);
    }
    printf("\n------------------------\n");
  }
  printf("\n");
}


void jouerplat(plateau *plat, int p, int s){
  int a;
  if(s==0){
    if(p==1){
      a=(*plat).grille[0][0];
      (*plat).grille[0][0]=(*plat).grille[2][0];
      (*plat).grille[2][0]=(*plat).grille[2][2];
      (*plat).grille[2][2]=(*plat).grille[0][2];
      (*plat).grille[0][2]=a;
      a=(*plat).grille[0][1];
      (*plat).grille[0][1]=(*plat).grille[1][0];
      (*plat).grille[1][0]=(*plat).grille[2][1];
      (*plat).grille[2][1]=(*plat).grille[1][2];
      (*plat).grille[1][2]=a;
    }
    else if(p==2){
      a=(*plat).grille[0][3];
      (*plat).grille[0][3]=(*plat).grille[2][3];
      (*plat).grille[2][3]=(*plat).grille[2][5];
      (*plat).grille[2][5]=(*plat).grille[0][5];
      (*plat).grille[0][5]=a;
      a=(*plat).grille[0][4];
      (*plat).grille[0][4]=(*plat).grille[1][3];
      (*plat).grille[1][3]=(*plat).grille[2][4];
      (*plat).grille[2][4]=(*plat).grille[1][5];
      (*plat).grille[1][5]=a;
    }
    else if(p==3){
      a=(*plat).grille[3][0];
      (*plat).grille[3][0]=(*plat).grille[5][0];
      (*plat).grille[5][0]=(*plat).grille[5][2];
      (*plat).grille[5][2]=(*plat).grille[3][2];
      (*plat).grille[3][2]=a;
      a=(*plat).grille[3][1];
      (*plat).grille[3][1]=(*plat).grille[4][0];
      (*plat).grille[4][0]=(*plat).grille[5][1];
      (*plat).grille[5][1]=(*plat).grille[4][2];
      (*plat).grille[4][2]=a;
    }
    else{
      a=(*plat).grille[3][3];
      (*plat).grille[3][3]=(*plat).grille[5][3];
      (*plat).grille[5][3]=(*plat).grille[5][5];
      (*plat).grille[5][5]=(*plat).grille[3][5];
      (*plat).grille[3][5]=a;
      a=(*plat).grille[3][4];
      (*plat).grille[3][4]=(*plat).grille[4][3];
      (*plat).grille[4][3]=(*plat).grille[5][4];
      (*plat).grille[5][4]=(*plat).grille[4][5];
      (*plat).grille[4][5]=a;
    }
  }
  else{
    if(p==1){
      a=(*plat).grille[0][0];
      (*plat).grille[0][0]=(*plat).grille[0][2];
      (*plat).grille[0][2]=(*plat).grille[2][2];
      (*plat).grille[2][2]=(*plat).grille[2][0];
      (*plat).grille[2][0]=a;
      a=(*plat).grille[0][1];
      (*plat).grille[0][1]=(*plat).grille[1][2];
      (*plat).grille[1][2]=(*plat).grille[2][1];
      (*plat).grille[2][1]=(*plat).grille[1][0];
      (*plat).grille[1][0]=a;
    }
    else if(p==2){
      a=(*plat).grille[0][3];
      (*plat).grille[0][3]=(*plat).grille[0][5];
      (*plat).grille[0][5]=(*plat).grille[2][5];
      (*plat).grille[2][5]=(*plat).grille[2][3];
      (*plat).grille[2][3]=a;
      a=(*plat).grille[0][4];
      (*plat).grille[0][4]=(*plat).grille[1][5];
      (*plat).grille[1][5]=(*plat).grille[2][4];
      (*plat).grille[2][4]=(*plat).grille[1][3];
      (*plat).grille[1][3]=a;
    }
    else if(p==3){
      a=(*plat).grille[3][0];
      (*plat).grille[3][0]=(*plat).grille[3][2];
      (*plat).grille[3][2]=(*plat).grille[5][2];
      (*plat).grille[5][2]=(*plat).grille[5][0];
      (*plat).grille[5][0]=a;
      a=(*plat).grille[3][1];
      (*plat).grille[3][1]=(*plat).grille[4][2];
      (*plat).grille[4][2]=(*plat).grille[5][1];
      (*plat).grille[5][1]=(*plat).grille[4][0];
      (*plat).grille[4][0]=a;
    }
    else{
      a=(*plat).grille[3][3];
      (*plat).grille[3][3]=(*plat).grille[3][5];
      (*plat).grille[3][5]=(*plat).grille[5][5];
      (*plat).grille[5][5]=(*plat).grille[5][3];
      (*plat).grille[5][3]=a;
      a=(*plat).grille[3][4];
      (*plat).grille[3][4]=(*plat).grille[4][5];
      (*plat).grille[4][5]=(*plat).grille[5][4];
      (*plat).grille[5][4]=(*plat).grille[4][3];
      (*plat).grille[4][3]=a;
    }
  }
}

int testv(plateau plat, int v[]){
  int i;
  int g=0;
  for(i=0 ; i<160 ; i=i+5){
    if(plat.grille[v[i]/10][v[i]%10]==plat.grille[v[i+1]/10][v[i+1]%10]&&
       plat.grille[v[i]/10][v[i]%10]==plat.grille[v[i+2]/10][v[i+2]%10]&&
       plat.grille[v[i]/10][v[i]%10]==plat.grille[v[i+3]/10][v[i+3]%10]&&
       plat.grille[v[i]/10][v[i]%10]==plat.grille[v[i+4]/10][v[i+4]%10]&&
       plat.grille[v[i]/10][v[i]%10]!=0){
      printf("Victoire du joueur %d !!!\n",plat.grille[v[i]/10][v[i]%10]);
      g=1;
    }
  }
  return g;
}

void jouerhpion(plateau *plat){
  int l,c,n;
  int p=(*plat).joueur;
  printf("Joueur %d, sur quelle ligne voulez-vous jouer votre pion ?\n",p);
  scanf("%d",&l);
  while(l<1 || l>6){
    printf("Le numéro de ligne doît être comprit entre 1 et 6, veuillez recommencer.\n");
    scanf("%d",&l);
  }
  printf("Quelle colonne ?\n");
  scanf("%d",&c);
  while(c<1 || c>6){
    printf("Le numéro de colonne doît être comprit entre 1 et 6, veuillez recommencer.\n");
    scanf("%d",&c);
  }
  if((*plat).grille[l-1][c-1]==0){
    (*plat).grille[l-1][c-1]=p;
  }
  else{
    while((*plat).grille[l-1][c-1]!=0){
      printf("Il y a déjà un pion sur cette case, veuillez choisir une autre case.\n");
      printf("Ligne ?\n");
      scanf("%d",&l);
      printf("Colonne ?\n");
      scanf("%d",&c);
    }
    (*plat).grille[l-1][c-1]=p;
    printf("\n");
  }
}

int jouerhplat(){
  int p,s,n;
  printf("Quel plateau voulez-vous tourner ? 1 2\n                                   3 4\n");
  scanf("%d",&p);
  while(p<1 || p>4){
    printf("Le numéro de plateau doît être comprit entre 1 et 4, veuillez recommencer.\n");
    scanf("%d",&p);
  }
  printf("Dans quel sens ? (0 = sens horaire / 1 = sens trigo)\n");
  scanf("%d",&s);
  while(s<0 || s>1){
    printf("Le sens doît être 0 ou 1, veuillez recommencez.\n");
    scanf("%d",&s);
  }
  n = p*10 + s;
  printf("\n");
  return n;
}

int alea(){
  int n;
  n=rand()%6;
  return n;
}

int palea(){
  int n;
  n=rand()%4;
  return n;
}

int salea(){
  int n;
  n=rand()%2;
  return n;
}
