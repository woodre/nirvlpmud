#define ROOT "/players/daranath/qualtor/newstuff/"

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
object ob, ob2, ob3, ob4;

 ob = clone_object("obj/money");
 ob->set_money(random(200) + 120);
  move_object(ob, this_object());
 ob2 = clone_object(ROOT+"weps/bl_axe.c");
  move_object(ob2, this_object());
 ob3 = clone_object("/players/daranath/arms/dwarf_chain.c");
  move_object(ob3, this_object());
 ob4 = clone_object("/players/daranath/arms/dwarf_helm.c");
  move_object(ob4, this_object());

set_name("Dwarven barricade guard");
set_short("Barricade Guard <dwarf>");
set_alias("guard");
set_alt_name("citymon");
set_race("dwarf");
set_gender("male");
set_long("When the Qual'tor barricades first came up, there were no shortage\n"+
         "of dwarven volunteers. Trade with Qual'tor is essential to the\n"+
         "dwarven nation, they want to see the city restored to its full glory.\n");
set_level(16);

init_command("wear armor");
init_command("wear helm");
init_command("wield axe");

set_ac(13);
set_wc(20 + random(6));
set_hp(250 + random(120));
set_al(500);
set_aggressive(0);

   }
}
