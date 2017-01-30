/* Version 1.o of the necro who listing */

necro_who() {

int a, b;
string who, loc;
object ob;

ob = users();

write("--------------------------------------------------------------------------\n");
write(" -> Name          Race      Lvl/Xl   Guild      Location\n");
write("--------------------------------------------------------------------------\n");

for(b=0; b<sizeof(ob); b+=1) {
  if(!ob[b]->query_invis()) {
write("   ");
write(pad(ob[b]->query_name(),15));
  if(ob[b]->query_name() == "Pain"){
write(pad("fool",9)); }
else {
write(pad(ob[b]->query_race(),9));
write(NORM+NORM);
}
write(" ");
write(pad(ob[b]->query_level(),3));
write("/");
write(pad(ob[b]->query_extra_level(),5));
if(ob[b]->query_guild_name() == 0) {
  write("none     ");
  }
  if(ob[b]->query_guild_name() == "Knights Templar"){
write(pad("templar",9)); }
  else {
write(pad(ob[b]->query_guild_name(),9));
  }
write("  ");
if(!environment(ob[b])) loc = "LOGIN";
else
loc = environment(ob[b])->short();
write(pad(loc,30));
write(NORM+NORM);
write("\n");
   }
}

write("--------------------------------------------------------------------------\n");
return 1; }

