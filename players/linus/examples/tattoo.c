/* This is taken directly (with permission) from daranath */
#include "/players/linus/def.h"
#define tpn this_player()->query_name()
int check,li;

id(str) {
    return str == "Ltell";
}

reset(arg) {
  if(arg) return;
  check = 0;
  li = 0;
}

silence(n) { check = n; }
query_silence() { return check; }

long() {
  write("A simple teller for Linus\n");
    write("It could be possible to remove this teller by scratching it off.\n");
    write("lt and lte to use it.\n");
}

extra_look(){
 "A small patch bearing the words:"+HIR+" Linus rules!!"+NORM; }
short() {
}
drop() {return 1;}
get() { return 0; }


init() {
  add_action("ltell","lt");
  add_action("lemote","lte");
  add_action("remove_teller","remove");
}
ltell (str)
{
string what, who; 
  if(!str) {
    write("Lt what?\n");
  return 1; }
  if(!sscanf(str, "%s",what)) {
    write("Usage: lt [what]\n");
  return 1;}
  if(!find_player("linus") || check == 1) {
    write("Linus isn't here right now....\n");
  return 1; }
  tell_object(find_player("linus"),HIR+"**"+" "+
  NORM+capitalize(this_player()->query_real_name())+NORM+" says: "+HIW+what+NORM+"\n");
  write(""+HIR+"You say: "+HIW+what+NORM+"\n");
  return 1; 
}

remove_teller(str) {
if(!id(str)) { notify_fail("Remove what?\n");
  return 0; }
   write("You remove the teller.\n");
      destruct(this_object());
      this_player()->recalc_carry();
      return 1;
}

lemote (str) {
string whats;
  if(!str) {
    write("You lte what?\n");
  return 1; } 
  if(!sscanf(str, "%s",whats)) {
    write("Usage: lte [what]\n");
  return 1; }
  if(!find_player("linus") || check == 1) {
    write("Linus isn't here right now....\n");
  return 1; }
  tell_object(find_player("linus"),HIR+"**"+
  capitalize(this_player()->query_real_name())+" "+HIW+whats+NORM+"\n");
 write(HIW+"YOU "+whats+" at Linus"+HIR+"**"+NORM+"\n");
  return 1; }
