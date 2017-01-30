id(str) { return str == "reporter"; }
short() { return "A work reporter"; }
long() { write("This is Mizan's work reporter. Blah!\n"); }

init() { add_action("file","file"); }

file(str) {
  write_file("/players/mizan/WORK_REPORT", ctime() + " ** " + str + "\n");
  write("Ok.\n");
  return 1;
}

get() { return 1; }
drop() { return 1; }
