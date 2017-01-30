inherit "/players/snow/shadows/cata/catabase";
 
reset(arg){
 
 if(!arg){
  ::reset();
 
 long_desc=
 "You find yourself in a dark passageway with several exits. Carved from shadow-\n"+
 "rock by ome extremely strong magical force, these caves exude dark power.\n"+
 "You think you hear some sort of scratching... but the hard you listen, the\n"+
 "less you hear... there is nothing there... you hope.\n"+
 "Your mind is so fuzzy all you can do is wander in search of someplace more\n"+
 "imaginable to your bewildered logic. There is a way 'up' here.";
 
  }   }

init() {
  ::init();
  add_action("move_up","up");
}

move_up() {
  write("You climb out of the catacombs.\n");
  say(this_player()->query_name()+" climbs out of the catacombs.\n");
  move_object(this_player(),"/players/snow/shadows/fort/throne_room.c");
  command("look", this_player());
  return 1; }
