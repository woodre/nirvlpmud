inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
object ob;
  ob = clone_object("obj/money");
  ob->set_money(random(440) + 500);
  move_object(ob, this_object());

move_object(clone_object("/players/daranath/qualtor/folk/obj/chainmail.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/folk/obj/helm.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/folk/obj/longsword.c"),this_object());

set_name("Qual'tor Guardsman");
set_short("Qual'tor Town Guardsman");
set_alias("guard");
set_alt_name("guardsman");
set_race("human");
set_gender("male");
set_long("The newly formed Qual'tor Town Guard has been created due to the\n"+
         "increased activity now that the city is being rebuilt. The\n"+
         "guardsmen handle any dangers that the average citizen cannot.\n"+
         "They bring a sense of calm during the rebuilding process.\n");
set_level(17);

init_command("wear chainmail");
init_command("wear helm");
init_command("wield longsword");

set_ac(14);
set_wc(22 + random(8));
set_hp(400 + random(120));
set_al(950);
set_aggressive(0);
set_chat_chance(2);
set_a_chat_chance(15);
load_chat("Qual'tor Guardsman looks you over.\n");
load_chat("Qual'tor Guardsman gives you a stern look.\n");
load_chat("Qual'tor Guardsman says: Move along.\n");
load_a_chat("Qual'tor Guardsman parries your blow.\n");
load_a_chat("Qual'tor Guardsman growls and attacks you with a sense of duty.\n");

   }
}
