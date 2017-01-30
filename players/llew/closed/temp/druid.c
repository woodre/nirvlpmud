#include "/players/llew/closed/ansi.h"

inherit "obj/monster";

int hasted,held,stunned,aura_count,count;
int magic;
string casting, cast;
mixed about_to_kill;
string spells;

reset(arg) {
   ::reset(arg);
   if(arg) return;
   cast=({}); 
   set_name("druid");
   set_level(19);
   set_alias("draidecht");
   set_race("human");
   set_hp(1000+random(500));
   set_al(0);
   set_short("Druid");
   set_long("An aged druid with dark penetrating eyes.\n"+
      "Long gray-white hair woven with mustaches curls down\n"+
      "around a brown wool robe.  Pouches of unknown substaces\n"+
      "adorn the rope around his waist.  The oak staff clutched\n"+
      "boldly and proudly radiates it own aura of power.\n"+
      "The druid stares at you as you enter.  He looks old,\n"+
      "wise, and EXTREMELY dangerous.\n");
   set_wc(31);
   set_ac(17);
   set_dead_ob(this_object());
   set_hbflag("hbstayon");
   set_chat_chance(6);
   set_a_chat_chance(14);
   load_chat("Druid chants softly to himself.\n");
   load_chat("Druid breaths deeply of the forest air.\n");
   load_chat("Druid whispers, 'Wary of what lies in the Other World...'\n");
   load_chat("Druid whispers, 'The realities are becoming unstable.'\n");
   load_chat("Druid whistles to a passing bird in the sky.\n");
   load_chat("Druid eats a wild berry.\n");
   load_chat("Druid whispers, 'Sunwise circles... three to pass... the time between times...'\n");
   load_chat("A deer walks through the clearing, stops briefly, and continues on its way.\n");
   load_chat("Druid whispers, 'The balance must be restored.  Order must be saved.'\n");
   load_chat("Druid whispers, 'Time is unraveling itself.'\n");
   load_chat("Druid whispers, 'Sacred circle come to pass.'\n");
   load_chat("Druid whispers, 'A prophecy is soon to come, the stars have forseen it.'\n");
   load_a_chat("Druid transforms into a bear, ripping you to shreds with his claws.\n");
   load_a_chat("Druid transforms into a wolf, gnashing it's teeth menacingly.\n");
   load_a_chat("Druid concentrates deeply.\n");
   load_a_chat("Druid transforms into a tiger, baring it's fangs.\n");
   load_a_chat("Druid tranforms into a giant hawk, clawing you with enormous talons.\n");
   load_a_chat("Druid says, 'The world will be lost... Who will save us?'\n");
   spells=({"call_lightning","regeneration","heal","haste","stun","aura","hold_person","anti_magic"});
}

short() {
   string temp_short;
   temp_short="Draidecht the Druid";
   if(member_array("anti_magic",cast) > -1) 
      temp_short=HIB+"[ "+NORM+temp_short+HIB+" ]"+NORM;
   if(member_array("aura",cast) > -1) 
      temp_short=HIW+"( "+NORM+temp_short+HIW+" )"+NORM;
   if(member_array("regeneration",cast) > -1)
      temp_short=HIY+"* "+NORM+temp_short+HIY+" *"+NORM;
   return temp_short;
}

heart_beat() {
   ::heart_beat();
   if(casting) call_other(this_object(),"do_"+casting,0);
   if(sizeof(cast) > 0) {
      int loop,sl;
      string tmpcast;
      tmpcast=cast;
      for(loop=0,sl=sizeof(tmpcast);sl > loop;loop++) {
         call_other(this_object(),"do_"+tmpcast[loop],0);
      }
   }
   if(!casting && query_attack()) cast_a_spell();
   if(!query_attack() && hit_point < max_hp && random(100) < 12) do_heal();
}

cast_a_spell() {
   if(random(100) < 20) {
      while(!casting || member_array(casting,cast) > -1) 
         casting=spells[random(sizeof(spells))];
      count=1;
      call_other(this_object(),"do_"+casting,0);
   }
}

do_aura() {
   if(aura_count && !random(10)) say("The "+BOLD+"Aura"+NORM+" flashes brightly.\n");
   if(aura_count < 0) {
      say("The "+BOLD+"Aura"+NORM+" around the druid flickers and fades.\n");
      aura_count=0;
      cast -= ({"aura"});
      return;
   }
   if(aura_count) return;
   switch(count) {
      case 1:
         say("Druid begins to whisper dark words in an ancient tongue...\n");
         say("Druid chants, \"Ynnara conneth...\"\n");
         count++;
         break;
      case 2:
         say("Druid chants, \"Ynnara conneth...\"\n");
         count++;
         break;
      case 3:
         say("Druid chants, \"Ynnara conneth...\"\n");
         say("A white light brightens around the druid.\n");
         count++;
         break;
      case 4:
         say("Driud chants, \"Conneth triusi!\"\n");
         say("An "+BOLD+"Aura"+NORM+" protects the druid from all attack.\n");
         count=0;
         casting=0;
         aura_count=150+random(100);
         cast += ({"aura"});
         break;
   }

}

      
   

do_regeneration() {
   if(member_array("regeneration",cast) > -1) {
      hit_point += 3;
      if (hit_point > max_hp) hit_point = max_hp;
      if(hit_point >= max_hp) {
         say("The yellow glowing pricks of light fade away.\n");
         cast -= ({"regeneration"});
         return;
      }
      if(!random(20)) 
         say("Tiny"+HIY+"*"+NORM+" stars of glowing"+HIY+"*"+NORM+" yellow "+
            "light spin slowly around "+HIY+"*"+NORM+"Druid.\n");
      return;
   }
   switch(count) {
      case 1:
         say("Druid begins to whisper dark words in an ancient tongue...\n");
         say("Druid chants, \"Noch tegid feral...\"\n");
         count++;
         break;
      case 2:
         say("Druid chants, \"Haeth glarw tom tafannan...\"\n");
         count++;
         break;
      case 3:
         say("Pricks of dim yellow light being to merge in the air.\n");
         say("Druid chants, \"Noch tegid feral...\"\n");
         count++;
         break;
      case 4:
         say("Druid chants, \"Haeth glarw tom tafannan...\"\n");
         say("Tiny"+HIY+"*"+NORM+" stars of glowing"+HIY+"*"+NORM+" yellow "+
            "light coalesce around "+HIY+"*"+NORM+"Druid.\n");
         count=0;
         casting=0;
         cast += ({"regeneration"});  
         break;
   }
}

do_call_lightning() {
         object *rmi;
         int x;
   switch(count) {
      case 1:
         say("Druid begins to whisper dark words in an ancient tougue...\n");
         say("Druid chants, \"Dogla ocht twllyth...\"\n");
         count++;
         break;
      case 2:
         say("A wind begins to pick up--the leaves start to rustle...\n");
         say("Druid chants, \"Twp glarhon phin ith...\"\n");
         count++;
         break;
      case 3:
         say("You hear a distant rumbling rising in volume...\n");
         say("Druid chants, \"Glyn Riyah!\"\n");
         count++;
         break;
      case 4:
         say("A great "+BOLD+"FLASH"+NORM+" of light explodes as a lightning bolt chars everything.\n");
         rmi=all_inventory(environment(this_object()));
         for(x=0;x<sizeof(rmi);x++) {
            if(living(rmi[x]) && rmi[x] != this_object() && !rmi[x]->query_ghost()) {
               int xx;
               if(rmi[x]->query_hp() < 40) {
                  death_dest(rmi[x]);
                  return;
               }
               for(xx=0;xx < 3;xx++) {
                  if(rmi[x]->query_hp() > 41) rmi[x]->hit_player(40);
                  else rmi[x]->hit_player(rmi[x]->query_hp()-1);
               }
            }
         }
         casting=0;
         count=0;
         break;
   }
   return;
}

death_dest(d) {
   string atta_name;
   d->transfer_all_to("players/llew/Celts/misc/dest_object");
   atta_name=d->query_real_name();
   d->heal_self(-(d->query_hp()+1));
   say(capitalize(atta_name)+" is charred beyond recognition.\n");
   destruct(present("corpse of "+atta_name,environment()));
   transfer(clone_object("players/llew/Celts/weapons/caled_dust.c"),environment());
}

stop_fight() {
   if(!attacker_ob->query_interactive() && !attacker_ob->query_npc()) {
      attacker_ob = alt_attacker_ob;
      alt_attacker_ob = 0;
   }
}

query_interactive() { return 1; }
is_player() { if(member_array("anti_magic",cast) > -1) return 1; }
query_npc() { if(member_array("anti_magic",cast) == -1) return 1; }

drink_soft() { return 1; }
drink_alcohol() { return 1; }
eat_food() { return 1; }
query_attrib() { return 100; }

do_anti_magic() {
   if(magic) {
      if(magic > 10+random(10)) {
         say("The "+HIB+"anti-magic"+NORM+" sphere around the druid dissipates.\n");
         magic=0;
         cast -= ({"anti_magic"});
      }
      else magic++;
      return;
   }
   switch(count) {
      case 1:
         say("Druid begins to whisper dark words in an ancient tongue...\n");
         say("Druid chants, \"Mathyn rhan terra...\"\n");
         count++;
         break;
      case 2:
         say("Druid chants, \"Tolas rhan terra...\"\n");
         say("An "+HIB+"anti-magic"+NORM+" sphere forms around druid, blocking all spells.\n");
         cast += ({"anti_magic"});
         casting=0;
         count=0;
         magic=1;
         break;
   }
}


do_hold_person() {
   if(held) {
      if(held > 10+random(8)) {
         say("You are no longer magically bound.\n");
         environment(this_object())->no_exit(0);
         held=0;
         cast -= ({"hold_person"});
      }
      else held++;
      return;
   }

   switch(count) {
      case 1:
         say("Druid begins to whisper dark words in an ancient tongue...\n");
         say("Druid chants, 'Lwch kiwyn nohm...'\n");
         count++;
         break;
      case 2:
         say("Druid chants, \"Selwyn caglyr...\"\n");
         say("The air around you beings to sparkle with relfected light.\n");
         count++;
         break;
      case 3:
         say("Druid chants, \"Rhodekai pledd!\"\n");
         say("A dome of sparkling energy covers the clearing.\n");
         say("You feel bound and cannot leave.\n");
         held=1;
         count=0;
         casting=0;
         cast+=({"hold_person"});
         environment(this_object())->no_exit(1);
         break;
   }
}

do_heal() {
   say("Druid chants, \"Lydair hadda rhostelchwdd...\n");
   say("Druid heals himself.\n");
   hit_point += 15+random(35);
   if(hit_point > max_hp) hit_point=max_hp;
   count=0;
   casting=0;
}

do_haste() {
   if(hasted) {
      object *ri,first;
      int X,SO;
      already_fight=0;
      attack();
      already_fight=0;
      attack();
      first=attacker_ob;
      for(X=0,ri=all_inventory(environment()),SO=sizeof(ri);SO>X;X++) {
         if(ri[X]->query_attack() == this_object() && ri[X] != first) {
            already_fight=0;
            attack_object(ri[X]);
         }
         attack_object(first);
      }
      if(stunned) do_stun();
      if(random(8)+6 < hasted) {
         say("Druid beings to slow down...\n");
         hasted=0;
         cast -= ({"haste"});
         set_ac(17);
         return;
      }
      hasted++;
      return;
   }
   if(count) {
      switch(count) {
         case 1:
            say("Druid begins to whisper dark words in an ancient tongue...\n");
            say("Druid chants, 'Stinh lokh toru...'\n");
            count++;
            break;
         case 2:
            say("Druid starts moving at a quickened pace.\n");
            say("Druid chants, 'Glaen Gurw...'\n");
            count++;
            break;
         case 3:
            say("Druid chants, 'Flan treddra!'\n");
            say("Druid hastes himself beyond normal ability.\n");
            count=0;
            hasted=1;
            cast += ({"haste"});
            casting=0;
            set_ac(8);
            break;
      }
   }
}

do_stun() {
   if(stunned) {
      attacker_ob->stop_fight();
      attacker_ob->stop_fight();
      if(stunned > random(4)+3) {
         cast -= ({"stun"});
         stunned=0;
         return;
      }
      stunned++;
      return;
   }
   if(count) {
      say("Driud says, \"Shen!\"\n");
      tell_object(attacker_ob,"You feel completely frozen in place.\nYour muscles refuse to attack.\n");
      stunned=1;
      cast += ({"stun"});
      count=0;
      casting=0;
      attacker_ob->stop_fight();
      attacker_ob->stop_fight();
   }
}


init() {
   ::init();
   add_action("disspell","sonic");
   add_action("disspell","so");
   add_action("disspell","missile");
   add_action("disspell","mi");
   add_action("disspell","shock");
   add_action("disspell","sh");
   add_action("disspell","fireball");
   add_action("disspell","fi");
   add_action("cannot_quit","quit");
}
disspell(str) {
   if(member_array("anti_magic",cast) > -1) {
      if(str == "druid" || this_player()->query_attack() == this_object()) {
         write("The "+HIB+"Anti-Magic"+NORM+" sphere around the druid prevents\n"+
            "you casting spells against him.\n");
         return 1;
      }
   }
}


hit_player(dam,zap) {
   if(member_array("aura",cast) > -1) {
      aura_count -= dam;
      return 0;
   }
   return ::hit_player(dam,zap);
}

heal_self(amt) {
   if(!amt) return;
   if(member_array("aura",cast) > -1) 
      if(amt < 0) {
         aura_count -= amt;
         amt=0;
      }
   hit_point += amt;
   if (hit_point > max_hp) hit_point = max_hp;
   if(amt > 0) {
      spell_points += amt;
      if(spell_points > max_spell) spell_points = max_spell;
   }
}
