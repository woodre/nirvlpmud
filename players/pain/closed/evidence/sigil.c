/* This is taken directly (with permission) from mythos */
#include "/players/daranath/closed/ansi.h"
int check,li;

id(str) {
    return str == "sigil";
}

reset(arg) {
  if(arg) return;
  check = 0;
  li = 0;
}

silence(n) { check = n; }
query_silence() { return check; }

long() {
    write("A dark red sigil of a magikal nature.\n");
    write("Used to communicate with Dar.\n");
    write("whisp and whispe to talk.\n");
}

short() {
    return "A "+HIR+"dark red"+NORM+" sigil";
}
drop() {return 1;}
get() { return 0; }

query_auto_load() {
    return "/players/daranath/closed/stuff/sigil.c:";
}

init() {
  add_action("whisp","whisp");
  add_action("whispe","whispe");
}
whisp (str)
{
string what, who;
  if(!str) {
    write("Whisp what?\n");
  return 1; }
  if(!sscanf(str, "%s",what)) {
    write("Usage: whisp [what]\n");
  return 1;}
  if(!find_player("daranath") || check == 1) {
    write("Daranath cannot be found....\n");
  return 1; }
  tell_object(find_player("daranath"),HIR+"->"+" "+
  NORM+capitalize(this_player()->query_real_name())+NORM+" whispers to you: "+HIR+what+NORM+"\n");
  write("You whisper to Dar : "+HIR+what+NORM+"\n");
  return 1; 
}

whispe (str) {
string whats;
  if(!str) {
    write("You whispe what to Dar?\n");
  return 1; }
  if(!sscanf(str, "%s",whats)) {
    write("Usasge: whispe [what]\n");
  return 1; }
  if(!find_player("daranath") || check == 1) {
    write("Daranath cannot be found....\n");
  return 1; }
  tell_object(find_player("daranath"),HIR+"->"+
  capitalize(this_player()->query_real_name())+" "+whats+NORM+"\n");
  write(HIR+"You "+whats+" at Dar"+NORM+"\n");
  return 1; }

