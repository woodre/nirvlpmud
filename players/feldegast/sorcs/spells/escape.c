/* A cheap teleport spell with random destination. */
#include "/players/feldegast/defines.h"
#include "/players/wocket/mages/def.h"

inherit "/players/wocket/mages/obj/page";

reset(arg) {
  if(arg) return;
  spell="escape";
  spell_short=HIB+"E"+RED+"s"+HIY+"c"+HIG+"a"+NORM+YEL+"p"+HIM+"e"+NORM;
  spell_desc=
"Cost:  40 sp\n\
  Of all the spells known by even the most accomplished sorceror, few\n\
have as many legends, tall tales, and anecdotes associated with them\n\
as the Escape spell, whose creator has long sinced past from mortal\n\
memory, and known territory.\n\
  From time to time, a mage will find himself in a situation so dire,\n\
so dangerous, that absolutely anyplace would be better than the place\n\
where the mage already is.  Under these circumstances, and only these\n\
circumstances, should the Escape spell be risked.\n";
  time=1;
  size=2;
  spcost=40;
  hpcost=0;
  type="sorcery";
}
check_spell(object mage, string str) {
  if(environment(mage)->realm()=="NT" ||
    environment(mage)->realm()=="NM" ||
    environment(mage)->query_NM()) {
    tell_object(mage,"Your spell fizzles.\nYou can't teleport from here.\n");
    return 0;
  }
  return 1;
}
cast_spell(object mage) {
  string where;
  while(!(where=call_other("obj/base_tele","teleport"))) ;
  tell_object(mage,"An unstable rift opens above your head and sucks you in.\n");
  mage->remote_say(mage->query_name()+" disappears in a flash of light as an unstable rift sucks "+mage->query_objective()+" in.\n");
  move_object(mage,where);

  present(GUILD_ID,mage)->clear_spell(); /* To end command block. */
  command("look",mage);

  say(mage->query_name()+" arrives in a flash of light.\n");
  return 1;
}
