#include "/players/vertebraker/guilds/meijin/defs.h"
#define COST 0
#define RANK 0
#define SKILL_NAME "wield"

/*****/
/* custom wield commands.  makes sure the player only wields his weapon */
/* of choice once the player has exceeded guild rank 20.                */
/*****/

void help() {
  write("\n");
  write("  [(>-----------------------------------------------------------<)]\n");
  write("     Skill  : Wield \n");
  write("     Syntax : wield <weapon>\n");
  write("     Cost   : "+COST+" ep\n");
  write("     Rank   : "+RANK+"\n");
  write("     Description : \n");
  write("        Wield a weapon.  Once you have choosen a weapon\n");
  write("        type to master you may only wield that type of weapon.\n");
  write("  [(>-----------------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }

string creator(object obj) {
  string name, who, tmp;
  
  name = file_name(obj);
  if(sscanf(name, "players/%s/%s", who, tmp) == 2) return capitalize(who);
  else return "Unknown";
}

int main(string str) {
  object obj;

  if(str && (obj=present(str, TP))) {
  if(!((int)obj->quest_item())) {

	if(!obj->query_type()) {
		write_file("/players/vertebraker/guilds/meijin/log/SET_TYPE",
		obj->short()+" ("+file_name(obj)+") does not have type set.\n");
	}

	if(TP->query_guild_rank() >= 20) {
		if(!obj->query_type()) {
			write("This weapon does not have its weapon_type set.  This is probably an\n");
			write("oversight of the weapon's creator ("+creator(obj)+").\n");
			return 1;
		}
		if(obj->weapon_class() && obj->query_type() && !GOB->query_skill(obj->query_type())) {
			write("You will not wield this type of weapon! ("+obj->query_type()+")\n");
			return 1;
		}
	}
  }
  }

}

