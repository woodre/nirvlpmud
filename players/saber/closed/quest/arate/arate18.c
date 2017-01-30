#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
 if(!arg){

set_light(1);
short_desc = "The Temple of Arate";
long_desc=
"     ==       ==            You stand within the outer sanctum of the\n"+
"     ==       ==            temple of Arate.  The chamber is congested\n"+
"    ==         ==           with an incense haze, making it impossible\n"+
"   ==           ==          to see for more than a few paces.  The low\n"+
"   ==           ==          echoes of chanting fill seem to emerge from\n"+
"   ==           ==          from the inner sanctum to the south.\n";

items=({
 "temple","You are in the Temple of Arate",
 "sanctum","You stand within the inner sanctum of the Temple of Arate",
 "chamber","The chamber is congested with an incense haze",
 "smoke","The smokey incense is so sweet you begin to feel light headed",
 "chanting","You source of the chanting is to the south",
 "haze","The haze twists in chaotic patterns",
 });

dest_dir=({
 "/players/saber/closed/quest/arate/arate12.c","north",
 "/players/saber/closed/quest/arate/arate18.c","south",
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
  write("A great force keeps you from moving to the south.\n");
  return 1;
            } 

realm()  { return "NT"; }
arate()  { return "YES"; }
