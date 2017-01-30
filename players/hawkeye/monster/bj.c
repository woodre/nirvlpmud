inherit "/obj/monster";
object ob;

reset(arg) {
   ::reset(arg);
   if (!arg) {
     set_name( "honeycutt" );
     set_short("B.J. Honeycutt");
    set_long("This the B.J. Honeycutt, one of Hawkeye's\n" +
       "two roomates. He looks pretty tough.\n");
     set_alias("bj");
     set_level(20);
     set_ac(17);
     set_wc(30);
     set_hp(500);
     set_al(0);
     set_aggressive(0);
 ob=clone_object("/players/hawkeye/armor/converse.c");
   move_object(ob, this_object());
     money = (4500);
   }
}
