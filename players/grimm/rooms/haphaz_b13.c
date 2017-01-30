inherit "room/room";
int i;
object paper;
init() {
  add_action("take","take");
  add_action("take","get");
  ::init();
}
reset(arg) {
  monster();
  if(arg) return;
  short_desc="Littered Room";
long_desc=
"This is the home of several mean looking dogs.  There are several holes\n"
+"in the ground that once contained once burried bones.\n";
  dest_dir=({"players/grimm/rooms/haphaz_c12","northeast"});
set_light(1);

items = ({"holes",
"You look at the holes and see that one of them has a tiny piece of paper\n"+
"sticking up from it.\n"});
}
monster() {
int count;
   object dog;

   if(!present("dog")) {
    while (i<5) {
      dog = clone_object("players/grimm/monster/pit_bull");
      move_object(dog, this_object());
     i++;
       }
    i = 0;
   }
}
take(str) {
  if (!str) {
    write("What do you want to take?\n");
    return 1;
   }
  if (str=="paper" && !present("dog")) {
    write("You take the piece of paper from one of the holes.\n");
    paper = clone_object("players/grimm/object/paper2");
    move_object(paper, this_player());
    return 1;
   } else {
     if (str=="paper" && present("dog")) {
        write("The dogs will not let you near their loot.\n");
        return 1;
     }
    }
return 0;
}
