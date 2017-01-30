inherit"room/room";

reset(arg) {

   if(!arg) {
   int i;
   object sprite;

   set_light(1);
   short_desc = "The First level of Fire";
   long_desc=
"Heat eminates from the room.  Flames seem to come out of the cracks in\n"+
"the walls.  This room is like an oven, with shadows dancing on the walls\n"+
"in the stark light of the fires.\n";

dest_dir = ({
   "players/blue/fire/sprite2n","north",
   "players/blue/fire/sprite2s","south",
   "players/blue/fire/level1","east",
   "players/blue/fire/sprite3","west"
   });

if(!present("sprite",this_object())) {
   i=0;
   while(i<5) {
sprite=clone_object("players/blue/monster/fire_sprite");
move_object(sprite,this_object());
   i+=1;
   }
}
}
}