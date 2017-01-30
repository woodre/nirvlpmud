#define ROOT "/players/daranath/qualtor/newstuff/"

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
object ob, ob2, ob3, ob4;

 ob = clone_object("obj/money");
 ob->set_money(random(200) + 120);
  move_object(ob, this_object());
 ob2 = clone_object(ROOT+"weps/half_axe.c");
  move_object(ob2, this_object());
 ob3 = clone_object(ROOT+"obj/half_leather.c");
  move_object(ob3, this_object());
 ob4 = clone_object(ROOT+"obj/leather_cap.c");
  move_object(ob4, this_object());

set_name("Halfling barricade guard");
set_short("Barricade Guard <halfling>");
set_alias("guard");
set_alt_name("citymon");
set_race("halfling");
set_gender("male");
set_long("When the other races of the land sent warriors to help hold the city\n"+
         "and rebuild Qual'tor, the halflings felt they had no choice but\n"+
         "to send a few young halflings to help, even if they didn't want\n"+
         "to go. Halflings are not the best fighters.\n");
set_level(16);

init_command("wear armor");
init_command("wear cap");
init_command("wield axe");

set_ac(13);
set_wc(20 + random(6));
set_hp(250 + random(120));
set_al(500);
set_aggressive(0);

   }
}
