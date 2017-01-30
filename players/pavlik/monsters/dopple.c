#include <ansi.h>
inherit "/obj/monster";

object owner;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Doppleganger");
  set_alias("doppleganger");
  set_short("A Doppleganger");
  set_long(
  "A Doppleganger.\n");
  set_race("dopple");
  set_level(30);
  set_hp(10000);
  set_al(0);
  set_aggressive(1);
  set_wc(18);
  set_ac(30);
  set_heart_beat(1);
}

init() {
  ::init();
  add_action("init_dopple", "dopp");
}

/*
 *
 */
init_dopple() {
  string name;
  string revname;
  int i;
  object ob;

  ob = this_player();
  owner = ob;

  name = ob->query_real_name();
  revname = "";

  for(i=strlen(name); i>=0; i--) {
     revname = revname+extract(name,i,i);
  }

  set_name(capitalize(revname));
  set_short(capitalize(revname));
  set_wc(ob->query_wc());
  set_ac(ob->query_ac());
  set_hp(ob->query_mhp());
  this_object()->add_hit_point(-(query_hp()-1));
  this_object()->add_hit_point(ob->query_hp());
  call_out("stat_update", 2);
  return 1;
}

stat_update() {
  if(!owner || !present(owner, environment(this_object()))) {
    destruct(this_object());
    return 1;
  }
  set_wc(owner->query_wc());
  set_ac(owner->query_ac());
  this_object()->add_hit_point(-(query_hp()-1));
  this_object()->add_hit_point(owner->query_hp());
  call_out("stat_update", 2);
  return 1;
}

/*
 * As usual, I don't like players being able to stop a fight.
 */
stop_fight() {
  if(this_player()->query_level() > 20) {
    ::stop_fight();
    return 1;
  }
  return;
}

/*
 * None of this heal_self crap
 */
heal_self(i) {
  if(i <= 0) {
    return;
  }
  else {
    ::heal_self(i);
  }
  return;
}

/*
 * No modifying stats either!
 */
set_ac(x) {
  if(this_player() != this_object()) { return; }
  ::set_ac(x);
  return 1;
}

set_wc(x) {
  if(this_player() != this_object()) { return; }
  ::set_wc(x);
}

set_heal_rate(x,y) {
  if(this_player() != this_object()) { return; }
  ::set_heal_rate(x,y);
}


