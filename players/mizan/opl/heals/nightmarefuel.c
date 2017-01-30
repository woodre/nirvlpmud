/*****************************************************************************
 *      File:                   nightmarefuel.c
 *      Function:               Heal with an evil twist
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 5/2011
 *      Notes:
 *      Change History:         DONE Initial revision - 06 May 2011
 ****************************************************************************/
inherit "/obj/generic_heal.c";
#include "/obj/ansi.h"
#include "/players/mizan/opl/definitions.h"

void reset(int arg)
{
    ::reset(arg);
    if (arg) return;
    set_name("fuel");
    add_alias("bottle");
    set_short("A bottle of " + HBRED + HIY + "NIGHTMARE FUEL" + NORM);
    set_long(
        "    Inside this jet-black bottle of fairly suspicious origins is a foul,\n"+
        "  caustic liquid which supposedly has amazing regenerative capabilities.\n"+
        "  Like any super-special heal, it should be consumed carefully because\n"+
        "  there are undoubtedly some pretty wicket side effects despite the gains.\n");

    set_type("drink");
    set_msg("You take a sip. Your head spins as you remember this wacky nightmare you\n" +
           "once had where you " + RANDOBJ_DM->get_nightmare() + ".\n");
    set_msg2(" sips down some " + HBRED + HIY + "NIGHTMARE FUEL" + NORM + ".\n");

    add_cmd("drink");
    set_heal(200,200);
    set_charges(4);
    set_intox(0);
    set_soak(10);
    set_value(400);
}

int cmd_imbibe(string str)
{
    int retval;
    object room;
    object nightmare;

    retval = ::cmd_imbibe(str);

    room = environment(this_player());
    if(retval && room && 1 == random(3))
    {
        tell_room(room, HIY + "A nightmare takes physical form from the bottle and attacks " + 
            this_player()->query_name() + "!" + NORM + "\n");

        nightmare = clone_object("/players/mizan/opl/beasties/rare/nightmare.c");
        move_object(nightmare, room);
        nightmare->attack_object(this_player());

    } 

    return 1;
}

conditions_check() 
{
    object room;
    /* The conditions_check() function can be used to check for conditions before applying
       the heal. Returning 0 from this function will cause the heal consumption to abort
       using the pre defined message given by notify_fail. If your heal doesn't have any
       condition check requirements then the function can be left out all together.
    */


    /* We don't allow this heal to be used except when in the maze area */
    room = environment(this_player());
    if (!room || !room->query_current_icon())
    {
        write("The fuel refuses to come out of the bottle, for some reason.\n");
        return 0;
    }
    else
        /* Continue healing if the conditions are satisfied */
        return 1;
}

