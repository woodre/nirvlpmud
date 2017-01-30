inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
object ob;

move_object(clone_object("/players/daranath/qualtor/obj/bil_bl_cloak.c"),this_object());
ob = clone_object("obj/money");
ob->set_money(random(3000)+1000);
/* Total value of 3500 average, 1500 less then monster guide */
move_object(ob,this_object());

     set_name("Dark Stalker");
     set_short("Dark Stalker");
     set_alias("stalker");
     set_alt_name("dark stalker");
     set_race("human");
     set_gender("male");
     set_long("Shadows swirl about the Dark Stalker, a lost spirit floating\n"+
              "about the streets of Qual'tor. No physical form accompanies\n"+
              "the stalker, the swirling shadows making up the\n"+
              "threat of the undead creature.\n");
     set_level(20);

     init_command("wear cloak");

     set_ac(20);
     set_wc(35 + random(4));
     set_hp(700 + random(70));
     set_al(-1000);
     set_aggressive(0);

   }
}
