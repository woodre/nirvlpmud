#include "/players/catwoman/closed/color.h"
inherit "obj/weapon.c";


reset(arg) {
  ::reset(arg); 
  if(arg) return;
  set_name("guitar");
  set_alias("guitar");
  set_short(BLUE+"Jimi's guitar"+OFF);
  set_long("Jimi' own Guitar you can play_guitar if you wish.\n");
  set_value(3000);
  set_class(19);
  set_weight(3);
  set_hit_func(this_object());

}

query_save_flag() { return 1;}

init() {
    add_action("play", "play_guitar");
   
    ::init();
}

wield(str) {
  object name;
 
  if(!id(str))
     return 0;
  name = call_other(this_player(), "query_name", 0);
  if(wielded) {
    write("You already wield it!\n");
    return 1;
  }
    say("Jimi's guitar humms and the croud gos wild.\n");
    wielded_by = this_player();
    call_other(this_player(), "wield", this_object());
    wielded = 1;
    return 1;
  }
play() {
	object name;
 	name = call_other(this_player(), "query_name", 0);
	write("you play a most excellent tune.\n");
	say(name+" plays a riff from"+RED+" 'Cross Town Traffic'.\n"+OFF);
	say(REV_PURPLE+"screeeeech\n"+OFF);
	return 1;
}

weapon_hit(attacker) {
	string align;
	write("The tone cuts deep and blood squirts everywhere.\n");
	say("You see a hunk of flesh go flying by.\n SPLAT the flesh hits the ground.\n");
	return 5;
}

