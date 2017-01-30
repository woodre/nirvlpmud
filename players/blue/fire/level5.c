inherit"room/room";

reset(arg) {

object incin;

   if(!arg) {


   set_light(1);
   short_desc = "The Final Level of Fire";
   long_desc = 
"The heat is unbearable in here; the walls seem to glow and vibrate with\n"+
"all the heat that they hold.  The air is so dry that your lungs immediately"+
"\nfeel as though they can only hold out for so long.  As you blearily look"+
"\naround, all you see is a stairway going down.\n";

dest_dir = ({
   "players/blue/fire/level4","down"
   });

incin=clone_object("players/blue/monster/incinerator");
   move_object(incin, this_object());

   }
}
