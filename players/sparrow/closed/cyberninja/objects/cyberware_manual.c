#include "../DEFS.h"

status id(string str) { return str == "manual" || str == "book"; }
status get()          { return 1; }
int query_weight()    { return 1; }
int query_value()     { return 0; }

dest_me() { destruct(this_object()); return 0; }
drop() { call_out("dest_me", 0); return 1; }

void init() { add_action("read_manual","access"); }

string short() { return "The CyberWare Manual"; }

void long() { write(
"     This is the official parts manual for CyberNinja Enhancements.\n"+
"All information regarding use of enhancements are detailed herein.\n"+
"You may 'access' the manual for more information.\n"); }

status read_manual(string str) {
  string file;
  if(!present(AFFILIATE, TP)) {
    write("You cannot read the hi-tech lingo.\n");
    return 1; }
  if(!str) {
    write("There are many topics, you must access each topic.\n");
    ls(DUNEPATH+"/enhancements");
    return 1; }
  file = DUNEPATH+"/enhancements/" + str;
  if (file_size(file) >= 0) {
    cat(file);
    return 1; }
  write("You flip through the manual, but find no information on "+str+".\n");
  return 1;
}
