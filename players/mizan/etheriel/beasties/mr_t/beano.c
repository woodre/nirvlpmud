inherit "obj/monster";

reset(arg){
   object gold, what;
   ::reset(arg);
   if(arg) return;
   set_name("Beano");
   set_race("beano");
   set_alias("beano");
   set_short("Beano");
   set_long("This is Beano. It is orange, fuzzy-like, and seems to be made \n"+
  "entirely of light and fuzz. Normally slaughtered in mass numbers at\n"+
  "the hands of everyone, This is a Beano which should not be trifled with.\n");
   set_level(13);
   set_hp(390);
   set_al(0);
   set_wc(6);
   set_ac(3);
   set_chance(1);
   set_spell_dam(4);
   set_spell_mess1("Beano does something to you.");
   set_spell_mess2("Beano ebverflugs you.");
   set_chat_chance(1);
   load_chat("Beano quibbles.\n");
   load_chat("Beano goes: wibble.\n");
   load_chat("Beano does something.\n");
   gold=clone_object("obj/money");
   gold->set_money(random(2)+10);
   move_object(gold,this_object());
   what=clone_object("players/mizan/etheriel/items/thingamajig.c");
   move_object(what, this_object());
}
