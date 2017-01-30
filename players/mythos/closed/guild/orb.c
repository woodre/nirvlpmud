#include "/players/mythos/closed/guild/def.h"
string hold;
int gg;
id(str) {return str == "black_orb" || str == "orb"; }

short() { return BOLD+"The Orb"+NORM;}
long() { write("You see a dark sphere of black mist.\n"+
               "Fae swirls about inside the orb...\n"+
               "To become one with the orb and the Order\n"+
               "'reach orb'.  To raise your ability to \n"+
               "embrace fae, 'raise_fae'.\n"); }

query_auto_load() { return "/players/mythos/closed/guild/hehe.c:"; }

drop() { return 0;}		
get() {return 0; }
query_save_flag() { return 1;}

init() {
  add_action("oget","get");
  add_action("oget","take");
  add_action("pput","put");
  if(present(pact,tp)) {
  add_action("reach","reach"); }
  if(present(fear,tp)) {
  add_action("raise","raise_fae"); }
  if(living(ep) && ep->query_current_room() != "/players/mythos/closed/guild/assembly.c" &&
  ep->query_current_room() != "/players/mythos/closed/guild/hall.c") {
#ifndef __LDMUD__
  add_action("mass");add_xverb("mass_");
#else
  add_action("mass", "mass_", 3);
#endif
  add_action("energy","energy");
  add_action("flare","flare");
  }
}

pput(str) {
string what, what2;
  if(!str) { write("Put what?\n"); return 1;}
  if(sscanf(str,"%s in %s",what, what2) != 2) { write("Put what in what?\n"); return 1;}
  if(what == "orb" || what == "black_orb") {
  write("You may not do that!\n"); return 1;}
}

reach(str) {
object orrb;
  if(!str) { return 1;}
  if(str == "orb") {
  if(present(fear,tp)) { write("You already have a guild object!\n"); return 1;}
  if((tp->query_guild_exp() != 0) ||  (tp->query_guild_file() != 0) ||
     (tp->query_guild_name() != 0) || (tp->query_guild_rank() != 0)) {
     write("Have a wiz look at you.\n");
  return 1;}
  if(read_file("/players/mythos/closed/guild/leave/"+tpn)) {
    write("contact Mythos.\n");
  return 1;}
  write("You reach into the orb and suddenly.....\nENERGY pours into you....!\n");
  if(restore_object(MEM+tpn)) { 
  move_object(clone_object("/players/mythos/closed/guild/hunger.c"),tp); 
  tp->save_me(); return 1;}
  write("You have been changed!  You may wish to extinguish any light source...\n");
  orrb = clone_object("/players/mythos/closed/guild/hunger.c"); 
  move_object(orrb,tp);
  pp->set_own(tpn);
  pp->set_dark_level(1); 
  pp->add_sacrifice(200);  
    pp->set_fae(1); 
  if(tp->query_gender() == "female") {
  if(0==random(10)) {
  pp->set_talent(1);
    pp->set_fae(3); }} 
  if(tp->query_gender() == "male") {
  if(0 == random(20)) {
  pp->set_talent(1);
    pp->set_fae(3); } } 
  pp->save_dark();
  write("Something whispers: "+
        "Welcome to the DARK....\n");
  tp->save_me();
  write("Talk to your sponsor or a guild commander for information...\n");
  /*
  write("\nSuddenly, you are transported someplace else...\n\n");
  move_object(tp,"/players/mythos/closed/guild/task/1/1.c");
  command("look",tp);
  write("\nA voice whispers:  See that woman.... feed upon her fear....\n\n");
  tp->set_wc(tp->query_attrib("str"));
  tp->set_ac(5);
  */
  command("dte enters the realm of Darkness....",tp);
  write_file("/players/mythos/closed/guild/ENTER",ctime(time())+" "+tpn+"\n");
  return 1;}
return 1;}

raise() {
int z, x, need, have;
z = tl;
x = tx;
if(qtf > 19) { write("You may no longer raise your fae....\n"); return 1;}
if(qtf < 17) { need = 10000; }
else { need = 50000; } 
if(z < 19 && x > 0) { 
write("You need fixing, you have extra levels when you shouldn't.\n");
write("Please talk to a wizard for help.\n"); 
return 1;}
if(z == 19 && x > 0) {
switch(x) {
  case 1 : have = 2500000; break;
  case 2 : have = 2700000; break;
  case 3 : have = 2900000; break;
  case 4 : have = 3300000; break;
  case 5 : have = 3600000; break;
  case 6 : have = 3900000; break;
  case 7 : have = 4200000; break;
  case 8 : have = 4500000; break;
  case 9 : have = 4800000; break;
  case 10 : have = 5100000; break;
  case 11 : have = 5400000; break;
  case 12 : have = 5700000; break;
  case 13 : have = 6000000; break;
  case 14 : have = 6300000; break;
  case 15 : have = 6600000; break;
  case 16 : have = 6900000; break;
  case 17 : have = 7300000; break;
  case 18 : have = 8100000; break;
  case 19 : have = 9000000; break;
  case 20 : have = 10000000; break; } 
}
if(z < 20 && x == 0) {
switch(z) {
  case 1 : break;
  case 2 : break;
  case 3 : break;
  case 4 : break;
  case 5 : have = 5885; break;
  case 6 : have = 12812; break;
  case 7 : have = 26662; break;
  case 8 : have = 39993; break;
  case 9 : have = 59995; break;
  case 10 : have = 90000; break;
  case 11 : have = 134998; break;
  case 12 : have = 195591; break;
  case 13 : have = 295592; break;
  case 14 : have = 492294; break;
  case 15 : have = 620026; break;
  case 16 : have = 820028; break;
  case 17 : have = 1040028; break;
  case 18 : have = 1367106; break;
  case 19 : have = 2000000; break; }
}

if(txp < have + need) { write("You do not have enough xp to raise fae.\n"); return 1;}
pp->raise_fae(1);
pp->save_dark();
tp->add_exp(-need);
tp->reset(1);
tp->save_me();
command("uu",tp);
return 1;}

oget(str) {
  if(str == "orb") {
  hold = tp->query_real_name();
  write("You take the orb....\n\nSUDDENLY, POWER flares into you!\n");
  write("The ORB whispers: Ultimate power is at your finger tips.....\n"+
        "                  You must take me out of this room and the guild hall first....\n");
  say(capitalize(tpn)+" takes the ORB!\n");
  call_out("ggcheck",1);
  call_out("tempt",10);
  return 1;}
}

ggcheck() {
if(living(ep)) {
  if(epn != hold) {
  move_object(this_object(),"/players/mythos/closed/guild/assembly.c");
  } }
  if(this_object()->query_current_room() == "/players/mythos/closed/guild/assembly.c") {
  rm("/players/mythos/closed/guild/check");
  write_file("/players/mythos/closed/guild/check",1); }
call_out("ggcheck",1);
return 1;}

tempt() {
  if(!living(ep)) { return 1;}
  if(call_other(ep,"query_attrib","wil") < random(400)) {
  switch(random(10)) {
  case 0 : tell_object(ep,
  "The ORB whispers: Type <energy> for energy.....\n"); break;
  case 1 : tell_object(ep,
  "The ORB whispers: Type <mass_chaos> for MUD wide CHAOS...\n"); break;
  case 2 : tell_object(ep,
  "The ORB whispers: Type <mass_peace> for MUD wide peace...\n"); break;
  case 3: tell_object(ep,
  "The ORB whispers: Type <flare <opponent>> for an attack...\n"); break;
  }
  }
call_out("tempt",10+random(100));
return 1;}

mass(str) {
object ob, ob2;
int v;
  if(str != "peace" && str != "chaos") { write("What?\n"); return 1;}
  ob = users();
  if(str == "peace") {
  for(v=0;v<sizeof(ob);v++) {
  if(ob[v]->query_level() < 20 && ob[v]->query_attack() && ob[v] != tp) {
    ob[v]->stop_fight();
    (ob[v]->query_attack())->stop_fight();
    ob[v]->stop_fight();
    (ob[v]->query_attack())->stop_fight(); } }
     emit_channel("gossip",HIR+"  **  PEACE HAS BEEN CALLED  **\n"+NORM);
     }
   if(str == "chaos") {
   for(v=0;v<sizeof(ob);v++) {
   if(ob[v]->query_level() < 20 && ob[v] != tp) {
   ob2 = first_inventory(environment(ob[v]));
   if(ob[v] = ob2) { ob[v]->attack_object(next_inventory(ob2)); }
   else { ob[v]->attack_object(ob2); } 
   }
   }
   }
   tp->heal_self(-100 - random(100));
return 1;}

energy() {
  tp->lower_attrib();
  tp->heal_self(600);
return 1;}

flare(str) {
object ob;
string name;
  if(!str && tp->query_attack()) { ob = tp->query_attack(); }
  if(!str && !(tp->query_attack())) { write("what?\n"); return 1;}
  if(!(tp->query_attack())) {
  name = str;
  if(!present(name,environment(tp))) { write("That is not here.\n"); return 1;}
  ob = present(name,environment(tp));
  if(!(ob->is_living())) { write("That is not alive!\n"); return 1;}
  }
  tell_room(environment(tp),capitalize(tpn)+" hurls a ball of "+HIG+"DEATHFLAME"+
  NORM+" at "+capitalize(name)+"!\n\n");
  tell_room(environment(tp),HIG+
  "                        DDDDDDD\n"+
  "                        D      D\n"+NORM);
  tell_room(environment(tp),HIG+
  "                        D       D\n"+
  "                        D       D\n"+
  "                        D       D\n"+NORM);
  tell_room(environment(tp),HIG+
  "                        D      D\n"+
  "                        DDDDDDD\n\n");
  ob->heal_self(-100-random(50));
  tp->lower_attrib();
  tp->add_money(-random(20000));
return 1;}

query_shatter_proof() { return 1;} 
