
long() {
  return
write("This is the Entrance to the Monks Guild.\n"+
"The commands avialable at this location are:\n"+
"   join      join the monks guild\n"+
"  leave      leave the monks guild\n"+
"  detail     get details about the monks guild\n"+
"  help ranks    get info on Monk guild ranks\n"+
"\n");
}

short() {
  write("A small sign\n");
}

id(str) {
  return str == "sign";
}

get() {
  return 0;
}

init() {
add_action("detail","detail");
}

detail() {
  write("This is the new Monks Guild.  A Monk is one who seeks\n"+
     "physical and spiritual perfection.  Because of this, one\n"+
     "who is a Monk, might find that thier own body is the best\n"+
     "weapon, and best armor avialable.  A Monk's fighting style\n"+
     "includes a lot of Martial Arts styles and moves, and\n"+
     "thier spiritual guidance allows them special healing powers\n"+
     "and immunities.  We hope anyone who tries out this guild\n"+
     "will enjoy it immensly, and through its operate we hope\n"+
    "to elevate the game play of this mud.\n"+
    "\n         GrandMasters:  Hawkeye and Pavlik\n");
}
