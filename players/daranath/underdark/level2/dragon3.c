#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(-1);
    short_desc= "A Tunnel within the UnderDark";
    long_desc=
      "The tunnels open into a large cavern here, in the center of\n"+
      "which is a large lake. The cavern itself is over 200 feet across\n"+
      "and a path encircles the still water in its center. Another\n"+
      "cave opening is set into the wall directly opposite the lake\n"+
      "from your position. The heat is almost unbearable here, and\n"+
      "the redish glow seems to come from the cave opposite you.\n";
      
    items=({
      "tunnels", "The tunnels continue in all directions in the darkness",
      "walls", "The walls are rocky and rough hewn",
      "passage", "The passage along the tunnel is interupted at times\n"+
                 "by sharp rock outcroppings",
      "glow", "A soft red glow is coming from the tunnel to the\n"+
              "southwest from here. The glow is accompanied by a\n"+
              "blast of really hot air",
      "lake", "The still waters of the lake cause it to be impossible\n"+
              "to judge the lake's depth",
     });

    dest_dir=({
      "/players/daranath/underdark/level2/dragon2.c","northwest",
      "/players/daranath/underdark/level2/dragon4.c","east",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search_room");
    }

    search(){
    write("You find nothing amonst the dirt and debris.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


arate() { return "YES"; }
