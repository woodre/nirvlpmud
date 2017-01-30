#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
if(!present("priest"))  {
move_object(clone_object("/players/saber/closed/quest/larn/larnguard.c"),this_object());  }
 if(!arg){

set_light(1);
short_desc = "The Church of Larn";
long_desc=
 "You stand in a passageway lit by the soft glow\n"+
 "of torchlight.  To the north is the chamber of\n"+
 "light, east is the armory, south is the chamber\n"+
 "of water and west is the altar.\n";

items=({
 "church","You are in the sanctum of the Church of Larn",
 "chamber","Chambers lie in all directions",
 "altar","The altar is in the room to the west",
 "torch","The torches are set high out of reach",
 });

dest_dir=({
 "/players/saber/closed/quest/larn/larn9.c","north",
 "/players/saber/closed/quest/larn/larn6.c","east",
 "/players/saber/closed/quest/larn/larn3.c","south",
 "/players/saber/closed/quest/larn/larn5.c","west",
           });
  }   }

init(){
 ::init();
  add_action("search","search");
  add_action("east","east");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }

east()  {
write("An invisible force keeps you from moving to the east.\n");
return 1;
        }

realm()  { return "NT"; }
