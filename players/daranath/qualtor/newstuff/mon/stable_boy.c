inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

set_name("Stable Boy");
set_short("A young stableboy");
set_alias("stableboy");
set_alt_name("citymon");
set_race("human");
set_gender("male");
set_long("A young boy works here, cleaning the stables in case of visitors to the\n"+
         "city of Qual'tor. His clothes and hair have straw stuck to them as\n"+
         "he diligently goes about his work.\n");
set_level(9);

init_command("wear armor");
init_command("wield weapon");

set_ac(7);
set_wc(12 + random(4));
set_hp(110 + random(45));
set_al(1000);
set_aggressive(0);
set_chat_chance(2);
load_chat("The stableboy sweeps up the area.\n");

   }
}
