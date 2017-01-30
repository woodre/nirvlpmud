#define tp this_player()->query_name()
inherit "room/room";
   int a;

reset(int arg){
   a=0;
  if(!arg){

    set_light(1);
    short_desc= "Ruined Gateway of the Keep";
    long_desc=
     "The shadow of the ruined keep falls all about the area, continually\n"+
     "keeping the pathway in darkness. The path itself turns east from\n"+
     "this point, leading to the arched entrance of an old \n"+
     "graveyard.\n";

    items=({
   "shadow","The shadow of the ruined keep bathe the area in darkness",
   "keep","The ruined keep is a sad reminder of the days of old",
   "archway","The archway lies to the east of your location",
   "graveyard","The pathway leads east into an old graveyard.\n"+
        "Many Qual'tor heroes were once buried there",
   "entrance","A stone archway leads into the old graveyard",
   "darkness","The dark can hide many enemies from view",
    });

    dest_dir=({
     "/players/daranath/qualtor/keep/keep1.c","north",
     "/players/daranath/qualtor/keep/path6.c","east",
     "/players/daranath/qualtor/keep/path5.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    add_action("dar_north","north");
    }

dar_north(){
write("The ruined gateway to the keep is a mass of rubble and twisted\n"+
      "iron. It would not be safe to enter.\n");
return 1;
}

search() {
write("You find nothing of interest around the archway leading into the graveyard.\n");
return 1;
 }
