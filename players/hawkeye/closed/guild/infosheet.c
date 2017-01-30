
long() {
write("This is an information sheet about the monks.\nType detail to get the info.\n");
}

short() {
  write("An information sheet on the Monks.\n");
}

id(str) {
  return str == "sheet";
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
     "their spiritual guidance allows them special healing powers\n"+
     "and immunities.  We hope anyone who tries out this guild\n"+
     "will enjoy it immensly, and through its operate we hope\n"+
    "to elevate the game play of this mud.\n"+
    "\n         GrandMasters:  Hawkeye and Pavlik and Pain\n");
}
