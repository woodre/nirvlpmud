/*HUMBLE CORPS 2004*/
#include "../defs.h"
inherit "/obj/monster";

reset(arg) {
    ::reset(arg);
    if (!arg)  {
    object gold;
    gold = clone_object("obj/money");
    money=1800+random(1000);
    move_object(gold, this_object());
    move_object(clone_object("players/humble/area1/objs/lipstick.c"));
    move_object(clone_object("players/humble/area1/objs/nametag.c"));
    set_name("Alice");
    set_alt_name("alice");
    set_alias("alice");
    set_short(HIR+"Alice"+NORM);
    set_race("human");
    set_gender("female");
    set_long(
    "This is "+HIR+"Alice"+NORM+" . She is a large busty white woman\n"+
    "who appears to be in her late 40s.  She wears so much make-up it's\n"+
    "hard to differentiate her from J.P. Patches.  She seems to be worried\n"+
    "about something.\n");
    set_level(19);
    set_ac(16);
    set_wc(27+random(1));
    set_hp(445+random(5));
    set_chat_chance(6);
    load_chat(HIR+"Alice mutters:"+NORM+" OOOOooooohhhhh I'm so worried about my Chauncey.\n");
    load_chat(HIR+"Alice screams:"+NORM+" Alright you cocksucker!\n");
    load_chat(HIR+"Alice rants:"+NORM+" We're striking cause those motherfuckers at Corporate only make a  quarter million now instead of half a million a year! Greedy Cocksuckers!\n");
    set_chance(25);
    set_spell_dam(35);
    set_spell_mess1(
    HIR+"Alice"+NORM+" bites her opponent incredibly hard!\n"+
    HIM+"           ?!?OUCH?!?\n"+NORM);
    set_spell_mess2(
    HIR+" Alice"+NORM+" waddles towards you and...\n"+
    RED+"       C  H  O  M  P  S\n"+NORM+
    "into your arm, piercing your skin.\n");
}
}
