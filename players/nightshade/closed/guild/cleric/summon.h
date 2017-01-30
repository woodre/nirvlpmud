

hammer() {
  if(Glevel < 5) {
    write("You are not worthy enough to ask Matry.\n");
    return 1;
  }
  if(SP < 50) {
    write("You do the possess enough magical energy to create a magica hammer.\n");
    return 1;
  }
  if(hamm) {
    write("You already summoned a magical hammer.\n");
    return 1;
  }
   hamm = clone_object("players/nightshade/closed/guild/obj/hamm");
  if(Glevel == 15 || Glevel > 15) hamm->set_class(15);
else if(Glevel == 12 || Glevel ==  13 || Glevel == 14) hamm->set_class(13);
else if(Glevel == 9 || Glevel == 10 || Glevel == 11) hamm->set_class(11);
else if(Glevel == 6 || Glevel == 7 || Glevel == 8) hamm->set_class(10);
else hamm->set_class(10);
  move_object(hamm, Me);
command("wield hammer", Me);
  write("You utter holy words to Matry and a hammer appears in your grasp\n");
  say(Name+" summoned a magical hammer to "+Obj+".\n");
  Ssp(50);
  Gain(EXP50);
  return 1;
}
vestment() {
  if(Glevel < 3) {
    write("You are not worthy enough to ask Matry.\n");
    return 1;
  }
  if(SP < 50) {
    write("You do the possess enough magical energy to create a magica vestment.\n");
    return 1;
  }
  if(vest) {
    write("A magical vestment still exist somewhere.\n");
    return 1;
  }
   vest = clone_object("players/nightshade/closed/guild/obj/vest");
  if(Glevel == 15 || Glevel > 15) vest->set_ac(5);
  else if(Glevel == 12 || Glevel == 13 || Glevel == 14) vest->set_ac(4);
  else if(Glevel == 9 || Glevel == 10 || Glevel == 11) vest->set_ac(3);
  else if(Glevel == 6 || Glevel == 7 || Glevel == 8) vest->set_ac(2);
  else vest->set_ac(1);
  move_object(vest, Me);
command("wear vestment", Me);
  write("You have created a magical armour around you.\n");
  say(Name+" created a magical armour around "+Obj+".\n");
  Ssp(50);
  Gain(EXP50);
  return 1;
}
wall_of_fire() {
object ob;
  if(Glevel < 13) {
    write("You are not worthy enough to ask Matry.\n");
    return 1;
  }
  if(SP < 30) {
    write("You do not possess enough magical energy to create a wall of fire.\n");
    return 1;
  }
  ob = this_player()->query_attack();
  if(!ob) {
    write("You are not fighting anything at the moment.\n");
    return 1;
  }
  if(fire) {
    write("A wall of fire still exists.\n");
    return 1;
  }
   fire = clone_object("players/nightshade/closed/guild/obj/fire");
  move_object(fire, Env(Me));
  ob->attack_object(fire);
  write(ob->query_name()+" is blocked by the wall of fire and tries to attack it.\n");
  say(ob->query_name()+" is blocked by the wall of fire and tries to attack it.\n");
  Ssp(30);
  Gain(EXP30);
  return 1;
}

wall_of_thorns(str) {
string dir;
  if(Glevel < 7) {
    write("You are not worthy enough to ask Matry.\n");
    return 1;
  }
  if(SP < 20) {
    write("You do not possess enough magical energy to create a wall of thorns.\n");
    return 1;
  }
  if(!str) {
    write("What direction would you like to block?\n");
    return 1;
  }
  if(thorn) {
    write("A wall of thorns still exists.\n");
    return 1;
  }
  if(str == "n" || str == "north") dir = "north";
else
  if(str == "s" || str == "south") dir = "south";
else
  if(str == "e" || str == "east" ) dir = "east";
else
  if(str == "w" || str == "west" ) dir = "west";
else
  if(str == "d" || str == "down" ) dir = "down";
else
  if(str == "ne" || str == "northeast") dir = "northeast";
else
  if(str == "nw" || str == "northwest") dir = "northwest";
else
  if(str == "se" || str == "southeast") dir = "southeast";
else
  if(str == "sw" || str == "southwest") dir = "southwest";
else
  if(str == "enter" ) dir = "enter";
else
  if(str == "in" ) dir = "in";
else
  if(str == "out") dir = "out";
else
  if(str == "leave") dir = "leave";
else
  if(str == "exit") dir = "exit";
else
  dir = "not";
  if(dir == "not") {
    write(str+" is not a valid direction.\n");
    return 1;
  }
  write("You create a wall of thorns blocking the "+dir+" passage.\n");
  say(Name+" creates a wall of thorns blocking the "+dir+" passage.\n");
   thorn = clone_object("players/nihgtshade/closed/guild/obj/thorn");
  thorn->set_direct(dir);
  thorn->set_short("A wall of thorn blocking "+dir);
  thorn->set_who(NAME);
  move_object(thorn, Env(Me));
  Ssp(20);
  Gain(EXP20);
  return 1;
}

blade_barrier() {
  if(Glevel < 10) {
    write("You are not worthy enough to ask Matry.\n");
    return 1;
  }
  if(blade_count > 5) {
    write("Matry says: You have called too many blade barriers. You will have to wait.\n");
    return 1;
  }
  if(SP < 25) {
    write("You do not possess enough magical energy to cast blade barrier.\n");
    return 1;
  }
  if(!Me->query_attack()) {
    write("You are not fighting. You must be in combat.\n");
    return 1;
  }
  if(blade) {
    write("A blade barrier already exists.\n");
    return 1;
  }
   blade  = clone_object("players/nightshade/closed/guild/obj/blade");
  blade->set_who(NAME);
  move_object(blade, Env(Me));
  write("A barrier of razor sharp edges appear and damages your foe.\n");
  say("A barrier of razor sharp edges appear and damages the enemies.\n");
  Ssp(25);
  blade_count++;
  Gain(EXP20A);
  return 1;
}

call_servant() {
  if(Glevel < 5) {
    write("You are not worthy enough to ask Matry.\n");
    return 1;
  }
  if(SP < 50) {
    write("You do not possess enough magical energy to call for a servant.\n");
    return 1;
  }
  if(servant) {
    write("You already have called a servant.\n");
    return 1;
  }
  write("You call for a servant.\n");
   servant = clone_object("players/nightshade/closed/guild/obj/servant");
  servant->set_max_weight((Glevel + 5)+(Faith * 2) + 5);
  servant->set_who(capitalize(NAME));
  servant->set_short(capitalize(NAME)+"'s servant");
  servant->set_short(capitalize(NAME)+"'s servant");
  servant->set_name(NAME+"'s servant");
  move_object(servant, environment(Me));
  tell_room(environment(Me), "A servant arrives.\n");
  Gain(EXP40A);
  Ssp(50);
  return 1;
}




