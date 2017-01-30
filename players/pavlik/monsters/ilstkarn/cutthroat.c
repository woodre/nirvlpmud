inherit "/obj/monster";
#define IT capitalize(obj->query_name())

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Cutthroat");
  set_alias("cutthroat");
  set_short("A desperate Cutthroat");
  set_long(
  "This haggard thief has been locked away in the dungeons for many\n"+
  "years.  He has been digging a tunnel with his sharpened spoon for\n"+
  "countless years, however I'm sure he will find going through you\n"+
  "an easier means of escape.\n");
  set_race("thief");
  if(!random(2)) set_gender("male"); else set_gender("female");
  set_level(15+random(5));
  set_hp(225+random(275));
  set_ac(12+random(15));
  set_al(-random(1000));
  set_aggressive(1);
  set_a_chat_chance(40);
  load_a_chat("Thief says: Get out of my way!\n");
  load_a_chat("Cutthroat slices you with his sharpened spoon!\n");
  load_a_chat("Cutthroat deftly rolls out of the way.\n");
  load_a_chat("The thief appraises your belongings.\n");
  load_a_chat("The thief tries to sneak behind you for a backstab.\n");
  move_object(clone_object("players/pavlik/weapons/sharp_spoon"), this_object());
  move_object(clone_object("players/pavlik/items/heals/bread"), this_object());
  init_command("wield spoon");
  set_wc(20+random(15));
  set_dead_ob(this_object());
  money = 100+random(200);
 if(!root())
  call_out("steal", 10);
}

id(str) {
  return str == "cutthroat" || str == "thief" || str == gender ||
  str == "ilstkarn_monster";
}

stop_fight() {
  if(this_player()->query_level() > 20) {
    ::stop_fight();
    return 1;
  }
  return;
}

steal() {
  object ob, obj;
  int i;

  obj = query_attack();

  if(obj || !environment()) { 
    call_out("steal", 35);
    return 1;
  }

  if(!present(obj, environment())) {
    call_out("steal", 15);
    return 1;
  }

  ob = obj->all_inventory();
  i = random(sizeof(ob));

  if(ob[i]->drop() && random(13)==4) {
    tell_room(environment(),
    "The desperate Cutthroat stumbles and bumps into "+IT+".\n");
    tell_object(obj,
    "The Cutthroat bumps into you ... something strange just happened.\n");
    transfer(ob[i], this_object());
  }

  call_out("steal", 10+random(50));
  return 1;
}

monster_died() {
  if(!random(4)) {
    move_object(clone_object("players/pavlik/items/ilstkarn/teleport_key"), present("corpse", environment()));
  }
  return 0;
}

