#include "../DEFS.h"
#include DEFS_ALEVELS


status main(string str) {
  /* Advances a guild member's art level               */
  /* Currently, different art types are disabled, so   */
  /* the art level daemon doesn't do anything with str */
  int teacherlev, studentlev;
  object ob;
  if(!str || !present(str, environment(TP)) || 
     !present(GUILD_ID, present(str, environment(TP)))) {
     write("Train who?\n"+
           "You must be in the same room as the student.\n");
     return 1;
  }
  ob = find_player(str);
  teacherlev = (int)IPTP->query_art_level();
  studentlev = (int)IPOB->query_art_level();
  if(teacherlev <= studentlev && 
  !call_other(OFFICED, "checkStone", TP, "ruby")) {
    write("You don't have the skills to train "+capitalize(str)+".\n");
    return 1; 
  }
  if(studentlev >= BLACK_BELT &&
  (int)IPTP->query_art_level() != MAX_ART_LEVEL){
    write("You cannot train fellow black belts.\n");
    return 1; 
  }
  write("You attempt to train "+capitalize(str)+".\n");
  if(!call_other(ALEVELD, "train", ob, str)) {
    write("Your student is not yet competent.\n");
    say(OPN+" can't seem to understand "+
      TPN+"'s advanced teachings.\n");
  }
  write("Your student has learned from your teachings well.\n");
  say(OPN+" quickly learns from "+
    TPN+"'s advanced martial training lessons.\n");
  return 1;
}
