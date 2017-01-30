inherit "obj/monster";

reset(arg)
{
  if (arg) return;
  ::reset(arg);
  set_name("Takquel");
set_alias("takquel");
  set_short("Takquel, Guardian of the Sword of Water");
  set_long("Takquel, A being from the sea, it's body is covered with\n"+
           "gill like structures.  It's back is serated with fins.\n"+
           "The hands and toes are webbed.  It's face is ardorned with\n"+
           "dangling seaweed like stuff.  It's eyes swivel towards you\n"+
           "threatingly....\n");
  set_level(23);
  set_ac(20);
  set_wc(36);
  set_hp(650); /* This wasn't even set! -F */
  set_al(-100);
  set_aggressive(1);
  set_chat_chance(8); /* Lowered from 40%. */
  load_chat("Strange gurgling sounds come from Takquel...\n");
  load_chat("Takquel says: Santhu, dilir bo !!!\n");
  load_chat("Takquel shouts: HATRATHA FRUDEM QWED !\n");
  load_chat("squish,  sqoosh, squish\n");
  set_chance(35);
  set_spell_mess1("");
  set_spell_mess2("You are hit with the force of a thousand tidal waves!!!\n");
  set_spell_dam(100);
}
