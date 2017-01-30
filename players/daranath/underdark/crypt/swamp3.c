#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
move_object(clone_object("/players/daranath/mons/un_snake.c"),this_object());
move_object(clone_object("/players/daranath/mons/un_snake.c"),this_object());
  if(!arg){
    
    set_light(1);
    short_desc= "Underground marsh";
    long_desc=
  "An open area hidden deep within the stone of the UnderDark holds a\n"+
  "small marsh from the penetrating light from above. The standing water\n"+
  "that is about waist deep in most parts, sending quite a chill about your\n"+
  "frame. Small, weedlike growths are floating upon the surface of the\n"+
  "water. The only exit appears to be back up the tunnel from here.\n";

    items=({
    "tunnel", "The tunnel is naturally formed from the rock",
    "stream", "The small stream runs down the same trail as the path,\n"+
               "gaining strength as it flows",
    "water", "The water of the stream is fresh and cool",
    "light", "A small amount of light filters through the hole in the\n"+
             "wall from the stairwell area",
     });

    dest_dir=({
      "/players/daranath/underdark/crypt/swamp2.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("You cannot find anything about the area with the water covering it.\n");
    say(tp +" searches the area.\n");
     return 1;
    }



arate() { return "YES"; }
