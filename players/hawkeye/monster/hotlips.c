inherit "/obj/monster";
object ob;

reset(arg) {
   ::reset(arg);
   if (!arg) {
     set_name( "hotlips" );
     set_short("Hotlips");
set_long("Margaret 'Hot Lips' Houlihan is a very gun ho army nurse\n" +
"She has a very nasty streak in her, be careful!.\n");
     set_alias("hotlips");
     set_level(15);
     set_ac(9);
     set_wc(30);
     set_hp(300);
     set_al(-500);
     set_aggressive(1);
     money = (1500);
   }
}
