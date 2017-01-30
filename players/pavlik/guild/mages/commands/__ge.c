#include "/players/pavlik/guild/mages/defs.h"
inherit "players/pavlik/guild/mages/inherit/command";
inherit "players/pavlik/guild/mages/inherit/channel";

reset(arg) {
  if(arg) return;
  set_verb("ge");
  set_name("Guild Emote");
  set_color_name(HIC+"Guild Emote"+NORM);
  set_rank(1);
  set_descrip(
	"Communicate with other guild members.\n" +
	"See Also: gt, gc\n"
  );
}


cmd(str)
{
  object ob, obj;
  string em, arg, file;
  int i;

  if(!str)
  {
	notify_fail("Guild emote what?\n");
	return 0;
  }

  if(guild->query_muffled() == 1)
  {
	notify_fail("You are muffled.\n");
	return 0;
  }

  if(sscanf(str, "%s %s", em, arg) != 2)
  {
	em = str;
  }

  em = implode(explode(em, "."), "");
  if(file_size(file="/bin/soul/_"+em+".c") > 0)
  {
	return (int)file->guildcast("mage", arg);
  }

  str = COLOR_PARSER->parse_pcodes(str);

  i = sizeof(ob = users());
  while(i--)
  {
	if(present("mageobj", ob[i]) && !present("mageobj", ob[i])->query_muffled())
		tell_object(ob[i], query_tag()+" "+ME+" "+str+NORM+"\n");
  }

  add_history(query_tag()+" "+ME+" "+str+NORM+"\n");
  return 1;

}

