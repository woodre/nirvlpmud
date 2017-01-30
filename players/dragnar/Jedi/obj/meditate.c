status get()   { return 1;}    /* can get */
status drop()  { return 1;}    /* can't drop */

id(str) { return str == "meditate_object_jedi"; }

init() {
  add_action("catch_all"); add_xverb("");
}

de_meditate() {
  write("You come out of meditation.\n");
  destruct(this_object());
  return 1;
}

catch_all(str) {
  if(str == "awaken") {
    de_meditate();
    return 1;
  }
  write("You are in deep meditation.\n");
  return 1;
}
