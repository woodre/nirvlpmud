#include "/players/mythos/closed/guild/def.h"
object weap, dark, count;
string name;
int numb, befo;
int demon_s, dragon_s, spirit_s, shadow_s;
int vampiric, soul_steal, sharp, dancing, berserk, speed;
int wound, spellcleaver;

empower(str) {
if(!str) { write("Usage: empower <weapon> <sp amount>\n"); return 1;}
if(qtf < 10) { write("Your control over fae is not enough!\n"); return 1;}
if(scrp < 300) { write("The darkness calls for a sacrifice.\n"); return 1;}
if(sscanf(str,"%s %d",name,numb) != 2) { 
write("Usage: empower <weapon> <sp amount>\n"); return 1;}
weap = present(name,tp);
if(numb < 1) { write("You can not do that.\n"); return 1; }
if(tp->query_sp() < numb) { write("You dont have that much sp!\n"); return 1;}
if(!weap) { write("You do not have that!\n"); return 1;}
if(!(weap->weapon_class())) { write("That is not a weapon!\n"); return 1;}
if(weap->weapon_class() < 17 && !(weap->id("demon blade"))) { 
write(weap->short()+" can not take the stress!\nIt is destroyed!\n");
tp->zap_object(tp);
return 1;}
tp->add_spell_point(-numb);
pp->add_sacrifice(-300);
write("You weave the dark fae into "+name+".\n");
say(capitalize(tpn)+" weaves dark material into "+name+"!\n");
if(!present("count",weap)) {
count = clone_object("/players/mythos/closed/guild/spells/count.c");
count->set_count(numb);
move_object(count,weap); }
else {
befo = present("count",weap)->query_count();
present("count",weap)->set_count(befo + numb); }
if(present("count",weap)->query_count() > (3000 + random(1000))) {
destruct(present("count",weap));
write("What ritual do you wish to do?  <type 'done' when you are done>\n");
write("The Ritual of: ");
input_to("ritual");
}
return 1;}

ritual(str) {
string small, path, inf, name_of;
int heavy;
  if(!str) { write("The Ritual of: "); input_to("ritual"); return 1;}
  if(str == "balberith") { demon_s = 1; 
                  write("The Ritual of: "); input_to("ritual"); return 1;}
  if(str == "samson") { dragon_s = 1; 
                  write("The Ritual of: "); input_to("ritual"); return 1;}
  if(str == "rosier") { spirit_s = 1; 
                  write("The Ritual of: "); input_to("ritual"); return 1;}
  if(str == "ebra") { shadow_s = 1; 
                  write("The Ritual of: "); input_to("ritual"); return 1;}
  if(str == "horlach") { vampiric = 1; 
                  write("The Ritual of: "); input_to("ritual"); return 1;}
  if(str == "wraithstorm") { soul_steal = 1; 
                  write("The Ritual of: "); input_to("ritual"); return 1;}
  if(str == "edith") { sharp = 1; 
                  write("The Ritual of: "); input_to("ritual"); return 1;}
  if(str == "bheleu") { berserk = 1; 
                  write("The Ritual of: "); input_to("ritual"); return 1;}
  if(str == "orith") { speed = 1; 
                  write("The Ritual of: "); input_to("ritual"); return 1;}
  if(str == "loial") { wound = 1; 
                  write("The Ritual of: "); input_to("ritual"); return 1;}
  if(str == "merdyn") { spellcleaver = 1; 
                  write("The Ritual of: "); input_to("ritual"); return 1;}
  if(str == "done") {
  command("unwield "+name,tp);
  small = weap->short();
  inf = weap->query_info();
  heavy = weap->query_weight();
  name_of = weap->query_name();
  sscanf(object_name(weap),"%s#%s",path);
  dark = clone_object("/players/mythos/closed/guild/spells/dwep.c");
  dark->set_path(path);
  dark->set_name("dark weapon");
  dark->set_alias(name_of);
  dark->set_alt_name(name);
  dark->set_short(small + CYN+"  * Cold Fire * "+NORM);
  dark->set_weight(heavy);
  dark->set_read(RED+"A Weapon of BLOOD- forged by "+capitalize(tpn)+".\n"+NORM); 
  dark->set_owner(tpn);
  dark->set_info(inf);
  dark->set_class(18);
  dark->set_value(10000);
  dark->set_storage(numb);
  
  if(dragon_s) { dark->set_slaying("dragon"); }
  if(shadow_s) { dark->set_slaying("shadow"); }
  if(weap->id("demonslayer") || (demon_s && !(weap->id("spirit sword")))) {
  dark->set_slaying("demon"); }
  if(weap->id("spirit sword") || (spirit_s && !(weap->id("demonslayer")))) {
  dark->set_slaying("spirit"); }
  destruct(weap);
  if(vampiric) { dark->set_vampire(); dark->set_class(17);}
  if(sharp) { dark->set_sharp(); dark->set_life(7 + random(10));}
  if(berserk) { dark->set_berserk(); dark->set_class(17); }
  if(speed) { dark->set_speed(); dark->set_class(16);}
  if(wound) { dark->set_wound(); }
  if(spellcleaver) { dark->set_spell(); }
  if(soul_steal) { dark->set_steal(); dark->set_life(10+random(10)); dark->set_class(16);}
  move_object(dark,tp);
  dark->save_thing("players/mythos/closed/guild/room/backup/"+tpn);
  write("You have empowered your weapon!  The DARK FAE sings in it!\n");
  pp->set_dblade(1);
  command("dsave",tp);
  command("uu",tp);
  return 1;}
  write("The Ritual of: "); 
  input_to("ritual");
return 1;}
