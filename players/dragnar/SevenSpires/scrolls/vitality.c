#include <ansi.h>
/******************************************************************************
 * Program: vitality.c
 * Path: /players/dragnar/SevenSpires/scrolls
 * Type: Object
 * Created: June 30th, 2015 by Dragnar
 *
 * Purpose: One of the scrolls in the Seven Spires area that give temporary
 *          powers to a player. This one enhances a players max HP for a short
 *          amount of time, depending on level / prestige.
 *
 * History:
 *          06/30/2015 - Dragnar
 *            Created
 ******************************************************************************/

int active, amount;

id(string str) {
   return str == "scroll" || str == "vitality" || str == "scroll of vitality" ||
          str == (active ? "generic_hp_bonus" : "scroll") ||
          str == (active ? "active_vitality" : "scroll");
}
short() {
	return "A Scroll of "+(active ? HIG : NORM)+"Vitality"+NORM;
}

long() {
write(YEL+
" _________________________________\n\
/  _\\                             \\\n\
\\ (_/_____________________________/\n\
 \\                             \\\n\
  \\                             \\\n\
   \\   "+HIG+"\\  / o _)_ _   ) o _)_"+NORM+YEL+"    \\ \n\
    \\   "+HIG+"\\/  ( (_ (_( (  ( (_ (_("+NORM+YEL+"  \\\n\
     \\  "+HIG+"                       _)"+NORM+YEL+"  \\\n\
      \\                             \\\n\
       \\                             \\\n\
      __\\ "+NORM+"Reading of this scroll will"+YEL+" \\\n\
     / )_\\  "+NORM+"invoke the power within"+YEL+"    \\\n\
     \\___/_____________________________/\n"+NORM);

  if( this_player() && this_player()->query_level() > 50 )
      write("\tActive  : "+active+"\n\
\tAmount  : "+amount+"\n");
}

reset(arg){
  if(arg) return;
  
}

init() {
  add_action("read_scroll","read");
  if( !environment() || !environment()->is_player() )
    return;
  
  amount = environment()->query_level() + environment()->query_extra_level() + environment()->query_prestige_level();
}

int read_scroll(string str) {
  if( !str || !id(str) )
    return 0;

  if( active ) {
    write("The scroll's power has already been released.\n");
    return 1;
  }
  
  /** Prevent stacking **/
  if( present("active_vitality", this_player() )) {
    write("Your enhanced vitality prevents you from using the scroll.\n");
    return 1;
  }
  
  write("You read the ancient words on the scroll and feel strength rush into you!\n");
  say(this_player()->query_name()+" says some ancient words and strength rushes into them.\n");
  call_out("time_out", (int) this_player()->query_level() * 35 + (int) this_player()->query_extra_level() * 10 );
  active = 1;
  return 1;
}

int gen_hp_bonus() {
  return active ? amount : 0;
}

time_out() {
  if(environment() && environment()->is_player() )
    tell_object( environment(), HIG+"The scroll bursts into flames and you feel weakened.\n"+NORM);
  destruct(this_object());
}

get() { return 1; }
drop() { return 0; }
query_weight() { return 0; }
query_value() { return 0; }
