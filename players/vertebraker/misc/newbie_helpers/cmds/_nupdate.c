int main() {
  destruct(previous_object());
  move_object(clone_object("/players/vertebraker/misc/newbie_helpers/noob"), this_player());
  write("updated newbie_helper object.\n");
  return 1;
}
