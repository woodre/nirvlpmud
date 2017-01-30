#include <ansi.h>
inherit "/obj/monster";
#define IT capitalize(obj->query_name())
#define ARM ob[i]->short()

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Green Slime");
  set_alias("green slime");
  set_short("A puddle of "+HIG+"Green Slime"+NORM);
  set_long(
  "An oozing bubbling puddle of green slime.  This foul substance is\n"+
  "known to be not only deadly, but intelligent too.  The puddle of slime\n"+
  "slithers across the floor.  Its green goo can eat through the strongest\n"+
  "metals and cause irreversible to damage to one's skin.\n");
  set_race("slime");
  set_level(15+random(5));
  set_hp(225+random(275));
  set_ac(12+random(15));
  set_wc(20+random(15));
  set_al(-random(1000));
  set_aggressive(1);
  set_a_chat_chance(40);
  load_a_chat("Green slime inches forward.\n");
  load_a_chat("Some slime splatters on your skin ... it Burns!\n");
  load_a_chat("Green slime bubbles and pops.\n");
  load_a_chat("Slime hisses as it burns into your flesh.\n");
  set_dead_ob(this_object());
  call_out("corrode", 10);
}

id(str) {
  return str == "slime" || str == "green slime" || str == "ilstkarn_monster";
}

/*
 * No stopping the fight.
 */
stop_fight() {
  if(this_player()->query_level() > 20) {
    ::stop_fight();
    return 1;
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

corrode() {
  object ob, obj;
  int i, n;

  obj = this_object()->query_attack();

  if(!obj) {
    call_out("corrode", 25);
    return 1;
  }

  if(!present(obj, environment(this_object()))) {
    call_out("corrode", 10);
    return 1;
  }

  /*
   * If the unlucky number doesn't come up then return
   */
  if(random(11) != 8) {
    tell_room(environment(), "Green Slime spits a blob of acid at you!\n");
    call_out("corrode", 6+random(30));
    return 1;
  }

  /*
   * If attacker is not a player then we kill it immediately
   */
  if(!obj->is_player()) {
    tell_room(environment(), "\n"+
    "The hideous "+HIG+"Green Slime"+NORM+" lunges forward and envelops "+IT+"!!!\n"+
    "A disgusting gurgling can be heard is the slime liquifies "+IT+"'s body.\n");
    tell_room(environment(),
    "The slime creature "+HIR+"completely destroys "+NORM+IT+".\n"+
    "Green Slime belches loudly.\n\n");
    move_object(obj, "room/void");
    destruct(obj);
    call_out("corrode", 40);
    return 1;
  }

  /*
   * If we aren't weilding a weapon then let's go for a piece of armor.
   */
  if(!obj->query_weapon() || !random(9)) {
    ob = all_inventory(obj);
    for(i=0; i<sizeof(ob); i++) {
      if(!random(3) && ob[i]->query_worn() && !ob[i]->query_invulnrable()) {
        tell_room(environment(), 
        HIG+"Green Slime"+NORM+" spits a blob of acid on "+IT+"!\n");
        tell_object(obj,
        "The acid blob strikes "+ARM+" and "+HIR+"destroys"+NORM+" it!\n"+
        "The armor dissolves into nothing.\n");
        ob[i]->drop(1);
        if(ob[i]) destruct(ob[i]);
        i = sizeof(ob)+1;
      }
    }
  }
  /*
   * Or if we have a weapon it is either destroyed or the weapon class
   * is reduced by one.
   */
  else {
    ob = obj->query_weapon();
    tell_room(environment(),
    HIG+"Green Slime"+NORM+" spits a blob of acid on "+IT+"!\n");
    tell_object(obj, "The acid blob strikes your weapon!\n");
    if(random(9)==4) {
      obj->stopwield();
      tell_object(obj, ob->short()+" is "+HIR+"destroyed!\n"+NORM);
      destruct(ob);
    }
    else {
      tell_object(obj,
      "The corrosive acid "+HIR+"weakens"+NORM+" your weapon.\n"+
      "You "+HIR+"drop"+NORM+" the burning weapon.\n");
      ob->drop(1);
      ob->set_class(ob->weapon_class() - 1);
    }
  }
  
  call_out("corrode", 50); 
  return 1;
}

monster_died() {
  object ob, obj;

  tell_room(environment(),
  "The puddle of green slime hisses and disappears.\n");
  destruct(present("corpse", environment()));

  obj = clone_object("players/pavlik/items/iron_chest");
  ob = clone_object("obj/money");
  ob->set_money(500+random(1000));
  move_object(ob, obj);
  move_object(obj, environment());
  move_object(clone_object("players/pavlik/items/heals/heal_potion"), obj);
  move_object(clone_object("players/pavlik/items/red_potion"), obj);
  if(!random(4)) {
    move_object(clone_object("players/pavlik/items/ilstkarn/teleport_key"), obj);
  }
  return 0;
}
 
