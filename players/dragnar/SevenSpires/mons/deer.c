inherit "/obj/monster";
#include <ansi.h>
/******************************************************************************
 * Program: deer.c
 * Path: /players/dragnar/SevenSpires/mons
 * Type: Mob
 * Created: October 22nd, 2014 by Dragnar
 *
 * Purpose: A low level monster in the Seven Spires area. 
 * History:
 *          10/22/2014 - Dragnar
 *            Created
 ******************************************************************************/
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  SetMultipleIds( ({ "white tail","white","white tailed", }) );
  set_name("deer");
  set_race("deer");
  set_short("A "+HIW+"White Tail Deer"+NORM);
  if( random(2) ) {
    set_level(10);
    set_long(
"A female white-tailed deer. Very shy, she seems very anxious about\n\
your presence. Her name sake is raised as she determines if she should\n\
run from you.\n");
    set_gender("female");
  }
  else {
    /** Males are much more of a threat **/
    set_level(15);
    set_long(
"A male white-tailed deer. He is much bigger and more muscular than\n\
the females of the same species. This one also has a fearsome looking\n\
set of antlers that can be very deadly.\n");
    set_gender("male");
  }
  set_wander_realm("/players/dragnar/SevenSpires/rooms/forest");
}

init() {
  int ste;
  
  ::init();
  if( !this_player() )
    return;
  
  ste = this_player()->query_attrib("ste");
  if( random(50) < ste ) {
    call_out("init_effect", 2+random(2), ste);
  }
  
}

init_effect( int x ) {
  switch(random(x)) {
    case 0..10:
      tell_room(environment(), "The deer gets spooked and waves its white tail as it runs off.\n");
      wander();
      break;
    case 11..15:
      tell_room(environment(), "The deer sniffs the wind and peers in your direction.\n");
      break;
    case 16..21:
      tell_room(environment(), "The deer raises its head and looks nervously around.\n");
      break;
    default:
      break;
  }
}

heart_beat() {
    ::heart_beat();
}
