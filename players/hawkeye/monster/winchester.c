inherit "/obj/monster";
object ob;

reset(arg) {
   ::reset(arg);
   if (!arg) {
     set_name( "winchester" );
     set_short("Charles Emerson Winchester III");
     set_long("Major Winchester is listening to his favorite record on his\n" +
       "record player.  He has his eyes closed and is humming along\n" +
       "with the music. You could probably get a cheap shot in.\n");
/* Changed from 'pierce' -Snow 3/00 */
     set_alias("charles");
     set_level(12);
     set_ac(9);
     set_wc(16);
     set_hp(180);
     set_al(0);
     set_aggressive(0);
     set_a_chat_chance(87);
  load_a_chat("Get out of here while i am listening to Mozart!\n");
     load_a_chat("Winchester begins to throw records at you.\n");
     load_a_chat("I am a skilled surgeon, don't attack me!\n");
   ob= clone_object("/players/hawkeye/items/record");
  move_object(ob, this_object());
     money = random(500);
   }
}
