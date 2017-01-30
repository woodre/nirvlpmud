#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(-1);
    short_desc= "A hallway within the UnderDark";
    long_desc=
      "The twisting myriad of tunnels that make up the bulk of the\n"+
      "UnderDark come to a sudden end here, a worked passage taking\n"+
      "up the remainder of the corridor. The walls are made of a\n"+
      "light grey granite, cut into blocks spaced evenly along the\n"+
      "hall. The halls continue to the northeast and north from here,\n"+
      "while the natural passage travels southwest.\n";

    items=({
      "tunnels", "The tunnels continue to the southwest into the darkness",
      "walls", "The walls are made of a grey granite stone, several\n"+
               "muddy footprints coming from the north passage,\n"+
               "and running southwest along the tunnel",
      "footprints", "The muddy footprints are webbed in nature and\n"+
                    "small claws come from the toes",
      "blocks", "The stone blocks are set in even rows along the walls",
      "granite", "The granite is a strong, cold stone",
      "paths", "The paths follow the tunnels about the UnderDark",
    });

    dest_dir=({
      "/players/daranath/underdark/level2/tunnel2.c","north",
      "/players/daranath/underdark/level2/tunnel3.c","northeast",
      "/players/daranath/underdark/level2/j32.c","southwest",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("You find nothing amonst the dirt and debris.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


arate() { return "YES"; }
