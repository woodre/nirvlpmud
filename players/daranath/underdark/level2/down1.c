#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(-1);
    short_desc= "Descent into the Depths of the UnderDark";
    long_desc=
      "The natural tunnel decends into the depths of the UnderDark.\n"+
      "The rough, rocky slope leaves little footing for the climb,\n"+
      "making one pick and choose thier path with care. The darkness\n"+
      "is all about and continues to close in upon you.\n";

    items=({
      "passage", "The passage along the tunnel is interupted at times\n"+
                 "by sharp rock outcroppings",
      "slope", "The rocky slope makes it impossible for anyone to\n"+
               "rush through this area",
      "darkness", "The darkness plays tricks with your vision, causing\n"+
                  "one to see things that are not quite there",
    });

    dest_dir=({
      "/players/daranath/underdark/level2/b2.c","up",
      "/players/daranath/underdark/level3/entry.c","down",
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

