inherit "/players/mizan/core/monster.c";
#include "/players/mizan/closed/RandomMove.c"

reset(arg) 
{
    object weapon,treasure;
    ::reset(arg);
    if(arg) return;
    set_name("A Great Wooly Waterlemon");
    set_race("waterlemon");
    set_alias("waterlmn");
    set_short("A Great Wooly Waterlemon (wandering)");
    set_long("This is a big, yellow and green.... fruit.\n"+
           "Yes, a fruit. Big, wooly, and... angry.\n"+
           "...and big and... Yes... It's a fruit.\n");
    set_level(17);
    set_hp(400);
    set_al(-520);
    set_ac(18);
    set_wc(23);
    set_chance(12);
    set_spell_dam(30);
    set_spell_mess1("A Great Wooly Waterlemon bowls you over! Ouch!");
    set_spell_mess2("A Great Wooly Waterlemon klunks you in the head! Eep!");
    set_chat_chance(10);
    load_chat("A Great Wooly Waterlemon makes a deep rumbling sound.\n");
    load_chat("A Great Wooly Waterlemon burps rudely.\n");
    treasure=clone_object("players/mizan/etheriel/items/spuck-sg.c");
    move_object(clone_object("players/mizan/etheriel/items/spuckballs-ext3"), treasure);
    move_object(treasure, this_object());
    weapon=clone_object("players/mizan/closed/random-item.c");
    move_object(weapon, this_object());
}
