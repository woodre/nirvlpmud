/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   2/18/01           */
/*    Realm:      Acadie            */
/************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"                    /*color header*/
#include "/players/vital/dest/include/dest.h"

inherit "room/room";

reset(arg) {
    if(!arg) { 
    set_light(1);
    short_desc = "Sidewalk";
    long_desc =
    "  The Sidewalk\n\
The concrete sidewalk splits off in three different directions. \n\
To the north and south it curves around the large structure to the \n\
west. To the east the sidewalk heads toward the edge of town. The \n\
buildings look especially short this close to the large structure. \n\
The fence is closer now and the turnstile gates are larger here. \n\
There is a large sign mounted on the side of the structure above \n\
and behind the gate.\n ";

items = ({
    "concrete",
    "The conglomeration of materials makes this pavement especially strong",
    "north",
    "The sidewalk curves off around the large structure to the west",
    "south",
    "The sidewalk curves off around the large structure to the west",
    "east",
    "The sidewalk heads off toward the edge of town between rows of buildings",
    "sidewalk",
    "The cold, "+BOLD+BLK+"grey"+NORM+", stone conglomeration provides an easy surface to travel upon. It travels off to the north, east and south",
    "structure",
    "This close, the structure towers over your head. It is a large colliseum or arena of some kind",
    "buildings",
    "These are low, "+BOLD+BLK+"grey"+NORM+", stone buildings and each one looks like the next one from the outside",
    "directions",
    "The sidewalk heads off in three different directions",
    "sign",
    "Perhaps if you tried to \'read\' the sign, you could learn what this large structure is here for",
    "fence",
    "This 3 meter high, metal fence stands about 4 meters from the base of the structure. There are large turnstile gates at regular intervals",
    "gates",
    "The gates are massive steel portals that are designed to allow pedestrian traffic to go only one direction. This gate is larger than the others in the fence that you have seen",
    "turnstile",
    "The gates are massive steel portals that are designed to allow pedestrian traffic to go only one direction. This gate is larger than the others in the fence that you have seen",
    "gate",
    "The gates are massive steel portals that are designed to allow pedestrian traffic to go only one direction. This gate is larger than the others in the fence that you have seen",
    "turnstiles",
    "The gates are massive steel portals that are designed to allow pedestrian traffic to go only one direction. This gate is larger than the others in the fence that you have seen"
});

dest_dir = ({
    ACADIE+"room/sidewalk8.c","north",
    ACADIE+"room/sidewalk12.c","south",
    ACADIE+"room/sidewalk18.c","east"
  });

  }
}

init() {
    ::init();
    add_action("search_me","search");
    add_action("read_me","read");
}

search_me(str) {
    if(!str) {
        notify_fail("What are trying to search?\n");
        return 0;
    }
    else write("You furiously search the "+str+" but find nothing.\n");
}

read_me(str) {
    if(!str) { notify_fail("What are you trying to read?\n"); return 0; }
    if(str != "sign") { return 0; }
write("                                                              \n");
write("                                               "+HIY+"IIIIII         \n");
write("  "+BLINK+HIC+"PPPPPP "+NORM+"                     "+BLINK+HIY+"GGGGGG             "+NORM+HIY+"II   "+HIC+"NN    NN"+NORM+"\n");
write("  "+BLINK+HIC+"PPPPPPP"+NORM+"          "+HIC+"NN    NN  "+BLINK+HIY+"GGGGGGGG            "+NORM+HIY+"II   "+HIC+"NNNN  NN"+NORM+"\n");
write("  "+BLINK+HIC+"PP   PP"+NORM+"  "+HIY+"EEEEEEE "+HIC+"NNNN  NN  "+BLINK+HIY+"GG    GG  "+NORM+HIC+"UU   UU   "+HIY+"II   "+HIC+"NN NN NN"+NORM+"\n");
write("  "+BLINK+HIC+"PPPPPPP"+NORM+"  "+HIY+"EEEEEE  "+HIC+"NN NN NN  "+BLINK+HIY+"GG        "+NORM+HIC+"UU   UU   "+HIY+"II   "+HIC+"NN  NNNN"+NORM+"\n");
write("  "+BLINK+HIC+"PPPPP  "+NORM+"  "+HIY+"EE      "+HIC+"NN  NNNN  "+BLINK+HIY+"GG   GGGG "+NORM+HIC+"UU   UU   "+HIY+"II   "+HIC+"NN    NN"+NORM+"\n");
write("  "+BLINK+HIC+"PP     "+NORM+"  "+HIY+"EEEE    "+HIC+"NN    NN  "+BLINK+HIY+"GG    GG  "+NORM+HIC+"UU   UU   "+HIY+"II   "+HIC+"NN    NN"+NORM+"\n");
write("  "+BLINK+HIC+"PP     "+NORM+"  "+HIY+"EEEEE   "+HIC+"NN    NN  "+BLINK+HIY+"GG    GG  "+NORM+HIC+"UU   UU   "+HIY+"II   "+HIC+"NN    NN"+NORM+"\n");
write("  "+BLINK+HIC+"PP     "+NORM+"  "+HIY+"EE      "+HIC+"NN    NN  "+BLINK+HIY+"GGGGGGG   "+NORM+HIC+"UU   UU "+HIY+"IIIIII "+HIC+"NN    NN"+NORM+"\n");
write("  "+BLINK+HIC+"PP     "+NORM+"  "+HIY+"EE      "+HIC+"NN    NN   "+BLINK+HIY+"GGGGG    "+NORM+HIC+"UU   UU        "+HIC+"NN    NN"+NORM+"\n");
write("           "+HIY+"EEEEEE  "+HIC+"NN    NN            "+HIC+"UUUUUUU                \n");
write("           "+HIY+"EEEEEEE "+NORM+"                     "+HIC+"UUUUU                 \n");
write("                                                              "+NORM+"\n");
write(" The Greatest Ring-Hockey Team on Planet Acadie\n");
    return 1;
}
