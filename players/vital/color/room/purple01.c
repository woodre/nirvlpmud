/*************************************************************/
/*  File:           purple01.c
/*  Function:       
/*  Author(s):      Vital@Nirvana
/*  Copyright:      Copyright (c) 2003 v-Dev Code Factory
/*                  All Rights Reserved.
/*  Source:         9/13/03
/*  Notes:          
/*  Change History: 9/18/03
/*************************************************************/

#include "/players/vital/closed/headers/vital.h"
#include <ansi.h>
#include "../color.h"
#include "/players/vital/closed/headers/sigils.h"

inherit "room/room";
inherit PROBABLE_EXITS;

string *temp, *open;

reset(arg) {
    if(!arg) { 
        set_light(1);
        short_desc = MAG+"A Purple Room"+NORM;
        long_desc =  BMAG+BLK+"\
  The floor is hidden by a thick, "+HIM+"purple"+NORM+BMAG+BLK+" mist \
that has a \nconsistency like that of pudding that makes movement \
difficult. \nThe walls glisten with pearlescent, "+HIM+"purple"+NORM+
BMAG+BLK+" drops of liquid. The \ndoors are regularly spaced on the \
four walls. Each wall has four \ndoorways, each with a strange sigil \
painted in contrasting "+NORM+BMAG+HIM+"magenta"+NORM+BMAG+BLK+" \n\
on the "+HIM+"purple"+NORM+BMAG+BLK+" doors. The ceiling is lost in \
the dark, "+HIM+"purple"+NORM+BMAG+BLK+" haze \nthat hangs in the air.\n";
        items = ({
            "room",
            "This is the same room you just entered",
            "walls",
            "The walls here are covered in drops of pearlescent, "+MAG+"purple"+NORM+" drops of poison.\n There are sixteen possible exits from this room",
            "wall",
            "The walls here are covered in drops of pearlescent, "+MAG+"purple"+NORM+" drops of poison.\nThere are four doors on each of the 4 walls",
            "floor",
            "The floor is hidden by a viscous, "+MAG+"purple"+NORM+" mist",
            "mist",
            "This is a viscous, "+MAG+"purple"+NORM+" mist that obscures the floor",
            "door",
            "There are several different doors here. In fact, there are \
sixteen \ndifferent doors here. Pick a color to look at",
            "drops",
            "The drops on the wall look extremely shiny and fluid",
            "liquid",
            "It looks like purple maple syrup",
            "sigil",
            "There is a sigil painted on every door",
            "sigils",
            "There is a sigil painted on every door",
            "paint",
            "The paint is various shades of purple that evoke odd emotions",
            "doors",
            "There are sixteen different doors to choose from. Pick a color to \
look at",
            "ceiling",
            "The ceiling must be up there somewhere, but it can't be seen",
            "haze",
            "The haze is a floating counter part to the purple mist that \
floats around \nthe ground",
            "mauve",
            mauve,
            "lilac",
            lilac,
            "lavender",
            lavender,
            "violet",
            violet,
            "plum",
            plum,
            "aubergine",
            aubergine,
            "wine",
            wine,
            "amethyst",
            amethyst,
            "indigo",
            indigo,
            "heliotrope",
            heliotrope,
            "perse",
            perse,
            "mulberry",
            mulberry,
            "magenta",
            magenta,
            "violaceous",
            violaceous,
            "orchid",
            orchid,
            "out",
            out,
        });
        dest_dir = ({"door_placeholder",NORM+MAG+"mauve"+NORM,
                     "door_placeholder",NORM+MAG+"lilac"+NORM,
                     "door_placeholder",NORM+MAG+"lavender"+NORM,
                     "door_placeholder",NORM+MAG+"violet"+NORM,
                     "door_placeholder",NORM+MAG+"plum"+NORM,
                     "door_placeholder",NORM+MAG+"aubergine"+NORM,
                     "door_placeholder",NORM+MAG+"wine"+NORM,
                     "door_placeholder",NORM+MAG+"amethyst"+NORM,
                     "door_placeholder",NORM+MAG+"indigo"+NORM,
                     "door_placeholder",NORM+MAG+"heliotrope"+NORM,
                     "door_placeholder",NORM+MAG+"perse"+NORM,
                     "door_placeholder",NORM+MAG+"mulberry"+NORM,
                     "door_placeholder",NORM+MAG+"magenta"+NORM,
                     "door_placeholder",NORM+MAG+"violaceous"+NORM,
                     "door_placeholder",NORM+MAG+"orchid"+NORM,
                     "door_placeholder",NORM+MAG+"out"+NORM,
        });
        temp = ({ });
        open = ({ });
    }
}

init() {
    ::init();
    add_action("search_me","search");
    add_action("a_door_me","mauve");
    add_action("a_door_me","lilac");
    add_action("a_door_me","violet");
    add_action("a_door_me","lavender");
    add_action("a_door_me","plum");
    add_action("a_door_me","aubergine");
    add_action("a_door_me","wine");
    add_action("a_door_me","amythyst");
    add_action("a_door_me","indigo");
    add_action("a_door_me","heliotrope");
    add_action("a_door_me","perse");
    add_action("a_door_me","mulberry");
    add_action("a_door_me","magenta");
    add_action("a_door_me","violaceous");
    add_action("a_door_me","orchid");
    add_action("a_door_me","out");
    selectomatic();
}

search_me(str) {
    if(!str) {
        notify_fail("What are trying to search?\n");
        return 0;
    }
    write("You furiously search the "+str+" but find nothing.\n");
    return 1;
}

random_exit();

a_door_me() {
    string door;
    door = query_verb();
    if(member_array(door, open)) {
        random_exit(door);
        return 1;
    }
    else
    notify_fail("Nope, the "+door+" door doesn't go anywhere right now...\n");
    return door;
}

selectomatic() {
    int x;
    if(!open) open = ({ });
    if(!temp) temp = ({ });
    for(x = 0; x < sizeof(dest_dir); x++) {
        x++;
        temp = temp + dest_dir[x];
    }
    for(x = 0; x < sizeof(temp); x++) open = random(2)?open+temp[x]:({ });
    return open;
}

