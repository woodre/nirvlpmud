#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
move_object(clone_object("/players/daranath/qualtor/mon/war_wife.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/mon/geisha.c"),this_object());
  if(!arg){
    
    set_light(1);
    short_desc= "Inside the Mountain Tent";
    long_desc=
     "A soft candle light reflects off the dark red interior of the tent,\n"+
     "bathing the area in a crimson glow. A pile of furs and soft pelts\n"+
     "lies against the far wall, while a small altar sits near the\n"+
     "front of the room. The only exit is back the way you came.\n";
                                                                      
    items=({
      "clearing", "The clearing within the stone is not typical for a\n"+
                  "mountain",
    });

    dest_dir=({
      "/players/daranath/clearing/mtent3.c","back",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("You find nothing of interest aabout the inside of the tent.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


