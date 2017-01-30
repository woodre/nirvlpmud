inherit "obj/monster";
reset(arg) {
object arm;
::reset(arg);
if(arg) return;
set_name("horror");
set_short("Hook Horror");
set_long("This huge beast is about 9 feet tall with huge hooks at the end of each arm in place of hands. His chest is as tough as any platemail and the beak he has for a mouth is as sharp as any blade. You best think again about attacking him.\n");
set_level(20);
set_hp(700);
set_wc(30);
set_ac(20);
set_al(-100);
set_aggressive(1);
arm=clone_object("players/nightshade/armor/hook_plate");
move_object(arm, this_object());
}
