#include "../DEFS.h"

status main(string str) {
  /* Advances a guild member's art level               */
  /* Currently, different art types are disabled, so   */
  /* the art level daemon doesn't do anything with str */
  object ob;

  if (!call_other(OFFICED,"checkStone",TP,"diamond sapphire pearl ruby emerald onyx"))
    return 0;

  if(!str || !present(str, environment(TP)) || 
     !present(GUILD_ID, present(str, environment(TP))))
  {
     write("Train who?\n"+
           "You must be in the same room as the student.\n");
     return 1;
  }

  ob = find_player(str);
  write("You attempt to train "+capitalize(str)+".\n");
  if(!call_other(ALEVELD, "train", ob, str)) {
    write("Your student is not yet competent.\n");
    say(OPN+" can't seem to understand "+
      TPN+"'s advanced teachings.\n");
    return 1;
  }
  write("Your student has learned from your teachings well.\n");
  say(OPN+" quickly learns from "+
    TPN+"'s advanced martial training lessons.\n");
  return 1;
}
