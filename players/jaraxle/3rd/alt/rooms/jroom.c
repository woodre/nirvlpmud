#include "/players/jaraxle/define.h"

#define LOGDIR "/players/jaraxle/3rd/writings/"

inherit "/players/jaraxle/3rd/alt/rooms/room.c";

void
init()
{
    ::init();
    add_action("cmdReport","j_bug");
    add_action("cmdReport","j_typo");
    add_action("cmdReport","j_idea");
    add_action("cmdReport","j_opinion");
    add_action("j_help","j_help");
}

status
cmdReport(string str)
{
    string verb;

    verb = query_verb();

    if(!str) return 0;

    write_file(LOGDIR + verb[2..strlen(verb) - 1] + "s",
    HIB + ">> " + NORM + ctime()[4..15] + " " + BOLD + pad(capitalize((string)this_player()->query_real_name()), 12) + NORM + " " + str + " <<"+HIG+"" + file_name(this_object()) + ""+NORM+">>\n");

    write(HIY+"Thank you"+NORM+".\nJaraxle has received your " + 
      verb[2..strlen(verb) - 1] + "s.\n");
    return 1;
}
j_help(){
write("\n"+HIW+"j_opinion"+NORM+" <"+HIW+"message"+NORM+"> : To give your opinion on anything in the area.\n"+
      ""+HIW+"j_idea "+NORM+"<"+HIW+"message"+NORM+"> : To stress any ideas you might have for Jaraxle.\n"+
      ""+HIW+"j_typo "+NORM+"<"+HIY+"typo"+NORM+"> : To let Jaraxle know of any typos you find.\n"+
      ""+HIW+"j_bug "+NORM+"<"+HIR+"bug"+NORM+"> : If you find a bug, or an error, please type that here.\n\n");
return 1; }
