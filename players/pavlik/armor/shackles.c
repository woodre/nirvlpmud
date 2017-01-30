inherit "/obj/armor";
#define ME capitalize(worn_by->query_name())

/*
 * These shackles will, at times, teleport the wearer to a
 * random location.  This event is not controlable by the
 * wearer.  The teleport does not check for NT
 */

string	*drooms;

reset(arg){
 ::reset(arg);
 set_short("Iron Shackles");
 set_long(
 "You have found a pair of heavy iron shackles.  Although not they\n"+
 "are not the most comfortable thing to wear, the iron shackles\n"+
 "look like they will provide really good protection.\n");
 set_ac(2);
 set_weight(4);
 set_value(500);
 set_alias("shackles");
 set_name("a set of Iron Shackles");
 set_type("misc");
 set_save_flag(1);
 call_out("shack", 15);

 /*
  * A list of locations picked randomly
  */
 drooms=({
   "players/boltar/sprooms/daycare",
   "players/mythos/aroom/forest/forestr2",
   "players/eurale/Keep/k62",
   "players/mizan/etheriel/ROOMS/spoogle",
   "room/vill_green",
   "room/eastroad2",
   "players/llew/closed/crystal/crys",
   "players/persephone/rooms/gnolla",
 });
}

/*
 * This function will whisk the wearer away to a random loction.
 */
shack() {
  object old_env;
  string new_env;

  if(!worn_by) {
    call_out("shack", 200+random(300));
    return 1;
  }

  if(!worn_by->is_player()) {
    call_out("shack", 200+random(300));
    return 1;
  }

  if(random(20) < 3) {

    old_env = environment(worn_by);
    new_env = drooms[random(sizeof(drooms))];

    tell_object(worn_by,
    "\n"+
    "Suddenly the Iron bands around your ankles grow hot against\n"+
    "your skin.  The shackles constrict tightly about your legs\n"+
    "and you are magically teleported to a new place!!!\n"+
    "\n");

    move_object(worn_by, new_env);

    tell_object(environment(worn_by),
    ME+" suddenly appears!\n");

    tell_object(old_env,
    ME+" suddenly disappears!\n");

  }
  else {
    tell_object(worn_by,
    "The Iron Bands around your ankles feel warm against your skin.\n");
  }

  call_out("shack", 200+random(400));
  return 1;
}

