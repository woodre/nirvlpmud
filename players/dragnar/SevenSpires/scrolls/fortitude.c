#include <ansi.h>
/******************************************************************************
 * Program: fortitude.c
 * Path: /players/dragnar/SevenSpires/scrolls
 * Type: Object
 * Created: June 30th, 2015 by Dragnar
 *
 * Purpose: One of the scrolls in the Seven Spires area that give temporary
 *          powers to a player. This one enhances a players WC for a short
 *          amount of time, depending on level / prestige.
 *
 * History:
 *          06/30/2015 - Dragnar
 *            Created
 ******************************************************************************/
int active;

id(string str) {
   return str == "scroll" || str == "fortitude" || str == "scroll of fortitude" ||
          str == (active ? "active_fortitude" : "scroll") ||
          str == (active ? "generic_wc_bonus" : "scroll");
}
short() {
	return "A Scroll of "+(active ? RED : NORM)+"Fortitude"+NORM;
}

long() {
write(YEL+
" _________________________________\n\
/  _\\                             \\\n\
\\ (_/_____________________________/\n\
 \\                             \\\n\
  \\                             \\\n\
   \\  "+RED+" __                      "+NORM+YEL+"  \\ \n\
    \\  "+RED+"|_  _  ___|_ o _|_    _| _ "+NORM+YEL+"\\\n\
     \\ "+RED+"|  (_) |  |_ |  |_|_|(_|(/_"+NORM+YEL+" \\\n\
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
  if( !str || !id(str) )
    return 0;
  
  if( active ) {
    write("The scroll's power has already been released.\n");
    return 1;
  }

  /** Prevent stacking **/
  if( present("active_fortitude", this_player() )) {
    write("Your enhanced fortitude prevents you from using the scroll.\n");
    return 1;
  }

  write("You read the ancient words on the scroll and feel blessed by great strength!\n");
  say(this_player()->query_name()+" says some ancient words and the scroll begins to glow.\n");
  call_out("time_out", (int) this_player()->query_level() * 35 + (int) this_player()->query_prestige_level() * 10 );
  active = 1;
  return 1;
}

gen_wc_bonus() {
  if( !environment() || !environment()->is_player() || environment()->query_level() < 15 )
    return 0;
  return active ? 3 + environment()->query_prestige_level()/2 : 0;
}

time_out() {
  if(environment() && environment()->is_player() )
    tell_object( environment(), HIR+"The scroll bursts into flames and you feel weakened.\n"+NORM);
  destruct(this_object());
}

is_active() { return active; }

get() { return 1; }
query_weight() { return 0; }
query_value() { return 8000; }
query_save_flag() { return (active ? 1 : 0); }
