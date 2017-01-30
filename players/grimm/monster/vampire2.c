inherit "obj/monster";
object coins, person;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("vampire");
set_short("A Strong Vampire");
set_long("This is a very large and powerful vampire!\n");
set_alias("vampire");
set_level(20);
set_al(-343);
set_hp(500);
set_ac(13);
set_wc(25);
set_aggressive(1);
set_dead_ob(this_object());
}
monster_died(arg) {
  write("You may have beaten me but you are a fool to think i am the great Malachi!!\n");
  write("Malachi will be triumphant and conquer the dark world!!\n");
return 0;
}
