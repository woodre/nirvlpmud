#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
    short_desc= "Empty Lot for Sale";
    long_desc=
     "The area around here has been cleaned out for construction. A private\n"+
     "mansion looks to be built upon this land.\n"+
     "\nThis is Mansion Lot #5.\n";

    items=({
     "area","The land here is completely bare and ready for construction.\n"+
         "You wonder just how much this lot goes for....",
    });

    dest_dir=({
     "/players/daranath/qualtor/shield_st3.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("Nothing of interest lies about his empty lot.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


