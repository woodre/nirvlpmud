/* Heavily inspired from
 * /players/wocket/turtleville/NPC/bartender.c
 */

inherit "/players/mizan/opl/core/monster.c";
#include "/obj/ansi.h"

reset(arg) 
{
    ::reset(arg);
    if (arg) return;
    set_short(GRN + "Shane" + NORM + " the barkeep");
    set_name("shane");
    set_alias("barkeep");
    set_alt_name("bartender");

    set_long("    Barrel-chested barkeep. That's what you think of when you see Shane.\n"+
             "  His best days in his previous career as a professional boxer are long\n"+
             "  behind him, but his general fitness, size, and that alert glint in his\n"+
             "  eye still would make him a tough man to beat even now.\n\n"+
             "  A few pictures hang behind him on the wall. One in particular catches\n"+
             "  your eye. Shane is cut and bloodied after a fight, but beaming like a\n"+
             "  dozen suns. Surrounded in a mob of ring entourage and press, he is\n"+
             "  wearing a championship belt. In the far corner of the photo you see a\n"+
             "  familiar face. A child who is no doubt the young Overpowerlord himself\n"+
             "  is clutching a meager bag of peanuts, cheering for his childhood hero.\n");

    set_level(26);
    set_hp(8500);
    set_wc(65);
    set_ac(55);
    add_money(5000 + random(1000));

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 4;

    set_chat_chance(3);
    load_chat(GRN + "Shane" + NORM + " smiles at you.\n");
    load_chat(GRN + "Shane" + NORM + " whistles happily and wipes down the bar.\n");
    load_chat(short() + " says: What can I get for you, my friend?\n");
    load_chat(short() + " nods solemnly.\n");
    load_chat(short() + " glances out the entrance way, and smiles.\n");
}


init() 
{
    ::init();
    add_action("on_buy","buy");
    add_action("on_buy","order");
}


on_buy(string str) 
{
    int COST,INTOX,HEAL,DRINK;
    switch (str) 
    {
    case "stout":
        COST = 1000;
        INTOX = 4;
        HEAL = 100;
        DRINK = "pint of stout";
        break;

    case "whisky":
    case "whiskey":
        COST = 3000;
        INTOX = 14;
        HEAL = 300;
        DRINK = "shot of Legends McFarlane whisky";
        break;

    case "cockpunch":
    case "punch":
        COST = 5000;
        INTOX = 22;
        HEAL = 600;
        DRINK = "swig of Firebreathing Cockpunch";
        break;

    default:
        notify_fail(short() + " says: What would you like to drink? We have stout, whisky, and cockpunch.\n");
        return 0;
    }

    if (this_player()->query_intoxination() > this_player()->query_level() + 3) 
    {
        write(short() + " says: It looks like you've had enough, friend.\n");
        return 1;
    }

    if (this_player()->query_money() < COST) 
    {
        write(short() + " says: We work on cash here. You seem to be short some.\n");
        return 1;
    }

    write(short() + " hands you a " + DRINK + ".\nYou chug it down in the blink of an eye!\n");

    this_player()->add_money(-COST);
    this_player()->heal_self(HEAL);

    call_other(this_player(),"drink_alcohol",INTOX);

    say(short() + " hands " + this_player()->query_name() + " a " + DRINK + ".\n", this_player());
    return 1;
}
