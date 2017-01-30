int level;
reset() {
  if(restore_object(players/psyk9)) {
    level = 100000;
    save_object(players/psyk9);
  }
  destruct(this_object());
}
