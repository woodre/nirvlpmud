inherit "/obj/monster";
#include "/players/pavlik/closed/colors.h"
#define DAEMON "/players/pavlik/guild/master.c"
#define ME capitalize(this_player()->query_real_name())

object seated;

reset(arg) {
  ::reset(arg);
  if (!arg) {
  set_name("Kentetsu");
  set_alias("kentetsu");
  set_alt_name("learned");
  set_short("Kentetsu the Learned");
  set_long("Kentetsu the Learned.\n");
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
  add_action("tell","tell");
}

tell(str) {
  string tmp;
  if(sscanf(str, "kentetsu %s", tmp) == 1) {
	write("You say to Kentetsu: "+tmp+"\n");
	tell_object(this_object(), ME+" tells you: "+tmp+"\n");
	return 1;
  }
}

short() {
  if(this_object()->query_attack()) return "Kentetsu (angered)";
  else return "Kentetsu the Learned sits here";
}

long() {
  if(this_object()->query_attack()) {
	write("Kentetsu the Angered is a fierce warrior.  His moves are\n");
        write("incredible quick and sure.  Kentetsu's hands and feet move\n");
        write("with blinding speed as he cuts down his enemy.\n");
  }
  else {
	write("It is said that Kentetsu has gathered the knowledge of man\n");
	write("since the world was born.  He has helped many "+CYN+"koute"+NORM+", or\n");
	write("better, themselves by partaking of his knowledge.  Kentetsu holds\n");
	write("a tiny clay bowl in his lap, which he eats from casually with a pair\n");
	write("of golden chopsticks.\n");
  }
  return;
}

catch_tell(str) {
  string tmp, tmp2, tmp3;

  if(!present(this_player(), environment(this_object()))) return;

  if(sscanf(str, "%s bows to you.", tmp) == 1) {
	write("Kentetsu returns your bow with a solemn nod of his head.\n");
	return 1;
  }
  if(sscanf(str, "%s waves at you.", tmp) == 1) {
	write("Kentetsu clicks his golden chopsticks together three times.\n");
	return 1;
  }
  if(sscanf(str, "%s thanks you.", tmp) == 1) {
	write("Kentetsu bows his head to you in silent welcome.\n");
	return 1;
  }
  if(sscanf(str, "%s winks at you suggestively.", tmp) == 1) {
	write("Kentetsu ignores your imbecilic gestures.\n");
	return 1;
  }
  if(sscanf(str, "%s fondles you.", tmp) == 1) {
	write("Kentetsu stabs you in the crotch with one of his golden chopsticks.\n");
	write("He doesn't seem amused.\n");
	return 1;
  }

  if(this_player() != environment(this_object())->query_seated()) return;

  if(sscanf(str, "%s sits %s", tmp, tmp2) == 2) {
	write("Kentetsu regards you with silent eyes.\n");
	return 1;
  }
  if(sscanf(str, "%s tells you: %sinfo%s", tmp, tmp2, tmp3) == 3) {
	if(this_player()->query_guild_name() != "meijin") {
		write("Kentetsu says to you:  There is nothing I can tell you.\n");
		return 1;
	}
	write(
	"Kentetsu says to you:  It is my duty to guide each member through\n"+
	"the ranks of the Meijin.  When you are ready to progress in guild\n"+
	"rank come to me.\n");
	return 1;
  }
  if(sscanf(str, "%s tells you: %skoute%s", tmp, tmp2, tmp3) == 3) {
	if(this_player()->query_guild_name() != "meijin") {
		write("Kentetsu says to you:  You cannot even begin to comprehend our ways.\n");
		return 1;
	}
	advance();
	return 1;
  }
}

advance() {
  int amt, cost, rank;
  int pracs, skills;

  rank = this_player()->query_guild_rank();
  amt = this_player()->query_guild_exp();
  cost = DAEMON->query_rank_cost(rank + 1);

  if(cost > amt) {
	write("Kentetsu says to you:  You are not prepared yet.\n");
	return 1;
  }

  /********************************************************/
  /* rank 30 is when we must select our choice of weapon. */
  /********************************************************/
  if((rank + 1) == 20) {
	write("Kentetsu says to you:  You show much promise!\n");
	write("Kentetsu says to you:  It has come time for you to choose.\n");
	write("You must select which weapon you will master.  You must forsake\n");
	write("all other types of weapon until you have become a master.\n");
	write("Which will you choose?\n");
	write("\n");
	write("('list') ->> ");
	input_to("choose_weapon");
	return 1;
  }

  /********************************************************/
  /* have a couple different messages for advancing ...   */
  /********************************************************/
  switch (random(5)) {
    case 0:
	write("Kentetsu says to you:  The spirit and the body become powerful\n");
	write("with the strength of knowledge.  You have done well.\n");
	break;
    case 1:
	write("Kentetsu says to you:  Remember, the inner self is the font of \n");
	write("our power.  You grow stronger each day.\n");
	break;
    case 2:
	write("Kentetsu says to you:  We are forever the pupils of life.  Our greatest\n");
	write("textbooks are not printed on paper.\n");
	break;
    case 3:
	write("Kentetsu says to you:  You excel, my friend!\n");
	break;
    case 4:
	write("Kentetsu says to you:  Never lose your purpose and you will succeed.\n");
	break;
  }

  /**********************************************************/
  /* Gain practice sessions to raise guild skills and stats */
  /**********************************************************/
  pracs = DAEMON->get_practices(rank + 1);
  present("pavlik_guild_obj", this_player())->add_practices(pracs);
  if(pracs) write("You have gained "+HIB+pracs+" practices"+NORM+".\n");

  /****************************/
  /* Gain new skils and stuff */
  /****************************/
  skills = DAEMON->get_skills(rank + 1);
  present("pavlik_guild_obj", this_player())->add_new_skills(skills);
  if(skills == 1) write("You can learn "+HIB+"1 new skill"+NORM+".\n");
  else if(skills > 1) write("You can learn "+HIB+skills+" new skills"+NORM+".\n");

  this_player()->add_guild_rank(1);
  DAEMON->guild_broadcast(HIB+"<("+HIY+"O"+HIB+")> "+HIW+ME+" has advanced in the guild!\n"+NORM);

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

  write(HIB+">"+NORM+" You have choosen to master the "+HIC+str+NORM+".\n\n");
  present("pavlik_guild_obj", this_player())->set_weapon_of_choice(str);
  present("pavlik_guild_obj", this_player())->add_guild_skill(str, 1);
  this_player()->add_guild_rank(1);
  DAEMON->guild_broadcast(HIB+"<("+HIY+"O"+HIB+")> "+HIW+ME+" has advanced in the guild!\n"+NORM);
  return 1;
}

query_npc() { return 0; }

