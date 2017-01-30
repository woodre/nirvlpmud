inherit "/obj/monster";
object ob,gold;

reset(arg) {
   ::reset(arg);
   if (!arg){
     set_name( "song" );
     set_short("A song");
     set_level(1);
     set_ac(3);
     set_wc(5);
     set_hp(15);
   }
}
