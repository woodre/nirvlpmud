inherit "obj/monster.c";
reset(arg) {
   ::reset(arg);
   if(!arg) {
      object key;
      key = clone_object("players/sandman/OBJ/key");
      move_object(key, this_object());
      set_name("fandral");
      set_alias("dashing warrior");
      set_short("Fandral");
      set_long("The daper, glib leader of the Warriors Three.\n");
      set_ac(14);
      set_wc(24);
      set_race("immortal");
      set_level(17);
     set_hp(350); /* Changed from 425. -Feldegast 1/26/01 */
      set_al(200);
      set_chat_chance(10);
      load_chat("Fandral laughs: What do we have here?\n");
      load_chat("Fandral cracks: come my rotund and somber friends let us go.\n");
      set_a_chat_chance(15);
      load_a_chat("Frandral yells: Prepare to join Hela mortal!\n");
     add_money(1000+(50*random(36))); /* 1000-2800 */
   }
}
