inherit "room/room";
int i;
reset(arg) {
  monster();
  if(arg) return;
  short_desc="Littered Room";
long_desc="This is the home of a rather disgusting looking creature.  The room\n"+
"is covered in litter and the walls are covered in graffiti.\n";

/* The dest_dir  is a list of directions out of this room. The format is
 * "room_to_move_to" , "command_to_move"  where the command is anything
 * from north, south, east, west to jump, asdf, scramble, wat_eber.
 */
  dest_dir=({
             "/players/yourname/directory/next_room","west",
             "/players/yourname/directory/next_room2","up",
             "/players/yourname/directory/next_room3","jump",
            });
set_light(1);

items = ({"graffiti",
"The graffiti on the wall is mostly illegible.\n"
  });
}


monster() {
int count;
   object creature;

   if(!present("creature")) {
    while (i<3) {
      creature = clone_object("players/yourname/monster/a_creature");
      move_object(creature, this_object());
     i++;
       }
    i = 0;
   }
}
