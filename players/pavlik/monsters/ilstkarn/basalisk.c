#include <ansi.h>
inherit "/obj/monster";
#define ME capitalize(ob->query_name())
#define PO ob->query_possessive()

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Basalisk");
  set_alias("basalisk");
  set_short("A greater Basalisk");
  set_long("A greater Basalisk\n");
  set_race("basalisk");
  set_level(20);
  set_hp(500);
  set_ac(18);
  set_wc(30);
  set_al(-1000);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_a_chat_chance(20);
  load_a_chat("The Basalisk's long body slithers across the ground.\n");
  load_a_chat("The Basalisk swipes at you with one of its huge claws.\n");
  load_a_chat("The Basalisk spits a "+HIB+"Bolt of Lightning"+NORM+"!\n"+
  "The bolt explodes into the ground next to you, missing you by inches!\n");
  move_object(clone_object("players/pavlik/items/ilstkarn/basalisk_weapon"),
  this_object());
  init_command("wield weapon");
  money = 1000+random(2000);
}

long() {
  /*
   * Player has a chance of getting petrified by looking at the
   * basalisk.  Also give hint that there is less chance of getting
   * turned to stone if the player is looking away.
   */
  if(present("look_away", this_player())) {
    write("You stop trying to look away from the Basalisk.\n");
    destruct(present("look_away", this_player()));
    return;
  }
  write(
  "You hesitantly glance at the long graceful body of the Basalisk.  It\n"+
  "is said that the gaze of this dragon-like creature can turn a person\n"+
  "into stone!  You might be safer if you decide to 'look away' from this\n"+
  "evil creature rather than chance seeing it eye to eye.  The Basalisk's\n"+
  "eight arms are tipped with very sharp, very dangerous claws.\n");
  call_out("petrify", 3, this_player());
  return;
}

hit_player(arg) {
  int dam;
  int x;

  x = 2 + random(3);
  /*
   * damage is reduced if the player is looking away.
   * damage is reduce by either 1/2, 1/3 or 1/4
   */
  if(present("look_away", this_player())) {
    arg = arg - arg/x;
  }
  else {
    /*
     * otherwise we suffer a chance of getting turned to stone!
     * (this means the more we hit the more likely we are to get turned
     *  to stone [heh heh heh])
     */
    if(!random(3)) petrify(this_player());
  }
  if(arg < 1) arg = 1;
  dam = ::hit_player(arg);
  return dam;
}

init() {
  ::init();
  if(this_player()->is_player()) {
    call_out("stare", 3+random(5), this_player());
  add_action("enter","enter");
  add_action("go_blind","look");
  }
}

query_ilstkarn(){ return 1; }

stare(ob) {
  int i;

  if(!present(ob, environment(this_object()))) {
    return 1;
  }

  if(ob->query_alignment() < 0) {
    if(query_attack()) {
      return 1;
    }
    else {
      tell_object(ob,
      "The greater Basalisk slithers silently out of your way.\n");
      return 1;
    }
  }

  petrify(ob);

  if(!query_attack() && present(ob, environment(this_object()))) {
    tell_room(environment(this_object()),
    "The greater Basalisk slithers forward and attacks!\n");
    attack_object(ob);
    return 1;
  }
  return 1;
}

enter() {
  object ob;
  ob = this_player();

  if(this_player()->query_alignment() < -100) {
    write("The greater Basalisk moves out of your way.\n");
    say("The greater Basalisk moves out of "+ME+"'s way.\n");
    this_player()->move_player("enter#players/pavlik/ilstkarn/secret_entrance");
    return 1;
  }
  write("The Basalisk blocks your path!\n");
  return 1;
}

/*
 * This gives the player a chance to 'look away' from the monster
 * and reduce the chance of being turned to stone.  The side
 * effect is that the amount of damage done to the monster is
 * reduced (can't be so accurate when you are essentially blind)
 */
go_blind(str) {
  object obj;

  if(str == "away") {
    if(present("look_away", this_player())) {
      write("You are already avoiding the gaze of the Basalisk.\n");
      return 1;
    }
    write("You turn your head and avoid looking directly at the Basalisk.\n");
    say(capitalize(this_player()->query_name())+" stares at the ground.\n");
    obj = clone_object("players/pavlik/items/ilstkarn/look_away");
    move_object(obj, this_player());
    return 1;
  }
}
   
/*
 * This function will immobilize an attacker for a short period
 * of time.  If the target is a player the stone curse will wear
 * off shortly.  If the target is an NPC the stone curse may expire
 * after a short time or it may be permanent.
 */
petrify(ob) {
  int chance;
  object obj;

  if(ob == this_object()) {
    return 1;
  }

  if(!present(ob, environment(this_object()))) {
    return 1;
  }

  if(present("look_away", ob)) {
    return 1;
  }

  if(ob->query_ilstkarn()) {
    return 1;
  }

  if(ob->is_player()) chance = 9;
  else chance = 30;

  if(random(100) < chance) {
    obj = clone_object("players/pavlik/items/ilstkarn/stone_curse");
    move_object(obj, environment(this_object()));
    move_object(ob, obj);
    obj->do_curse(ob);
    return 1;
  }
  else if(!random(3)) {
    tell_object(ob,
    "The Basalik's eyes shine with a magical "+HIR+"crimson"+NORM+" light.\n");
    return 1;
  }
  else if(!random(2)) {
    tell_object(ob,
    "You "+HIM+"narrowly"+NORM+" avoid the gaze of the sinister Basalisk!\n");
  }
  return 1;
}

/*
 * No stopping the fight with this guy.
 */
stop_fight() {
  if(this_player()->query_level() > 20 || this_player() == this_object()) {
    ::stop_fight();
    return 1;
  }
  return;
}

/*
 * Non of this heal_self crap
 */
heal_self(i) {
  if(i <=0) {
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

monster_died() {
  object obj;

  tell_room(environment(this_object()),
  "The Basalisk's dragon-like body turns to stone and falls apart!\n");
  destruct(present("corpse", environment(this_object())));

  move_object(clone_object("players/pavlik/armor/stone_armor"),
  environment(this_object()));

  move_object(clone_object("players/pavlik/weapons/lightning_rod"),
  environment(this_object()));

  if(this_player()->query_real_name())
    write_file("/players/pavlik/ilstkarn/LOG",
    capitalize(this_player()->query_real_name())+" killed the Basalisk. ["+ctime()+"]\n");

  return 0;
}

