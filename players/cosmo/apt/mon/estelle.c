#include "/players/cosmo/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name(HIY+"Estelle"+NORM);
set_alias("estelle");
set_alt_name("castanza");
set_race("human");
set_short("Mrs. Estelle Castanza");
set_long(
  "  Estelle is quite the opposite of her husband: quiet,\n"+
  "bashful, introverted. This is obviously where George got\n"+
  "most of his genes.  Estelle is definitely old-school\n"+
  "material; she doesn't understand much about today's\n"+
  "generation.  However, she loves her Georgie very much.\n");

set_level(11);
  set_hp(240);
  set_al(100);
  set_wc(6);
  set_ac(14);
  set_heal(3,20);
  set_aggressive(0);
  set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("Estelle quietly asks: Have you seen my Georgie?\n");
set_a_chat_chance(15);
  load_a_chat("Estelle cries out: Oh dear! I never hurt anybody.\n");

gold = clone_object("obj/money");
gold->set_money(350+random(100));
move_object(gold,this_object());
}

monster_died() {
object ob;
  ob = present("frank", environment());
  if(ob) {
    ob->attack_object(this_player());
    tell_room(environment(),
	"Frank roars angrily: Now you've done it!\n"+
        "You cower in fear from his mighty bark.\n"); }
  else {
    tell_room(environment(),
        "The room suddenly becomes very silent.\n"); }
return 0; }
