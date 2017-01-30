/* This weapon was made for Brimstone.  He turned in 
   some bugs and was awarded an altered weapon by 
   Maledicta.  Brimstone wanted to have his wep before
   he went away for active duty so he just requested 
   that Mal alter an exsiting weapon.  Now he that he's
   back he requested something a little more Unique.

   Fred
*/

inherit "obj/weapon.c";
#include "/players/fred/defines.h"
#define ME environment()->query_name()
#define WEP BOLD+RED+"D"+BLK+"e"+RED+"M"+BLK+"ons "+RED+"E"+BLK+"dge"+NORM 

reset(arg){
  ::reset(arg);
  if (arg) return;
  set_name("edge");
  set_alias("demons edge");
  set_short(WEP);
  set_long("The "+WEP+" is a finely crafted axe that until now was\n"+
           "only believed to be that of legend. It's composed of a\n"+
           "massive blade on a thick handle carved entirely from marble.\n"+
           "Forged deep within the depths of hell, fire still consumes\n"+
           "the axe. Only it's rightful owner will be able to harness its\n"+
           "true power.\n");   
  set_type("axe");  
  set_class(18);
  set_weight(2);
  set_value(0);
 set_hit_func(this_object());
}

weapon_hit(attacker){
int MSG, WHERE, COLOR, A, B, HOW;
int bonus;
A = (int)environment()->query_attrib("sta");
B = (int)environment()->query_attrib("str");
"/players/maledicta/weapon/powers/flame.c"->main(EN, TO, "edge", WEP); 
"/players/maledicta/weapon/powers/cleansing.c"->main(EN, TO, "edge", WEP); 
"/players/maledicta/weapon/powers/fire.c"->main(EN, TO, "edge", WEP);

  switch(random(6)){
    case 0: COLOR = HIR; break; 
    case 1: COLOR = HIC; break; 
    case 2: COLOR = HIB; break;
    case 3: COLOR = HIM; break;
    case 4: COLOR = HIG; break; 
    case 5: COLOR = HIY; break;
  }

  switch(random(10)){
    case 0: MSG = "smashing"; break; 
    case 1: MSG = "obliterating"; break; 
    case 2: MSG = "slicing"; break;
    case 3: MSG = "gouging"; break; 
    case 4: MSG = "hacking"; break; 
    case 5: MSG = "tearing into"; break;
    case 6: MSG = "slaughtering"; break; 
    case 7: MSG = "stabbing"; break;
    case 8: MSG = "destroying"; break;
    case 9: MSG = "devastating"; break;
  }

 switch(random(9)){
    case 0: WHERE = "chest"; break; 
    case 1: WHERE = "leg"; break;
    case 2: WHERE = "arm"; break; 
    case 3: WHERE = "neck"; break; 
    case 4: WHERE = "ribs"; break; 
    case 5: WHERE = "chest"; break; 
    case 6: WHERE = "stomach"; break;
    case 7: WHERE = "side"; break;
    case 8: WHERE = "torso"; break;
  }

 switch(random(7)){
    case 0: HOW = "dances across"; break;
    case 1: HOW = "leaps off of"; break;
    case 2: HOW = "engulfs"; break;
    case 3: HOW = "surrounds"; break;
    case 4: HOW = "ignites around"; break;
    case 5: HOW = "erupts from"; break;
    case 6: HOW = "flickers on"; break;
  }

  switch(random(21)){
    case 0..7:
      if(A+B > 39){
        write("You scream wildly "+COLOR+""+MSG+""+NORM+" "+attacker->query_name()+"'s "+WHERE+"!\n");
        say(TPN+" screams wildly "+COLOR+""+MSG+""+NORM+" "+attacker->query_name()+"'s "+WHERE+"!\n");
        return(1+random(3)) + bonus;
      }
      return 0;
    break;

    case 8..12:
      if(A+B > random(100)){  
        write(COLOR+"\n       F I R E "+NORM+"\n\n"+
                    "              "+HOW+"\n\n"+
                    "                     your "+WEP+"!\n");
        
        say(COLOR+"\n       F I R E "+NORM+"\n\n"+
                  "                "+HOW+"\n\n"+
                  "                       "+ME+"'s "+WEP+"!\n");
        return 1 + bonus;
      }
      return 0;
    break;
  }
 return bonus;
}

get(){
  if(TP)
    if(TPRN != "brimstone" && TPRN != "fred") return 0;
  return 1;
 }

query_wear() { return 1; }
