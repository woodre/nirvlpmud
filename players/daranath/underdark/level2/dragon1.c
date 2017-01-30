#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(-1);
    short_desc= "A Tunnel within the UnderDark";
    long_desc=
      "The natural tunnels of the UnderDark continue here, however there\n"+
      "is a major change to this tunnel. The area is bathed in a red\n"+
      "glow, washing over everything within the area. The glow is\n"+
      "accompanied by a blast of heat, coming at you from the south.\n"+
      "The tunnel continues torwards that blast of heat, travelling\n"+
      "to the south and also back to the northeast.\n";

    items=({
      "tunnels", "The tunnels continue in all directions in the darkness",
      "walls", "The walls are rocky and rough hewn",
      "passage", "The passage along the tunnel is interupted at times\n"+
                 "by sharp rock outcroppings",
      "glow", "A soft red glow is coming from the tunnel to the\n"+
              "southwest from here. The glow is accompanied by a\n"+
              "blast of hot air",
     });

    dest_dir=({
      "/players/daranath/underdark/level2/g15.c","northeast",
      "/players/daranath/underdark/level2/dragon2.c","south",
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
