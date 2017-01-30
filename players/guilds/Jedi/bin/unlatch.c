#include <ansi.h>
#include "../defs.h"

main(string str, object jedi, object gob){
	
  if( gob->query_wep_life() <= 0){
    tell_object( jedi, "What?\n");
    return 1;
  }

  if(!str){ 
    tell_object(jedi, "Unlatch what?\n");
    return 0;
  }
        
  if(str == "lightsaber" || str == "saber"){
    object ls;
    say(jedi->query_name()+" unlatches "+ jedi->query_possessive()+" lightsaber.\n");
    tell_object(jedi, "You unlatch your lightsaber from your belt.\n");
    /** Set the saber attributes **/
    ls = clone_object(OBJDIR +"/saber.c");
    ls->set_wep_color(gob->query_wep_color());
    ls->set_wep_life(gob->query_wep_life());
    move_object(ls, jedi);
    /** Clear the guild obj attributes **/
    gob->set_wep_color(NORM);
    gob->set_wep_life(0);
    return 1;
  }
  tell_object(jedi, "What?\n");
  return 1;
}
