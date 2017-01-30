/* Version 1.0 of the clan members listing ...   */

clan_gwho() {

int a;
object attacker;
object ob, ob2;
string pkcheck;
int max;

ob = (present("clan_ob",this_player()));

write("\n");
write(HIW+"<> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <>"+NORM+"\n");
write(HIC+"Name           Level   Sex   Clan Rank   Combat?"+NORM+"\n");
write(HIW+"<> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <>"+NORM+"\n");

  max = call_other("players/daranath/closed/clan/good/chatter","query_guild_chat_size");
   for(a=0;a<max;a++) {
   ob2 = call_other("players/daranath/closed/clan/good/chatter","query_guild_chat",a);
  if(ob2)
  if(!ob2->query_invis()) {
write(pad(ob2->query_name(),15));

write(pad(ob2->query_level(),3));
if(ob2->query_level() < 20){
write("+");
write(pad(ob2->query_extra_level(),5));
} else {
write("      ");  }

if(ob2->query_gender() == "male") {
write(pad("M",3)); }
else {write(pad("F",3)); }

/* Clan status check here, once I figure it out  -Dar  */ 
write("                ");

attacker = ob2->query_attack();
if(attacker) {
if(attacker->is_player()) {
pkcheck = (BLINK+HIR+"PK"+NORM+" - "+BLINK+HIR+attacker->query_name()+NORM); }
if(attacker->is_npc()) {
pkcheck = (HIR+"YES"+NORM); }
} else { pkcheck = "NO"; }

write(pkcheck);

/*
if(ob2->query_attack()){
write(HIR+"YES"+NORM);
write(" ");
} else {write("NO"); }
*/

write("\n");
   }
}
write(HIW+"<> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <>"+NORM+"\n");
return 1; 
}
