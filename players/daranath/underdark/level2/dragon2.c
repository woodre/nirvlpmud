#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(-1);
    short_desc= "A Tunnel within the UnderDark";
    long_desc=
      "The natural tunnels of the UnderDark continue here, however there\n"+
      "is a major change to this tunnel. The area is bathed in a red\n"+
      "glow, which eminating from the southeast of here. The glow is\n"+
      "accompanied by a blast of heat, coming at you from the southeast.\n"+
      "The tunnel continues torwards that blast of heat, travelling\n"+
      "to the southeast and also back to the north.\n";

    items=({
      "tunnels", "The tunnels continue in all directions in the darkness",
      "walls", "The walls are rocky and rough hewn",
      "passage", "The passage along the tunnel is interupted at times\n"+
                 "by sharp rock outcroppings",
      "glow", "A soft red glow is coming from the tunnel to the\n"+
              "southwest from here. The glow is accompanied by a\n"+
              "blast of really hot air",
     });

    dest_dir=({
      "/players/daranath/underdark/level2/dragon1.c","north",
      "/players/daranath/underdark/level2/dragon3.c","southeast",
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
