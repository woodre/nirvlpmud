inherit "room/room";
reset(arg) {
monst();
if(arg)
      return;
short_desc="Forest of Blood";
long_desc="The forest is extremely dark here.  You can't tell which way you\n"+
   "came from because of the over-grown vegetation that surrounds you and\n"+
   "seems to move towards you.  The best thing to do is to keep moving.\n",
items=({"vegetation","It is a great mass of thorns with red and black leaves\n"+
   "that seem to be drawn by the blood in your body!"});
dest_dir=({"players/grimm/frst/forest5","west",
           "players/grimm/frst/forest7","east",
           "players/grimm/frst/forest10","south"});
set_light(0);
}
monst() {
int count;
object dog,vampire;
   if(!present("dog",this_object())) {
      while(count<3) {   count += 1;
         dog = clone_object("players/grimm/monster/vampdog");
         move_object(dog,this_object());
         vampire = clone_object("players/grimm/monster/yungvamp");
         move_object(vampire,this_object());
      }
   return 1; }
return 1; }
