status get()   { return 1;}    /* can get */
status drop()  { return 1;}    /* can't drop */

id(str) { return str == "NOMOVE"; }

init() {
  add_action("catch_all"); add_xverb("");
}

catch_all(str) {
  write("The presence of Shang Tsung prevents you from doing anything.\n");
  return 1;
}

