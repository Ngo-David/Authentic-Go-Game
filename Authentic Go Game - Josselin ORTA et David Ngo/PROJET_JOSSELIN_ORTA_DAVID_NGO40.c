#include "graphics.h"
#include <stdio.h>
#include <string.h>
#include "couleur.h"
#include "police.h"

#define taille_t 20

void menu_gagner(int tableau[taille_t][taille_t])
{
POINT p,p1,p2;
p1.x=400-125;p1.y=450+20;p2.x=400+125;p2.y=450-20;
affiche_image("rejouer.bmp", p1, 50, 100);
p1.x=400-125;p1.y=400+20;p2.x=400+125;p2.y=400-20;
affiche_image("revenir_au_menu.bmp", p1, 50, 100);
p1.x=400-125;p1.y=350+20;p2.x=400+125;p2.y=350-20;
affiche_image("quitter.bmp", p1, 50, 100);

synchro();
affiche_auto_on();

p=wait_clic();
int i=0;
//rejouer
while (i==0)
{
if(p.x>=400-125 && p.x<=400+125 && p.y>=450-20 && p.y<=450+20)
	{
	p1.x=400-125;p1.y=450+20;
	affiche_image("rejouer2.bmp", p1, 50, 100);
	synchro();
	attendre(300);
    plateau(tableau);
	jeu(tableau);
	}
//revenir au menu
if(p.x>=400-125 && p.x<=400+125 && p.y>=400-20 && p.y<=400+20)
	{
	p1.x=400-125;p1.y=400+20;
	affiche_image("revenir_au_menu2.bmp", p1, 50, 100);
	synchro();
	attendre(300);
    menu(tableau);
	}
//quitter
if(p.x>=400-125 && p.x<=400+125 && p.y>=350-20 && p.y<=350+20)
	{
	p1.x=400-125;p1.y=350+20;
	affiche_image("quitter2.bmp", p1, 50, 100);
	synchro();
	attendre(300);
    exit(0);
	}
	p=wait_clic();
}
}


void menu_perdu(int mode,int j1,int j2,int tableau[taille_t][taille_t])
{
POINT p,p1,p2;
p1.x=400-125;p1.y=450+20;p2.x=400+125;p2.y=450-20;
affiche_image("rejouer.bmp", p1, 50, 100);
p1.x=400-125;p1.y=400+20;p2.x=400+125;p2.y=400-20;
affiche_image("revenir_au_menu.bmp", p1, 50, 100);
p1.x=400-125;p1.y=350+20;p2.x=400+125;p2.y=350-20;
affiche_image("quitter.bmp", p1, 50, 100);

if(j1==1) //les noir gagne
{

p.x=150;p.y=600;

aff_pol("Les noirs sont victorieux", 40, p, blanc);
p.x=150;p.y=550;
aff_pol("        par abandon", 40, p, blanc);
}
if(j1==2) //les blanc gagne
{

p.x=150;p.y=600;

aff_pol("Les blanc sont victorieux", 40, p, blanc);	
p.x=150;p.y=550;
aff_pol("        par abandon", 40, p, blanc);
}

synchro();
affiche_auto_on();

p=wait_clic();
int i=0;
//rejouer
while (i==0)
{
if(p.x>=400-125 && p.x<=400+125 && p.y>=450-20 && p.y<=450+20 && mode==1)
	{
	p1.x=400-125;p1.y=450+20;
	affiche_image("rejouer2.bmp", p1, 50, 100);
	synchro();
	attendre(300);
    plateau(tableau);
	jeu(tableau);
	}
if(p.x>=400-125 && p.x<=400+125 && p.y>=450-20 && p.y<=450+20 && mode==2)
	{
	p1.x=400-125;p1.y=450+20;
	affiche_image("rejouer2.bmp", p1, 50, 100);
	synchro();
	attendre(300);
    plateau(tableau);
	jeu_solo(tableau);
	}
if(p.x>=400-125 && p.x<=400+125 && p.y>=450-20 && p.y<=450+20 && mode==3)
	{
	p1.x=400-125;p1.y=450+20;
	affiche_image("rejouer2.bmp", p1, 50, 100);
	synchro();
	attendre(300);
    plateau(tableau);
	jeu_automate(tableau);
	}
//revenir au menu
if(p.x>=400-125 && p.x<=400+125 && p.y>=400-20 && p.y<=400+20)
	{
	p1.x=400-125;p1.y=400+20;
	affiche_image("revenir_au_menu2.bmp", p1, 50, 100);
	synchro();
	attendre(300);
    menu(tableau);
	}
//quitter
if(p.x>=400-125 && p.x<=400+125 && p.y>=350-20 && p.y<=350+20)
	{
	p1.x=400-125;p1.y=350+20;
	affiche_image("quitter2.bmp", p1, 50, 100);
	synchro();
	attendre(300);
    exit(0);
	}
	p=wait_clic();
}
}



POINT pointeur(int mode,int j1,int j2,int tableau[taille_t][taille_t]) //return le point joué
{
POINT p;
int i=0,c_colonnes,c_lignes;
p=wait_clic();

while(i==0)
{
	if(p.x<=50 || p.x>=750 || p.y<=50 || p.y>=750)
	{
	if(p.x>=400-125 && p.x<=400+125 && p.y>=50-40 && p.y<=50) //si le joueur clique sur abandonner
	{
	p.x=400-125;p.y=50;
	affiche_image("abandonner2.bmp", p, 50, 100);
			for(c_colonnes=1;c_colonnes<14;c_colonnes++)
		{
			for(c_lignes=1;c_lignes<14;c_lignes++)
			{
				tableau[c_colonnes][c_lignes]=0;
		}
		}
	attendre(300);
	menu_perdu(mode,j1,j2,tableau);

	}
	
	p=wait_clic();
	}
	else
	{
	p.x=((p.x-25)/50+1)*50;p.y=((p.y-25)/50+1)*50; //centre le point
	i=1;
	}
}
return p;
}



void piece_b(POINT p) //affiche une piece blanche
{
p.x=p.x-25;p.y=p.y+25;
affiche_image("blanc.bmp", p, 50, 100);
}

void piece_n(POINT p) //affiche une piece blanche
{
p.x=p.x-25;p.y=p.y+25;
affiche_image("noir.bmp", p, 50, 100);
}

void cercle_centre(POINT p,COULEUR c) //fonction test
{
draw_fill_circle(p,47,c);
}

void nb_piece(int tableau[taille_t][taille_t])
{
POINT p1,p2;

int score=0,score2=0,c_colonnes=1,c_lignes=1;

	for(c_colonnes=1;c_colonnes<14;c_colonnes++)
	{
	for(c_lignes=1;c_lignes<14;c_lignes++)
		{
		if(tableau[c_colonnes][c_lignes]==1)
		{
		score=(score+1);
		}
		if(tableau[c_colonnes][c_lignes]==2)
		{
		score2=(score2+1);
		}
	}
	}
if(score >= 0 && score < 10) // les if permettent de centrer les chiffres
{
p1.x=25;p1.y=785;
p2.x=25+25;p2.y=785-13;
affiche_image("nb_piece_b.bmp", p1, 50, 100);
aff_int(score, 30, p2, noir); //nb de piece blanche sur le plateau
}
if(score >= 10 && score < 100)
{
p1.x=25;p1.y=785;
p2.x=15+25;p2.y=785-13;
affiche_image("nb_piece_b.bmp", p1, 50, 100);
aff_int(score, 30, p2, noir); //nb de piece blanche sur le plateau
}
if(score >= 100)
{
p1.x=25;p1.y=785;
p2.x=5+25;p2.y=785-13;
affiche_image("nb_piece_b.bmp", p1, 50, 100);
aff_int(score, 30, p2, noir); //nb de piece blanche sur le plateau
}

if(score2 >= 0 && score2 < 10) // les if permettent de centrer les chiffres
{
p1.x=710;p1.y=785;
p2.x=710+25;p2.y=785-13;
affiche_image("nb_piece_n.bmp", p1, 50, 100);
aff_int(score2, 30, p2, blanc); //nb de piece noir sur le plateau
}
if(score2 >= 10 && score2 < 100)
{
p1.x=710;p1.y=785;
p2.x=700+25;p2.y=785-13;
affiche_image("nb_piece_n.bmp", p1, 50, 100);
aff_int(score2, 30, p2, blanc); //nb de piece noir sur le plateau
}
if(score2 >= 100)
{
p1.x=710;p1.y=785;
p2.x=690+25;p2.y=785-13;
affiche_image("nb_piece_n.bmp", p1, 50, 100);
aff_int(score2, 30, p2, blanc); //nb de piece noir sur le plateau
}

}


//validée
int nb_colonnes(POINT p) //Fonction qui permet de mettre l'emplacement de la colonne de la pièce jouée dans le tableau.
{
int i,c_colonnes=1; //c_colonnes est une valeur du tableau
POINT p2;
p2.y=100;
for(i=1;i<15;i++)
{ 
if(p.y==p2.y)
{
c_colonnes=c_colonnes;
return c_colonnes;
}
else
{
p2.y=p2.y+50;
c_colonnes=c_colonnes+1;
}
}
return 0;
}


//validée
int nb_lignes(POINT p) //Fonction qui permet de mettre l'emplacement de la ligne de la pièce jouée dans le tableau.
{
int i,c_lignes=1; //c_ligne est une valeur du tableau
POINT p2;
p2.x=100;
for(i=1;i<15;i++)
{ 
if(p.x==p2.x)
{
c_lignes=c_lignes;
return c_lignes;
}
else
{
p2.x=p2.x+50;
c_lignes=c_lignes+1;
}
}
return 0;
}


void plateau(int tableau[taille_t][taille_t]) //Créer le plateau
{
affiche_auto_off();

POINT p;
p.x=0,p.y=800;

affiche_image("plateau.bmp", p, 50, 100);

p.x=400-125;p.y=50;
affiche_image("abandonner.bmp", p, 50, 100); //rajoute le bouton abandonner

POINT p1;
POINT p2;
int abscisse=100;
while(abscisse <= 700)
{
p1.x = abscisse; p1.y = 100;
p2.x = abscisse; p2.y = 700;
draw_line(p1,p2,noir);
abscisse = abscisse+50;
}

int ord=100;
while(ord <= 700)
{
p1.x = 100; p1.y = ord;
p2.x = 700; p2.y = ord;
draw_line(p1,p2,noir);
ord = ord+50;
}

int c_colonnes=1,c_lignes=1;

for(c_colonnes=1;c_colonnes<14;c_colonnes++) //recharge les pieces
{
for(c_lignes=1;c_lignes<14;c_lignes++)
{
			if(tableau[c_colonnes][c_lignes]==2)
			{
			p.y=100+((c_colonnes-1)*50);p.x=100+((c_lignes-1)*50);
			piece_n(p);
			}
			if(tableau[c_colonnes][c_lignes]==1)
			{
			p.y=100+((c_colonnes-1)*50);p.x=100+((c_lignes-1)*50);
			piece_b(p);
			}
}
}
nb_piece(tableau); //affiche le nombre de piece
synchro();
affiche_auto_on();
}



//pas besoin de return, le tableau se modifie directement dans la mémoire
void bordure(int tableau[taille_t][taille_t]) //fonction qui permet d'attribuer aux contours du plateau une variable correspondante sur le tableau
{
int c_colonnes=0,c_lignes=0;

for(c_colonnes=0;c_colonnes<15;c_colonnes++)
{
tableau[c_colonnes][c_lignes]=3;
}
for(c_colonnes=0;c_colonnes<15;c_colonnes++)
{
c_lignes=14;
tableau[c_colonnes][c_lignes]=3;
}
c_colonnes=0;
for(c_lignes=0;c_lignes<15;c_lignes++)
{
tableau[c_colonnes][c_lignes]=3;
}
for(c_lignes=0;c_lignes<15;c_lignes++)
{
c_colonnes=14;
tableau[c_colonnes][c_lignes]=3;
}
}








POINT bloquer(int mode,POINT p,int j1,int j2,int tableau[taille_t][taille_t]) //bloque les piece jouées sur des pièces déjà jouées.
{
POINT p1;
p1.x=375;p1.y=795;
int r=0;
p=pointeur(mode,j1,j2,tableau);
int c_colonnes=nb_colonnes(p),c_lignes=nb_lignes(p);
int i=0,j=0,k=0;
int j3;

while(i==0)
{
	
	if((tableau[c_colonnes][c_lignes]>=1)
	//bloque la mise en place d'une piece sur une autre
	|| ((tableau[c_colonnes+1][c_lignes]==j2) && (tableau[c_colonnes][c_lignes+1]==j2) && (tableau[c_colonnes-1][c_lignes]==j2) && (tableau[c_colonnes][c_lignes-1]==j2))
	//bloque la mise en place d'une piece au milieu de 4 piece ennemi sauf exception plus bas
	|| ((tableau[c_colonnes+1][c_lignes]==3) && (tableau[c_colonnes][c_lignes+1]==j2) && (tableau[c_colonnes-1][c_lignes]==j2) && (tableau[c_colonnes][c_lignes-1]==j2))
	|| ((tableau[c_colonnes+1][c_lignes]==j2) && (tableau[c_colonnes][c_lignes+1]==3) && (tableau[c_colonnes-1][c_lignes]==j2) && (tableau[c_colonnes][c_lignes-1]==j2))
	|| ((tableau[c_colonnes+1][c_lignes]==j2) && (tableau[c_colonnes][c_lignes+1]==j2) && (tableau[c_colonnes-1][c_lignes]==3) && (tableau[c_colonnes][c_lignes-1]==j2))
	|| ((tableau[c_colonnes+1][c_lignes]==j2) && (tableau[c_colonnes][c_lignes+1]==j2) && (tableau[c_colonnes-1][c_lignes]==j2) && (tableau[c_colonnes][c_lignes-1]==3))
	//même fonction mais avec les bordures
    || ((tableau[c_colonnes+1][c_lignes]==3) && (tableau[c_colonnes][c_lignes+1]==3) && (tableau[c_colonnes-1][c_lignes]==j2) && (tableau[c_colonnes][c_lignes-1]==j2))
	|| ((tableau[c_colonnes+1][c_lignes]==j2) && (tableau[c_colonnes][c_lignes+1]==3) && (tableau[c_colonnes-1][c_lignes]==3) && (tableau[c_colonnes][c_lignes-1]==j2))
	|| ((tableau[c_colonnes+1][c_lignes]==j2) && (tableau[c_colonnes][c_lignes+1]==j2) && (tableau[c_colonnes-1][c_lignes]==3) && (tableau[c_colonnes][c_lignes-1]==3))
	|| ((tableau[c_colonnes+1][c_lignes]==3) && (tableau[c_colonnes][c_lignes+1]==j2) && (tableau[c_colonnes-1][c_lignes]==j2) && (tableau[c_colonnes][c_lignes-1]==3)))
	//même fonction mais avec les coins
	{
	if((tableau[c_colonnes][c_lignes]==0) && (((tableau[c_colonnes+2][c_lignes]==j1) && (tableau[c_colonnes+1][c_lignes+1]==j1) && (tableau[c_colonnes+1][c_lignes-1]==j1))
	|| ((tableau[c_colonnes][c_lignes+2]==j1) && (tableau[c_colonnes+1][c_lignes+1]==j1) && (tableau[c_colonnes-1][c_lignes+1]==j1))
	|| ((tableau[c_colonnes-1][c_lignes+1]==j1) && (tableau[c_colonnes-2][c_lignes]==j1) && (tableau[c_colonnes-1][c_lignes-1]==j1))
	|| ((tableau[c_colonnes-1][c_lignes-1]==j1) && (tableau[c_colonnes][c_lignes-2]==j1) && (tableau[c_colonnes+1][c_lignes-1]==j1))
	
	
    //si le milieux de 4 piece du joueur2 est vide et que une de ses 4 piece est entouré de 3 piece du joueur1 alors le joueur1 peut placer la pièce
   	|| ((tableau[c_colonnes+1][c_lignes]==3) && (tableau[c_colonnes][c_lignes+1]==j1) && (tableau[c_colonnes-1][c_lignes]==j1) && (tableau[c_colonnes][c_lignes-1]==j1))
	|| ((tableau[c_colonnes+1][c_lignes]==j1) && (tableau[c_colonnes][c_lignes+1]==3) && (tableau[c_colonnes-1][c_lignes]==j1) && (tableau[c_colonnes][c_lignes-1]==j1))
	|| ((tableau[c_colonnes+1][c_lignes]==j1) && (tableau[c_colonnes][c_lignes+1]==j1) && (tableau[c_colonnes-1][c_lignes]==3) && (tableau[c_colonnes][c_lignes-1]==j1))
	|| ((tableau[c_colonnes+1][c_lignes]==j1) && (tableau[c_colonnes][c_lignes+1]==j1) && (tableau[c_colonnes-1][c_lignes]==j1) && (tableau[c_colonnes][c_lignes-1]==3))
	//même fonction mais avec les bordures
    || ((tableau[c_colonnes+2][c_lignes]==j1) && (tableau[c_colonnes+1][c_lignes-1]==j1) && (tableau[c_colonnes][c_lignes-2]==j1) && (tableau[c_colonnes][c_lignes+1]==3) && (tableau[c_colonnes-1][c_lignes]==3))
    || ((tableau[c_colonnes+2][c_lignes]==j1) && (tableau[c_colonnes+1][c_lignes+1]==j1) && (tableau[c_colonnes][c_lignes+2]==j1) && (tableau[c_colonnes-1][c_lignes]==3) && (tableau[c_colonnes][c_lignes-1]==3))
    || ((tableau[c_colonnes][c_lignes+2]==j1) && (tableau[c_colonnes-1][c_lignes+1]==j1) && (tableau[c_colonnes-2][c_lignes]==j1) && (tableau[c_colonnes][c_lignes-1]==3) && (tableau[c_colonnes+1][c_lignes]==3))
    || ((tableau[c_colonnes][c_lignes-2]==j1) && (tableau[c_colonnes-1][c_lignes-1]==j1) && (tableau[c_colonnes-2][c_lignes]==j1) && (tableau[c_colonnes+1][c_lignes]==3) && (tableau[c_colonnes][c_lignes+1]==3))))
	//même fonction mais avec les coins
	{
	i=1; //serrure
	j=1; //serrure
	}
	else
	{
	i=0;
	}
	}
	else
	{
	i=1;
	}

	
if(i==1 && j==0)
{
//bloque le suicide de ses propres pieces
j3=tableau[c_colonnes][c_lignes]; //j3 récupère la valeur du tableau

tableau[c_colonnes][c_lignes]=j1; //permet de considéré la piece qui vien d'être posé dans bloquer_if_groupe
r=bloquer_if_groupe(j1,j2,tableau); //r=0 etant : il n'y a pas de piece allié détruit et r>=1 : cet emplacement provoque la destruction de piece alliés
tableau[c_colonnes][c_lignes]=j3; //remet l'emplacement comme il etait

if(r>=1)
{
	r=0;
	i=0;
}
}
//si je suis sur une case vierge et que je suis entouré de 4 ennemi
if((tableau[c_colonnes][c_lignes]==0) && (tableau[c_colonnes+1][c_lignes]>=1) && (tableau[c_colonnes-1][c_lignes]>=1) && (tableau[c_colonnes][c_lignes+1]>=1) && (tableau[c_colonnes][c_lignes-1]>=1))
{
//permet de poser une piece si je detruit celle de mon ennemi
j3=tableau[c_colonnes][c_lignes]; //j3 récupère la valeur du tableau

tableau[c_colonnes][c_lignes]=j1; //permet de considéré la piece qui vien d'être posé dans bloquer_if_groupe
r=permettre_if_desgroupe(j1,j2,tableau); //r=0 etant : il n'y a pas de piece allié détruit et r>=1 : cet emplacement provoque la destruction de piece alliés
tableau[c_colonnes][c_lignes]=j3; //remet l'emplacement comme il etait
}


if(r>=1)
{
	r=0;
	i=1;
}


if(i==0)
{
	affiche_image("impossible.bmp", p1, 50, 100);
	synchro();
	p=pointeur(mode,j1,j2,tableau);
	c_colonnes=nb_colonnes(p);
	c_lignes=nb_lignes(p);
	k=1;
}
	

}
if(k==1)
{
plateau(tableau);
}
return p;
}


int permettre_if_desgroupe(int j1,int j2,int tableau[taille_t][taille_t])
{

int c_colonnes=1,c_lignes=1; //variable qui va spécifier le groupe dont fait partie la piece
int groupe=11; //variable qui va spécifier le groupe dont fait partie la piece

//la fonction scan tout le tableau
for(c_colonnes=1;c_colonnes<14;c_colonnes++)
{
for(c_lignes=1;c_lignes<14;c_lignes++)
{
//La piece prend une valeur supérieur a 10 si elle est entouré de piece différente de 0
if((tableau[c_colonnes][c_lignes]==j2) && ((tableau[c_colonnes+1][c_lignes]!=0) && (tableau[c_colonnes][c_lignes+1]!=0) && (tableau[c_colonnes-1][c_lignes]!=0) && (tableau[c_colonnes][c_lignes-1]!=0)))

{
tableau[c_colonnes][c_lignes]=groupe;

groupe=groupe+1; //chaque piece qui respecte les conditions se voit attribuer une valeur differente dans le tableau.
}
}
}


//compare si les pieces a cote ont les plus petite valeurs pour choisir la valeur la plus petite a attribué a la piece en position c_colonnes/c_lignes

for(c_colonnes=1;c_colonnes<14;c_colonnes++)
{
for(c_lignes=1;c_lignes<14;c_lignes++)
{
if(tableau[c_colonnes][c_lignes]>=10)
{
if((tableau[c_colonnes+1][c_lignes] >= 10) && (tableau[c_colonnes+1][c_lignes] < tableau[c_colonnes][c_lignes]))
{
tableau[c_colonnes][c_lignes]=tableau[c_colonnes+1][c_lignes];

c_colonnes=1;c_lignes=1; //relance les boucles tant que des chiffres sup a 10 qui se touche sont différents
}

if((tableau[c_colonnes-1][c_lignes] >= 10) && (tableau[c_colonnes-1][c_lignes] < tableau[c_colonnes][c_lignes]))
{
tableau[c_colonnes][c_lignes]=tableau[c_colonnes-1][c_lignes];

c_colonnes=1;c_lignes=1; //relance les boucles tant que des chiffres sup a 10 qui se touche sont différents
}

if((tableau[c_colonnes][c_lignes+1] >= 10) && (tableau[c_colonnes][c_lignes+1] < tableau[c_colonnes][c_lignes]))
{
tableau[c_colonnes][c_lignes]=tableau[c_colonnes][c_lignes+1];

c_colonnes=1;c_lignes=1; //relance les boucles tant que des chiffres sup a 10 qui se touche sont différents
}

if((tableau[c_colonnes][c_lignes-1] >= 10) && (tableau[c_colonnes][c_lignes-1] < tableau[c_colonnes][c_lignes]))
{
tableau[c_colonnes][c_lignes]=tableau[c_colonnes][c_lignes-1];

c_colonnes=1;c_lignes=1; //relance les boucles tant que des chiffres sup a 10 qui se touche sont différents
}

}
}
}


//le scaner va verifier si un 2 est a coté d'une piece > 10 si oui, on prend sa valeur et toute les pieces qui possede cette valeur sont remis comme ils étaient
for(c_colonnes=1;c_colonnes<14;c_colonnes++)
{
for(c_lignes=1;c_lignes<14;c_lignes++)
{
if(tableau[c_colonnes][c_lignes]>=10)
{
//les if vont comparer si les pieces a cote sont les plus petite pour choisir la valeur la plus petite a attribué a la piece en position c_colonnes/c_lignes
if(tableau[c_colonnes+1][c_lignes]==j2 || tableau[c_colonnes-1][c_lignes]==j2 || tableau[c_colonnes][c_lignes-1]==j2 || tableau[c_colonnes][c_lignes+1]==j2)
{
	groupe=tableau[c_colonnes][c_lignes]; //la variable groupe prend la valeur de la piece qui est a coté d'un 2

	for(c_colonnes=1;c_colonnes<14;c_colonnes++)
	{
	for(c_lignes=1;c_lignes<14;c_lignes++)
	{
		if(tableau[c_colonnes][c_lignes]==groupe)
			{
			tableau[c_colonnes][c_lignes]=j2;
			}
	}
	}
c_colonnes=1;c_lignes=1; //relance les boucles tant que des chiffres sup a 10 qui se touche sont différents
}
}
}
}

int r=0;

for(c_colonnes=1;c_colonnes<14;c_colonnes++) //rechange les piece qui ont changer de valeur en j1
{
for(c_lignes=1;c_lignes<14;c_lignes++)
{
if(tableau[c_colonnes][c_lignes]>=10)
{
tableau[c_colonnes][c_lignes]=j2;
r=r+1;
}
}
}

return r;

}//fin




int bloquer_if_groupe(int j1,int j2,int tableau[taille_t][taille_t])
{

int c_colonnes=1,c_lignes=1; //variable qui va spécifier le groupe dont fait partie la piece
int groupe=11; //variable qui va spécifier le groupe dont fait partie la piece

//la fonction scan tout le tableau
for(c_colonnes=1;c_colonnes<14;c_colonnes++)
{
for(c_lignes=1;c_lignes<14;c_lignes++)
{
//La piece prend une valeur supérieur a 10 si elle est entouré de piece différente de 0
if((tableau[c_colonnes][c_lignes]==j1) && ((tableau[c_colonnes+1][c_lignes]!=0) && (tableau[c_colonnes][c_lignes+1]!=0) && (tableau[c_colonnes-1][c_lignes]!=0) && (tableau[c_colonnes][c_lignes-1]!=0)))

{
tableau[c_colonnes][c_lignes]=groupe;

groupe=groupe+1; //chaque piece qui respecte les conditions se voit attribuer une valeur differente dans le tableau.
}
}
}


//compare si les pieces a cote ont les plus petite valeurs pour choisir la valeur la plus petite a attribué a la piece en position c_colonnes/c_lignes

for(c_colonnes=1;c_colonnes<14;c_colonnes++)
{
for(c_lignes=1;c_lignes<14;c_lignes++)
{
if(tableau[c_colonnes][c_lignes]>=10)
{
if((tableau[c_colonnes+1][c_lignes] >= 10) && (tableau[c_colonnes+1][c_lignes] < tableau[c_colonnes][c_lignes]))
{
tableau[c_colonnes][c_lignes]=tableau[c_colonnes+1][c_lignes];

c_colonnes=1;c_lignes=1; //relance les boucles tant que des chiffres sup a 10 qui se touche sont différents
}

if((tableau[c_colonnes-1][c_lignes] >= 10) && (tableau[c_colonnes-1][c_lignes] < tableau[c_colonnes][c_lignes]))
{
tableau[c_colonnes][c_lignes]=tableau[c_colonnes-1][c_lignes];

c_colonnes=1;c_lignes=1; //relance les boucles tant que des chiffres sup a 10 qui se touche sont différents
}

if((tableau[c_colonnes][c_lignes+1] >= 10) && (tableau[c_colonnes][c_lignes+1] < tableau[c_colonnes][c_lignes]))
{
tableau[c_colonnes][c_lignes]=tableau[c_colonnes][c_lignes+1];

c_colonnes=1;c_lignes=1; //relance les boucles tant que des chiffres sup a 10 qui se touche sont différents
}

if((tableau[c_colonnes][c_lignes-1] >= 10) && (tableau[c_colonnes][c_lignes-1] < tableau[c_colonnes][c_lignes]))
{
tableau[c_colonnes][c_lignes]=tableau[c_colonnes][c_lignes-1];

c_colonnes=1;c_lignes=1; //relance les boucles tant que des chiffres sup a 10 qui se touche sont différents
}

}
}
}


//le scaner va verifier si un 2 est a coté d'une piece > 10 si oui, on prend sa valeur et toute les pieces qui possede cette valeur sont remis comme ils étaient
for(c_colonnes=1;c_colonnes<14;c_colonnes++)
{
for(c_lignes=1;c_lignes<14;c_lignes++)
{
if(tableau[c_colonnes][c_lignes]>=10)
{
//les if vont comparer si les pieces a cote sont les plus petite pour choisir la valeur la plus petite a attribué a la piece en position c_colonnes/c_lignes
if(tableau[c_colonnes+1][c_lignes]==j1 || tableau[c_colonnes-1][c_lignes]==j1 || tableau[c_colonnes][c_lignes-1]==j1 || tableau[c_colonnes][c_lignes+1]==j1)
{
	groupe=tableau[c_colonnes][c_lignes]; //la variable groupe prend la valeur de la piece qui est a coté d'un 2

	for(c_colonnes=1;c_colonnes<14;c_colonnes++)
	{
	for(c_lignes=1;c_lignes<14;c_lignes++)
	{
		if(tableau[c_colonnes][c_lignes]==groupe)
			{
			tableau[c_colonnes][c_lignes]=j1;
			}
	}
	}
c_colonnes=1;c_lignes=1; //relance les boucles tant que des chiffres sup a 10 qui se touche sont différents
}
}
}
}

int r=0;

for(c_colonnes=1;c_colonnes<14;c_colonnes++) //rechange les piece qui ont changer de valeur en j1
{
for(c_lignes=1;c_lignes<14;c_lignes++)
{
if(tableau[c_colonnes][c_lignes]>=10)
{
tableau[c_colonnes][c_lignes]=j1;
r=r+1;
}
}
}

return r;

}//fin


void manger_groupe(COULEUR c2,COULEUR c1,int j1,int j2,int tableau[taille_t][taille_t]) //fonction ultime qui a pour but d'éradiquer tout groupe de piece encerclé par des pièces ennemies
{
affiche_auto_off();	
	
	
POINT p;
int c_colonnes=1,c_lignes=1; //variable qui va spécifier le groupe dont fait partie la piece
int groupe=11; //variable qui va spécifier le groupe dont fait partie la piece

//la fonction scan tout le tableau
for(c_colonnes=1;c_colonnes<14;c_colonnes++)
{
for(c_lignes=1;c_lignes<14;c_lignes++)
{
//La piece prend une valeur supérieur a 10 si elle est entouré de piece différente de 0
if((tableau[c_colonnes][c_lignes]==j2) && ((tableau[c_colonnes+1][c_lignes]!=0) && (tableau[c_colonnes][c_lignes+1]!=0) && (tableau[c_colonnes-1][c_lignes]!=0) && (tableau[c_colonnes][c_lignes-1]!=0)))

{
tableau[c_colonnes][c_lignes]=groupe;
groupe=groupe+1; //chaque piece qui respecte les conditions se voit attribuer une valeur differente dans le tableau.
}
}
}


//compare si les pieces a cote ont les plus petite valeurs pour choisir la valeur la plus petite a attribué a la piece en position c_colonnes/c_lignes

for(c_colonnes=1;c_colonnes<14;c_colonnes++)
{
for(c_lignes=1;c_lignes<14;c_lignes++)
{
if(tableau[c_colonnes][c_lignes]>=10)
{
if((tableau[c_colonnes+1][c_lignes] >= 10) && (tableau[c_colonnes+1][c_lignes] < tableau[c_colonnes][c_lignes]))
{
tableau[c_colonnes][c_lignes]=tableau[c_colonnes+1][c_lignes];

c_colonnes=1;c_lignes=1; //relance les boucles tant que des chiffres sup a 10 qui se touche sont différents
}

if((tableau[c_colonnes-1][c_lignes] >= 10) && (tableau[c_colonnes-1][c_lignes] < tableau[c_colonnes][c_lignes]))
{
tableau[c_colonnes][c_lignes]=tableau[c_colonnes-1][c_lignes];

c_colonnes=1;c_lignes=1; //relance les boucles tant que des chiffres sup a 10 qui se touche sont différents
}

if((tableau[c_colonnes][c_lignes+1] >= 10) && (tableau[c_colonnes][c_lignes+1] < tableau[c_colonnes][c_lignes]))
{
tableau[c_colonnes][c_lignes]=tableau[c_colonnes][c_lignes+1];

c_colonnes=1;c_lignes=1; //relance les boucles tant que des chiffres sup a 10 qui se touche sont différents
}

if((tableau[c_colonnes][c_lignes-1] >= 10) && (tableau[c_colonnes][c_lignes-1] < tableau[c_colonnes][c_lignes]))
{
tableau[c_colonnes][c_lignes]=tableau[c_colonnes][c_lignes-1];

c_colonnes=1;c_lignes=1; //relance les boucles tant que des chiffres sup a 10 qui se touche sont différents
}

}
}
}


//le scaner va verifier si un 2 est a coté d'une piece > 10 si oui, on prend sa valeur et toute les pieces qui possede cette valeur sont remis comme ils étaient
for(c_colonnes=1;c_colonnes<14;c_colonnes++)
{
for(c_lignes=1;c_lignes<14;c_lignes++)
{
if(tableau[c_colonnes][c_lignes]>=10)
{
//les if vont comparer si les pieces a cote sont les plus petite pour choisir la valeur la plus petite a attribué a la piece en position c_colonnes/c_lignes
if(tableau[c_colonnes+1][c_lignes]==j2 || tableau[c_colonnes-1][c_lignes]==j2 || tableau[c_colonnes][c_lignes-1]==j2 || tableau[c_colonnes][c_lignes+1]==j2)
{
	groupe=tableau[c_colonnes][c_lignes]; //la variable groupe prend la valeur de la piece qui est a coté d'un 2

	for(c_colonnes=1;c_colonnes<14;c_colonnes++)
	{
	for(c_lignes=1;c_lignes<14;c_lignes++)
	{
		if(tableau[c_colonnes][c_lignes]==groupe)
			{
			tableau[c_colonnes][c_lignes]=j2;
			}
	}
	}
c_colonnes=1;c_lignes=1; //relance les boucles tant que des chiffres sup a 10 qui se touche sont différents
}
}
}
}

int r=0;

//_________________________________

for(c_colonnes=1;c_colonnes<14;c_colonnes++) //rechange les piece qui ont changer de valeur en 0
{
for(c_lignes=1;c_lignes<14;c_lignes++)
{
if(tableau[c_colonnes][c_lignes]>=10)
{
p.y=100+((c_colonnes-1)*50+50);p.x=100+((c_lignes-1)*50-87);
affiche_image("explosion1.bmp", p, 50, 100);
r=r+1;
}
}
}

synchro();
attendre(20);

if(r>=1)
{
for(c_colonnes=1;c_colonnes<14;c_colonnes++) //rechange les piece qui ont changer de valeur en 0
{
for(c_lignes=1;c_lignes<14;c_lignes++)
{
if(tableau[c_colonnes][c_lignes]>=10)
{
p.y=100+((c_colonnes-1)*50+50);p.x=100+((c_lignes-1)*50-87);
affiche_image("explosion8.bmp", p, 50, 100);
tableau[c_colonnes][c_lignes]=0;
}
}
}

synchro();
attendre(50);
}



//_____________________________________________

if(r>=1)
{
synchro();
affiche_auto_on();

plateau(tableau); //prend en compte les modifications
}

synchro();
affiche_auto_on();



}//fin

void gagner_partie(int tour,int j1,int j2,int tableau[taille_t][taille_t]) //fonction qui permet de donner la victoire a j1 ou j2
{
POINT p1;

int score=0,score2=0,c_colonnes=1,c_lignes=1;

if(tour >= 1) //lorsque le premier tour est passé, alors le système de victoire est activé > si un des deux joueurs n'a plus de piece, alors il a perdu
{

	for(c_colonnes=1;c_colonnes<14;c_colonnes++)
	{
	for(c_lignes=1;c_lignes<14;c_lignes++)
		{
		if((tableau[c_colonnes][c_lignes]==0) && (tableau[c_colonnes+1][c_lignes]!=0 && tableau[c_colonnes-1][c_lignes]!=0 && tableau[c_colonnes][c_lignes-1]!=0 && tableau[c_colonnes][c_lignes+1]!=0))
		{
		tableau[c_colonnes][c_lignes]=4;
		}
	}
	}
	
int sc_vide=0; //nb d'emplacement vide

	for(c_colonnes=1;c_colonnes<14;c_colonnes++)
	{
	for(c_lignes=1;c_lignes<14;c_lignes++)
		{
		if(tableau[c_colonnes][c_lignes]==0)
		{
		sc_vide=sc_vide+1;

		}
	}
	}
	
if(sc_vide==0)
{
	for(c_colonnes=1;c_colonnes<14;c_colonnes++)
	{
	for(c_lignes=1;c_lignes<14;c_lignes++)
		{
		if(tableau[c_colonnes][c_lignes]==1)
		{
		score=(score+1);
		}
		if(tableau[c_colonnes][c_lignes]==2)
		{
		score2=(score2+1);
		}
	}
	}
		
if(score2>score) //les noir gagne
{

p1.x=150;p1.y=600;

aff_pol("Les noirs sont victorieux", 40, p1, blanc);	
menu_gagner(tableau);	
}
if(score2<score) //les blanc gagne
{

p1.x=150;p1.y=600;

aff_pol("Les blancs sont victorieux", 40, p1, blanc);	
menu_gagner(tableau);
}
if(score2==score)  //égalité
{

p1.x=150;p1.y=600;

aff_pol("       Match nul", 40, p1, blanc);	
menu_gagner(tableau);	
}

}
	for(c_colonnes=1;c_colonnes<14;c_colonnes++)
	{
	for(c_lignes=1;c_lignes<14;c_lignes++)
		{
		if((tableau[c_colonnes][c_lignes]==4)) //remet la valeur des emplacements vide entouré par des autre valeur par 0
		{
		tableau[c_colonnes][c_lignes]=0;
		}
	}
	}
}
}

//ne fonctionne pas. Je n'arrive pas a modifier en conséquence le graphic.c pour obtenir un wait_clic qui ne dure que 60 ms
//fonction pour le chronomètre, le joueur a 60 seconde pour jouer sinon il perd.
void chro(int tableau[taille_t][taille_t])
{
affiche_auto_off();
int ch;

POINT p,p2,p3;
p.x=380;p.y=775;
p3.x=362;p3.y=790;

chrono_start();


do
{
ch=61-chrono_val();

affiche_image("chro.bmp", p3, 50, 100);
aff_int(ch, 30, p, noir);
synchro();

p2=wait_clic_chro();




}
while(ch>30); //correspond aux coordonnée que j'ai rajouté si aucun clique n'est fait pendant un lapse de temps de 1 seconde

do
{
ch=61-chrono_val();

aff_int(ch, 30, p, jaune);
synchro();

p2=wait_clic_chro();

attendre(60);

affiche_image("chro.bmp", p3, 50, 100);

}
while(ch>10 || (p2.x==1000 && p2.y==1000)); //correspond aux coordonnée que j'ai rajouté si aucun clique n'est fait pendant un lapse de temps de 1 seconde



do
{
ch=61-chrono_val();

aff_int(ch, 30, p, rouge);
synchro();

p2=wait_clic_chro();
attendre(60);

affiche_image("chro.bmp", p3, 50, 100);

}
while(ch>0 && p2.x==1000 && p2.y==1000); //correspond aux coordonnée que j'ai rajouté si aucun clique n'est fait pendant un lapse de temps de 1 seconde
}




//0=vide,1=rouge,2=bleu,3=bordure,4=vide entouré de piece differente de 0, >=10=variable temporaire

void jeu(int tableau[taille_t][taille_t]) //Lance le jeu
{
POINT p;
int i,tour=0,c_colonnes=0,c_lignes=0,j1,j2;
int mode=1;

bordure(tableau);

p.x=200;p.y=790;
aff_pol("Honneur aux blancs", 40, p, blanc);
synchro();
attendre(2000);
plateau(tableau);

for(i=1;i<10000;i++) 
{
j1=1; //considéré comme les pieces du joueur1 dans le tableau
j2=2; //considéré comme les pieces du joueur2 dans le tableau
manger_groupe(bleu,rouge,j1,j2,tableau);
p=bloquer(mode,p,j1,j2,tableau);

c_colonnes=nb_colonnes(p);
c_lignes=nb_lignes(p);


tableau[c_colonnes][c_lignes]=1; //Le tableau prend la valeur de la colonne et de la ligne et attribue le nombre 1 a la pièce blanche
piece_b(p);

nb_piece(tableau);

manger_groupe(bleu,rouge,j1,j2,tableau);

nb_piece(tableau);


j1=2; //considéré comme les pieces du joueur1 dans le tableau
j2=1; //considéré comme les pieces du joueur2 dans le tableau
manger_groupe(rouge,bleu,j1,j2,tableau);

nb_piece(tableau);

gagner_partie(tour,j1,j2,tableau);

p=bloquer(mode,p,j1,j2,tableau);

c_colonnes=nb_colonnes(p);
c_lignes=nb_lignes(p);

tableau[c_colonnes][c_lignes]=2; //Le tableau prend la valeur de la colonne et de la ligne et attribue le nombre 2 a la pièce noir
piece_n(p);

nb_piece(tableau);


manger_groupe(rouge,bleu,j1,j2,tableau);

nb_piece(tableau);

gagner_partie(tour,j1,j2,tableau);

tour=tour+1;
}
}

//____________Fonctions pour partie solo


POINT pointeur_automate(int mode,int j1,int j2,int tableau[taille_t][taille_t]) //return le point joué
{
POINT p;
int abandonne,c_colonnes,c_lignes;

p.x=51+alea_int(649); //donne une valeur aléatoire entre 51 et 649, centré sur le plateau
p.y=51+alea_int(649);
abandonne=alea_int(1000);

	if(abandonne==500) //loi binomiale \o/, de parametre 1/1000;n, le succes equivaut a l'IA décide d'abandonner
	{
	p.x=400-125;p.y=50;
	affiche_image("abandonner2.bmp", p, 50, 100);
			for(c_colonnes=1;c_colonnes<14;c_colonnes++)
		{
			for(c_lignes=1;c_lignes<14;c_lignes++)
			{
	
				tableau[c_colonnes][c_lignes]=0;
				
		}
		}
	menu_perdu(mode,j1,j2,tableau);
	}
	
p.x=((p.x-25)/50+1)*50;p.y=((p.y-25)/50+1)*50; //centre le point
	
return p;
}


POINT bloquer_automate(int mode,POINT p,int j1,int j2,int tableau[taille_t][taille_t]) //bloque les piece jouées sur des pièces déjà jouées.
{
POINT p1;
p1.x=375;p1.y=795;
int r=0;
p=pointeur_automate(mode,j1,j2,tableau);
int c_colonnes=nb_colonnes(p),c_lignes=nb_lignes(p);
int i=0,j=0;
int j3;

while(i==0)
{
	
	if((tableau[c_colonnes][c_lignes]>=1)
	//bloque la mise en place d'une piece sur une autre
	|| ((tableau[c_colonnes+1][c_lignes]==j2) && (tableau[c_colonnes][c_lignes+1]==j2) && (tableau[c_colonnes-1][c_lignes]==j2) && (tableau[c_colonnes][c_lignes-1]==j2))
	//bloque la mise en place d'une piece au milieu de 4 piece ennemi sauf exception plus bas
	|| ((tableau[c_colonnes+1][c_lignes]==3) && (tableau[c_colonnes][c_lignes+1]==j2) && (tableau[c_colonnes-1][c_lignes]==j2) && (tableau[c_colonnes][c_lignes-1]==j2))
	|| ((tableau[c_colonnes+1][c_lignes]==j2) && (tableau[c_colonnes][c_lignes+1]==3) && (tableau[c_colonnes-1][c_lignes]==j2) && (tableau[c_colonnes][c_lignes-1]==j2))
	|| ((tableau[c_colonnes+1][c_lignes]==j2) && (tableau[c_colonnes][c_lignes+1]==j2) && (tableau[c_colonnes-1][c_lignes]==3) && (tableau[c_colonnes][c_lignes-1]==j2))
	|| ((tableau[c_colonnes+1][c_lignes]==j2) && (tableau[c_colonnes][c_lignes+1]==j2) && (tableau[c_colonnes-1][c_lignes]==j2) && (tableau[c_colonnes][c_lignes-1]==3))
	//même fonction mais avec les bordures
    || ((tableau[c_colonnes+1][c_lignes]==3) && (tableau[c_colonnes][c_lignes+1]==3) && (tableau[c_colonnes-1][c_lignes]==j2) && (tableau[c_colonnes][c_lignes-1]==j2))
	|| ((tableau[c_colonnes+1][c_lignes]==j2) && (tableau[c_colonnes][c_lignes+1]==3) && (tableau[c_colonnes-1][c_lignes]==3) && (tableau[c_colonnes][c_lignes-1]==j2))
	|| ((tableau[c_colonnes+1][c_lignes]==j2) && (tableau[c_colonnes][c_lignes+1]==j2) && (tableau[c_colonnes-1][c_lignes]==3) && (tableau[c_colonnes][c_lignes-1]==3))
	|| ((tableau[c_colonnes+1][c_lignes]==3) && (tableau[c_colonnes][c_lignes+1]==j2) && (tableau[c_colonnes-1][c_lignes]==j2) && (tableau[c_colonnes][c_lignes-1]==3)))
	//même fonction mais avec les coins
	{
	if((tableau[c_colonnes][c_lignes]==0) && (((tableau[c_colonnes+2][c_lignes]==j1) && (tableau[c_colonnes+1][c_lignes+1]==j1) && (tableau[c_colonnes+1][c_lignes-1]==j1))
	|| ((tableau[c_colonnes][c_lignes+2]==j1) && (tableau[c_colonnes+1][c_lignes+1]==j1) && (tableau[c_colonnes-1][c_lignes+1]==j1))
	|| ((tableau[c_colonnes-1][c_lignes+1]==j1) && (tableau[c_colonnes-2][c_lignes]==j1) && (tableau[c_colonnes-1][c_lignes-1]==j1))
	|| ((tableau[c_colonnes-1][c_lignes-1]==j1) && (tableau[c_colonnes][c_lignes-2]==j1) && (tableau[c_colonnes+1][c_lignes-1]==j1))
	
	
    //si le milieux de 4 piece du joueur2 est vide et que une de ses 4 piece est entouré de 3 piece du joueur1 alors le joueur1 peut placer la pièce
   	|| ((tableau[c_colonnes+1][c_lignes]==3) && (tableau[c_colonnes][c_lignes+1]==j1) && (tableau[c_colonnes-1][c_lignes]==j1) && (tableau[c_colonnes][c_lignes-1]==j1))
	|| ((tableau[c_colonnes+1][c_lignes]==j1) && (tableau[c_colonnes][c_lignes+1]==3) && (tableau[c_colonnes-1][c_lignes]==j1) && (tableau[c_colonnes][c_lignes-1]==j1))
	|| ((tableau[c_colonnes+1][c_lignes]==j1) && (tableau[c_colonnes][c_lignes+1]==j1) && (tableau[c_colonnes-1][c_lignes]==3) && (tableau[c_colonnes][c_lignes-1]==j1))
	|| ((tableau[c_colonnes+1][c_lignes]==j1) && (tableau[c_colonnes][c_lignes+1]==j1) && (tableau[c_colonnes-1][c_lignes]==j1) && (tableau[c_colonnes][c_lignes-1]==3))
	//même fonction mais avec les bordures
    || ((tableau[c_colonnes+2][c_lignes]==j1) && (tableau[c_colonnes+1][c_lignes-1]==j1) && (tableau[c_colonnes][c_lignes-2]==j1) && (tableau[c_colonnes][c_lignes+1]==3) && (tableau[c_colonnes-1][c_lignes]==3))
    || ((tableau[c_colonnes+2][c_lignes]==j1) && (tableau[c_colonnes+1][c_lignes+1]==j1) && (tableau[c_colonnes][c_lignes+2]==j1) && (tableau[c_colonnes-1][c_lignes]==3) && (tableau[c_colonnes][c_lignes-1]==3))
    || ((tableau[c_colonnes][c_lignes+2]==j1) && (tableau[c_colonnes-1][c_lignes+1]==j1) && (tableau[c_colonnes-2][c_lignes]==j1) && (tableau[c_colonnes][c_lignes-1]==3) && (tableau[c_colonnes+1][c_lignes]==3))
    || ((tableau[c_colonnes][c_lignes-2]==j1) && (tableau[c_colonnes-1][c_lignes-1]==j1) && (tableau[c_colonnes-2][c_lignes]==j1) && (tableau[c_colonnes+1][c_lignes]==3) && (tableau[c_colonnes][c_lignes+1]==3))))
	//même fonction mais avec les coins
	{
	i=1; //serrure
	j=1; //serrure
	}
	else
	{
	i=0;
	}
	}
	else
	{
	i=1;
	}

	
if(i==1 && j==0)
{
//bloque le suicide de ses propres pieces
j3=tableau[c_colonnes][c_lignes]; //j3 récupère la valeur du tableau

tableau[c_colonnes][c_lignes]=j1; //permet de considéré la piece qui vien d'être posé dans bloquer_if_groupe
r=bloquer_if_groupe(j1,j2,tableau); //r=0 etant : il n'y a pas de piece allié détruit et r>=1 : cet emplacement provoque la destruction de piece alliés
tableau[c_colonnes][c_lignes]=j3; //remet l'emplacement comme il etait

if(r>=1)
{
	r=0;
	i=0;
}
}

if(tableau[c_colonnes][c_lignes]==0)
{
//permet de poser une piece si je detruit celle de mon ennemi
j3=tableau[c_colonnes][c_lignes]; //j3 récupère la valeur du tableau

tableau[c_colonnes][c_lignes]=j1; //permet de considéré la piece qui vien d'être posé dans bloquer_if_groupe
r=permettre_if_desgroupe(j1,j2,tableau); //r=0 etant : il n'y a pas de piece allié détruit et r>=1 : cet emplacement provoque la destruction de piece alliés
tableau[c_colonnes][c_lignes]=j3; //remet l'emplacement comme il etait
}


if(r>=1)
{
	r=0;
	i=1;
}


if(i==0)
{
	p=pointeur_automate(mode,j1,j2,tableau);
	c_colonnes=nb_colonnes(p);
	c_lignes=nb_lignes(p);	
}
	
	
}
return p;
}

void jeu_automate(int tableau[taille_t][taille_t]) //Lance le jeu
{
POINT p;
int i=0,tour=0,c_colonnes=0,c_lignes=0,j1,j2;
int mode=3;

//_______________________

bordure(tableau);

for(i=1;i<10000;i++) 
{
j1=1; //considéré comme les pieces du joueur1 dans le tableau
j2=2; //considéré comme les pieces du joueur2 dans le tableau
manger_groupe(bleu,rouge,j1,j2,tableau);

attendre(50);

p=bloquer_automate(mode,p,j1,j2,tableau);

c_colonnes=nb_colonnes(p);
c_lignes=nb_lignes(p);


tableau[c_colonnes][c_lignes]=1; //Le tableau prend la valeur de la colonne et de la ligne et attribue le nombre 1 a la pièce blanche
piece_b(p);

nb_piece(tableau);

manger_groupe(bleu,rouge,j1,j2,tableau);

nb_piece(tableau);


j1=2; //considéré comme les pieces du joueur1 dans le tableau
j2=1; //considéré comme les pieces du joueur2 dans le tableau
manger_groupe(rouge,bleu,j1,j2,tableau);

nb_piece(tableau);

gagner_partie(tour,j1,j2,tableau);

attendre(50);

p=bloquer_automate(mode,p,j1,j2,tableau);



c_colonnes=nb_colonnes(p);
c_lignes=nb_lignes(p);

tableau[c_colonnes][c_lignes]=2; //Le tableau prend la valeur de la colonne et de la ligne et attribue le nombre 2 a la pièce noir
piece_n(p);

nb_piece(tableau);


manger_groupe(rouge,bleu,j1,j2,tableau);

nb_piece(tableau);

gagner_partie(tour,j1,j2,tableau);

tour=tour+1;
}
}


void jeu_solo(int tableau[taille_t][taille_t]) //Lance le jeu
{
POINT p,p2;
int i=0,tour=0,c_colonnes=0,c_lignes=0,j1,j2;
int mode=2;
int choix;
//si choix = 1 alors le joueur est blanc, si il est 2 le joueur sera noir
p2.x=0;p2.y=800;
affiche_image("menu2.bmp", p2, 50, 100);

p2.x=100;p2.y=600;
aff_pol("Choisissez votre piece", 50, p2, blanc);
p2.x=400-100;p2.y=500;
affiche_image("nb_piece_b.bmp", p2, 50, 100);
p2.x=400+100-75;p2.y=500;
affiche_image("nb_piece_n.bmp", p2, 50, 100);
synchro();



while(i==0)
{
p=wait_clic();

if(p.x>=425 && p.x<=495 && p.y>=500-75 && p.y<=500)
	{
	i=1;
	choix=2; //le joueur joue les noirs
	}

if(p.x>=400-100 && p.x<=400-100+75 && p.y>=500-75 && p.y<=500)
	{
	i=1;
	choix=1; //le joueur joue les blancs
	}
plateau(tableau);


}
i=0;
//_______________________

bordure(tableau);

for(i=1;i<10000;i++) 
{
j1=1; //considéré comme les pieces du joueur1 dans le tableau
j2=2; //considéré comme les pieces du joueur2 dans le tableau
manger_groupe(bleu,rouge,j1,j2,tableau);

attendre(50);

if(choix==1)
{
p=bloquer(mode,p,j1,j2,tableau);
}

if(choix==2)
{
p=bloquer_automate(mode,p,j1,j2,tableau);
}


c_colonnes=nb_colonnes(p);
c_lignes=nb_lignes(p);


tableau[c_colonnes][c_lignes]=1; //Le tableau prend la valeur de la colonne et de la ligne et attribue le nombre 1 a la pièce blanche
piece_b(p);

nb_piece(tableau);

manger_groupe(bleu,rouge,j1,j2,tableau);

nb_piece(tableau);


j1=2; //considéré comme les pieces du joueur1 dans le tableau
j2=1; //considéré comme les pieces du joueur2 dans le tableau
manger_groupe(rouge,bleu,j1,j2,tableau);

nb_piece(tableau);

gagner_partie(tour,j1,j2,tableau);

attendre(50);

if(choix==2)
{
p=bloquer(mode,p,j1,j2,tableau);
}

if(choix==1)
{
p=bloquer_automate(mode,p,j1,j2,tableau);
}



c_colonnes=nb_colonnes(p);
c_lignes=nb_lignes(p);

tableau[c_colonnes][c_lignes]=2; //Le tableau prend la valeur de la colonne et de la ligne et attribue le nombre 2 a la pièce noir
piece_n(p);

nb_piece(tableau);


manger_groupe(rouge,bleu,j1,j2,tableau);

nb_piece(tableau);

gagner_partie(tour,j1,j2,tableau);

tour=tour+1;
}
}


void credits()
{
POINT p,p3,p1,p2;
int i=0;
affiche_auto_off();
p3.x=0;p3.y=800;
affiche_image("menu_credits.bmp", p3, 50, 100);

p1.x=400-125;p1.y=75;p2.x=400+125;p2.y=75-40;
affiche_image("revenir_au_menu.bmp", p1, 50, 100);
synchro();
affiche_auto_on();

while(i==0)
{
p=wait_clic();

if(p.x>=400-125 && p.x<=400+125 && p.y>=75-40 && p.y<=75)
	{
	p1.x=400-125;p1.y=75;
	affiche_image("revenir_au_menu2.bmp", p1, 50, 100);
	synchro();
	attendre(300);
    i=1;
	}
}
}



void didacticiel(tableau)
{
POINT p,p1;
int i=0,j=1;
p1.x=0;p1.y=800;
affiche_image("1.bmp", p1, 50, 100);
p1.x=135-125;p1.y=50;
affiche_image("precedent.bmp", p1, 50, 100);
p1.x=400-125;p1.y=50;
affiche_image("revenir_au_menu.bmp", p1, 50, 100);
p1.x=800-135-125;p1.y=50;
affiche_image("suivant.bmp", p1, 50, 100);

synchro();

while(i==0)
{
p=wait_clic();
//precedent
if(p.x>=135-125 && p.x<=135+125 && p.y>=50-40 && p.y<=50)
	{
	p1.x=135-125;p1.y=50;
	affiche_image("precedent2.bmp", p1, 50, 100);
	synchro();
	attendre(300);
	j=(j-1);
		if(j==0) //revient au menu si on est a la premiere page
		{
		i=1;
		}
	}
//revenir au menu
if(p.x>=400-125 && p.x<=400+125 && p.y>=50-40 && p.y<=50)
	{
	p1.x=400-125;p1.y=50;
	affiche_image("revenir_au_menu2.bmp", p1, 50, 100);
	synchro();
	attendre(300);
	i=1;
	}
//suivant
if(p.x>=800-135-125 && p.x<=800-135+125 && p.y>=50-40 && p.y<=50)
	{
	p1.x=800-135-125;p1.y=50;
	affiche_image("suivant2.bmp", p1, 50, 100);
	synchro();
	attendre(300);
	j=j+1;
		if(j==12) //revient au menu si on est a la derniere page
		{
		i=1;
		}
		}
	
	
	if(j==2)
	{
    p1.x=0;p1.y=800;
	affiche_image("2.bmp", p1, 50, 100);
	p1.x=135-125;p1.y=50;
	affiche_image("precedent.bmp", p1, 50, 100);
	p1.x=400-125;p1.y=50;
	affiche_image("revenir_au_menu.bmp", p1, 50, 100);
	p1.x=800-135-125;p1.y=50;
	affiche_image("suivant.bmp", p1, 50, 100);
	synchro();
	}
	if(j==3)
	{
    p1.x=0;p1.y=800;
	affiche_image("3.bmp", p1, 50, 100);
	p1.x=135-125;p1.y=50;
	affiche_image("precedent.bmp", p1, 50, 100);
	p1.x=400-125;p1.y=50;
	affiche_image("revenir_au_menu.bmp", p1, 50, 100);
	p1.x=800-135-125;p1.y=50;
	affiche_image("suivant.bmp", p1, 50, 100);
	synchro();
	}
	if(j==4)
	{
    p1.x=0;p1.y=800;
	affiche_image("4.bmp", p1, 50, 100);
	p1.x=135-125;p1.y=50;
	affiche_image("precedent.bmp", p1, 50, 100);
	p1.x=400-125;p1.y=50;
	affiche_image("revenir_au_menu.bmp", p1, 50, 100);
	p1.x=800-135-125;p1.y=50;
	affiche_image("suivant.bmp", p1, 50, 100);
	synchro();
	}
	if(j==5)
	{
    p1.x=0;p1.y=800;
	affiche_image("5.bmp", p1, 50, 100);
	p1.x=135-125;p1.y=50;
	affiche_image("precedent.bmp", p1, 50, 100);
	p1.x=400-125;p1.y=50;
	affiche_image("revenir_au_menu.bmp", p1, 50, 100);
	p1.x=800-135-125;p1.y=50;
	affiche_image("suivant.bmp", p1, 50, 100);
	synchro();
	}
	if(j==6)
	{
    p1.x=0;p1.y=800;
	affiche_image("6.bmp", p1, 50, 100);
	p1.x=135-125;p1.y=50;
	affiche_image("precedent.bmp", p1, 50, 100);
	p1.x=400-125;p1.y=50;
	affiche_image("revenir_au_menu.bmp", p1, 50, 100);
	p1.x=800-135-125;p1.y=50;
	affiche_image("suivant.bmp", p1, 50, 100);
	synchro();
	}
	if(j==7)
	{
    p1.x=0;p1.y=800;
	affiche_image("7.bmp", p1, 50, 100);
	p1.x=135-125;p1.y=50;
	affiche_image("precedent.bmp", p1, 50, 100);
	p1.x=400-125;p1.y=50;
	affiche_image("revenir_au_menu.bmp", p1, 50, 100);
	p1.x=800-135-125;p1.y=50;
	affiche_image("suivant.bmp", p1, 50, 100);
	synchro();
	}
	if(j==8)
	{
    p1.x=0;p1.y=800;
	affiche_image("8.bmp", p1, 50, 100);
	p1.x=135-125;p1.y=50;
	affiche_image("precedent.bmp", p1, 50, 100);
	p1.x=400-125;p1.y=50;
	affiche_image("revenir_au_menu.bmp", p1, 50, 100);
	p1.x=800-135-125;p1.y=50;
	affiche_image("suivant.bmp", p1, 50, 100);
	synchro();
	}
	if(j==9)
	{
    p1.x=0;p1.y=800;
	affiche_image("9.bmp", p1, 50, 100);
	p1.x=135-125;p1.y=50;
	affiche_image("precedent.bmp", p1, 50, 100);
	p1.x=400-125;p1.y=50;
	affiche_image("revenir_au_menu.bmp", p1, 50, 100);
	p1.x=800-135-125;p1.y=50;
	affiche_image("suivant.bmp", p1, 50, 100);
	synchro();
	}
	if(j==10)
	{
    p1.x=0;p1.y=800;
	affiche_image("10.bmp", p1, 50, 100);
	p1.x=135-125;p1.y=50;
	affiche_image("precedent.bmp", p1, 50, 100);
	p1.x=400-125;p1.y=50;
	affiche_image("revenir_au_menu.bmp", p1, 50, 100);
	p1.x=800-135-125;p1.y=50;
	affiche_image("suivant.bmp", p1, 50, 100);
	synchro();
	}
	if(j==11)
	{
    p1.x=0;p1.y=800;
	affiche_image("11.bmp", p1, 50, 100);
	p1.x=135-125;p1.y=50;
	affiche_image("precedent.bmp", p1, 50, 100);
	p1.x=400-125;p1.y=50;
	affiche_image("revenir_au_menu.bmp", p1, 50, 100);
	p1.x=800-135-125;p1.y=50;
	affiche_image("suivant.bmp", p1, 50, 100);
	synchro();
	}
	
}
}



void menu(int tableau[taille_t][taille_t])
{

int i=0;
POINT p,p1,p2,p3;
p.x=400;
p.y=400;

while(i==0)
{
affiche_auto_off();
p3.x=0;p3.y=800;
affiche_image("menu.bmp", p3, 50, 100);

p1.x=400-125;p1.y=650;p2.x=400+125;p2.y=650-40;
affiche_image("Joueur_vs_joueur.bmp", p1, 50, 100);
p1.x=400-125;p1.y=600;p2.x=400+125;p2.y=600-40;
affiche_image("un_joueur.bmp", p1, 50, 100);
p1.x=400-125;p1.y=550;p2.x=400+125;p2.y=550-40;
affiche_image("automate.bmp", p1, 50, 100);
p1.x=400-125;p1.y=500;p2.x=400+125;p2.y=500-40;
affiche_image("didacticiel.bmp", p1, 50, 100);
p1.x=400-125;p1.y=450;p2.x=400+125;p2.y=450-40;
affiche_image("credits.bmp", p1, 50, 100);
p1.x=400-125;p1.y=75;p2.x=400+125;p2.y=75-40;
affiche_image("quitter.bmp", p1, 50, 100);

synchro();
affiche_auto_on();

p=wait_clic();
//joueur vs joueur
if(p.x>=400-125 && p.x<=400+125 && p.y>=650-40 && p.y<=650)
	{
	p1.x=400-125;p1.y=650;
	affiche_image("Joueur_vs_joueur2.bmp", p1, 50, 100);
	synchro();
	attendre(300);
	plateau(tableau);
	jeu(tableau);
	}
//un joueur
if(p.x>=400-125 && p.x<=400+125 && p.y>=600-40 && p.y<=600)
	{
	p1.x=400-125;p1.y=600;
	affiche_image("un_joueur2.bmp", p1, 50, 100);
	synchro();
	attendre(300);
	jeu_solo(tableau);
	}
//automate vs automate
if(p.x>=400-125 && p.x<=400+125 && p.y>=550-40 && p.y<=550)
	{
	p1.x=400-125;p1.y=550;
	affiche_image("automate2.bmp", p1, 50, 100);
	synchro();
	attendre(300);
	plateau(tableau);
	jeu_automate(tableau);
	}

//didacticiel
if(p.x>=400-125 && p.x<=400+125 && p.y>=500-40 && p.y<=500)
	{
	p1.x=400-125;p1.y=500;
	affiche_image("didacticiel2.bmp", p1, 50, 100);
	synchro();
	attendre(300);
	didacticiel(tableau);
	}


//credit
if(p.x>=400-125 && p.x<=400+125 && p.y>=450-40 && p.y<=450)
	{
	p1.x=400-125;p1.y=450;
	affiche_image("credits2.bmp", p1, 50, 100);
	synchro();
	attendre(300);
	credits();
	}
//quitter
if(p.x>=400-125 && p.x<=400+125 && p.y>=75-40 && p.y<=75)
	{
	p1.x=400-125;p1.y=75;
	affiche_image("quitter2.bmp", p1, 50, 100);
	synchro();
	attendre(300);
    i=1;
	}
}
exit(0);
}

int main()
{
/* Initialisation de la fenêtre graphique */
init_graphics(800,800); // x800/y800



int tableau[taille_t][taille_t]; //Le tableau est a 2 dimension, une pour l'horizontale et l'autre pour la verticale, 
memset(tableau,0,sizeof(tableau)); //celui-ci prend la valeur 0 pour tout les emplacements

menu(tableau);

wait_escape();
exit(0);
}
