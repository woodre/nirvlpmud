#include "/players/illarion/dfns.h"
inherit "obj/monster";

int been_attacked;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;

  set_name("HK-50");
  set_short("An HK-50 protocol droid");
  set_long(
      "A fully humanoid droid, the HK-50 has a brushed steel finish, and\n"+
      "yellow optical sensors that seem vaguely menacing.\n");
  set_race("droid");
  set_alias("hk-50");
  set_gender("creature");
  set_al(-300);

  set_weapon_params("other|laser",10+random(26),0);
  set_ac(10+random(11));
  set_armor_params("other|laser",10+random(11),0,0);
  set_hp(500+random(500));

  add_spell("sniper shot",
      "In a tinny but delighted voice, the assassin droid says, \"Optimal accuracy ratio achieved!\"\n"+
      "It fires a particularly well-aimed shot at you.\n",
      "In a tinny but delighted voice, the assassin droid says, \"Optimal accuracy ratio achieved!\"\n"+
      "It fires a particularly well-aimed shot at #TN#.\n",
      10,"20-60","other|laser");
  set_chat_chance(3);
  load_chat(
      "The droid says, \"Proud Statement: I am an HK-50 protocol droid,\n"+
      "responsible for the facilitation of communication and the termination\n"+
      "of hostiles...  er, hostilities.\"\n");
  load_chat("The droid says, \"Statement: If you remain in this area, Master, you\n"+
      "will be in great danger.\n");
  set_a_chat_chance(5);
  load_a_chat(
      "The droid says, \"Threat: Your fragile organic body and inferior reflexes\n"+
      "will make you easy to kill.\"\n");
  load_a_chat(
      "The droid says, \"Condescending Observation: Organic, you seem hurt.  You should\n"+
      "seek medical attention.\"\n");
  
  
  set_death_emote("In the same tinny, cheerful voice it used for everything else, the droid reports, "+
      "\"Systems Failing, Master,\" then falls into a heap of scrap.\n");
  set_corpse_name("scrap");
  set_corpse_short("A heap of droid scrap");
  set_corpse_long("A smoking heap of polished steel and electronic components.\n");
}

attacked_by(ob) {
  if(!been_attacked) {
    set_short("An HK-50 assassin droid");
    tell_room(ETO,
        "The droid's chest opens, and it extracts a nasty-looking blaster rifle.\n"+
        "It says, \"Pitying Statement: Organic, I tried to warn you.  Now you\n"+
        "must die.\"\n",({TO}));
    been_attacked=1;
  }
  return ::attacked_by(ob);
}
