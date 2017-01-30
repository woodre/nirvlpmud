/*HUMBLE CORPS 2004*/
#include "../defs.h"
inherit "/obj/monster";
reset(arg) {
    ::reset(arg);
    if (!arg)  {
    money=5000+random(2000);
    move_object(clone_object("/players/humble/area1/objs/nametag3.c"));
    init_command("wear nametag");
    move_object(clone_object("/players/humble/area1/objs/apron2.c"));
    init_command("wear apron");
    set_name("Debbie");
    set_alt_name("debbie");
    set_alias("debbie");
    set_short(GRN+"Debbie"+NORM);
    set_race("human");
    set_long(
    "Debbie is a short girl with an enormous ass.  Her ass is so huge she\n"+
    "waddles when she walks.  Not only is it wide but it sticks out so much.\n"+
    "She seems like a very nice girl, she seems to hardly notice you.\n");
    set_gender("female");
    set_level(20);
    set_wc(34+random(6));
    set_ac(23+random(2));
    set_hp(999+random(101));
    set_chat_chance(6);
    load_chat(HIW+"Debbie shuffles about picking through items and scanning them.\n"+NORM);
    load_chat(HIW+"Debbie shouts out:"+NORM+" Oh that Gary, always messing stuff up\n");
    set_chance(15);
    set_spell_type("other|good");
    set_spell_dam(50);
    set_spell_mess1(
    GRN+"Debbie dumps an entire pallet of pepsi on you!\n"+NORM);
    set_spell_mess2(
    GRN+"Debbie dumps an entire pallet of pepsi on you!!\n"+NORM+
    HIY+"     $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"+NORM+
    HIY+"$$$$$$$$$$$$"+HIR+" ! S M A C K ! "+HIY+"$$$$$$$$$$$$$$\n"+NORM+
    HIY+"     $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"+NORM+
    GRN+"You stumble from the tremendous blow.\n"+NORM);
  }
}
stop() {
    if(this_player()->query_level() >1) {
    write(GRN+"Debbie throws you to the ground!\n"+NORM+
    GRN+" Debbie screams:"+NORM+" WHAT THE HELL ARE YOU DOING!?\n");
    return 1;
    }

    return 0;
}
init() {
  ::init();
    add_action("stop", "open");
    add_action("stop","enter");
  }
