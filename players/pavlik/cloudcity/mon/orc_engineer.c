inherit "/obj/monster";
#include "/players/pavlik/closed/colors.h"
#define TO this_object()
#define ENV environment(this_object())

string *custom_chats;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Orc Engineer");
  set_alias("engineer");
  set_race("orc");
  set_gender("male");
  set_short("An Orc Engineer");
  set_long(
    "An Orc Engineer is busy constructing a device that will pull the\n"+
    "Cloud City out of the sky.  His ugly green brow is knitted with\n"+
    "concentration as he studies the task at hand.\n");
  set_level(12);
  set_ac(10);
  set_wc(14);
  set_hp(225);
  set_al(-700);
  money = (200);
  message_hit = ({
	"pummels", " with a small hammer",
	"beats", " with a small hammer",
	"bites", " on the ankle",
	"begs", " for mercy",
	"thwacks", "",
	"jabs", " with a small hammer",
	"squeals at", " like a stuck pig",
  });
  custom_chats = ({
	"Orc Engineer takes something from a box of parts.",
	"Orc Engineer continues to tinker.",
	"The Orc Engineer curses and hammers on something.",
	"Orc Engineer says: This will bring down the city!",
	"Orc Engineer continues to build something.",
	"The Orc Engineer says: Almost done ...",
  });
  if(!root()) call_out("custom_check", 3);
}

id(str) {
  return str == "orc" || str == "engineer" || str == "orc_engineer";
}

query_cloud_npc() { return 1; }

custom_check() {
  object obj;

  obj = present("orc_machine", ENV);

  /* if there is no machine present then we move */
  if(!obj) {
	switch (random(4)) {
		case 0:	 command("north", this_object()); break;
		case 1:  command("south", this_object()); break;
		case 2:  command("east", this_object()); break;
		case 3:  command("west", this_object()); break;
	}
	call_out("custom_check", 5+random(15));
	return 1;
  }

  /* don't do anything else if attacked */
  if(TO->query_attack()) {
	call_out("custom_check", 10);
	return 1;
  }

  /* if a box is here and its broken */
  if(obj->query_broken()) {
	tell_room(ENV, "\n"+
		"Orc Engineer says: OH NO!  My poor machine!\n"+
		"Orc Engineer says: It must be rebuilt, and quickly!\n");
	tell_room(ENV,
		HIW+"The Orc Engineer gathers up all the broken parts and starts to rebuild.\n\n"+NORM);
	obj->set_broken(0);
	obj->set_build_count(0);
	call_out("custom_check", 5+random(15));
	return 1;
  }

  if(obj->query_build_count() < obj->query_build_max()) {
	tell_room(ENV, custom_chats[random(sizeof(custom_chats))]+"\n");
	obj->add_build_count();
  }

  call_out("custom_check", 5 + random(15));
  return 1;
}

hit_player(x) {
  if(!this_player()) return x;
  if(present("orc_fighter", ENV)) {
	object *ob, fighter;
	int i;
	ob = all_inventory(ENV);
	for(i=0; i<sizeof(ob); i++) {
		if(ob[i]->id("orc_fighter")) {
			if(!ob[i]->query_attack()) {
				ob[i]->attack_object(this_player());
				this_player()->attack_object(ob[i]);
				break;
			}
			else {
				fighter = ob[i];
			}
		}
	}
	if(fighter) {
		fighter->attack_object(this_player());
		this_player()->attack_object(fighter);
	}
	tell_room(ENV, "The Orc Engineer squeals for help!\n");
	tell_object(this_player(), "An Orc Fighter rushes you!\n");
	TO->stop_fight();
	TO->stop_fight();
	TO->stop_hunted();
	return x;
  }
  if(this_player()->query_npc()) return x;
  return ::hit_player(x);
}

