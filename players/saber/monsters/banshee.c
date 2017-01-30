inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
   object ob, ob2;
  ob = clone_object("/players/saber/armor/aura.c");
  move_object(ob, this_object());
  command("wear aura", this_object());
 ob2 = clone_object("/players/saber/stuff/comb.c");
move_object(ob2,this_object());
     set_name( "banshee" );
      set_short();
     set_race( "spirit");
     set_long("The ghost of a beautiful young woman, perhaps of irish descent.  She has long,\n"+
 "silky black hair and eyes red from constant weeping.  The banshee appears so\n"+
 "distracted that she would probably not notice anybody trying to sneak away.\n");
     set_level(20);
     set_ac(21);
     set_wc(33);
     set_hp(500);
     set_al(-700);
     set_aggressive(0);
     set_chat_chance(15);
     set_a_chat_chance(20);
     load_chat("Banshee wails: Goooo noooo furtherrrrrr.\n");
     load_chat("Banshee wails: Whereeee isssss minnnnne daughterrrrrr.\n");
     load_chat("You see something move out of the corner of your eye.\n");
     load_chat("Banshee wails: Nooooooo.  Issssss musssst finnnnnd minnnnne daughterrrrr.\n");
     load_chat("Banshee materializes in front of you.\n");
     load_chat("Banshee fades from view.\n");
     load_a_chat("Banshee wails: Doooooo noooot killssss meeeeeee.\n");
     load_a_chat("Banshee wails: Nooooooo.  Isssss mussssst finnnnd minnnnnne daughterrr.\n");
     load_a_chat("You see something move out of the corner of your eye.\n");
     load_a_chat("Banshee materializes in front of you.\n");
     load_a_chat("Banshee fades from view.\n");
     add_spell("wail",
"\n     THE BANSHEE WAILS\n\n",
"\n     THE BANSHEE WAILS\n\n",
20,70,"other|wind");
/* switched to add_spell format by illarion dec 2004
     set_spell_mess1("\n     THE BANSHEE WAILS \n\n");
     set_spell_mess2("\n   THE BANSHEE WAILS       \n\n");
     set_chance(20);
     set_spell_dam(70);
     */
   }
}
