#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
if(!present("guard"))  {
move_object(clone_object("/players/saber/closed/quest/arate/arateguard.c"),this_object());  }
 if(!arg){

set_light(1);
short_desc = "The Temple of Arate";
long_desc=
"     ====   ====            You stand at the entrance to the Temple \n"+
"     ==       ==            of Arate.  To the south the dark corridor\n"+
"     ==       ==            stretches off into heavy shadows.  In the\n"+
"     ==       ==            distance you hear the sounds of chanting\n"+
"     ==       ==            and low, demonic laughter...\n";

items=({
 "temple","You are in the Temple of Arate",
 "shadows","The shadows almost seem like they are alive",
 "corridor","The corridor is filled with a haze of incense smoke",
 "incense","The incense is so sweet you begin to feel light headed",
 "chanting","You can't look at chanting",
 });

dest_dir=({
 "/players/saber/closed/quest/arate/arate.c","north",
 "/players/saber/closed/quest/arate/arate3.c","south",
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
arate()  { return "YES"; }
