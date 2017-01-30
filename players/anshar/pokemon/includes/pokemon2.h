reset(arg)
{
 ::reset(arg);
 if(arg) return;
 set_name(NAME);
 set_race("pokemon");
 set_alias(TYPE);
 set_short(SHORT);
 set_long(LONG);
 set_level(20);
 set_hp(500);
 set_al(0);
 set_wc(30);
 set_ac(17);

 set_chat_chance(2);
 set_a_chat_chance(15);
 load_chat(CHAT);
 load_a_chat(ACHAT);

 set_chance(25);
 set_spell_dam(SPELL);
 set_spell_mess1(SPELL1);
 set_spell_mess2(SPELL2);
}