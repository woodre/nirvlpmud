#include "/players/pavlik/guild/mages/defs.h"
inherit "players/pavlik/guild/mages/inherit/command";
inherit "players/pavlik/guild/mages/inherit/string";

#define STRMAX 200

reset(arg) {
  if(arg) return;
  set_verb("lmsg");
  set_name("Login Message");
  set_color_name(HIC+"Login Message"+NORM);
  set_rank(1);
  set_descrip(
	"Customize your guild login/logout message.\n" +
	"\n" +
	"Use 'lmsg [login/logout] to view your custom message.\n" +
	"Use 'lmsg [login/logout] [msg]' to set a custom message.\n" +
	"Use 'lmsg [login/logout] clear' to reset your message.\n" +
	"Use '%NAME%' to substitute your name in the custom message.\n" +
	"\n" +
	"Example:\n" +
	"    lmsg login The world feels brighter when $NAME$ enters!\n" +
	"    lmsg logout You feel saddened when $NAME$ departs this realm.\n"
  );
}


cmd(str)
{
  string what, msg;
  string v_msg;
  string *n_test;

  if(!str)
  {
	if(!guild->query_login_msg())
		write("Login message  : <none>\n");
	else
	{
		v_msg = guild->query_login_msg();
		v_msg = COLOR_PARSER->parse_pcodes(v_msg);
		v_msg = tokenize(v_msg);
		write("Login message  : "+v_msg+"\n"+NORM);
	}

	if(!guild->query_logout_msg())
		write("Logout message : <none>\n");
	else
	{
		v_msg = guild->query_logout_msg();
		v_msg = COLOR_PARSER->parse_pcodes(v_msg);
		v_msg = tokenize(v_msg);
		write("Logout message : "+v_msg+"\n"+NORM);
	}
	return 1;
  }

  if(str == "login")
  {
	if(!guild->query_login_msg())
		write("You do not have a custom "+HIC+"login"+NORM+" message.\n");
	else
	{
		v_msg = guild->query_login_msg();
		v_msg = COLOR_PARSER->parse_pcodes(v_msg);
		v_msg = tokenize(v_msg);
		write("Your "+HIC+"login"+NORM+" message is:\n"+v_msg+"\n");
	}
	return 1;
  }

  if(str == "logout")
  {
	if(!guild->query_logout_msg())
		write("You do not have a custom "+HIC+"logout"+NORM+" message.\n");
	else
	{
		v_msg = guild->query_logout_msg();
		v_msg = COLOR_PARSER->parse_pcodes(v_msg);
		v_msg = tokenize(v_msg);
		write("Your "+HIC+"logout"+NORM+" message is:\n"+v_msg+"\n");
	}
	return 1;
  }

  if( (sscanf(str, "%s %s", what, msg) == 2) && (what=="login" || what=="logout") )
  {
	if(msg == "clear")
	{
		write("You reset your "+HIC+what+NORM+" message.\n");
		call_other(guild, "set_"+what+"_msg", 0);
		return 1;
	}

	if(strlen(msg) > STRMAX)
	{
		write("Character limit exceeded, "+STRMAX+" character maximum.\n");
		return 1;
	}

	v_msg = COLOR_PARSER->parse_pcodes(msg);
	v_msg = tokenize(v_msg);

	write("You set your "+HIC+what+NORM+" message to:\n"+v_msg+"\n");
	call_other(guild, "set_"+what+"_msg", msg);
	return 1;
  }

  notify_fail("Use lmsg [login/logout] [msg]\n");
  return 0;

}


