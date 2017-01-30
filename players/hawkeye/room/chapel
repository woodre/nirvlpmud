
/* The Chapel of Love */

short() { 
  return "Chapel of Love";
}

long(str) {
  if(!str) {
    write(format("You are a small chapel, the walls dressed with pink " +
     "silk. Two pews face a lectern at the front of the room, a statue " +
     "of cupid being prominent. You note a portrait of Elvis on one of " +
     "the walls.\n     There is one obvious exit: south.\n"));
    return 1;
  }
  if(str=="pew" || str=="pews")
    write(format("This place is so small it could only fit two!\n"));
  else if(str=="statue" || str=="cupid")
    write(format("It is a marble likeness of the chubby cherabim.\n"));
  else if(str=="elvis" || str=="portrait")
    write("Is this guy dead or what?\n");
  return 1;
}

id(str) { 
  return str=="elvis" || str=="pews" || str=="pew" || str=="cupid" ||
   str=="statue" || str=="portrait";
}

init() {
  add_action("south", "south");
}

south() {
  this_player()->move_player("south#room/yard");
  return 1;
}

reset(arg) {
  object ob;
  if(!present("minister")) {
    ob=clone_object("players/bastion/monster/minister");
    move_object(ob, this_object());
  }
  if(arg) return;
  set_light(1);
}
