inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("al bundy");
    set_alt_name("al");
set_alias("bundy");
   set_race("human");
    set_al(215);
    set_level(20);
    set_aggressive(1);
    set_hp(1110);
MOCO("/players/jenny/bundy/items/card.c"),this_object());
MOCO("/players/jenny/bundy/items/shoelights.c"),this_object());
init_command("wear shoes");
    set_ac(21);
   set_ac_bonus(2);
    set_wc(37);
   set_wc_bonus(15);
    set_gender("male");
    set_short(""+CYN+"Al Bundy"+NORM+"");
    set_long(
      "Al Bundy is a pathetic looking man.  At the prime of his life,\n"+
      "he was a star fullback in High School.  He could have had\n"+
     "a good football career, but married an evil redhead instead.\n"+
     "Now he sells shoes to earn a meager living.\n");
set_chat_chance(21);
    load_chat(""+RED+"Al Bundy says: "+NORM+" I played High School Football.  Scored 4 touchdowns in one game!"+NORM+"\n");
}
heart_beat(){
if(attacker_ob && random(100) < 18) {
if(!present(attacker_ob, environment())) return; /* added by Zeus */
say(RED+"Al takes off his shoes.\n"+
MEATN+" gags at the smell of Al's feet."+NORM+"\n");
MEAT->do_damage( ({ 40+random(50) }), ({ "other|poison" }) );
return 1;}

::heart_beat();
}
