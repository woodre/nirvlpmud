/*****************************************************************************
 *      File:                   gatekeeper.c
 *      Function:               A monster serving as a warning beacon to
 *                              people about to enter the maze and prevents
 *                              anyone less than level 19 from entering.
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:
 *      Change History:
 *      2/25/2012 - added a few more text messages (warnings about area)
 ****************************************************************************/
inherit "/players/mizan/opl/core/monster.c";
#include "/obj/ansi.h"

reset(arg)
{
    object suit, hat, tag, pitchfork;
    ::reset(arg);
    if (arg) return;
    set_name("Overpowerlord's Gatekeeper");
    set_race("devil");
    set_alias("gatekeeper");
    set_short(HBRED + HIW + "Overpowerlord's Gatekeeper" + NORM);
    set_long("    The character standing before you is a full four feet tall, including\n"+
             "  the garish, giant helmet he is wearing in the shape of a key- and that\n"+
             "  comprises half his height. He looks old, shrivelled, and feeble... but\n"+
             "  there is a sharp twinkle in his eye. He appears to size you up as you stand\n"+
             "  before him. " + HIR + "Your gut feeling tells you that this man despite his harmless\n"+
             "  appearances is not someone to be trifled with." + NORM + "\n");
    set_level(36);
    set_hp(540000);
    set_al(500);
    set_wc(650);
    set_ac(300);
    set_chat_chance(20);

    /* The difficulty of our monster. 0 is weak, 1 is easy, 2 is medium, 3 is hard, and 4 is special. */
    monster_difficulty_type = 4;

    load_chat(query_name() + " says: " + HIW + "I hope you are ready for the maze below! Level 19 +5 players only!" + NORM + "\n");
    load_chat(query_name() + " says: " + HIW + "Beware of large explosive items in the maze! They are hazardous and can KILL you!" + NORM + "\n");
    load_chat(query_name() + " says: " + HIW + "Please note that strong monsters congregate at intersections!" + NORM + "\n");
    load_chat(query_name() + " says: " + HIW + "Monsters fortify intersections, and prevent movement!" + NORM + "\n");
    load_chat(query_name() + " says: " + HIW + "Radioactive pools can harm you if you linger nearby too long!" + NORM + "\n");
    load_chat(query_name() + " says: " + HIW + "The movement map is dynamic, reflecting loaded rooms." + NORM + "\n");
    load_chat(query_name() + " says: " + HIW + "Please note that playerkilling is allowed within the maze!" + NORM + "\n");
    load_chat(query_name() + " says: " + HIW + "I am the Gatekeeper of the Maze and I bid you welcome!" + NORM + "\n");
    load_chat(query_name() + " says: " + HIW + "Teleportation is restricted, but follow is enabled here." + NORM + "\n");
    load_chat(query_name() + " says: " + HIW + "Please note that this is an unrestricted player killing area!" + NORM + "\n");
    load_chat(query_name() + " says: " + HIW + "The Tripod Card you have been given is also the bulletin board for the area." + NORM + "\n");
    load_chat(query_name() + " says: " + HIW + "This is a VERY LARGE maze! Expect to get lost if you are not mapping it!" + NORM + "\n");
    load_chat(query_name() + " says: " + HIW + "Make sure you are properly equipped! This is a VERY difficult area!" + NORM + "\n");
    load_chat(query_name() + " says: " + HIW + "Sometimes doors will appear in dead-ends. These can offer great rewards but also great hazards!" + NORM + "\n");
    load_chat(query_name() + " says: " + HIW + "It is recommended that you don't proceed into this realm alone!" + NORM + "\n");
    load_chat(query_name() + " says: " + HIW + "Vehicles can help you bypass some monsters without being trapped!" + NORM + "\n");
    load_chat(query_name() + " says: " + HIW + "Don't count on spawn points being in the same place! The maze reshuffles..." + NORM + "\n");

    if (!hat)
    {
        hat = clone_object("/players/mizan/opl/items/gatekeeper_hat.c");
        move_object(hat, this_object());
    }

    if (!suit)
    {
        suit = clone_object("/players/mizan/opl/items/gatekeeper_suit.c");
        move_object(suit, this_object());
    }

    if (!tag)
    {
        tag = clone_object("/players/mizan/opl/items/gatekeeper_tag.c");
        move_object(tag, this_object());
    }

    if (!pitchfork)
    {
        pitchfork = clone_object("/players/mizan/opl/items/gatekeeper_pitchfork.c");
        move_object(tag, this_object());
    }
}


init()
{
    /* gatekeeper also serves to keep monsters DOWN */
    if(this_player() && this_player()->is_maze_monster())
    {
        say(short() + " smacks " + this_player()->query_name() + " across the face!\n");
        say(short() + " says: Go back DOWN, you bastard! You're on the clock!\n");
        this_player()->move_player("down#/players/mizan/opl/CELLS/C118.c");
        return 1;
    }

    add_action("on_down", "down");
    add_action("on_down", "d");
    ::init();
}

on_down()
{
    object room;

    room = environment(this_object());

    if(room && this_player() && this_player()->query_level() < 19)
    {

        write(short() + " gently blocks you with his trident.\n");
        tell_room(room, short() + " says: I'm sorry, but " + this_player()->query_name() + " is too low level to enter the maze.\n");
        return 1;
    }
    else return 0;
}

/*
init()
{
    object guest;
    object room;
    object card;

    guest = this_player();
    if (guest)
    {
        room = environment(guest);
        if (room &&
                environment(this_object()) &&
                room == environment(this_object()) &&
                guest->is_player() &&
                !guest->query_invis())
        {
            if (!present("tripod_card", guest))
            {
                say(this_object()->query_name() + " hands " + guest->query_name() + " a tripod card.\n");
                card = clone_object("/players/mizan/opl/items/tripod_card.c");
                move_object(card, guest);

            }

        }
    }
    ::init();
}
*/
