/* Chat device for Kat set up to look like wedding ring. */
#include <ansi.h>

int check,li;

id(str) {
    return str == "band";
}

reset(arg) {
  if(arg) return;
  check = 0;
  li = 0;
}

silence(n) { check = n; }
query_silence() { return check; }

long() {
  write("A gothic wedding band made from a dark metal.\n");
  write("A large cat's eye agate is set into the ring.\n");
  write("ring_help for more info.\n");
}

short() {
return "A gothic wedding band ("+HIW+"Daranath"+NORM+")";
}
drop() {return 1;}
get() { return 0; }

extra_look() {return "Kat has half a pair of handcuffs about one wrist"; }
query_auto_load() {
    return "/players/daranath/closed/stuff/ring_kat.c:";
}

init() {
  add_action("ring_talk","ring");
  add_action("ring_emote","ringe");
  add_action("ring_echo","echo");
  add_action("ring_help","ring_help");
}

ring_help() {
write("You can do the following with your wedding ring.\n");
write("\nring talks to Daranath.\n");
write("ringe emotes to Daranath.\n");
write("echo sends an echo to Daranath.\n");
write("ring_help -> this listing.\n");
return 1; }

ring_talk(str) {
string what, who;
  if(!str) {
    write("Ring what?\n");
  return 1; }
  if(!sscanf(str, "%s",what)) {
    write("Usage: ring [what]\n");
  return 1;}
  if(!find_player("daranath") || check == 1) {
    write("Daranath is not logged in with you right now...\n");
  return 1; }
  tell_object(find_player("daranath"),HIR+"->"+" "+
  NORM+capitalize(this_player()->query_real_name())+NORM+" whispers to you: "+HIR+what+NORM+"\n");
  write("<"+HIW+"Ring"+NORM+"> You say: "+HIR+what+NORM+"\n");
  return 1; 
}

ring_emote(str) {
string whats;
  if(!str) {
   write("Ringe what?\n");
  return 1; }
  if(!sscanf(str, "%s",whats)) {
    write("Usasge: ringe [what]\n");
  return 1; }
  if(!find_player("daranath") || check == 1) {
    write("Daranath is not logged in with you right now....\n");
  return 1; }
  tell_object(find_player("daranath"),HIR+"->"+
  capitalize(this_player()->query_real_name())+" "+whats+NORM+"\n");
  write("<"+HIW+"Ring"+NORM+"> Kat "+HIR+""+whats+""+NORM+".\n");
  return 1; }

ring_echo(str) {
string echos;
  if(!str) { write("What do you want to echo?\n"); return 1; }
  if(!sscanf(str, "%s",echos)) {
    write("Usage: echo [what]\n");
  return 1; }
  if(!find_player("daranath") || check == 1) {
  write("Daranath is not logged in with you right now...\n");
  return 1; }
  tell_object(find_player("daranath"),"<Ring> "+echos+" \n");
  write("<"+HIW+"Ring"+NORM+"> "+HIW+""+echos+""+NORM+" \n");
return 1; 
}
