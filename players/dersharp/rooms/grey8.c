inherit "room/room";
int i;
reset(arg) {
  monster();
   if (arg) return;
   short_desc="University Drive";
   long_desc ="Two rooms to the north is the university itself.  Gathered about\n"+
              "the park here are students and other people enjoying the park.\n"+
              "The trees here are enormous and, rather than block the sun, seem\n"+
              "to give just the right amount of shade.\n";
   set_light(1);
   dest_dir =
   ({
             "players/dersharp/rooms/grey7.c", "west",
             "players/dersharp/rooms/grey9.c", "east",
             "players/dersharp/rooms/grey-1.c", "north",
   });
   items = ({
          "tree", "These trees are bigger than all the ones you have seen so far,\n"+
                  "but have no easy access to the first branches...tough luck!",
           });
}
monster() {
int count;
   object creature;
   if(!present("creature")) {
    while (i<3) {
      creature = clone_object("players/dersharp/monsters/student");
      move_object(creature, this_object());
     i++;
       }
    i = 0;
   }
}
