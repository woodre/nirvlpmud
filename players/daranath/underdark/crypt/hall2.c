#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
    short_desc= "Hallway within the Crypt";
    long_desc=
      "Dirty white marble lines the hallway here, traveling east and\n"+
      "west along a straight path. The hall is dinly lit by a series\n"+
      "of smoldering torches, casting some light, but also deepening\n"+
      "the shadows within. An ornate wooden door is set into the west\n"+
      "end of the hallway, the door left slightly ajar.\n";

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
      "door", "The ornate wooden door has a brass knobb and a large\n"+
              "golden sigil set into the front of it",
     });

    dest_dir=({
      "/players/daranath/underdark/crypt/entry.c","east",
      "/players/daranath/underdark/crypt/mage.c","west",
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
