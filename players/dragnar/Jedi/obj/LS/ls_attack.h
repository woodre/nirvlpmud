#define ATTHP ((ATT->query_hp()*10)/(ATT->query_mhp()))

int base;
int hp_mod;
int multi;

ls_attack(string str){

if(!USER->query_attack()) return 0;

if(!str) return 0;

/***** Lunge attack ********************/
if(str == "lunge" || str == "1"){
base = 2 * SKILL;
if(SP < base) {
  tell_object(USER, "You are too drained to do that.\n");
  return 1;
}
USER->add_spell_point(-base);
multi = hp_mod(2); /* A higher number here in hp_mod() will allow for an
                      easier strike and more success if the opponents
                      hps are higher. */
modtype = "lunge";         /* also found in the paladin code, makes sure ppl
                              don't keep using the same attack over and over */
tell_object(USER, "\t\t\tMULTI: "+multi+".\n");
if(!multi){
tell_object(USER,
"You lunge at "+ATTN+" and miscalculate your strike.\n");
modifier = random(base/4); /* modifier is found in the paladin code for the wep */
return 1;
}

tell_object(USER,
"You lunge nimbly at "+ATTN+".\n");
modifier = base*multi;
return 1;
}
/***************************************/

/***** Side attack ********************/
if(str == "side" || str == "2"){
base = 2 * SKILL;
multi = hp_mod(7); /* A higher number here in hp_mod() will allow for an
                      easier strike and more success if the opponents
                      hps are higher. */
modtype = "side";         /* also found in the paladin code, makes sure ppl
                              don't keep using the same attack over and over */
tell_object(USER, "\t\t\tMULTI: "+multi+".\n");
if(!multi){
tell_object(USER,
"You sidestep at "+ATTN+" and miscalculate your strike.\n");
modifier = random(base/4); /* modifier is found in the paladin code for the wep*/
modtype = "side";         /* also found in the paladin code, makes sure ppl
                              don't keep using the same attack over and over */
return 1;
}

tell_object(USER,
"You sidestep around "+ATTN+" and slash at their exposed flank.\n");
modifier = base*multi;
return 1;
}
/***************************************/
return 1;
}


hp_mod(int i){
int number;
number = i - ATTHP;
  if(number < 0) number *= -1;
  if(number == 0) return 2;
  if(number == 1) return 1;
  return 0;

}


