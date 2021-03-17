#include <iostream>
#include <string>
#include <vector>
#include "functions.h"
using namespace std;

int main()
{
    int nombre_joueurs;
    int const essais_max(5);
    string mot_mystere;
    vector<char> melange, mystere;
    bool retry, replay;

    cout << endl << endl;
    cout << "Bienvenue dans MYSTERY WORD !!" << endl << endl;
    cout << "Les lettres d'un mot ont ete melangees. A vous de deviner quel etait ce mot. ";
    cout << "Vous avez 5 essais. Bonne chance!" << endl << endl;

    do {
        cout << "==========MENU==========" << endl << endl;
        cout << "Comment voulez-vous jouer?" << endl;
        mark:
        cout << "1. PvAI (1 joueur)" << endl << "2. PvP (2 joueurs)" << endl;
        cin >> nombre_joueurs;
        cout << endl << endl;

        switch (nombre_joueurs)
        {
            case 1:         //Cas du PvAI.
                do{
                    int tour(1);
                    bool ok = false;        //Pour savoir si le joueur a trouvé le bon mot (vrai) ou pas (faux).

                    mot_alea(mot_mystere, ok);           //L'ordinateur chosit un mot.
                    melange = shuffle(mot_mystere);            //Récupère le mot mélangé.
                    mystere = tab_mystere(mot_mystere);     //Récupère le tableau contenant le mot mystère.

                    cout << "--Ordinateur--" << endl << "Mot mystère choisi." << endl << endl << endl;

                    cout << "--Joueur 2--" << endl;
                    while (tour <= essais_max && !ok)
                    {
                        player2(mystere, melange, ok);
                        cout << endl;
                        tour++;
                    }

                    again(ok, retry);       //Demande au joueur s'il veut refaire une partie et stocke sa décision dans le booléen "retry".
                } while(retry);

                break;

            case 2:         //Cas du PvP.
                do{
                    int tour(1);
                    bool ok = false;
                    mot_mystere = player1(mot_mystere);     //Récupère le mot mystère saisi par le joueur 1.
                    melange = shuffle(mot_mystere);
                    mystere = tab_mystere(mot_mystere);

                    cout << "--Joueur 2--" << endl;
                    while (tour <= essais_max && !ok)
                    {
                        player2(mystere, melange, ok);
                        cout << endl;
                        tour++;
                    }

                    again(ok, retry);
                } while(retry);

                break;

            default:
                cout << "Vous ne pouvez choisir que l'option 1 ou l'option 2." << endl << "Que choisissez-vous?";
                cout << endl << endl;
                goto mark;      //Renvoie le joueur auc choix du mode si il entre autre chose que 1 et 2.
        }

        replay = ask_replay();   //Demande au joueur s'il veut rejouer (changer de mode) et stocke sa décision dans le booléen "replay".
        cout << endl << endl;
    } while(replay);

    cout << "A tres bientot!" << endl;

    return 0;
}
