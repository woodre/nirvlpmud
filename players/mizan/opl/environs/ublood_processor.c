/*****************************************************************************
 *      File:                   ublood_processor.c
 *      Function:               This thing will make me enemies.
 *                              Everything they say is in all capitals
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:
 *      Change History:         DONE Initial revision - 09 Mar 2011
 ****************************************************************************/

#include "/obj/ansi.h"
#define ITEM_COST 1000000

int is_inserted;
int is_busy;
int is_paid;

reset(arg)
{
    if(arg) return;

    is_inserted = 0;
    is_busy = 0;
    is_paid = 0;
}

id(str) { return str == "machine" || str == "processor"; }

short() { return HIW + "A Unicorn Blood Processor" + NORM + " (Model 318)"; }

long()
{
    object ob, oc;

    write(
      "    " + HIW + "Spuck Heavy Industries (Model 318) Unicorn Blood Processor\n" + NORM +
      "  This is a large, roughly cube-shaped enclosure about 5 feet in each\n"+
      "  dimension which has the explicit purpose of accepting Unicorn blood\n"+
      "  vials and processing them into some un-named, super-powered product\n"+
      "  which is capable of harnessing such normally untamed fairy special\n"+
      "  super-duper specialness. There are some instructions engraved on a\n"+
      "  stainless steel placard reading:\n\n"+
      HIW + "  UNICORN BLOOD PROCESSOR UNIT. COST IS 1,000,000 GOLD COINS.\n"+
      "  DUE TO THE NATURE OF THIS CONSUMABLE PRODUCT THERE WILL BE NO REFUNDS.\n" + NORM +
      "  1) 'Insert vial' one by one into machine.\n"+
      "  2) Make payment (funds are paid via Nirvana bank electronic transaction).\n"+
      "  3) Push button.\n"+
      "  4) Receive product.\n\n" +
      "  Also, you can 'reset chute' to unload anything if you make an error.\n\n");

    ob = first_inventory(this_object());

    if(ob) write("The processing chute contains:\n");
    else write("The processing chute is empty.\n");

    while(ob)
    {
        oc = next_inventory(ob);
        if(ob->short()) write(ob->short() + ".\n");
        ob = oc;
    }
}


init()
{
    add_action("on_insert", "insert");
    add_action("on_push", "push");
    add_action("on_make_payment", "make");
    add_action("on_reset", "reset");
}


on_reset(string arg)
{
    if(!arg || arg != "chute") return 0;

    if(is_busy)
    {
        write("The machine is busy right now. The processing chute is closed.\n");
        return 1;
    }

    write("You pull on the chute reset lever.\n");

    eject_inventory();

    return 1;
}


on_insert(string arg)
{
    object ob;
    if(!arg) return 0;

    if(is_busy)
    {
        write("The machine is busy right now. The processing chute is closed.\n");
        return 1;
    }

    ob = present(arg, this_player());
    if(!ob)
    {
	write("You don't have one of those.\n");
	return 1;
    }

    if(!ob->query_color() || !ob->id("vial") || creator(ob) != "mizan" || is_inserted)
    {
        write(ob->short() + " doesn't appear to fit into the machine.\n");
        return 1;
    }

    this_player()->add_weight(-(ob->query_weight()));
    move_object(ob, this_object());

    write("You put the " + ob->query_color() + " vial into the machine.\n");
    return 1;
}


on_push(string arg)
{
    object room;

    if(!arg || arg != "button") return 0;

    room = environment(this_object());

    if(!is_inserted || is_busy || !is_paid)
    {
        tell_room(room, this_player()->query_name() + " pushes the button.\n");
        write("Nothing happens.\n");
        return 1;
    }
    else
    {
        is_busy = 1;

        tell_room(room, this_player()->query_name() + " pushes the button.\n");
        tell_room(room, "The machine begins rumbling and some whirring noises can be heard.\n");

        remove_call_out("manufacture01");
        call_out("manufacture01", 6);
        return 1;
    }
}

manufacture01()
{
    object room;
    room = environment(this_object());

    if(room)
        tell_room(room, "The machine makes several popping noises, followed up with the\nsound of breaking glass vials.\n");

    remove_call_out("manufacture02");
    call_out("manufacture02", 6);
}

manufacture02()
{
    object room;
    room = environment(this_object());

    if(room)
        tell_room(room, "The machine makes sounds which make you think of baby pixies\nbeing ground up into a fine, sticky paste.\n");

    remove_call_out("manufacture03");
    call_out("manufacture03", 6);
}

manufacture03()
{
    object room;
    object result;

    room = environment(this_object());

    if(room)
        tell_room(room, "The machine makes a whirring 'shoosh' noise, and then abruptly goes quiet.\n");


    destruct_inventory();
    is_busy = 0;
    result = clone_object("/players/mizan/opl/items/ublood_product.c");

    move_object(result, this_object());
    eject_inventory();
    return 1;
}



on_make_payment(string arg)
{
    object room;

    if(!arg || arg != "payment") return 0;

    room = environment(this_object());

    if(is_paid)
    {
        write("The screen reads: Transaction is paid for already.\n");
        return 1;
    }

    if(!check_inventory())
    {
        write("The screen reads: PC LOAD LETTER.\n");
        return 1;
    }

    if((this_player()->query_bank_balance()) < ITEM_COST)
    {
        write("The screen reads: You don't have enough gold in your bank balance!\n");
        write("You currently have " + this_player()->query_bank_balance() + " coins in your account.\n");
        return 1;
    }

    this_player()->add_bank_balance(-ITEM_COST);

    write("You feed your account number into the machine, and it goes through.\n");
    tell_room(room, this_player()->query_name() + " makes an electronic payment through the machine.\n");

    is_paid = 1;
    return 1;
}


check_inventory()
{
    int has_cyan, has_yellow, has_black, has_magenta;
    object ob, oc;

    has_cyan = 0;
    has_yellow = 0;
    has_black = 0;
    has_magenta = 0;

    ob = first_inventory(this_object());

    while(ob)
    {
        oc = next_inventory(ob);

        if(ob->query_color() == "cyan") has_cyan = 1;
        if(ob->query_color() == "yellow") has_yellow = 1;
        if(ob->query_color() == "magenta") has_magenta = 1;
        if(ob->query_color() == "black") has_black = 1;

        ob = oc;
    }

    if(has_cyan && has_yellow && has_magenta && has_black)
    {
        is_inserted = 1;
        return 1;
    }
    else 
    {
        is_inserted = 0;
        return 0; 
    }
}


destruct_inventory()
{
    object ob, oc;
    ob = first_inventory(this_object());

    while(ob)
    {
        oc = next_inventory(ob);
        destruct(ob);
        ob = oc;
    }
    is_inserted = 0;
}


eject_inventory()
{
    object ob, oc;
    object room;

    room = environment(this_object());
    if(!room) return;

    tell_room(room, "The processing chute on the machine opens.\n");
    
    ob = first_inventory(this_object());
    if(!ob) tell_room(room, "Nothing falls out of the processing chute.\n");

    while(ob)
    {
        oc = next_inventory(ob);
        if(ob->short()) 
            tell_room(room, ob->short() + " falls out of the processing chute.\n");
        move_object(ob, room);
        ob = oc;
    }

    is_inserted = 0;
}

