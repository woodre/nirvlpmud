inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
object ob, ob2, gold;
gold = clone_object("/players/saber/gems/sapphire.c");
move_object(gold,this_object());
  ob = clone_object("/players/saber/weapons/spiritsword.c");
move_object(ob,this_object());
 ob2 = clone_object("/players/saber/armor/age.c");
move_object(ob2,this_object());
     set_name("he Who Must Wait");
     set_alt_name("He Who Must Wait");
     set_short("He Who Must Wait <Guardian>");
     set_race( "immortal");
     set_alias("guardian");
     set_long("The Guardian of the Icey Realms, He Who Must Wait is the incarnation of the\n"+
          "mountain watcher.  He has lived many lives, and will rise again after this one.\n"+
          "He Who Must Wait is waiting for the end of the world.\n");
     set_level(21);
     set_ac(30);
     set_wc(40);
/* Changed due to value of objects and description from 525hp to 1000hp 
 * -Snow */
     set_hp(1000);
     set_al(-1000);
     set_aggressive(0);
     set_chat_chance(10);
     set_a_chat_chance(15);
     load_chat("He Who Must Wait counts quietly.\n");
     load_a_chat("He Who Must Wait counts quietly.\n");
     load_a_chat("He Who Must Wait gazes at you sadly.\n");

     set_spell_mess2("He Who Must Wait points at you and intones:\n\n"+
      "     *                D I E                *\n\n");
     set_spell_mess1("He Who Must Wait points at his foe and intones:\n\n"+
       "     *                D I E                *\n\n");
     set_chance(15);
     set_spell_dam(80);
   }
}
