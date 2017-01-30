inherit "/obj/monster";
#include "/players/pavlik/guild/defs.h"
#define ADV_GUILD "/room/adv_guild"
#define ATTRIB_COST 2200        /* from tune.h */
#define ATTRIB_COST_TWO 3800    /* from tune.h */
#define ATTRIB_COST_THREE 6000  /* from tune.h */
#define ATTRIB_COST_FOUR 10000  /* added by pavlik */

reset(arg) {
  ::reset(arg);
  if (!arg) {
  set_name("Reidai");
  set_alias("reidai");
  set_alt_name("master");
  set_short("Master Reidai");
  set_long("Master Reidai.\n");
  set_level(50);
  set_ac(100);
  set_wc(500);
  set_hp(10000);
  set_al(0);
  set_aggressive(0);
  }
}

query_meijin_master() { return 1; }

init() {
  ::init();
  add_action("practice","practice");
  add_action("practice","prac");
  add_action("train","train");
  add_action("sit","sit");
}

short() {
  if(this_object()->query_attack()) return "Reidai";
  else return "Master Reidai is here helping students train";
}

long() {
  if(this_object()->query_attack()) {
	write("Reidai the Angered is a fierce warrior.  His moves are\n");
        write("incredible quick and sure.  Reidai's hands and feet move\n");
        write("with blinding speed as he cuts down his enemy.\n");
  }
  else {
	write("Master Reidai stands here overwatching his pupils train.  His\n");
	write("sharp eyes and stern voice ensure that each person trains to his\n");
	write("utmost potential.\n");
	write("From Master Reidai you can:\n");
        write("    'practice' a Stat.\n");
        write("    'train' to raise your Stamina (non-guild).\n");
  }
  return;
}

sit() {
  write("You sit down on the floor.\n");
  write("Master Reidai says:  Get up you lazy cow!  We do not rest here!\n");
  write("Master Reidai kicks you sharply in the ribs.\n");
  return 1;
}

practice(str) {
  int amt;
  string stat;

  if(!str) {
	write("Master Reidai says to you:  What do you wish to practice?\n");
	return 1;
  }
  if(!GOB->query_practices()) {
	write("Master Reidai says to you:  You will not gain anything from this.\n");
	return 1;
  }

  if(str == "dexterity" || str == "dex") stat = "dexterity";
  if(str == "strength" || str == "str") stat = "strength";
  if(str == "agility" || str == "agi") stat = "agility";
  if(str == "prowess" || str == "pro") stat = "prowess";
  if(str == "endurance" || str == "end") stat = "endurance";
  if(str == "constitution" || str == "con") stat = "constitution";

  if(!stat) {
	write("Master Reidai says to you:  I do not know how to help you with that.\n");
	return 1;
  }
  if(GOB->query_stat(stat) >= 100) {
	write("Master Reidai says to you:  You have already perfected this.\n");
	return 1;
  }

  amt = DAEMON->get_practice_increase();

  write("Master Reidai says to you:  Excellent, let us get started!\n");
  write("Reidai hands you some excercise equipment and begins instructing you.\n");
  write("After a long, grueling workout you feel much improved.\n");
  write("Your "+HIB+stat+NORM+" has improved "+HIW+amt+"%"+NORM+".\n");
  say(ME+" practices "+stat+".\n");
  GOB->add_guild_stat(stat, amt);
  GOB->add_practices(-1);
  return 1;
}

train() {
  int current, new;
  int expcost, minexp;

  current = call_other(TP, "query_attrib", "sta");
  new = current + 1;

  if(current < 11) expcost = -ATTRIB_COST;
  if(current < 12 && current > 10) expcost = -3*ATTRIB_COST/2;
  if(current < 14 && current > 11) expcost = -ATTRIB_COST_TWO;
  if(current < 16 && current > 13) expcost = -4*ATTRIB_COST_TWO/3;
  if(current < 18 && current > 15) expcost = -ATTRIB_COST_THREE;
  if(current < 21 && current > 17) expcost = -4*ATTRIB_COST_THREE/3;
  if(current < 24 && current > 20) expcost = -ATTRIB_COST_FOUR;
  if(current >= 24) {
	write("You cannot train your Stamina any higher.\n");
	return 1;
  }

  if(TP->query_extra_level() <= 0)
	minexp = TP->query_exp() - call_other("room/adv_guild", "get_next_exp", TP->query_level() - 1);
  else
	minexp = TP->query_exp() - call_other("room/exlv_guild", "get_next_exp", TP->query_extra_level() - 1);

  if(expcost < -minexp) {
	write("You do not have enough experience to train your stamina.\n");
	return 1;
  }

  write("You train vigirously under the watchful eye of Master Reidai.\n");
  write("You continue to work out until your whole body is trembling and\n");
  write("and sweat pours down your face.\n");
  call_other(TP, "raise_stamina", 1);
  call_other(TP, "add_exp", expcost);
  return 1;
}


