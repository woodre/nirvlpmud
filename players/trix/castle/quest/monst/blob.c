inherit "obj/monster";
reset(arg){
   object gold,key;
   ::reset(arg);
   if(arg) return;
   set_name("blob");
   set_race("blob");
   set_alias("blob");
   set_alt_name("blob");
   set_short("A blob");
   set_long("A shapeless mass of dense green liquid. It pulses slightly at the rythem of what\n"+
            "can be euphemistically called its heart. You see a solid object hidden inside\n"+
            "of this semitransparent living substance.\n");
   set_level(17);
   set_hp(500);
   set_al(-2000);
   set_wc(24);
   set_ac(14);
   set_aggressive(0);
   set_chat_chance (15);
   load_chat("The blob pulses.\n");
   load_chat("The blob drools.\n");
   set_chance(5);
   set_spell_dam(random(10)+10);
   set_spell_mess1("The blob chokes you.");
   set_a_chat_chance(10);
   load_a_chat("The blob soakes you with its green substance.\n");
   load_a_chat("The blob drools at you.\n");
   gold=clone_object("obj/money");
   gold->set_money(900 + random(51));
   move_object(gold,this_object());
   key=clone_object("players/trix/castle/quest/monst/key");
   move_object(key,this_object());
}
