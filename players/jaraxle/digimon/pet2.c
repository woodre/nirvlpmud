/* This is adapted from Sandman's basic pet code for a skeleton
and highly modified by me.  Jaraxle 2/4/02 */
   
#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/digimon/spells";
is_pet() { return 1; }

reset(arg) {
   DIGI_NAME = "DigiMon";
   DIGI_FORM = ""+HIG+"("+HIW+"none"+HIG+")"+NORM+"";
   FORMED = 0;
   SPELL_WAIT = 0;
   SPELL_COUNT = 0;
   FIRE_OK = 0;
   ICE_OK = 0;
   EAR_OK = 0;
   WAT_OK = 0;
   ELEC_OK = 0;
   MIS_OK = 0;
   SHIELD = 0;
   WC = 8;
   ::reset(arg);
   if (arg) return;
   set_alias("digimon");
   set_name("digimon");
   set_level(1);
   set_hp(1);
   set_wc(8);
   set_ac(1);

/* This was stolen from Wocket's neopet.c with permission from Wocket. */

message_hit = ({
         "hit","hard",
         "hit","",
     HIB+"STOMPS"+NORM+" on","",
     HIG+"kicks"+NORM,HIG+" very hard"+NORM,
     HIC+"punches"+NORM,HIC+" hard"+NORM,
     HIR+"bites"+NORM," horribly",
     HIM+"swats"+NORM," with its tail",
});
/* End thievery, -Thanks Wocket :) */

   enable_commands();
}
short(){ return ""+capitalize(DIGI_NAME)+", the DigiMon. "+DIGI_FORM+""; }
long(){
   if (!check_ok() && FORMED == 0){
      write("A small, cute looking DigiMon.  It stands on four legs, with a short\n"+
         "bushy tail.  It's eyes are wide with youth.\n");
      return 0; }
   if (!check_ok() && FORMED == 1){
      write("A huge DigiMon standing about ten feet.  It has enourmous paws, with sharp\n"+
         "metallic claws.  It has large snout, full of razor teeth.  Thin lines of steam\n"+
         "rise from its nostrills.  Two huge Rocket Launchers rest on its broad shoulders.\n");
      return 0; }
   write("You do the following things with your DigiMon:\n"+
            HIC+"attack "+HIY+"<"+HIC+"thing"+HIY+">"+NORM+",  "+HIC+"name "+HIY+"<"+HIC+"name"+HIY+">"+NORM+", "+HIC+"release digimon"+NORM+", "+HIC+"eat"+NORM+"\n"+
            HIC+"corpse"+NORM+", "+HIC+"protect"+NORM+", "+HIC+"check_me"+NORM+", "+HIC+"heel"+NORM+", "+HIC+"self_heal"+HIY+" <"+HIC+"amount"+HIY+">"+NORM+",\n"+
           "and "+HIC+"digimotes"+NORM+".\n"+
          capitalize(DIGI_NAME)+" is currently in form "+HIW+DIGI_FORM+HIG+NORM+"\n"+capitalize(DIGI_NAME)+"'s has "+HIR+"["+HIY+SPELL_COUNT+HIR+"]"+NORM+" gigs of DigiPower.\n");
  if(present("digi_volver",this_player()) && FORMED == 0){ 
          write("You can "+HIY+"digivolve"+NORM+" your DigiMon!\n");
}
  if(!present("digi_volver",this_player()) && FORMED == 0){ 
          write("If you have a DigiDevice you can "+HIY+"digivolve"+NORM+" your DigiMon\n");
}
   if(FORMED >=1){
   write(HIM+"digi_shield"+NORM+" now available.\n");
      if(FIRE_OK = 1){ write(""+HIR+"digi_fire "+HIW+"<"+HIR+"target"+HIW+">"+NORM+" now available.\n"); return 1; }
      if(ICE_OK = 1){ write(""+HIB+"digi_ice "+HIW+"<"+HIB+"target"+HIW+">"+NORM+" now available.\n"); return 1; }
      if(ELEC_OK = 1){ write(""+HIY+"digi_elec "+HIW+"<"+HIY+"target"+HIW+">"+NORM+" now available.\n"); return 1; }
      if(MIS_OK = 1){ write(BLK+BOLD+"digi_mis "+HIW+"<"+BLK+BOLD+"target"+HIW+">"+NORM+" now available.\n"); return 1; }
      if(EAR_OK = 1){ write(""+HIG+"digi_ear "+HIW+"<"+HIG+"target"+HIW+">"+NORM+" now available.\n"); return 1; }
      if(WAT_OK = 1){ write(""+HIC+"digi_wat "+HIW+"<"+HIC+"target"+HIW+">"+NORM+" now available.\n"); return 1; }
   }
}
patch_owner(o) { owner = o; }

/* The following was used from Wocket's neopet.c with permission from 
     Wocket. -Thanks :)  */

add_weight(){
   write(capitalize(DIGI_NAME)+" cannot carry that.\n");
return 0; }

init() {
   ::init();
   add_action("atk","attack");
   add_action("eat","eat");
   add_action("release","release");
   add_action("guard","guard");
   add_action("heel","heel");
   add_action("name","name");
}
atk(str) {
   object target;
   if (!check_ok()) return 0;
   if (!str) return 0;
   target = present(str, environment(this_object()));
   if (!target || !living(target) || !target->query_npc()) {
      write(capitalize(DIGI_NAME)+" looks at you with a confused expression.\n");
      return 1;
   }
   write(capitalize(DIGI_NAME)+" attacks "+target->query_name()+".\n");
   say(owner->query_name()+"'s DigiMon attacks "+
      target->query_name()+".\n");
   this_object()->attack_object(target);
   return 1;
}
eat(str) {
   object target;
   int value;
   if (!check_ok()) return 0;
   if (!str || str != "corpse") return 0;
   target = present("corpse",environment(this_object()));
   if(!target) {
      write("Your DigiMon does not see any corpses here.\n");
      
      return 1;
   }
   value=(int)target->heal_value();
   write(capitalize(DIGI_NAME)+" eats a corpse! (eww)\n");
   say(owner->query_name()+"'s DigiMon eats a corpse! (eew)\n");
   destruct(target);
   this_object()->heal_self(5+random(6));
   SPELL_COUNT +=value;
   return 1;
}

release(str) {
   if (!check_ok()) return 0;
   if(str != "digimon"){ write("Release digimon?\n"); return 1; }

   write("You release "+capitalize(DIGI_NAME)+" to the digital world.\n");
   say(owner->query_name()+" releases the DigiMon.\n");
   destruct(this_object());
   return 1;
}

guard() {
   if (!check_ok()) return 0;
   write(capitalize(DIGI_NAME)+" takes guard of this room.\n");
   say(owner->query_name()+"'s DigiMon surveys the area.\n");
   guarding = 1;
   return 1;
}

heel()
{
   object target;
   if (!check_ok()) return 0;
   write(capitalize(DIGI_NAME)+" yells, 'I'm ready, Trainer!'\n");
   say(owner->query_name()+"'s DigiMon gets ready!\n");
   target = this_object()->query_attack();
   if (target) {
      this_object()->stop_fight();
      target->stop_fight();
   }
   if (guarding) guarding = 0;
   set_heart_beat(1);
   return 1;
}

name(str) {
   if (!check_ok()) return 0;
   if (!str) return 0;
   write(capitalize(DIGI_NAME)+"'s name has been changed!\n");
   set_name(str);
   DIGI_NAME = str;
   write("Ok\n\tIt's new name is "+capitalize(DIGI_NAME)+"\n");
   return 1;
}

check_ok() {
   if (!owner) owner = this_player();
   if (this_player() != owner) {
      tell_object(owner, this_player()->query_name()+" is trying "+
         "to command your DigiMon.\n");
      return 0;
   }
   if(this_player()->query_ghost()) {
      write("You are a ghost!\n");
      return 0; }
   return 1;
}

catch_tell(str) {
   string s1,s2;
   object target;
   if (!guarding) return 1;
   if (!owner) destruct(this_object());
   if(sscanf(str, "%s %s.",s1,s2) != 2) return;
   if (lower_case(s2) == "arrives") {
      target = find_living(lower_case(s1));
      if (target) {
         tell_object(owner, "\n\n"+capitalize(DIGI_NAME)+" tells you: "+
            target->query_name()+" just entered the room!\n\n");
         return 1;
       }
   }
   return 1;
}
heart_beat() {
   ::heart_beat();
   if(!owner || (owner && owner->query_ghost())) { destruct(this_object()); return 1; }
   if (guarding) return;
   if (environment(this_object()) != environment(owner)) {
      tell_room(environment(this_object()), this_object()->query_name()+
         " leaves the room.\n");
      tell_room(environment(owner), this_object()->query_name()+
         " arrives.\n");
      move_object(this_object(),environment(owner));
   }
if(owner && this_object()->query_attack()) {
    tell_object(owner,""+HIC+">>> "+NORM+capitalize(DIGI_NAME)+": "+HIG+       (this_object()->query_hp())+" / "+this_object()->query_mhp()+""+
       NORM+"\n");
    }
}
   
spell_wait(){
   SPELL_WAIT -=1;
   write(DIGI_NAME+" yells, 'OK! READY!\n");
   tell_object(owner, ""+DIGI_NAME+" yells, 'OK! READY!\n");
   remove_call_out("spell_wait");
   return 1; }

revert_me(){
    WC -=2;
   FORMED = 0;
   DIGI_FORM = ""+HIG+"("+HIW+"none"+HIG+")"+NORM+"";
   tell_object(owner, ""+DIGI_NAME+" reverts back to normal. :( \n");
   FIRE_OK = 0;
   ICE_OK = 0;
   MIS_OK = 0;
   ELEC_OK = 0;
   EAR_OK = 0;
   WAT_OK = 0;
   remove_call_out("revert_me");
   return 1; }

stop_shield(){
   object shield;
   shield = present("digi@shield",this_object());
   destruct(shield);
   SHIELD = 0;
  tell_object(owner, "The "+HIM+"defensive force field"+NORM+" dissipates from "+DIGI_NAME+".\n");
   remove_call_out("stop_shield");
   return 1; }
