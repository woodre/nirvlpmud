/*HUMBLE CORPS 2004*/
#include "../defs.h"
inherit "/obj/monster";
reset(arg) {
    ::reset(arg);
    if (!arg)  {
    money=5000+random(3000);
    move_object(clone_object("/players/humble/area1/objs/boxcutter.c"));
    init_command("wield boxcutter");
    set_name(HIY+"Pavel"+NORM);
    set_alt_name("pavel");
    set_alias("pavel");
    set_short(HIY+"Pavel"+NORM);
    set_race("human");
    set_long(
    "This is Pavel.  He is one scary looking russian dood.  He is tall and skinny\n"+
    "but nevertheless he is intimidating.  He's throwing cans onto the\n"+
    "shelves at lightning speeds.\n");
    set_gender("male");
    set_level(20);
    set_ac(22+random(7));
    set_wc(35+random(8));
    set_hp(800+random(500));
    set_al(750);
    set_chance(18);
    set_spell_type("other|dark");
    set_spell_dam(40+random(10));
    set_spell_mess1(
    HIY+"Pavel spins in a cricle casting a"+HIM+" purple mist"+HIY+" about the room.\n"+NORM);
    set_spell_mess2(
    HIW+"Pavel twirls about in a mindless fashion\n"+NORM+
    MAG+" A purple cloud emits from behind Pavel encompassing the room.\n"+NORM+
    HIM+"            ()()()()()()()()()()()()()()()()()()()()()()            \n"+NORM+
    HIM+"        ()()()()()()()(@@@@@@)()()()()()()()      \n"+NORM+
    HIM+"        ()()()()()()()(@@@@@@)()()()()()()()      \n"+NORM+
    HIM+"        ()()()()()()()(@@@@@@)()()()()()()()      \n"+NORM+
    HIM+"        ()()()()()()()(@@@@@@)()()()()()()()      \n"+NORM+
    HIM+"            ()()()()()()()()()()()()()()()()()()()()()()            \n"+NORM);
    }
}
heart_beat() {
    ::heart_beat();
    if(attacker_ob) {
      already_fight=0;
    attack();
    already_fight=0;
      attack();
    }
}
