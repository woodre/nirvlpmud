#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
 if(!arg){

set_light(1);
short_desc = "The Temple of Arate";
long_desc=
"     ==        == \n"+
"     ==        ==           You stand in the torture chamber of Arate.\n"+
"  =====        =======      The room is filled with various implements\n"+
"  ==                        of torture, and several large wide lipped\n"+
"  ==                        bowls from which pour hazy clouds of blue\n"+
"  =====        =======      and purple incense.  To both the east and\n"+
"     ==        ==           south you see prison cells.\n"+
"     ==        ==  \n";

items=({
 "temple","You are in the Temple of Arate",
 "chamber","You are in the torture chamber of Arate",
 "cell","There are prison cells to the east and south",
 "cells","There are prison cells to the east and south",
 "incense","The smokey incense is so sweet you begin to feel light headed",
 "bowl","Huge clouds of smoke incense pour from the bowls",
 "implements","Many evil implements of torture fill the chamber",
 });

dest_dir=({
 "/players/saber/closed/quest/arate/arate20.c","north",
 "/players/saber/closed/quest/arate/arate25.c","east",
 "/players/saber/closed/quest/arate/arate27.c","south",
           });
  }   }

init(){
 ::init();
  add_action("search","search");
  add_action("south","south");
  add_action("south","east");
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
