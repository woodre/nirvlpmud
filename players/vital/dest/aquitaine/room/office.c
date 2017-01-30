/************************************
*    Owner:      Vital@Nirvana
*    Created:    10/5/01
*    Modified:   
*    Realm:      Aquitaine
************************************/

#include "/players/vital/closed/headers/vital.h"                 /*universal header*/
#include "/players/vital/dest/include/dest.h"

inherit "room/room";

reset(arg) {
  if(!arg) { 
  set_light(1);
  short_desc = CYN+"Aquitaine"+NORM+"Spaceport Office";
  long_desc ="\
  The room is an ultra-modern station. Every surface is clean and \n\
smooth. The walls, floors and ceilings meet without seams or even \n\
noticeable boundaries. The furniture is molded right out of the floor \n\
and also seamlessly made. There is a large security gate in the  \n\
southwest corner of the station that lead toward the landing pad. \n\
Against the north wall is a lift that goes up to the observation and \n\
departure lounge. To the east there is movement as people exit the \n\
Spaceport.\n ";

  items = ({
    "station",
    "The Aquitaine Spaceport Office is a very modern place",
    "surface",
    "The surfaces are a "+HIW+"light"+NORM+", "+BOLD+"grey"+NORM+" and polished to mirrored perfection",
    "walls",
    "The walls are shiny, mirrored and the edges are joined to the floor and \nceiling without seam",
    "wall",
    "There is no difference between the floor and the wall. \nBoth are made from the same material",
    "material",
    "The room and everything in it is made from the same type of shiny material",
    "floors",
    "The floors are shiny, mirrored and joins the walls without a seam",
    "floor",
    "As you look at the floor, you can see your reflection looking back up at you",
    "ceilings",
    "The ceiling is one great, shiny, mirrored surface that doesn't have any \nlights, but emits light none-the-less",
    "ceiling",
    "The ceiling is one great, shiny, mirrored surface that doesn't have any \nlights, but emits light none-the-less",
    "seams",
    "Everywhere the walls, ceiling and floor meet, there are no seams",
    "seam",
    "Everywhere the walls, ceiling and floor meet, there are no seams",
    "boundaries",
    "The walls, ceiling and floor flow from one into the other",
    "boundary",
    "The walls, ceiling and floor flow from one into the other",
    "furniture",
    "The furniture is made out of the same high-tech polymer found in the \nrest of the office",
    "gate",
    "description",
    "corner",
    "description",
    "pad",
    "description",
    "north",
    "description",
    "north wall",
    "description",
    "lift",
    "description",
    "up",
    "description",
    "lounge",
    "description"
  });

  dest_dir = ({
    AQUITAINE+"landing.c","pad",
    AQUITAINE+"room/lounge.c","up",
    AQUITAINE+"room/bus.c","outside"
  });

  }
}

init() {
    ::init();
    add_action("search_me","search");
}

search_me(str) {
    if(!str) {
        notify_fail("What are trying to search?\n");
        return 0;
    }
    else write("You furiously search the "+str+" but find nothing.\n");
}
