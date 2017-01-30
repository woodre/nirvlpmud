#include "/players/eurale/defs.h"

id(str) { return str == "jukebox"; }

short() { return BOLD+"A Jukebox"+NORM; }

long() { write(
  "A Jukebox to help change player stats and make them what you need.\n"+
  "The commands are:\n"+
  "  level <num>\n"+
  "  exl <num>\n"+
  "  exp <num>\n"+
  "  gexp <num>\n"+
  "  setat <attrib> <num>\n"+
  "To get rid of jukebox just 'hide jukebox'.\n");
}
        
get() { return 0; }  /* This makes it so that people can not pick it up*/

init() {
  add_action("new_attribs","setat");
  add_action("jukebox","hide");
  add_action("new_level","level");
  add_action("new_exl","exl");
  add_action("new_exp","exp");
  add_action("new_gexp","gexp");
}

new_attribs(str) {
string what;
int num;
if(!str) { write("setat <what> <num>\n"); return 1; }
sscanf(str, "%s %d", what,num);
write("You change your '"+what+"' to "+num+".\n");
  TP->set_attrib(what,num);
  TP->save_me();
return 1;
}

new_exp(str) {
int num;
if(!str) { write("Usage: exp <amt>\n"); return 1; }
sscanf(str, "%d", num);
write("You alter your exp by "+num+" amt.\n");
  TP->add_exp(num);
  TP->save_me();
return 1;
}

new_gexp(str) {
int num;
if(!str) { write("Usage: gexp <num>\n"); return 1; }
sscanf(str, "%d", num);
  TP->add_guild_exp(num);
write("You alter your guild exp by "+num+" to "+TPGEXP+".\n");
TP->save_me();
return 1;
}

new_level(str) {
int num;
if(!str) { write("level <num>\n"); return 1; }
sscanf(str, "%d", num);
write("You change your level to "+num+".\n");
  TP->set_level(num);
  TP->save_me();
return 1;
}

new_exl(str) {
int num;
if(!str) { write("Usage:  exl >num>\n"); return 1; }
sscanf(str, "%d", num);
write("You change your extra level to "+num+".\n");
  TP->set_extra_level(num);
  TP->save_me();
return 1;
}

jukebox(str) {
if(!str) { write("Usage: hide jukebox\n"); return 1; }
if(!str || str != "jukebox") {
  write("Usage: hide jukebox\n");
  return 1; }
write("In a puff of blue smoke, the jukebox disappears.\n");
destruct(TO);
return 1;
}
