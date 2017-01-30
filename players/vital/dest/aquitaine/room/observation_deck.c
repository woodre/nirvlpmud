/*
 *  observation_deck.c
 *  Nirvana Development
 *
 *  Created by Vital on Sat Feb 15 2003.
 *  Copyright (c) 2002 by VitalCode.
 *  All rights reserved.
 */

#include "/players/vital/closed/headers/vital.h" /* universal header */
#include "/players/vital/closed/headers/ansi.h" /* color header */
#include "/players/vital/closed/headers/room.h" /* room header */

inherit "/room/room.c";

void reset(arg)
{
    ::reset(arg);
    if(arg) return;
    set_light(0);
    set_short("Observation Deck");
    set_long("  The observation deck of the "+CYN+"Aquitaine"+NORM+" spaceport /nextends out to the southwest and overlooks the landing pad. There /nare tall, wide windows set into the walls allowing a full view of every /nincoming and leaving shuttle. The rooms appears bright, although there is /nno visible source of lighting. The benches here reflect the seamless styling seen /nelsewhere in the "+CYN+"Aquitaine"+NORM+" spaceport. People come here to see /noff their loved ones and await the arrival of friends, family and /nbusiness contacts.\n");
    set_info("In spite of the apparent lack of security, this spaceport /nis monitored tightly and any infraction of the law is dealt with seriously.\n");
    set_items({ /* "item name", "item description" */
        "deck",
        "The Observation deck is immaculately spotless beneath you",
        "spaceport",
        "The spaceport landing pad extends out to the southwest with shuttles /ncoming and going at regular intervals",
        "pad",
        "The spaceport landing pad extends out to the southwest with shuttles /ncoming and going at regular intervals",
        "windows",
        "There are three windows, each 3 meters tall and about 5 meters wide. /nEach window is seamlessly mounted into the wall. They additionally \noffer protection in the event of an accident out on the landing pad"
    });
    set_directions({ /* exit path, exit direction */
        AQUITAINE+"office.c","down",
    });
}

void init() /* add actions here */
{
    ::init();
    add_action("search_me","search");
}

search_me(str) {
    string adverb;
    if(!str) {
        notify_fail("What are trying to search?\n");
        return 0;
    }
    get_search_adverb();
    write("You "+adverb+" search the "+str+" but find nothing.\n");
    return 1;
}

