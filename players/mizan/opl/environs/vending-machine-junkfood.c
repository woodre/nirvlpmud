/*****************************************************************************
 *      File:                   vending-machine-junkfood.c
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

    desc[0] = "A jelly donut.................................1,000 coins";
    desc[1] = "A food loaf...................................1,200 coins";
    desc[2] = "A hot garbage flavored energy bar.............1,800 coins";
    desc[3] = "A used diaper flavored energy bar.............1,800 coins";

    item[0] = HEALS + "jellydonut.c";
    item[1] = HEALS + "foodloaf.c";
    item[2] = HEALS + "energybar_hotgarbage.c";
    item[3] = HEALS + "energybar_diaper.c";

    cost[0]=1000;
    cost[1]=1200;
    cost[2]=1800;
    cost[3]=1800;

    stock[0] = 15;
    stock[1] = 15;
    stock[2] = 20;
    stock[3] = 15;

    set_items_for_sale(4);

    set_name("Vending Machine");
    set_race("machine");
    set_short(HIW + "A magical snack vending machine" + NORM);
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
    load_chat("The machine says: I sell snacks and junk food!\n");
    load_chat("The machine smiles at you.\n");
    load_chat("The machine says: I am made in Japan.\n");
    load_chat("The machine says: You need a bank account to purchase stuff here.\n");
    load_chat("The machine says: I like food.\n");

    gold = clone_object("obj/money");
    gold->set_money(random(200)+800);
    move_object(gold,this_object());

}
