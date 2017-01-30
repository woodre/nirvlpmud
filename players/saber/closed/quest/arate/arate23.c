#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
 if(!arg){

set_light(1);
short_desc = "The Temple of Arate";
long_desc=
"     ==        ==   \n"+
"     ==        ==           You stand within the sacrifice chamber of\n"+
"=======        ======       the temple of Arate.  The air is think with\n"+
"                   ==       a haze of incense and the low, deep sounds\n"+
"                   ==       of rhythmic chanting.  In the center of the\n"+
"=======        ======       chamber is a massive crimson stained altar\n"+
"     ==        ==           covered with glowing purple runes.\n"+
"     ==        ==  \n";

items=({
 "temple","You are in the Temple of Arate",
 "chamber","You stand within the sacrifice chamber of the Temple of Arate",
 "incense","The smokey incense is so sweet you begin to feel light headed",
 "chanting","You source of the chanting is to the east",
 });

dest_dir=({
 "/players/saber/closed/quest/arate/arate16.c","north",
 "/players/saber/closed/quest/arate/arate26.c","south",
 "/players/saber/closed/quest/arate/arate22.c","west",
           });
  }   }

init(){
 ::init();
  add_action("search","search");
  add_action("south","south");
}

search() {
 write("You find nothing.\n");
 say (tp +" searches the area.\n");
 return 1;  }

south()  {
  if(present("guard",  environment(this_player()))     ||
     present("priest", environment(this_player()))     ||
     present("priestess", environment(this_player())))  {
     write("You find your path blocked by servants of Arate.\n");
     return 1;
          }
          }

realm()  { return "NT"; }
arate()  { return "YES"; }
