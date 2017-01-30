#include "/players/mizan/esc.h"
#define MORPH_ID "Mizan-morph-object"
#define HELPFILE "/players/mizan/closed/poly/help/golem"

#define MASTER_R "/players/mizan/closed/poly/PDM.c"
#define ENV environment(this_object())
#define DEATHTIME 5400

object attacker;

object weapon;

id(str) { return str == "sphere" || str == MORPH_ID; }
get() { return 1; }
drop() { return 1; }


extra_look() {
   if(ENV) return (ENV->query_name()) + " is a giant stone creature, mute and therefore\n"+
      "unable to communicate with you in normal methods";
}


reset() {
   call_out("fake_beat", 2);
   call_out("force_return", DEATHTIME);
   
}

fake_beat() 
{
   int i;
   object here;
   
  if(!ENV) return 1;
   attacker = (ENV)->query_attack();
   if(attacker && present(attacker, environment(ENV))) 
   {
      if(weapon) 
      {
         if(environment(weapon) != this_object()) weapon = 0;
         else{
            MASTER_R->extra_hit(weapon->weapon_class(),0,attacker,ENV);
            MASTER_R->hit_creature(ENV, attacker, weapon->weapon_class());
         }
         weapon->count_hit_made();
         if(weapon->query_wear() > 1 && random(4000000/weapon->query_wear()) < 10)
            weapon->weapon_breaks();
      }
      if(1 == random(14)) {
         tell_object(ENV, "You get your second wind!\n");
         ENV->remote_say((ENV->query_name()) + " gets a second wind!\n");
         MASTER_R->extra_hit(weapon->weapon_class(), 0, attacker, ENV);
         MASTER_R->hit_creature(ENV, attacker, weapon->weapon_class());
      }
   }
   here = ENV;
   move_object(this_object(), here);
   remove_call_out("fake_beat");
   call_out("fake_beat", 2);
}

strap_weapon(str) {
   object ob;
   ob = present(str, this_player());
   if(!ob) {
      write("You have no such item.\n");
      return 1;
   }
   if(!ob->weapon_class() || this_player()->query_weapon() == ob) {
      write("You cannot strap that!\n");
      return 1;
   }
   if(!weapon) {
      weapon = ob;
      write("You strap " + lower_case(ob->short()) + " as a secondary weapon.\n");
      ENV->remote_say((ENV->query_real_name()) + " straps " + lower_case(weapon->short()) + " as a secondary weapon.\n");
      move_object(weapon, this_object());
   } else write("You have no more free limbs.\n");
   return 1;
}

unstrap_weapon(str) {
   
   object ob;
   if(!str) return 0;
   ob = present(str, this_object());
   if(weapon && ob && ob == weapon) {
      write("You unstrap " + lower_case(weapon->short()) + ".\n");
      ENV->remote_say((ENV->query_real_name()) + " unwields " + lower_case(weapon->short()) + " as a secondary weapon.\n");
      move_object(weapon, ENV);
      weapon = 0;
   } else write("You have no such weapon strapped.\n");
   return 1;
   
}

short() {
   string temp;
   temp = "";
   if(weapon) temp = temp + (weapon->short()) + " (wielded secondary).\n";
   temp = temp + "A dark granite sphere";
   return temp;
}

long() {
   int a;
   write("You look into the sphere and see a dark, stony face\n"+
      "staring right back.\n"+
      "your current polymorph as a golem.\n"+
      "Type 'class' to see your new abilities.\n");
   if(weapon) write((weapon->short()) + " is strapped secondary.\n");
}


init() {
   add_action("class","class");
   add_action("strap_weapon","strap");
   add_action("unstrap_weapon","unstrap");
   add_action("block_magic","mi");
   add_action("block_magic","missile");
   add_action("block_magic","sh");
   add_action("block_magic","shock");
   add_action("block_magic","fi");
   add_action("block_magic","fireball");
   add_action("block_say","say");
   add_action("block_say","ring");

   
#ifndef __LDMUD__
   add_action("block_say"); add_xverb("'");
#else
   add_action("block_say", "'", 3);
#endif

#ifndef __LDMUD__
   add_action("block_say"); add_xverb("\"");
#else
   add_action("block_say", "\"", 3);
#endif

   add_action("block_say","gossip");
   add_action("block_say","risque");
   add_action("block_say","junk");
   add_action("block_say","msg");
   add_action("block_say","equip");
   add_action("block_say","babble");
   add_action("block_say","chat");
   add_action("block_say","chate");
   add_action("block_say","tale");
   add_action("block_say","talee");
   add_action("block_say","story");
   add_action("block_say","storye");
   add_action("block_say","tempt");
   add_action("block_say","meow");
   add_action("block_say","meowe");
   add_action("block_say","alt");
   add_action("block_say","ale");
   add_action("block_say","brag");
   add_action("block_say","brage");
   add_action("block_say","shout");
   add_action("block_say","com");
   add_action("block_say","be");
   add_action("block_say","fli");
   add_action("block_say", "tell");
   add_action("block_say","bdt");
   add_action("block_say","bbe");
   add_action("block_say","farem");
   add_action("filter_party","party");
   add_action("block_say","pe");
   add_action("block_say","pt");
   add_action("block_say","emote");
   
#ifndef __LDMUD__   
   add_action("block_say"); add_xverb(";");
#else
   add_action("block_say", ";", 3);
#endif
   
#ifndef __LDMUD__   
   add_action("block_say"); add_xverb(":");
#else
   add_action("block_say", ":", 3);
#endif

   add_action("block_say","communicate");
}

class() { return cat(HELPFILE); }

filter_party(str) {
   string tmpl;
   if(!str) return 0;
   if(sscanf(str, "sa%s", tmpl) == 1 || sscanf(str, "tel%s", tmpl) == 1) return block_say();
   else return 0;
}
block_magic() {
   write("You are ignorant of magic.\n");
   return 1;
}

block_say() {
   write("You can't.\n");
   return 1;
}

force_return() {
   if(ENV) tell_object(ENV, ESC + "[1m" + ESC + "[31m" +
         "You feel that the strain of retaining this morph is getting to you\n"+
      "and you will be unable to hold it for much longer...\n" + ESC + "[0m");
   call_out("force_return2", 20);
}

force_return2() {
   if(ENV) {
      if((ENV)->query_dead()) return 0;
      tell_object(ENV, "For no reason whatsoever, you suddenly lose concentration.\n");
      command("revert", ENV);
   }
}


unstrap_all() {
   if(ENV && weapon) {
      tell_object(ENV, "You unstrap " + lower_case(weapon->short()) + ".\n");
      ENV->remote_say((ENV->query_name()) + " stops wielding " + (weapon->query_name()) + " as a secondary weapon.\n");
      move_object(weapon, ENV);
      weapon = 0;
   }
}

query_weapons() { return weapon; }

