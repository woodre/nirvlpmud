#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
    short_desc= "Hallway within the Crypt";
    long_desc=
      "Dirty white marble lines the hallway here, traveling north and\n"+
      "south along a straight path. The hall is dinly lit by a series\n"+
      "of smoldering torches, casting some light, but also deepening\n"+
      "the shadows within. The marble hallway continues into the\n"+
      "darkness, splitting off to the southeast and southwest, while\n"+
      "travelling back to the stairwell to the north.\n";

    items=({
      "marble", "The marble of the walls here looks as if it was lifted\n"+
                "from another area of the mountain and brought here. It\n"+
                "looks very out of place within this area",
      "dirt", "The dirt spills about the area, covering the white stone\n"+
              "floor and walls",
      "torches", "Smoldering torches are lined along the walls, shedding\n"+
                 "some light about the area",
      "shadows", "The shadows run deep in this area, playing tricks with\n"+
                 "your mind",
      "stairwell", "The stairwell leading up from the crypt lies to the\n"+
                   "north from here",
      "tunnel", "A tunnel made by some sort of large creature breaks\n"+
                "through the wall into the room from the north",
    });

    dest_dir=({
      "/players/daranath/underdark/crypt/entry.c","north",
      "/players/daranath/underdark/crypt/knight1.c","southwest",
      "/players/daranath/underdark/crypt/knight2.c","southeast",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search_room");
    }

    search(){
    write("You find nothing amongst the dirt.\n");
    say(tp +" searches the area.\n");
     return 1;
    }



arate() { return "YES"; }
