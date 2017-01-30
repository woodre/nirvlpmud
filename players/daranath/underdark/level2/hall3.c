#include <ansi.h>
#include "/players/saber/closed/esc.h"
#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
    short_desc= "Hallway of Portals";
    long_desc=
      "A long dark grey granite hallway extends north and south from your\n"+
      "location. The ceiling looms overhead, about twelve feet above you.\n"+
      "The most striking aspect of this hallway is the pair of glowing\n"+
      "portals stand against the east and west walls of the hall. The\n"+
      "portal to the east glows with a yellow glow, while the one on the\n"+
      "western wall has a bright blue hue to it.\n";

    items=({
      "hallway", "The granite hallway extends to the north and south\n"+
                 "from here, a series of glowing portals against the\n"+
                 "eastern and western walls",
      "ceiling", "The ceiling overhead is about twelve feet off the floor",
      "portals", "The glowing portals rest against the eastern and\n"+
                 "western walls here. The portals appear to shimmer and\n"+
                 "shift when you look at them. Perhaps you could enter\n"+
                 "one of them",
      "glow", "The glow from the portals fills the hallway with light",
    });

    dest_dir=({
      "/players/daranath/underdark/level2/hall2.c","north",
      "/players/daranath/underdark/level2/hall_entry.c","south",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search_room");
    add_action("enter","enter");
    }

    search(){
    write("You find nothing about the hallway.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

    enter(str){string msg,path;
    if(!str) {
    msg == "Which color portal do you wish to enter?";
    if(str == "blue portal"){
    msg == "\n\nThe mist of the portal engulfs you as you step into it.\n"+
           "Emotions strike your body with a wave of force, washing over\n"+
           "you and filling your mind with thoughts of\n\n"+
           "      "+HIB+"ANGST"+NORM+"  \n\n"+
           "As your mind clears, you find yourself someplace else.\n";
    path == "/players/daranath/underdark/level2/angst.c";}
    if(str == "yellow portal"){
    msg == "\n\nThe mist of the portal engulfs you as you step into it.\n"+
           "Emotions strike your body with a wave of force, washing over\n"+ 
           "you and filling your mind with thoughts of\n\n"+
           "      "+HIY+"ENVY"+NORM+"  \n\n"+
           "As your mind clears, you find yourself someplace else.\n";
    path == "/players/daranath/underdark/level2/envy.c";}
    write(msg);
    say(tp +" disappears into a portal.\n");
    move_object(this_player, path);
     return 1;
    }



arate() { return "YES"; }
