inherit "/obj/monster";
#include "/players/pavlik/closed/colors.h"
#define TO this_object()
#define ENV environment(this_object())

string *custom_chats;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Ariel Guard");
  set_alias("guard");
  set_race("ariel");
  if(!random(2)) set_gender("male");
  else set_gender("female");
  set_short("An Ariel Guard");
  set_long(
    "You see a winged Ariel that has pledged whos duty it is to\n"+
    "protect the Cloud City.  The Ariel Guard fights courageously\n"+
    "with a golden spear and shield.\n");
  set_level(16);
  set_ac(14);
  set_wc(22);
  set_hp(400);
  set_al(700);
  set_a_chat_chance(20);
  load_a_chat("Ariel Guard says: You will not get away with this!\n");
  load_a_chat("The Ariel Guard calls for help.\n");
  load_a_chat("Ariel Guard fights desperately to save his city.\n");
  load_a_chat("Ariel Guard says: Stop them!\n");
  money = (200);
  message_hit = ({
	"pierces", "'s body with a golden spear",
	"thrusts his spear into", "",
	"swoops down and drops a rock on", "'s head",
	"flies out of", "'s reach",
	"swoops down and stabs", "",
	"flies down and clocks", " on the head with his shield",
	"prods", " with his spear",
  });
  custom_chats = ({
	"Ariel says: Stop them!  Hurry!",
	"Ariel grapples desperately with the Orc",
	"Ariel Guard says: We must save our City!",
	"The Ariel Guard swoops through the air.",
	"Ariel Guard says: Don't let them capture our city!",
  });
  call_out("custom_check", 3);
}

id(str) {
  return str == "ariel" || str == "guard" || str == "ariel_guard";
}

query_cloud_npc() { return 1; }

custom_check() {

  if(present("orc", ENV)) {
	if(!TO->query_attack())
		TO->attack_object(present("orc", ENV));

	if(!random(3))
		tell_room(ENV, custom_chats[random(sizeof(custom_chats))]+"\n");
	call_out("custom_check", 3);
	return 1;
  }
  /* if no bad guys here then we move */
  switch (random(4)) {
	case 0:  command("north", this_object()); break;
	case 1:  command("south", this_object()); break;
	case 2:  command("east", this_object()); break;
	case 3:  command("west", this_object()); break;
  }
  call_out("custom_check", 5+random(15));
  return 1;
}

hit_player(x) {
  if(this_player()->query_npc()) return x;
  return ::hit_player(x);
}

stop_fight() {
  if(this_player()->query_level() >= 20) ::stop_fight();
}

