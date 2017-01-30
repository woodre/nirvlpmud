#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!present("sign")) {
move_object(clone_object("/players/daranath/qualtor/wep/wshop.c"),this_object());
  }
  if(!arg){
    
    set_light(1);
    short_desc= "Weapon Shop within Qual'tor";
    long_desc=
     "Racks of weapondry line the walls of this small shop, both mundane\n"+
     "and exotic weapons on display. The only exit from the small store\n"+
     "is out the way you came in. A sign on the far wall lists the\n"+
     "various weapons for sale.\n";

    items=({
     "racks","The racks are mostly made of wood",
     "counter","The counter also displays items for sale",
     "weapon","Why not look at the sign",
     "weapons","Look at the sign for the weapons for sale",
    });

    dest_dir=({
      "/players/daranath/qualtor/old_road1.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("There are way too many weapons to search here. You could\n"+
          "spend hours looking through everything.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

