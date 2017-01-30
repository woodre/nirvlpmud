#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(-1);
    short_desc= "A Tunnel within the UnderDark";
    long_desc=
      "The myriad of tunnels ends in this area, coming to a stop within\n"+
      "a small cave-like area. Several column like rock formations are\n"+
      "in evidence here, with a couple of stalagmites and stactites\n"+
      "coming together. A sloping tunnel descends from this small room,\n"+
      "leading down into the darkness below.\n";

    items=({
      "tunnels", "The tunnels continue in all directions in the darkness",
      "walls", "The walls are rocky and rough hewn",
      "darkness", "Not much is visible within the darkness from below",
      "tunnel", "The tunnel leads downwards, not giving any indication\n"+
                "as to where it leads. The passage is steep, yet still\n"+
                "smooth enough for you to descend without much trouble",
      "formations", "The rocky formations are common within this area\n"+
                    "and have nothing outstanding about them",
    });

    dest_dir=({
      "/players/daranath/underdark/level2/c3.c","southeast",
      "/players/daranath/underdark/level2/down1.c","down",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("You find nothing amongst the dirt and debris.\n");
    say(tp +" searches the area.\n");
     return 1;
    }



arate() { return "YES"; }
