/* Changed from hp500 to 600, wc20 to 40, added spell effects -Snow */
inherit"obj/monster";

reset(arg) {
   ::reset();

   if(!arg) {

   set_name( "reaper" );
   set_alias( "grim reaper" );
   set_short( "The Grim Reaper" );
   set_long(
"You can barely make out the shape and colors of a skull underneath the hood"+
"\n of his robe.  The is the Grim Reaper, and he carries a scythe that looks"+
"\nsharper than a ginsu.  He calls your name softly...\n");

   set_level(20);
   set_hp(600);
   set_ac(20);
   set_wc(40);
   set_aggressive(1);

   set_chance(25);
   set_spell_dam(20);
   set_spell_mess1("The Reaper slices into his prey!\n");
   set_spell_mess2("The Reaper slices into you!\n");

   set_chat_chance(40);
   load_chat("The reaper beckons you to him.\n");
   load_chat("The reapers formless face calls to you.\n");
   set_a_chat_chance(60);
   load_a_chat("An eerie voice echoes from the reaper: 'Romeo and juliet "+
               "will be together for eternity...'\n");
   load_a_chat("'Come on baby....'\n");
   load_a_chat("'Come feel the reaper...'\n");
   load_a_chat("'We can be like they are...'\n");
   load_a_chat("'Baby take my hand...'\n");

   }
}
