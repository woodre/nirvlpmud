
string owner;

id(str) { return str == "burrow"; }
reset() { set_light(1); }

set_owner(str) { owner = str; }
query_owner() { return owner; }

short() {
  if(owner) return capitalize(owner) + "'s wombat burrow [no visible exits]";
  else return "Nobody's wombat burrow";
}

long() {
    if(owner) {
      write("This is the burrow of " + capitalize(owner) + ".\n"+
      "There is nothing really special about it, since it is just a hole in\n"+
      "the ground somewhere, but it's warm and cozy in here.\n");
    } else write("This is just some hole in the ground that someone has dug.\n");

  write("There is one obvious exit: up.\n");

}

init() {
  add_action("up","up");
  add_action("nodig","dig");
}

up() {
  write("You stick your head out of the burrow and peer around.\n");
  this_player()->move_player("up#room/wild1");
  return 1;

}

nodig() {
  write("You are left in a steep bogglement.\n");
    return 1;
}
