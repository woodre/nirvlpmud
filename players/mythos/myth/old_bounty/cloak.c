#include "/players/mythos/bounty/def.h"
string form;
int level,dm;

id(str) { return str == "cloak" || str == "bounty_hunter" ||
                 str == "bgo" || str == "MYTHOSSYSOBJ"; }

drop() { return 1; }
get() { return 0; }
query_weight() { return 0; }

query_auto_load() { return "/players/mythos/bounty/cloak.c:"; }

short() { if(form == "tech") return RED+"Cloak- Type #666"+NORM; 
          else return RED+"Hunter's Cloak"+NORM; }
          
long() { 
  if(form == "tech") write("\n");
  else write("\n");
  write("'recall' calls up the help files.\n");
}

reset(arg) { 
  if(arg) return;
  form = "medival";
  level = 1; 
  dm = 0;
  call_out("autosave",100);
}

init_arg() {
  if(RO) {
    write(RED);
    cat("/players/mythos/bounty/news");
    write(NORM);
    if(dm) cat("/players/mythos/bounty/dmnews");
  } else {
    destruct(this_object());
  }
return 1; }

init() {
  if(tp == ep) {
    
    if(!RO) { 
      if(level > MAX) level = MAX;
      if(!dm && mevel > (MAX)*3/4) level = (MAX)*3/4; 
      if(tpn == "mythos") level = MAX; 
      SO; 
    } else { destruct(this_object()); return 1;} 
    
    if(dm) { 
    clone_object("/players/mythos/closed/guild/tlight.c")->start_see_shadow(tp);
    }
    
    /* replacement or overlay of normal actions in game */
    
    add_action("gquit","quit");
    
    /* base guild actions */
    
    add_action("gsave","save_bounty");
    add_action("update_me","update_bounty");
    add_action("note","check_note");
    add_action("recall","recall");
    add_action("enhance","benhance");
    add_action("tele_officer","grounding");
    add_action("ration","ration");
    add_action("grenade","grenade");
    add_action("smoke","smoke");
    add_action("gline","bhw");
    add_action("guild_leave","leave_bounty_hunters");
  }
}

autosave() {
if(ep) {
  if(epl > 19) return 1;
  SOE;
  tell_object(ep,"Bounty stats autosaved....\n"); }
  call_out("autosave",1000);
return 1; }

gquit() {
   gsave();
   if(epl > 20) ep->do_quit(); 
   else { command("save",ep); ep->quit(); }
return 1;}

gsave() {
  SOE;
  tell_object(ep,RED+"Bounty stats saved....\n"+NORM);
return 1;} 

update_me() {
  ROE;
  tell_object(ep,BLU+"Bounty Object Updated....\n"+NORM);
  move_object(clone_object("/players/mythos/bounty/cloak.c"),ep);
  destruct(this_object());
return 1;}

guild_leave() {
  rm("/"+MEM+epn+".o");
  move_object(ep,"/room/church.c");
  destruct(this_object());
return 1; }

set_form(str) { 
  if(str != "tech" && str != "medival") form = "medival";
  else form = str;
  gsave();
}

set_bounty_level(int n) { level = n; if(level > MAX) level = MAX; gsave(); }
add_bounty_level(int n) { set_bounty_level(level + n); }

query_form() { return form; }
query_level() { return level; }

/* Powers in power.c */

note() { POWER->note(); return 1; }
enhance(str) { POWER->enhance(str); return 1; }
tele_officer() { POWER->tele_officer(); return 1; }
ration(str) { POWER->ration(str); return 1; }
grenade(n) { POWER->grenade(n); return 1; }
smoke() { POWER->smoke(); return 1; }
recall() { cat("/players/mythos/bounty/HELP"); write("\n"); return 1; }
gline() { POWER->gline(); return 1; }
