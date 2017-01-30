/*****************************************************************************
 *      File:                   vending-machine.c
 *      Function:               The main accessory vending machine of the maze
 *                              There is only one copy.
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


    desc[0] = "Wookiee Translator (Version 2)...............75,000 coins";
    desc[1] = "A green scarf...............................100,000 coins";
    desc[2] = "A key fob remote............................100,000 coins";
    desc[3] = "A bottle of rotting meat perfume............100,000 coins";
    desc[4] = "A tube of Cock Unblocker....................100,000 coins";
    desc[5] = "A patriotic lapel pin.......................150,000 coins";
    desc[6] = "A bag of MEGA SAND..........................150,000 coins";
    desc[7] = "A brown key fob remote......................150,000 coins";

    item[0] = ITEMS+"wookie-translator.c";
    item[1] = ITEMS+"goblin-scarf.c";
    item[2] = ITEMS+"autocannon-remote.c";
    item[3] = ITEMS+"zombie-perfume.c";
    item[4] = ITEMS+"cock_unblocker.c";
    item[5] = ITEMS+"usa-lapel-pin.c";
    item[6] = ITEMS+"mega_sand_bag.c";
    item[7] = ITEMS+"volcanogun-remote.c";

    cost[0]=75000;
    cost[1]=100000;
    cost[2]=100000;
    cost[3]=100000;
    cost[4]=100000;
    cost[5]=150000;
    cost[6]=150000;
    cost[7]=150000;

    stock[0] = 3;
    stock[1] = 2;
    stock[2] = 2;
    stock[3] = 2;
    stock[4] = 10;
    stock[5] = 2;
    stock[6] = 5;
    stock[7] = 3;

    set_items_for_sale(8);

    set_name("Vending Machine");
    set_race("machine");
    set_short("A magical vending machine");
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
    load_chat("The machine says: I sell useful stuff to help you in the maze!\n");
    load_chat("The machine smiles at you.\n");
    load_chat("The machine says: My prices aren't cheap, but protection is never cheap!\n");
    load_chat("The machine says: You need a bank account to purchase stuff here.\n");
    load_chat("The machine says: I like food.\n");

    gold = clone_object("obj/money");
    gold->set_money(random(200)+800);
    move_object(gold,this_object());
}

