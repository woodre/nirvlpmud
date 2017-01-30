/*  Jurassic Park ranger  */

inherit "obj/monster";
reset(arg) {

object gold;
object gun;
::reset(arg);
if(arg) return;
set_name("ranger");
set_alt_name("jurassic ranger");
set_race("human");
set_short("Park Ranger");
set_alias("park ranger");
set_long(
	"  This ranger is an old hand at controlling animals.  His years\n"+
	"of experience and tested abilities landed him this 'cushy' job.\n"+
	"He is dressed in hunter green clothes to blend into the scenery\n"+
	"and avoid unnecessary confrontration.  By looking at him, how-\n"+
	"ever, it doesn't look like he'd run from a fight.\n");

set_hp(725);
set_level(21);
set_al(100);
set_aggressive(0);

gun = clone_object("players/eurale/Wep/stgun.c");
move_object(gun,this_object());
init_command("wield gun");
set_ac(17);
set_wc(30);
set_dead_ob(this_object());

set_chat_chance(5);
  load_chat("The ranger says:  Shhhsssssss... there's danger about.\n");
  load_chat("The ranger stoops to check out a fresh track.. \n");

gold = clone_object("obj/money");
gold->set_money(random(100)+3900);
move_object(gold,this_object());
}

monster_died() {
tell_room(environment(this_object()),
  "As the ranger falls, you hear a 'ping' like something metal striking\n"+
  "a stone as it falls to the ground.\n");
move_object(clone_object("players/eurale/Park/OBJ/spade"),
  environment(this_object()));
return 0; }
