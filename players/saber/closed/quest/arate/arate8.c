#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){

  if(!present("guard"))  {
  move_object(clone_object("/players/saber/closed/quest/arate/pool.c"),
  this_object());        }

 if(!arg){

set_light(1);
short_desc = "The Temple of Arate";
long_desc=
"     ==        ==\n"+
"     ==        ==           Shadows gather as you walk through the\n"+
"=======        =======      dark corridor of the Temple of Arate.\n"+
"                            The area is lit faintly by dim black\n"+
"                            candles.  The smell of incense is heavy\n"+
"======================      in the air.\n";

items=({
 "temple","You are in the Temple of Arate",
 "shadows","The shadows almost seem like they are alive",
 "corridor","The corridor is filled with a haze of incense smoke",
 "incense","The incense is so sweet you begin to feel light headed",
 "candles","The candles are small and black",
 });

dest_dir=({
 "/players/saber/closed/quest/arate/arate4.c","north",
 "/players/saber/closed/quest/arate/arate9.c","east",
 "/players/saber/closed/quest/arate/arate7.c","west",
           });
  }   }

init(){
 ::init();
  add_action("search","search");
}

search() {
 write("You find nothing.\n");
 say (tp +" searches the area\n");
 return 1;  }

realm()  { return "NT"; }
arate()  { return "YES"; }
