/*HUMBLE CORPS 2004*/
#include "../defs.h"
int coins;

inherit "/obj/monster";

reset(arg) {
    object gold, keys;
    ::reset(arg);
    if (!arg)  {
       gold = clone_object("obj/money");
    money=3000+random(500);
       move_object(gold,this_object());
    move_object(clone_object("/players/humble/area1/objs/nametag3.c"));
    move_object(clone_object("/players/humble/area1/objs/apron1.c"));
    init_command("wear apron");
    init_command("wear nametag");
    set_name(HIB+"Billy"+NORM);
    set_alt_name("billy");
    set_alias("billy");
    set_short(HIB+"Billy"+NORM);
    set_race("human");
    set_long(
    "This is Billy.  She is the head checker and holds the keys\n"+
    "to all the tills as well as the safe.  She looks like a nice lady\n"+
    "in her early 50s.  She has a very shapely figure and a great smile.\n");
    set_gender("female");
    set_level(19);
    set_ac(16+random(1));
    set_wc(28);
    set_hp(700+random(50));
    set_hp(425+random(85));
    load_chat(HIW+"Billy speaks into a telephone"+NORM+" Beth, com line 1. Beth com line 1.\n");
    set_chance(15);
    set_spell_dam(20+random(35));
    set_spell_mess1(
    HIB+"Billy"+NORM+" smashes her opponent with a devestating blow!\n");
    set_spell_mess2(
    HIB+"Billy"+NORM+" glides across the floor and flies into the air and...\n"+NORM+
    "hits you with a "+HIM+"####DOUBLE-FISTED FIERCE PUNCH####\n"+NORM+
    "you reel back on your heels and begin to feel ill.\n");
    }
}
