#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

  status rock;
reset(arg) {
   if(arg) return;
  rock = 1;
   set_light(1);
   
   short_desc = RED+"Earth Region"+NORM;
   long_desc =
 "     The ground quakes beneath your feet.  An unscalable mountain range\n"+
   "is visible in the distance, and a huge volcano spewing lava can be seen\n"+
   "at the top of the mountain.  A small rock catches you eye.\n";

        items = ({
         "rock","A small odd shaped rock, maybe you could 'move' it",
         "ground","The ground seems to be unsteady",
         "volcano","Lava spewing from a huge mountain",
          });

      dest_dir = ({
         "/players/brittany/xanth/fen.c","east",
         });
}

   init() {
   ::init();
      add_action("move_rock","move");
      add_action("search","search");
   }

search() {
notify_fail("You find nothing of interest.\n");
return 0;
}

move_rock(str){
object dragon;
  if (!str || str != "rock") {
notify_fail ("What do you want to move?\n");
return 0; }

if(rock) {
write("You move the rock and the ground shakes.\n\n"+
  "A small dragon appears.\n");
  dragon = clone_object("/players/brittany/xanth/NPC/rockling.c");
  move_object(dragon,this_object());
  dragon->attack_object(this_player());
  rock = 0;
  }

else write("You move the rock.\n");
  return 1;}
