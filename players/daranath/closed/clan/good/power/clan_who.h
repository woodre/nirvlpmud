/* Version 1.0 of the Clan (good) world who listing */

clan_who() {

int a, b;
string who, loc, gld, clan;
object *ob;
object ob2;

ob = users();

 write(HIW+"<> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <>"+NORM+"\n");
write(HIC);
write("Name            Level    Profession   Affiliation   Location\n");
write(NORM);
 write(HIW+"<> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <>"+NORM+"\n");

for(b=0; b<sizeof(ob); b+=1) {
  if(!ob[b]->query_invis()) {
write(pad(ob[b]->query_name(),15));
write(" ");
write(pad(ob[b]->query_level(),3));
if(ob[b]->query_level() < 20){
write("+");
write(pad(ob[b]->query_extra_level(),5));
} else {
write("      ");  }

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
write(pad(gld,11));
write("  ");
}

ob2 = (present("clan_ob",ob[b]));
if(!ob2) {clan = "Clanless"; }
if(ob2){
if(ob2->query_clan_align() == 1) {clan = (HIC+"Lion Clan     "+NORM); }
if(ob2->query_clan_align() == 0) {clan = (BOLD+BLK+"Snake Clan    "+NORM); }
if(ob2->query_clan_align() == 2) {clan = (HIW+"Scorpion Clan"+NORM); }
} else{ clan = "Clanless      "; }

write(clan);
if(!environment(ob[b])) loc = "LOGIN";
else
loc = environment(ob[b])->short();
write(loc);
write(NORM+NORM);
write("\n");
   }
}

 write(HIW+"<> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <>"+NORM+"\n");
write(HIC);
 write("Name            Level    Profession   Affiliation   Location\n");
write(NORM);
 write(HIW+"<> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <>"+NORM+"\n");
return 1; }

