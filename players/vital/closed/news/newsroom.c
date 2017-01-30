/******************************************************************************
 *	File:			newsroom.c
 *	Function:		room with no windows, doors, or people
 *	Author(s):		Vital@Nirvana
 *	Copyright:		Copyright (c) 2003 v-Dev Code Factory
 *					All Rights Reserved.
 *	Source:			14/1/04
 *	Notes:			
 *	Change History:
 *****************************************************************************/

#include "/players/vital/closed/headers/vital.h"

inherit "room/room";

void
reset(status arg)
{
  if(!arg)
  { 
    set_light(1);
    short_desc = "The News Room";
    long_desc =  "\
  This is the Nirvana Newsroom. From here the words of the press are \n\
delivered to the eyes of the people. In the background is the constant \n\
chatter of teletype machines and the hum of typewriters. In the middle \n\
of the room are several desks with state-of-the-art computer work-\n\
stations at them and a large, network printer in the between them.\n";

    items = 
    ({
        "teletype",
        "These are the old-fashioned, news delivery machines.",
        "machines",
        "These are the old-fashioned, news delivery machines.",
        "teletype machines",
        "These are the old-fashioned, news delivery machines.",
        "typewriter",
        "This is some arcane, foul contraption.",
        "typewriters",
        "These are some arcane, foul contraptions that go Ding.",
        "desk",
        "A large, pressed-wood desk from IKEA.",
        "desks",
        "These are all look-a-like desks from the IKEA catalog.",
        "computer",
        "This is a modern, top-of-the-line desktop publishing machine.",
        "computers",
        "These are modern, top-of-the-line desktop publishing machines.",
        "workstation",
        "This is a modern, top-of-the-line desktop publishing machine.",
        "workstations",
        "These are modern, top-of-the-line desktop publishing machines.",
        "printer",
        "This is a DocuColor iGen3ª Digital Production Press from Xerox.",
        "network printer",
        "This is a DocuColor iGen3ª Digital Production Press from Xerox.",
        "between",
        "This is a DocuColor iGen3ª Digital Production Press from Xerox.",
    });
    
    dest_dir = 
    ({
    });
  }
}

int
search_me(string str)
{
    if(!str)
    {
        notify_fail("What are trying to search?\n");
        return 0;
    }
    write("You furiously search the "+str+" but find nothing.\n");
    return 1;
}

int
head_out()
{
    string destination;
    switch(random(10))
    {
        case 0:
            destination = "/room/vill_green.c";
            break;
        case 1:
            destination = "/room/orc_dump.c";
            break;
        case 2:
            destination = "/players/vital/dest/spaceport/rooms/bombbar.c";
            break;
        case 3:
            destination = "/room/ptroom.c";
            break;
        case 4:
            destination = "/room/big_tree.c";
            break;
        case 5:
            destination = "/players/earwax/area/fields/room/fields1.c";
            break;
        case 6:
            destination = "players/mizan/etheriel/ROOMS/eastwest.c";
            break;
        case 7:
            destination = "/players/cosmo/apt/rooms/elevator.c";
            break;
        case 8:
            destination = "/players/sandman/ASGARD/high_top.c";
            break;
        case 9:
            destination = 
                "/players/nooneelse/entryforest/e_marble_quarry_pit.c";
            break;
        default:
            destination = "/players/katya/area/esquire/r/concession.c";
            break;
    }
    this_player()->move_player(
        "suddenly through a mistake in the space-time continuum#"
        + destination);
    return 1;
}

void
init()
{
    ::init();
    add_action("search_me","search");
    add_action("head_out", "exit");
    add_action("head_out", "out");
    add_action("head_out", "leave");
}
