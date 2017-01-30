#include "/players/pavlik/guild/mages/defs.h"
inherit "players/pavlik/guild/mages/inherit/command";

#define STRMAX 200

reset(arg) {
  if(arg) return;
  set_verb("lcmds");
  set_name("Login Commands");
  set_color_name(HIC+"Login Commands"+NORM);
  set_rank(1);
  set_descrip(
	"Use this feature to set commands that will automaticaly " +
	"be executed when you login/logout.  Up to 5 commands can be " +
	"specified.  Commands should be seperated by commas.\n" +
	"\n" +
	"Example:\n" +
	"    lcmds login gt Hi Everyone!,gm vault,list\n" +
	"    lcmds logout rescue,gm vault,deposit all,gt Bye!\n" +
	"\n" +
	"Use 'lcmds [login/logout]' to view your present login commands.\n" +
	"Use 'lcmds [login/logout]' clear' to erase all commands.\n"
  );
}


cmd(str)
{
  string what, cmds;

  if(!str)
  {
	notify_fail("Use 'lcmds [login/logout]' to view current command list.\n");
	return 0;
  }

  if(str == "login")
  {
	if(!guild->query_login_cmds())
		write("You have no "+HIC+"login"+NORM+" commands set.\n");
	else
		write("Your "+HIC+"login"+NORM+" commands are: "+HIM+guild->query_login_cmds()+NORM+"\n");
	return 1;
  }

  if(str == "logout")
  {
	if(!guild->query_logout())
		write("You have no "+HIC+"logout"+NORM+" commands set.\n");
	else
		write("Your "+HIC+"logout"+NORM+" commands are: "+HIM+guild->query_logout_cmds()+NORM+"\n");
	return 1;
  }

  if( (sscanf(str, "%s %s", what, cmds) == 2) && (what=="login" || what=="logout") )
  {
	if(cmds == "clear")
	{
		write("You clear all "+HIC+what+NORM+" commands.\n");
		call_other(guild, "set_"+what+"_cmds", 0);
		return 1;
	}

	if(strlen(cmds) > STRMAX)
	{
		write("Character limit exceeded, "+STRMAX+" character maximum.\n");
		return 1;
	}

	write("You set your "+HIC+what+NORM+" cmds to: "+HIM+cmds+NORM+"\n");
	write("These commands will be executed automaticaly when you next "+what+".\n");
	call_other(guild, "set_"+what+"_cmds", cmds);
	return 1;
  }

  notify_fail("Use lcmds [login/logout] [commands]\n");
  return 0;

}


