#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(-1);
    short_desc= "Signpost within the UnderDark";
    long_desc=
      "You stand at a crossroads within the darkened pathways that make\n"+
      "up the bulk of the UnderDark realm. The rocky walls are dark grey\n"+
      "and rough hewn. Grabbing your attention here is the large stone\n"+
      "signpost jutting out from the ground and rising up above you. The\n"+
      "natural tunnels leads from here in several directions.\n";

    items=({
      "tunnels", "The tunnels continue in all directions in the darkness",
      "walls", "The walls are rocky and rough hewn",
      "paths", "The paths follow the tunnels about the UnderDark",
      "signpost", "the stone signpost is the same dark grey color as the\n"+
                  "remainder of the walls about you. The stone has been\n"+
                  "worked smooth, and several intriguing plaques point in\n"+
                  "many directions. Perhaps you could "+HIY+"<"+NORM+"read"+HIY+">"+NORM+" them",
      "pathways", "The paths and twisting tunnels of the UnderDark extend\n"+
                  "from here in many directions",
    });

    dest_dir=({
      "/players/daranath/underdark/level2/j28.c","northwest",
      "/players/daranath/underdark/level2/l30.c","southeast",
      "/players/daranath/underdark/level2/k30.c","east",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search_room");
    add_action("read","read_sign");
    }

    search(){
    write("You find nothing amonst the dirt and debris.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

    read_sign(){
    write("The plaques upon the signpost are in a strange language.\n");
    say(tp +" reads the signpost.\n");
     return 1;
    }

arate() { return "YES"; }
