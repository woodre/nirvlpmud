#define TPRN this_player()->query_real_name()

inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("wild bill");
set_race("human");
set_short("Wild Bill Hickock");
set_alias("bill");
set_long(
	"  James Butler Hickock (1837-1876)  Scout for Custer, stage \n"+
	"driver, trick rider, gunslinger, lawman.  Killed while playing \n"+
	"poker, holding aces and eights.  Now known as the 'dead man's \n"+
	"hand.' \n");
set_level(15);
set_hp(225);
set_al(-40);
set_wc(20);
set_ac(12);
set_aggressive(0);

set_chat_chance(5);
  load_chat("Wild Bill sneers:  I think you'd better move on. \n");
  load_chat("Bill squints and looks directly into your eyes. \n");
  load_chat("Bill whispers:  I'll give you one chance to move along. \n");

gold = clone_object("obj/money");
gold->set_money(random(100)+800);
move_object(gold,this_object());
}

init() {
  ::init();
  add_action("North","north");
}

North() {
tell_room(environment(this_object()),
  "Wild Bill steps into the path of "+capitalize(TPRN)+" with a "+
  "nasty sneer.\n");
  return 1; }
