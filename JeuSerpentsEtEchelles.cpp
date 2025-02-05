/////////////////////////////////////////////////////////////////////////////
//Fichier JeuSerpentsEtEchelles.cpp
/////////////////////////////////////////////////////////////////////////////
/**
 * \file JeuSerpentsEtEchelles.cpp
 * \brief Ce fichier contient une implémentation de la classe JeuSerpentsEtEchelles
 * \author Antoine Rivard
 * \version 0.1
 * \date mai-juin 2024
 */

#include <cmath>

#include "JeuSerpentsEtEchelles.h"

using std::cout;
using std::endl;
using std::string;
using std::ostream;

namespace tp1
{

    /**
     * \fn JeuSerpentsEtEchelles::JeuSerpentsEtEchelles()
     * 
     * \brief Constructeur de la classe JeuSerpentsEtEchelles
     * 
     */  
    JeuSerpentsEtEchelles::JeuSerpentsEtEchelles()
    {
        // Ce constructeur peut rester vide (en utilisant la liste d'initialisation).
    }
    
    /**
     * \fn Resultat JeuSerpentsEtEchelles::jouer(unsigned int maximumDeTours)
     * 
     * \brief Simule une partie de Serpents et Échelles
     * 
     * \param[in] maximumDeTours le nombre maximum de tours qu'une partie peut durer
     * 
     * \return Le résultat de la partie
     * 
     */
    Resultat JeuSerpentsEtEchelles::jouer(unsigned int maximumDeTours)
    {
        // Faire une boucle qui fera au plus «maximumDeTours» tours.
        // Dans cette boucle, faire une autre boucle qui fera un tour par joueur.
        // La partie se termine dès qu'un joueur accède à la dernière case À LA FIN DE SON TOUR.

        // La liste des choix de couleurs est contenue dans une liste circulaire appelée m_choix.
        // Vous devez parcourir toutes les couleurs et lorsque vous arrivez à la dernière, vous devez revenir à la première.

        // Les joueurs sont contenus dans une file et joue à tour de rôle.
        // Il faut donc défiler un joueur, le faire jouer et l'enfiler à la fin de la file.

        // Aide sur l'utilisation des itérateurs de cases que possèdent les joueurs.
        // Supposer que unJoueur est une instance de la classe Joueur, alors :
        // unJoueur.position.existeCaseSuivante(uneCouleur) : permet de savoir si une case de couleur «uneCouleur»
        // se trouve après la case où se trouve unJoueur.
        // unJoueur.position.caseSuivante(uneCouleur) : permet de déplacer un joueur sur la prochaine case de couleur uneCouleur.
        // unJoueur.position.caseCourante().decoration : permet de connaître la décoration de la case sur laquelle
        // se trouve unJoueur.
        // Voir la classe ListeDeCases::Iterateur pour connaitre les autres fonctions disponibles.
      
      int tour = 0;
      int i = 0;
      bool victoire = false;
      Resultat resultat_partie(maximumDeTours);
      
      while(tour < maximumDeTours - 1 && !victoire) // Boucle comptant le nombre de tour et se terminant si la limite ou la victoire est atteinte
        {
          tour++;
          for (int n = 0; n < m_joueurs.taille (); n++) // Boucle jouant le tour d'un joueur pour chaque joueur
                {
              if (i == m_choix.taille ()) // Permet de réinitialiser le choix au début si on arrive à la fin de la liste
                {
                  i = 0;
                }
              Joueur joueur_courant(m_joueurs.defiler()); // Defile le joueur dont c'est le tour de jouer
              i++;
              if (joueur_courant.position.existeCaseSuivante (m_choix.element(i))) // Vérifie si il existe une prochaine case de la couleur du choix, avance si c'est le cas
                {
                  joueur_courant.position.caseSuivante (m_choix.element(i));
                  if (joueur_courant.position.caseCourante ().decoration == tp1::Case::Serpent) // (if et else if) Rejoue si le joueur tombe sur un serpent ou une échelle
                    {
                      if (i == m_choix.taille ()) // Permet de réinitialiser le choix au début si on arrive à la fin de la liste
                        {
                          i = 0;
                        }  
                      i++;
                      if (joueur_courant.position.existeCasePrecedente (m_choix.element(i)))
                        {
                          joueur_courant.position.casePrecedente (m_choix.element (i));
                        }
                    } else if(joueur_courant.position.caseCourante ().decoration == tp1::Case::Echelle)
                      {
                          if (i == m_choix.taille ()) // Permet de réinitialiser le choix au début si on arrive à la fin de la liste
                            {
                              i = 0;
                            }  
                          i++;
                          if (joueur_courant.position.existeCaseSuivante (m_choix.element(i)))
                            {
                              joueur_courant.position.caseSuivante (m_choix.element (i));
                            }                    
                      }
                }
              m_joueurs.enfiler (joueur_courant); // Remet le joueur à la fin de la file
              if (joueur_courant.position.estADerniereCase ()) // Verifie la condition de victoire
                {
                  resultat_partie.nombreDeTours = tour;
                  resultat_partie.nom = joueur_courant.nom;
                  victoire = true;
                  break;
                }
            }
        }
       return resultat_partie;
    }

    //Les quatre méthodes suivantes sont utilisées par le générateur jeu.
    //Normalement, vous ne devriez pas avoir besoin de les appeler.

    //Ne pas modifier cette méthode.
    
    /**
     * \fn void JeuSerpentsEtEchelles::effacer()
     * 
     * \brief Réinitialise un jeu de Serpents et Échelles
     * 
     */ 
    void JeuSerpentsEtEchelles::effacer()
    {
       while ( m_cases.taille() > 0 )
          m_cases.enleverCase(1);
       while ( m_choix.taille() > 0 )
          m_choix.enleverPos(1);
       while ( m_joueurs.taille() > 0 )
          m_joueurs.defiler();
    }

    //Ne pas modifier cette méthode.
    
    /**
     * \fn void JeuSerpentsEtEchelles::ajouterCase( Case &_case )
     * 
     * \brief Ajoute une case au plateau d'un jeu
     * 
     * \param[in] _case, la case
     * 
     */    
    void JeuSerpentsEtEchelles::ajouterCase( Case &_case )
    {
       m_cases.ajouterCaseALaFin( _case );
    }

    //Ne pas modifier cette méthode.
    
    /**
     * \fn void JeuSerpentsEtEchelles::ajouterCase( Case &_case )
     * 
     * \brief Ajoute un choix dans la liste de choix d'un jeu
     * 
     * \param[in] couleur, la couleur du choix
     * 
     */ 
    void JeuSerpentsEtEchelles::ajouterChoix( Case::Couleur couleur )
    {
       m_choix.ajouterFin( couleur );
    }

    //Ne pas modifier cette méthode.
    
    /**
     * \fn void JeuSerpentsEtEchelles::ajouterJoueur( Joueur joueur )
     * 
     * \brief Ajoute un joueur à un jeu
     * 
     * \param[in] joueur, le joueur
     * 
     */ 
    void JeuSerpentsEtEchelles::ajouterJoueur( Joueur joueur )
    {
       m_joueurs.enfiler( joueur );
    }

    //Ne pas modifier cette méthode.
    
    /**
     * \fn ListeDeCases::Iterateur JeuSerpentsEtEchelles::premiereCase()
     * 
     * \brief Accesseur de la première case du plateau d'un jeu
     * 
     * \return un itérateur pointant sur le début de la liste de cases du plateau
     * 
     */     
    ListeDeCases::Iterateur JeuSerpentsEtEchelles::premiereCase()
    {
       return m_cases.debut();
    }


    //Ne pas modifier cette fonction.
    
    /**
     * \fn ostream& operator<<(ostream& os, const Joueur & joueur)
     * 
     * \brief Permet de visualiser les informations d'un joueur
     * 
     * \param[in] os, l'objet ostream qui sert à représenter le joueur
     * \param[in] joueur, le joueur
     * 
     * \return un objet ostream représentant le joueur
     * 
     */ 
    ostream& operator<<(ostream& os, const Joueur & joueur)
    {
       os << joueur.nom << " : " << joueur.position.positionCourante();
       return os;
    }

    //Ne pas modifier cette méthode.

    /**
     * \fn void JeuSerpentsEtEchelles::afficheResultats(Resultat gagnant)
     * 
     * \brief Permet de visualiser les informations d'une partie de jeu terminée
     * 
     * \param[in] gagnant, le gagnant de la partie
     * 
     */    
    void JeuSerpentsEtEchelles::afficheResultats(Resultat gagnant)
    {

       if (gagnant.nom != "")
          cout << "Gagnant : " << gagnant.nom << endl;
       else
          cout << "Aucun gagnant" << endl;
       cout << "Nombre de tours realises : " << gagnant.nombreDeTours << endl;
       cout << "Position des joueurs : " << endl;
       cout << m_joueurs << endl;

       cout << "Plateau de jeu:" << endl;
       cout << m_cases << endl;

       cout << "Liste de choix:" << endl;
       cout << m_choix << endl;
    }

}
