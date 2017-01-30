#define ME capitalize(this_player()->query_real_name())

object fd;

reset(arg) {
  if(arg) return;

  fd = find_object("players/pavlik/armor/ralston_necklace");

  if(!fd) {
    tell_object(find_player("pavlik"), "No necklace found.\n");
  }
  else {
    tell_object(find_player("pavlik"), "The necklace was found.\n");
  }
}

short() { return "A test object"; }

long() {
  write(
  "This is a test item for find_object.\n"+
  "Use: ftest <objname> to use.\n");
  return;
}

id(str) { return (str == "test" || str == "test2"); }

init() {
  add_action("ftest","ftest");
}

ftest(str) {
  object obj;

  if(!str) {
    write("Find what?\n");
    return 1;
  }

  obj = find_object(str);

  if(!obj) {
    write(str+" was not found.\n");
    return 1;
  }

  if(!environment(obj)) {
    write(str+" was found but has no environment.\n");
    return 1;
  }

  write(str+" found at: "+environment(obj)->short()+"\n");
  return 1;
}

