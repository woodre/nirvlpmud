inherit "/obj/monster";
#include "/players/vertebraker/guilds/meijin/defs.h"

reset(arg) {
  ::reset(arg);
  if (!arg) {
  set_name("Mosakou");
  set_alias("mosakou");
  set_alt_name("master");
  set_short("Master Mosakou");
  set_long("Master Mosakou.\n");
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
  add_action("learn","learn");
  add_action("list","list");
  add_action("practice","practice");
  add_action("practice","prac");
  add_action("sit","sit");
}

short() {
  if(this_object()->query_attack()) return "Mosakou the Superior";
  else return "Master Mosakou is here helping students train";
}

long() {
  if(this_object()->query_attack()) {
	write("Mosakou the Angered is a fierce warrior.  His moves are\n");
        write("incredible quick and sure.  Mosakou's hands and feet move\n");
        write("with blinding speed as he cuts down his enemy.\n");
  }
  else {
	write("Master Mosakou is here to guide his pupils training.  He\n");
	write("teaches members new skills and helps them practice existing\n");
	write("skills so that they might achieve perfection.\n");
	write("From Master Mosakou you can:\n");
	write("     'list' the skills avaliable for you to learn.\n");
	write("     'learn' a new skill.\n");
	write("     'practice' an existing skill.\n");
  }
  return;
}

sit() {
  write("Mosakou glares at you menacingly.\n");
  write("You decide not to sit afterall.\n");
  return 1;
}

list() {
  string skill;
  string *cmds;
  int i, rank;

  write("\n");
  write(HIW+"       Avaliable Skills:                \n"+NORM);
  write(HIB+"[(>-------------------------------<)]\n"+NORM);

  /* if we have mastered our weapon then we can learn another */
  if(GOB->query_weapon_of_choice() && GOB->query_skill(GOB->query_weapon_of_choice()) >= 100) {
	write("    "+HIW+"weapon"+NORM+"\n");
  }

  cmds = get_dir(POWERS);
  for(i=0; i<sizeof(cmds); i++) {
	skill = call_other(POWERS+cmds[i], "query_skill_name", 0);
	rank = call_other(POWERS+cmds[i], "query_rank", 0);

	if(!skill || !rank) continue;
	if(GOB->query_skill(skill)) continue;
	if((rank > 0) && (TP->query_guild_rank() < rank)) continue;

	write("    "+HIW+skill+NORM+"\n");
  }
  write(HIB+"[(>-------------------------------<)]\n"+NORM);
  write("\n");
  return 1;
}

practice(str) {
  int amt;

  if(!str) {
	write("Mosakou says to you:  What would you like to train?\n");
	return 1;
  }
  if(!GOB->query_practices()) {
	write("Mosakou says to you:  You will not gain anything from this right now.\n");
	return 1;
  }
  if(!GOB->query_skill(str)) {
	write("Mosakou says to you:  I cannot teach you that.\n");
	return 1;
  }
  if(GOB->query_skill(str) >= 100) {
	write("Mosakou says to you:  I cannot teach you anything more about "+str+".\n");
	return 1;
  }
  write("Mosakou says to you:  Very well, let us get started.\n");
  write("Master Mosakou punishes you with his relentless instructions.\n");
  write("When you finish, lying on the floor and gasping for breath, he\n");
  write("says to you:  You have done well.\n");
  say(ME+" practices "+str+".\n");

  amt = DAEMON->get_practice_increase();

  write("Your "+HIB+str+NORM+" skill has increased "+HIW+amt+"%"+NORM+".\n");
  GOB->add_guild_skill(str, amt);
  GOB->add_practices(-1);
  return 1;
}

learn(str) {
  string skill;
  string *cmds;
  string cmd, weap;
  int i, amt, rank;

  if(!str) {
	write("Mosakou says to you:  What would you learn?\n");
	return 1;
  }
  if(!GOB->query_new_skills()) {
	write("Mosakou says to you:  You are not prepared for this.\n");
	return 1;
  }
  if(GOB->query_skill(str)) {
	write("Mosakou says to you:  You already know this.\n");
	return 1;
  }
  if(str == "weapon") {
	if((weap=GOB->query_weapon_of_choice()) && GOB->query_skill(weap) >= 100) {
		write("Mosakou says to you:  Since you have mastered the "+weap+",  You\n");
		write("may begin the study of another weapon.  Which will you choose?\n");
		write("('list') ->> ");
		input_to("choose_weapon");
	}
	else {
		write("Mosakou says:  You are not ready to learn another weapon yet.\n");
	}
	return 1;
  }
  /*******************************/
  /* get the skill name and rank */
  /*******************************/
  if(file_size(POWERS+str+".c") > 0) {
	skill = call_other(POWERS+str+".c", "query_skill_name", 0);
	rank = call_other(POWERS+str+".c", "query_rank", 0);
	if(call_other(POWERS+str+".c", "query_trainable", 0)) amt = 1;
	else amt = 100;
  }
  else {
	cmds = get_dir(POWERS);
	for(i=0; i<sizeof(cmds); i++) {
		skill = call_other(POWERS+cmds[i], "query_skill_name", 0);
		if(skill == str) {
			rank = call_other(POWERS+cmds[i], "query_rank", 0);
			if(call_other(POWERS+cmds[i], "query_trainable", 0)) amt = 1;
			else amt = 100;
			break;
		}
	}
  }
  if(amt < 1) {
	write("Mosakou says to you:  I do not know how to teach you "+str+".\n");
	return 1;
  }
  if(TP->query_guild_rank() < rank) {
	write("Mosakou says to you:  You are not ready to learn this yet.\n");
	return 1;
  }
  write("Mosakou says to you:  I will teach this to you.\n");
  write("Master Mosakou teaches you the "+HIB+skill+NORM+" skill.\n");
  say(ME+" learns "+skill+".\n");
  GOB->add_guild_skill(skill, amt);
  GOB->add_new_skills(-1);
  return 1;
}

choose_weapon(str) {
  string *weapons;
  int i, col, is_ok;

  weapons = DAEMON->query_weapon_types();

  if(!str || str == "" || str == 0) {
        write("('list') ->> ");
        input_to("choose_weapon");
        return 1;
  }
  if(str == "?" || str == "list") {
        col = 0;
        write("\n");
        write(HIW+"                         Weapon Types                        \n"+NORM);
        write(HIB+" [(>-----------------------------------------------------<)]\n"+NORM);

        for(i=0; i<sizeof(weapons); i++) {
                if(!col) write("    ");
                write(pad(weapons[i], 15));
                col++;
                if(col == 4) {
                        write("\n");
                        col = 0;
                }
        }
        if(col) write("\n");
        write(HIB+" [(>-----------------------------------------------------<)]\n"+NORM);
        write("\n");
        write("('list') ->> ");
        input_to("choose_weapon");
        return 1;
  }

  is_ok = 0;
  for(i=0; i<sizeof(weapons); i++) {
        if(str == weapons[i]) is_ok = 1;
  }
  if(!is_ok) {
        write("Invalid selection.  Please choose again.\n");
        write("('list') ->> ");
        input_to("choose_weapon");
        return 1;
  }
  if(GOB->query_skill(str)) {
	write("Mosakou says:  You have already learned the "+str+".\n");
	write("('list') ->> ");
	input_to("choose_weapon");
	return 1;
  }
  write("Mosakou says:  You may know seek to master the "+HIB+str+NORM+".\n");
  GOB->set_weapon_of_choice(str);
  GOB->add_guild_skill(str, 1);
  return 1;
}

