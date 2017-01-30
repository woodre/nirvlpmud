#include <ansi.h>
inherit "room/room";

object *kombatants;

init() {
  ::init();
  if(this_player()) {
    if(this_player()->is_pet() || this_player()->is_kid()) {
      tell_room(this_object(), HIR+"A wall of flame erupts from the platform!\n"+NORM);
      tell_room(this_object(), this_player()->query_name()+"'s flesh instantly begins to melt.\n");
      this_player()->hit_player(1000);
    }
    if( !kombatants ) {
      kombatants = ({ this_player() });
    }
    	
    else if( sizeof(kombatants) >= 2 ) {
      write("You are unable to enter "+HIR+"Mortal "+HIY+"Kombat"+NORM+".\n");
      move_object(this_player(),"players/dragnar/workroom");
      return;
    }
    else {
      kombatants += ({ this_player() });
    } 
    this_player()->set_fight_area();
    add_action("NoQuit","quit");
    tell_object(find_player("dragnar"), "Kombatants: "+sizeof(kombatants)+"\n");
  }
}

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc=("Temple of mortal kombat");
  long_desc=
"You stand in the middle of a platform.  Around the platform are many masters\n" +
"of martial arts.  The old men seem to be pleased that a tounament is about\n" +
"to begin.  The time has come, you have entered Mortal Kombat.\n" +
"You must fight well or die.\n",

  dest_dir=
  ({
  });
}

realm() {
  return "NT"; 
}

exit() {
  if(this_player() && kombatants) {
    if( member_array( this_player(), kombatants ) >= 0 )
      kombatants -= ({ this_player() });
    this_player()->clear_fight_area();
  }
}

NoQuit(){
   write("You are unable to quit out of Mortal Kombat!\n");
   return 1;
}

QueryMKTemple() { return 1; }

ResetTemple() {
  kombatants = 0;
  call_out("CleanRoom",2);
}

CleanRoom() {
  object *inv;
  int i;
  
  inv = all_inventory();
  for(i=0; i<sizeof(inv); i++) {
    if(inv[i]->is_player()) {
      move_object(inv[i],"players/dragnar/workroom");
    }
    else {
      destruct(inv[i]);
    }
  }
}