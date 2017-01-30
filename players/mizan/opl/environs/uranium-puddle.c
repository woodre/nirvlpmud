/*****************************************************************************
 *      File:                   uranium-puddle.c
 *      Function:               Hurts players who linger nearby too long.
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:
 *      Change History:
 ****************************************************************************/
inherit "/players/mizan/core/object.c";
#include "/obj/ansi.h"

string emotes;

reset(arg)
{
    ::reset(arg);
    if (arg) return;

    set_name("puddle");
    set_weight(10000);
    set_alias("uranium-238");
    add_alias("uranium");
    set_save_flag(1);

    set_short("A puddle of green liquid " + BBLK + HIG + "[RADIOACTIVE]" + NORM + NORM);
    set_long(
        "    This is a large puddle of green, glowing liquid. You stand here staring\n"+
        "  at it, and feel as if it is almost pulsating slightly. This is not a good\n"+
        "  sign. You are thinking at this point that it's probably not a good idea to\n" +
        "  be so close to the puddle. Getting away from it might be the best plan.\n");

    emotes = ( {
        "The puddle of green liquid gives off a soft, sickening glow.\n",
        "You almost feel as if heat is eminating from the green puddle.\n",
        "Perhaps being so close to the glowing green puddle is not a good idea.\n",
    });

    remove_call_out("fake_beat");
    call_out("fake_beat", 10);
}

fake_beat()
{
    object ob, oc;
    object poison;
    object room;
    
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
            poison = present("radiation-sickness", ob);
            if (!poison) move_object(clone_object("/players/mizan/opl/environs/uranium-238-sickness.c"), ob);
        }

        ob = oc;
    }

    if (1 == random(10))
        tell_room(room, emotes[random(sizeof(emotes))]);

    remove_call_out("fake_beat");
    call_out("fake_beat", 5 + random(10));
}

get() {
    return 0;
}
