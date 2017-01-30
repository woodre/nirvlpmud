#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(-1);
    short_desc= "A Tunnel within the UnderDark";
    long_desc=
      "The myriad of tunnels continues from this area, naturally twisting\n"+
      "and turning along unseen paths. Small fungal growths cling to the\n"+ 
      "rough walls and rocky passage. The walls are rough hewn and\n"+
      "rocky, making for an isolated feeling, yet well travelled enough\n"+
      "that you know you are not alone. A soft red glow is eminating\n"+
      "from the southwest of here.\n";

    items=({
      "tunnels", "The tunnels continue in all directions in the darkness",
      "walls", "The walls are rocky and rough hewn",
      "paths", "The paths follow the tunnels about the UnderDark",
      "fungus", "The fungus is a normal type for the UnderDark",
      "passage", "The passage along the tunnel is interupted at times\n"+
                 "by sharp rock outcroppings",
      "glow", "A soft red glow is coming from the tunnel to the\n"+
              "southwest from here. The glow is accompanied by a\n"+
              "blast of hot air",
     });

    dest_dir=({
      "/players/daranath/underdark/level2/f14.c","northwest",
      "/players/daranath/underdark/level2/dragon1.c","southwest",
      "/players/daranath/underdark/level2/g16.c","east",
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
