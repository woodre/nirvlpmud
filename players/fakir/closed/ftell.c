#include "/players/vertebraker/define.h"
inherit TREASURE;

drop() { return 1; }
init() {
   ::init();
   add_action("cmd_ft","ftell");
}

cmd_ft(str) {
   string msg;
   object fak;
   fak = find_player("fakir");
   if(!fak) {
      FAIL(HIR+"Fakir isn't logged on!\n"+NORM);
      return 0; }
   if(in_editor(fak)) {
      FAIL(HIR+"Fakir is editing ("+NORM+"LEAVE HIM ALONE!"+HIR+")\n"+NORM);
      return 0; }
   write(HIR+"~"+HIW+"^"+HIR+"~ You tell Fakir: "+NORM+str+"\n");
   msg = HIR+"~"+HIW+"^"+HIR+"~ "+TPN+" tells you: "+NORM+str;
   tell_object(fak,msg+"\n");
   fak->add_tellhistory(msg);
   present("ftell",fak)->set_replyer(TPRN);
   return 1; }


extra_look() {
   write(USER->QN+" has a telepathic link to "+HIR+"Fakir"+NORM+".\n");
}

id(str) {
   return str == "link" || str == "ftell"; }
