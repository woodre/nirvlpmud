#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
 if(!arg){

set_light(1);
short_desc = "The Church of Larn";
long_desc=
 "\n\n\n\n    You stand within the chamber of light.\n\n\n\n";

items=({
 "light","It is too bright to see well",
 });

dest_dir=({
 "/players/saber/closed/quest/larn/larn8.c","west",
 "/players/saber/closed/quest/larn/larn6.c","south",
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
