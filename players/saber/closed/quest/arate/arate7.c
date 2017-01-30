#define tp this_player()->query_name()
inherit "room/room";
int guards;

reset(int arg){

  if(!present("guard"))  {
  for(guards = 0; guards < 2; guards = guards + 1)  {
  move_object(clone_object("/players/saber/closed/quest/arate/arateguard.c"),
  this_object());        }  }

 if(!arg){

set_light(1);
short_desc = "The Temple of Arate";
long_desc=
"======================       The magnitude of the darkness grows,\n"+
"                             casting shadows so thick that they\n"+
"                             slowly impede your progress through\n"+
"=======        =======       the corridor.  The chanting echoes\n"+
"     ==        ==            from all directions, weaving weird\n"+
"     ==        ==            patterns in the heavy incense haze.\n";

items=({
 "temple","You are in the Temple of Arate",
 "shadows","The shadows almost seem like they are alive",
 "corridor","The corridor is filled with a haze of incense smoke",
 "incense","The incense is so sweet you begin to feel light headed",
 "chanting","You can't see chanting",
 "darkness","The darkness almost seems to be alive",
 "patterns","Patterns shift before your eyes in a storm of chaotic images", 
 });

dest_dir=({
 "/players/saber/closed/quest/arate/arate8.c","east",
 "/players/saber/closed/quest/arate/arate12.c","south",
 "/players/saber/closed/quest/arate/arate6.c","west",
           });
  }   }

init(){
 ::init();
  add_action("search","search");
}

search() {
 write("You find nothing.\n");
 say (tp +" searches the area.\n");
 return 1;  }

realm()  { return "NT"; }
arate()  { return "YES"; }
