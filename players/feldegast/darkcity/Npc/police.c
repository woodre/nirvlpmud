inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(!present("club")) {
    object club;
    club=clone_object("/obj/weapon");
    club->set_name("club");
    club->set_short("Billy club");
    club->set_long("This is a standard black policeman's billy club.\n");
    club->set_weight(1);
    club->set_value(250);
    club->set_class(13);
    club->set_type("club");
    move_object(club,this_object());
  }
  if(arg) return;
  set_name("Policeman");
  set_alt_name("policeman");
  set_alias("man");
  set_short("Policeman");
  set_long(
"This is a tall beat cop wearing a blue uniform and a cap.\n"+
"Though he doesn't carry a gun, he does have a billy club\n"+
"slung through his belt.\n"
);
  set_gender("male");
  set_race("human");
  set_level(11);
  set_wc(9);
  set_ac(15);
  set_hp(165);
  add_money(250);
  set_al(random(500));
  set_chat_chance(1);
  load_chat("Policeman says: I heard another hooker got iced.\n");
  load_chat("Policeman looks at you suspiciously.\n");
  load_a_chat("Policeman beats you with his billy club.\n");
  set_a_chat_chance(4);
  
}
