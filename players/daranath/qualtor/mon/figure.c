inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
object ob;

move_object(clone_object("/players/daranath/qualtor/obj/gob_cryst.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/obj/sm_ruby.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/newstuff/weps/dark_blade3.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/obj/bil_bl_cloak.c"),this_object());
ob = clone_object("obj/money");
ob->set_money(random(2000)+1000);
/* Average coins of 2000 + 4000 from objs for 6000 total per monster guide */
move_object(ob,this_object());

     set_name("Dark Figure");
     set_short("A dark figure with a billowing cloak");
     set_alias("figure");
     set_alt_name("dark figure");
     set_race("human");
     set_gender("male");
     set_long("A billowing black cloak engulfs the figure, shadows\n"+
              "intermixing with the form making it difficult to make out\n"+
              "any details. Darkness itself seems to be his ally, as\n"+
              "he stands watch here in Scimitar Alley.\n");
     set_level(21);

     init_command("wield blade");
     init_command("wear cloak");

     set_ac(20);
     set_wc(35 + random(4));
     set_hp(700 + random(70));
     set_al(-1000);
     set_aggressive(0);
     set_chat_chance(10);
     set_a_chat_chance(10);
     load_chat("The cloak swirls about in the breeze.\n");
     load_chat("The cloak moves torwards you as if it were alive.\n");
     load_a_chat("Dark Figure cuts into you with the Dark Blade.\n");

   }
}
