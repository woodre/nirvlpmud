#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
move_object(clone_object("/players/daranath/qualtor/swamp/grolm2.c"),this_object());
  if(!present("critter")) {
    int a; a = 0;
  while(a<(random(4))){
    int b; b = random(3);
  if(b == 0) move_object(clone_object("/players/daranath/qualtor/swamp/urchin.c"),this_object());
  if(b == 1) move_object(clone_object("/players/daranath/qualtor/swamp/mosq.c"),this_object());
  if(b == 2) move_object(clone_object("/players/daranath/qualtor/swamp/sm_snake.c"),this_object());
  a++;
  }
move_object(clone_object("/players/daranath/qualtor/swamp/grolm.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/swamp/grolm.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/swamp/grolm.c"),this_object());
}
  if(!arg){
    
    set_light(1);
    short_desc= "Qual'tor Swamp";
    long_desc=
     "You stand at the northern edge of the swamp just outside the walls\n"+
     "of Qual'tor. The swamp itself lies south from here, while just to\n"+
     "the west a roadway can be seen running about the exterior of the\n"+
     "city.\n";

    items=({
     "roadway","The road itself is little travelled....",
     "swamp","The swamp is full of many dangers for rookie adventurors",
     "city","Qual'tor was a ruined city that is on its way back",
    });

    dest_dir=({
     "/players/daranath/qualtor/swamp/swamp8.c","north",
     "/players/daranath/qualtor/swamp/swamp9.c","northeast",
     "/players/daranath/qualtor/swamp/swamp11.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    add_action("dar_west","west");
    }

    search(){
    write("The swamp makes you a little too nervous to search thoroughly.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

    dar_west(){
    if(present("grolm")){
    write("The grolm blocks your path.\n");
    return 1; }
    return 0; 
    }
