#include "/players/traff/closed/ansi.h"
int check;

id(str) {
    return str == "ttell";
}

reset(arg) {
  if(arg) return;
  check = 0;
}

silence(n) { check = n; }

long() {
    write("A Ttell to Traff\n");
    write("Usage: ttell or ttelle\n");
}

short() {
    return "ttell [Traff]";
}
drop() {return 1;}

query_auto_load() {
    return "/players/traff/closed/play/xtell.c:";
}

init() {
  add_action("ttell","ttell");
  add_action("ttelle","ttelle");
}
ttell (str)
{
string what, who;
  if(!str) {
    write("Ttell Traff what?\n");
  return 1; }
  if(!sscanf(str, "%s",what)) {
    write("Usage: ttell [what]\n");
  return 1;}
  if(!find_player("traff") || check == 1) {
    write("Traff is not here....\n");
  return 1; }
  tell_object(find_player("traff"),HIC+"[]"+"  "+
  NORM+capitalize(this_player()->query_real_name())+NORM+" ttells you: "+BLU+what+NORM+"\n");
  write("You ttell Traff : "+CYN+what+NORM+"\n");
  return 1; 
}

ttelle (str) {
string whats;
  if(!str) {
    write("You ttelle what to Traff?\n");
  return 1; }
  if(!sscanf(str, "%s",whats)) {
    write("Usasge: ttelle [what]\n");
  return 1; }
  if(!find_player("traff") || check == 1) {
    write("Traff is not here....\n");
  return 1; }
  tell_object(find_player("traff"),BLU+":)"+
  capitalize(this_player()->query_real_name())+" "+whats+NORM+"\n");
  write(CYN+"You "+whats+NORM+"\n");
  return 1; }
