#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

/* Initialisation of the list
 * */
list_ptr list_new(void)
{
  return NULL;
}

/* Add a new cel to a list. 
 *  store the sprite_t to the new cel
 * */
list_ptr list_add(sprite_t sprite, list_ptr list)
{
  //crée un pointeur 'nouveau' qui va contenir l'adresse de la nouvelle case (data +next)
  list_ptr nouveau;
  
  // on reserve en mémoire la place nécessaire pour une case (data + next) et on stocke dans nouveau
  nouveau = malloc(sizeof(s_list_node_t));
  
  // si aucune adresse n'est retournée , on garde l'ancienne liste
  if (nouveau == NULL){
    return list;
  }
  
  // on met le sprite dans data de la nouvelle case
  nouveau->data = sprite;

  // next pointe vers la première case de l'ancienne liste
  nouveau->next = list;
  
  // on retourne la nouvelle premiere case
  return nouveau;
}

/* Return true if the list is empty
 * */
bool list_is_empty(list_ptr l)
{
  //si l ne pointe vers aucune adresse alors l est vide
  return l == NULL;
}

/* Return the next cel in list or NULL
 * */
list_ptr list_next(list_ptr l)
{
  // si aucne case actuel, impossible d'aller au prochain
  if (l == NULL){
    return NULL;
  }
  // va a la case suivante grace à l'adresse dans next
  return l->next;
}

/* Search the first cel of the list & 
 *  return the associated sprite 
 * */
sprite_t list_head_sprite(list_ptr l)
{
  // si aucune case actuel alors aucune liste à récupérer
  if (l == NULL){
    return NULL;
  } 
  // récupère le sprite dans data
  return l->data;
}

/* Search the last cel of a list 
 *  Remove the cel from the list
 *  Return the associated sprite
 * */
sprite_t list_pop_sprite(list_ptr * l)
{
  // si l ne pointe vers aucune liste, on a rien à supprimer
  if (l== NULL){
    return NULL;
  }
  // si la liste est vide, on a rien à supprimer
  if (*l== NULL){
    return NULL;
  }
  
  // on fait pointé actuel vers la premère case de la liste
  list_ptr actuel = *l;

  //et on avance jusqu'a la dernière case
  while (actuel->next != NULL){
    actuel = actuel->next;
  }

  //a la sortie de la boucle, actuel pointe vers la dernière case
  sprite_t sprite = actuel->data;

  //ensuite on supprime la dernière case de la liste 
  list_remove(actuel, l);
  
  // et on retourne le sprite qui était dans la case supprimée
  return sprite;
}

/* Remove the given cel in a list
 * */
void list_remove(list_ptr elt, list_ptr *l)
{
  // si l ne pointe vers aucune liste, on a rien à supprimer
  if (l== NULL){
    return;
  }

  // si elt ne pointe vers aucune case, on a rien à supprimer
  if (elt== NULL){
    return;
  }

  // si la liste est vide, on a rien à supprimer
  if (*l== NULL){
    return;
  }

  // si elt est la première case
  if (*l== elt){
    // la première case devient celle qui vient après elt
    *l=elt->next;

    // et ensuite on doit libérer la mémoire qui était occupé par elt
    free(elt);
    return;
  }

  // on parcourt ensuite la liste pour trouver lacase avant elt
  list_ptr actuel = *l;
  while (actuel->next != NULL && actuel->next != elt){
    actuel = actuel->next;
  }

  // si la case suivante est elt, on la retire de la chaine
  if (actuel->next == elt){
    actuel->next = elt->next;

    //ensuite on libère la mémoire de la case elt
    free(elt);
  }
}

/* Wipe out a list. 
 *  Don't forget to sprite_free() for each sprite
 * */
void list_free(list_ptr l)
{
}

/* Return the length of a list
 * */
int list_length(list_ptr l)
{
  int longueur = 0;

  list_ptr actuel = l;

  while (actuel!=NULL){
    longueur++;
    actuel=actuel->next;
  }

  return longueur;
}

/* Reverse the order of a list
 * */
void list_reverse(list_ptr * l)
{
}

/* Copy a list to another one. 
 *  Return the new list
 * */
list_ptr list_clone(list_ptr list)
{
  return NULL;
}
