/*****************************************************************************
 *      File:                   lava.c
 *      Function:               Where there is a lava icon in the maze...
 *                              There is one of these...
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:
 *      Change History:         DONE Initial revision - 09 Mar 2011
 ****************************************************************************/

inherit "/players/mizan/core/object.c";
#include "/obj/ansi.h"

string emotes;

reset(arg)
{
    ::reset(arg);
    if (arg) return;

    set_name("lava");
    set_weight(10000);
    set_save_flag(1);
    set_alias("pool");

    set_short(HBRED + HIK + "A pool of molten lava" + NORM);
    set_long(
        "    This is a lake of molten lava. It is hot, and it can kill you.\n" +
        "  Now that we got that out of the way, let's also make it perfectly\n" +
        "  clear that fishing in this lake is expressly prohibited by management.\n");

    emotes = ( {
        "The lava gives off a sickenly hot wave of heat.\n",
        "Gloop. Gloop. This is what liquid rock looks like.\n",
 	"Gurgle. Blub.\n",
        "Perhaps being so close to the lava is not a good idea.\n",
    });

}

init()
{
    remove_call_out("fake_beat");
    call_out("fake_beat", 2);
}

fake_beat()
{
    object ob, oc;
    object poison;
    object room;
    int found_someone;

    found_someone = 0;

    room = environment(this_object());
    if(!room) return;

    ob = first_inventory(room);

    while(ob)
    {
        oc = next_inventory(ob);

        if (ob &&
	    living(ob) &&
	    interactive(ob) &&
            ob->is_player() &&
            ob->query_level() < 21)
        {
            tell_object(ob, HBRED + HIK + "The heat from the lava HURTS!" + NORM + "\n");
            ob->hit_player(50 + random(40), "fire");
            found_someone = 1;
        }

        ob = oc;
    }

    if (1 == random(10))
        tell_room(room, emotes[random(sizeof(emotes))]);

    remove_call_out("fake_beat");
    if(found_someone) call_out("fake_beat", 2);
}

get() {
    return 0;
}
