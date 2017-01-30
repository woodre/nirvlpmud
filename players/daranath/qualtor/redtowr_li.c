#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
move_object(clone_object("/players/daranath/qualtor/mon/mourn_coil.c"),this_object());
  if(!arg){
    
    set_light(1);
    short_desc= "Red Tower Library";
    long_desc=
     "Shelves filled with ancient tomes and dust covered manuscripts line\n"+
     "the walls of this small chamber, many so fragile they would fall\n"+
     "apart at the slightest touch. No windows are available to allow\n"+
     "light into this area, the only light source is a small\n"+
     "glowing crystal mounted on the far wall.\n";

    items=({
     "crystal","The crystal glows with a redish internal fire",
    });

    dest_dir=({
      "/players/daranath/qualtor/redtowr7.c","out",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    add_action("touch","touch");
    }

    search(){
    write("The red tower library is full of tomes and ancient books to touch\n"+
          "and look through. It would take you weeks to go through\n"+
          "everything.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

    touch() {
    write("You touch one of the books and it crumbles into dust.\n");
    say(tp +" grabs at one of the ancient tomes.\n");
    return 1; 
    }
