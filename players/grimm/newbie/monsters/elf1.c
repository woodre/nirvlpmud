inherit "obj/monster";
object ob;
reset(arg) {
::reset(arg);
if(arg) return;
weapon();
set_name("elf");
set_short("An Elf");
set_long("This guy is a young elf who is learning how to fight.\n\tWhy not"
  +" help him out?.\n");
set_al(15);
set_level(1);
set_wc(2);
set_hp(10);
set_ac(2);
set_aggressive(0);
init_command("wield sword");
}

weapon() {
  ob=clone_object("players/grimm/weapons/sword_4");
  move_object(ob,this_object());
  return 1;
}
