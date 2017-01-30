status get()   { return 1;}    /* can get */
status drop()  { return 1;}    /* can't drop */

id(str) { return str == "NOMOVE"; }

init() {
#ifndef __LDMUD__
  add_action("catch_all"); add_xverb("");
#else
  add_action("catch_all", "", 3);
#endif
}

catch_all(str) {
  write("The presence of Shang Tsung prevents you from doing anything.\n");
  return 1;
}

