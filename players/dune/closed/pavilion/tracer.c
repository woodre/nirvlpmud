/* this is the actual bullet that gets fired. */
/* it runs up to a target and explodes upon   */
/* the mech, all depending upon what weapon   */
/* it came from.                              */
#define ROOM  environment(this_object())
inherit "obj/monster";

id(str) { return str == "_tracer_"; }

reset(arg){
   if(arg) return 0;
   ::reset(arg);
   set_name("tracer");
   set_alias("_tracer_");
   set_level(1);
   enable_commands();
   set_can_kill(0);
   set_aggressive(0);
   set_ep(0);
   set_no_exp_value();
}

activate(object self, int dm, int rg,
         int bm, int ht, string wep) {
  /* distance ranging      */
  /* this moves the bullet */
  string aim, targ;
  int count;
  count = 0;
  if(rg == 0) { bullet_func(self, dm, rg, bm, ht, wep); }
  else {
    aim = self->query_aim();
    if(!aim) aim = random_compass();
    if(bullet_func(self, dm, rg, bm, ht, wep)) return 1;
      while(count < rg) {
        command(aim, this_object());
        if(bullet_func(self, dm, rg, bm, ht, wep)) return 1;
        count += 1;
      }
    }
  return 1;
}

bullet_func(object self, int dm, int rg,
            int bm, int ht, string wep) {
  /* target recognition and bullet handling */
  /* this function determines who gets hit  */
  string targ;
  object * room;
  int i;
  targ = ((string)self->query_target())	;
  if(!targ) targ = "none";
  if(targ == "any") targ = "none";
  room = all_inventory(ROOM);
  for(i = 0; i < sizeof(room); i++) {
    if(room[i]->is_mech() && room[i] != self) {
      if(room[i]->id(targ)) {
        if(bm > 0) boom(room[i], bm);
        harm_mech(room[i], dm, self, wep);
        return 1; }
      if(targ == "none") {
        if(bm > 0) boom(room[i], bm);
        harm_mech(room[i], dm, self, wep);
        return 1; }
      }
      tell_object(room[i],
      "You hear the sound of "+wep+" fire hum past you.\n");
    }
  call_out("do_check", 3);
  return 0;
}

do_check() {
  /* this destroys the bullet once it has done its job */
  destruct(this_object());
  return 1;
}

string random_compass() {
  /* this determines blast direction */
  int rnd;
  rnd = random(8);
  switch(rnd) {
    case 0:  return "north";
    case 1:  return "northeast";
    case 2:  return "northwest";
    case 3:  return "south";
    case 4:  return "southeast";
    case 5:  return "southwest";
    case 6:  return "east";
    case 7:  return "west";
    }
  return "nothing";
}

boom(object * ob, int bm) {
  /* this blasts the mech a certain direction. */
  /* depending upon the weapon's blast radius. */
  /* what really happens is that the special   */
  /* living.c forces the monster to move in a  */
  /* special way (different msgout/msgin)      */
  string dir;
  string * exits;
  int i, count;
  count = 0;
  dir = random_compass();
  dir = reduce(dir);
  ob->set_blown_away(1);
  while(bm > 0) {
      exits = ROOM->query_dest_dir();
      for(i = 0; i < sizeof(exits); i++) {
        if(exits[i] == dir) count = 1;
        }
      if(count) command(dir, ob);
      bm -= 1;
      }
  ROOM->shout(
    "You hear the sound of a mech smashing into the ground\n");
  ob->set_blown_away(0);
  return 1;
}

string reduce(string str) {
  switch(str) {
    case "north":     return "n";
    case "northwest": return "nw";
    case "northeast": return "ne";
    case "east":      return "e";
    case "west":      return "w";
    case "south":     return "s";
    case "southeast": return "se";
    case "southwest": return "sw";
    }
  return "nowhere"; }

harm_mech(object * targ, int dm, object attacker, string wep) {
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
  ROOM->shout("The blast of "+wep+
                 " fire upon a mech rings in your ears.\n");
  if(death) {
    pilotwinner = attacker->query_pilot();
    pilotloser = targ->query_pilot();
    ROOM->shout(name+" explodes into a million pieces.\n");
    write_file("/players/dune/log/ROBOMECH",
               who+" (pilot "+pilotwinner+") destroyed "+
               name+" (pilot "+pilotloser+")\n"+
               "   on the date of "+ctime()+"\n");
    targ->hit_player(1000);
    death = 0;
    }
  else {
  targ->hit_player(dm);
  death = 0;
  }
  call_out("do_check", 3);
  return 1;
}

/* bullets are invisible (you shouldn't see them entering/exiting rooms) */
query_invis(num) {
  return 19;
}
