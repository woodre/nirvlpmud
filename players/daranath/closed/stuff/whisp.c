#include <ansi.h>
#define tp this_player()

id(str) { return str == "teller"; }

drop() { return 1; }

init() {
   if(tp->query_level() < 60) destruct(this_object());
  add_action("tell","wtell");
}

tell(str) {
object targ;
int h;
string msg,who;

if(!str) { write("wtell <who> <msg>\n"); return 1; }
if(sscanf(str,"%s %s",who,msg) != 2) return 0;
  if(targ = find_player(who)) {
   tell_object(targ,capitalize(tp->query_real_name())+" whispers softly: "+HIW+msg+NORM+"\n");
     write("You whisper to "+who+": "+msg+"\n");
  return 1; }
  else {
     targ = users();
   for(h=0;h<sizeof(targ);h++) {
     if(targ[h]->query_real_name() == who) {
     tell_object(targ[h],capitalize(tp->query_real_name())+" whispers softly: "+msg+"\n");
      write("You whisper to "+who+": "+msg+"\n");
     return 1; }
   }}
    write(who+" is not in game\n");
return 1; }
