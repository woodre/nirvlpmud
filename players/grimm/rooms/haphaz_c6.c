inherit "room/room";
int i;
reset(arg) {
  monster();
  if(arg) return;
  short_desc="Littered Room";
long_desc="This is the home of a rather disgusting looking punk.  The room\n"+
"is covered in litter and the walls are covered in graffiti.\n";
  dest_dir=({"players/grimm/rooms/haphaz_b6","west"});
set_light(1);

items = ({"graffiti",
"The graffiti on the wall has many different messages, but only one\n"+
"seems to catch your interest.  Although it is kind of blury you can\n"+
"make out:\n           SE_ORD_\n"});
}


monster() {
int count;
   object punk;

   if(!present("punk")) {
    while (i<3) {
      punk = clone_object("players/grimm/monster/mpunk");
      move_object(punk, this_object());
     i++;
       }
    i = 0;
   }
}
