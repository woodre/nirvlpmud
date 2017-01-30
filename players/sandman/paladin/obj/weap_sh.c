
/* 
 * WEAPON SHADOW (2/12/94)
 */

#define GUILD present("pro_object", this_player())
#define MIN_ALIGN 0

object weap;
string weapon_type;

start_weapon_shadow(what) {
   weap = what;
   weapon_type = "sword";
   shadow(weap,1);
   return 1;
}

query_pro_weapon() { return 1; }

short() {
   if(GUILD)
     return weap->short()+" [PW]";
   return weap->short()+"";
}

/* Add proficiency damage..called from living.c in attack() */
proficiency_hit(ob) {
   int pro, counter, str;       
   
   if(environment(weap)->query_alignment() < MIN_ALIGN) {
     write("[P] You are unworthy of Paladin skills!\n");
     return 0;
   }
   str = environment(weap)->query_attrib("str");
   pro = ob->query_weapon_pro(weapon_type);
   pro = (pro*2)/5;
   counter = (str*2) + (pro*3);
   counter = random(counter);
   if(ob->query_blessed()) 
     counter += ob->query_blessed();
   if(counter <= 5) {
     write("[P] You swing wildy at your opponent.\n");
     return -10;
   } else
   if(counter <= 30) {
     return pro;
   } else
   if(counter <= 65) {
     write("[P] You skillfully attack your target.\n");
     return (pro + str/5);
   } else
   if(counter <= 85) {
     write("[P] You throw all your strength behind your blow.\n");
     return (pro + (2*str)/5);
   } else
   if(counter > 85) {
     write("[P] All your skill and strength come together for a "+ 
                                      "punishing strike!\n");
     return ((pro*3)+str)/2;
   }
   return pro;
}   
