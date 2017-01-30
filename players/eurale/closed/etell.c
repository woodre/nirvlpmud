#include "/players/eurale/closed/ansi.h"
int check,li;

id(str) {
    return str == "etell";
}

reset(arg) {
  if(arg) return;
  check = 0;
  li = 0;
}

silence(n) { check = n; }
query_silence() { return check; }
listen(a) { li = a; }

long() {
  write("\nAn {E}tell to Eurale... \n");
  write("Usage: 'etell' to talk, 'etelle' to emote\n");
}

short() {
  return HIC+"{E}tell"+NORM; }

drop() {return 1;}
get() { return 0; }

/*  for autoload, add the following two lines: */
/*  query_auto_load() {  */
/*  return "/players/eurale/closed/etel.c:"; }  */

init() {
  add_action("etell","etell");
  add_action("etelle","etelle");
}

etell(str) {
string what, who;
  if(!str) {
	write("Etell Eurale what?\n");
  return 1; }
  if(!sscanf(str, "%s",what)) {
    write("Usage: etell [what]\n");
  return 1;}
  if(!find_player("eurale") || check == 1) {
    write("Eurale is not here....\n");
  return 1; }
tell_object(find_player("eurale"),HIC+
  "{E} "+capitalize(this_player()->query_real_name()) + " etells you: "+
  NORM + what + "\n");
  write("You etell Eurale : "+HIC+what+NORM+"\n");
  return 1; 
}

etelle (str) {
string whats;
  if(!str) {
    write("You etelle what to Eurale?\n");
  return 1; }
  if(!sscanf(str, "%s",whats)) {
    write("Usasge: etelle [what]\n");
  return 1; }
  if(!find_player("eurale") || check == 1) {
    write("Eurale is not here....\n");
  return 1; }
  tell_object(find_player("eurale"),HIC+"{E} "+
  capitalize(this_player()->query_real_name())+" "+whats+NORM+"\n");
  write(HIC+"You "+whats+" at Eurale"+NORM+"\n");
  return 1; }

