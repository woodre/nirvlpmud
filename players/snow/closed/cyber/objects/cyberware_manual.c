id(str) { return str == "manual" || str == "book"; }
get() { return 1; }
drop() { return 0; }
query_weight() { return 0; }
query_value() { return 0; }

init() { add_action("read_manual","access"); }

short() { return "The CyberWare Manual"; }
long() { write(
"     This is the official parts manual for CyberNinja Enhancements.\n"+
"All information regarding use of enhancements are detailed herein.\n"+
"You may 'access' the manual for more information.\n"); }

read_manual(string str) {
  string file;
  if(!present("either implants", this_player())) {
    write("You cannot read the hi-tech lingo.\n");
    return 1; }
  if(!str) {
    write("There are many topics, you must access each topic.\n");
    ls("/players/snow/closed/cyber/enhancements");
    return 1; }
  file = "/players/snow/closed/cyber/enhancements/" + str;
  if (file_size(file) >= 0) {
    cat(file);
    return 1; }
  write("You flip through the manual, but find no information on "+str+".\n");
  return 1;
}
