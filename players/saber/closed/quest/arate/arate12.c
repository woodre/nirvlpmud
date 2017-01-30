#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
 if(!arg){

set_light(1);
short_desc = "The Temple of Arate";
long_desc=
"     ==        ==           You stand in a hazy four way intersection,\n"+
"     ==        ==           deep within the temple of Arate.  To the\n"+
"=======        =======      south lies the ebon shadowed sanctum of\n"+
"                            Arate, from which pour endless clouds of\n"+
"                            of musky smoke.  The chanting has grown\n"+
"=======        =======      so loud that is seems to invade your body,\n"+
"     ==        ==           echoing through you to the very depths of\n"+
"     ==        ==           your soul.\n";

items=({
 "temple","You are in the Temple of Arate",
 "sanctum","The sanctum of the Temple of Arate is to the south",
 "corridor","The corridor is filled with a haze of incense smoke",
 "smoke","The smokey incense is so sweet you begin to feel light headed",
 "chanting","You source of the chanting is to the south",
 });

dest_dir=({
 "/players/saber/closed/quest/arate/arate7.c","north",
 "/players/saber/closed/quest/arate/arate13.c","east",
 "/players/saber/closed/quest/arate/arate18.c","south",
 "/players/saber/closed/quest/arate/arate11.c","west",
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
