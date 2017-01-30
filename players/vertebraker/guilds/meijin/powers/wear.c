#include "/players/vertebraker/guilds/meijin/defs.h"
#define COST 0
#define RANK 0
#define SKILL_NAME "wear"

/*****/
/* customer wear command.  allows the player to only wear armor */
/* types: armor, helmet, boot                                   */
/*****/

void help() {
  write("\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     Skill  : Wear \n");
  write("     Syntax : wear <armor>\n");
  write("     Cost   : n/a\n");
  write("     Rank   : n/a\n");
  write("     Description : \n");
  write("         Meijin are only permitted to wear armor types:\n");
  write("         body, helmet, amulet and boots.\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }

int main(string str) {
  object obj;
  string type;

  if(str && (obj=present(str, TP))) {
  if(!((int)obj->quest_item())) {

    if(obj->armor_class() && (type=(string)obj->query_type())) {
	if(type != "armor" && type != "amulet" && type != "boot" && type != "boots" && type != "helmet") {
		write("You cannot wear this type of armor!\n");
		return 1;
	}
    }
  }

  }
}

