/* Dark Rider recode. -Snow 3/00 */
inherit "obj/monster.c";
reset(arg) {
  object wep, arm;
  ::reset(arg);
  if(arg) return;
  wep = clone_object("/players/ultramagnus/darkweapon");
  arm = clone_object("/players/ultramagnus/darkarmor");
  move_object(wep, this_object());
  move_object(arm, this_object());
  init_command("wield "+wep->query_name());
  init_command("wear "+arm->query_name());
set_name("rider");
set_alt_name("dark rider");
set_wc(random(10)+20);
set_ac(random(8)+12);
set_level(19);
set_al(-500);
set_hp(random(120)+400);
set_short("A Dark Rider Dressed in Black and Red");
set_long("A Dark Rider Dressed in Black and Red.\n" +
       "He looks at you with Two Red Glowing Eyes!!!\n" +
       "You are not the One that he is Looking for...\n");
set_aggressive(1);
}
