/* Version 1.0 of the Druid guild members listing */

druid_gwho() {

int a;
object attacker;
object ob, ob2;
string pkcheck, title;
int max;

ob = (present("druid_ob",this_player()));

write("\n");
write(GRN+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
write(HIG+"   Name           Level   Sex   Druid Rank   Combat?"+NORM+"\n");
write(GRN+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");

  max = call_other("players/daranath/druid/chatter","query_guild_chat_size");
   for(a=0;a<max;a++) {
   ob2 = call_other("players/daranath/druid/chatter","query_guild_chat",a);
  if(ob2)
  if(!ob2->query_invis()) {
write("   ");
write(pad(ob2->query_name(),15));

write(pad(ob2->query_level(),3));
if(ob2->query_level() < 20){
write("+");
write(pad(ob2->query_extra_level(),5));
} else {
write("      ");  }

if(ob2->query_gender() == "male") {
write(pad("M",5)); }
else {write(pad("F",5)); }

if(ob->query_glvl() < 6) {title = "Initiate  "; }
if((ob->query_glvl() > 5) && (ob->query_glvl() < 10)) {title = "Aspirant  "; }
if((ob->query_glvl() > 9) && (ob->query_glvl() < 15)) {title = "Ovate     "; }
if((ob->query_glvl() > 14) && (ob->query_glvl() < 20)) {title = (GRN+"LoreMaster"+NORM); }
if((ob->query_glvl() > 19) && (ob->query_glvl() < 30)) {title = (GRN+"Protector "+NORM); }
if((ob->query_glvl() > 29) && (ob->query_glvl() < 40)) {title = (GRN+"Druid     "+NORM); }
if(ob->query_glvl() > 39) {title = (HIG+"ArchDruid "+NORM); }
write(title);
write(" ");

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
write(GRN+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
return 1; 
}
