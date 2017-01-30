inherit "room/room";
int i;
reset(arg) {
  monster();
  if(arg) return;
  short_desc="Slime Covered Room";
long_desc="This is the home of several slimy, disgusting looking creatures.\n"
+"They don't look very dangerous, in fact they look downright wimpy.\n";
  dest_dir=({"players/grimm/rooms/haphaz_d6","west"});
set_light(1);

}
monster() {
int count;
   object creature;

   i = 0;
   if(!present("creature")) {
    while (i<4) {
      creature = clone_object("players/grimm/monster/creature");
      move_object(creature, this_object());
     i++;
       }
    i = 0;
   }
}
