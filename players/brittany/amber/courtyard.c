#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int i;

reset(arg) {
	if(!present("guard", this_object())) {
    for(i=0; i < 3; i++) {
      move_object(clone_object("/players/brittany/amber/guard.c"),
      this_object());
    }
  }
  
   if(arg) return;
   set_light(1);
   
   short_desc = BLU+"Courtyard"+NORM;
   long_desc =
   "     Inside the main entrance, there is a large, cobbled courtyard, lit\n"+
   "by torches and filled with bedrolls.  You can smell the sweat, smoke,\n"+
   "horses, and the odors of cooking.  A small army is inside the courtyard.\n";
   
   items = ({
         "courtyard","A large courtyard made out of cobblestone",
         "horses","Horses are tied to stacks",
         "smoke","The smoke of campfires blazes the air",
         "army","A small army bivouacked in the courtyard",
         "torches","Lighted torches staked into the ground",
         "bedrolls","Bedrolls lay around the courtyard",
         });

   dest_dir = ({
         "/players/brittany/amber/keep.c","out",
         "/players/brittany/amber/chamber.c","in",
              });
}

init() {
   add_action("out","out");
   add_action("in","in");
   add_action("search","search");
}

out(str){
  tp->move_player("out#/players/brittany/amber/keep.c");
  return 1; }
  
in(str){
  tp->move_player("in#/players/brittany/amber/chamber.c");
  return 1; }

search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}
