/*****************************************************************************
 *      File:                   cock_unblocker.c
 *      Function:               An expensive item which temporarily disables
 *                              monsters from blocking exits. Limited charges.
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:
 *      Change History:
 ****************************************************************************/

inherit "/players/mizan/core/object.c";
#include "/obj/ansi.h"
int charges;

reset(arg)
{
    ::reset(arg);
    if(arg) return;

    charges = 10;

    set_get(1);
    set_value(10);
    set_weight(2);
    
    set_name("unblocker");
    set_alias("tube");
    set_short("A tube of " + HIM + "Cock Unblocker" + NORM);
    set_long("    This heavy plastic tube filled with some sort of magical ointment.\n"+
            "  Most of the text is written in a language that you cannot comprehend.\n"+
            "  The label depicts a giant rooster, being lubricated with what appears\n"+
	    "  with a shower of Bulgarian suntan lotion. The only part of the package\n"+
            "  that has English that makes any sense is written as follows:\n\n" +
            "    FOR USE: TO LUBRICATION OF COCKS BLOCKING PATHWAYS\n"+
            "    FACING COCK GRASP TUBE FIRMLY JIGGLE 'spray lubricant' ON CROWD\n"+
            "    COCKS WILL BE PRESENTLY, RESPECTFULLY SMOOTHENED ATTITUDE\n"+
            "    DURATION OF ACHIEVED TEN MINUTES IN LUBRICATED FOLLOWING WHICH\n"+
            "    RETURN TO COCK BLOCKING MANNERISMS.\n");


    set_smell("This tube smells like a Turkish cathouse, with extra Freddy Mercury.\n");
    set_taste("No. NO NO NO NO NO. No. Don't do that.\n");
}

short() { return "A tube of " + HIM + "Cock Unblocker" + NORM + " *" + charges + "*"; }

init()
{
    add_action("spray","spray");
}

spray(string str)
{
    object ob, oc, room;
    string temp1, filename, result;

    room = environment(this_player());

    if(!str || str!= "lubricant") return 0;
    write("You open the cap and wave the tube about.\nLubricant goes all over the place!\n");
    this_player()->remote_say(this_player()->query_name() + " waves a tube wildly! Lubricant goes flying everywhere!\n");

    ob = first_inventory(room);

    /* uncockblocks everything in the room */
    while(ob)
    {
        oc = next_inventory(ob);
        filename = object_name(ob);

        if(living(ob))
        {
            result = call_other(ob, "unblock_exits_temporarily");
            if(result)
                tell_room(room, ob->query_name() + " seems to be affected by the lubricant.\n");
            else
                tell_room(room, ob->query_name() + " does not seem to appreciate the lubricant.\n");
        }
        ob = oc;
    }

    charges --;
    write("There are *" + charges + "* doses remaining.\n");

    if(charges < 1)
    {
        write("The tube is empty, so you simply toss it away. YOU LITTERBUG!\n");
        say(this_player()->query_name() + " tosses away an empty tube of lubricant.\n");
        this_player()->add_weight(-2);
        destruct(this_object());
    }

    return 1;
}

query_save_flag() { return 1; }
