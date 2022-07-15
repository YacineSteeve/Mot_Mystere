#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include "functions.h"
using namespace std;

bool ask_retry_win()
{
    int retry;
    cout << "Voulez-vous recommencer la partie?" << endl;
    mark1:
    cout << "1. Oui" << endl << "2. Non" << endl;
    cin >> retry;
    if (retry == 1)
    {
        return true;
    }
    else if (retry == 2)
    {
        return false;
    }
    else
    {
        cout << "Vous ne pouvez choisir que l'option 1 ou l'option 2." << endl << "Que choisissez-vous?";
        cout << endl << endl;
        goto mark1;
    }
}

bool ask_retry_lose()
{
    int retry;
    cout << "Perdu! Nombre maximum d'essais atteint." << endl << "Voulez-vous recommencer la partie?" << endl;
    mark2:
    cout << "1. Oui" << endl << "2. Non" << endl;
    cin >> retry;
    if (retry == 1)
    {
        return true;
    }
    else if (retry == 2)
    {
        return false;
    }
    else
    {
        cout << "Vous ne pouvez choisir que l'option 1 ou l'option 2." << endl << "Que choisissez-vous?";
        cout << endl << endl;
        goto mark2;
    }
}

void again(bool &ok, bool &retry)
{
    /* "ok" est vrai si le joueur a trouvé le bon mot */
    if(ok)
    {
        retry = ask_retry_win();
    }
    else
    {
        retry = ask_retry_lose();
    }
    cout << endl << endl;
}

bool ask_replay()
{
    int replay;
    cout << "Voulez-vous retourner au menu?" << endl;
    mark3:
    cout << "1. Oui" << endl << "2. Non" << endl;
    cin >> replay;
    if (replay == 1)
    {
        return true;
    }
    else if (replay == 2)
    {
        return false;
    }
    else
    {
        cout << "Vous ne pouvez choisir que l'option 1 ou l'option 2." << endl << "Que choisissez-vous?";
        cout << endl << endl;
        goto mark3;
    }
}

string player1(string mot_mystere)
{
    cout << "--Joueur 1--" << endl << "Veuillez entrer le mot mystère: " << endl;
    cin >> mot_mystere;
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    /* Pour que le joueur 2 ne voit pas le mot mystère saisi par le joueur 1. */
    return mot_mystere;
}

vector<char> shuffle(string mot_mystere)
{
    vector<char> tableau2;
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<unsigned long> dist(0, mot_mystere.size());

    while(!mot_mystere.empty())
    {
        vector<char> tableau1;
        for (char & i : mot_mystere)
        {
            tableau1.push_back(i);
        }

        int nombre_aleatoire;

        nombre_aleatoire = int(dist(mt));     //Prend aléatoirement un des indices des lettres du mot mystère.
        tableau2.push_back(tableau1[nombre_aleatoire]);     //Ajoute au tableau 2 la lettre correspondant à cet indice.
        mot_mystere.erase(nombre_aleatoire, 1);        //Efface du mot mystère la lettre déjà prise.
    }

    return tableau2;
}

void player2(vector<char> &mystere, vector<char> &melange, bool &ok)
{
    int test(0);
    string mot, admin("admin");

    cout << "Quel est le mot mystère? ";
    for (char i : melange)
    {
        cout << i;
    }
    cout << endl;
    cin >> mot;

    if (mot.size() == mystere.size())
    {
        int i(0);
        while (i < mot.size())
        {
            if (mystere[i] == mot[i])
            {
                test++;
            }
            i++;
        }
        if(test == mystere.size())      //Si l'égalité des caractères est vérifiée pour tous les caractères.
        {
            cout << endl << "Bravo! C'est bien ce mot!" << endl;
            ok = true;
        }
        else
        {
            cout << endl << "Ce n'est pas le mot mystère." << endl << endl;
        }
    }
    else if (mot == admin)      /* Met directement fin à la partie... */
    {
        cout << "System call..." << endl;
        ok = true;
        goto admin;
    }
    else
    {
        cout << endl << "Ce n'est pas le mot mystère." << endl << endl;
    }
    admin:;
}

vector<char> tab_mystere(string &mot_mystere)
{
    vector<char> mystere;
    for(char & i : mot_mystere)
    {
        mystere.push_back(i);
    }
    return mystere;
}

void mot_alea(string &mot_mystere, bool &ok)
{
    int position_alea, indic(0), lignes(323577) /* Nombre de lignes (de mots) dans le dictionnaire */;
    string const dico("/home/yacine/CLionProjects/Mot_Mystere/dico.txt");   //Récupère le fichier dictionnaire.
    ifstream out_flux(dico);       //Crée un flux pour la lecture du dictionnaire.
    if(out_flux)
    {
        random_device rd;
        mt19937 mt(rd());
        uniform_int_distribution<int> dist(0, lignes);

        position_alea = dist(mt);        //Choisit aléatoirement une ligne (donc un mot) du dictionnaire.
        while (indic < position_alea)           //Jusqu'à atteinte la ligne aléatoirement choisie.
        {
            mot_mystere.erase(0, ios::end);     //Efface le précédent contenu de la variable "mot_mystere".
            out_flux >> mot_mystere;                //Récupère une ligne du dico dans la variable "mot_mystere"
                                                    //Ce qui correspond à un déplacement du curseur.
            indic++;
        }
    }
    else
    {
        cout << "Erreur! Fichier dictionnaire introuvable!" << endl << endl;
        ok = true;          //Pour directement mettre fin à la partie.
    }
}