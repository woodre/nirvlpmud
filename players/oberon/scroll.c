#include <ansi.h>
#include "../defs.h"
/******************************************************************************
 * Program: acuminate.c
 * Path: /players/dragnar/SevenSpires/scrolls
 * Type: Object
 * Created: June 30th, 2015 by Dragnar
 *
 * Purpose: One of the scrolls in the Seven Spires area that give temporary
 *          powers to a player. This one enhances uses a shadow to make
 *          any weapon un-breakable.
 *
 * History:
 *          06/30/2015 - Dragnar
 *            Created
 ******************************************************************************/
 int charges;
 
id(string str) {
   return str == "scroll" || str == "acuminate" || str == "acumination" ||
          str == "scroll of acumination";
}
short() {
  return "A Scroll of "+HIK+"Acumination"+NORM;
}

long() {
write(YEL+
" _________________________________\n\
/  _\\                             \\\n\
\\ (_/_____________________________/\n\
 \\                             \\\n\
  \\   "+HIK+" _                        "+NORM+YEL+"\\ \n\
   \\  "+HIK+"|_| _    __  o __  _ _|_ _ "+NORM+YEL+"\\\n\
    \\ "+HIK+"| |(_ |_|||| | | |(_| |_(/_"+NORM+YEL+" \\\n\
     \\  "+HIK+ pad(implode(explode(pad("",charges,'*'),""),"    "),25)+NORM+YEL+"  \\\n\
      \\                             \\\n\
       \\   "+NORM+"This scroll gives the "+YEL+"    \\\n\
      __\\    "+NORM+"bearer the power to "+YEL+"     \\\n\
     / )_\\    "+NORM+"acuminate any weapon."+YEL+"    \\\n\
     \\___/_____________________________/\n"+NORM);
}

reset(arg){
  if(arg) return;
  charges = 5;
}

init() {
  add_action("do_acuminate","acuminate");
}

int do_acuminate(string str) {
  object wep, shad;

  if( !str ) {
    notify_fail("Acuminate what weapon?\n");
    return 0;
  }
  wep = present(str, this_player());

  if( !wep ) {
    notify_fail("You do not have a "+str+".\n");
    return 0;
  }

  if( !wep->is_weapon() || wep->is_acuminated() ) {
    notify_fail("You are unable to acuminate the "+wep->short()+".\n");
    return 0;
  }
  
  write("You whisper the words of acumination and the "+wep->short()+" vibrates with the added strength.\n"); 
  say(this_player()->query_name()+" whispers the words of acumination and the "+wep->short()+" vibrates.\n"); 
  shad = clone_object(OBJDIR+"/acuminate_shadow.c");
  shad->start_wep_shadow( wep );
  charges--;
  if( charges < 1 ) {
    write("The scroll, devoid of power, crumbles to ashes in your hands.\n");
    destruct( this_object() );
  }
  return 1;
}

locker_arg() {
  return ""+charges;
}

locker_init(str) {
  if(str)
    sscanf(str,"%d",charges);
}

get() { return 1; }
drop() { return 0; }
query_weight() { return 0; }
query_value() { return 0; }
