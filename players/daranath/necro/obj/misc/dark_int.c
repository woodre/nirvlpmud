#define ep environment(this_object())
int day;
object cor, cor2, zom;

id(str) { return str == "xb" || str == "dark_int"; }

get() { return 0;}

reset(arg) {
  if(arg) return;
  call_out("corp",3);
}

corp() {
int last, ttim;
int n;

if(ep) {
cor = first_inventory(ep);
while(cor) {
cor2 = next_inventory(cor);
  if(cor->id("corpse of living corpse")) { 
    destruct(cor); }
  if(cor->id("corpse") && !living(cor) && random(3) == 0) { 
  rise(); }
  cor = cor2;
  }
  }
call_out("corp",3);
return 1;}

rise() {
  zom = clone_object("/players/mythos/closed/guild/spells/monster2.c");
  zom->set_name("living corpse");
  zom->set_alias("living");
  zom->set_race("corpse");
  zom->set_level(1*(cor->query_corpse_level()));
  zom->set_wc(10 + 1*(cor->query_corpse_level()));
  zom->set_hp(25*1*(cor->query_corpse_level()));
  zom->set_ac(1*(cor->query_corpse_level()));
  zom->set_short("The Living "+cor->short());
  zom->set_long(cor->long()+"\nThis has risen by the power of the forest!\n");
  zom->set_aggressive(1);
  zom->set_chat_chance(20);
  zom->set_load_chat("Living corpse moans....\n");
  zom->set_load_chat("The 'living' corpse slips into the shadows...\n");
  zom->set_wander();
  destruct(cor);
  if(ep) {
  move_object(zom,ep);
  tell_room(ep,"You notice something wrong with the surrounding area!\n"+
               "Suddenly, something moves!\n\n");
  tell_room(ep,"The Dead come back to life!\n\n"); }
}

