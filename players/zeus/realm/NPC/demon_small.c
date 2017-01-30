
inherit "/obj/monster";
#include "/players/zeus/closed/all.h"

reset(arg) {
   ::reset(arg);
   if (!arg) {

  set_name("planar demon");
  set_short("A demon of the planes");
  set_race("demon");
  set_long(
"This is a small red demon.  It has a tough little body with gangly arms.\n"+
"It is hunched over, but looks only to be about two feet tall.  A constant\n"+
"grin adorns it's face, which is highlighted by it's burning eyes.  It's\n"+
"claws are razor sharp and caked with dry blood.\n");
  set_level(15);
  set_ac(8);
  set_wc(32);
  set_hp(180);
  set_gender("creature");
  set_aggressive(1);
  set_al(-666);
  set_chat_chance(3);
  set_a_chat_chance(1);
  load_chat("The demon glares at you.\n");
  load_chat("The demon's eyes burn.\n");
  load_chat("The demon grins.\n");
  load_chat("The demon examines you.\n");
  load_a_chat("The demons eyes glaze over in bloodlust.\n");
  set_dead_ob(this_object());
}  }

id(str){ return str == "demon" || str == "daemon" || str == "planar demon"; }


monster_died(){
  DD->add_kills(attacker_ob, 1);
}

void init()
{
  ::init();
  add_action("dir_block", "north");
  add_action("dir_block", "east");
  add_action("dir_block", "south");
  add_action("dir_block", "west");
}

dir_block()
{
 if(this_player()->query_npc() || this_player()->query_level() > 19 ||
   this_player()->query_ghost()) return;
  tell_room(environment(), "The demon blocks "+
	  this_player()->query_name()+" from escaping.\n",
	  ({ this_player() }));
  tell_object(this_player(),
	  "The demon blocks you from escaping.\n");
  this_object()->attack_object(this_player());
  return 1;
}

