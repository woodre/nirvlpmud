/* This is the final monster in the quest...if the player meets it they
screwed up on the quest and have to start over...this creature is here
to help them decide in a rushed way to leave the room (snicker) */
inherit "obj/monster";
object coins;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("malachi");
set_long("This is the Master Vampire Malachi.\n");
set_short("Malachi");
set_alias("vampire");
set_al(-1000);
set_level(30);
set_aggressive(1);
set_hp(99999999999); /* so he cannot be killed */
}
