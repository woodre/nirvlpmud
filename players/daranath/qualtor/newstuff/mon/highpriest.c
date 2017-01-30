#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
inherit "players/mythos/amon/forest/monster1";
reset(arg)  {
  ::reset(arg);
  if(arg) return;

move_object(clone_object(ROOT+"obj/holy_vestm.c"),this_object());
move_object(clone_object(ROOT+"obj/holy_mitre.c"),this_object());
move_object(clone_object(ROOT+"weps/dmace_min.c"),this_object());

set_name("Qual'tor High Priest");
set_alias("priest");
set_alt_name("high priest");
set_race("human");
set_short("High Priest of Qual'tor");
set_long("The High Priest is usually selected from amongst the strongest of\n"+
         "Qual'tor's temple Paladins. They are given the magical Mace\n"+
         "of Distruption and wage battle against the undead forces\n"+
         "within the city.\n");
set_level(20);

init_command("wear mitre");
init_command("wear armor");
init_command("wield mace");

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
