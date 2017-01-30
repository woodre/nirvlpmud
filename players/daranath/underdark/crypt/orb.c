#define tp this_player()->query_name()
inherit "room/room";
#include <ansi.h>
#include "/players/saber/closed/esc.h"

reset(int arg){
  if(!arg){
    
    set_light(-1);
    short_desc= "Orb Chamber";
    long_desc=
      "The swirling mist is thickest in this area, about waist deep at\n"+
      "its deepest. The white marble walls in the small room here are\n"+
      "blackened with a layer of darkness, keeping the walls from\n"+
      "showing thier true form. The room itself is dominated by a glowing\n"+
      "orb floating in the center of the chamber.\n";

    items=({
      "marble", "The marble of the walls here looks as if it was lifted\n"+
                "from another area of the mountain and brought here. It\n"+
                "looks very out of place within this area",
      "dirt", "The dirt spills about the area, covering the white stone\n"+
              "floor and walls",
      "mist", "A light blue colored mist is flowing through the archway\n"+
              "to the east from here. It is cool to the touch",
      "darkness", "A mysterious layer of darkness covers the walls",
      "orb", "The floating orb within the room glows with the same erie\n"+
             "light blue glow the mist has. The mist itself seems to\n"+
             "originate from the orb, leading you to believe the orb\n"+
             "is the cause for the evil all about. The orb looks very\n"+
             "brittle, perhaps you could "+HIY+"<"+NORM+"shatter"+HIY+">"+NORM+" it",

      });

    dest_dir=({
      "/players/daranath/underdark/crypt/death.c","north",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search_room");
    add_action("shatter","shatter");
    }

    search(){
    write("It is impossible to search the area with the mist about.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

    shatter(){
    write("You reach out and grab the orb within your hand, a chill\n"+
          "running from the tips of your fingers to your shoulder.\n\n"+
          "Raising the orb overhead, you speak a soft word to your god\n"+
          "as you bring it down violently to the ground, shattering it\n"+
          "about the area.\n");
    say(tp +" reaches out and grabs the orb, taking it within one hand.\n"+
            "Whispering an unheard word, "+tp+" throws the orb to the\n"+
            "ground, shattering it about the area.\n");
    return 1;
    }
    



arate() { return "YES"; }
