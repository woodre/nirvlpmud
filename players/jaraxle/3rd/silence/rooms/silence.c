#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/3rd/silence/rooms/no_exit.c";
#define LOGDIR "/players/jaraxle/3rd/writings/"
void
init()
{
   ::init();
   
   /*  ************************************************  */
   /*  These add_actions are for the theme of the area   */
   /*  They make it so the forest is "silent"            */
   /*  ************************************************  */
   
   add_action("tellem","tell"); 
   add_action("tellem","reply"); 
   add_action("tellem","say");
   add_action("tellem","say");
#ifndef __LDMUD__
   add_action("tellem"); add_xverb("'");
   add_action("tellem"); add_xverb(":");
#else
  add_action("tellem", "'", 3);
  add_action("tellem", ":", 3);
#endif
   add_action("tellem","gossip");
   add_action("tellem","star");
   add_action("tellem","junk");
   add_action("tellem","babble");
   add_action("tellem","shout");
   add_action("tellem","equip");
   add_action("tellem","ring");
   add_action("tellem","be");
   add_action("tellem","newbie");
   add_action("tellem","risque");
   add_action("tellem","derv");
   add_action("tellem","derve");
   add_action("tellem","tc");
   add_action("tellem","tce");
   add_action("tellem","net");
   add_action("tellem","nem");
   add_action("tellem","rt");
   add_action("tellem","rte");
   add_action("tellem","emote");
   add_action("tellem","bleat");
   add_action("tellem","gt");
   add_action("tellem","te");
   add_action("tellem","tf");
   add_action("tellem","ahelp");
   add_action("tellem","techie");
   add_action("tellem","farem");
#ifndef __LDMUD__
   add_action("tellem"); add_verb("?");
#else
  add_action("tellem", "?", 3);
#endif
   add_action("tellem","bdt");
   add_action("tellem","bbe");
   add_action("tellem","bts");
   add_action("tellem","mtell");
   add_action("tellem","reply");
   add_action("tellem","hte");
   add_action("tellem","ht");
   add_action("tellem","hta");
   add_action("tellem","gt");
#ifndef __LDMUD__
   add_action("tellem"); add_verb("gt :");
#else
  add_action("tellem", "gt :", 3)
#endif
   add_action("tellem","at");
   add_action("tellem","ae");
    add_action("tellem", "gossip :");
    add_action("tellem", "risque :");
    add_action("tellem", "babble :");
    add_action("tellem", "equip :");
    add_action("tellem", "newbie :");
    add_action("tellem", "junk :");
   add_action("tellem","hte");
   add_action("tellem","att");
   add_action("tellem","ate");
   add_action("tellem","chat");
   add_action("tellem","chate");
   add_action("tellem","brag");
   add_action("tellem","recite");
   add_action("tellem","recitee");
   add_action("tellem","Recite");
   add_action("tellem","brage");
   add_action("tellem","meow");
   add_action("tellem","meowe");
   add_action("tellem","story");
   add_action("tellem","storye");
   add_action("tellem","tempt");
   add_action("tellem","tempte");
   add_action("tellem","sp");
   add_action("tellem","fdraw");
   add_action("tellem","punt");
    add_action("tellem","party say");
   
   /*  ******************************************  */
   /*        END OF THEMATIC ADD_ACTIONS           */
   /*  ******************************************  */
   
    add_action("cmdReport","j_bug");
    add_action("cmdReport","j_typo");
    add_action("cmdReport","j_idea");
    add_action("cmdReport","j_opinion");
    add_action("j_help","j_help");
   add_action("the_key","key");
}
tellem(){
   if(TP->query_level() > 20){
      return; }
   write("You try to break the silence of the forest, but for some reason cannot.\n");
   return 1; }
the_key(str){
   write("\n"+
      ""+BLU+"\tX"+NORM+" = You are here!!\n"+
      ""+GRN+"\t@"+NORM+" = Trees (impassable)\n"+
      ""+YEL+"\t#"+NORM+" = Walkable Paths\n"+
      ""+MAG+"\t~"+NORM+" = Living Ooze!\n"+
      ""+CYN+"\t#"+NORM+" = ?\n"+
      ""+RED+"\t$"+NORM+" = Further Access Denied!\n");
   return 1; }

status
cmdReport(string str)
{
    string verb;

    verb = query_verb();

    if(!str) return 0;

    write_file(LOGDIR + verb[2..strlen(verb) - 1] + "s",
    HIB + ">> " + NORM + ctime()[4..15] + " " + BOLD +
pad(capitalize((string)this_player()->query_real_name()), 12) + NORM + " " +
str + " <<"+HIG+"" + file_name(this_object()) + ""+NORM+">>\n");

    write(HIY+"Thank you"+NORM+".\nJaraxle has received your " + 
      verb[2..strlen(verb) - 1] + "s.\n");
    return 1;
}
j_help(){
write("\n"+HIW+"j_opinion"+NORM+" <"+HIW+"message"+NORM+"> : To give your"+
"opinion on anything in the area.\n"+
      ""+HIW+"j_idea "+NORM+"<"+HIW+"message"+NORM+"> : To stress any ideas"+
"you might have for Jaraxle.\n"+
      ""+HIW+"j_typo "+NORM+"<"+HIY+"typo"+NORM+"> : To let Jaraxle know of"+
"any typos you find.\n"+
      ""+HIW+"j_bug "+NORM+"<"+HIR+"bug"+NORM+"> : If you find a bug, or an"+
"error, please type that here.\n\n");
return 1; }
