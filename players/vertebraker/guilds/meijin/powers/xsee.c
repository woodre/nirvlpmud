#include "/players/vertebraker/guilds/meijin/defs.h"
#define COST 175
#define RANK 20
#define SKILL_NAME "farsight"
/* may need failure rate, Ok for now -Bp Jul 23 22:02 xsee.c */

/************************************************************/
/* This skill allows the player to scan the contents of     */
/* surrounding rooms.  The player also has the options to   */
/* scan several rooms in a given location.  This skill will */
/* only work with rooms that use query_dest_dir.            */
/************************************************************/

void help() {
  write("\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("     Skill  : Farsight \n");
  write("     Syntax : xsee\n");
  write("     Cost   : "+COST+" ep\n");
  write("     Rank   : "+RANK+"\n");
  write("     Description : \n");
  write("         Use heightened perception to survey your\n");
  write("         surroundings.  Command options:\n");
  write("             <dir>  : Survey several rooms in the given\n");
  write("                      direction.\n");
  write("  [(>----------------------------------------------------<)]\n");
  write("\n");
}

int query_rank() { return RANK; }
string query_skill_name() { return SKILL_NAME; }

int dirtest(object ob, string str) {
  int x;
  string *exits;
  exits = (mixed)environment(ob)->query_dest_dir();
  for(x=1; x<sizeof(exits); x+=2) {
	if(exits[x] == str) return 1;
  }
  return 0;
}

int main(string str){
  object obj;
  int i;
  string *exits;
  string name, dir;

  if(!GOB->query_skill(SKILL_NAME)) return 0;

  if(GOB->query_endurance() < COST) {
	write("You are too tired.\n");
	return 1;
  }
  if(!environment(TP)->query_dest_dir()) {
	write("Farsight will not work here.\n");
	return 1;
  }
  if(str && !dirtest(TP, str)) {
	write("You cannot farsee "+str+".\n");
	return 1;
  }
  write(PRE+"You use the powers of "+HIB+"farsight"+NORM+" to survey your surroundings.\n");
  say(ME+" closes "+POS+" eyes and uses the power of "+HIB+"farsight"+NORM+".\n");

  obj = clone_object("players/pavlik/guild/obj/far_sight");
  if(str) {
	move_object(obj, environment(TP));
	obj->exit_report(str);
  }
  else {
	exits = (mixed)environment(TP)->query_dest_dir();
	for(i=0; i<sizeof(exits); i+=2) {
	    name = exits[i];
	    dir = exits[i+1];
	    move_object(obj, name);
	    obj->do_report(dir);
	}
  }
  GOB->add_endurance(-COST);
  return 1;
}

