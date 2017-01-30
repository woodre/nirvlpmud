/* a generic monster set-up */

inherit "obj/monster";
reset(arg) {

::reset(arg);
if(arg) return;
set_name("pteranodon");
set_race("creature");
set_short("Pteranodon");
set_alias("don");
set_long(
	"  The greatest of the pterosaurs was the Pteranodon.  It's wing \n"+
	"span was 25 feet and it had a beak like a bird.  It also had a \n"+
	"huge bony crest on the back of its head. \n");
set_level(20);
set_hp(500 + random(50));
set_al(-1);
set_aggressive(1);
set_dead_ob(this_object());

set_wc(30);
set_ac(17);


set_chat_chance(5);
  load_chat("The pteranodon wobbles awkwardly toward you.. \n");
set_a_chat_chance(7);
  load_a_chat("\nThe pteranodon pecks viciously at you.. \n\n");
  load_a_chat("The pteranodon SQUAWKS loudly... \n");

}

monster_died() {
tell_room(environment(this_object()),
  "As the giant pteranodon dies, you see the reason it has fought so\n"+
  "so relentlessly to protect its nest.\n");
move_object(clone_object("players/eurale/Park/OBJ/pter_egg"),
  environment(this_object()));
return 0; }
