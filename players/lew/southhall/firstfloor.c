
inherit "room/room";

reset(arg) {
  if(!arg) {
   set_light(1);
   short_desc="1st South";
   long_desc=
"As you enter South Hall, you have the distinc fealing of fear rush\n"+
"through you.  You notice that this area of the residence hall hasn't\n"+
"been renovated, thus the administration decided to put all (or at\n"+
"least as many as possibe) the ROTC students.  The place gives you the\n"+
"chills.  It resembles a prison.  Yet you still hear much laughter\n"+
"from upstairs (Not too mention the shouts of half the RHA staff).\n"+
"Goin up would be cool.\n";

   dest_dir= ( {
     "players/lew/southhall/stairway", "up",
     "players/lew/southhall/tunnel", "down",
     "players/lew/lounge2", "east",
     } );
}
}
