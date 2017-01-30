inherit "obj/monster";
object ob;
reset(arg) {
::reset(arg);
if(arg) return;
weapon();
set_name("pig");
set_alias("porky");
set_short("Porky Pig");
set_long("Porky usually hangs out here when he is not making cartoons.\n");
set_al(0);
set_level(6);
set_wc(7);
set_hp(50);
set_ac(4);
set_aggressive(0);
init_command("wield dagger");
}

weapon() {
  ob=clone_object("players/grimm/weapons/sword_8");
  move_object(ob,this_object());
  return 1;
}
