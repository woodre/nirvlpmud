#include "/players/pavlik/guild/mages/defs.h"
inherit "players/pavlik/guild/mages/inherit/command";

reset(arg) {
  if(arg) return;
  set_verb("affluence");
  set_name("Affluence");
  set_color_name(HIC+"Affluence"+NORM);
  set_rank(1);
  set_descrip(
	"The affluence command will tell you which Wizard create " +
	"a specific object or room.\n"
  );
}


cmd(str)
{
  object obj;
  string name, who;
  string junk, junk2;

  if(!str) obj = env;
  else obj = present(str, tp);
  if(!obj) obj = present(str, env);

  if(!obj)
  {
	notify_fail("There is no "+capitalize(str)+" here.\n");
	return 0;
  }

  if(!str)
  {
	write("You study your surroundings very carefully.\n");
	say(ME+" studies "+PO+" surroundings very carefully.\n");
  }
  else
  {
	write("You study the "+str+" very carefully.\n");
	say(ME+" studies a "+str+" very carefully.\n");
  }

  name = object_name(obj);
  if(tp->query_level() > 19) write(CYN+"Filename: "+name+NORM+"\n");

  sscanf(name, "players/%s/%s", who, junk);

  if(!who)
  {
	write("You are unable to determine any information.\n");
	return 1;
  }

  if(!str) write("This room was created by "+HIY+capitalize(who)+NORM+".\n");
  else write(obj->short()+" was created by "+HIY+capitalize(who)+NORM+".\n");
  return 1;

}

