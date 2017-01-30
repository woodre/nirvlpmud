inherit "obj/monster.c";
reset(arg) {
    ::reset(arg);
    if(!arg) {
      object item;
    item = clone_object(" filename ");
  move_object(item, this_object());
  command("wear/wield item", "monster_name");
set_name("   ");
set_alias("  ");
set_short("   ");
set_long("    \n"+
  "      \n");
set_level(#);
set_wc(#);
set_ac(#);
set_hp(#);
set_al(#);
set_gender(#);
set_chat_chance(#);
load_chat("    \n");
set_a_chat_chance(#);
load_a_chat("    \n");
set_chance(#);
set_spell_dam(#);
set_spell_mess1("    \n");
  }
}
