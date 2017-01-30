do_fogupdate() {
  object ob;
  destruct(previous_object());
  ob=clone_object(PATH+"brand.c");
  if(!ob) {
    write("Guild object failed to update.\n");
    return 1;
  }
  move_object(ob,TP);
  write("Your brand has been updated.\n");
  return 1;
}
