inherit "/obj/monster";
object flu;

reset(arg) {
   ::reset(arg);
   if (!arg) {
   object ob, ob2;
   ob = clone_object("/players/saber/weapons/bane.c");
   move_object(ob,this_object());
   ob2 = clone_object("/players/saber/armor/bshield.c");
   move_object(ob2,this_object());
     set_name( "guard" );
     set_short("A Temple guard of Arate");
     set_race( "human");
     set_gender("male");
     set_long("An evil looking man with a dark black eyepatch.\n"+
              "He is wielding a blade that seems to pulse with evil power.\n");
     set_level(18);
     set_ac(16);
     set_wc(24);
     set_hp(425);
     set_al(-1000);
     set_frog(1);
     set_aggressive(0);
     set_chat_chance(20);
     set_a_chat_chance(25);
     load_chat("You begin to feel sick.\n");
     load_chat("You begin to feel sick.\n");
     load_chat("The man glares at you.\n");
     load_chat("The man fingers his blade.\n");
     load_a_chat("The man says: You'll be sorry.  My masters will revenge me.\n");
     load_a_chat("The man calls for additional guards.\n");
     load_a_chat("The man punches you.\n");

     set_spell_mess1("The guardsman of Arate curses his foe.\n");
     set_spell_mess2("The guardsman of Arate curses you.\n");
     set_chance(20);
     set_spell_dam(10);
   }
}

init()  {
  ::init();
  add_action("fff","fff");
  if(this_player()->query_level() > 5)  {
    if(!present("flu", this_player()))  {
      if(this_player()->is_player())    {
        if(random(10) > 6)              {
        flu = clone_object("/players/saber/closed/virus/flu.c");
          move_object(flu, this_player());
          return 1;
            }
            }
            }
            }
            }
