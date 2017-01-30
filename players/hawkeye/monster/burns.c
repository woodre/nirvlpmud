inherit "/obj/monster";
object ob;

reset(arg) {
   ::reset(arg);
   if (!arg) {
object ob;
     set_name( "burns" );
     set_short("Frank Burns");
set_long("Frank alias needle nose, alias ferrat face, Burns, the army's biggest pain\n"+
"in the ass. Unfortunately he is a Major.\n");
     set_alias("frank");
     set_level(20);
     set_ac(30);
     set_wc(35);
     set_hp(600);
     set_al(-500);
     set_aggressive(1);
 ob=clone_object("/players/hawkeye/items/bible.c");
   move_object(ob, this_object());
     money = (2832);
   }
}
