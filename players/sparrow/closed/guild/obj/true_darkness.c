/*****************************************************************************
 *      File:                   true_darkness.c
 *      Function:               True Darkness ability object
 *      Author(s):              Sparrow@Nirvana
 *      Copyright:              Copyright (c) 2011 Sparrow All Rights Reserved.
 *      Source:                 03/14/2011
 *      Notes:                  
 *      Change History:         
 ****************************************************************************/
#include <ansi.h>
inherit "obj/treasure";

short() {
  return 0;
}
long() {
  write("A wall of dark shadows has eveloped you. They feel cool and inviting.\n");
}
extra_look() {
  if(this_player() == environment()) {
    write("You are surrounded by a flowing wall of "+HIK+"d"+HIW+"ark "+
          HIK+"s"+HIW+"hadows"+NORM+".\n");
  }
  else {
    write((string)environment()->query_name()+" is surrounded by a flowing wall of "+HIK+"d"+HIW+"ark "+
          HIK+"s"+HIW+"hadows"+NORM+".\n");
  }
}
get() { return; }
drop() { return 1; }
id(str) { return str=="true_darkness" || str == "darkness" || str == "shadows"; }

void init() {
  if (!this_object()) return;
}

/* 
 * Function name: wink_out()
 * Description:   This function causes the globe of darkness to
 *                "wink out" (destruct)
 * Arguments:     none
 * Returns:       void
 */
void 
wink_out(){
  tell_room(environment(environment()), 
    HIY+"The darkness surrounding "+environment()->query_name()+
    " is sucked back into "+possessive(environment())+" eye sockets.\n"+NORM);
  destruct(this_object());
  return;
}

int
set_darkness(int dark){
  if(!dark) {
    return 0;
  }
  if(!environment()){
    return 0;
  }
  set_light(dark);
  tell_room(environment(environment()), 
    BOLD+"Darkness"+NORM+" pours from "+environment()->query_name()+"'s eyes, creating a wall of "+HIK+"s"+HIW+"hadows"+NORM+".\n");
  /* uncomment for debugging
  tell_room(environment(environment(this_object())), 
    BOLD+"The light level of this object is: "+HIY+this_object()->query_light()+NORM+".\n"+
    BOLD+"It is supposed to be: "+HIY+dark+NORM+".\n");
  */
  return 1;
}