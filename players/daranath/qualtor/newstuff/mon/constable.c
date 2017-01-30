#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
inherit "players/mythos/amon/forest/monster1";
object gold;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

/* Average value of kill, 4450 coins, 550 less then monster guide */
 gold = clone_object("obj/money.c");
  gold->set_money(1000+random(2000));
  move_object(gold, this_object());
move_object(clone_object(ROOT+"junk/mithril.c"),this_object());
move_object(clone_object(ROOT+"junk/surcoat1.c"),this_object());
move_object(clone_object(ROOT+"weps/keen_rapier.c"),this_object());

set_name("Qual'tor Constable");
set_alias("constable");
set_alt_name("citymon");
set_race("human");
set_gender("male");
set_short("Constable of Qual'tor");
set_long("Standing tall and watching over Qual'tors new Marketplace, the new Constable\n"+
         "of City Ward is one of the strongest warriors in the city. Wearing light\n"+
         "chainmail armor and carrying a wicked looking rapier, he rapidly discourages\n"+
         "crime within the area.\n");
set_level(20);

init_command("wear surcoat");
init_command("wear armor");
init_command("wield rapier");

set_hp(500+random(100));
set_al(1000);
set_wc(30);
set_ac(17);
set_aggressive(0);

set_mult(2);
set_mult_chance(20);
set_mult_dam1(15);
set_mult_dam2(25);

}
