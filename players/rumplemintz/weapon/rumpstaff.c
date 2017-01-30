inherit "/obj/weapon";

#include <ansi.h>

void reset(int arg) {
  ::reset(arg);
  if(arg)
    return;
  set_name("staff");
  set_short("Rump's Staff");
  set_long("A long crooked white staff.  Looks like it beats things.\n");
  set_class(20);
  set_weight(1);
  set_value(100);
  set_hit_func(this_object());
}

int weapon_hit(object attacker){
  if (random(50) < this_player()->query_attrib("int")){
    say(HIW + "Lightning " + NORM + "leaps from Rump's staff to smite " +
        attacker->query_name() + "!\n");
    write("Your staff strikes "+ attacker->query_name() + " with " + HIW +
          "lightning"+NORM+"!\n");
    return 20;
  }
}

void init() {
  ::init();
  if (environment(this_object()) != this_player())
    return;
  if ((string)this_player()->query_real_name() != "rump" &&
      (string)this_player()->query_real_name() != "rumplemintz") {
    write("Foolish child, this is not yours!\n");
    destruct(this_object());
    return;
  }
  add_action("rump_heal", "rumpheal");
  add_action("rump_money", "rumpmoney");
  add_action("rump_home", "rumphome");
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
