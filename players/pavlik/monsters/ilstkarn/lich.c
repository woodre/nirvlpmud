inherit "obj/monster";
#include "/players/pavlik/closed/colors.h"
#define LZ GRN+"Lancoz"+NORM
#define ME capitalize(this_player()->query_name())
#define IT capitalize(obj->query_name())
#define ROOM environment(this_object())

reset(arg){
  ::reset(arg);
  if(arg) return;
  set_name(GRN+"Lancoz"+NORM);
  set_alt_name("lancoz_lich");
  set_alias("lancoz");
  set_race("lich");
  set_short(LZ+" the Lich");
  set_long(
  LZ+" was imprisoned here many centuries ago for his heinous crimes\n"+
  "against men.  Now he is destined to guard the Gate of Dimensions\n"+
  "until he is freed.  His body is nearly transparent and two red orbs\n"+
  "burn brightly from within the deep sockets of his skull.  Lancoz has\n"+
  "a passion for valuable jewels and he wears a multitude of them on\n"+
  "his wasted body.\n");
  set_level(25);
  set_al(-1000);
  set_hp(3000);
  set_wc(44);
  set_ac(23);
  set_aggressive(0);
  set_can_kill(1);
  call_out("kombat", 3);
}

clean_up() { return 0; }   /* do not clean */

stop_fight(){
 return this_object()->heal_self(20+random(30));
}

stop_fight2(){
 return ::stop_fight();
}

init() {
  ::init();
  add_action("gimme","give");
}

gimme(str) {
  string who, what;

  if( (sscanf(str, "%s %s", what, who)==2) && (who == "to lich" ||
  who == "to lancoz")) {
    object ob;
    int value;

    ob = present(what, this_player());

    if(!ob) return 0;
    if(transfer(ob, this_object())) return 0;

    write("You give "+ob->short()+" to Lancoz.\n");
    say(ME+" gives "+ob->short()+" to the Lich.\n");
    value = ob->query_value();

    if(value < 1000) {
      tell_room(ROOM,
      LZ+" hisses: You call this treasure!  Bah!\n"+
      LZ+" hisses: You can do better than this ... I hope.\n"+
      "The Lich's "+HIR+"red eyes"+NORM+" flare dangerously.\n");
      return 1;
    }
    else {
      tell_room(ROOM,
      LZ+" hisses: Ecckkssssellent.\n"+
      LZ+" hisses: You may pass.\n");
      present("lich_gate", ROOM)->add_name(this_player()->query_real_name());
      return 1;
    }
  }
}

kombat(){
  object obj;
  int ranx;

  obj = this_object()->query_attack();
  ranx = random(10);

  if(!obj) {
    call_out("kombat", 15);
    return 1;
  }

  if(!present(obj, environment(this_object()))){
    this_object()->stop_fight2();
    call_out("kombat", 10);
    return 1;
  }

  if(ranx == 0) {
    tell_room(ROOM,
    "Lancoz's "+HIR+"fire red eyes"+NORM+" burn deep into your soul!\n");
    obj->hit_player(10+random(10), "other|evil");
  }
  else if(ranx == 1) {
    tell_room(ROOM,
    LZ+" reaches "+HIB+"deep"+NORM+" into your soul!\n"+
    "You "+HIY+"tremble"+NORM+" in helpless terror!\n");
  }
  else if(ranx == 2) {
    tell_room(ROOM,
    LZ+" casts a "+HIR+"Blazing Death"+NORM+" spell over "+IT+"!\n"+
    IT+"'s writhes and twists in unbearable "+HIY+"agony!\n"+NORM);
    tell_object(obj,
    "You fall to the ground and clutch your chest!\n");
    obj->hit_player(30+random(30), "other|evil");
  }
  else if(ranx == 3) {
    if(!obj->is_player() || random(50) == 13) {
      tell_room(ROOM,
      HIC+"Lancoz hisses evily and slashes "+IT+" across the chest!\n"+
      "The evil lich reaches into "+IT+"'s open chest and rips out his heart!\n"+NORM);
      tell_room(ROOM, 
      HIR+"Lancoz holds "+IT+"'s beating heart in his hand!!!\n"+NORM);
      tell_object(obj, HIW+"Lancoz rips your heart out of your body!\n"+NORM);
      obj->hit_player(10001);
      call_out("kombat", 3);
      return 1;
    }
    else {
      tell_room(ROOM,
      LZ+" slashes at "+IT+" and narrowly misses.\n");
    }
  }
  else if(ranx == 5) {
    tell_room(ROOM,
    "The powerful Lich casts a "+HIC+"Torment"+NORM+" spell.\n"+
    IT+" writhes "+HIR+"in horrible pain!\n"+NORM);
    tell_object(obj, "Your body screams in agony!\n");
    obj->hit_player(20+random(50), "other|evil");
  }
  else if(ranx == 6) {
    tell_room(ROOM,
    LZ+" the Undead grows "+HIC+"stronger"+NORM+" off your fears.\n"+
    "You feel tired and weary.\n");
    obj->heal_self(-random(50));
    this_object()->heal_self(20+random(50));
  }
  else if(ranx == 7) {
    tell_room(ROOM,
    LZ+" calls on powers from beyond the grave!\n"+
    "The chamber darkens ominously.\n");
  }
  else if(ranx == 9) {
    tell_room(ROOM,
    "The evil Lich "+HIM+"grasps"+NORM+" "+IT+" with an evil claw.\n"+
    HIR+"Jagged lacerations"+NORM+" appears up "+IT+"'s arm and begins to "+HIR+"bleed!\n"+NORM);
    obj->hit_player(random(40), "other|evil");
  }

  if(obj->query_npc() || obj->is_pet()) obj->hit_player(30);

  call_out("kombat", 6);
  return 1;
}

monster_died(){
  tell_room(environment(this_object()),
  "The Lich's badly beaten body falls to the dust.\n"+
  "A soft voice echoes throughout the chamber:\n"+
  "FRREEEEEEEEEEE  FIIIIINNNAAALLLLYYYYYYY FREEEEEEEEEEEEE\n");
  destruct(present("corpse", environment(this_object())));
  return 0;
}
