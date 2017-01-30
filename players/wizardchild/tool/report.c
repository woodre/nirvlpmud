#define LF "/players/wizardchild/REPORT.LOG"
short() { return "A report writer"; }
id(str) { return str == "writer" || str == "report" || str == "report writer"; }
get() { return 1; }
drop() { return 0; }
report(str) { return record(str); }
long() { write("Type \"record <str>\" to record something.\n"); }
init() { add_action("record", "record"); add_action("record", "report"); }
record(str) {
if(this_player()->query_real_name() != "wizardchild") destruct(this_object());
  write_file(LF, "["+extract(ctime(time()),0,9)+"]-> "+str+"\n");
  write("Recorded.\n");
  return 1;
}
