inherit "/obj/treasure";
#include "/players/illarion/dfns.h"
#define COLOR "/players/illarion/obj/addcolor"

void reset(int arg) {
  if(arg) return;
  set_id("tool");
  set_short("A channel tool");
  set_long("A tool to echo to mud channels.  Simply "+BLD("echochan")+
         " <channel> <message>\n"+
           "You can also add colors with `<color>` or `<COLOR>`, with `off`\n"+
           "to terminate, and newlines with \\n.\n");
  set_weight(1);
}
void init() {
  if(TP->query_level()<21) { destruct(this_object()); return; }
  add_action("cmd_echochan","echochan");
  add_action("cmd_joesign","joesign");
  add_action("cmd_showcolors","showcolors");
  add_action("cmd_echoto","echoto");
}
int cmd_echochan(string str) {
  string chan,what;
  object *ppl;
  int s,k;
  if(!str || sscanf(str,"%s %s",chan,what)!=2)
    FAIL("Echochan syntax: echochan <channel> <message>\n");
  ppl=users();
  s=sizeof(ppl);
  what=implode(explode(what,"\\n"),"\n");
  what=(string)call_other(COLOR,"addcolor",what);
  emit_channel(chan,what+"\n");
/*
  for(k=0;k<s;k++) if(ppl[k]->on_channel(chan)) tell_object(ppl[k],what+"\n");
*/
  return 1;
}
cmd_showcolors() {
  COLOR->showcolors();
  return 1;
}
int cmd_echoto(string str) {
  string to,what;
  object who;
  if(sscanf(str,"%s %s",to,what)!=2) return 0;
  who=find_player(to);
  if(!who) return 0;
  what=implode(explode(what,"\\n"),"\n");
  what=(string)COLOR->addcolor(what);
  what+="\n";
  tell_object(who,what);
  write(who->query_name()+" sees:\n");
  write(what);
  return 1;
}
