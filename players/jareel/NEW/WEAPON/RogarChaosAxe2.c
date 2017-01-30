inherit "/obj/weapon.c";
#include "/players/jareel/define.h"

#define CO call_other
#define SETNAME HIG+"Set of the Berzerker"+NORM
#define FULLSETNAME HIG+"Full Set of the Berzerker"+NORM
#define WEP BOLD+"||"+NORM
#define  F1      HIR+"             (  "+NORM+RED+".     "+HIR+" )"+NORM
#define  F2      HIR+"         )           (              )"+NORM
#define  F3      HIR+"               "+NORM+RED+".  '   "+NORM+RED+".   '  "+NORM+RED+".  '  "+NORM+RED+"."+NORM
#define  F4      HIR+"      (    "+NORM+RED+","+HIR+" )       ("+NORM+RED+".  "+HIR+" )  (   '"+NORM+RED+", "+HIR+"   )"+NORM
#define  F5      HIR+"       "+NORM+RED+".' "+HIR+") ( "+NORM+RED+". "+HIR+")    "+NORM+RED+", "+HIR+" ( "+NORM+RED+",  "+HIR+"   )   ( "+NORM+RED+"."+NORM
#define  F6      HIR+"    )"+NORM+RED+". , "+HIR+"( "+NORM+RED+"."+HIR+"   (  ) ( "+NORM+RED+", '"+HIR+")  "+NORM+RED+".'"+HIR+" (  "+NORM+RED+",  "+HIR+"  )"+NORM
#define  F7      HIR+"   (_"+NORM+RED+","+HIR+") "+NORM+RED+"."+HIR+" )"+NORM+RED+","+HIR+" ) _) _"+NORM+RED+",'"+HIR+")  ("+NORM+RED+","+HIR+" ) '"+NORM+RED+". "+HIR+")  "+NORM+RED+",. "+HIR+"(' )"+NORM
#define  F8      HIR+"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"+NORM

#define  F9 BOLD+"                                  GOD"+NORM
#define  F10 BOLD+"             *      .            dZZZZZ,       .          *"+NORM
#define  F11 BOLD+"                                dZZZZ  ZZ,"+NORM
#define  F12 BOLD+"    *         .         ,AZZZZZZZZZZZ  `ZZ,_          *"+NORM
#define  F13 BOLD+"                   ,ZZZZZZV'      ZZZZ   `Z,`"+NORM
#define  F14 BOLD+"                 ,ZZZ    ZZ   .    ZZZZ   `V"+NORM
#define  F15 BOLD+"       *      ZZZZV'     ZZ         ZZZZ    _              ."+NORM
#define  F16 BOLD+".              V   l   .   ZZ        ZZZZZZ          ."+NORM
#define  F17 BOLD+"              l           ZZ,     ZZZ  ZZZZZZ,"+NORM
#define  F18 BOLD+"  .          /            ZZ l    ZZZ    ZZZ `Z,"+NORM
#define  F19 BOLD+"                         ZZ  l   ZZZ     Z Z, `Z,            *"+NORM
#define  F20 BOLD+"               .        ZZ      ZZZ      Z  Z, `l"+NORM
#define  F21 BOLD+"                        Z        ZZ      V  `Z   |"+NORM
#define  F22 BOLD+"                        V        ZZC     l   V"+NORM
#define  F23 BOLD+"          Z             l        V ZR        l      ."+NORM
#define  F24 BOLD+"           |             |       l  ZA"+NORM
#define  F25 BOLD+"                           |         C          C"+NORM
#define  F26 BOLD+"                                 |   K   /    /             K"+NORM
#define  F27 BOLD+"                         A    |   |  |  /  /              /"+NORM
#define  F28 BOLD+"                          |        |||/ /  /"+NORM
#define  F29 BOLD+"  __________________________________||/_________________________"+NORM
#define  F30 BOLD+"                                                                 "+NORM

object ob;


string *Weapon_pieces_The_Duo;

     reset(arg) {
       ::reset(arg);

     set_name("axe of the berzerker");
     set_value(4200);
	 set_class(20);
     set_weight(1);
     set_type("axe");
     set_short(RED+"Berserker Axe Bite"+HIK+"["+HIC+" Chaos Honed "+HIK+"]"+NORM+" ["+SETNAME+"]"+NORM);
  set_long(
    "A Ward forged in the moon forge of the Red Goddess high blacksmith Kar-relk, the mighty.\n"+
    "A palpable clinging darkness seeps out of the magical Ward.  The encircling darkness\n"+
	"seems to empower the magical energy within the encrusted Ward, great power lies within\n");

                     /* PUT THE ARMOR ID FOR THE SET HERE */
     set_hit_func(this_object());
  Weapon_pieces_The_Duo = ({ "ChaosAxeRoar", "ChaosAxeBite" });
     }

status id(string arg) { return ( ::id(arg) || arg == "ChaosAxeBite" || arg == "axe of bite"); }

int wield(string str) { 

if (str && !id(str))
        return 0;
  if ((int)this_player()->query_level() < 19) {
    write("This weapon is too powerful for you to Wield.\n"); 
    return 1; 
  }

  return (::wield(str) ? 1 : 0);
}

status check_full_set() {
  object wep, who;

  if(!USER) return 0;

  wep = present( "ChaosAxeRoar", USER ); 
  if( wep ) {
    who = (object) wep->query_wielded_by();
    if( who )
    /** If it is wielded **/
    if( who == USER )
      return 1;
    /** If it is offwield **/
    if( (object) USER->query_second_weapon() == wep )
      return 1;
    if( wep->query_wep_shadow() )
      return 1;
  }
  return 0;
}

int check_wielded() {
  return (int) this_object()->query_wielded() || (int) this_object()->query_wep_shadow();
}

string short() {

  if (check_full_set() && check_wielded() )
    set_short(RED+"Berserker Axe Bite"+HIK+"["+HIC+" Chaos Honed "+HIK+"]"+NORM+" ["+FULLSETNAME+"]"+NORM);
  else
    set_short(RED+"Berserker Axe Bite"+HIK+"["+HIC+" Chaos Honed "+HIK+"]"+NORM+" ["+SETNAME+"]"+NORM+""+NORM);
  return (string) ::short();
}

weapon_hit(attacker) {
     int swordhit;
     int ice;
     int wind;

  if( !check_full_set() ) 
    return 0;

 ice = random(5);
  wind = random(8);
 
  if (wind==0){
      if(!attacker) return 1;
	  write("\n"+BOLD+BLINK+"    With blurring speed you rush your adversary\n             With blurring speed you rush your adversary\n                        With blurring speed you rush your adversary\n\n "+NORM);
	  say(environment()->query_name()+" blurs with blinding speed"+NORM+"\n");
    TP->attack();
    return 1;
  }

  if(ice==0){
    if(!attacker) return 1;
    write(BLU+BLINK+"The blade becomes cold to the touch as it freezes the wound\n"+NORM);
    say(environment()->query_name()+" freezes the wound as the sword penetrates flesh!\n"+NORM);
  attacker->hit_player(3+random(4), "other|ice");
  }   

   swordhit=random(1000);
   if(!random(1) && check_race(attacker)){ /* This Attack only Lights up in My area unless people use My Specific id Tags */
       if(!attacker) return 1;

        tell_room(environment(this_player()),
REF+F9+"\n"+
F10+"\n");

        tell_room(environment(this_player()),
F11+"\n"+
F12+"\n");

        tell_room(environment(this_player()),
F13+"\n"+
F14+"\n");

        tell_room(environment(this_player()),
F15+"\n"+
F16+"\n");

        tell_room(environment(this_player()),
F17+"\n"+
F18+"\n");

        tell_room(environment(this_player()),
F19+"\n"+
F20+"\n");

        tell_room(environment(this_player()),
F21+"\n"+
F22+"\n");

        tell_room(environment(this_player()),
F23+"\n"+
F24+"\n");

        tell_room(environment(this_player()),
F25+"\n"+
F26+"\n");

        tell_room(environment(this_player()),
F27+"\n"+
F28+"\n");

        tell_room(environment(this_player()),
F29+"\n"+
F30+"\n");

        tell_room(environment(this_player()),
BOLD+F9+"\n"+
F10+"\n");

        tell_room(environment(this_player()),
F11+"\n"+
F12+"\n");

        tell_room(environment(this_player()),
F13+"\n"+
F14+"\n");

        tell_room(environment(this_player()),
F15+"\n"+
F16+"\n");

        tell_room(environment(this_player()),
F17+"\n"+
F18+"\n");

        tell_room(environment(this_player()),
F19+"\n"+
F20+"\n");

        tell_room(environment(this_player()),
F21+"\n"+
F22+"\n");

        tell_room(environment(this_player()),
F23+"\n"+
F24+"\n");

        tell_room(environment(this_player()),
F25+"\n"+
F26+"\n");

        tell_room(environment(this_player()),
F27+"\n"+
F28+"\n");

        tell_room(environment(this_player()),
F29+"\n"+
F30+"\n");

  attacker->hit_player(25+random(40), "other|light"); /* Only affects Specific Mobs in My area sword is designed to light up to kill these mobs */
      return 1;
   }
}

check_race(object ob) {
  if(
    CO(ob,"id","chaos") ||
    CO(ob,"id","dark demon") ||
    CO(ob,"id","sembrak") ||
    CO(ob,"id","cacodemon") ) return 1;
  else return 0;
}

