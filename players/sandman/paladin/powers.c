
/*
 * MAIN PALADIN GUILD OBJECT (3/19/94)
 * Houses all 'universal' paladin functions.
 */

#define TELL(x) tell_room(environment(this_player()), x)   
#define CME this_player()->query_name()
#include "defs.h"

/* Commands included from /players/sandman/paladin/lib */
#include "lib/assess.h"
#include "lib/psi_sword.h"
#include "lib/bless.h"
#include "lib/call.h"
#include "lib/cant.h"
#include "lib/cmdrs.h"
#include "lib/compare.h"
#include "lib/cure.h"  
#include "lib/forge.h"
#include "lib/guildcom.h"
#include "lib/id_obj.h"
#include "lib/invite.h"
#include "lib/judge.h"
#include "lib/k_blow.h"
#include "lib/mark.h"
#include "lib/members.h"
#include "lib/mudwho.h"
#include "lib/protect.h"
#include "lib/salute.h"
#include "lib/titles.h"
#include "lib/wimpy.h"
#include "lib/track.h"

register() {
   string com;
   object ob, new_medal, medal;
   
   new_medal = clone_object("players/sandman/paladin/medal");
   medal = previous_object();
   if(medal->query_combat_method() == 0) com = "standard";
   if(medal->query_combat_method() == 1) com = "mounted";
   if(medal->query_combat_method() == 2) com = "shield";
   if(medal->query_combat_method() == 3) com = "dual";
   new_medal->set_combat_method(com);
   medal->save_medal();
   new_medal->restore_medal();
   transfer(new_medal, this_player());
   write("Your medallion brightens for a moment then returns to normal.\n");
   destruct(medal);
   return 1;
}

rank() {
   int wimpy_at;
   string wimpydir;
   
   write("\n");
   write(capitalize(this_player()->query_real_name())+" (Level: "+
         this_player()->query_level()+") (Extra Level: "+
         this_player()->query_extra_level()+")\n");
   write("Hit points:\t"+this_player()->query_hp()+"["+
         this_player()->query_mhp()+"]"+"\tSpell points:\t"+
         this_player()->query_sp()+
         "["+this_player()->query_msp()+"]\n");
   write("Experience:\t"+this_player()->query_exp()+"\t\tGold coins:\t"+
         this_player()->query_money()+"\n");
   if(previous_object()->query_wimpy_at()) {
    wimpy_at = previous_object()->query_wimpy_at();
    wimpydir = previous_object()->query_wimpydir();
    write("Guildwimpy is on. Wimpyhp: "+wimpy_at+" Wimpydir: "+wimpydir+"\n");
   } else write("Guildwimpy is off.\n");
   if(previous_object()->query_muffled()) {
      write("Guildmuffles are on.\n");
   } else write("Guildmuffles are off.\n");
   write("\n");
   previous_object()->abilities();
   previous_object()->attributes();
   return 1;
}

help_medal(str) {
   if(!str) {
      cat(HELPDIR+"help");
      return 1;
   }
   if(sscanf(str, "cmd %s", str) == 1) 
     str += ".cmd";
   if(!cat(HELPDIR+str)) {
     write("No such help file: "+str+"\n");
     return 1;
   }
   return 1;
}

verify_use(string check, int min_level, int cost) {
   if(this_player()->query_alignment() < MIN_ALIGN) {
     write("You are not worthy to use the powers of a Paladin!\n");
     return 0;
   }
   if(check == "spell") {
     if(this_player()->query_level() < min_level ||
            this_player()->query_sp() < cost) {
       write("You are unable to use this power.\n");
       return 0;
     }
     this_player()->add_spell_point(-cost);
     return 1;
   }
   return 1;
}

