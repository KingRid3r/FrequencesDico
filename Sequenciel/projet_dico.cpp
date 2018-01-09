#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <sstream>
#include "compteur.cpp"
using namespace std;


int main()
{
  string adresse;
  cout << "Entrez l'adresse du repertoire contenant votre dico" << endl;
  cin >> adresse;

  ifstream dico1(adresse, ios::in);  // ouvre le dico en lecture
  ifstream dico2(adresse, ios::in);  // ouvre le dico en lecture
  ifstream dico3(adresse, ios::in);  // ouvre le dico en lecture
  ofstream fcaractere1("test1.txt", ios::out); //ouvre test1 en ecriture
  ofstream fcaractere2("test2.txt", ios::out); //ouvre test2 en ecriture
  ofstream fcaractere3("test3.txt", ios::out); //ouvre test3 en ecriture

  if(dico1)  // si le dico s'ouvre
  {
    string ligne;  // déclaration d'une chaîne qui contiendra la ligne lu
    while(getline(dico1, ligne, '\n'))  // on met dans "ligne" la ligne
    {
      fcaractere1 << ligne[0] << endl; //recupere le premier caractere
    }
  }
  else // si il s'ouvre pas
  {
    cerr << "Impossible d'ouvrir le dico1 !" << endl;
  }
  fcaractere1.close();
  dico1.close();


  if(dico2)  // si le dico s'ouvre
  {
    string ligne;  // déclaration d'une chaîne qui contiendra la ligne lu
    while(getline(dico2, ligne, '\n'))  // on met dans "ligne" la ligne
    {
      fcaractere2 << ligne[0]; //recupere le premier caractere
      fcaractere2 << ligne[1] << endl;
    }
  }
  else // si il s'ouvre pas
  {
    cerr << "Impossible d'ouvrir le dico2 !" << endl;
  }
  fcaractere2.close();
  dico2.close();


  if(dico3)  // si le dico s'ouvre
  {
    string ligne;  // déclaration d'une chaîne qui contiendra la ligne lu
    while(getline(dico3, ligne, '\n'))  // on met dans "ligne" la ligne
    {
      fcaractere3 << ligne[0]; //recupere le premier caractere
      fcaractere3 << ligne[1];
      fcaractere3 << ligne[2] << endl;
    }
  }
  else // si il s'ouvre pas
  {
    cerr << "Impossible d'ouvrir le dico3 !" << endl;
  }
  fcaractere3.close();
  dico3.close();
  remove("resultat.txt");

  compteur(1);
  compteur(2);
  compteur(3);

  remove("test1.txt");
  remove("test2.txt");
  remove("test3.txt");

  cout << "Done" << endl;

  return 0;
}
