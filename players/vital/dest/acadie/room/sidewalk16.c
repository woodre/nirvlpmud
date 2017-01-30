/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   2/25/01           */
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
The concrete, sidewalk splits and heads off in three directions. \n\
The imposing structure to the north is surrounded by a large fence \n\
and there is a sign mounted on the side of the structure.  There \n\
is more vegetation here as the buildings thin out and the space to \n\
the east is composed of what could loosely be referred to as a park.\n ";

items = ({
    "park",
    "The small, brown vegetation and open space between buildings provides a \n\
sense of peace",
    "vegetation",
    "Dry, brown flora that manages to sustain life in the harsh environment here",
    "northeast",
    "The sidewalk curves off toward the northeast",
    "southwest",
    "The sidewalk curves off toward the southwest",
    "northwest",
    "This close, the structure towers over your head. It is a large colliseum \n\
or arena of some kind",
    "concrete",
    "The conglomeration of materials makes this pavement especially strong",
    "sidewalk",
    "The cold, "+BOLD+BLK+"grey"+NORM+", stone conglomeration provides an easy \n\
surface to travel upon. It travels off to the north, east and south",
    "structure",
    "This close, the structure towers over your head. It is a large colliseum \n\
or arena of some kind",
    "buildings",
    "These are low, "+BOLD+BLK+"grey"+NORM+", stone buildings and each one looks \n\
like the next one from the outside",
    "sign",
    "Perhaps if you \'read\' the sign you could learn more about this large structure",
    "fence",
    "This 3 meter high, metal fence stands about 4 meters from the base of the \n\
structure. There are large turnstile gates at regular intervals",
    "gates",
    "The gates are massive steel portals that are designed to allow pedestrian \n\
traffic to go only one direction. This gate is larger than the others in the \n\
fence that you have seen"
});

dest_dir = ({
    ACADIE+"room/sidewalk14.c","northeast",
    ACADIE+"room/sidewalk15.c","northwest",
    ACADIE+"room/sidewalk36.c","south"
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
