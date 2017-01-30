inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("monster");
    set_alt_name("monster");
    set_short("A monster");
    set_race( "monster");
    set_alias("monster");
    set_gender("creature");
    set_long("The monster is boring.\n");
    set_level(20);
    set_ac(20);
    set_wc(30);
    set_hp(500);
    set_al(-1000);
    set_aggressive(0);
    set_chat_chance(9);
    set_a_chat_chance(9);
    load_chat("The monster chats.\n");
    load_a_chat("The monster chats while in combat.\n");
  }
}
