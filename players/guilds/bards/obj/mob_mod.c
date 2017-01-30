/* original code by Maledicta.  recoded by Illarion for the Bards
 * duration can be increased without limit, but wc/ac can go no
 * lower than 2/3 of their original value
 *
 * 11 June 04 - Recoded to use RegisterArmor, which gets rid of the
 *              need to adjust set_ac_bonus
 *              generic_wc_bonus to adjust damage instead of set_ac
 *
 *
 */

get(){ return 1; }
drop(){ return 1; }

query_weight(){ return 0; }
query_value(){ return 0; }

int owc;
int oac;
int wc_difference;
int ac_difference;
int duration;

originals(){ 
 if(!environment() || owc || oac)
   return;
 owc = environment()->query_wc(); 
 oac = environment()->query_ac();
 wc_difference = 0;
 ac_difference = 0;

}
             
wc_mod(overflow){ 
  if(!environment() || !owc) return;
  if(!overflow) duration += 6;
  wc_difference++;
  if(wc_difference >= owc / 3) {
    wc_difference = owc / 3;  
    if(!overflow) ac_mod(1);
  }
} 
      
ac_mod(overflow){ 
  if(!environment() || !oac) return;
  if(!overflow)duration += 6; 
  ac_difference++;
  if(ac_difference >= oac / 3) {
    ac_difference = oac / 3;
    if(!overflow) wc_mod(1);
  }
  environment()->RegisterArmor(this_object(),({"physical",-ac_difference,0,"agony_ac_emote"}));
}

void check_max()
{
  if(wc_difference >= owc / 3)
    write(environment()->query_name()+"'s attack cannot be weakened any further.\n");
  if(ac_difference >= oac / 3) 
    write(environment()->query_name()+"'s defense cannot be weakened any further.\n");

}

reset() { 
  duration = 6;
  set_heart_beat(1);  
}

id(str) { return str == "bard_acwc_modifier" || str == "generic_wc_bonus"; }

agony_ac_emote() {
  if(!random(20) && environment() && environment(environment()) 
     && environment()->query_name())
  tell_room(environment(environment()),
    environment()->query_name()+"'s defense is hindered by the agony "+
    environment()->query_pronoun()+" suffers.\n",
    ({environment()}));
}
   

gen_wc_bonus() {
  if(!random(10) && environment() && environment(environment()) 
     && environment()->query_name())
  tell_room(environment(environment()),
    environment()->query_name()+"'s attack is hindered by the agony "+
    environment()->query_pronoun()+" suffers.\n",
    ({environment()})); 

  return -wc_difference;
}

heart_beat(){
 if(!environment())
   return;
 if(!living(environment())){ destruct(this_object()); }
 if(duration > 0)
   duration--;
 if(duration <= 0){
   return recover();
  }
  if(duration <=3){
  tell_room(environment(environment()),environment()->query_name()+" will soon recover from "+environment()->query_possessive()+" agony.\n");  
  }
}


recover() {
  if(!environment()) return;
  tell_room(environment(environment()),environment()->query_name()+" recovers from "+environment()->query_possessive()+" agony.\n");
  environment()->RemoveArmor(this_object());
  destruct(this_object());
}

no_exp_effect() { return 1; }
