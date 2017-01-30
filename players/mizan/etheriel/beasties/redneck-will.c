inherit "/players/mizan/core/monster.c";

reset(arg)
{
   object gold, what;
   ::reset(arg);

   if(arg) return;
   
   /* descriptions */
   set_name("Redneck Will");
   set_race("redneck");
   set_alias("will");
   set_short("Redneck Will");
   set_long("This is Redneck Will of the Church of the Automatic Transmission.\n"+
   "He is a slightly graying, bearded, heavyset man with the tattoo of a\n"+
   "bowling ball proudly emblazoned on his right arm, and the word 'Jane' on\n"+
   "his left. He comes across as being a less-respected member of the Church\n"+
   "for some reason.\n");
   
   /* vital stats */
   set_level(13);
   set_hp(240 + random(60));
   set_al(0);
   set_wc(17);
   set_ac(10);
   set_chance(10);
   
   /* combat spell stuff */
   set_spell_dam(4);
   set_spell_mess1("Redneck Will tries to kick you!\n"+
       "Redneck Will screams: You communist bastage!\n");
   set_spell_mess2("Redneck Will tries to grope you!\n"+
      "Redneck Will screams: Gitcha self over here!\n");
   
   /* chat related stuff */
   set_chat_chance(10);
   load_chat("Redneck Will says: Where the... hell.. goddamn... am I?\n");
   load_chat("Redneck Will says: Where's my steamroller at?\n");
   load_chat("Redneck Will says: What.. the hell?\n");
   load_chat("Redneck Will says: Oooh. This a'int no so good...\n");
   load_chat("Redneck Will peers about in total confusion.\n");

   /* gold */
   gold = clone_object("obj/money");
   gold->set_money(random(2)+10);
   move_object(gold,this_object());

   /* treasures */
   what=clone_object("players/mizan/etheriel/items/steamroller-pouch.c");
   move_object(what, this_object());
}

