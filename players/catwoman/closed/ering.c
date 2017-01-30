inherit "obj/treasure";
#include "/players/illarion/dfns.h"

object worn_by;
string fiance;

reset(int arg) {
  if(arg) return;
  
  set_id("ring");
  set_short("A "+BOLD+"diamond"+NORM+" engagement ring");
  set_long(
"A slim silver band set with a beautifully sparkling diamond, a\n"+
"proclimation that the wearer is someone's beloved and intended in\n"+
"marriage.  If you've decided you've made a mistake, you may release\n"+
"your intended.\n");
}
drop(int s) {
  return 1;
}
init() {
  ::init();
  add_action("cmd_wear","wear");
  add_action("set_fiance","remove");
  add_action("cmd_release","release");
}
void check_wear() {
  object ob;
  if(!worn_by) return;
  if(!(ob=environment(this_object())) || ob!=worn_by) {
    worn_by=0;
    return;
  }
}
set_fiance(string name,object wearer) {
  fiance=name;
  worn_by=wearer;
}
short() {
  check_wear();
  return ::short()+(fiance?" ["+capitalize(fiance)+"]":"")+
          (worn_by?" (worn)":"");
}
cmd_wear(string str) {
  if(!str || present(str,TP)!=this_object())
    FAIL("Wear what?\n");
  check_wear();
  if(worn_by) {
    write("You already wear it!\n");
    return 1;
  }
  write("You slip on the engagement ring.\n");
  say(TPN+" slips on an engagement ring.\n");
  worn_by=TP;
  return 1;
}
cmd_remove(string str) {
  if(!str || present(str,TP)!=this_object())
    FAIL("Remove what?\n");
  check_wear();
  if(!worn_by) {
    write("You aren't wearing it.\n");
    return 1;
  }
  write("You slip off the engagement ring.\n");
  say(TPN+" takes off an engagement ring!\n");
  worn_by=0;
  return 1;
}
cmd_release(string str) {
  object ob;
  if(!str || str != fiance)
    FAIL("Release who?\n");
  write("You release "+capitalize(str)+" from the engagement.\n");
  say(TPN+" takes off an engagement ring, and it vanishes!\n");
  if((ob=find_player(fiance)))
    tell_object(ob,TPN+" has removed your engagement ring.\n");
  destruct(this_object());
  return 1;
}
query_auto_load() {
  if(!fiance) {
    write("Ring not saved.\n");
    return 0;
  }
  return "/players/catwoman/closed/ering.c:"+fiance;
}
init_arg(string str) {
  if(str) {
    set_fiance(str,TP);
  }
}
