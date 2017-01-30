#include "/players/vital/closed/headers/vital.h"
#include <ansi.h>

main(str) {
   string npc, npc2;
   object o, o2;
   if(!str || sscanf(str,"%s %s",npc,npc2) != 2)
      {
      write("Syntax: 'battle <npc1> <npc2>'\n");
      return 1;
   }
   npc = LOWER(npc); npc2 = LOWER(npc2);
   o = present(npc,ENV(TP)); o2 = present(npc2,ENV(TP));
   if(!o || !o2)
      {
      write("One of them isn't here...\n");
      return 1;
   }
   if(!living(o) || !living(o2))
      {
      write("One of them isn't alive...\n");
      return 1;
   }
   write("Forcing "+BOLD+CAP(npc)+NORM+" to attack "+BOLD+CAP(npc2)+NORM+" -\n");
   TP->remote_say(TPN+" waves his hand and "+o->QN+" attacks "+o2->QN+"!\n");
   o->attack_object(o2);
   return 1;
}

get_help() {
    string help;
    help = "Set 2 things into battle";
    return help;
}