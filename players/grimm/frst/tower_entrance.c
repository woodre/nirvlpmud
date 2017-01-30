search() {
  if(present("gargoyle")) {
    write("The gargoyles won't let you!!!!\n");
    return 1;
  }
  write("You find a passage leading down!!\n");
  down();
  return 1;
}
down() {
   write("Being the adventuresome person you are you decide to take it.\n");
   this_player()->move_player("down#players/grimm/frst/forest40");
}
