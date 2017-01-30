#include "/players/vertebraker/guilds/meijin/defs.h"
#define COST 15
#define RANK 250
#define SKILL_NAME "makebag"

/*******************************************************/
/* create a bag from a corpse.  the object created is: */
/* ~/guild/obj/corpse_bag.c                            */
/*******************************************************/

/* creation cmd approved -Bp Jul 16 21:19 xbag.c */
void help() {
  write("\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     Skill  : Makebag\n");
  write("     Syntax : makebag\n");
  write("     Cost   : "+COST+" ep\n");
  write("     Rank   : "+RANK+"\n");
  write("     Description : \n");
  write("         Create a handy bag from someone's corpse.\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }

int main(){
  object obj;
  string name;

  if(!GOB->query_skill(SKILL_NAME)) return 0;

  if(GOB->query_endurance() < COST) {
	write("You are too tired.\n");
	return 1;
  }

  obj = present("corpse", TP);
  if(!obj) obj = present("corpse", environment(TP));

  if(!obj) {
    write("You don't have a corpse.\n");
    return 1;
  }
  name = (string)obj->query_name();
  destruct(obj);
  obj = clone_object("players/pavlik/guild/obj/corpse_bag");
  obj->set_name(name);
  move_object(obj, TP);

  write("You strip the flesh from "+name+"'s corpse and create a bag!\n");
  say(ME+" strips the flesh from "+name+"'s corpse and creates a bag!\n");

  GOB->add_endurance(-COST);
  return 1;
}

