#ifndef MOT_MYSTERE_FUNCTIONS_H
#define MOT_MYSTERE_FUNCTIONS_H
using namespace std;

bool ask_retry_win();              //Demande si le joueur veut recommencer la partie si il a gagné.
                                   //Renvoie "vrai" si oui, et "faux" sinon.

bool ask_retry_lose();             //Dis au joueur qu'il a perdu et lui demande s'il veut recommencer la partie.
                                   //Renvoie "vrai" si oui, et "faux" sinon.

void again(bool &ok, bool &retry); //Prend en argument les booléens "ok" et "retry" passés par référence.
                                   //Selon leurs valeurs, oriente le joueur selon si il a gagné ou pas.

bool ask_replay();                 //Demande au joeur s'il veut retourner au menu (pour changer de mode de jeu).
                                   //Renvoie "vrai" si oui, et "faux" sinon.

string player1(string mot_mystere);    //Prend en argument une chaîne de caractères.
                                       //Dans un PvP, demande au joueur 1 de saisir le mot mystère
                                       //Renvoie le mot saisi par le joueur.

vector<char> shuffle(string mot_mystere);   //Prend en argument le mot mystere.
                                            //Mélange les lettres du mot en les classant aléatoirement dans un tableau dynamique.
                                            //Renvoie le tableau.

void player2(vector<char> &mystere, vector<char> &melange, bool &ok);   //Prend en argument le mot mystère, le mot mélangé et le booléen "ok".
                                                                        //Présente le mot mélangé au joueur 2 et lui laisse la main pour saisir le mot mystère.
                                                                        //Vérifie la justesse du mot saisi par le joueur 2.

vector<char> tab_mystere(string &mot_mystere);  //Prend en argument le mot mystère passé par référence.
                                                //Récupère ce mot dans un tableau.
                                                //Renvoie le tableau.

void mot_alea(string &mot_mystere, bool &ok);   //Prend en argument la variable du mot mystère et le booléen "ok" passés par réference.
                                                //Dans un PvAI, choisit aléatoirement un mot dans le dictionnaire. Ce mot est pris comme mot mystère.
                                                //"ok" prend la valeur "vrai" si le dictionnaire n'est pas trouvé, afin de mettre fin à la partie.

#endif //MOT_MYSTERE_FUNCTIONS_H
