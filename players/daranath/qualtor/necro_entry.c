#define tp this_player()->query_name()
inherit "room/room";
   int a;

reset(int arg){
   a=0;
if(!present("portal")) {
move_object(clone_object("/players/daranath/qualtor/obj/portal2.c"),this_object());
}
  if(!arg){

    set_light(1);
    short_desc= "Necromancer Stronghold Entrance";
    long_desc=
     "A small chamber with walls made from pure white marble, the room\n"+
     "serves as the entrance to the necromantic stronghold.\n";

    items=({
     "walls","The walls of the small chamber are pure marble",
     "wall","The walls of the small chamber are pure marble",
     "marble","The marble is of the purest kind",
     "stronghold","You are in the stronghold of the Necromancers",
    });

    dest_dir=({
  "/players/wocket/necro/room/necro1.c","north",
     "/players/daranath/qualtor/necro_path6.c","out",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

search(){
write("You find nothing about the guild hall.\n");
return 1;
}

