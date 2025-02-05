/////////////////////////////////////////////////////////////////////////////
//Fichier ListeDeCases.cpp
/////////////////////////////////////////////////////////////////////////////
/**
 * \file ListeDeCases.cpp
 * \brief Ce fichier contient une implémentation de la classe ListeDeCases
 * \author Antoine Rivard
 * \version 0.1
 * \date mai-juin 2024
 */

#include <string>
#include <sstream>
#include <stdexcept>
#include <iostream>

#include "ListeDeCases.h"

using std::string;
using std::ostringstream;
using std::out_of_range;
using std::range_error;

namespace tp1
{

    /**
     * \fn ListeDeCases::ListeDeCases()
     * 
     * \brief Constructeur de la classe Case
     * 
     */
    ListeDeCases::ListeDeCases() : m_taille(0) // Initialise la taille à 0
    {
        // Ce constructeur peut rester vide (en utilisant la liste d'initialisation).
    }

    /**
     * \fn ListeDeCases::~ListeDeCases()
     * 
     * \brief Destructeur de la classe Case
     * 
     */
    ListeDeCases::~ListeDeCases()
    {
        // À compléter !
      int n = m_taille;
      for (int i = n - 1; i >= 0; i--) // Enlève tous les noeuds de la liste de cases un par un
        {
          enleverCase(1);
        }
    }

    /**
     * \fn int ListeDeCases::taille() const
     * 
     * \brief Accesseur de la taille de la liste
     * 
     * \return La taille de la liste
     * 
     */
    int ListeDeCases::taille() const
    {
        // À corriger !
       return m_taille;
    }

    /**
     * \fn bool ListeDeCases::estVide() const
     * 
     * \brief Vérifie si la liste est vide
     * 
     * \return Si la taille est égale à 0 ou non (vide ou non)
     * 
     */
    bool ListeDeCases::estVide() const
    {
        // À corriger !
       return m_taille == 0;
    }

    /**
     * \fn void ListeDeCases::ajouterCase(const Case& uneCase, int position) throw (out_of_range)
     * 
     * \brief Ajoute une case à la position désirée
     * 
     * \param[in] uneCase, la case que l'on souhaite ajouter
     * \param[in] position, la position de la case que l'on souhaite ajouter
     * 
     */
    void ListeDeCases::ajouterCase(const Case& uneCase, int position)
    {
        // À compléter !
      if (position < 1 or position > m_taille + 1) // Vérifie que la position se trouve dans les bornes de la liste
        {
          throw out_of_range("Position hors de portée");
        }
       if (m_taille == 0) // Si la taille est 0, initialise m_debut et m_fin
         {
          Noeud* N = new Noeud(uneCase, 0, 0);
          m_debut = N;
          m_fin = N;
         } else if(position == 0) // Si la position est 0, réassigne m_debut et connecte le nouveau noeud au début
           {
              Noeud* N = new Noeud(uneCase, m_debut, 0);
              m_debut->m_precedent = N;
              m_debut = N;
           } else if (position == m_taille + 1) // Si la position est à la fin, réassigne m_fin et connecte le nouveau noeud à la fin
              {
                Noeud* N = new Noeud(uneCase, 0,m_fin);
                m_fin->m_suivant = N;
                m_fin = N;
              } else // Si la position est au milieu de la liste, met le nouveau noeud entre les deux et change leurs connections
                {
                  Noeud* N = new Noeud(uneCase,noeudAt(position), noeudAt(position - 1));
                  noeudAt(position)->m_precedent = N;
                  noeudAt(position - 1)->m_suivant = N;
                }
       m_taille++; // Incrémente la taille de la liste par un
    }
    
    /**
     * \fn void ListeDeCases::ajouterCaseALaFin(const Case& uneCase)
     * 
     * \brief Ajoute une case à la fin
     * 
     * \param[in] uneCase, la case que l'on souhaite ajouter
     * 
     */
    void ListeDeCases::ajouterCaseALaFin(const Case& uneCase)
    {
       // À compléter !
      ajouterCase(uneCase, m_taille + 1); // Appelle la fonction ajouterCase avec l'argument de la position taille + 1
      
    }
    
    /**
     * \fn void ListeDeCases::enleverCase(int position) throw (logic_error)
     * 
     * \brief Enlève une case à une position précise
     * 
     * \param[in] position, la position de la case que l'on souhaite enlever
     * 
     */
    void ListeDeCases::enleverCase(int position)
    {
        // À compléter !
      if (position < 1 or position > m_taille) // Vérifie que la position est dans les bornes de la liste
        {
          throw std::logic_error("Position hors de portée");
        }
      if(m_taille == 1) // S'il n'y a qu'une seule case, elle est simplement enlevée
        {
          delete noeudAt(position);
        }else if(position == 1) // Si la position est 1, il faut réassigner m_début et déconnecter le noeud adjacent
            {
              m_debut = m_debut->m_suivant;
              delete m_debut->m_precedent;
              m_debut->m_precedent = 0;
            } else if(position == m_taille) // Si la position est à la fin, il faut réassigner m_fin et déconnecter le noeud adjacent
              {
                m_fin = m_fin -> m_precedent;
                delete m_fin->m_suivant;
                m_fin->m_suivant = 0;
              } else // Si la position est au milieu de la liste, il faut reconnecter le noeud précédent au prochain avant de détruire le noeud
                {
                  noeudAt(position - 1)->m_suivant = noeudAt(position + 1);
                  delete noeudAt(position)->m_precedent;
                  noeudAt(position)->m_precedent = noeudAt(position - 1);            
                }
      m_taille--; // Réduction de la taille par 1
    }
    
    /**
     * \fn const Case& ListeDeCases::caseA(int position) const throw (range_error)
     * 
     * \brief Permet de connaître la case se trouvant à une certaine position
     * 
     * \param[in] position, la position de la case que l'on souhaite avoir
     * 
     * \return La case en question
     * 
     */
    const Case& ListeDeCases::caseA(int position) const
    {
        // À corriger !
        if (position < 1 or position > m_taille) // Vérifie que la position se trouve dans les bornes de la liste
        {
          throw range_error("Position hors de portée");
        }
        return noeudAt(position)->m_case; // Fait appel à noeudAt avec la position en argument et donne la case du noeud
    }

    /**
     * \fn ListeDeCases::Noeud* ListeDeCases::noeudAt(int position) const throw (range_error)
     * 
     * \brief Permet de connaître le noeud se trouvant à une certaine position
     * 
     * \param[in] position, la position du noeud
     * 
     * \return Le noeud se trouvant à cette position
     * 
     */
    ListeDeCases::Noeud* ListeDeCases::noeudAt(int position) const
    {
        // À corriger !
        if (position < 1 or position > m_taille) // Vérifie que la position se trouve dans les bornes de la liste
        {
          throw range_error("Position hors de portée");
        }
       Noeud* N = m_debut; // Sélectionne le noeud au début de la liste
       for(int i = 1; i < position; i++) // Le noeud suit le prochain dans la liste jusqu'à ce que la position soit atteinte
         {
           N = N->m_suivant;         
         }
        return  N;
    }

    // Le reste du code qui utilise surtout l'itérateur est fourni.
    // Ajoutez simplement les balises Doxygen.

    
    /**
     * \fn ListeDeCases::Iterateur ListeDeCases::debut() const
     * 
     * \brief Place un itérateur au début de la liste de cases
     * 
     * \return Un itérateur placé au début de la liste
     * 
     */
    ListeDeCases::Iterateur ListeDeCases::debut() const
    {
       return Iterateur(*this);
    }

    /**
     * \fn ListeDeCases::Iterateur::Iterateur(const ListeDeCases& liste)
     * 
     * \brief Constructeur de la classe Iterateur
     * 
     * \param[in] liste, la liste de cases de l'itérateur
     * 
     */    
    ListeDeCases::Iterateur::Iterateur(const ListeDeCases& liste) :
       m_liste(liste), m_courant(liste.m_debut)
    {
    }

    /**
     * \fn ListeDeCases::Iterateur::~Iterateur()
     * 
     * \brief Destructeur de la classe Iterateur
     * 
     */ 
    ListeDeCases::Iterateur::~Iterateur()
    {
       m_courant = 0;
    }

    /**
     * \fn const Case& ListeDeCases::Iterateur::caseCourante() const
     * 
     * \brief Accesseur de la case contenu dans un noeud
     * 
     * \return La case contenue dans le noeud pointé par l'itérateur
     * 
     */ 
    const Case& ListeDeCases::Iterateur::caseCourante() const
    {
       return m_courant->m_case;
    }
    
    /**
     * \fn bool ListeDeCases::Iterateur::existeCaseSuivante() const
     * 
     * \brief Permet de savoir s'il existe une case suivant celle présente
     * 
     * \return S'il existe une case suivant ou non (true ou false)
     * 
     */ 
    bool ListeDeCases::Iterateur::existeCaseSuivante() const
    {
       return (m_courant != 0 && m_courant->m_suivant != 0);
    }

    /**
     * \fn ListeDeCases::Iterateur& ListeDeCases::Iterateur::operator ++() throw (out_of_range)
     * 
     * \brief Surcharge l'opérateur ++ sur la classe Itérateur (Fait avancer l'itérateur au prochain noeud)
     * 
     * \return Le prochain noeud
     * 
     */ 
    ListeDeCases::Iterateur& ListeDeCases::Iterateur::operator ++()
    {
       if (existeCaseSuivante())
       {
          m_courant = m_courant->m_suivant;
       }
       else
       {
          m_courant = 0;
          throw out_of_range("L'iterateur ne peut pas aller à une case suivante.");
       }
       return *this;
    }

    /**
     * \fn ListeDeCases::Noeud* ListeDeCases::Iterateur::noeudSuivant(Case::Couleur couleur, int& distance) const
     * 
     * \brief Trouve le prochain noeud avec la case de la bonne couleur
     * 
     * \param[in] couleur, la couleur recherchée
     * \param[in] distance, la distance du noeud
     * 
     * \return 0 si le noeud courant est 0, le noeud suivant avec la bonne couleur sinon
     */     
    ListeDeCases::Noeud* ListeDeCases::Iterateur::noeudSuivant(Case::Couleur couleur, int& distance) const
    {
       distance = 0;
       if (m_courant == 0)
       {
          return 0;
       }

       ListeDeCases::Noeud* suivant = m_courant->m_suivant;
       while (noeudMauvaiseCouleur(suivant, couleur))
       {
          suivant = suivant->m_suivant;
          distance++;
       }
       return suivant;
    }

    /**
     * \fn bool ListeDeCases::Iterateur::noeudMauvaiseCouleur(ListeDeCases::Noeud *noeud, Case::Couleur couleur) const
     * 
     * \brief Vérifie si un noeud contient une case de la bonne couleur
     * 
     * \param[in] couleur, la couleur recherchée
     * \param[in] noeud, le noeud que l'on souhaite vérifier
     * 
     * \return true si le noeud est de la bonne couleur, false sinon
     */  
    bool ListeDeCases::Iterateur::noeudMauvaiseCouleur(ListeDeCases::Noeud *noeud,
          Case::Couleur couleur) const
    {
       return (noeud != 0 && noeud->m_case.couleur != couleur);
    }

    /**
     * \fn void ListeDeCases::Iterateur::caseSuivante(Case::Couleur couleur) throw (out_of_range)
     * 
     * \brief Place l'itérateur sur la prochaine case de la bonne couleur
     * 
     * \param[in] couleur, la couleur recherchée
     * 
     */  
    void ListeDeCases::Iterateur::caseSuivante(Case::Couleur couleur)
    {
       int distance = 0;
       m_courant = noeudSuivant(couleur, distance);
       if (m_courant == 0)
       {
          ostringstream message;
          message << "L'iterateur ne peut pas aller à une case suivante de couleur " << couleur << ".";
          throw out_of_range(message.str());
       }
    }
    
    /**
     * \fn bool ListeDeCases::Iterateur::existeCaseSuivante(Case::Couleur couleur) const
     * 
     * \brief Détermine s'il existe une prochaine case d'une certaine couleur
     * 
     * \param[in] couleur, la couleur recherchée
     * 
     * \return true si elle existe, false sinon
     * 
     */  
    bool ListeDeCases::Iterateur::existeCaseSuivante(Case::Couleur couleur) const
    {
       int distance = 0;
       return noeudSuivant(couleur, distance) != 0;
    }

    /**
     * \fn ListeDeCases::Noeud* ListeDeCases::Iterateur::noeudPrecedent(Case::Couleur couleur, int& distance) const
     * 
     * \brief Trouve le premier noeud précédent avec la case de la bonne couleur
     * 
     * \param[in] couleur, la couleur recherchée
     * \param[in] distance, la distance du noeud
     * 
     * \return 0 si le noeud courant est 0, le noeud précédent avec la bonne couleur sinon
     */   
    ListeDeCases::Noeud* ListeDeCases::Iterateur::noeudPrecedent(Case::Couleur couleur, int& distance) const
    {
       distance = 0;
       if (m_courant == 0)
       {
          return 0;
       }

       ListeDeCases::Noeud* precedent = m_courant->m_precedent;
       while (noeudMauvaiseCouleur(precedent, couleur))
       {
          precedent = precedent->m_precedent;
          distance++;
       }
       return precedent;
    }

    /**
     * \fn void ListeDeCases::Iterateur::casePrecedente(Case::Couleur couleur) throw (out_of_range)
     * 
     * \brief Place l'itérateur sur la première case précédente de la bonne couleur
     * 
     * \param[in] couleur, la couleur recherchée
     * 
     */ 
    void ListeDeCases::Iterateur::casePrecedente(Case::Couleur couleur)
    {
       int distance;
       m_courant = noeudPrecedent(couleur, distance);
       if (m_courant == 0)
       {
          ostringstream message;
          message << "L'iterateur ne peut pas aller à une case precedente de couleur " << couleur
                << ".";
          throw out_of_range(message.str());
       }
    }
    
    /**
     * \fn bool ListeDeCases::Iterateur::existeCasePrecedente(Case::Couleur couleur) const
     * 
     * \brief Détermine s'il existe une précédente case d'une certaine couleur
     * 
     * \param[in] couleur, la couleur recherchée
     * 
     * \return true si elle existe, false sinon
     * 
     */ 
    bool ListeDeCases::Iterateur::existeCasePrecedente(Case::Couleur couleur) const
    {
       int distance = 0;
       return noeudPrecedent(couleur, distance) != 0;
    }

    /**
     * \fn int ListeDeCases::Iterateur::positionCourante() const
     * 
     * \brief Permet de connaître la position courante de l'itérateur dans la liste
     * 
     * \return La position de l'itérateur dans la liste
     * 
     */  
    int ListeDeCases::Iterateur::positionCourante() const
    {
       Noeud *courant = m_liste.m_debut;
       if (courant == 0)
          throw range_error("positionCourante: La liste est vide");

       int i = 1;
       while (courant != m_courant)
       {
          courant = courant->m_suivant;
          i++;
       }
       return i;
    }

    /**
     * \fn bool ListeDeCases::Iterateur::estADerniereCase() const
     * 
     * \brief Permet de savoir si l'itérateur se trouve présentement à la dernière case de la liste
     * 
     * \return true si oui, false sinon
     * 
     */
    bool ListeDeCases::Iterateur::estADerniereCase() const
    {
       return m_courant == m_liste.m_fin && m_courant != 0;
    }

    //Ne touchez surtout pas à cette fonction.
    /**
     * \fn std::ostream& operator<<(std::ostream& os, const ListeDeCases & liste)
     * 
     * \brief Permet de visualiser une liste de case
     * 
     * \param[in] os, l'objet os qui représentera la liste
     * \param[in] liste, la liste de cases
     * 
     * \return La liste de case sous forme d'objet ostream
     * 
     */
    std::ostream& operator<<(std::ostream& os, const ListeDeCases & liste)
    {
       if (liste.estVide())
       {
          os << "Liste de cases vide";
       }
       else
       {
          ListeDeCases::Iterateur iter = liste.debut();
          while (!iter.estADerniereCase())
          {
             os << iter.caseCourante() << "; ";
             ++iter;
          }
          os << iter.caseCourante();
       }

       return os;
    }

}
