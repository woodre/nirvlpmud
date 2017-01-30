#include "/players/pavlik/closed/colors.h"

/*
 * A player can fight this object and get an idea of how much
 * damage his attack is doing.  Original design by Balowski.
 * I probably coulda whipped up something like this without
 * borrowing Bal's code, but I just like the way he does things!
 */

/* different returns for amts of damage */
static string   *colors;

/* who's trying to kill me */
static object   Attacker;

int total_hits;
int total_damage;

string short() {
    return "A Practice Dummy";
}

status id(string s) {
    return s == "dummy";
}

string query_name() {
    return "Practice Dummy";
}

status query_npc() {
    return 1;
}

void reset(int arg) {
  if (arg || root()) return;
  enable_commands();
  total_hits = 0;
  total_damage = 0;
}

int query_hp() { return 500; }
int query_mhp() { return 500; }

void long() {
  write("A stuffed dummy used to practice combat on.\n");
  write("The following commands are avaliable here : \n");
  write("     reset       : Reset dummy stats.\n");
  write("     report      : Report dummy stats.\n");
  write("     stop        : Stop fighting dummy.\n");
  write("     info        : Information about the meter.\n");
  return;
}

int hit_player(int dam) {
  int i, stars;
  string bar;

  bar = HIW+"["+NORM;

  stars = dam / 3;
  if(dam > 0 && stars < 1) stars = 1;

  for(i=1; i<=10; i++) {
	if(i <= stars) {
		if(i <= 4) bar += "*";
		else if(i <= 7) bar += HIW+"*"+NORM;
		else bar += HIR+"*"+NORM;
	}
	else {
		bar += " ";
	}
  }

  if(stars > 10) {
	bar += HIR+"|"+BLINK;
  }

  for(i=11; i<=stars; i++) {
	bar += "*";
  }

  bar += NORM+HIW+"]"+NORM;

  tell_room(environment(this_object()), bar);

  if(this_player()->query_level() > 20) {
	tell_object(this_player(), " (Dmg: "+dam+")");
  }

  tell_room(environment(this_object()), "\n");

  total_hits++;
  total_damage += dam;

  return dam;
}

void heal_self(int amount) {
    if (amount < 0)
       hit_player(amount);
}

void attacked_by(object ob) {
    Attacker = ob;
}

object query_attack() {
    return Attacker;
}

void stop_fight() {
    Attacker = 0;
}

init() {
  add_action("dummy_reset", "reset");
  add_action("dummy_report", "report");
  add_action("dummy_stop", "stop");
  add_action("dummy_info", "info");
}

dummy_reset() {
  tell_room(environment(this_object()), "The Training Dummy is "+HIW+"reset"+NORM+".\n");
  total_hits = 0;
  total_damage = 0;
  return 1;
}

dummy_report() {
  int i, avg;
  string bar;

  if(!total_hits) {
	write("\t"+HIB+"Total Hits:  "+HIW+total_hits+NORM+"\n");
	write("\t"+HIB+"Damage Rating:  "+HIW+"none"+NORM+"\n");
	return 1;
  }

  avg = total_damage / total_hits;
  avg = avg / 3;
  bar = "";

  write("\n");
  write("\t"+HIB+"Total Hits:  "+HIW+total_hits+NORM+"\n");
  write("\t"+HIB+"Damage Rating:  "+HIW+"[");

  for(i=1; i<=10; i++) {
	if(i == avg) {
		if(i <= 4) bar += "*";
		else if(i <= 7) bar += HIW+"*"+NORM;
		else if(i <= 10) bar += HIR+"*"+NORM;
	}
	else {
		bar += " ";
	}
  }
  if(avg > 10) {
	bar += HIR+"|"+NORM;
  }
  for(i=11; i<=avg; i++) {
	if(i == avg) bar += BLINK+HIR+"*"+NORM;
	else bar += " ";
  }

  bar += HIW+"]"+NORM;
  write(bar+"\n");

  if(this_player()->query_level() > 20) {
	write("\tTotal Hits: "+total_hits+"  Total Damage: "+total_damage+"  Average: "+
	(total_damage/total_hits)+"\n");
  }

  return 1;
}

dummy_stop() {
  if(this_player()->query_attack() != this_object()) return 0;
  write("You stop beating on the helpless dummy.\n");
  this_player()->stop_fight();
  stop_fight();
  return 1;
}

dummy_info() {
  write("\n"+
  "The practice dummy gives can help you determine how well you are\n"+
  "fightning.  Each time the practice dummy is hit a damage meter\n"+
  "is displayed : \n"+
  "\n"+
  "           "+HIW+"["+NORM+"****"+HIW+"***"+HIR+"***|"+BLINK+"***"+NORM+HIW+"]"+NORM+"\n"+
  "            ^   ^  ^   ^\n"+
  "            ----|--|---|------ * light to moderate damage.\n"+
  "                |  |   |\n"+
  "                ---|---|------ "+HIW+"*"+NORM+" moderate to heavy damage.\n"+
  "                   |   |\n"+
  "                   ----|------ "+HIR+"*"+NORM+" heavy to severe damage.\n"+
  "                       |\n"+
  "                       ------- "+HIR+BLINK+"*"+NORM+" super-human damage.\n"+
  "\n");
  return 1;
}

