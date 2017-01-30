#include "../TRY.c"
  get() { return 0; }
  query_weight() { return 0; }
  query_value() { return 0; }

id(str) { return str == "poster"; }

short() { return "A poster of latest developments"; }
long() {
  sign_disp();
}

init() {
  add_action("read","read");
}

read (str) {
  if(!str || str != "poster") return 0;
  poka("ya");
  sign_disp();
  return 1;
}

sign_disp() {
  write("The brand new poster lists a few\n"+
        "important highlights:\n\n"+
  "KNOW THIS...\n"+
  "THINGS ARE GOING TO CHANGE.  ELEMENTAL TOWER WILL BE GONE SOON\n"+
  "A WHOLE NEW WORLD WILL OPEN SOON!!!!\n");
}
