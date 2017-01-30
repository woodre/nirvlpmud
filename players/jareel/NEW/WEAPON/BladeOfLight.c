inherit "obj/weapon";
#include <ansi.h>
#include "/players/jareel/define.h"
#include "/players/jareel/ansi.h"
#define CO call_other
#define USER environment()
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

reset(arg) {
  ::reset(arg);
     if(arg) return;
       set_class(20);
	   set_light(3);
       set_weight(1);
       set_value(4000);
       set_type("sword");
       set_alias("blade");
       set_alt_name("blade of light");
       set_short(
	   
HIY+"Blade"+NORM+BOLD+" of"+NORM+HIY+" Light"+NORM);
       
	   set_long(

	   HIY+"Blade"+NORM+BOLD+"of"+NORM+HIY+" Light"+NORM+" has been crafted by Graum, with ore extracted from deep within the Dark Tunnels.\n"+
"The "+HIY+"golden"+NORM+" hue of the steel edge has been forged in dragon's flame, to create a keen razor\n"+
"sharp Valyrian blade.  On one side of the blade is engraved a constellation chart of heavenly\n"+
"bodies, on the other side is a topographical map of mountains, forests, plains and rivers.\n"+ 
"A twirling 'Chaos' glyph is engraved upon the guard, hilt and scabbard each being a different\n"+
"hue. A nugget of "+HIY+"gold"+NORM+" rests in the pommel surrounded by four ribs giving the impression of a\n"+
"dragon's claw clutching it.  "+HIY+"Blade"+NORM+BOLD+"of"+NORM+HIY+" Light"+NORM+" is capable of cutting through magical Demon wards and \n"+ 
"Chaotic beings.  The faint "+HIY+"golden"+NORM+" hue flows from the hilt over the razor-sharp blade emanating \n"+
"with its strange mystical gleaming power.\n");

       set_hit_func(this_object());
}

query_wear() {
   return 1;
}

weapon_breaks() {
   return 1;
}

weapon_hit(attacker) {
   
   int swordhit;
   int ice;
   int wind;
 
  ice = random(5);
  wind = random(15);
 
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
