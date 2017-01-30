#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
if(!present("priestess"))  {
move_object(clone_object("/players/saber/closed/quest/larn/larnheal.c"),this_object());  }
 if(!arg){

set_light(1);
short_desc = "The Church of Larn";
long_desc=
 "You stand in the chamber of healing.  A large banquet\n"+
 "table stretches nearly the length of the room.  There\n"+
 "are archways both to the north and to the east.\n";

items=({
 "chamber","You stand in the chamber of healing",
 "table","A large banquet table stretches before you.  It is empty",
 "archways","Archways lead both north and east",
 "benches","There are many pew benches here on which to sit",
 });

dest_dir=({
 "/players/saber/closed/quest/larn/larn4.c","north",
 "/players/saber/closed/quest/larn/larn2.c","east",
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
