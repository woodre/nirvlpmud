/*****************************************************************************
 *      File:                   lemonade-stand.c
 *      Function:               There are several copies of this distributed
 *                              across the maze.
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:
 *      Change History:         DONE Initial revision - 09 Mar 2011
 ****************************************************************************/

#define HEALS "players/mizan/opl/heals/"
#define ITEMS "players/mizan/opl/items/"
inherit "/players/mizan/opl/core/vending-creature.c";
#include "/obj/ansi.h";


reset(arg) 
{

    ::reset(arg);
    if (arg) return;

    desc[0] = "Spicy Lemonade................................1,200 coins";
    desc[1] = "Hot Lemonade..................................1,000 coins";
    desc[2] = "Limonade Exotiques............................1,000 coins";
    desc[3] = "Soda - not Lemonade...........................2,000 coins";

    item[0] = HEALS + "baturine.c";
    item[1] = HEALS + "beaverpiss.c";
    item[2] = HEALS + "bacon_lemonade.c";
    item[3] = HEALS + "cloacacola.c";

    cost[0]=1200;
    cost[1]=1000;
    cost[2]=1000;
    cost[3]=2000;

    stock[0] = 5 + random(10);
    stock[1] = 5 + random(10);
    stock[2] = 5 + random(10);
    stock[3] = 5 + random(10);

    set_items_for_sale(4);

    set_name("Spuckball");
    set_race("spuckball");
    set_alias("stand");
    set_alt_name("lemonade stand");
    set_short(HIY + "A Spuckball lemonade stand" + NORM);
    set_long("This is a small, mobile cart with a Spuckball inside manning the console.\n"+
             "A large sign on the side reads: LEMONADE STAND. The Spuckball sees you\n"+
             "looking, and it says: 'Type list for a list of items!'\n");
    set_level(15);
    set_hp(2000);
    set_al(1000);
    set_wc(2);
    set_ac(12);
    set_chance(100);
    set_chat_chance(10);

    load_chat("The Spuckball says: Hello there, traveler!\n");
    load_chat("The Spuckball says: I sell lemonade!\n");
    load_chat("The Spuckball says: Lemonade is good!\n");
    load_chat("The Spuckball says: You need a bank account to purchase stuff here.\n");

}

