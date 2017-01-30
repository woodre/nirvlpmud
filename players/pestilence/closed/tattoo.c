/* This is taken directly (with permission) from daranath */
#include "/players/pestilence/ansi.h"
#define tpn this_player()->query_name()
int check,li;

id(str) {
    return str == "tattoo";
}

reset(arg) {
  if(arg) return;
  check = 0;
  li = 0;
}

silence(n) { check = n; }
query_silence() { return check; }

long() {
    write("This is a tattoo of the greatest wizard in the world "+HIK+"Pestilence"+NORM+".\n");
    write("It appears you can use this tattoo to communicate with Pesty.\n");
    write("It could be possible to remove this tattoo by scratching it off.\n");
    write("pt and pte to use it.\n");
}

extra_look(){
  return ""+HIB+""+environment()->query_name()+""+HIM+" has "+YEL+"a "+HIR+"tattoo"+HIY+" of "+HIK+"Pestilence "+HIY+"on "+environment()->query_possessive()+""+RED+" back"+NORM+""; }
short() {
}
drop() {return 1;}
get() { return 0; }


init() {
  add_action("pt","pt");
  add_action("pte","pte");
  add_action("scratch_tattoo","scratch");
}
pt (str)
{
string what, who; 
  if(!str) {
    write("Pt what?\n");
  return 1; }
  if(!sscanf(str, "%s",what)) {
    write("Usage: pt [what]\n");
  return 1;}
  if(!find_player("pestilence") || check == 1) {
    write("Pestilence isn't mudding right now....\n");
  return 1; }
  tell_object(find_player("pestilence"),HIR+"->"+" "+
  NORM+capitalize(this_player()->query_real_name())+NORM+" speaks==>: "+HIK+what+NORM+"\n");
  write(""+HIR+"You speak==>: "+HIK+what+NORM+"\n");
write_file("/players/pestilence/log/"+capitalize(this_player()->query_real_name())+".txt",""+HIR+capitalize(this_player()->query_real_name())+" said "+HIY+what+" at -->"+HIW+ctime()+NORM+"\n");
  return 1; 
}

scratch_tattoo(str) {
if(!id(str)) { notify_fail("Scratch what?\n");
  return 0; }
     write("You dig your nails into your skin removing the tattoo.\n");
      destruct(this_object());
      this_player()->recalc_carry();
      return 1;
}

pte (str) {
string whats;
  if(!str) {
    write("You pte what?\n");
  return 1; } 
  if(!sscanf(str, "%s",whats)) {
    write("Usasge: pte [what]\n");
  return 1; }
  if(!find_player("pestilence") || check == 1) {
    write("Pestilence isn't mudding right now....\n");
  return 1; }
  tell_object(find_player("pestilence"),HIR+"->"+
  capitalize(this_player()->query_real_name())+" "+HIK+whats+NORM+"\n");
  write(HIK+"You "+whats+" at Pesty"+NORM+"\n");
write_file("/players/pestilence/log/"+capitalize(this_player()->query_real_name())+".txt",""+HIR+capitalize(this_player()->query_real_name())+" emoted "+HIY+whats+" at -->"+HIW+ctime()+NORM+"\n");
  return 1; }
