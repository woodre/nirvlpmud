inherit "/players/mizan/core/monster.c";
#include "/obj/ansi.h"

string my_color;


reset(arg)
{
    object gold;
    ::reset(arg);
    if(arg) return;

    my_color = get_random_color();

    set_name(my_color + " sock");
    set_alias("sock");
    set_short("A " + my_color + " sock");
    set_long("This of all things... a sock. It is faceless, noiseless, and\n"+
    "seemingly filled with bitterness at having been lost or abandoned some\n"+
    "time ago. Plus, it is missing its made as it is only one item of what\n"+
    "was once a pair...\n");

    set_level(6);
    set_hp(100);
    set_al(200);
    set_wc(12);
    set_ac(3);
    set_chance(20);
    set_spell_dam(10);
    set_spell_mess1("A " + my_color + " sock tries to run away, but fails.");
    set_spell_mess2("A " + my_color + " appears to be absolutely terrified!");
    set_chat_chance(1);
    
    load_chat("A " + my_color + " sock rustles about aimlessly.\n");
    load_chat("A " + my_color + " sock falls back down the the ground.\n");
    load_chat("Strangely enough, you could read their emotions, and a " + my_color + " sock seems upset.\n");

    gold=clone_object("obj/money");
    gold->set_money(random(100)+150);
    move_object(gold,this_object());
}



get_random_color()
{
    int a;
    a = random(6);

    switch(a)
    {
    case 1:
        return HIR + "red" + ESC + "[0m"+ ESC + "[0m";
    case 2:
        return HIG + "green" + ESC + "[0m"+ ESC + "[0m";
    case 3:
        return HIB + "blue" + ESC + "[0m"+ ESC + "[0m";
    case 4:
        return HIY + "yellow" + ESC + "[0m"+ ESC + "[0m";
    case 5:
        return HIBLK + "black" + ESC + "[0m"+ ESC + "[0m";
    default:
        return HIW + "white" + ESC + "[0m"+ ESC + "[0m";
    }
}
