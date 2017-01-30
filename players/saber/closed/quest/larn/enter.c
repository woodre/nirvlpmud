#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
if(!present("priest"))  {
move_object(clone_object("/players/saber/closed/quest/larn/larnguard.c"),this_object());  }
if(!present("priestess"))  {
move_object(clone_object("/players/saber/closed/new_mini/agents/larn.c"),this_object());  }
 if(!arg){

set_light(1);
short_desc = "The Church of Larn";
long_desc=
 "You stand in the grand entrance hallway of the Church of Larn.  To the north\n"+
 "you see the dimly lit sanctum, and to the east are the huge double doors\n"+
 "leading back into the city of Ryllian.  You feel quiet serenity radiating from\n"+
 "every direction.\n";

items=({
 "enterance","You are in the enterance to the church of Larn",
 "church","You are in the enterance to the church of Larn",
 "sanctum","The sanctum is to the north",
 "ryllian","You are in the city of Ryllian",
 });

dest_dir=({
 "/players/saber/closed/quest/larn/larn2.c","north",
 "/players/saber/ryllian/ryll5.c","east",
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
