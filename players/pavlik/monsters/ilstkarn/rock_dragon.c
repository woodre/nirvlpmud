inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Rock Dragon");
  set_alias("dragon");
  set_short("Rock Dragon");
  set_long(
  "The Rock Dragon is a small fierce monster that thrives in the\n"+
  "mountain tops.  Its gray-brown body blends well with the environment\n"+
  "and the Rock Dragon is almost invisible unless you are looking directly\n"+
  "at it.  The Dragon's tail is tipped with a large spiked ball which can\n"+
  "inflict mortal wounds on any enemy.\n");
  set_race("rock dragon");
  if(!random(3)) set_gender("female"); else set_gender("male");
  set_level(18+random(3));
  set_hp(400+random(300));
  set_ac(25+random(6));
  set_wc(20+random(10));
  set_al(-1000);
  set_aggressive(0);
  set_chat_chance(20);
  set_a_chat_chance(40);
  load_chat("The Dragon bites into a large rock.\n");
  load_chat("The Rock Dragon snaps its jaws hungrily.\n");
  load_chat("Rock Dragon looks around for something to eat.\n");
  load_a_chat("Rock Dragon swings its heavy tail at you.\n");
  load_a_chat("The Rock Dragon snaps its jaws at you.\n");
  load_a_chat("The Rock Dragon rakes you with its claws!\n");
  set_chance(15);
  set_spell_dam(50);
  set_spell_mess1(
  "The Rock Dragon SMASHES its enemy with a mighty swing of its tail!");
  set_spell_mess2("\n"+
  "The Rock Dragon SMASHES you into the ground with a mighty\n"+
  "swing of its tail!\n");
  set_dead_ob(this_object());
}

id(str) {
  return str == "dragon" || str == "rock dragon" || str == "rock_dragon" ||
  str == "ilstkarn_monster";
}

monster_died() {
   tell_room(environment(this_object()),
   "The Rock Dragon's body crumbles to dust.  Only the spiked ball of its\n"+
   "once deadly tail remains.\n");
    move_object(clone_object("players/pavlik/items/ilstkarn/dragon_tail"),
    environment(this_object()));
    destruct(present("corpse", environment(this_object())));
    return 0;
}

