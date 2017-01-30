int cmd_bupdate()
{
  string file;
  file=basename(previous_object());
  command("bsave", this_player());
  write("Updating guild object ...");
  destruct(previous_object());
  move_object(clone_object(file), this_player());
  write("Success.\n");
  return 1;
}
