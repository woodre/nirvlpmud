/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   7/16/01           */
/*    Realm:      Acadie            */
/************************************/

#include "/players/vital/closed/headers/vital.h"                    /*color header*/
#include "/players/vital/dest/include/dest.h"
#define  SIDEWALK random(37)
#define ALLEY random(16)

inherit "room/room";

object mob;

reset(arg) {
  if(!present("crew",TO)) {
    mob = CO(NPC+"padcrew.c");
    MO(mob,TO);
  remote_populate();
  }
  if(!arg) {
  set_light(1);
  short_desc = "The Acadie Landing Pad";
  long_desc =
  "  "+short_desc+".\nThis is a much smaller version of the N.U.T.S. \
Spaceport.\nThe air here is colder and thinner than normal. Breathing is \n\
laborious, but not impossible. The open sky over the landing pad \n\
is a light, cloudless blue. The concrete and asphalt pad here is \n\
mottled with cracks and crevices. The sound of shuttles crackling \n\
keeps you from thinking that absolutely nothing is going on here. \n\
To the north you see a small structure and to the rest of the \n\
directions, walls.\n";

items = ({
    "pad",
    "This is where the shuttles come to land and take off",
    "shuttles",
    "These are the interstellar commuter craft that can take you to your destination",
    "spaceport",
    "At some point, you must have traveled through the heart of the transitway system",
    "air",
    "You look up into the clear sky and faintly make out stars",
    "stars",
    "After careful consideration, you decide that you cannot see your home sun from this planet's surface",
    "sky",
    "You search the heavens for incomming shuttles",
    "concrete",
    "This loosely resembles the mixture of sand, quicklime and other particulate matter that you are used to seeing",
    "asphalt",
    "The black tarmac is covered again and again with cracks and crevises",
    "crack",
    "The cracks have been covered and recreated by the constant shuttle flights",
    "cracks",
    "The cracks have been covered and recreated by the constant shuttle flights",
    "crevise",
    "The crevises are the results of water falling as rain, freezing and expanding in cracks, pushing them farther apart",
    "crevise",
    "The crevises are the results of water falling as rain, freezing and expanding in cracks, pushing them farther apart",
    "north",
    "You turn to look north and see a smaller, dilapidated building that beckons to you",
    "structure",
    "You turn to look north and see a smaller, dilapidated building that beckons to you",
    "building",
    "You turn to look north and see a smaller, dilapidated building that beckons to you",
    "wall",
    "The four meter high wall circles the landing pad in every direction, except for the structure to the north",
    "walls",
    "The four meter high wall circles the landing pad in every direction, except for the structure to the north",
    "east",
    "The four meter high wall circles the landing pad in every direction, except for the structure to the north",
    "west",
    "The four meter high wall circles the landing pad in every direction, except for the structure to the north",
    "south",
    "The four meter high wall circles the landing pad in every direction, except for the structure to the north"
});

dest_dir = ({
    "/players/vital/dest/acadie/room/landingoffice.c","north"
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

remote_populate() {
  int x, y;
  x = SIDEWALK+1;
  y = ALLEY+1;
  if(!x) x = 1;
  if(!y) y = 1;
  if(!ENV(ACADIE+"npc/proc.c")) {
      MO(CO(ACADIE+"npc/proc.c"),ACADIE+"room/sidewalk"+x+".c");
  }
  if(!ENV(ACADIE+"npc/woman_driver.c")) {
      MO(CO(ACADIE+"npc/woman_driver.c"),ACADIE+"room/sidewalk"+x+".c");
  }
  if(!ENV(NPC+"shopkeep.c")) {
      MO(CO(NPC+"shopkeep.c"),ACADIE+"room/shop.c");
  }
  if(!ENV(NPC+"drunk.c")) {
    MO(CO(NPC+"drunk.c"),ACADIE+"room/alley"+y+".c");
    MO(CO(NPC+"drunk.c"),ACADIE+"room/alley"+y+".c");
  }
  if(!ENV(ACADIE+"npc/pimp.c")) {
    MO(CO(ACADIE+"npc/pimp.c"),ACADIE+"room/sidewalk"+x+".c");
  }
  return;
}
