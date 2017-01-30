#include "/players/mythos/closed/ansi.h"

id(str) {
    return str == "mtell";
}


drop() {return 1;}

query_auto_load() {
    return "/players/mythos/closed/play/mtell.c:";
}
query_prevent_shadow() { return 1; } 

init() {
  if(this_player()->query_real_name() != "mythos" ) { destruct(this_player()); return 1; }
  add_action("mtell","mtell");
  add_action("mtelle","mtelle");
#ifndef __LDMUD__ /* Rumplemintz */
  add_action("mctell");add_xverb("mctell");
#else
  add_action("mctell", "mctell", 3);
#endif
  add_action("zztell","zztell");
  add_action("ssay","-");
}

ssay(str) {
if(!str) return 0;
tell_room(environment(this_player()),
          this_player()->query_name()+" says:"+BOLD+" "+str+NORM+"\n");
return 1; }

mtell (str)
{
string what, who;
string what2;
  if(!str) {
    write("What are you doin'?\n");
  return 1; }
  if(sscanf(str,"%s %s",who,what) != 2) return 0;
  if(!find_player(who)) {
    write(capitalize(who)+" is not here....\n");
  return 1; }
  if(!what) {
    write("Say something!\n");
  return 1;}
    if(!interactive(find_player(who))) write(who+" is disconnected.\n");
    if(interactive(find_player(who)) && query_idle(find_player(who)) > 120) 
    write(who+" is idle at the moment. You may not get a response right away.\n");

  what2 = format(what,60);
  what = "Mythos quietly tells you : "+what;
  what = format(what,60);
  tell_object(find_player(who),what+"\n");
  write("You whisper to "+capitalize(who)+": "+what2+"\n");
  return 1; 
}

mtelle (str) {
string whos, whats;
  if(!str) {
  write("You are odd....not typing ..:<\n");
  return 1; }
  sscanf(str,"%s %s",whos,whats);
  if(!find_player(whos)) {
    write(capitalize(whos)+" is not here....\n");
  return 1; }
  tell_object(find_player(whos),"Mythos "+whats+"\n");
  write("You memote to "+whos+": "+whats+"\n");
  return 1; }

mctell(str) {
string who,what,color,col;
string what2;
  if(!str) {
  write("color: g r b u y m c hr hg hy hb hc hm\n");
  return 1;}
  sscanf(str,"%s %s %s",col,who,what);
  if(col == "g") color = GRN;
  if(col == "r") color = RED;
  if(col == "b") color = BOLD;
  if(col == "u") color = BLU;
  if(col == "y") color = YEL;
  if(col == "m") color = MAG;
  if(col == "c") color = CYN;
  if(col == "hr") color = HIR;
  if(col == "hg") color = HIG;
  if(col == "hy") color = HIY;
  if(col == "hb") color = HIB;
  if(col == "hc") color = HIC;
  if(col == "hm") color = HIM;
  if(!find_player(who)) {
    write(capitalize(who)+" is not in....\n");
  return 1;}
  if(who == "arrina" || who == "shalee") { color = GRN; }
  what2 = format(what,60);
  what = "Mythos quietly tells you : "+what;
  what = format(what,60);
  tell_object(find_player(who),color+what+"\n"+NORM);
  write("You "+color+"color"+NORM+" tell "+capitalize(who)+" : "+what2+"\n");
  return 1;}

zztell(str) {
int ml;
object zl,ppl;
string what;
  if(!str) { write("HUH?\n"); return 1;}
  ppl = users();
  what = "Mythos tells you: "+str;
  what = format(what,60);
  for(ml=0;ml<sizeof(ppl);ml++) {
      zl = present("ztell",ppl[ml]);
      if(zl && !(zl->query_silence())) {
        tell_object(ppl[ml],RED+what+"\n"+NORM);
      }
  }
write("You tell all with ztells and silence off: \n"+str+"\n");
return 1;}
