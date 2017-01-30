#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(-1);
    short_desc= "A hallway within the UnderDark";
    long_desc=
      "The air here is filled is a damp, unpleasent smell which dominates\n"+
      "your senses as you travel through. The grey hallways continue from\n"+
      "here to the south, but the hall itself descends along a stone\n"+ 
      "staircase down into a darkened area. The stairs themselves have\n"+
      "a layer of thick slime across them. After a couple of stairs the\n"+
      "hallway drops into a murky liquid, which completly seals off the\n"+
      "rest of the hall.\n";
      
    items=({
      "tunnels", "The tunnels continue to the southwest into the darkness",
      "liquid", "The murky liquid blocks all sight 
    });

    dest_dir=({
      "/players/daranath/underdark/level2/stairs1.c","north",
      "/players/daranath/underdark/level2/tunnel1.c","south",
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
