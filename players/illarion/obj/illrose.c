#include "/players/illarion/dfns.h"
inherit "obj/treasure";


query_weight() { return 1;}
int id(string str) { return
  (str== "rose" || str == "illarion_rose" || str == "flower");
}
string short() {
  return HIC+"@"+HIG+">-"+GRN+","+HIG+"--"+GRN+"'"+HIG+"----"+NORM;
}
void long() {
  write("\n"+
HIC+"         .     .                        \n"+
"    ...  :``..':              "+HIW+"The perfect form of a rose before you...\n"+HIC+
"     : ````.'   :''::'        "+HIW+"A mysterious, compelling scent....\n"+HIC+
"   ..:..  :     .'' :                   \n"+
" ``.    `:    .'     :                  \n"+
"    :    :   :        :                 \n"+
"     :   :   :         :                \n"+
"      :    :   :        :               \n"+
"       :    :   :"+HIG+"..''''``::.            \n"+HIC+
"        :"+HIG+" ...:..'     .''               \n"+
"        .'   .'  .::::'            "+HIW+"A rose from....\n"+HIG+
"       :..'''``:::::::     "+HIW+"   ___ __  ___ ____  _____ __ ___  ____\n"+HIG+
"       '         `::::     "+HIW+"  /  /  / /  /\\___ \\/  __/  /    \\/    \\\n"+HIG+
"                   `::.    "+HIW+" /  /  /_/  /_/ _  /  / /  /  /  /  /  /\n"+HIG+
"                    `::    "+HIW+" \\_/\\____\\____\\___/\\_/  \\_/\\____/\\_/__/\n"+HIG+
"                     :::.               \n"+
"          ..:.:.::'`. ::'`.  . : : .    \n"+
"        ..'      `:.: ::   :'       .:  \n"+
"       .:        .:``:::  :       .: :: \n"+
"       .:    ..''     :::.'    :':    : \n"+
"        : .''         .:: : : '         \n"+
"         :          .'`::               \n"+
"                       ::               \n"+NORM);
}
