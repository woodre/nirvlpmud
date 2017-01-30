#include "/players/feldegast/closed/ansi.h"
#include "/players/feldegast/closed/shortcut.h"
inherit "/obj/monster";

reset(arg) {
  object rattle;
  ::reset(arg);
  if(!present("rattler")) {
    rattle=clone_object("/obj/treasure");
    rattle->set_id("rattler");
    rattle->set_short("A rattler");
    rattle->set_long(
"This is a rattle made out of a gourd and some beads.  A long\n"+
"handle is attached to it with some bright string.\n");
    rattle->set_weight(1);
    rattle->set_value(200);
    move_object(rattle,this_object());
  }
  if(arg) return;
  set_name("doctor");
  set_short("Witch Doctor");
  set_long(
"     The village's witch doctor is a very strange looking\n"+
"human being.  He's very tall and chubby and his long curly\n"+
"hair sticks out at odd angles.  He's painted odd looking\n"+
"designs and tic-tac-toe games all over his body.\n"
  );
  set_gender("male");
  set_race("human");
  set_level(5);
  set_wc(9);
  set_ac(5);
  set_hp(75);
  set_al(50);
  set_chat_chance(15);
  load_chat(
"Doctor rattles his rattler at you and goes,'Hoo-hah!'\n"
  );
  load_chat(
"Doctor rattles his rattler contemplatively.\n"
  );
  load_chat(
"Doctor goes,'Hoo-hah!'\n"
  );
  load_chat(
"Doctor rattles his rattler happily.\n"
  );
  load_chat(
"Doctor rattles his rattler mysteriously.\n"
  );
  set_a_chat_chance(15);
  
  load_a_chat(
"Doctor rattles his rattler fiercely.\n"
  );
  load_a_chat(
"Doctor yells, 'HOO-HAH!'\n"
  );
  load_a_chat(
"Doctor yells,'P-p-p-pirate!'"
  );
}

