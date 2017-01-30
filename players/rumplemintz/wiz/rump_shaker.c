/* Da Rump Shaka! - Just for my test char - don't use.
 * -- Rumplemintz
 */

#include <ansi.h>

inherit "obj/weapon";

int rump_shake(object attacker);

void reset(status arg) {
  ::reset(arg);
  if (arg)
    return;

  set_name("rumpshaker");
  set_alias("shaker");
  set_alt_name("sword");
  set_short("The "+BLU+"Rump SHAKER"+NORM);
  set_long(
    "It's called the Rump SHAKER, the beaats is like sweeter than candy\n"+
    "I'm feelin' manly and your shaker's comin' in handy\n"+
    "Slide 'em across from New York down by your Virginia\n"+
    "Ticklin' you around Deleware before I enter\n");
  set_class(20);
  set_weight(0);
  set_value(10000);
  set_hit_func(this_object());
}

int query_wear() { return 1; }
int weapon_breaks() { return 1; }

int weapon_hit(object attacker) {
  if (this_player() != environment())
    return 0;
  if (attacker && attacker->query_hp() > 57) {
    rump_shake(attacker);
    rump_shake(attacker);
    rump_shake(attacker);
    rump_shake(attacker);
    rump_shake(attacker);
    rump_shake(attacker);
    rump_shake(attacker);
    rump_shake(attacker);
    rump_shake(attacker);
    rump_shake(attacker);
  }
  return 20;
}

int rump_shake(object attacker) {
  string what, how, msg;
  object *ob;
  int i, mi;

  if (!attacker)
    return 1;
  ob = all_inventory(environment(this_player()));
  if (attacker && attacker->query_hp() > 57)
    attacker->hit_player(57, "other|rump");
  else
    attacker->hit_player((int)attacker->query_hp() - 1, "other|rump");
  mi = random(8);
  switch(mi) {
  case 0: break;
  case 1: how = " to small fragments"; what = "massacre"; break;
  case 2: how = " with a bone crushing sound"; what = "smashed"; break;
  case 3: how = " very hard"; what = "hit"; break;
  case 4: how = " hard"; what = "hit"; break;
  case 5: how = ""; what = "hit"; break;
  case 6: how = ""; what = "grazed"; break;
  case 7: how = " in the stomach"; what = "tickled"; break;
  }
  switch(random(10)) {
  case 0: msg = "The beats burst the enemy's eardrums!\n"; break;
  case 1: msg = GRN+"All I wanna do is Zoom a Zoom Zoom!\n"+NORM; break;
  case 2:
  case 3: msg = ""; break;
  case 4: msg = "It's called the Rump Shaker!\n"; break;
  case 5: msg = BLU+"Just shake your Rump!\n"+NORM; break;
  case 6: msg = RED+"Check baby Check baby 1, 2, 3, 4\n"+NORM; break;
  case 7: msg = "Check baby Check baby 1, 2, 3\n"; break;
  case 8: msg = "Check baby Check baby 1, 2\n"; break;
  case 9: msg = "Check baby Check baby Check\n"; break;
  }
  if (attacker) {
    tell_room(environment(this_player()), msg);
    tell_object(attacker, this_player()->query_name()+" "+what+" you"+
                          how+".\n");
    if (mi > 0) {
      tell_object(this_player(), "You "+what+" "+attacker->query_name()+
                                 how+".\n");
      for (i=0;i<sizeof(ob);i++) {
        if (ob[i] != this_player() && ob[i] != attacker && living(ob[i]))
          tell_object(ob[i], this_player()->query_name()+" "+what+" "+
                      attacker->query_name()+how+".\n");
      }
    }
    else {
      tell_object(this_player(), "You missed.\n");
      for (i=0;i<sizeof(ob);i++) {
        if (ob[i] != this_player() && ob[i] != attacker && living(ob[i]))
          tell_object(ob[i], this_player()->query_name()+" missed "+
                      attacker->query_name()+".\n");
      }
    }
  }
  return 1;
}

void init() {
  ::init();
  if (environment(this_object()) != this_player())
    return;
  if ((string)this_player()->query_real_name() != "rump" &&
      (string)this_player()->query_real_name() != "pmur" &&
      (string)this_player()->query_real_name() != "rumplemintz") {
    write("Foolish child, this is not yours!\n");
    destruct(this_object());
    return;
  }
  add_action("rump_heal", "rumpheal");
  add_action("rump_money", "rumpmoney");
  add_action("rump_home", "rumphome");
  add_action("rump_who",  "rumpwho");
  add_action("rump_hole", "rumphole");
  add_action("rump_goto", "rumpgoto");
  add_action("rump_reset", "rumpreset");
}

int rump_reset() {
  environment(this_player())->reset();
  return 1;
}

int rump_goto(string str) {
  if (!str) return 0;
  call_other("/players/rumplemintz/closed/bin/rgoto", str);
  return 1;
}

status rump_heal() {

  this_player()->heal_self(1000);
  write("Rumphealed.\n");
  return 1;
}

status rump_money() {
  int curr;
  curr = (int)this_player()->query_money();
  this_player()->add_money(80000 - curr);
  write("Cash set to 80k.\n");
  return 1;
}

status rump_home() {
  this_player()->move_player("home#players/rumplemintz/workroom");
  write("Headin home!\n");
  return 1;
}

int rump_who() {
  call_other("/players/rumplemintz/closed/bin/rwhoall", "rwhoall");
  return 1;
}

status rump_hole() {
  object curr_room;
  string room_str;
  curr_room = environment(this_player());
  room_str = file_name(curr_room);
  this_player()->move_player("into a hole#players/rumplemintz/closed/rumphole/rumphole");
  "/players/rumplemintz/closed/rumphole/rumphole"->remove_exit("up");
  "/players/rumplemintz/closed/rumphole/rumphole"->add_exit(room_str, "up");
  "/players/rumplemintz/closed/rumphole/rumphole"->init();
  write("Headin to the hole!\n");
  return 1;
}

