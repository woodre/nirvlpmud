inherit"room/room";

reset(arg) {
   object lava;
   int i;

   if(!arg) {

   set_light(1);
   short_desc = "The Second level of Fire";
   long_desc = 
"The heat is...well...its pretty uncomfortable.  Beads of sweat begin to pour"+
"\nout all over your face.  You wonder what the purpose of this strange tow"+
"er\nmight be.  Above you hear explosions that seem to shake the entire fort"+
"ress.\nThere are stairs leading up and down.\n";

dest_dir = ({
   "players/blue/fire/level3.c","up",
   "players/blue/fire/level1.c","down"
   });

if(!present("lava man",this_object())) {
   i = 0;
   while ( i < 5) {
lava=clone_object("players/blue/monster/lava_man");
   move_object(lava, this_object());
   i+=1;
      }
   }

   }
}
