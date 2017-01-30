inherit "/obj/monster.c";
#include "/players/fred/ansi.h";
#define tpn this_player()->query_name()

reset(arg) {
  ::reset(arg);
  if(arg) return;
	
  set_name("venom");
  set_alias("venom_1");
  set_race("Symbiote");
  set_short(""+HIK+"Venom"+NORM);
  set_long("A horrifying Symbiote! This being is completely Dark\n"+
  "Except fot the Whites of his eyes, and mouth. This beast is a \n"+
  "Horrifying sight.\n");
  add_money(4000+random(2000));
  set_level(21);
  set_hp(1200+random(250));
  set_al(-800);
  set_ac(22+random(4));
  set_wc(40);
  set_aggressive(0);
  move_object(clone_object("/players/sami/area/carnival/obj/armors/belt.c"),this_object());
init_command("wear belt");

   }