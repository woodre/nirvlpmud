/* My personal who listing for the wizclan   -Dar */

clan_who() {

int a, b;
string who, gld;
object *ob;
object attacker;
string pkcheck, pkcheck2;

ob = users();

write(HIR+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
write(HIW);
write("   Name            Level    Guild        PK    Combat\n");
write(NORM);
write(HIR+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");

for(b=0; b<sizeof(ob); b+=1) {
{
write("   ");
write(pad(capitalize(ob[b]->query_real_name()),15));
write(" ");

if(ob[b]->query_level() > 19) {
write(pad(ob[b]->query_level(),9));
} else {
write(pad(ob[b]->query_level(),2));
write(" + ");
write(pad(ob[b]->query_extra_level(),4));
}

if(ob[b]->query_level() > 19) {
write(BOLD+"Wizard       "+NORM);
} else {
if(ob[b]->query_guild_name() == 0) {
   gld = "none"; }
if(ob[b]->query_guild_name() == "NONE"){
  gld = "none"; }
if(ob[b]->query_guild_name() == "None"){
  gld = "none"; }
if(ob[b]->query_guild_name() == "necromancer"){
   gld = "Necromncer"; }
if(ob[b]->query_guild_name() == "Knights Templar"){
   gld = "Templar"; }
if(ob[b]->query_guild_name() == "polymorph"){
   gld = "Polymorph"; }
if(ob[b]->query_guild_name() == "bloodfist"){
   gld = "Bloodfist"; }
if(ob[b]->query_guild_name() == "vampire"){
   gld = "Vampire"; }
if(ob[b]->query_guild_name() == "healer"){
   gld = "Healer"; }
if(ob[b]->query_guild_name() == "monk"){
   gld = "Monk"; }
if(ob[b]->query_guild_name() == "fallen"){
   gld = "Fallen"; }
if(ob[b]->query_guild_name() == "dervish"){
   gld = "Dervish"; }
if(ob[b]->query_guild_name() == "bard"){
   gld = "Bard"; }
if(ob[b]->query_guild_name() == "symbiote"){
   gld = "Symbiote"; }
if(ob[b]->query_guild_name() == "neo symbiote"){
   gld = "Neo Symb"; }
if(ob[b]->query_guild_name() == "shardak"){
   gld = "Shardak"; }
if(ob[b]->query_guild_name() == "warrior"){
   gld = "Warrior"; }
if(ob[b]->query_guild_name() == "cyberninja"){
   gld = "Cyberninja"; }
if(ob[b]->query_guild_name() == "rangers"){
   gld = "Ranger"; }
if(ob[b]->query_guild_name() == "dark rangers"){
   gld = "Dark Ranger"; }
write(pad(gld,11));
write("  ");
}

if((ob[b]->query_pl_k() == 1) && (ob[b]->query_level() < 20)) {
  pkcheck2 = (HIR+"YES"+NORM);
} else {
  pkcheck2 = "NO ";
}

write(pkcheck2);
write("   ");

attacker = ob[b]->query_attack();
if(attacker) {
if(attacker->is_player()) {
pkcheck = (BLINK+HIR+"PK"+NORM+" - "+BLINK+HIR+attacker->query_name()+NORM); }
if(attacker->is_npc()) {
pkcheck = (HIW+"YES"+NORM+" - "+HIW+attacker->query_name()+NORM); }
} else { pkcheck = "NO"; }

write(pkcheck);

write("\n");
   }
}

write(HIR+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
write(HIW);
write("   Name            Level    Guild        PK    Combat\n");
write(NORM);
write(HIR+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
return 1; }

