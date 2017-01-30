#include "/players/guilds/bards/def.h"
#include "/players/guilds/bards/lib/ansi_pad.h"

status main(string str) {
  string message;
  
  if(!str || str=="" || sscanf(str, "%s", message) != 1) {
    write("What would you like to say?\n");
    return 1;
  }
  if (sscanf(str," %s",message))
    str=message;
  if(BLVL > 4)
    str=ADDCOLOR(str);
  if (sscanf(str, "%s!!!", message)) {
    write(ansi_format(HIR+"You yell \""+NORM+str+HIR+"\"\n"+NORM,76));
    say(ansi_format(HIR+tp+" yells \""+NORM+str+HIR+"\"\n"+NORM,76));
    return 1;
  }
  if (sscanf(str, "%s!", message)) {
    write(ansi_format(RED+"You exclaim \""+NORM+str+RED+"\"\n"+NORM,76));
    say(ansi_format(RED+tp+" exclaims \""+NORM+str+RED+"\"\n"+NORM,76));
    return 1;
  }
  if (sscanf(str, "%s???", message)) {
    write(ansi_format(HIB+"You wonder \""+NORM+str+HIB+"\"\n"+NORM,76));
    say(ansi_format(HIB+tp+" wonders \""+NORM+str+HIB+"\"\n"+NORM,76));
    return 1;
  }
  if (sscanf(str, "%s?", message)) {
    write(ansi_format(BLU+"You ask \""+NORM+str+BLU+"\"\n"+NORM,76));
    say(ansi_format(BLU+tp+" asks \""+NORM+str+BLU+"\"\n"+NORM,76));
    return 1;
  }
  write(ansi_format(HIM+"You say, \""+NORM+str+HIM+"\"\n"+NORM,76));
  say(ansi_format(HIM+tp+" says, \""+NORM+str+HIM+"\"\n"+NORM,76));
  return 1;
}
