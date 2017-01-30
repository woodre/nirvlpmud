/*****************************************************************************
 *      File:                   autocannon-remote.c
 *      Function:               An expensive item which temporarily disables
 *                              the autocannon
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:
 *      Change History:
 ****************************************************************************/

inherit "/players/mizan/core/object.c";
#include "/obj/ansi.h"

reset(arg)
{
    ::reset(arg);
    if(arg) return;

    set_get(1);
    set_value(10);
    set_weight(1);
    
    set_name("remote");
    set_alias("fob");
    set_short("A plastic remote key fob");
    set_long("This is a black plastic key fob, with a single large button on it.\n"+
            "It does not seem to be used for car alarm/locks. There are no other\n"+
	    "markings on it aside from a very small label on the back in tiny print.\n"+
            "To use this device, it appears you need to 'activate remote'.\n");

    set_read("The label reads: 'Dactrol Corporation Autocannon EPO - All Rights Reserved 2144'.\n");
    set_smell("The remote smells like... industrial electronics.\n");
    set_taste("Don't do that. You look silly.\n");
}

init()
{
    add_action("activate","activate");
}

activate(string str)
{
    object ob, oc;
    string temp1, filename;

    if(!str || str!= "remote") return 0;
    write("You hold out the remote and push the button.\n");
    this_player()->remote_say(this_player()->query_name() + " holds out a small plastic remote and pushes its button.\n");

    ob = first_inventory(environment(this_player()));

    /* do this the long way in case there are multiple autocannons present */
    while(ob)
    {
        oc = next_inventory(ob);
        filename = object_name(ob);

        if(sscanf(filename, "players/mizan/opl/environs/autocannon%s", temp1) == 1 &&
           living(ob)) call_other(ob, "disable_autocannon");
        ob = oc;
    }
    return 1;
}

query_save_flag() { return 1; }
