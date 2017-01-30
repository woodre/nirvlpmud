/* this is the daemon (slave) object for cockpit.c */
#define MECH    environment(this_player())
#define ROOM    environment(MECH)
#define TP      this_player()
#define CAP     capitalize

id(str) { return str == "cockpit_daemon"; }

object PIT(object ob) {
  /* similar to #define */
  object cockpit;
  if(!environment(ob)) return 0;
  if(present("_cockpit_", environment(ob)))
  cockpit = present("_cockpit_", environment(ob));
  return cockpit; }

info(string str) {
  /* help files */
  string file;
  if(!str) {
  write(
"Welcome Pilot!\n"+
"\n"+
"     Here's all the information you'll need about\n"+
"how to play, weapon/ammo stats, RoboMech physics,\n"+
"and the utilities available for your use.\n"+
"     You may get more detailed information by\n"+
"typing 'robo <topic>' for each of these other topics.\n");
  ls("/players/dune/closed/pavilion/docs");
    return 1; }
  file = "/players/dune/closed/pavilion/docs/"+str;
  if(file_size(file) >= 0) {
    cat(file);
    return 1; }
  write("That file does not exist.\n");
}

install(string str) {
  /* installs weapons upon the mech */
  string wep, file, this;
  int capacity, maxcapacity, wepcapacity;
  file = file_name(ROOM);
  if(!sscanf(file, "%spavilion/rooms/robosh%s", this)) {
    write("You must go to the Hangar to install weapons.\n");
    return 1; }
  if(!str) {
    write("Usage: install <weapon>\n");
    return 1; }
  wep = call_other("/players/dune/closed/pavilion/control.c",
                   "find_weapon", str);
  if(wep == "none") {
    write("No such weapon as "+str+", your choices are:\n"+
          "'autocannon, srm, lrm, laser, rifle, or ppc'\n");
    return 1; }
  maxcapacity = MECH->query_maxcapacity();
  capacity = PIT(TP)->query_capacity();
  wepcapacity = find_capacity(wep, 1);
  capacity += wepcapacity;
  if(capacity > maxcapacity) return 0;
  PIT(TP)->add_weapon(wep);
  PIT(TP)->add_capacity(wepcapacity);
  write("You install the "+wep+" weapon.\n");
  tell_room(ROOM, capitalize(MECH->query_myname())+
            " has installed the "+wep+" weapon.\n");
  return 1;
}

int find_capacity(string wep, int flag) {
  /* returns 1)weapon and 2)ammo capacities and 3)ammo packages */
  switch(wep) {

    case "autocannon": if(flag==1) return 15; if(flag==2) return 10;
                         if(flag==3) return 14; break;
    case "srm":        if(flag==1) return 12; if(flag==2) return 6;
                         if(flag==3) return 10; break;
    case "lrm":        if(flag==1) return 11; if(flag==2) return 8;
                         if(flag==3) return 10; break;
    case "laser":      if(flag==1) return 10; if(flag==2) return 9;
                         if(flag==3) return 12; break;
    case "rifle":      if(flag==1) return 9; if(flag==2) return 10;
                         if(flag==3) return 16; break;
    case "ppc":        if(flag==1) return 15; if(flag==2) return 9;
                         if(flag==3) return 12; break;
    }
  return 0;
}

supply(string str) {
  /* allows pilot to add ammo to the mech's weapons */
  string wep, file, this;
  int maxcapacity, capacity, ammocapacity, pack;
  file = file_name(ROOM);
  if(!sscanf(file, "%spavilion/rooms/robosh%s", this)) {
    write("You must go to the Hangar to supply weapons.\n");
    return 1; }
  if(!str) {
    write("Usage: supply <weapon>\n");
    return 1; }
  wep = call_other("/players/dune/closed/pavilion/control.c",
                   "find_weapon", str);
  if(wep == "none") {
    write("No such weapon as "+str+", your choices are:\n"+
          "'autocannon, srm, lrm, laser, rifle, or ppc'\n");
    return 1; }
  maxcapacity = MECH->query_maxcapacity();
  capacity = PIT(TP)->query_capacity();
  ammocapacity = find_capacity(wep, 2);
  capacity += ammocapacity;
  if(capacity > maxcapacity) return 0;
  pack = find_capacity(wep, 3);
  PIT(TP)->add_ammo(wep, pack);
  PIT(TP)->add_capacity(ammocapacity);
  write("You supply your mech with "+wep+" ammo.\n");
  tell_room(ROOM, capitalize(MECH->query_myname())+
            " has added "+wep+" ammo.\n");
  return 1;
}

out() {
  /* ejects the user from the mech */
  /* mech is later destructed      */
  object ob;
  string pos;
  pos = TP->query_possessive();
  write("You bail out of your mech.\n");
  say(capitalize(TP->query_name())+
    " bails out of "+pos+" mech.\n");
  ob = MECH;
  comm(CAP(TP->query_name())+
       " bails out of "+CAP(ob->query_myname())+".");
  move_object(TP, ROOM);
  destruct(ob);
  return 1; }

say(string str) {
  /* allows pilot to say things to the room */
  if(!str) {
    write("What do you say?\n");
    return 1; }
  tell_room(ROOM, "A voice from "+CAP(MECH->query_myname())+
    "'s speaker says: "+str+"\n");
  return 1; }

loook(string str) {
  /* allows pilot to look at things in the room */
  object ob, eob;
  ob = MECH;
  move_object(TP, ROOM);
  if(!str) {
    call_other(TP, "look");
    move_object(TP, ob);
    return 1; }
  command("look "+str, TP);
  move_object(TP, ob);
  return 1; }

walk(string str) {
  /* allows pilot to move the mech around      */
  /* works on a delay, according to mech speed */
  int speed;
  int name;
  if(!str) {
    write("Usage: walk <direction>\n");
    return 1; }
  name = this_player()->query_real_name();
  name = lower_case(name);
  speed = MECH->query_speed();
  call_out("walk_delay", speed, str+" "+name);
  return 1; }

walk_delay(string str) {
  string message, name;
  object player, ob;
  sscanf(str, "%s %s", message, name);
  player = find_player(name);
  ob = environment(player);
  if(command(message, ob)) command("look",player);
  return 1; }

comm(string str) {
  /* annoucements for all mechs */
  object everyone, pilot;
  int i;
  everyone = users();
  for(i = 0; i < sizeof(everyone); i++) {
    if(environment(everyone[i]) && PIT(everyone[i])) {
      pilot = PIT(everyone[i]);
      if(pilot)
        tell_object(everyone[i], "[[RoboComm]] "+str+"\n");
      }
    }
  return 1; }

comm_channel(string str) {
  /* talk to other mechs over a channel */
  string name; 
  object everyone, pilot;
  int i;
  if(!str) {
    write("Usage: comm <message>\n");
    return 1; }
  name = capitalize(MECH->query_myname());
  everyone = users();
  for(i = 0; i < sizeof(everyone); i++) {
    pilot = PIT(everyone[i]);
    if(pilot)
      tell_object(everyone[i], "[["+name+"]] "+str+"\n");
    }
  return 1; }

comm_who()  {
  /* see what other mechs (and their pilots) are playing */
  int i;
  object ob, mech, room;
  string pilot_name, mech_name, type, loc;
  ob = users();
  write("RoboMech     Pilot        Type      Location\n");
  write("###################################################\n");
  for(i = 0; i < sizeof(ob); i++)  {
   if(environment(ob[i]) && PIT(ob[i])) {
    pilot_name = capitalize(ob[i]->query_name());
    mech = environment(ob[i]);
    room = environment(mech);
    mech_name = capitalize(mech->query_myname());
    type = capitalize(mech->query_type());
    loc = room->zone();
    if(!loc) loc = "Off Battlefield";
    write(pad(mech_name,13));
    write(pad(pilot_name,13));
    write(pad(type, 10));
    write(pad(loc, 16));
    write("\n");
    }
  }
  write("###################################################\n");
  return 1;
}

punch(string str) {
  /* default weapon. punchs never need ammo */
  /* punchs don't do much damage either     */
  object targ;
  string file, this;
  file = file_name(ROOM);
  if(!sscanf(file, "%spavilion/rooms/field%s", this)) {
    write("Mechs must fight in the RoboMech Battlefield.\n");
    return 1; }
  if(!str) {
    write("What do you want to punch?\n");
    return 1; }
  if(!present(str, ROOM)) {
    write("There is no "+str+" here.\n");
    return 1; }
  targ = present(str, ROOM);
  if(!targ->is_mech()) {
    write(str+" is not a RoboMech.\n");
    return 1; }
  punch_mech(targ, 3, MECH, "punch");
  return 1; }

punch_mech(object targ, int dm, object attacker, string wep) {
  /* this does the actual damage to the mech */
  /* deaths are recorded                     */
  int death;
  string name, pilotwinner, pilotloser, who;
  object targroom;
  targroom = environment(targ);
  name = capitalize(targ->query_myname());
  who = capitalize(attacker->query_myname());
  death = 0;
  if(targ->query_hp() <= dm) death = 1;
  tell_room(targroom, name+
              " takes a hit from "+who+"'s "+wep+".\n");
  ROOM->shout(
    "You hear the clanking sounds of mechs bashing eachother.\n");
  if(death) {
    pilotwinner = attacker->query_pilot();
    pilotloser = targ->query_pilot();
    ROOM->shout(name+" falls apart from continual bashing.\n");
    write_file("/players/dune/log/ROBOMECH",
               who+" (pilot "+pilotwinner+") destroyed "+
               name+" (pilot "+pilotloser+")\n"+
               "   on the date of "+ctime()+"\n");
    targ->hit_player(1000);
    death = 0;
    return 1;
    }
  targ->hit_player(dm);
  death = 0;
  return 1;
}

fire(string str) {
  /* allows pilot to fire a specified weapon */
  int num_of_wep;
  string wep, file, this;
  file = file_name(ROOM);
  if(!sscanf(file, "%spavilion/rooms/field%s", this)) {
    write("Mechs must fight in the RoboMech Battlefield.\n");
    return 1; }
  if(!str) {
    write("Usage: fire <weapon>\n");
    return 1; }
  wep = find_weapon(str);
  if(wep == "none") {
    write("No such weapon as "+str+", your choices are:\n"+
          "'autocannon, srm, lrm, laser, rifle, or ppc'\n");
    return 1; }
  num_of_wep = PIT(TP)->have_weapon(wep);
  if(!num_of_wep) {
    write("You do not have the "+str+" weapon.\n");
    return 1; }
  if(PIT(TP)->ammo(wep)) {
    PIT(TP)->reduce_ammo(wep);
    fire_away(wep, num_of_wep); 
    return 1; }
  else {
    write("You're out of "+str+" ammo!\n");
    return 1; }
  return 1; }

string find_weapon(string str) {
  /* returns the string used to identify the weapon */
  switch(str) {
    case "autocannon": return "autocannon";
    case "cannon":     return "autocannon";
    case "srm":        return "srm";
    case "lrm":        return "lrm";
    case "laser":      return "laser";
    case "rifle":      return "rifle";
    case "ppc":        return "ppc";
    }
  return "none"; }

aim(string str) {
  /* directional system                                  */
  /* allows pilot to aim the mech in a certain direction */
  int ok;
  string dir;
  if(!str) {
    write("Usage: aim <direction>\n");
    return 1; }
  switch(str) {
    case "n": ok = 1; dir = "n"; break;
    case "north": ok = 1; dir = "n"; break;
    case "s": ok = 1; dir = "s"; break;
    case "south": ok = 1; dir = "s"; break;
    case "e": ok = 1; dir = "e"; break;
    case "east": ok = 1; dir = "e"; break;
    case "w": ok = 1; dir = "w"; break;
    case "west": ok = 1; dir = "w"; break;
    case "ne": ok = 1; dir = "ne"; break;
    case "northeast": ok = 1; dir = "ne"; break;
    case "se": ok = 1; dir = "se"; break;
    case "southeast": ok = 1; dir = "se"; break;
    case "nw": ok = 1; dir = "nw"; break;
    case "northwest": ok = 1; dir = "nw"; break;
    case "sw": ok = 1; dir = "sw"; break;
    case "southwest": ok = 1; dir = "sw"; break;
    }
  if(!ok) {
    write(str+" is not a valid direction.  Your choices are:\n"+
          "'n, e, s, w, ne, nw, se, or sw'\n");
    return 1; }
  MECH->set_aim(dir);
  tell_room(ROOM, CAP(MECH->query_myname())+" faces "+dir+".\n");
  return 1; }

target(string str) {
  /* targeting system                    */
  /* allows pilot to target another mech */
  if(!str) {
    write("Usage: target <mech>\n");
    write(
"Note: Be sure to target the mech, and not the pilot.\n"+
"      If you don't know who to target, type 'target any'\n");
    return 1; }
  str = lower_case(str);
  MECH->set_target(str);
  tell_object(this_player(), "You target "+capitalize(str)+".\n");
  return 1; }

overheat(int heat) {
  /* too much heat causes the mech to overheat.     */
  /* this causes a delay in actions, makes the      */
  /* mech vulnerable to attack (while cooling down) */
  object ob;
  heat = heat * 2;
  ob = clone_object(
       "/players/dune/closed/pavilion/overheat.c");
  move_object(ob, MECH);
  ob->set_cooldown(heat);
  return 1; }

repair(string str) {
  /* allows pilot to repair damage and cool the  */
  /* mech down.  makes mech vulnerable to attack */
  int time;
  object ob;
  if(!str) {
    write("Usage: repair [minor/average/major]\n");
    return 1; }
  switch(str) {
    case "minor":   time = 5; break;
    case "average": time = 10; break;
    case "major":   time = 15; break;
    }
  if(!time) {
    write("Wrong repair type, your choices are:\n"+
          "'minor, average, or major'\n");
    return 1; }
  ob = clone_object(
       "/players/dune/closed/pavilion/repair.c");
  move_object(ob, MECH);
  ob->set_repairs(time, str);
  return 1; }

fire_away(string str, int num_of_wep) {
  /* function for calculating weapon features */
  int dm, rg, bm, ht, maxheat, temp, heat;
  object tracer;
  switch(str) {

    case "autocannon":  dm=16; rg=0; bm=0; ht=8; break;
    case "srm":         dm=14; rg=2; bm=1; ht=6; break;
    case "lrm":         dm=13; rg=5; bm=2; ht=5; break;
    case "laser":       dm=13; rg=3; bm=0; ht=5; break;
    case "rifle":       dm=12; rg=2; bm=1; ht=4; break;
    case "ppc":         dm=17; rg=2; bm=2; ht=9; break;
    }
  dm *= num_of_wep;
  ht *= num_of_wep;
  PIT(TP)->add_heat(ht);
  heat = PIT(TP)->query_heat();
  maxheat = MECH->query_maxheat();
  if(heat > maxheat) {
    temp = heat - maxheat;
    if(temp >= 30) { blow_up(); return 1; }
    overheat(temp);
    return 1; }
  tracer = clone_object(
           "/players/dune/closed/pavilion/tracer.c");
  move_object(tracer, ROOM);
  tell_room(ROOM, CAP(MECH->query_myname())+
            " fires its "+str+".\n");
  ROOM->shout("The blast of "+str+
                 " rings through the battlefield.\n");
  tracer->activate(MECH, dm, rg, bm, ht, str);
  return 1; }

blow_up() {
  string name;
  name = capitalize(MECH->query_myname());
  ROOM->shout(name+" overheats and blows up in a huge mushroom cloud.\n");
  write("Your mech's thermal systems have exceeded way over their limits.\n");
  MECH->hit_player(1000);
 return 1; }
