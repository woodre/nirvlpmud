#include "../defs.h"

inherit "/obj/monster";
int coins;
int knife;
reset(arg) {
    ::reset(arg);
    if (!arg)  {
    object gold, knife;
    gold = clone_object("obj/money");
    money= 4250+random(750);
    move_object(gold, this_object());
    move_object(clone_object("/players/humble/area1/objs/boxcutter.c"));
    init_command("wield boxcutter");
    set_name(HIW+"Tyler"+NORM);
    set_alt_name("tyler");
    set_alias("tyler");
    set_short(HIW+"Tyler"+NORM);
    set_race("human");
    set_gender("male");
    set_long(
    "This is "+HIW+"Tyler"+NORM+" . He is a good looking young man\n"+
    "who appears to be in his early 20s.  He is short and whines a lot.\n"+
    "You can tell by his body language he is irritated about something\n"+
    "or another, possibly the fact he is a closet homosexual or\n"+
    "maybe it's the fact he's a perfectionist. It wouldn't be a good idea\n"+
    "to attack this one if I was you.\n");
    set_level(22);
    set_spell_dam(45);
    set_ac(22);
    set_wc(30);
    set_hp(800+random(150));
    set_al(0);}
    set_chat_chance(10);
    load_chat(HIW+"Tyler tells you:"+NORM+" Fucking Fatboy doesn't do shit, I do EVERYTHING around here!\n");
    load_chat(HIW+"Tyler thinks out loud:"+NORM+" I go to church so I can cast my brother down in his sins.\n");
    load_chat(HIW+"Tyler mumbles:"+NORM+" Can you believe that stupid bitch Alice?\n");
    set_chance(25);
    set_spell_dam(25+random(20));
    set_spell_mess1(
    HIW+"Tyler hurls a case of freight at his opponent at lightning speed!\n"+NORM);
    set_spell_mess2(
    HIW+"Tyler picks up a box of freight and throws it at you!\n"+NORM+
    GRN+"     ?????????  B  O  I  N  K  ????????\n"+NORM);
    set_dead_ob(this_object());
}

    monster_died(ob) {
    object knife;

    write(HIW+"Tyler"+NORM+" falls against the aisle knocking over things as he over-dramatically dies.\n");
    tell_room(environment(),

    this_player()->query_name()+" smashes "+HIW+"Tyler"+NORM+" to the ground.\n",
        ({ this_player()})
);
}
