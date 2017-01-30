#include "/players/laera/closed/ansi.h"
#include "/players/laera/closed/ldef.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("dino bone");
set_alias("bone");
set_short(HIW + "Dino Bone" + OFF);
set_long(
	"Long and sturdy, this is a bone from the hind leg of the mighty T-Rex.\n" +
	"It fits easily into the hand of a warrior, and would be an effective\n" +
	"weapon against other animals.  Legend has it that this bone was used\n" +
	"to create powerful magic at one time.\n");

set_type("club");
set_class(17 - random(3));
set_weight(5 + random(3));
set_value(7000 + random(5000));
set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
W = random(13);
if(W>9)  {
  say(
  HIW + "CRACK!  " + this_player()->query_name() + " hits " + this_player()->query_attack()->query_name() +
  " over the head, sending shards of bone everywhere.\n" + OFF);

  write(
  "You hear " + (this_player()->query_attack())->query_name() + "'s skull crack and shards of bone " +
  "fly everywhere.\n");
  return 3;
   }
return;
}
init() {
::init();
  add_action("cmd_barter","barter");
}

cmd_barter(str) {
  if(id(str)) {
    if(present("etien",environment(this_player()))) {
      write("Etien looks over the item and decides its worth.  He pays \n" +
      		"you " + value + " for it then thanks you for your business.\n");
      say(this_player()->query_name() + " barters an item to Etien.\n");
      this_player()->add_money(value);
      this_player()->add_weight(-2);
      destruct(this_object());
      return (1);
    }
  }
  notify_fail("Barter what?\n");
}

/* Added for BF guild. Fred [7.29.06] */
query_nonchoose(){ return 1; }

