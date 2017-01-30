
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Levin the Trapper");
  set_alt_name("levin");
  set_alias("trapper");
  set_short("Levin the Trapper");
  set_long(
"Levin is short, stocky, and wears a patch over his left eye.\n"+
"He has a thin and scraggly beard and sideburns.  He wears a\n"+
"wide-brimmed hat and an earthy brown cloak.\n"
);
  set_gender("male");
  set_race("human");
  set_level(19);
  set_ac(17);
  set_hp(450);
  set_al(150);
  add_money(700);
  set_chat_chance(5);
  load_chats( ({
    "The Trapper mutters to himself.\n",
             "The Trapper's beady eyes dart back and forth as he studies the woods.\n"
  }));
  set_a_chat_chance(8);
  load_a_chat("Levin darts in and out of the trees, using the woods for cover.\n");
  set_chance(12);
  set_spell_mess1(
"\nThe Trapper's knife flies through the air, hitting his foe with a loud\n"+
"\t\t\t* T H U N K *\n\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"\nThe Trapper's knife flies through the air, hitting you with a loud\n"+
"\t\t\t* T H U N K *\n\n"
  ); /* 1ST PERSON */
  set_spell_dam(15);
  if(!present("cloak")) {
    object cloak;
    cloak=clone_object("/players/feldegast/equip/bcloak");
    move_object(cloak,this_object());
    init_command("wear cloak");
  }
  if(!present("axe")) {
    object axe;
    axe=clone_object("/players/feldegast/wep/woodaxe");
    move_object(axe,this_object());
    init_command("wield axe");
  }
  set_wc(28);
  set_ac(17);
}

heart_beat() {
  ::heart_beat();
  if(hit_point < 50)
    if(random(3)) tell_room(environment(),"The trapper says: PLEASE DON'T HURT ME!!!\n");
}
