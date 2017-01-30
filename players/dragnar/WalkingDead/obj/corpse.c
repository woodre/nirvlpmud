inherit "/obj/corpse";

#include "../defs.h"

status search_flag;
status dismembered;

reset(arg) {
	if(arg) return;
  set_heart_beat(1);
  dismembered = -2;
}

init() {
  ::init();
  add_action("Dismember","dismember");
  add_action("Dismember","mutilate");
}

search(str) {
  int i, size;
  object *treasure;
  
  if (!str || !id(str))
    return 0;
  if( !search_flag++ ) {
    treasure = DEADDM->get_walker_objs( query_corpse_level() );
    for( i = 0, size = sizeof(treasure); i < size; i ++ ) {
      move_object(treasure[i] ,this_object());
    }
  }
  ::search( str );
  return 1;
}

Dismember(string str) {
  object guts;
  if (!str || !id(str) )
    return 0;
  
  if( dismembered++ < 1 ) {
    guts = present("walker_guts", this_player() );
  	if( !guts )
      guts = clone_object("/players/dragnar/WalkingDead/obj/walker_guts");
    guts->set_time_len( (query_corpse_level() - WALKER_START)*50 + 100 );
    move_object( guts, this_player() );
    if( dismembered == -1 )
	  name = name + " (dismembered)";
    write("You dismember the corpse and gag as you pick up the foul smelling innards.\n");
    say(capitalize(this_player()->query_name())+" dismembers the corpse and gags as "+this_player()->query_pronoun()+" picks up the innards.\n");
  }
  else 
    write("This corpse has already been dismembered.\n");
  
  return 1;
}
