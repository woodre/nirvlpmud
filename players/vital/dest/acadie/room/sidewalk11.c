/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   2/18/01           */
/*    Realm:               */
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
The concrete sidewalk reaches the western side of massive structure \n\
and the fence continues as well. The other buildings are dwarfed \n\
next to the mighty structure. The sidewalk splits and heads of in \n\
three directions. The light blue sky overhead is accented with the \n\
presence of the high wispy clouds that move slowly by.\n ";

items = ({
    "concrete",
    "The cold, grey conglomeration of materials provide a solid surface to walk upon",
    "sidewalk",
    "The sidewalk splits and runs off toward the north, south, and west",
    "directions",
    "The sidewalk splits and runs off toward the north, south, and west",
    "side",
    "As you look at the massive structure, you see a large, garrish, commercial sign hanging high on the side of the structure",
    "fence",
    "The fence is about 3 meters high and stands about 4 meters away from the base of the structure. It is punctuated by the regular turnstile gates",
    "buildings",
    "The buildings are low, stone constructs that make up the town",
    "town",
    "The town is a collection of low buildings, all surrounding the large structure in the middle",
    "structure",
    "The structure is about 3 or 4 stories high and curves around to the north and south",
    "sky",
    "The sky is a pale "+CYN+"blue"+NORM+" and has several small, ribbon shaped clouds strung across it",
    "clouds",
    "The clouds are thin, sparse and stretched out in long lines"
});

dest_dir = ({
    ACADIE+"room/sidewalk9.c","north",
    ACADIE+"room/sidewalk13.c","south",
    ACADIE+"room/sidewalk17.c","west"
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
