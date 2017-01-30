#define ep environment(this_object())
int day;
object cor, cor2, zom;

id(str) { return str == "xb"; }

get() { return 0;}

init() {
  if (environment() && ep)
    call_out("corp",3);
}

reset(arg) {
  if(arg) return;
  day = 0;
}

corp() {
int last, ttim;
int n;

last = call_other("/players/mythos/castle.c","query_reboot",0);
ttim = last - time();

if(ttim > 10799 && ttim < 21600) { day = 1; }  /* 9am ~ */
if(ttim > 21599 && ttim < 32400) { day = 2; }  /* noon ~ */
if(ttim > 32399 && ttim < 43200) { day = 3; }  /* 3pm ~ */
if(ttim > 43199 && ttim < 54000) { day = 4; }  /* 6pm- sundown ~ */
if(ttim > 53999 && ttim < 64800) { day = 5; }  /* 9pm ~ */
if(ttim > 64799 && ttim < 75600) { day = 6; }  /* 12am- midnight ~ */
if(ttim > 75599 && ttim < 86400) { day = 7; }  /* 3am ~*/
if(ttim > 86399) { day = 0; }                  /* 6am- dawn ~then reboot~ */
if(ep) {
cor = first_inventory(ep);
  while(cor) {
    cor2 = next_inventory(cor);
    if(cor->id("corpse of thorns") || cor->id("corpse of living corpse")) { 
      destruct(cor); }
    else if(cor->id("corpse") && !living(cor) && random(3) == 0) { 
      rise(); }
    cor = cor2;
  }
while(remove_call_out("corp") != -1);
call_out("corp",3);
}
return 1;}

rise() {
  zom = clone_object("/players/mythos/closed/guild/spells/monster2.c");
  zom->set_name("living corpse");
  zom->set_alias("living");
  zom->set_race("corpse");
  zom->set_level(cor->query_corpse_level());
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

query_day() { return day; }
query_shatter_proof() { return 1;}
