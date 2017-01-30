#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(-1);
    short_desc= "A Tunnel within the UnderDark";
    long_desc=
      "The myriad of tunnels continues from this area, naturally twisting\n"+
      "and turning along unseen paths. The walls here are rough hewn and\n"+
      "rocky, making for an isolated feeling, yet well travelled enough\n"+
      "that you know you are not alone. The passage turns to the southwest\n"+
      "from here, the walls of the tunnel turning into a blackened stone\n"+
      "making up the hallway .\n"; 

    items=({
      "tunnels", "The tunnels continue in all directions in the darkness",
      "walls", "The walls are rocky and rough hewn",
      "paths", "The paths follow the tunnels about the UnderDark",
      "passage", "The passage along the tunnel is interupted at times\n"+
                 "by sharp rock outcroppings",
      "stone", "The blackened stone lines the hallway leading to the\n"+
               "southwest from here. The stone itself is not from this\n"+
               "area, making it look as if someone brought it in here",
      "hallway", "The hallway leads to the southwest from here",
    });

    dest_dir=({
      "/players/daranath/underdark/level2/l18.c","east",
      "/players/daranath/underdark/level2/m16.c","southwest",
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
