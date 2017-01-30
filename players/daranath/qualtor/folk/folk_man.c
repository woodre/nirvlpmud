inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
object ob, ob2;
  ob = clone_object("obj/money");
  ob->set_money(random(390) + 200);
  move_ob(ob, this_object());
  ob2 = clone_object("/players/daranath/qualtor/folk/obj/name.c");
  move_object(ob2, this_object());

set_name("Townsman from Qual'tor");
set_short("Qual'tor Townsman <worker>");
set_alias("townsman");
set_alt_name("man");
set_race("human");
set_gender("male");
set_long("Long descript here");
set_level(9);

     init_command("wear armor");
     init_command("wield weapon");

set_ac(7);
set_wc(11 + random(5));
set_hp(100 + random(60));
set_al(750);
set_aggressive(0);
set_chat_chance(2);
set_a_chat_chance(15);
load_chat("Townsman grins and waves a greeting.\n");
load_a_chat("Townsman screams for the Qual'tor Guard.\n");

   }
}
