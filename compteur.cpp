#include <iostream>
#include <fstream>
#include <unordered_map>
#include <sstream>
using namespace std;

int compteur(int num)
{
  ostringstream fichier;
  fichier << "test";
  fichier << num;
  fichier << ".txt";
  string nom = fichier.str();

  ofstream resultat("resultat.txt", ios::app);  //ouvre resultat en ecriture
  ifstream file(nom.c_str());
  unordered_map<string, int> tab;
  string mot;
  unordered_map<string,int>::iterator got;
  while(file.good())  //tant que file marche/est ouvert
  {
    file >> mot; //lit le mot
    got= tab.find(mot); //cherche dans tab si mot est dedans
    if(got == tab.end()) //si mot n'existe pas (pas dans la table)
      tab[mot]= 1; //si mot n'y est pas, il l'ajoute
    else
      ++got->second; //si le mot existe, j'incremente second
  }
    file.close();
    int max= 0;
    string motMax;
    for(auto i : tab)
    {
      if (i.second > max)
      {
        motMax= i.first;
        max= i.second;
      }
      resultat << i.first << " " << i.second << endl;
    }
    resultat.close();
    //cout << "\t" << motMax << " " << max << endl;
    return EXIT_SUCCESS;
}
