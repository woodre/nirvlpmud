#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(-1);
    short_desc= "Entrance into the Crypt";
    long_desc=
      "The iron rung stairwell empties out onto a cold marble floor.\n"+
      "A layer of dirt and filth spills out about the area. Marble\n"+
      "hallways run from here to the east, west and south, while a\n"+
      "tunnel breaks into the room from the north.\n";

    items=({
      "marble", "The marble of the walls here looks as if it was lifted\n"+
                "from another area of the mountain and brought here. It\n"+
                "looks very out of place within this area",
      "dirt", "The dirt spills about the area, covering the white stone\n"+
              "floor and walls",
      "stairwell", "The black iron rung stairwell descends into the room\n"+
                   "from above",
      "tunnel", "A tunnel made by some sort of large creature breaks\n"+
                "through the wall into the room from the north",
    });

    dest_dir=({
      "/players/daranath/underdark/crypt/swamp1.c","north",
      "/players/daranath/underdark/crypt/hall3.c","south",
      "/players/daranath/underdark/crypt/hall1.c","east",
      "/players/daranath/underdark/crypt/hall2.c","west",
      "/players/daranath/underdark/level1/crypt_entry.c","up",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("Shuffling footprints move across the area in several directions.\n");
    say(tp +" searches the area.\n");
     return 1;
    }



arate() { return "YES"; }
