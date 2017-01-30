/* this is the control panel which allows the pilot to    */
/* control the mech.  this file is daemonized.  It serves */
/* as the master object                                   */
#include "DEFS.h"
#define CONTROL (PATH+"control.c")
#define MECH    environment(this_object())

int autocannon, srm, lrm, laser, rifle, ppc;
int autocannon_wep, srm_wep, lrm_wep,
    laser_wep, rifle_wep, ppc_wep;
int heat, capacity;

static mapping cmds;

id(str) { return str == "_cockpit_" || str == "_cp_"; }

init() {
  if (!environment()) return;
  if (present(this_player(), environment())) {
  add_action("go_north","north");         add_action("go_north","n");
  add_action("go_northeast","northeast"); add_action("go_northeast","ne");
  add_action("go_northwest","northwest"); add_action("go_northwest","nw");
  add_action("go_south","south");         add_action("go_south","s");
  add_action("go_southeast","southeast"); add_action("go_southeast","se");
  add_action("go_southwest","southwest"); add_action("go_southwest","sw");
  add_action("go_east","east");           add_action("go_east","e");
  add_action("go_west","west");           add_action("go_west","w");

  add_action("mechstatus","sys");         add_action("mechstatus","system");

  if (cmds = ACTIOND->query_cmds()) {                  
    string *ks; int i;
    i = sizeof(ks = keys(cmds));
    while (i--) add_action("cmd_hook", ks[i]);
  } 
}
}

get() { return 0; }
drop() { return 1; }
reset() {}

go_west()      { command("walk w", this_player()); return 1; }
go_east()      { command("walk e", this_player()); return 1; }
go_north()     { command("walk n", this_player()); return 1; }
go_northeast() { command("walk ne", this_player()); return 1; }
go_northwest() { command("walk nw", this_player()); return 1; }
go_south()     { command("walk s", this_player()); return 1; }
go_southeast() { command("walk se", this_player()); return 1; }
go_southwest() { command("walk sw", this_player()); return 1; }

cmd_hook(string str) {
  string cmd;  
  if (cmd = cmds[query_verb()])
    return (status) cmd->main(str);
}

mechstatus() {
  tell_object(this_player(),
    "Stats for "+capitalize(MECH->query_myname())+" the "+
    capitalize(MECH->query_type())+" Mech...\n"+
    "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"+
    "Heat: "+heat+"/"+MECH->query_maxheat()+"\n"+
    "Armor: "+MECH->query_hp()+"/"+MECH->query_mhp()+"\n"+
    "Aim: "+MECH->query_aim()+"\n"+
    "Target: "+MECH->query_target()+"\n"+
    "Capacity: "+capacity+"/"+MECH->query_maxcapacity()+"\n"+
    "Weapons:\n");

  if(autocannon_wep) write("Autocannon ("+autocannon_wep+")\n");
  if(srm_wep) write("SRM ("+srm_wep+")\n");
  if(lrm_wep) write("LRM ("+lrm_wep+")\n");
  if(laser_wep) write("Laser ("+laser_wep+")\n");
  if(rifle_wep) write("Rifle ("+rifle_wep+")\n");
  if(ppc_wep) write("PPC ("+ppc_wep+")\n");

  write("Ammo:\n");
  if(autocannon) write("Autocannon ("+autocannon+")\n");
  if(srm) write("SRM ("+srm+")\n");
  if(lrm) write("LRM ("+lrm+")\n");
  if(laser) write("Laser ("+laser+")\n");
  if(rifle) write("Rifle ("+rifle+")\n");
  if(ppc) write("PPC ("+ppc+")\n");

  write(
    "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
  return 1;
}

add_ammo(string wep, int num) {
  switch(wep) {
    case "autocannon": autocannon += num; break;
    case "srm":   srm += num; break;
    case "lrm":   lrm += num; break;
    case "laser": laser += num; break;
    case "rifle": rifle += num; break;
    case "ppc":   ppc += num; break;
  }
}

add_weapon(string wep) {
  switch(wep) {
    case "autocannon": autocannon_wep += 1; break;
    case "srm":        srm_wep += 1; break;
    case "lrm":        lrm_wep += 1; break;  
    case "laser":      laser_wep += 1; break;
    case "rifle":      rifle_wep += 1; break;
    case "ppc":        ppc_wep += 1; break;
  }
}

reduce_ammo(string wep) {
  switch(wep) {
    case "autocannon": autocannon -= 1; break;
    case "srm":   srm -= 1; break;
    case "lrm":   lrm -= 1; break;
    case "laser": laser -= 1; break;
    case "rifle": rifle -= 1; break;
    case "ppc":   ppc -= 1; break;
  }
}

int have_weapon(string wep) {
  /* returns how many weapons of type 'wep' the mech has */
  switch(wep) {
    case "autocannon": return autocannon_wep;
    case "srm":        return srm_wep;
    case "lrm":        return lrm_wep;
    case "laser":      return laser_wep;
    case "rifle":      return rifle_wep;
    case "ppc":        return ppc_wep;
  }
  return 0;
}

int ammo(string wep) {
  /* returns amount of ammo of type 'wep' the mech has */
  switch(wep) {
    case "autocannon": return autocannon;
    case "srm":        return srm;
    case "lrm":        return lrm;
    case "laser":      return laser;
    case "rifle":      return rifle;
    case "ppc":        return ppc;
  }
  return 0;
}

int query_heat() { return heat; }
add_heat(int more) {
  int maxheat, temp;
  if (heat+more < 0) heat = 0;  
  heat+=more;
  if (more < 0) return;
  maxheat = (int)ETO->query_maxheat();
  if(heat > maxheat) {
    temp = heat - maxheat;
    if(temp >= 30) {
      blow_up();
      return;  
    }
    if (present(OVERHEAT_ID, ETO)) {
      present(OVERHEAT_ID, ETO)->cancel_overheat();
    }
    else {
      tell_room(ETO, "Your mech has overheated.\n");
      tell_room(ETO, "All systems shutting down.\n");
    }
    heat = maxheat + 1;
    overheat(temp);
  } 
}

int query_capacity() { return capacity; }
add_capacity(int more) { capacity+=more; }

status overheat(int heat) {
  /* too much heat causes the mech to overheat.     */
  /* this causes a delay in actions, makes the      */
  /* mech vulnerable to attack (while cooling down) */
  object ob;
  heat = heat * 2;
  ob = clone_object(PATH+"overheat.c");
  move_object(ob, ETO);
  ob->set_cooldown(heat);
  return 1;
}
 
status blow_up() {
  string name;
  name = capitalize((string)ETO->query_myname());
  environment(ETO)->shout(name+" overheats and blows up in a huge mushroom cloud.\n");
  write("Your mech's thermal systems have exceeded way over their limits.\n");
  ETO->hit_player(1000);
  return 1;
}

status is_overheated() {
  int maxheat;
  maxheat = (int)ETO->query_maxheat();
  if (heat > maxheat) return 1;
  return 0;
}
