
short() {return "The lair of Queen Regis";}

long() {
  write("You have entered the Lair undetected due to your disquise as an\n");
  write("Invid shock trooper. You see Queen Regis near the center of the\n");
  write("Lair generating more new Invids. She glances at you and continues\n");
  write("to generate. At the top of the Lair is a huge gaping hole which\n");
  write("you figure is probably how she gets in and out of this place.\n");
 write("    There are two obvious exits: down and south\n");
}

reset(arg) {
if(!present("regis")) {
move_object(clone_object("players/cyrex/quest/regis"), this_object());
}
  if (arg) return;

  set_light(1);
}


init() {
if(!present("shockplate",this_player())) {
write("As soon as you see Regis, you cringe and run away!\n\n");
move_object(this_player(), "/players/cyrex/quest/shockroom");
return 1;
}
add_action("down", "down");
add_action("south", "south");
}
down() {
this_player()->move_player("down#players/cyrex/quest/shockroom");
return 1;
}
south() {
if(present("regis")) {
write("Regis says: where do you think your going my little Invid?\n");
return 1;
}
destruct(present("amulokt", this_player()));
this_player()->move_player("south#room/church");
return 1;
}

