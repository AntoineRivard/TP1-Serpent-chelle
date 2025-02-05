/////////////////////////////////////////////////////////////////////////////
//Fichier Case.cpp
/////////////////////////////////////////////////////////////////////////////
/**
 * \file Case.cpp
 * \brief Ce fichier contient une implémentation de la classe Case
 * \author Antoine Rivard
 * \version 0.1
 * \date mai-juin 2024
 */

#include "Case.h"

namespace tp1
{

    /*
     * \fn Case::Case(Case::Couleur p_couleur, Case::Decoration p_decoration)
     * 
     * \brief Constructeur de la classe Case
     * 
     * \param[in] decoration, la décoration
     * \param[in] couleur, la couleur
     * 
     */
    Case::Case(Case::Couleur couleur, Case::Decoration decoration) : couleur(couleur), decoration(decoration)
    {
    }

    /**
     * \fn Case::~Case()
     * 
     * \brief Destructeur de la classe Case
     * 
     */
    Case::~Case()
    {
    }

    //Fonction pour aider à afficher plus naturellement une case à l'écran.
    
    /**
     * \fn std::string decorationEnLettre(Case::Decoration decoration)
     * 
     * \brief Permet de représenter la décoration d'une case sous forme de lettre
     * 
     * \param[in] decoration, la decoration
     * 
     */
    std::string decorationEnLettre(Case::Decoration decoration)
    {
       switch (decoration)
       {
          case Case::Serpent:
             return "S";
          case Case::Echelle:
             return "E";
          default:
             return "A";
       }
    }
    
    /**
     * \fn std::ostream& operator<<(std::ostream& os, const Case & uneCase)
     * 
     * \brief Permet de visualiser une case
     * 
     * \param[in] os, l'objet os qui représentera la case
     * \param[in] uneCase, la case
     * 
     * \return La case sous forme d'objet ostream
     * 
     */
    std::ostream& operator<<(std::ostream& os, const Case & uneCase)
    {
       os << "(" << uneCase.couleur << "," << decorationEnLettre(uneCase.decoration) << ")";

       return os;
    }

}
