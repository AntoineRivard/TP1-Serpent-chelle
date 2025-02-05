
#include "ListeCirculaire.h"

/////////////////////////////////////////////////////////////////////////////
//Fichier File.hpp
/////////////////////////////////////////////////////////////////////////////
/**
 * \file File.hpp
 * \brief Ce fichier contient une implémentation générique de la classe File
 * \author Antoine Rivard
 * \version 0.1
 * \date mai-juin 2024
 */


namespace tp1
{
    /**
     * \fn File<T>::File() : liste()
     * 
     * \brief Constructeur de la classe File
     * 
     */
    template<typename T>
    File<T>::File() : liste()
    {
        // Ce constructeur peut rester vide (en utilisant la liste d'initialisation).
    }
    
    /**
     * \fn void File<T>::enfiler ( const T& element )
     * 
     * \brief Permet d'ajouter un element dans la file
     * 
     * \param[in] element, l'élément à ajouter
     * 
     */
    template<typename T>
    void File<T>::enfiler ( const T& element )
    {
        // À compléter !
        liste.ajouterFin (element);
    }

    /**
     * \fn T File<T>::defiler () throw (logic_error)
     * 
     * \brief Retourne et enlève le premier élément de la file
     * 
     * \return Le premier élément de la file
     * 
     */
    template<typename T>
    T File<T>::defiler ()
    {
        // À corriger !
      if (liste.taille() == 0) // Lance une erreur de logique si la file est vide
        {
          throw std::logic_error("La file est vide");
        }
        T valeur = liste.element(1); // Passage à une valeur local de l'élément de la liste avant de l'ôter
        liste.enleverPos(1);
        return valeur;
    }

    /**
     * \fn unsigned int File<T>::taille ()
     * 
     * \brief Permet de connaître la taille de file
     * 
     * \return La taille de la file
     * 
     */
    template<typename T>
    unsigned int File<T>::taille ()
    {
       // À corriger !
       return liste.taille ();
    }

    //Ne touchez pas à cette fonction.
    
    /**
     * \fn std::ostream& operator<<(std::ostream& os, const File<T> & file)
     * 
     * \brief Permet de visualiser une file
     * 
     * \param[in] os, l'objet os qui représentera la file
     * \param[in] file, la file
     * 
     * \return La file sous forme d'objet ostream
     * 
     */
    template< typename T >
    std::ostream& operator<<(std::ostream& os, const File<T> & file)
    {
       os << file.liste;
       return os;
    }

}
