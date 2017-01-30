#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
 if(!arg){

set_light(1);
short_desc = "The Temple of Arate";
long_desc=
"================ \n"+
"              ==            Surrounded by shadows and the haze of\n"+
"              ==            incense, you begin to feel that you \n"+
"=======       ==            are being watched.  The chanting echoes\n"+
"     ==       ==            off the walls, giving the impression\n"+
"     ==       ==            that this corridor may not be as empty\n"+
"     ==       ==            as it initially appeared.\n";

items=({
 "temple","You are in the Temple of Arate",
 "shadows","The shadows almost seem like they are alive",
 "corridor","The corridor is filled with a haze of incense smoke",
 "incense","The incense is so sweet you begin to feel light headed",
 "chanting","You can't look at chanting",
 });

dest_dir=({
 "/players/saber/closed/quest/arate/arate3.c","west",
 "/players/saber/closed/quest/arate/arate8.c","south",
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
