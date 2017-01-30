inherit "/obj/monster";
#include "/players/pavlik/closed/colors.h"
#define TO this_object()
#define ENV environment(this_object())

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Orc Fighter");
  set_alias("fighter");
  set_race("orc");
  set_gender("male");
  set_short("An Orc Fighter");
  set_long(
    "This is an evil Orc Fighter.  A green snout and ugly yellow teeth\n"+
    "protrude from his grotesque face.  The orc carries a bloodied\n"+
    "broadsword at his side, and he looks like he intends to use it!\n");
  set_level(14);
  set_ac(11);
  set_wc(18);
  set_hp(210);
  set_al(-700);
  money = (200);
  message_hit = ({
	"slices deeply into", "'s body",
	"hacks mercilessly at", "",
	"bites", " on the arm",
	"chops", " brutally",
	"slashes", " with his wicked broadsword",
	"pokes", " with his sword",
	"scratches", " with little effect",
  });
}

id(str) {
  return str == "orc" || str == "fighter" || str == "orc_fighter";
}

query_cloud_npc() { return 1; }

hit_player(x) {
  if(this_player()->query_npc()) return x;
  return ::hit_player(x);
}

stop_fight() {
  if(this_player()->query_level() >= 20) ::stop_fight();
}

