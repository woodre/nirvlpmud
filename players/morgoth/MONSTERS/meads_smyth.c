inherit "obj/monster";

reset(arg)
{
  if (arg) return;
  ::reset(arg);
  set_name("mead smyth");
  set_alias("smyth");
  set_short("A mead smyth");
  set_long("A strong burly mead smyth.  His job is considered very\n"+
           "important in castle life.  He is to assure that there\n"+
           "is plenty of mead for the knights to drink every day.\n"+
           "He is very strong for it is hard work to stir the thick\n"+
           "barley, oats, wheat, and yeast mixture.  It takes many\n"+
        "hours of heating and stirring to get it just right.\n");
  set_level(17);
  set_ac(14);
  set_wc(24);
  set_chat_chance(40);
  load_chat("Get your foul hands out of my mead kettle you swamp rat !\n");
  load_chat("Wait your turn !\n");
  set_chance(35);
  set_spell_mess2("The mead smyths laddle crashes into your skull !!\n");
  set_spell_dam(20);
}
