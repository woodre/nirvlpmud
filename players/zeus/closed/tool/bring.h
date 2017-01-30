/*  A fancy 'trans' that will also allow me to grab a player
    who has no environment [like that ever happens! :)  ]
*/
#include "/players/zeus/closed/all.h"
status bring_cmd(string str){
object ob;
  if(!str){ 
	  tell_object(ENV,"Usage: 'bring <player>'\n"); 
	  return 1; 
  }
 ob = find_player(str);
  if(!ob) return 0;
   tell_object(ob,
"A "+BOLD+BLK+"dark shadow"+NORM+" grips you tightly...\n"+
"\t\t\t\t\tYou have been summoned.\n\n");
   if(environment(ob)){ TR(environment(ob), 
"A "+BOLD+BLK+"dark shadow"+NORM+" folds in upon "+ob->QN+".\n", 
   ({ ob })); }   MO(ob, environment(TP));
   TR(environment(ob), ob->QN+" appears suddenly.\n", ({ ob }));
   command("look", ob);
   return 1; 
}

