#include "/players/pavlik/guild/defs.h"
#define COST 0
#define RANK 0
#define SKILL_NAME "xmon"

/* guild health monitor */

/* Ok, I suppose, really shouldnt exist as monitor is in basic game. -Bp */
void help() {
  write("\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     Skill  : xmon \n");
  write("     Syntax : xmon \n");
  write("     Cost   : n/a \n");
  write("     Rank   : n/a \n");
  write("     Description : \n");
  write("         Xmon is the guild health monitor.  Command\n");
  write("         options include:\n");
  write("             /off - turn the monitor off.\n");
  write("             /on  - turn the monitor on.\n");
  write("             <#>     - set the display interval to #.\n");
  write("             <color> - sets the display color.\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return 0; }
string query_skill_name() { return SKILL_NAME; }

int main(string str) {
  int x;
  object pet, attk;
  string col, pname;

  if(!str) {
	col = (string)GOB->query_monitor_color();
	if(col) write(col);
	write(
	"[Hp: "+(int)TP->query_hp()+"/"+(int)TP->query_mhp()+"] "+
	"[Sp: "+(int)TP->query_sp()+"/"+(int)TP->query_msp()+"] "+
	"[En: "+(int)GOB->query_endurance()+"/"+(int)GOB->query_max_endurance()+"] ");
        if(pet=find_living(TP->query_real_name()+"'s meijin_pet")) {
                pname = extract((string)pet->query_name(), 0, 2);
                tell_object(TP, "["+pname+": "+pet->query_hp()+"/"+pet->query_mhp()+"] ");
        }
	if(attk=(object)TP->query_attack()) {
		x = ((int)attk->query_hp()) * 100 / ((int)attk->query_mhp());
		x = (x / 10) * 10;
		write("[Att: "+x+"%]\n");
	}
	else write("\n");
	if(col) write(NORM);
	return 1;
  }

  if(lower_case(str) == "off" || lower_case(str) == "/off") {
	write("The monitor is now off.\n");
	GOB->set_monitor_interval(0);
	return 1;
  }

  if(lower_case(str) == "on" || lower_case(str) == "/on") {
	write("The monitor is now on.\n");
	write("Display interval set to default (3).\n");
	GOB->set_monitor_interval(3);
	return 1;
  }

  sscanf(str, "%d", x);
  if(x > 0) {
	write("The monitor is now on.\n");
	write("Display interval set to: "+x+".\n");
	GOB->set_monitor_interval(x);
	return 1;
  }

  /* select a color */
  switch (str) {
	case "red" :
		write(PRE+"Monitor color now set to "+HIR+"red"+NORM+".\n");
		GOB->set_monitor_color(HIR);
		break;
	case "green" :
		write(PRE+"Monitor color now set to "+HIG+"green"+NORM+".\n");
		GOB->set_monitor_color(HIG);
		break;
	case "yellow" :
		write(PRE+"Monitor color now set to "+HIY+"yellow"+NORM+".\n");
		GOB->set_monitor_color(HIY);
		break;
	case "blue" :
		write(PRE+"Monitor color now set to "+HIB+"blue"+NORM+".\n");
		GOB->set_monitor_color(HIB);
		break;
	case "magenta" :
		write(PRE+"Monitor color now set to "+HIM+"magenta"+NORM+".\n");
		GOB->set_monitor_color(HIM);
		break;
	case "cyan" :
		write(PRE+"Monitor color now set to "+HIC+"cyan"+NORM+".\n");
		GOB->set_monitor_color(HIC);
		break;
	case "white" :
		write(PRE+"Monitor color now set to "+HIW+"white"+NORM+".\n");
		GOB->set_monitor_color(HIW);
		break;
	default :
		write(PRE+"Monitor color choices:\n");
		write(PRE+"  white, red, green, yellow, blue, magenta, cyan.\n");
		break;
  }
  return 1;
}

