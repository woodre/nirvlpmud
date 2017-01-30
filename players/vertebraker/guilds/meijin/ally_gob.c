#include "/players/vertebraker/guilds/meijin/defs.h"

int guild_channel;		/* channel muffling */
string enter_msg;		/* login message */
string exit_msg;		/* logout message */
string handed;			/* handedness */
static string skill_actions;	/* object commands */

id(str) {
  return str == GUILDID || str == ALLYID || str == "armband" || str == "band";
}

reset(arg) {
  if(arg) return;
  handed = allocate(2);
  handed[0] = "right";
  handed[1] = "left";
  guild_channel = 1;
  skill_actions = ({
	"xt",
	"xwho",
	"setenter",
	"setexit",
  });
}

query_auto_load() {
  return "players/pavlik/guild/ally_gob.c:0";
}

/*********************************************************************/
/* This function is called when the guild object is first created.   */
/*********************************************************************/
init_arg(arg) {

  restore_object(ALLYSAVEPATH+TP->query_real_name());

  /* register with master */
  DAEMON->add_Meijin(this_object());

  /* login message to guild members */
  DAEMON->broadcast_login(TP, enter_msg);

  return 1;
}

guild_init(silent) {
  restore_object(ALLYSAVEPATH+TP->query_real_name());

  /* register with master */
  DAEMON->add_Meijin(this_object());
}

/*********************************************************************/
/* This function is called when the player leaves the game.          */
/*********************************************************************/
guild_quit(silent) {
  if(!TP) {
	destruct(this_object());
	return 1;
  }

  /* remove from master */
  DAEMON->remove_Meijin(this_object());

  /* logout message to guild members */
  DAEMON->broadcast_logout(TP, exit_msg, silent);

  save_object(ALLYSAVEPATH+TP->query_real_name());
}
 
get() { return 1; }
drop() { return 1; }
short() { return; }

long() {
  write(
	"A small silver armband encircles your "+HAND+" forearm.  The circlet\n"+
	"indicates that you are an "+HIW+"ally"+NORM+" of the "+HIB+"Meijin"+NORM+".\n"+
	"For much information type 'xhelp'.\n");
  return;
}

extra_look() {
  if(this_player() == ENV)
	return "A "+HIW+"silver"+NORM+" armband encircles your "+HAND+" forearm";
  else
	return "A "+HIW+"silver"+NORM+" armband encircles "+ENV->query_possessive()+" "+
	HAND+" forearm";
}

set_guild_channel(x) { guild_channel = x; }
query_guild_channel() { return guild_channel; }
query_handed(x) { return handed[x]; }
set_handed(x, str) { handed[x] = str; }
set_enter_msg(str) { enter_msg = str; }
query_enter_msg() { return enter_msg; }
set_exit_msg(str) { exit_msg = str; }
query_exit_msg() { return exit_msg; }

init() {
  int x;

  for(x=0; x<sizeof(skill_actions); x++) {
	add_action("guild_cmd", skill_actions[x]);
  }
  add_action("guild_quit", "quit");
  add_action("local_help", "xhelp");
  add_action("refresh_object", "xregister");
}

guild_cmd(str) {
	if(file_size(POWERS+query_verb()+".c") <= 0) {
		notify_fail("Invalid command.\n");
	}
	return (int)call_other(POWERS+query_verb(), "main", str);
}

/*****************************/
/* register the guild object */
/*****************************/
refresh_object() {
  write(PRE+"Refreshing ... "+HIB+"ok!\n"+NORM);
  DAEMON->add_Meijin(this_object());
  TP->set_heart_beat(1);
  TP->heart_beat();
  call_other(TP, "reset", 1);
  TP->recalc_quest();
  TP->recalc_carry();
  return 1;
}

local_help(str) {
  int i;

  if(!str) {
	write(
	"This object identifies you as an Ally to the Meijin.  The circlet\n"+
	"grants you the following powers : \n");
	for(i=0; i<sizeof(skill_actions); i++) {
		write(skill_actions[i]+"\n");
	}
	write("xregister\n");
	write("Type 'xhelp <cmd>' to find out more about a specific command.\n");
	return 1;
  }
  if(file_size(POWERS+str+".c") <= 0) {
	return 0;
  }
  call_other(POWERS+str+".c", "help", 0);
  return 1;
}

