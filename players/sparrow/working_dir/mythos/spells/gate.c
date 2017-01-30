#include "/players/mythos/closed/guild/def.h"
object ob, ob2, ob3;
int num, timer, tyme;

id(str) { return str == "nexus_gate" || str == "gate"; }
short(){write(BOLD+"] GATE  [to the]  NEXUS [\n"+NORM);}
long() {write(BOLD+"A dark portal leading to the NEXUS\n"+NORM);}
drop() {return 1;}
get() { return 0;}

set_num(n) { num = n;}
query_num() { return num;}
set_time(ti) { tyme = ti*100;}

reset(arg) {
if(arg) return;
timer = 0;
call_out("time",10);
call_out("gating",1+random(8));
}

gating() {
int arms, level, mkm;
if(environment(this_object())) {
if(10+random(40) < random(100)) {
ob = clone_object("/players/mythos/closed/guild/spells/monster2.c");
level = 10+random(12);
ob->set_name("demon");
ob->set_race("demon");
ob->set_al(-random(1000));
ob->set_hp(level*10+random(400));
ob->set_level(level);
if(level < 12) {
ob->set_short("Nexus Demon <Type I>"); }
if(level > 11 && level < 14) {
ob->set_short("Nexus Demon <Type II>"); }
if(level > 13 & level < 16) {
ob->set_short("Nexus Demon <Type III>"); }
if(level > 15 && level < 17) {
ob->set_short("Nexus Demon <Type IV>"); }
if(level > 16 && level < 19) {
ob->set_short("Nexus Demon <Type V>"); }
if(level > 18 && level < 21) {
ob->set_short("Nexus Demon <Type VI>"); }
if(level > 20) {
ob->set_short("Nexus Demon <Type VII>"); }
ob->set_wc(10+random(10));
ob->set_ac(random(15));
ob->set_spec_aggres();
ob->set_can_kill(1);
ob->set_exx(0);
if(0== random(3)) {
ob->set_wander();}
if(0==random(7)) {
arms= 2+random(3);
ob->set_mult(arms);
ob->set_mult_chance(random(10));
ob->set_mult_dam1(random(7));
ob->set_mult_dam2(random(5));
ob->set_long("A monster of hideous features, a mouth full of teeth, "+arms+" arms...\n"+
            "A demon of your nightmares!\n");}
else {
ob->set_long("A monster of hideous features...\n"+
            "A demon of your nightmares!\n");}
ob->set_a_chat_chance(10);
ob->load_a_chat("The Demon screams!\n");
ob->load_a_chat("The Demon growls!\n");
if( environment(this_object())) 
move_object(ob,environment(this_object())); }
if( environment(this_object())) {
ob2= all_inventory(environment(this_object()));
for(mkm=0;mkm<sizeof(ob2);mkm++) {
  if(living(ob2[mkm]) && call_other(ob2[mkm],"id","demon")) {
  if(10+random(20) > random(100)) {
  move_object(ob2[mkm],"/players/mythos/closed/guild/spells/nexus.c");
  tell_room(environment(this_object()),ob2[mkm]->short()+" vanshes into the NEXUS!\n");
  } }
  } } }
call_out("gating",10+random(300));
return 1;}

time() {
if(environment(this_object())) {
if(timer > tyme) {
tell_room(environment(this_object()),"The GATE collapses!\n");
destruct(this_object());
return 1;}
timer = timer + 1; }
call_out("time",10);
return 1;}

query_shatter_proof() { return 1;}
