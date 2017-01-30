#include "/players/illarion/dfns.h"
inherit "/players/illarion/high/mon/imm_mon";

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("Xavier St. Cloud");
  set_short("A handsome and cultured-looking black man");
  set_race("immortal");
  set_long(
    "Though he wears perfectly-fitting and obviously very expensive clothes and\n"+
    "his hair is immaculately cut, there is nevertheless something just... slimy\n"+
    "about this man.  His eyes glint with greed, and there is something furtive\n"+
    "about the way he studies things.  Perhaps it's just his pronounced widow's\n"+
    "peak, or perhaps his character is shining through.\n");
  set_level(15);
  set_attacks(3);
  set_x_attack_chance(75);
  set_immortal(1);
  set_healing_factor(5);
  set_weapon_path(HOBJ+"xmachete");
  set_gender("male");
  set_hp(2200);
  set_wc(30);
  set_counter_chance(10);
  add_emote("counter",
    "You've left yourself open to a dirty trick, and Xavier wastes no time in exploting\n"+
    "it to gain a free attack on you.\n",
    "Xavier uses a dirty trick to gain a free attack on $TN$.\n");
  set_al(-400);
  set_ac(20);
  set_dodge_chance(10);
  add_emote("dodge","Xavier oozes out of the way of your attack like the slime he is.\n",
    "Xavier oozes out of the way of $TN$'s attack.\n");
  add_emote("dodge","With a cowardly gasp, Xavier flings himself out of the way.\n",
    "With a cowardly gasp, Xavier flings himself out of the way of $TN$'s attack.\n");
  add_chat_response("hello","$xavier_response$");
  add_chat_response("immortal","$attack_it$");
  add_chat_response("duncan",
"Xavier says with evident annoyance, \"Please do not mention that name to me again.\"\n");
  add_chat_response("name",
"With an urbane yet slimy smile, Xavier responds, \"I am Xavier St. Cloud.\"\n");
  add_spell("gas bomb",
"The gas makes you choke and cough!\n",
"Xavier reaches inside his coat and pulls out a small grenade.  He throws it down, and\n"+
"a cloud of noxious green gas billows out!\n",
25,"20-50","other|poison",1);
}
id(string str) {
  return ::id(str) || str == "man" || str == "xavier" || str == "cloud";
}
xavier_response(string who) {
  object ob;
  ob=present(lower_case(who),environment());
  if(!ob) return;
  say("Xavier says, \"Greetings to you as well, "+
  ((string)ob->query_gender()=="female"?"fair lady":"good sir")+".\"\n");
}
attack_it(string who) {
  object ob;
  ob=present(lower_case(who),environment());
  if(!ob) return;
  if(kill_ob && present(kill_ob,environment())) return;
  say("Xavier says, \"Oh really, you know about that?  Too bad for you.\"\n");
  attack_object(ob);
}