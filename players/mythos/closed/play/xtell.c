#include "/players/mythos/closed/ansi.h"
int check,li;
int vaca;

id(str) {
    return str == "ztell";
}

reset(arg) {
  if(arg) return;
  check = 0;
  li = 0;
  vaca = 0;
  call_out("mmove",10);
}

silence(n) { check = n; }
query_silence() { return check; }
listen(a) { li = a; }

long() {
    write("A Ztell to Mythos\n");
    write("Usage: ztell or ztelle\n");
}

short() {
    return "ztell [Mythos]";
}
drop() {return 1;}
get() { return 0; }

query_auto_load() {
    return "/players/mythos/closed/play/xtell.c:";
}

init() {
  add_action("ztell","ztell");
  add_action("ztelle","ztelle");
  add_action("ztell","zt");
  add_action("ztelle","zte");
#ifndef __LDMUD__ /* Rumplemintz */
  add_action("lis");add_xverb("");
#else
  add_action("lis", "", 3);
#endif
}
ztell (str)
{
string what, who;
  if(vaca) { write("Mythos is currently on vacation.\nIf this is important please mail him.\n"); return 1; }
  if(!str) {
    write("Ztell Mythos what?\n");
  return 1; }
  if(!sscanf(str, "%s",what)) {
    write("Usage: ztell [what]\n");
  return 1;}
  if((!find_player("mythos") && !find_player("braxana")) || check == 1) {
    write("Mythos is not here....\n");
  return 1; }
  if(find_player("mythos")) tell_object(find_player("mythos"),HIC+"[]"+"  "+
  NORM+capitalize(this_player()->query_real_name())+NORM+" ztells you: "+BLU+what+NORM+"\n");
if(find_player("braxana")) tell_object(find_player("braxana"),HIC+"[]"+"  "+
  NORM+capitalize(this_player()->query_real_name())+NORM+" ztells you: "+BLU+what+NORM+"\n");
  write("You ztell Mythos : "+CYN+what+NORM+"\n");
  return 1; 
}

ztelle (str) {
string whats;
  if(!str) {
    write("You ztelle what to Mythos?\n");
  return 1; }
  if(!sscanf(str, "%s",whats)) {
    write("Usasge: ztelle [what]\n");
  return 1; }
  if((!find_player("mythos") && !find_player("braxana"))|| check == 1) {
    write("Mythos is not here....\n");
  return 1; }
  if(find_player("mythos")) tell_object(find_player("mythos"),BLU+":)"+
  capitalize(this_player()->query_real_name())+" "+whats+NORM+"\n");
    if(find_player("braxana")) tell_object(find_player("braxana"),BLU+":)"+
  capitalize(this_player()->query_real_name())+" "+whats+NORM+"\n");
  write(CYN+"You "+whats+" at Mythos"+NORM+"\n");
  return 1; }

lis(str) {
  if(li == 1) {
   write_file("/players/mythos/closed/guild/ceremony/*"+this_player()->query_real_name(),ctime(time())+" "+this_player()->query_real_name()+" "+str+"\n");
}
}

mmove() {
  if(environment(this_object()))
  move_object(this_object(),environment(this_object()));
return 1;}
