#define tp this_player()->query_name()
inherit "room/room";
   int a;

reset(int arg){
   a=0;
  if(!arg){

    set_light(1);
    short_desc= "Pathway to the Ruined Keep";
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
      "/players/daranath/qualtor/keep/path5.c","north",
      "/players/daranath/qualtor/keep/path3.c","south",
      "/players/daranath/qualtor/keep/area2.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    add_action("dar_east","east");
    }

dar_east(){
  if(a == 0) {
  if(!present("necro_ob",this_player())) {
move_object(clone_object("/players/daranath/guild/mon/skel_guardian.c"),this_object());
write("As you try to pass through the area, something climbs from the gound!\n");
say("As "+tp+" walks through the area, something attacks!!!\n");
    a++;
 return 1; }
write("\nYou move further into the darkness about the ruined keep.\n\n");
}
  if(a>0) {
write("\nYou move further into the darkness about the ruined keep.\n\n");
say(tp +" searches the area.\n");
 return 1;
    }
}

search() {
write("You find nothing of interest around the archway leading into the graveyard.\n");
return 1;
 }
