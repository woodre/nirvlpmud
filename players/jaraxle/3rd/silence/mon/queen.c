#include "/players/jaraxle/define.h"
inherit "obj/monster.c";

int exp_total;
reset(arg)  {
   object gold;
   ::reset(arg);
   exp_total = 0;
   if(arg) return;
   
   set_name("Queen Fairy");
   set_alias("queen");
   set_alt_name("queen fairy");
   set_race("fairy");
   set_short("Queen Fairy");
   set_gender("female");
   set_long(
      "  A "+HIR+"r"+HIM+"a"+HIC+"i"+HIG+"n"+HIB+"b"+HIY+"o"+BLK+BOLD+"w"+NORM+" of color radiates an aura of immense "+HIM+"magical"+NORM+" energy around the\n"+
      "beautiful Queen Fairy.  She has "+GRN+"dark green"+NORM+" eyes, and an enourmous head of "+HIB+"blue hair"+NORM+"\n"+
      "with "+HIY+"yellow strands"+NORM+" blended in.  Her thin body is overshadowed by giant feathered\n"+
      "wings that seem to move in a hypnotic pattern.\n");
   set_level(20);
   set_hp(500+random(100));
   set_al(0);
   set_ac(17);
   set_wc(30);
   set_dead_ob(this_object());
   set_chat_chance(5);
   load_chat("The fairy flutters her wings.\n");
   load_chat("The fairy zips through the air.\n");
   set_a_chat_chance(15);
   load_a_chat("The fairy dodges your attack!\n");
   gold = clone_object("obj/money");
   gold->set_money(5000+random(1001));
   move_object(gold,this_object());
}

monster_died() {
   tell_room(environment(this_object()),
      "The dead fairy plops to the ground.\n");
      MOCO("/players/jaraxle/3rd/silence/items/ring_piece5.c"),environment(this_object()));
   return 0; }


THORNS(){
   string ATT_NAME,ATT_LVL,ATT_LVL2;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   if(attacker_ob)  ATT_LVL = attacker_ob->query_level();
   if(attacker_ob)  ATT_LVL2 = attacker_ob->query_extra_level();
   
   say("The Queen Fairy claps her hands.\n\t"+YEL+"Thorns"+NORM+" crash down from the trees!\n");
   if(ATT_LVL >= 2){
      say("  The "+YEL+"thorns"+NORM+" zip past "+ATT_NAME+".\n");
      attacker_ob->hit_player(10+random(10), "other|earth");
   }
   
   if(ATT_LVL >= 12){
      say("    The "+YEL+"thorns"+RED+" scratch"+NORM+" across "+ATT_NAME+"'s body!\n"); 
      attacker_ob->hit_player(5+random(6), "other|earth");
      exp_total+=1;
   }
   
   if(ATT_LVL >= 17){
      say("    The "+YEL+"thorns"+RED+" slash"+NORM+" "+ATT_NAME+"'s body painfully!\n"); 
      attacker_ob->hit_player(10+random(11), "other|earth");
      exp_total+=1;
   }
   
   if(ATT_LVL2 > 4){
      say("  The "+YEL+"thorns "+HIW+"thunder"+NORM+" into "+ATT_NAME+"'s body!\n"); 
      attacker_ob->hit_player(20+random(11), "other|earth");
      exp_total+=1;
   }
}


WIND(){
   string ATT_NAME,ATT_LVL,ATT_LVL2;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   if(attacker_ob)  ATT_LVL = attacker_ob->query_level();
   if(attacker_ob)  ATT_LVL2 = attacker_ob->query_extra_level();
   
   say("Queen Fairy whips up a gust of "+HIB+"wind"+NORM+"...\n");
   if(ATT_LVL >= 2){
      say("  A "+HIB+"breeze"+NORM+" whisks by "+ATT_NAME+".\n");
      attacker_ob->hit_player(10+random(10), "other|wind");
   }
   
   if(ATT_LVL >= 12){
      say(HIB+"    Winds blow into "+ATT_NAME+".\n"+NORM);
      attacker_ob->hit_player(3+random(6), "other|wind");
      exp_total+=1;
   }
   
   if(ATT_LVL >= 17){
      say(HIW+"  A gust of wind pushes "+NORM+ATT_NAME+HIW+" to the floor!\n"+NORM);
      attacker_ob->hit_player(15+random(11), "other|wind");
      exp_total+=1;
   }
   
   if(ATT_LVL2 > 4){
      say(HIB+"Thunderous winds "+HIR+"punish "+NORM+ATT_NAME+".\n");
      attacker_ob->hit_player(25+random(16), "other|wind");
      exp_total+=1;
   }
}



SUN(){
   string ATT_NAME,ATT_LVL,ATT_LVL2;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   if(attacker_ob)  ATT_LVL = attacker_ob->query_level();
   if(attacker_ob)  ATT_LVL2 = attacker_ob->query_extra_level();
   
   say("Queen Fairy raises her hands to the sky...\n");
   if(ATT_LVL >= 2){
      say("  A "+HIW+"ray of light"+NORM+" glances "+ATT_NAME+".\n");
      attacker_ob->hit_player(10+random(10), "other|fire");
   }
   
   if(ATT_LVL >= 12){
      say(HIY+"    A ray of light "+HIW+"beams"+NORM+" to the ground and tans "+ATT_NAME+"!\n"+NORM);
      attacker_ob->hit_player(10+random(6), "other|fire");
      exp_total+=1;
   }
   
   if(ATT_LVL >= 17){
      say(HIW+"      The light "+HIR+"burns"+HIW+" into "+NORM+ATT_NAME+NORM+"!\n");
      attacker_ob->hit_player(15+random(16), "other|fire");
      exp_total+=1;
   }
   
   if(ATT_LVL2 > 4){
      say(HIY+"  Rays of "+HIW+"light"+HIY+" beam down, "+NORM+RED+"burning "+NORM+ATT_NAME+" to a "+HIR+"crisp"+HIY+"!"+NORM+"\n");
      attacker_ob->hit_player(25+random(21), "other|fire");
      exp_total+=1;
   }
}



LEAVES(){
   string ATT_NAME,ATT_LVL,ATT_LVL2;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   if(attacker_ob)  ATT_LVL = attacker_ob->query_level();
   if(attacker_ob)  ATT_LVL2 = attacker_ob->query_extra_level();
   
   say("Queen Fairy swarms up a "+HIG+"tornado of leaves."+NORM+"\n");
   if(ATT_LVL >= 2){
      say("  The "+HIG+"leaves"+NORM+" dance around "+ATT_NAME+".\n");
      attacker_ob->hit_player(10+random(10), "other|earth");
   }
   
   if(ATT_LVL > 12){
      say("    The "+HIG+"tornado of leaves"+NORM+" glance softly at "+ATT_NAME+".\n");
      attacker_ob->hit_player(5+random(5), "other|earth");
      exp_total+=1;
   }
   
   if(ATT_LVL >= 17){
      say("    The "+HIG+"tornado of leaves"+NORM+" snap dangerously at "+ATT_NAME+".\n");
      attacker_ob->hit_player(5+random(6), "other|earth");
      exp_total+=1;
   }
   
   if(ATT_LVL2 > 4){
      say("  The "+HIG+"tornado of leaves"+NORM+" lash "+HIR+"violently"+NORM+" at "+ATT_NAME+" spraying "+HIR+"blood"+NORM+" over the room!\n");
      attacker_ob->hit_player(15+random(11), "other|earth");
      exp_total+=1;
   }
}



FLOWER(){
   string ATT_NAME,ATT_LVL,ATT_LVL2;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   if(attacker_ob)  ATT_LVL = attacker_ob->query_level();
   if(attacker_ob)  ATT_LVL2 = attacker_ob->query_extra_level();
   
   say("Queen Fairy waves her hands in a swooping motion...\n");
   if(ATT_LVL >= 2){
      say("  A shower of "+HIM+"petals"+NORM+" dance around the Queen.\n");
      this_object()->heal_self(20+random(10));
   }
   
   if(ATT_LVL >= 12){
      say("    A rain of "+HIM+"flower petals"+NORM+" shower over the Queen.\n");
      this_object()->heal_self(10+random(6));
   }
   
   if(ATT_LVL >= 17){
      say("      Twirling "+HIM+"flowers"+NORM+" fall from the forest, protecting the Queen.\n");
      this_object()->heal_self(15+random(16));
   }
   
   if(ATT_LVL2 > 4){
      say("    Thorned "+HIR+"roses"+NORM+" drive into "+ATT_NAME+" like arrows!\n");
      attacker_ob->hit_player(20+random(16), "other|earth");
      exp_total+=1;
   }
}



ALL(){
   string ATT_NAME,ATT_LVL,ATT_LVL2;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   if(attacker_ob)  ATT_LVL = attacker_ob->query_level();
   if(attacker_ob)  ATT_LVL2 = attacker_ob->query_extra_level();
   if(attacker_ob && !attacker_ob->query_ghost()){
      
      say("The Queen Fairy rises high above you and spreads her wings wide apart...\n");
      say("   She holds out her palms...\n");
      say("      The Queen Fairy cries out, '"+BMAG+HIY+"YOU WILL NOT FORSAKEN ME!"+NORM+"'\n\n");
      
      if(ATT_LVL2 > 4){
         say("Thorned "+HIR+"roses"+NORM+" stab into "+ATT_NAME+" like arrows!\n"); 
         say("  Swirling "+HIB+"winds"+NORM+" swarm the room with "+HIW+"razor"+NORM+" sharp "+GRN+"leaves"+NORM+"!\n");
         say("   "+HIW+"Razor sharp "+NORM+GRN+"leaves"+NORM+" slice into "+ATT_NAME+", spraying "+RED+"blood"+NORM+" everywhere!\n");
         say("    An aura of "+HIY+"sunlight"+NORM+" surrounds the Queen Fairy...\n"+
            "     Queen Fairy reflects a "+HIR+"boiling "+HIY+"beam "+NORM+"of"+HIW+" light"+NORM+" through "+ATT_NAME+"!\n");
         say("  Giant log spears drive through "+ATT_NAME+"'s body!\n");
         attacker_ob->hit_player(55+random(41), "other|magic");
         exp_total+=1+random(5);
      }
      
      else if(ATT_LVL >= 17){                  
         say("\tTwirling "+HIM+"flowers"+NORM+" fall from the forest over the Queen Fairy.\n");
         say("\t\tA "+HIB+"tornado of winds"+NORM+" spin "+ATT_NAME+" in place.\n"); 
         say("\tA "+GRN+"giant leaf"+NORM+" slaps around "+ATT_NAME+".\n");
         say("\t\tA "+HIY+"giant beam of "+HIW+"light"+NORM+" drops down from the sky, and "+HIR+"~"+NORM+RED+"BURNS"+HIR+"~"+NORM+" "+ATT_NAME+" to a crisp!\n");
         say("\tGiant log spears drive through "+ATT_NAME+"'s body!\n");  
         this_object()->heal_self(25+random(16));    
         exp_total+=1;
         attacker_ob->hit_player(40+random(36), "other|magic");
      }
      
      else if(ATT_LVL >= 12){
         say("\tA rain of "+HIM+"flower petals"+NORM+" dance around the Queen Fairy.\n"); 
         say("\t\tA gust of "+HIB+"wind"+NORM+" lifts "+ATT_NAME+" in the air.\n");
         say("\t"+GRN+"Leaves"+NORM+" shoot into "+ATT_NAME+" like darts!\n");
         say("\t\tArrows of "+HIW+"light"+NORM+" penetrate "+ATT_NAME+"'s body!\n");
         say("\tTree branches drive into "+ATT_NAME+"'s chest!\n");
         this_object()->heal_self(20+random(6));
         exp_total+=1;
         attacker_ob->hit_player(36+random(26), "other|magic");
      }
      
      else if(ATT_LVL >= 2){
         say("\tA shower of "+HIM+"petals"+NORM+" dance around the Queen Fairy.\n"); 
         say("\t\tA gust of "+HIB+"wind"+NORM+" lifts "+ATT_NAME+" in the air.\n");
         say("\t"+GRN+"Leaves"+NORM+" twirl up from the ground circling "+ATT_NAME+".\n");
         say("\t\t"+HIW+"Rays o"+HIY+"f sunshine"+NORM+" shoot through the "+GRN+"leaves"+NORM+" into "+ATT_NAME+".\n");
         say("\tThorns shower in through the "+HIW+"rays o"+HIY+"f light"+NORM+"!\n"); 
         this_object()->heal_self(10+random(16));   
         attacker_ob->hit_player(20+random(16), "other|magic");
         exp_total+=1;
      }
   }
}

heart_beat(){
   int i;
   ::heart_beat();
   if(attacker_ob){
      i = random(18);
      switch(i){
         
         case 0..1: SUN();
         break;
         case 2..3: WIND();
         break;
         case 4..5: LEAVES();
         break;
         case 6..7: FLOWER();
         break;
         case 8..11: ALL();
         break;
         case 12..13: THORNS();
         break;
         case 14..17: return 0;
         break;
      }
      say("\t"+HIB+"BONUS: "+HIR+exp_total+NORM+"\n");
   }
}

calculate_worth(){
   if(attacker_ob && attacker_ob->is_player())
      set_wc_bonus(exp_total*2);
   return ::calculate_worth(); }
