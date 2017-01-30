int do_shine(string str) {
  notify_fail("Shine what?\n");
  if(!str || str!="pendant") return 0;
  MYOB->guild_save();
  write("You spend a moment re-examining your healer abilities.\n");
  destruct(present(GUILD_ID,TP));
  move_object(clone_object(PATH+"gob"),TP);
  return 1;
}
