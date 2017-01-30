inherit "obj/monster";

reset(arg)
{
  object weapon, armor;
  ::reset(arg);
  if(arg) return;
  set_name("Draco");
   set_race("Dragon");
  set_alias("draco");
  set_short("Draco");
  set_long("The dragon who stands before you is very deadly. Once\n"+
	"long ago, he lived deep in the caverns of Terl'inok. However,\n"+
	"since the battles of Qit'nor and his home have stopped, he has\n"+
	"found a new place to dwell. Now, lurking in the shadows, he senses\n"+
	"his next meal.... You!\n");
  set_level(10);
  set_hp(400);
  set_al(0);
  set_wc(18);
  set_ac(10);
   weapon=clone_object("/open/EXAMPLES/brutusweap");
  move_object(weapon,this_object());
  armor=clone_object("/open/EXAMPLES/brutusarmor");
  move_object(armor,this_object());
}
