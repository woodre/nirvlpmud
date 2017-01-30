#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

int mob;
reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = BLU+"A bug house"+NORM;
   long_desc =
    "     The door swings and closes behind you.  Suddenly some chittering\n"+
    "sound becomes loud.  Something rustles over your feet.  When your eyes\n"+
    "finally adjust to the gloom, you notice the dead insects all over the\n"+
    "floor.  You have entered a bug-house, in the corner there is a strange\n"+
    "looking bed.\n";
   
   items = ({
         "door","The door to the house swings closed as you enter",
         "bugs","Dead bugs are smashed on the floor",
         "house","The house is filled with dead bugs all over the place",
         "floor","The floor is covered with dead bugs",
         "wall","The wall is covered with gourd",
         "bed","A comfortable looking bed on rollers, maybe you could 'lay'\n"+
         "on it",
          });

   dest_dir = ({
         "/players/brittany/xanth/garden.c","out",
              });
}
init() {
::init();
   add_action("out","out");
   add_action("lay_bed","lay");
   add_action("search","search"); 
}
 
search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}

out(str){
tp->move_player("out#/players/brittany/xanth/garden.c");
return 1; }

lay_bed(str) {
   if(!str || str != "bed") {
      notify_fail("Where do you want to lay?\n");
      return 0; }
   write(
    "You lay on the bed and you get thrown off.\n");
   say(tpn+"  lay on the bed.\n");
if(!mob) { move_object(clone_object("/players/brittany/xanth/NPC/bedbug.c"), this_object()); mob = 1; }
   return 1;
}
