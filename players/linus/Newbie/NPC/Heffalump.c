#include "/players/linus/def.h"
#include "/players/linus/color.c"
/*  The color randomizer code can be found in /players/linus/color.c  */
/*   Special thanks to Earwax for help with the code!   */
inherit "/obj/monster.c";
object coins;
string blah;
id(str) { return str=="heffalump" || str=="lump" || str=="monster"; }
reset(arg) {
 ::reset(arg);
 if(arg) return;
 blah = color_name("Heffalump");
 set_short(blah);
 set_name(blah);
 set_long(
 "The " +blah+ " is a menacing creature.  It is capable of taking any\n"+
 "form, but generally looks like an elephant.  This one stands about\n"+
 "forty-five inches to the shoulder.  It is waiting for Pooh bear to\n"+
 "walk by, so it can ambush him and his honey.\n");
 set_level(8);
 set_ac(7);
 set_wc(12);
 set_hp(100+random(51));
 set_dead_ob(this_object());
}
monster_died() {
 tell_room(environment(TO),"The "+blah+" falls over dead.  Behind it was a pile of coins.\n");
 coins = CO("/obj/money.c");
 coins->set_money(300+random(101));
 MO(coins, environment());
 return 1;
}
