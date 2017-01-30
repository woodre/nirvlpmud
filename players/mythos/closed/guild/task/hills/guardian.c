#include "/players/mythos/closed/guild/def.h"
inherit "players/mythos/closed/guild/spells/monster2";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("golem");
  set_alias("guardian");
  set_alt_name("ashmek");
  set_race("spirit");
  set_short("Spirit Golem of Ashmek");
  set_long("A large flesh golem stands before you.  A thing\n"+
           "made from the skins of dead men.  It looks at\n"+
           "you through haunted eyes.  You recall a legend\n"+
           "about this thing: It never dies.....\n");
  set_hp(500);
  set_level(25);
  set_al(-random(10000) + random(10000));
  set_wc(40);
  set_ac(15);
  set_heal(5,10);
  set_dead_ob(this_object());
  set_a_chat_chance(10);
  load_a_chat("The Flesh Golem moans!\n");
  load_a_chat("The Golem lashes out with a heavy hand!\n"); 
  set_mult(2);
  set_mult_chance(40);
  set_mult_dam1(10);
  set_mult_dam2(30);
  call_out("checks",6);
}

monster_died() {
  move_object(clone_object("/players/mythos/closed/guild/task/hills/guardian.c"),
              environment(this_object()));
return 0; }

init() {
  ::init();
  add_action("iinvoke","invoke");
}

iinvoke(str) {
  if(!str) return 0;
  if(id(str)) {
    write("The golem falls back with a wordless moan!\n");
    tell_room(ep,"Lightning flashes and suddenly the golem is no more!\n");
    destruct(this_object());
  return 1;}
}

checks() {
object around;
int h, z;
  z = 0;
  around = all_inventory(ep);
  for(h=0;h<sizeof(around);h++) {
    if(around[h] != this_object()) {
      if(present("DarkStone",around[h])) z = 1;
    }
  }
  if(!z) {
    iinvoke("golem");
  return 1;}
call_out("checks",3);
return 1;}
