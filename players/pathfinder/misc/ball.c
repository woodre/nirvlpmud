  id(str) { return str == "ball" || str == "crystal ball"; }
short() { return "A beautiful crystal ball"; }
long() {
  write("A Beautiful Crystal ball that you just want to 'kick'.\n");
  }

init() {
  add_action("kickme","kick");
}

get() { return 1; }
drop() { return 1; }
kickme() {
  if (this_player()) {
  this_player()->raise_stamina(10000);
  this_player()->raise_strength(1000);
  this_player()->raise_magic_aptitude(10000);
  destruct(this_object());
  return 1;
}
}
