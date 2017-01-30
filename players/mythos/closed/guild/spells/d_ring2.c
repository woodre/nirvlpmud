#include "/players/mythos/closed/guild/def.h"
string owner, trapped;
string ob;
static int wer, cde;
static string msg, mmsg;
id(str) { return str == "demonring" || str == "ring" || str == "demon ring" ||
                 str == "emerald" || str == "emerald ring"; }

reset(arg) {
  if(arg) return;
  msg = "Demon Ring "+GRN+"[Emerald]"+NORM;
  mmsg = "Demon Ring "+GRN+"[Emerald]"+NORM;
  wer = 0;
  cde = 0;
 call_out("decheck",20);
}

short(){return msg;}

long() {
write("A emerald ring of exquisite beauty.\n"+
      "If you look closely you can see "+trapped+" who\n"+
      "is trapped inside.\n\nType <help_d_ring> for powers.\n");
}

set_trap_path(str) { ob = str;}
set_owner(str) { owner = str;}
set_trapped(str) { trapped = str; }
query_owner() { return owner; }
query_trapped() { return trapped;}
query_trap_path() { return ob;}

drop() {return 0;}
get() { return 1;}
query_gsave() { return 1;}
query_save_flag() { return 0;}

init() {
  add_action("ddrop","drop");
  add_action("ggive","give");
  add_action("help_d","help_d_ring");
  add_action("rremove","remove");
  add_action("wwear","wear");
  add_action("chains","chains");
  add_action("meld","meld");
  add_action("demonic_essence","demonic_essence");
  add_action("release","release");
}

wwear(str) {
 if(!str) { write("What?\n"); return 1;}
 if( str == "demonring" || str == "ring" || str == "demon ring" ||
     str == "emerald" || str == "emerald ring" ) {
     if(wer == 0) {
     msg = mmsg + " <worn>";
     wer = 1;
     write("You wear the demon ring.\n");
     return 1;}
     write("You already wear the demon ring!\n");
     return 1;}
 }
 
rremove(str) {
 if(!str) { write("What?\n"); return 1;}
 if( str == "demonring" || str == "ring" || str == "demon ring" ||
     str == "emerald" || str == "emerald ring" ) {
     if(wer == 1) {
     msg = mmsg;
     wer = 0;
     write("You slip the demon ring off your finger.\n");
     return 1;}
     write("You already removed the demon ring!\n");
     return 1;}
}

ddrop(str) {
if(!str) { write("What?\n"); return 1;}
 if( str == "demonring" || str == "ring" || str == "demon ring" ||
     str == "emerald" || str == "emerald ring" ) {
     if(wer == 1) {
     msg = mmsg;
     wer = 0;
     write("You slip the demon ring off your finger.\n");
     } }
}

ggive(str) {
if(!str) { write("What?\n"); return 1;}
 if( str == "demonring" || str == "ring" || str == "demon ring" ||
     str == "emerald" || str == "emerald ring" ) {
     if(wer == 1) {
     msg = mmsg;
     wer = 0;
     write("You slip the demon ring off your finger.\n");
     } }
}

help_d() {
  write("\n"+"Note: The ring must be worn for most powers to work.\n"+
        "wear                 You may wear the ring\n");
  write("remove               You may remove the ring\n"+
        "help_d_ring          This help file\n"+
        "meld                 Melds minds together to allow xp to\n"+
        "                     go to only one person\n"+
        "chains               Locks target to the current room\n"+
        "demonic_essence      When your hp is low, demonic rage sets in\n"+
        "release              Releases trapped creature from ring\n");
return 1;}

decheck() {
int before;
object com, wep;
if(ep) {
if(epn == owner) {
com = ep->query_attack();
if(com && (call_other(com,"id","demon") || call_other(com,"id","avatar") ||
   call_other(com,"id","daemon") || epp || call_other(com,"id","spirit")) && 
   wer == 1 && cde == 0){
   before = ep->query_wc();
   wep = ep->query_weapon();
   cde = 1;
   ep->set_wc(before + random(3));
   write("The ring begins to glow softly with an evil light...\n");
   }
if(!com && cde == 1) {
  write("The ring stops glowing....\n");
  if(ep->query_weapon() == wep) {
  ep->set_wc(before); }
}
if(ep->query_crime()) {
ep->add_spell_point(random(6)); }
else { ep->add_spell_point(-random(6)); }
if(ep->query_alignment() > -2000) {
ep->add_alignment(-random(10)); }
} }
call_out("decheck",20);
return 1;}

chains(str) {
object chain, ch;
  if(scrp < 20) { write("The darkness calls for a sacrifice.\n"); return 1;}
  if(tsp < 5) { write("You do not have enough energy!\n"); return 1;}
  if(!str) {
    if(tp->query_attack() && ((tp->query_attack())->query_npc() || dpp) && 
    !present("chains",tp->query_attack())) {
    chain = tp->query_attack(); }
    else {
    write("You may not do that.\n"); return 1;} }
  if(!present(str,environment(tp))) { write("That is not here.\n"); return 1;}
  if(present(str,environment(tp)) && (present(str,environment(tp))->query_npc() ||
    dpp)) { chain = present(str,environment(tp)); }
    else { write("You may not use this on players at this time.\n"); return 1;}
    ch = clone_object("/players/mythos/closed/guild/spells/chains.c");
    ch->set_place(tp->query_current_room());
    ch->set_strength(qtf);
    move_object(ch,chain);
  write("You have chained "+chain->query_name()+" to this room!\n");
  say(capitalize(tpn)+" points at "+chain->query_name()+" and black chains rise up\n"+
      "from the ground and trap "+chain->query_name()+"!\n");
  tp->add_spell_point(-5);
  pp->add_sacrifice(-20);
return 1;}

demonic_essence() {
  if(scrp < 10) { write("The darkness calls for a sacrifice.\n"); return 1;}
  if(tsp < 25) { write("You do not have enough energy!\n"); return 1;}
  write("You feel odd....\n");
  say(capitalize(tpn)+" is engulfed in red mist....\n");
  tp->add_spell_point(-25);
  pp->add_sacrifice(-10);
  call_out("rage",3);
return 1;}

rage() {
if(ep->query_attack()) {
if(ep->query_hp() < (ep->query_mhp())/4) {
ep->set_wc(20);
} }
if(random((present(fear,ep)->query_fae())) == 0) {
tell_object(ep,"You feel a bit dizzy....\n");
ep->set_wc(0);
ep->heal_self(-1-random(100));
return 1;}
call_out("rage",10);
return 1;}

meld(str) {
object ask, who;
if(!str) { write("Usage: meld <name>\n"); return 1;}
if(present("mind_meld",tp)) { write("You are already mind melded!\n"); return 1;}
who = present(str,environment(tp));
if(!who || who->query_npc() || (who->query_level() > 19)) { 
write("Not here.\n"); return 1;}
if(present("mind_meld",who)) { 
write("That person is already mind melded!\n");
return 1;}
ask = clone_object("/players/mythos/closed/guild/spells/con_ask.c");
ask->set_asker(tpn);
ask->set_recieve(who->query_real_name());
move_object(ask,find_player(str));
write("You ask "+capitalize(str)+" for a mind meld.\n");
return 1;}

release() {
object de;
write("You drop the ring and crush it with your heel!\n");
say(capitalize(tpn)+" drops a ring and crushes it!\n");
write("You release the creature inside the ring!\n");
de = clone_object(ob);
move_object(de,environment(tp));
tell_room(environment(tp),capitalize(trapped)+" has been released!\n");
destruct(this_object());
return 1;}

save_thing(str){
     save_object(str);
return 1;}
  
restore_thing(str){
      restore_object(str);
return 1;} 
