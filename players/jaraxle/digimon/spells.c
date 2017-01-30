inherit "/players/jaraxle/digimon/emotes.c";
inherit "obj/monster";
#include "/players/jaraxle/define.h"
object target, owner, environment;
string name;
int level, hp, wc, ac, guarding, DIGI_NAME, FORMED, DIGI_FORM, SPELL_COUNT, SPELL_WAIT;
int FIRE_OK, ICE_OK, ELEC_OK, MIS_OK, EAR_OK, WAT_OK, SHIELD, WC;
void
init()
{
   ::init();
   add_action("digivolve","digivolve");
   add_action("cast_fire","digi_fire");
   add_action("cast_ice","digi_ice");
   add_action("cast_elec","digi_elec");
   add_action("cast_ear","digi_ear");
   add_action("cast_mis","digi_mis");
   add_action("cast_wat","digi_wat");
   add_action("shield_me","digi_shield");
   add_action("check_me","check_me");
   add_action("heal_me","self_heal");
}

/* heal_me spell done with courtesy of Pain's help */
heal_me(str){
   int amt;
   
if(!str){ write(capitalize(DIGI_NAME)+" says, 'You must specify an amount of DigiPower for me to use to heal.'\n"); return 1; }
if(sscanf(str, "%d", amt) != 1) { write(capitalize(DIGI_NAME)+" says, 'You must specify an amount of DigiPower for me to use to heal.'\n"); return 1; }
if(amt < 1) { write(capitalize(DIGI_NAME)+" says, 'You must specify an amount of DigiPower for me to use to heal.'\n"); return 1; }
  if(SPELL_COUNT < amt){ write(capitalize(DIGI_NAME)+" says, 'I can heal a maximum of "+HIR+"["+HIY+SPELL_COUNT+HIR+"]"+NORM+" hitpoints.'\n"); return 1; }
   this_object()->heal_self(amt);
   tell_object(owner, ""+capitalize(DIGI_NAME)+" transfers "+amt+" gigs of DigiPower to its hitpoints.\n");
   tell_object(owner,""+HIC+">>> "+NORM+capitalize(DIGI_NAME)+": "+HIG+       (this_object()->query_hp())+" / "+this_object()->query_mhp()+""+NORM+"\n");
   SPELL_COUNT -=amt;
   return 1; }

/* End Pain's help. :) */

check_me(){
   tell_object(owner,""+HIC+">>> "+NORM+capitalize(DIGI_NAME)+": "+HIG+       (this_object()->query_hp() * 10)/this_object()->query_mhp()+" / 10"+HIC+" <<<\n"+NORM);
   return 1; }

shield_me(){
   if (!check_ok()) return 0;
   if(present("magi@shield", this_object())){ write(DIGI_NAME+" already has a defensive field.\n"); return 1; }
   if(SPELL_COUNT <= 40){ write(capitalize(DIGI_NAME)+" tells you, 'I need "+HIR+"["+HIY+"40"+HIR+"]"+NORM+" gigs of DigiPower for this!'\n"); return 1; }
   if(FORMED <=0){ write(DIGI_NAME+" looks confused!\n"); return 1; }
   if(SHIELD == 1){ write(DIGI_NAME+" has a shield!\n"); return 1; }
   tell_room(environment(), "With a whirling sound, a "+HIM+"defensive force field"+NORM+" bubbles over "+capitalize(DIGI_NAME)+"!\n");
   MOCO("/players/jaraxle/digimon/shield.c"),this_object());
   SHIELD +=1;
   SPELL_COUNT -=19;
   call_out("stop_shield", 30);
   return 1; }

cast_fire(str){
   object target;
   if (!check_ok()) return 0;
   if (!str) return 0;
   if(SPELL_COUNT <= 15){ write(capitalize(DIGI_NAME)+" tells you, 'I need "+HIR+"["+HIY+"16"+HIR+"]"+NORM+" gigs of DigiPower for this!'\n"); return 1; }
   if(SPELL_WAIT >=1){ write(capitalize(DIGI_NAME)+" tells you, 'Wait a moment!'\n"); return 1; }
   if(FORMED <=0){ write(capitalize(DIGI_NAME)+" looks confused!\n"); return 1; }
   if(FIRE_OK = 0){ write(capitalize(DIGI_NAME)+" looks confused!\n"); return 1; }
   target = present(str, environment(this_object()));
   if (!target || !living(target) || !target->query_npc()) {
      write(capitalize(DIGI_NAME)+" looks at you with a confused expression.\n");
      return 1;
   }
   tell_object(owner, ""+capitalize(DIGI_NAME)+" yells, '"+HIR+"FIR"+HIY+"E BLAS"+HIR+"TER!"+NORM+"'\n");
   tell_room(environment(), "\t"+capitalize(DIGI_NAME)+" breathes "+HIR+"FIRE"+NORM+" on "+target->query_name()+"!\n");
   this_object()->attack_object(target);
   target->add_hit_point(-1-random(40));
   SPELL_WAIT +=1;
   SPELL_COUNT -=16;
   call_out("spell_wait", 10);
   return 1;
}

cast_ice(str){
   object target;
   if (!check_ok()) return 0;
   if (!str) return 0;
   if(SPELL_COUNT <= 10){ write(capitalize(DIGI_NAME)+" tells you, 'I need "+HIR+"["+HIY+"11"+HIR+"]"+NORM+" gigs of DigiPower for this!'\n"); return 1; }
   if(SPELL_WAIT >=1){ write(capitalize(DIGI_NAME)+" tells you, 'Wait a moment!'\n"); return 1; }
   if(FORMED <=0){ write(capitalize(DIGI_NAME)+" looks confused!\n"); return 1; }
   if(ICE_OK = 0){ write(capitalize(DIGI_NAME)+" looks confused!\n"); return 1; }
   target = present(str, environment(this_object()));
   if (!target || !living(target) || !target->query_npc()) {
      write(capitalize(DIGI_NAME)+" looks at you with a confused expression.\n");
      return 1;
   }
   tell_room(environment(), ""+capitalize(DIGI_NAME)+" yells, '"+HIC+"FREE"+HIW+"ZING C"+HIC+"RUSH!"+NORM+"'\n\t"+capitalize(DIGI_NAME)+" drops a "+HIC+"glacier"+NORM+" of "+HIW+"ICE"+NORM+" on "+target->query_name()+"!\n");
   this_object()->attack_object(target);
   target->add_hit_point(-1-random(30));
   SPELL_WAIT +=1;
   SPELL_COUNT -=11;
   call_out("spell_wait", 10);
   return 1;
}

cast_elec(str){
   object target;
   if (!check_ok()) return 0;
   if (!str) return 0;
   if(SPELL_COUNT <= 5){ write(capitalize(DIGI_NAME)+" tells you, 'I need "+HIR+"["+HIY+"6"+HIR+"]"+NORM+" gigs of DigiPower for this!'\n"); return 1; }
   if(SPELL_WAIT >=1){ write(capitalize(DIGI_NAME)+" tells you, 'Wait a moment!'\n"); return 1; }
   if(FORMED <=0){ write(capitalize(DIGI_NAME)+" looks confused!\n"); return 1; }
   if(ELEC_OK = 0){ write(capitalize(DIGI_NAME)+" looks confused!\n"); return 1; }
   target = present(str, environment(this_object()));
   if (!target || !living(target) || !target->query_npc()) {
      write(capitalize(DIGI_NAME)+" looks at you with a confused expression.\n");
      return 1;
   }
   tell_room(environment(), ""+capitalize(DIGI_NAME)+" yells, '"+HIY+"SUP"+HIW+"ER SH"+HIY+"OCK!'\n\t"+capitalize(DIGI_NAME)+" "+HIY+"shocks"+NORM+" "+target->query_name()+" with a jolt of "+HIY+"electricity"+NORM+" from its eyes!\n");
   this_object()->attack_object(target);
   target->add_hit_point(-1-random(20));
   SPELL_WAIT +=1;
   SPELL_COUNT -=6;
   call_out("spell_wait", 10);
   return 1;
}


cast_ear(str){
   object target;
   if (!check_ok()) return 0;
   if (!str) return 0;
   if(SPELL_COUNT <= 9){ write(capitalize(DIGI_NAME)+" tells you, 'I need "+HIR+"["+HIY+"10"+HIR+"]"+NORM+" gigs of DigiPower for this!'\n"); return 1; }
   if(SPELL_WAIT >=1){ write(capitalize(DIGI_NAME)+" tells you, 'Wait a moment!'\n"); return 1; }
   if(FORMED <=0){ write(capitalize(DIGI_NAME)+" looks confused!\n"); return 1; }
   if(EAR_OK = 0){ write(capitalize(DIGI_NAME)+" looks confused!\n"); return 1; }
   target = present(str, environment(this_object()));
   if (!target || !living(target) || !target->query_npc()) {
      write(capitalize(DIGI_NAME)+" looks at you with a confused expression.\n");
      return 1;
   }
   tell_room(environment(), ""+capitalize(DIGI_NAME)+" yells, '"+GRN+"SHAK"+BLU+"E"+GRN+" 'EM UP!"+NORM+"'\n\t"+capitalize(DIGI_NAME)+" stomps its foot on the ground!\nThe ground rumbles beneath "+target->query_name()+"!\n");
   this_object()->attack_object(target);
   target->add_hit_point(-3-random(13));
   SPELL_WAIT +=1;
   SPELL_COUNT -=10;
   call_out("spell_wait", 9);
   return 1;
}

cast_wat(str){
   object target;
   if (!check_ok()) return 0;
   if (!str) return 0;
   if(SPELL_COUNT <= 5){ write(capitalize(DIGI_NAME)+" tells you, 'I do not have the strength!\n"); return 1; }
   if(SPELL_WAIT >=1){ write(capitalize(DIGI_NAME)+" tells you, 'Wait a moment!'\n"); return 1; }
   if(FORMED <=0){ write(capitalize(DIGI_NAME)+" looks confused!\n"); return 1; }
   if(WAT_OK = 0){ write(capitalize(DIGI_NAME)+" looks confused!\n"); return 1; }
   target = present(str, environment(this_object()));
   if (!target || !living(target) || !target->query_npc()) {
      write(capitalize(DIGI_NAME)+" looks at you with a confused expression.\n");
      return 1;
   }
   tell_room(environment(), ""+capitalize(DIGI_NAME)+" yells, '"+HIB+"AQUA BLASTER!"+NORM+"'\n\t"+BLU+"Water"+NORM+" rushes from "+capitalize(DIGI_NAME)+"'s mouth, drowning "+target->query_name()+"!\n");
   this_object()->attack_object(target);
   target->add_hit_point(-2-random(5));
   SPELL_WAIT +=1;
   SPELL_COUNT -=5;
   call_out("spell_wait", 3);
   return 1;
}


cast_mis(str){
   object target;
   if (!check_ok()) return 0;
   if (!str) return 0;
   if(SPELL_COUNT <= 20){ write(capitalize(DIGI_NAME)+" tells you, 'I do not have the strength!\n"); return 1; }
   if(SPELL_WAIT >=1){ write(capitalize(DIGI_NAME)+" tells you, 'Wait a moment!'\n"); return 1; }
   if(FORMED <=0){ write(capitalize(DIGI_NAME)+" looks confused!\n"); return 1; }
   if(MIS_OK = 0){ write(capitalize(DIGI_NAME)+" looks confused!\n"); return 1; }
   target = present(str, environment(this_object()));
   if (!target || !living(target) || !target->query_npc()) {
      write(capitalize(DIGI_NAME)+" looks at you with a confused expression.\n");
      return 1;
   }
   tell_object(owner, ""+capitalize(DIGI_NAME)+" yells, 'ROCKET BLASTER!'\nA dozen ballistic missiles rocket into "+target->query_name()+"!/n");
   this_object()->attack_object(target);
   target->add_hit_point(-1-random(45));
   SPELL_WAIT +=1;
   SPELL_COUNT -=20;
   call_out("spell_wait", 5);
   return 1;
}


digivolve(){
   if (!check_ok()) return 0;
   if(!present("digi_volver",this_player())){ 
      write("You need a DigiDevice to do this.\n");
      return 1; }
   if(FORMED >= 1){
      write(capitalize(DIGI_NAME)+" is already DigiVolved!\n");
      return 1; }
   if(TP->query_sp() < 150){
      write("You do not have enough power to DigiVolve "+capitalize(DIGI_NAME)+"!\n");
      return 1; }
    if(SPELL_COUNT <= 24){ write(capitalize(DIGI_NAME)+" tells you, 'I need "+HIR+"["+HIY+"25"+HIR+"]"+NORM+" gigs of DigiPower to DigiVolve!'\n"); return 1; }
   tell_object(owner, "You cry out...\n"+
      ""+capitalize(DIGI_NAME)+" DigiVolve to....\n"+
      "MEGA "+capitalize(DIGI_NAME)+"!\n");
   tell_room(environment(), ""+TPN+" cries out...\n"+
      "\t"+capitalize(DIGI_NAME)+" DigiVolve to....\n"+
      "\t   MEGA "+capitalize(DIGI_NAME)+"!\n");
   TP->add_sp(-150);
   SPELL_COUNT -=25;
    WC +=2;
   switch(random(6)){
      case 0: FIRE_OK = 1;
      break;
      case 1: ICE_OK = 1;
      break;
      case 2: ELEC_OK = 1;
      break;
      case 3: MIS_OK = 1;
      break;
      case 4: EAR_OK = 1;
      break;
      case 5: WAT_OK = 1;
      break;
   }
   DIGI_FORM = ""+HIW+"("+HIB+"Champion"+HIW+")"+NORM+"";
   FORMED = 1;
   call_out("revert_me", 80);
   /* This should make the morph last about 4 minutes */
   return 1; }
