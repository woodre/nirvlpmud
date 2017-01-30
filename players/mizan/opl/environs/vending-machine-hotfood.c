/*****************************************************************************
 *      File:                   vending-machine-hotfood.c
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
    object gold, stick;

    ::reset(arg);
    if (arg) return;

    desc[0] = "An insanely spicy bean burrito................1,000 coins";
    desc[1] = "An insanely spicy TURBO bean burrito..........1,500 coins";
    desc[2] = "A sack of hot nuts............................2,000 coins";
    desc[3] = "A wienernut...................................2,200 coins";
    desc[4] = "A Calcutta omelette...........................3,500 coins";

    item[0] = HEALS + "superburrito.c";
    item[1] = HEALS + "turboburrito.c";
    item[2] = HEALS + "hotnuts.c";
    item[3] = HEALS + "wienernut.c";
    item[4] = HEALS + "calomelette.c";

    cost[0]=1000;
    cost[1]=1500;
    cost[2]=2000;
    cost[3]=2200;
    cost[4]=3500;

    stock[0] = 15;
    stock[1] = 15;
    stock[2] = 20;
    stock[3] = 15;
    stock[4] = 4;

    set_items_for_sale(5);

    set_name("Vending Machine");
    set_race("machine");
    set_short(HIW + "A magical hot food vending machine" + NORM);
    set_long("This is a magical vending machine. Sure, you've seen lots of these..\n"+
             "It's alive, and when it notices you looking at it it, it says:\n"+
             "  'Type list for a list of items!'\n");
    set_level(15);
    set_hp(2000);
    set_al(1000);
    set_wc(2);
    set_ac(12);
    set_chance(100);
    set_spell_dam(30);
    set_spell_mess1("The machine launches a coin at you and hits you squarely in the head!");
    set_spell_mess2("The machine cries: What did I ever do to you??");
    set_chat_chance(10);

    load_chat("The machine makes a gurgling noise.\n");
    load_chat("The machine says: Howdy!\n");
    load_chat("The machine says: I sell hot food!\n");
    load_chat("The machine smiles at you.\n");
    load_chat("The machine says: I am made in Japan.\n");
    load_chat("The machine says: You need a bank account to purchase stuff here.\n");
    load_chat("The machine says: I like food.\n");

    gold = clone_object("obj/money");
    gold->set_money(random(200)+800);
    move_object(gold,this_object());
}
