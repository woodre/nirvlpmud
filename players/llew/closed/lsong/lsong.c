#include "/players/llew/closed/ansi.h"
int check;

id(str) {
    return str == "lsong";
}

reset(arg) {
  if(arg) return;
  check = 0;
}

silence(n) { check = n; }

long() {
    write("A song from Llew.  If you listen closely and concentrate,\n");
    write("he may be able to hear your thoughts...\n");
    write("Usage: lsong or lsonge\n");
    write("To ignore the song type \"deafen\"\n");
}

drop() {return 1;}

query_auto_load() {
   return "players/llew/closed/lsong/lsong.c:";
}

init() {
  add_action("deafen","deafen");
  add_action("lsong","lsong");
  add_action("lsonge","lsonge");
  write(BOLD+"*"+NORM+GRN+"\tA song softly drifts through your thoughts...\t"+NORM+BOLD+"*\n"+NORM);
}
lsong(str) {
   object *people;
   int x,si;
   string what, who;
  if(!sscanf(str, "%s",what)) {
    write("Usage: lsong [what]\n");
  return 1;}
   if(this_player()->query_real_name() == "llew") {
      for(x=0,people=users(),si=sizeof(people);si > x;x++) {
         if(present("lsong",people[x])) {
         tell_object(people[x],GRN+"-,-{"+RED+"@ "+HIW+"Llew"+NORM+RED+" @"+GRN+"}-`- "+NORM+format(what+"\n",60));
         }
      }
      return 1;
   }
  if(!str) {
     write("sing what?\n");
  return 1; }
  if(!find_player("llew") || check == 1) {
    write("Llew is not here....\n");
    if(this_player()->query_real_name() == "mischief") {
      write("But he is probably thinking of you right now, Teri Sue. :)\n");
    }
  return 1; }
   tell_object(find_player("llew"),GRN+"-,-{"+RED+"@ "+HIW+capitalize(this_player()->query_real_name())+" "+NORM+RED+"@"+GRN+"}-`- "+NORM+format(what+"\n",60));
   write(GRN+"-,-{"+RED+"@ "+HIW+this_player()->query_name()+" "+NORM+RED+"@"+GRN+"}-`- "+NORM+format(what+"\n",60));
  return 1; 
}

lsonge (str) {
string whats;
  if(!str) {
    write("You lsonge what to Llew?\n");
  return 1; }
  if(!sscanf(str, "%s",whats)) {
    write("Usage: lsonge [what]\n");
  return 1; }
  if(!find_player("llew") || check == 1) {
    write("Llew is not here....\n");
  return 1; }
   tell_object(find_player("llew"),GRN+"-,--`-{"+RED+"@ "+NORM+capitalize(this_player()->query_real_name())+" "+format(whats+"\n",60));
   write(GRN+"-,--`-{"+BOLD+RED+"@ "+NORM+capitalize(this_player()->query_real_name())+" "+format(whats,60)+"\n");
  return 1; }

deafen() {
write("\n"+BOLD+pad("",79,'~')+"\n\n"+RED+"\tYou stop listening to the beautiful song.\n\tYour heart longs to flow with the lost melodies of life.\n\tYour deaf ears will never hear the same.\n\n"+NORM+BOLD+pad("",79,'~')+"\n\n"+NORM);
   destruct(this_object());
   return 1;
}
