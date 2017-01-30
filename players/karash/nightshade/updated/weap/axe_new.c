inherit "obj/weapon";
#include <ansi.h>

/******************************************************************************
 * Program: axe_new.c
 * Path: /players/nightshade/weap/
 * Type: Weapon
 * Created: September 2014 by Karash
 *
 * Purpose: A basic axe weapon to clone on Imp Master since his attack chat mentions
 *          his axe.  Since imps usually fight with poison, this axe has an additional
 *          poison damage.
 * 
 * History:
 *          
 ******************************************************************************/

reset(arg) 
{
::reset(arg);
  if(arg) return;
  
  set_name("axe");
  set_short("The Master's Axe");
  set_long("A well-balanced axe with an extremely sharp edge which seems to be dripping\n\
with a green, poisonous ooze.\n");

  set_type("axe");
  /* Physical Damage */
  set_class(10);
  /* Poison Damage */
  set_params("other|poison",5,0);
  set_weight(3);
  set_value(2000);

}


