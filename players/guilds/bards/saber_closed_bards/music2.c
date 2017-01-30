inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg){
     set_name( "a chord of music" );
     set_alias("music");
     set_alt_name("chord");
     set_short("A chord of music");
     set_level(1);
     set_ac(1);
     set_wc(1);
     set_hp(1);
   }
}
