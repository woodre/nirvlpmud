int main(string str){
  write("Updating guild object...\n");
  destruct(previous_object());
  move_object(clone_object("/players/x/guilds/knights/gob"), this_player());
  write("Ok.\n");
  return 1;
}
