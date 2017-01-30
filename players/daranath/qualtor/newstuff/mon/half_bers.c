#define ROOT "/players/daranath/qualtor/newstuff/"

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
object ob, ob2, ob3;

 ob = clone_object("obj/money");
 ob->set_money(random(400) + 120);
  move_object(ob, this_object());
 ob2 = clone_object(ROOT+"weps/half_axe.c");
  move_object(ob2, this_object());
 ob3 = clone_object(ROOT+"obj/half_leather.c");
  move_object(ob3, this_object());

set_name("Halfling Gladiator");
set_short("An insane looking halfling");
set_alias("gladiator");
set_alt_name("arenamon");
set_race("halfling");
set_gender("male");
set_long("A wild and feral looking halfling, this young male spent some time\n"+
         "battling within the arenas far to the south. Now, with Qual'tor\n"+
         "being rebuilt, he has come here, hoping for the Arena to reopen.\n");
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
