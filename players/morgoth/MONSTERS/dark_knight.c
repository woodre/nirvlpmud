inherit "obj/monster";

reset(arg)
{
  if (arg) return;
  ::reset(arg);
  set_name("dark knight");
  set_alias("knight");
  set_short("A dark knight");
  set_long("A dark knight.  He is dressed in armor that is\n"+
           "black as night.  It's almost as if the armor absorbs\n"+
           "all light.  The knight is not real tall but appears very\n"+
           "strong.\n");
  set_level(17);
  set_ac(14);
  set_hp(400);
  set_wc(24);
  set_chat_chance(8); /* Lowered from 40% to 8%. -Feldegast 10-6-00 */
  load_chat("AHHH... what a nice day to maim and kill !!\n");
  load_chat("So, have you come to kill or be killed ?\n");
  set_chance(35);
  set_spell_mess1("");
  set_spell_mess2("You feel excrutiating pain as the dark blade slices into you !\n");
  set_spell_dam(20);
}
