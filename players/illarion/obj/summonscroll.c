#include "/players/illarion/dfns.h"
inherit "obj/treasure";

object summoner;

void reset(status arg) {
  if(arg) return;
  
  set_id("scroll");
  set_short("A scroll of summons.");
  set_long("This scroll allows you to answer a summons from a wizard.\n"
          +"You have but to "+BLD("intone")+" the words written on it.\n"
		  +"However, even as you look at it, the edges of the scroll are\n"
		  +"crumbling away.\n");
}

/* Send the scroll to a player, with a limited time trans to the target
 * This function should be called from another object, probably a wiztoy.
 */
void summon_player(object player, object wizard, int time) {
  summoner = wizard;
  move_object(this_object(),player);
  tell_object(player,
  "A scroll materializes in your hands.  "+NAME(wizard)+" requests your\n"+
  "presence.  You have "+time+" seconds to "+BLD("intone")+" your acceptance.\n");
  call_out("remove_scroll",time);
}

void remove_scroll() {
  IBUG("remove_scroll call");
  if(environment()) {
    tell_object(environment(),"The scroll crumbles away.\n");
    destruct(this_object());
  }
}

void init() {
/* Why does init get called on load?  the world may never know */
  if(!summoner && environment()) {
    remove_scroll();
	return;
  }
  add_action("cmd_intone","intone");
}

int cmd_intone(string str) {
  if(str != "acceptance") FAIL("Syntax: intone acceptance.\n");
  if(!summoner) {
    write("The wizard is gone.");
	remove_scroll();
	return 1;
  }
  say("A flash of silver light occludes your vision.\n  When it clears, "+TPN+" is gone!\n");
  write("Your surroundings vanish in a flash of silver light!\n");
  move_object(TP,environment(summoner));
  tell_object(summoner, NAME(TP)+" accepted your summons.\n");
  say(TPN+" appears in a puff of smoke.\n");
  say("A flash of silver light occludes your vision.\n  When it clears, "+TPN+" is here!\n");
  remove_scroll();
  command("look");
  return 1;
}

status drop() {
  remove_scroll();
}