#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
move_object(clone_object("/players/daranath/mons/un_knight1.c"),this_object());
move_object(clone_object("/players/daranath/mons/un_knight1.c"),this_object());
move_object(clone_object("/players/daranath/mons/un_knight1.c"),this_object());
move_object(clone_object("/players/daranath/mons/un_knight2.c"),this_object());
move_object(clone_object("/players/daranath/mons/un_knight2.c"),this_object());
move_object(clone_object("/players/daranath/mons/un_knight2.c"),this_object());
  if(!arg){
    
    set_light(-1);
    short_desc= "Knight's Archway";
    long_desc=
      "Doubling back upon itself, the marble hall runs from the northeast\n"+
      "back unto the east. A large granite archway is mounted into the\n"+
      "walls further down the eastern tunnel. A soft, rolling mist is\n"+
      "flowing through the arch torwards your position.\n";

    items=({
      "marble", "The marble of the walls here looks as if it was lifted\n"+
                "from another area of the mountain and brought here. It\n"+
                "looks very out of place within this area",
      "dirt", "The dirt spills about the area, covering the white stone\n"+
              "floor and walls",
      "arch", "The large granite archway leads eastward into a small\n"+
              "room filled with a strange mist",
      "archway", "The large granite archway leads eastward into a small\n"+
                 "room filled with a strange mist",
      "mist", "A light blue colored mist is flowing through the archway\n"+
              "to the east from here. It is cool to the touch",
     });

    dest_dir=({
      "/players/daranath/underdark/crypt/hall3.c","northeast",
      "/players/daranath/underdark/crypt/death.c","east",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search_room");
    }

    search(){
    write("It is hard to search the area with the mist about.\n");
    say(tp +" searches the area.\n");
     return 1;
    }



arate() { return "YES"; }
