/*  Music for Bard Sight */

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg){
     set_name( "a chord of music" );
     set_alias("music_note");
     set_race("chord");
     set_short("A chord of music");
     set_level(1);
     set_ac(1);
     set_wc(1);
     set_hp(1);
     enable_commands();
     
     call_out("bye_bye",3);
   }
}

bye_bye()  {
  say("The music drifts off into the sky.\n");
  destruct(this_object());
  return 1;
    }
