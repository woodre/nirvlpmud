 inherit "/obj/monster";
  reset(arg) {
    ::reset(arg);
    if (!arg) {
  object ob,ob2;
    ob2 = clone_object("/players/arrina/weapons/revenant.c");
  ob = clone_object("/players/arrina/armor/torque.c");
 move_object(ob,this_object());
       set_name("scribe");
      set_short("Aldren, the Ghost Scribe");
      set_alias("aldren");
      set_race( "ghost");
      set_long("Aldren served the troops faithfully for years, and\n"+
        "was honest with the nobility and the guards.\n");
      set_level(17);
      set_ac(14);
 move_object(ob2,this_object());
     init_command("wield blade");
      set_wc(24);
      set_hp(425);
      set_al(-1000);
      set_aggressive(0);
      set_chat_chance(20);
      set_a_chat_chance(25);
       load_chat("Aldren says: I served loyally and well for years.\n");
       load_chat("Aldren's eyes are blank as he stares through you.\n");
       load_chat("Aldren says: Only I can open the safe.\n");
       load_chat("Aldren says: The evil has consumed my earthly form.\n");
       load_a_chat("Aldren says: I will protect the funds with my life.\n");
       load_a_chat("Aldren moves to stand in front of the safe.\n");
    }
 }
