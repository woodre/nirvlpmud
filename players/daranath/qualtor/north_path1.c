#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
    short_desc= "Northern Trail";
    long_desc=
     "The pathway you stand upon runs along the northern edge of the city\n"+
     "of Qual'tor. Tall reeds grow along one edge of the trail, while\n"+
     "the outer wall of the city lines the trails southern edge.\n"+
     "The trail runs east and west from here.\n";

    items=({
     "area","The land here is completely bare and ready for construction.\n"+
         "You wonder just how much this lot goes for....",
    });

    dest_dir=({
/*
     "/players/daranath/qualtor/mansion/lot11.c","east",
*/
     "/players/daranath/qualtor/nor_qual1.c","west",
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


