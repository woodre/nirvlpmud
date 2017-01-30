/* Version 1.0 of the Druid world who */

druid_who() {

int a, b;
string who, loc, gld, align;
object *ob;
object ob2;

ob = users();

write(GRN+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
write(YEL+"   --'--,--"+GRN+"{"+HIR+"@"+NORM+HIG+"                 Druid World Who"+NORM+"                   "+HIR+"@"+NORM+GRN+"}"+YEL+"--,--'--"+NORM+"\n");
write(GRN+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
write(HIG+"   Name            Level    Guild      Alignment   Location"+NORM+"\n");

for(b=0; b<sizeof(ob); b+=1) {
  if(!ob[b]->query_invis()) {
write("   ");
if((ob[b]->query_pl_k() == 1) && (ob[b]->query_level() < 20)) {
write(pad(ob[b]->query_name(),12));
write(HIR+" PK"+NORM);
} else {
write(pad(ob[b]->query_name(),15));
}
write(" ");
write(pad(ob[b]->query_level(),3));
if(ob[b]->query_level() < 20){
write("+");
write(pad(ob[b]->query_extra_level(),5));
} else {
write("      ");  }

if(ob[b]->query_level() > 19) {
write(HIW+"Wizard     "+NORM);
} else {
if(ob[b]->query_guild_name() == 0) {
   gld = "none"; }
if(ob[b]->query_guild_name() == "NONE"){
  gld = "none"; }
if(ob[b]->query_guild_name() == "None"){
  gld = "none"; }
if(ob[b]->query_guild_name() == "Elemental") {
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
if(ob[b]->query_guild_name() == "The Hive"){
   gld = "none"; }
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
write(pad(gld,9));
write("  ");
}

if(ob[b]->query_alignment() > 250) {
   align = (HIW+"Pure Soul "+NORM); }
if(ob[b]->query_alignment() < (-250)) {
   align = (BOLD+BLK+"Corrupted "+NORM); }
if((ob[b]->query_alignment() < 250) && (ob[b]->query_alignment() > (-250))) {
   align = (GRN+"In Balance"+NORM); }
write(align);
write("  ");

if(!environment(ob[b])) loc = "LOGIN";
else
loc = environment(ob[b])->short();
write(loc);
write(NORM+NORM);
write("\n");
   }
}

write(GRN+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
write(YEL+"   --'--,--"+GRN+"{"+HIR+"@"+NORM+HIG+"                 Druid World Who"+NORM+"                   "+HIR+"@"+NORM+GRN+"}"+YEL+"--,--'--"+NORM+"\n");
write(GRN+"<< --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- >>"+NORM+"\n");
return 1; }

