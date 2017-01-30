inherit "obj/monster";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("Unicorn");
  set_race("unicorn");
  set_alias("queen");
  set_short("White Queen Unicorn");
  set_long("Female sleek unicorn with silver horn, flowing mane and tail.\n"+
           "She has a gold chain on her neck and is very regal laying there.\n");
  set_level(50);
  set_hp(100);
  set_wc(100);
  set_ac(100);
  set_al(100);
  set_chat_chance(2);
  load_chat("Queen asks, Have you seen my son? Goblins stole him.\n");
  load_chat("Can you find him for me?\n");
  add_money(500);
}
