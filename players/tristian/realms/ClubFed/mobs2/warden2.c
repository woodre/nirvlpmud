inherit "/players/vertebraker/closed/std/monster.c";
#include "/players/tristian/lib/ClubFeddefine.h"
id(str) { return (::id(str) || str == "warden"); }

int x;

reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("Warden Jones");
  set_alt_name("jones");
  set_race("human");
  set_alias("warden");
  set_gender("male");
  set_short("Warden Jones");
  set_long(
    "This is Warden Jones, he is in charge of the prison but don't let the suit and tie\n"+
    "fool you, he used to walk a beat and still knows how to wield a billy club like a\n"+
    "old time screw.  To control the animals he has to, you know he is stronger than the\n"+
    "rest of the pack, you have been warned.\n");
  set_level(20);
  set_ac(55+random(10));
  set_wc(55+random(10));
  set_wc_bonus(random(15));
  set_hp((1200)+random(100));
  move_object(clone_object("/players/tristian/realms/ClubFed/obj/billyclub2.c"),this_object());
    init_command("wield club");
  add_money(4000+random(2500));
  set_al(1);
  set_aggressive(2);
  set_chance(25);
  set_spell_dam(30+random(20));
  set_spell_mess1(
  HIC+"Warden Jones's club takes on a life of its own and hits you over and over and over!\n"+NORM);
  set_spell_mess2(
  HIC+"Warden Jones's club takes on a life of its own and hits you over and over and over!\n"+NORM);

  set_multi_cast(0);
  
  add_spell("gun",
  HIC+"Warden Jones pulls out his gun and unloads a clip at you!!\n",
  "Warden Jones pulls out his gun and unloads a clip at his foe!\n"+NORM,
  10,({60,60}),({"physical","other|tristian"}));  

  set_chat_chance(10);
  load_chat(
    "The warden orders you out of his office!\n");
  load_chat(
    "The warden send you to the hole.\n");
  set_death_emote(
    "\n\nWarden Jones falls against his desk, dead at the hands of one of his convicts.....you!\n");
}