#include <ansi.h>
/******************************************************************************
 * Program: wisdom.c
 * Path: /players/dragnar/SevenSpires/scrolls
 * Type: Object
 * Created: June 30th, 2015 by Dragnar
 *
 * Purpose: One of the scrolls in the Seven Spires area that give temporary
 *          powers to a player. This one gives the player double xp for an
 *          amount of time.
 *
 * History:
 *          06/30/2015 - Dragnar
 *            Created
 ******************************************************************************/
 
int active;

id(string str) {
   return str == "scroll" || str == "wisdom" || str == "scroll of wisdom" ||
          str == (active ? "double_xp_object" : "scroll");
}
short() {
	return "A Scroll of "+(active ? HIB : NORM)+"Wisdom"+NORM;
}

long() {
write(YEL+
" _________________________________\n\
/  _\\                             \\\n\
\\ (_/_____________________________/\n\
 \\                             \\\n\
  \\                             \\\n\
   \\   "+HIB+"\\  X  / o  _ _ ) _   _ _"+NORM+YEL+"  \\ \n\
    \\   "+HIB+"\\/ \\/  ( ( (_( (_) ) ) )"+NORM+YEL+"  \\\n\
     \\  "+HIB+"         _)             "+NORM+YEL+"   \\\n\
      \\                             \\\n\
       \\                             \\\n\
      __\\ "+NORM+"Reading of this scroll will"+YEL+" \\\n\
     / )_\\  "+NORM+"invoke the power within"+YEL+"    \\\n\
     \\___/_____________________________/\n"+NORM);
}

reset(arg){
  if(arg) return;
}

init() {
  add_action("read_scroll","read");
}

int read_scroll(string str) {
  int bonus_time;
  
  if( !str || !id(str) )
    return 0;

  if( active ) {
    write("The scroll's power has already been released.\n");
    return 1;
  }
  
  if( present("double_xp_object", this_player() ) ) {
    write("Your level of wisdom prevents you from invoking the scroll.\n");
    return 1;    
  }
  
  write("You read the ancient words on the scroll and feel blessed by great wisdom!\n");
  say(this_player()->query_name()+" says some ancient words and looks more wise.\n");
  tell_object( environment(), ctime() );
  
  /** 45 mins plus bonus time for prestige levels with cap of 75 mins **/
  bonus_time = (int) this_player()->query_prestige_level() * 50;
  if( bonus_time > 1800 )
    bonus_time = 1800;
  call_out("time_out", 2700 + bonus_time );
  active = 1;
  return 1;
}

time_out() {
  if(environment() && environment()->is_player() ) {
    tell_object( environment(), HIB+"\n\nThe scroll bursts into flames and you feel your enhanced wisdom fade.\n\n"+NORM);
    tell_object( environment(), ctime() );
  }
  destruct(this_object());
}

get() { return 1; }
drop() { return (active ? 1 : 0 ); }
query_weight() { return 0; }
query_value() { return 30000; }
query_save_flag() { return (active ? 1 : 0); }
