#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
inherit "players/mythos/amon/forest/monster1";
object ob1, ob2, ob3;
reset(arg)  {
  ::reset(arg);
  if(arg) return;

 ob1 = clone_object(ROOT+"obj/phantom_aura.c");
  move_object(ob1, this_object());
 ob2 = clone_object(ROOT+"weps/phantom_blade.c");
  move_object(ob2, this_object());
 ob3 = clone_object("obj/money.c");
  ob3->set_money(2000+random(2000));
  move_object(ob3, this_object());

set_name("Gloom Assassin");
set_alias("gloom");
set_alt_name("assassin");
set_race("undead");
set_short();
set_long("A rare form of undead that took the body of one of Gundar's former\n"+
         
         "assassins, the Gloom would take over the body used to combat and\n"+
         "killing, feeding off its negative energy.\n");
set_hp(600+random(200));
set_level(20);
set_al(-1000);
set_wc(34+random(8));
set_ac(19+random(3));
set_heal(5,10);
set_aggressive(1);
  
set_dead_ob(this_object());

set_chance(25);
set_spell_dam(25+random(50));
set_spell_mess1("The form of a glowing spirit materializes and slashes at its foe.\n");
set_spell_mess2("The Gloom Assassin materials in front of you, slashing with the phantom\n"+
          "scimitars, drawing blood and tearing into your soul.\n");

set_mult(2);
set_mult_chance(30);
set_mult_dam1(12);
set_mult_dam2(10);

}

monster_died() {
write_file("/players/daranath/closed/log/gloom_death",ctime(time())+"\t"+
  (this_object()->query_attack())->query_real_name()+"\t\t"+
  (this_object()->query_attack())->query_level()+"\n");
write("\n");
write("The Gloom flees the body of the dead assassin, leaving only the husk\n"+
      "behind. A howl can be heard off in the distance.\n");
write("\n");
return 0;
}
