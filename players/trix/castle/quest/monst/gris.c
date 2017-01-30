inherit "obj/monster";
reset(arg){
   object gold,axe;
   ::reset(arg);
   if(arg) return;
   set_name("grishnakh");
   set_race("orc");
   set_alias("orc");
   set_short("Grishnakh, a huge orc");
   set_long("This is Grishnakh, a huge black orc, he's the chief of a forgotten legion of\n"+
           "orcs, he won't let you exit his cove unless you kill him.\n");
   set_level(19);
   set_hp(475);
   set_al(1000);
   set_wc(28);
   set_ac(16);
   set_aggressive(0);
   set_chat_chance (15);
   load_chat("Grishnakh says: Hmmm, how can it be?\n");
   load_chat("Grishnakh says: How could a little human reach this place?\n");
   load_chat("Grishnakh says: You know you won't leave this place alive, don't you?\n");
   set_chance(10);
   set_spell_dam(random(5)+5);
   set_spell_mess1("Grishnakh hits you with the back of his huge hand.");
   set_spell_mess2("Grishnakh kicks you very hard.");
   gold=clone_object("obj/money");
   gold->set_money(450 + random(50));
   move_object(gold,this_object());
   axe=clone_object("players/trix/castle/quest/monst/gaxe");
   move_object(axe,this_object());
}
