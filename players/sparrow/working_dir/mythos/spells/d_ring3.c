#include "/players/mythos/closed/guild/def.h"
string owner, trapped;
string ob;
static int wer, cde;
static string msg, mmsg;
id(str) { return str == "demonring" || str == "ring" || str == "demon ring" ||
                 str == "sapphire" || str == "sapphire ring"; }

reset(arg) {
  if(arg) return;
  msg = "Demon Ring "+BLU+"[Sapphire]"+NORM;
  mmsg = "Demon Ring "+BLU+"[Sapphire]"+NORM;
  wer = 0;
  cde = 0;
  call_out("decheck",20);
}

short(){ return msg;}

long() {
write("A sapphire ring of exquisite beauty.\n"+
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
  add_action("meld","meld");
  add_action("release","release");
}

wwear(str) {
 if(!str) { write("What?\n"); return 1;}
 if( str == "demonring" || str == "ring" || str == "demon ring" ||
     str == "sapphire" || str == "sapphire ring" ) {
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
     str == "sapphire" || str == "sapphire ring" ) {
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
     str == "sapphire" || str == "sapphire ring" ) {
     if(wer == 1) {
     msg = mmsg;
     wer = 0;
     write("You slip the demon ring off your finger.\n");
     }
} }

ggive(str) {
if(!str) { write("What?\n"); return 1;}
 if( str == "demonring" || str == "ring" || str == "demon ring" ||
     str == "sapphire" || str == "sapphire ring" ) {
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
   cde = 1;
   write("The ring begins to glow softly with an evil light...\n");
   }
if(!com && cde == 1) {
  write("The ring stops glowing....\n");
}
if(ep->query_crime()) {
ep->add_spell_point(random(2)); }
else { ep->add_spell_point(-random(2)); }
if(ep->query_alignment() > -2000) {
ep->add_alignment(-random(3)); }
}}
call_out("decheck",20);
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
