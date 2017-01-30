/*
 * The purpose of this object is to house basic functionality used by the smart monsters.
 * Contents personal copyright Mizan@Nirvana, 2003.
 * Exclusive rights also to Boltar@Nirvana.
 * Reproduction on other muds restricted, under penalty of personal retribution.
 *
 */

#define IS_WAYPOINT_DM
#include "../../definitions.h"
#include "definitions.h"
#include "router.h"
#include "/obj/ansi.h"

/* 
 * 27 dec 2003 new change - we can do multiple waypoints for each castle now.
 */

/* member variables */
string my_waypoints;    /* contains a base point for the critters to start from in a pillagecastle order */

id(str) { return str == "waypoint-daemon" || str == "server"; }

short() { return "A network server named (waypoint-daemon)"; }


reset(arg)
{
    if(arg) return;

    move_object(this_object(), DAEMON_HOME);

    report_message("System online. Function reset(" + arg + ") called.\n");


    my_waypoints = ({

        ({ "arrina",
           "/players/arrina/tunnel/tunnel3.c"
        }),

        ({ "boltar",
           "/players/boltar/lv2/level2room2.c",
        }),


        ({ "catacomb",
           "/players/catacomb/barbtribe/brooms/barbentrance.c",
        }),

        ({ "catt",
           "/players/catt/AREAS/TEMPLE/monkroom1.c",
        }),

        ({ "catwoman",
           "/players/catwoman/city/19.c",
        }),

        ({ "coldwind",
           "/players/coldwind/desert/rooms/ma7.c",
        }),

        ({ "deathmonger",
           "/players/deathmonger/main6.c",
        }),

        ({ "dragnar",
           "/players/dragnar/WasteLands/rooms/entrance.c",
           "/players/dragnar/WasteLands/rooms/forest.c",
           "/players/dragnar/WasteLands/rooms/path1.c",
        }),

        ({ "earwax",
           "/players/earwax/area/fields/room/road2.c",
           "/players/earwax/area/fields/room/road1.c",
           "/players/earwax/area/fields/room/shack_entrance.c",
        }),

        ({ "emerson",
           "/players/emerson/rooms/dine1.c",
        }),


        ({ "fakir",
           "/players/fakir/woods/room27.c",
        }),

/*
        ({ "forbin",
           "/players/forbin/gov_complex/RMS/gc04.c",
        }),
*/

        ({ "francesco",
           "/players/francesco/kale/rooms/kale49.c",
        }),

        ({ "fred",
           "/players/fred/forest/Rooms/vill_1.c",
        }),

        ({ "gowron",
           "/players/gowron/room/road4.c",
        }),

        ({ "hawkeye",
           "/players/hawkeye/room/newent.c",
        }),

        ({ "hurtbrain",
           "/players/hurtbrain/castello/dag/dag10.c",
        }),


        ({ "jara",
           "/players/jara/area1/docks/room/wrhs3.c",
        }),

        ({ "jaraxle",
           "/players/jaraxle/closed/phoenix/rooms/floor1a.c",
        }),


        ({ "jareel",
           "/players/jareel/areas/chaos/forest6.c",
           "/players/jareel/areas/chaos/forest2.c",
           "/players/jareel/areas/entrance_area/grass_plain_8",
        }),


        ({ "lew",
           "/players/lew/37th_state.c",
        }),

   ({ "llew",
      "/players/llew/closed/crystal/crys1.c",
      }),

        ({ "maledicta",
           "/players/maledicta/cont/rooms/491.c",
        }),

        ({ "mizan",
           "/players/mizan/etheriel/subrealms/watchlar/k7.c",
           "/players/mizan/etheriel/subrealms/watchlar/k10.c",
           "/players/mizan/etheriel/subrealms/watchlar/k3.c",
           "/players/mizan/etheriel/ROOMS/duk.c",
        }),

        ({ "morgoth",
           "/players/morgoth/CASTLE/entrance.c",
        }),

        ({ "mythos",
           "/players/mythos/closed/guild/forest/rooms/hunter.c",
        }),

        ({ "nightshade",
           "/players/nightshade/room/c13.c",
        }),

        ({ "pain",
           "/players/pain/NEW/square.c",
        }),

        ({ "pathfinder",
           "/players/pathfinder/detroit/rooms/city1.c",
        }),

        ({ "pestilence",
           "/players/pestilence/amity/room/nmain1.c",
        }),

        ({ "saber",
           "/players/saber/ryllian/hero2",
        }),

        ({ "scathe",
           "/players/scathe/cave/monk3.c",
           "/players/scathe/cave/cavex1.c",
           "/players/scathe/cave/caved3.c",
           "/players/scathe/cave/monk12.c",
           "/players/scathe/cave/monk16.c",
        }),

/*
        ({ "snow",
           "/players/snow/shadows/cata/cata2.c",
        }),
*/

        ({ "softly",
           "/players/softly/point/rooms/for10.c",
        }),

        ({ "traff",
           "/players/traff/delnoch/town/dmain.c",
        }),

        ({ "trix",
           "/players/trix/castle/primo/nave5.c",
           "/players/trix/castle/disco/in4.c",
           "/players/trix/castle/disco/grid13.c",
           "/players/trix/castle/primo/raisle16.c",
           "/players/trix/castle/primo/eroom22.c",
           "/players/trix/castle/town/bank2.c",
        }),

        ({ "wizardchild",
           "/players/wizardchild/darkwood/rooms/path2.c",
        }),

        ({ "zone",
           "/players/zone/rooms/goblin.c",
        }),
    });

    /*
        "beck",
        "/players/beck/room/park8.c",
     */

}

/* returns a waypoint that can use */
get_castle_waypoint(arg)
{
    int i;
    int j;
    string subsection;
    
    if(!arg) return "/room/wild1.c";

    for(i = 0; i < sizeof(my_waypoints); i ++)
    {
        subsection = my_waypoints[i];
        j = sizeof(subsection) - 1;

        if(subsection[0] == arg)
        {
            return subsection[random(j) + 1];
        }
    }

    return 0;
}


/* returns a random castle that we can pillage */
get_random_castle()
{
    string temp;
    int i;

  if(!my_waypoints) reset(0);
    i = random(sizeof(my_waypoints));

    temp = my_waypoints[i];
    /* the first string in the subsection is the castle creator name */
    return temp[0];
}


/* simply tests if the string we are being sent matches a castle we know of */
match_castle(arg)
{
    string temp;
    int i;
    
    if(!arg) return 0;

    for(i = 0; i < sizeof(my_waypoints); i ++)
    {
        temp = my_waypoints[i];
        if(temp[0] == arg) return 1;
    }
    return 0;
}


/* used internally... */
report_message(arg)
{
    object ob;
    object room;
    string message;
    int i;

    message = HIY + ">> " + HIR + "*" + HIY + "System.waypoint" + NORM + NORM + " reports: " + arg;

    ob = users();

    for(i = 0; i < sizeof(ob); i ++)
    {
        if(present(RADIO_ID, ob[i]))
            tell_object(ob[i], message);
    }
    tell_room(LISTENING_ROOM, message);

}
/* eof */
