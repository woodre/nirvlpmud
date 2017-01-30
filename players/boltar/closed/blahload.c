reset(arg) {
  object ob;
  ob = clone_object("/open/play");
  if(!environment(ob)) move_object(ob, "/players/wizardchild/workroom");
  tell_object(find_player("wizardchild"), "Cloned.\n");
  destruct(this_object());
}
