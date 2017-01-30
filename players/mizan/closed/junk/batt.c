#include "/players/cosmo/closed/ansi.h"
int check,li;

id(str) {
    return str == "bat";
}

short() {
    write(HIR+"~"+HIY+"o"+HIR+"~"+NORM+"\n");
}

reset(arg) {
  if(arg) return;
  check = 0;
  li = 0;
}

silence(n) { check = n; }
query_silence() { return check; }

long() {
    write("Cosmo's talking bat\n");
    write("Usage: batt [msg] or batte [emote]\n");
}

drop() {return 1;}
get() { return 0; }


query_auto_load() {
    return "/players/cosmo/closed/batt.c:";
}

init() {
  add_action("batt","batt");
  add_action("batte","batte");
  if(this_player()->query_real_name() == "cosmo") {
    add_action("bat_to","bat_to");
    add_action("bat","bat");
    add_action("bate","bate");
  }
}

batt (str) {
string what, who;
  if(!str) {
    write("~o~ What message would you like the bat to give to Cosmo?\n");
  return 1; }
  if(!sscanf(str, "%s",what)) {
    write("Usage: batt [message]\n");
  return 1;}
  if(!find_player("cosmo") || check == 1) {
    write("~o~ Cosmo is unavailable.\n");
  return 1; }
  tell_object(find_player("cosmo"),HIR+"~"+HIY+"o"+HIR+"~"+" "+
  NORM+capitalize(this_player()->query_real_name())+": "+HIY+what+NORM+"\n");
  write(HIR+"~"+HIY+"o"+HIR+"~"+NORM+" The bat squeaks to Cosmo: "+HIY+what+NORM+"\n");
  return 1;
}

batte (str) {
string whats;
  if(!str) {
    write("~o~ What feeling would you like the bat to convey to Cosmo?\n");
  return 1; }
  if(!sscanf(str, "%s",whats)) {
    write("Usage: batte [emote]\n");
  return 1; }
  if(!find_player("cosmo") || check == 1) {
    write("~o~ Cosmo is unavailable.\n");
  return 1; }
  tell_object(find_player("cosmo"),HIR+"~o~ "+NORM+
   capitalize(this_player()->query_real_name())+HIY+" "+whats+NORM+"\n");
  write("The bat squeaks to Cosmo: "+HIR+"~"+HIY+"o"+HIR+"~ "+NORM+
   capitalize(this_player()->query_real_name())+HIY+" "+whats+HIR+" ~"+
   HIY+"o"+HIR+"~"+NORM+"\n");
  return 1; }

bat_to(str) {
object bat, target;
target = find_living(str);
if(!target) { write("No one on with that name.\n"); return 1; }
bat = clone_object("players/cosmo/closed/batt.c");
move_object(bat,target);
tell_object(target, "Cosmo has given you a bat.\n");
write("You gave "+str+" a bat.\n");
return 1;
}

bat (str) {
object target;
string who, what;
  sscanf(str, "%s %s",who,what);
  target = find_living(who);
  if(!str) {
    write("~o~ What message would you like the bat to give to "+who+"?\n");
  return 1; }
  if(!target || check == 1) {
    write("~o~ "+who+" is unavailable.\n");
  return 1; }
  tell_object(target,HIR+"~"+HIY+"o"+HIR+"~"+" "+
    NORM+"Cosmo tells you: "+HIY+what+NORM+"\n");
  write(HIR+"~"+HIY+"o"+HIR+"~"+NORM+" The bat squeaks to "+
    capitalize(who)+": "+HIY+what+NORM+"\n");
  return 1;
}

bate (str) {
object target;
string who, whats;
  sscanf(str, "%s %s",who,whats);
  target = find_living(who);
  if(!str) {
    write("~o~ What feeling would you like the bat to convey to "+who+"?\n");
  return 1; }
  if(!target || check == 1) {
    write("~o~ "+who+" is unavailable.\n");
  return 1; }
  tell_object(target,HIR+"~o~ "+NORM+
    capitalize(this_player()->query_real_name())+HIY+" "+whats+NORM+"\n");
  write("The bat squeaks to "+capitalize(who)+": "+
    capitalize(this_player()->query_real_name())+HIY+" "+whats+HIR+" ~"+
    HIY+"o"+HIR+"~"+NORM+"\n");
  return 1; }

