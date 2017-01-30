/*HUMBLE CORPS 2004*/
#include "../defs.h"
inherit "/obj/monster";
reset(arg) {
    ::reset(arg);
    if (!arg)  {
    money=2500+random(2000);
    move_object(clone_object("/players/humble/area1/objs/nametag1.c"));
    init_command("wear nametag");
    move_object(clone_object("/players/humble/area1/objs/canoftuna.c"));
    set_name(HIC+"Ryan"+NORM);
    set_alt_name("ryan");
    set_alias("ryan");
    set_short(HIC+"Ryan"+NORM);
    set_race("human");
    set_long(
    "This is Ryan, he is a young man who looks to be about 20 at most.\n"+
    "He is a short chubby little fellar and he is responsible for assisting\n"+
    "the Seafood Manager.  He dons rubber gloves and is carrying\n"+
    "a bucket of ice.\n");
    set_gender("male");
set_level(19);
    set_ac(22);
    set_wc(24);
    set_hp(600+random(150));
    set_al(350);
    set_chat_chance(4);
    load_chat(HIW+"Ryan stares out into space.\n"+NORM);
    load_chat(HIW+"Ryan mutters to himself:"+HIC+" I gotta get some dope tonight.\n"+NORM);
    set_chance(20);
    set_spell_dam(30+random(15));
    set_spell_mess1(
    HIC+"Ryan"+NORM+" takes off his rubber gloves and slaps you with them.\n");
    set_spell_mess2(
    "\n slaps this player with his gloves.\n");
  }
}
