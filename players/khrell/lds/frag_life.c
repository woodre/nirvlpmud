#include "/players/llew/closed/ansi.h"
inherit "/obj/clean";
int worn;
object crystal;
string victim;

reset(arg) {
   if(arg) return;
   worn=0;
}

query_weight() {return 0;}
query_value() {return 0;}
id(str) { return str == "drain"; }

effect() {
   if(find_player(victim) != environment()) { destruct(this_object()); return; }
   if(find_player(victim)->query_hp() < 10) {
      death();
      return;
   }
   say("The crystal saps away your health to regain it's power.\n");
   find_player(victim)->add_hit_point(-8);
   worn++;
   if(worn >= 5) { destruct(this_object()); return; }
   call_out("effect",3);
   return 1;
}

drop() { return 1; }
get() { return 1; }
can_put_and_get() { return 0; }

death() {
   object xetra;
   xetra=clone_object("/players/llew/closed/crystal/frag_demon");
   move_object(xetra,environment(find_player(victim)));
   say("\nYou feel weak, drained completely of all your life essence.\n\n");
   say(capitalize(victim)+" crumples lifelessly to the ground.\n\n",find_player(victim));
   tell_room(environment(find_player(victim)),RED+"An enraged Xetra breaks free of its confinement!\n");
   tell_room(environment(find_player(victim)),NORM+"Xetra says,\""+capitalize(victim)+", your soul is mine!\"\n");
   say("The Xetra kisses you, it's forked tongue probing your mouth.\n");
   say("The Xetra leans forward and kisses "+capitalize(victim)+".\n",find_player(victim));
   lower_att();
   tell_room(environment(find_player(victim)),"The Xetra wipes its mouth with pleasure.\n");
   crystal->des();
      find_player(victim)->add_hit_point(-10);
      xetra->summoner(find_player(victim));
   destruct(this_object());
}

lower_att() {
   string stat;
   int x;
   x=0;
   tell_object(find_player(victim),HIR);
   while(x < 5) {
      stat=({"strength","intelligence","stamina","piety","stealth","will_power","magic_aptitude","luck"})[random(8)];
      if(call_other(find_player(victim),"query_attrib",pad(stat,3)) > 0) {
         call_other(find_player(victim),"raise_"+stat,-1);
         x++;
      }
   }
   tell_object(find_player(victim),NORM);
}

origin(ob) {
   crystal=ob;
   victim=environment()->query_real_name();
   call_out("effect",1);
}
