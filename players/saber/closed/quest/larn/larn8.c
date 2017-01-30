#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
 if(!arg){

set_light(1);
short_desc = "The Church of Larn";
long_desc=
 "You are within the inner sanctum of the church\n"+
 "of Larn.  It is here that the priestesses and\n"+
 "priests of Larn come to cast their most potent\n"+
 "magics.  To the north is the chamber of wards,\n"+
 "in which the church of Larn guards the items\n"+
 "which must be kept\n";

items=({
 "church","You are in the sanctum of the Church of Larn",
 "sanctum","You are in the inner sanctum of the church of Larn",
 "north","North is the chamber of wards",
 });

dest_dir=({
 "/players/saber/closed/quest/larn/larn8.c","north",
 "/players/saber/closed/quest/larn/larn9.c","east",
 "/players/saber/closed/quest/larn/larn7.c","west",
           });
  }   }

init(){
 ::init();
  add_action("search","search");
  add_action("north","north");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }

north()  {
write("An invisible force keeps you from moving to the north.\n");
return 1;
        }

realm()  { return "NT"; }
