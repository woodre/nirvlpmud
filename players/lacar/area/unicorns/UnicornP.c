inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
set_name("Unicorn");
  set_race("unicorn");
  set_alias("lacar's_beloved_unicorn");
set_short("A White Unicorn");
set_long("Muscular unicorn with gold horn, flowing mane and tail.\n");
set_level(50);
set_hp(2500);
set_al(0);
set_wc(60);
set_ac(30);
  set_chat_chance(2);
  load_chat("White unicorn prances around the room.\n");
  load_chat("White Unicorn neighs,\"play time!\"\n");
  load_chat("\"Stop work and play\", says Unicorn.\n");
  load_chat("Unicorn nudges you with his horn.\n");
}

  
