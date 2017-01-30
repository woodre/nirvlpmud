#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(-1);
    short_desc= "Death's Chamber";
    long_desc=
      "Mist swirls about your legs as you stand within this area. The\n"+
      "white marble walls and ceiling continue here, streaks of blood\n"+ 
      "and dirt staining the pure nature of the stone. A pair of granite\n"+
      "archways lead from the area, one heading east and the other west,\n"+
      "while a smaller marble doorway heads south from here.\n";

    items=({
      "marble", "The marble of the walls here looks as if it was lifted\n"+
                "from another area of the mountain and brought here. It\n"+
                "looks very out of place within this area",
      "dirt", "The dirt spills about the area, covering the white stone\n"+
              "floor and walls",
      "mist", "A light blue colored mist is flowing through the archway\n"+
              "to the east from here. It is cool to the touch",
      "blood", "Blood and dirt cover the walls here, splattered about in\n"+
               "a random fashion",
      "doorway", "The marble doorway leading southwards is in very bad\n"+
                 "condition, its door long since ripped from its hinges,\n"+
                 "and the frame of the door broken and shattered",
      "streaks", "Streaks of blood cover the walls",
      });

    dest_dir=({
      "/players/daranath/underdark/crypt/knight2.c","east",
      "/players/daranath/underdark/crypt/knight1.c","west",
      "/players/daranath/underdark/crypt/orb.c","south",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search_room");
    }

    search(){
    write("It is impossible to search the area with the mist about.\n");
    say(tp +" searches the area.\n");
     return 1;
    }



arate() { return "YES"; }
