/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   1/4/01            */
/*    Realm:      Spaceport         */
/************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
#include "/players/vital/dest/include/spaceport.h"     /*area header */

inherit "room/room";

int rnd, i;

reset(arg)
{
  rnd = random(3);
  if(!present("human", this_object()))
  {
    for(i=0; i < rnd; i++)
    {
      human = CO(SPNPC+"human.c");
	    MO(human, TO);
    }
  }
  if(!arg)
  {
  set_light(1);
  short_desc = "The N.U.T.S. Security Gates";
  long_desc =
  "  \
The N.U.T.S. Security Gates.\n\
These are the security gates where people come to see their friends\n\
and relatives off. Directly in front of you is a large arched entry that\n\
leads into the transitway. To the immediate east and west is a waist-high\n\
counter where N.U.T.S. Security personnel check passengers, luggage and\n\
tickets before they can enter the transitway. A large display hangs from\n\
the ceiling to alert passengers to shuttle arrival and departure times.\n\
The N.U.T.S. concourse extends toward the southwest and southeast where\n\
tourists, adventurers, and regulars wait for shuttles.\n";

  items =
  ({
    "gates",
    "The gates are large, steel structures that are common throughout the\n\
spaceport. They look like they could withstand an attack or a shuttle\n\
"+RED+"explosion"+NORM,
    "structure",
    "Composite metallic alloys that protect passengers and personnel",
    "spaceport",
    "This is Nirvana Universal Transport Spaceport (N.U.T.S)",
    "people",
    "These are the ones who aren't going anywhere. Their lives will be all\n\
the more boring for staying",
    "friends",
    "Passengers and adventurers who will soon be travelling to other places.\n\
They all wear travelling clothes and some have luggage with them as well",
    "travellers",
    "Passengers and adventurers who will soon be travelling to other places.\n\
They all wear travelling clothes and some have luggage with them as well",
    "luggage",
    "These are the pieces and parcels that the travellers carry with them to\n\
their destinations",
    "relatives",
    "Passengers and adventurers who will soon be travelling to other places.\n\
They all wear travelling clothes and some have luggage with them as well",
    "entry",
    "This large, arched entry leads to the transitway. The entry stands about\n\
3 meters tall and as travellers pass through it you lose sight of them",
    "transitway",
    "The transitway sits in "+BOLD+BLK+"darkness"+NORM+". As travellers pass \
through the entry,\nthey immediately disappear",
    "counter",
    "A long waist-high counter composed of the same metallic alloys but painted\n\
in colors of "+RED+"red"+NORM+" and "+YEL+"yellow"+NORM,
    "alloy",
    "This composite metal appears everywhere. It is a swirl of "+BOLD+BLK+"grey\
"+NORM+" and "+HIW+"silver"+NORM+"\nand looks strong and supportive",
    "personnel",
    "These are the security people that protect the innocent travellers and\n\
enforce the laws in the N.U.T.S",
    "passengers",
    "Passengers and adventurers who will soon be travelling to other places.\n\
They all wear travelling clothes and some have luggage with them as well",
    "tickets",
    "The tickets used here are small, \'plass\' chits that store the travel\n\
iteneraries of travellers",
    "plass",
    "A common, slang term used for plastic/glass wafer-thin computers that come\n\
in all possible shapes and sizes",
    "display",
    "A very large, \'plass\' viewscreen that shows all the current and future\n\
shuttle arrivals and departures",
    "ceiling",
    "Made out of the same metallic alloy that you see everywhere, the ceiling\n\
supports a large display and is about 20 meters above you",
    "shuttle",
    "The standard rho-field transportation vessel used at the N.U.T.S. Their\n\
arrivals and departures are recorded on the display",
    "times",
    "The shuttles come and go according to a predefined and set schedule",
    "concourse",
    "The concourses are like small cities where just about anything can be\n\
obtained. Many travellers spend hours here waiting for shuttles",
    "tourists",
    "These are the ones who will soon be travelling to other destinations.\n\
They all wear travelling clothes and some have luggage with them as well",
    "adventurers",
    "These are the ones who will soon be travelling to other destinations.\n\
They all wear travelling clothes and some have luggage with them as well",
    "regulars",
    "These regulars make the N.U.T.S. the great place that it is. They work,\n\
play, and hang out here"
  });
  dest_dir =
  ({
    SPROOM+"econcourse.c","southeast",
    SPROOM+"wconcourse.c","southwest",
    SPROOM+"enter.c",     "entrance",
    "blank",              "transitway"
  });
  }
}

init()
{
  ::init();
  add_action("search_me","search");
  add_action("move_transitway","transitway");
}

search_me(str)
{
  switch(str)
  {
    case "display": 
        write("You see many shuttle arrivals and departures.\n");
        return 1;
        break;
    case "counter":
        write("You find a great way to get your hands slapped.\n");
        return 1;
        break;
    case "entry":
        write("The darkness of the entry seems to be a forcefield\
that offers protection\nin the case of emergencies.\n");
        return 1;
        break;
    default:
        write("You search randomly and randomly find nothing.\n");
        return 1;
  }
}

move_transitway(str)
{
  TP->move_player("transitway#"+SPROOM+"transitway.c");
  return 1;
}
