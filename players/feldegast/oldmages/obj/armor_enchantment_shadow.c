/*
A shadow for mage armor enchantment spell(s).
*/
#include "/players/feldegast/defines.h"

inherit "/players/feldegast/mages/obj/enchantment_shadow";

int protection; /* 0 or 1 */
int flash; /* 0..3 */

void set_protection(int arg) {
  protection=arg;
}

void add_flash(int arg) {
  if(++flash > 3) flash=3;
}

call_armor_special(owner) {
  if(protection && !random(5) && charges > 0) {
    tell_object(owner,"Your "+target->short()+" flashes protectively!\n");
    charges--;
    return 1;
  }
  if(flash && !random(4)) {
    tell_object(owner,HIC+"Your armor zaps "+TP->query_name()+" with electric volts!\n"+NORM);
    if(TP)
    write(HIC+"You're jolted and your arm feels numb as you are electrocuted by\n "+
          owner->query_name()+"'s "+short()+".\n"+NORM);
    flash--;
    TP->hit_player(random(5)+5);
  }
  target->call_armor_special(owner);
}

