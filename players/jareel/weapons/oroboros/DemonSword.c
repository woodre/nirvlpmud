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

reset(arg) {
  ::reset(arg);
     if(arg) return;
       set_class(20);
	   set_light(-1);
       set_weight(1);
       set_value(4000);
       set_type("sword");
       set_alias("blade");
       set_alt_name("blackfyre");
set_long(

YEL+"Storm"+BOLD+"bringer"+NORM+" has been crafted by Graum, with ore extracted from deep within the Dark Tunnels.\n"+
"The burnt "+YEL+"amber"+NORM+" hue of the steel edge has been forged in dragon's flame, to create a keen razor\n"+
"sharp Valerian blade.  On one side of the blade is engraved a constellation chart of heavenly\n"+
"bodies, on the other side is a topographical map of mountains, forests, plains and rivers.\n"+ 
"A twirling 'Demon' glyph is engraved upon the guard, hilt and scabbard each being a different\n"+
"hue. A dark "+YEL+"amber"+NORM+" rests in the blades pommel surrounded by four ribs giving the impression of a\n"+
"dragon's claw clutching it.  "+YEL+"Storm"+BOLD+"bringer"+NORM+" is capable of cutting through magical Demon wards and \n"+ 
"Demonic beings.  The faint "+YEL+"amber"+NORM+" hue flows from the hilt over the razor-sharp blade absorbing\n"+
"the surrounding lighting with its strange mystical gleaming power.\n");
       set_hit_func(this_object());
}

query_wear() {
   return 1;
}

weapon_breaks() {
   return 1;
}

weapon_hit(attacker) {

   int swordhit; /* Specials Trigger a lot and look like they do a lot of damage but it is mostly spam */
   int good;     /* Damage is 2+random of 2 aditional damage at the most */
   int head;     /* Spam is made to Look pretty and have some function as this weapon is very hard to obtain */
   int speed;
   int physical;
   int fire;
   int ice;
   int wind;
   
  good = random(5);
  head = random(5);
  speed = random(5);
  physical = random(5);
  fire = random(5);
  ice = random(5);
  wind = random(5);
  
 if(good==0){
    if(!attacker) return 1;
	if( environment() && environment()->is_player() && environment()->query_alignment() < 0 ) {
	  environment()->hit_player( 4, "other|good" );
	  tell_object( environment(), "The Sword righteousness aura burn your evil soul\n");
        }
    write(HIY+"\n   ==================================================================\n"+NORM+BOLD+"A Holy aura surrounds "+attacker->query_name()+" burning them in a righteous fever\n"+NORM+HIY+"   ===================================================================\n\n"+NORM);
    say("               \nA Holy aura engulfs "+attacker->query_name()+"\n\n"+NORM);
  attacker->hit_player(1+random(2), "other|good");
  }
 
  if(head==0){
    if(!attacker) return 1;
    write(RED+"Black"+BOLD+"fyre"+NORM+" bites deep into "+attacker->query_name()+" skin.\n"+NORM);
    say(environment()->query_name()+" slashes "+attacker->query_name()+" through "+attacker->query_possessive()+" head!\n"+NORM);
  attacker->hit_player(1+random(2));
  }
 
  if (speed==0){
      if(!attacker) return 1;
	  write("\n"+BOLD+BLINK+"    With blurring speed you rush your adversary\n             With blurring speed you rush your adversary\n                        With blurring speed you rush your adversary\n\n "+NORM);
	  say(environment()->query_name()+" blurs with blinding speed"+NORM+"\n");
    TP->attack();
    return 1;
  }

  if(physical==0){
    if(!attacker) return 1;
    write(RED+"\nBlack"+BOLD+"fyre"+NORM+" slices "+attacker->query_name()+" with deadly grace!\n"+
    "                              "+attacker->query_name()+" recoils with fear and horror.\n"+NORM);
    say(environment()->query_name()+" descends upon "+attacker->query_name()+" with "+RED+"Black"+BOLD+"fyre"+NORM+"!\n"+
    "                                                       "+attacker->query_name()+" recoils with fear and horror.\n"+NORM);
  attacker->hit_player(2+random(2), "other|physical");
  }

  if(fire==0){
    if(!attacker) return 1;
    write(RED+"Black"+BOLD+"fyre"+NORM+" poised above your head unleashes a deadly rain of "+BOLD+RED+"fire.\n"+F1+"\n"+F2+"\n"+F3+"\n"+F4+"\n"+F5+"\n"+F6+"\n"+F7+"\n"+F8+"\n"+NORM);
    say(environment()->query_name()+" holds "+environment()->query_possessive()+RED+" Black"+BOLD+"fyre"+NORM+" poised above "+attacker->query_name()+"'s head "+BOLD+RED+"FIRE.\n"+NORM);
  attacker->hit_player(1+random(2), "other|fire");
  }

  if(ice==0){
    if(!attacker) return 1;
    write(BLU+BLINK+"The blade becomes cold to the touch as it freezes the wound\n"+NORM);
    say(environment()->query_name()+" freezes the wound as the sword penetrates flesh!\n"+NORM);
  attacker->hit_player(2+random(3), "other|ice");
  }   

  if(wind==0){
    if(!attacker) return 1;
    write(NORM+attacker->query_name()+" slashes the wind and torrents ripple opening small wounds.\n"+NORM);
    say(environment()->query_name()+" gracefully whirls in closes to "+attacker->query_name()+"\n"+NORM);
  attacker->hit_player(1+random(2), "other|wind");
  }

   swordhit=random(100);
   if(!random(1) && check_race(attacker)){ /* This Attack only Lights up in My area unless people use My Specific id Tags */
       if(!attacker) return 1;

        tell_room(environment(this_player()),
HIC+"Chaos is unleashed!!!!!!!\n"+NORM+""+
RED+"  .o oOOOOOOOo                                            OOOo\n"+
"   Ob.OOOOOOOo  OOOo.      oOOo.                      .adOOOOOOO\n");
        tell_room(environment(this_player()),
"   OboO''''''''''''.OOo. .oOOOOOo.    OOOo.oOOOOOo..'''''''''''OO\n"+
"   OOP.oOOOOOOOOOOO 'POOOOOOOOOOOo.   `'OOOOOOOOOP,OOOOOOOOOOOB'\n");
        tell_room(environment(this_player()),
"   `O'OOOO'     `OOOOo'OOOOOOOOOOO` .adOOOOOOOOO'oOOO'    `OOOOo\n"+
"   .OOOO'            `OOOOOOOOOOOOOOOOOOOOOOOOOO'            `OO\n");
        tell_room(environment(this_player()),
"   OOOOO                  'OOOOOOOOOOOOOOOO`                 oOO\n"+
"  oOOOOOba.                .adOOOOOOOOOOba               .adOOOOo.\n");
        tell_room(environment(this_player()),
" oOOOOOOOOOOOOOba.    .adOOOOOOOOOO@^OOOOOOOba.     .adOOOOOOOOOOOO\n"+
"OOOOOOOOOOOOOOOOO.OOOOOOOOOOOOOO'`  ''OOOOOOOOOOOOO.OOOOOOOOOOOOOO\n");
        tell_room(environment(this_player()),
"OOOO'       'YOoOOOOMOIONODOO'`  .   ''OOROAOPOEOOOoOY'     'OOO'\n"+
"   Y           'OOOOOOOOOOOOOO: .oOOo. :OOOOOOOOOOO?'         :`\n");
        tell_room(environment(this_player()),
"   :            .oO%OOOOOOOOOOo.OOOOOO.oOOOOOOOOOOOO?         .\n"+
"   .            oOOP'%OOOOOOOOoOOOOOOO?oOOOOO?OOOO'OOo\n");
        tell_room(environment(this_player()),
"                '%o  OOOO'%OOOO%'%OOOOO'OOOOOO'OOO':\n");
        tell_room(environment(this_player()),
"                     `$'  `OOOO' `O'Y ' `OOOO'  o             .\n"+
"   .                  .     OP'          : o     .\n"+
"                            :\n"+NORM);

      attacker->heal_self(-(15+random(40))); /* Only affects Specific Mobs in My area sword is designed to light up to kill these mobs */
      return 1;
   }
}

check_race(object ob) {
  if(
    CO(ob,"id","chaos") ||
	CO(ob,"id","skeleton")||
    CO(ob,"id","broo") ||
    CO(ob,"id","rhino broo") ) return 1;
  else return 0;
}
