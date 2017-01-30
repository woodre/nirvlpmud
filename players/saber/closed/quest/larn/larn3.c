#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
if(!present("pool"))  {
move_object(clone_object("/players/saber/closed/quest/larn/pool.c"),this_object());  }
 if(!arg){

set_light(1);
short_desc = "The Church of Larn";
long_desc=
 "You stand in the chamber of water.  The room is faintly\n"+
 "lit by a soft glow emanating from the pool of holy water\n"+
 "which fills the center of the chamber.\n";

items=({
 "church","You are in the sanctum of the Church of Larn",
 "water","Type typing <look at pool>",
 "glow","The glow is emanating from the holy water",
 "chamber","You are in the chamber of water",
 });

dest_dir=({
 "/players/saber/closed/quest/larn/larn6.c","north",
 "/players/saber/closed/quest/larn/larn2.c","west",
           });
  }   }

init(){
 ::init();
  add_action("search","search");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }

realm()  { return "NT"; }
