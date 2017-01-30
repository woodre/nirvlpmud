#include <ansi.h>
#include "../defs.h"
/******************************************************************************
 * Program: quiescent.c
 * Path: /players/dragnar/SevenSpires/scrolls
 * Type: Object
 * Created: June 30th, 2015 by Dragnar
 *
 * Purpose: One of the scrolls in the Seven Spires area that give temporary
 *          powers to a player. This one allows a player to prevent a mob
 *          from running away, for a period of time. 1 use only.
 *
 * History:
 *          06/30/2015 - Dragnar
 *            Created
 ******************************************************************************/
int active;
object shad;

id(string str) {
   return str == "scroll" || str == "quiescent" || str == "quiescence" || str == "scroll of quiescence";
}
short() {
	return "A Scroll of "+(active ? BLU : NORM)+"Quiescence"+NORM;
}

long() {
write(YEL+
" ___________________________________\n\
/  _\\                               \\\n\
\\ (_/_______________________________/\n\
 \\                               \\\n\
  \\ "+BLU+"  _                           "+NORM+YEL+"\\\n\
   \\ "+BLU+"/ \\     o  _   _  _  _  ._ _|_"+NORM+YEL+"\\\n\
    \\"+BLU+"\\_X |_| | (/_ _> (_ (/_ | | |_"+NORM+YEL+" \\\n\
     \\                               \\\n\
      \\                               \\\n\
       \\     "+NORM+"This scroll gives the "+YEL+"    \\\n\
      __\\      "+NORM+"bearer the power to "+YEL+"     \\\n\
     / )_\\      "+NORM+"quiescent any foe."+YEL+"       \\\n\
     \\___/_______________________________/\n"+NORM);
}

reset(arg){
  if(arg) return;
}

init() {
  add_action("do_quiescent","quiescent");
}

int do_quiescent(string str) {
  object ob, targ;

  if( !str )
    return 0;
  
  if( active ) {
    write("The scroll's power has already been released.\n");
    return 1;
  }

  targ = present(str, environment( this_player() ) );
  if( !targ || !targ->is_npc() ) {
    write("The scroll fails to obey your command.\n");
    return 1;
  }

  write("You read the ancient words on the scroll and "+capitalize(str)+" stops moving!\n");
  say(this_player()->query_name()+" says some ancient words and the scroll begins to glow.\n");
  active = 1;
  shad = clone_object(OBJDIR+"/quiescence_shadow.c");
  shad->do_shadow( targ );
  call_out( "time_out", (int) this_player()->query_attrib("int") * 20 );
  return 1;
}

time_out() {
  if(environment() && environment()->is_player() )
    tell_object( environment(), BLU+"The scroll melts away and evaporates into the air.\n"+NORM);
  if(shad)
    shad->stop_shad();
  destruct(this_object());
}

remove_object() {
  if(shad)
    shad->stop_shad();
  destruct(this_object());
  return 1;
}


is_active() { return active; }

get() { return 1; }
drop() { return (active ? 1 : 0 ); }
query_weight() { return 0; }
query_value() { return 0; }
query_save_flag() { return (active ? 1 : 0); }
