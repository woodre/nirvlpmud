inherit"room/room";

reset(arg) {


   object burn, scorch, scald, torch;

   if(!arg) {

   set_light(1);
   short_desc = "Level Four";
   long_desc = 
"This is where the noise is coming from.  Jets of fire shoot out of the\n"+
"walls from small holes, making smoke everywhere and putting out wave after"+
"\nwave of heat.  You can barely make a stairs going up and a stairs going d"+
"own\nthrough all this confusion.\n";

dest_dir = ({
   "players/blue/fire/level5","up",
   "players/blue/fire/level3","down"
   });
burn=clone_object("players/blue/monster/burn");
   move_object(burn, this_object());

scorch=clone_object("players/blue/monster/scorch");
   move_object(scorch, this_object());

scald=clone_object("players/blue/monster/scald");
   move_object(scald, this_object());

   }
}

