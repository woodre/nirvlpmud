#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
    short_desc= "Mountain Road";
    long_desc=
     "The trail leading around the base of the mountain ends here, a\n"+
     "large cave entrance leading into the mountain itself. The cave\n"+
     "is supported by mining beams, making an arch-shaped doorway\n"+
     "leading into the darkness within.\n";

    items=({
     "cave","The cave has been dug from the side of the mountain long ago,\n"+
           "probably by dwarves hoping to make a profit here",
     "trail","The trail leads back around the mountain to the south",
     "mountain","The mountain seems massive when standing at its base",
     "beams","The wooden beams are standard fare in any Indiana Jones movie",
     "doorway","The wooden beams and cave entrance make the doorway",
     "darkness","I wouldn't go in there without a good light source",
    });

    dest_dir=({
      "/players/daranath/mines/outside/nroad6.c","north",
      "/players/daranath/mines/outside/nroad4.c","south",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("You find little bits and pieces of dark grey stone along the trail.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

