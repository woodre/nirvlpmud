inherit "/obj/monster";
object ob,ob1;

reset(arg) {
   ::reset(arg);
   if (!arg) {
     set_name( "blake" );
     set_short("Henry Blake");
    set_long("Standing before you is the colonel of this M*A*S*H camp.\n" +
     "He is wearing a fishing hat and looks quite fond of it\n" +
     "You notice he is rumaging around his desk for a pen, \n" +
    "and you dont think he notices your presense.\n");
     set_alias("henry");
     set_alt_name("colonel");
     set_level(20);
     set_ac(17);
     set_wc(30);
     set_hp(500);
     set_al(100);
  ob=clone_object("/players/hawkeye/armor/fishing.c");
   move_object(ob, this_object());
   ob1=clone_object("/players/hawkeye/items/bourbon.c");
  move_object(ob1, this_object());
     set_aggressive(0);
     money = (3500);
   }
}
