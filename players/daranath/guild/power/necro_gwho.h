/* version 1.0 of the necro guild score */

necro_gwho() {

int a, glevel;
object ob, ob2;
object members;
int max;
string loc, lvl;

ob = (present("necro_ob",this_player()));

write("\n");
write("----------------------------------------------------------------------\n");
write(" -> Name         Level   Necro Status    Current Location\n");
write("----------------------------------------------------------------------\n");

  max = call_other("players/daranath/guild/chatter","query_guild_chat_size");
   for(a=0;a<max;a++) {
   ob2 = call_other("players/daranath/guild/chatter","query_guild_chat",a);
  if(ob2)
  if(!ob2->query_invis()) {
write("  ");
write(pad(ob2->query_name(),15));
if(ob2->query_level() > 18) {
write(pad(ob2->query_level(),2));
write("+");
write(pad(ob2->query_extra_level(),5));
} else {
write("  ");
write(pad(ob2->query_level(),6));
}
  glevel = ob2->query_guild_rank();
if(glevel == 11) { lvl = "Avatar"; }
if(glevel == 10) { lvl = "Necromancer"; }
if(glevel == 9) { lvl = "Bone Minister"; }
if(glevel == 8) { lvl = "Dark Servant"; }
if(glevel == 7) { lvl = "Dark Initiate"; }
if(glevel == 6) { lvl = "Grifter"; }
if(glevel == 5) { lvl = "Bone Harvester"; }
if(glevel == 4) { lvl = "Shadow Servant"; }
if(glevel == 3) { lvl = "Shadow Initiate"; }
if(glevel == 2) { lvl = "Acolyte"; }
if(glevel < 2) { lvl = "Apprentice"; }
if(ob2->query_level() > 19) { lvl = "Warlock"; }
if(ob2->query_name() == "Daranath") { lvl = "The Creator"; }
write(pad(lvl, 16));
  if(!environment(ob2)) loc = "LOGIN";
else
  loc = environment(ob2)->short();
write(pad(loc, 29));
write(NORM+NORM);
write("\n");

   }
}
write("----------------------------------------------------------------------\n");
return 1; 
}
