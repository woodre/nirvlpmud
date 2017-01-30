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

#define  F81 HIY+"              Xbo.                      .odX"+NORM
#define  F82 HIY+"             `xXx.                  .xXx'"+NORM
#define  F83 HIY+"                `YX.                .XY'"+NORM
#define  F84 HIY+"                 X)x.              .x(X                 .'"+NORM
#define  F85 HIY+"                 .Xn              nX.                  <"+NORM
#define  F86 HIY+"                  xX.            .Xx                  dY"+NORM
#define  F87 HIY+"  ?.         .oP     9o           .oP     9o.         .P'X"+NORM
#define  F88 HIY+" O b.      .X'      dXY.          .YXb      'X.      .d(P'"+NORM
#define  F89 HIY+" ?b Y    .dY'       XXPb          d?XX       'Yb.    Y dP"+NORM
#define  F90 HIY+"  X b.  .d X       dXYQP.        .?RYXb       X d   .d X"+NORM
#define  F91 HIY+"  )9 VPoP  Y     .d) ooo )dPPPPb( ooo (b.     Y  9o9V P("+NORM
#define  F92 HIY+"o'X        L. .oodPPP ' d'      'b ' '?@boo. .J        X'o."+NORM
#define  F93 HIY+"?bo         Po.          '                 .o9         odPYx."+NORM
#define  F94 HIY+"   '9        RPo .odPXx            .o9bo. o9Z        P'     )"+NORM
#define  F95 HIY+"    Y             'Xb 'Xn         x  dX'             Y      '"+NORM
#define  F96 HIY+"   dP        .pP. 'o 'p bn      .d q' o' .9q.        9b"+NORM
#define  F97 HIY+"  'X   oTb.,XY''d9 'P..8o9      P.8..9' Pb''YX..dTo   X'"+NORM
#define  F98 HIY+".YP' 'X' 'X(   xY'      '        '      'Yx   )X' 'X. '9Y."+NORM
#define  F99 HIY+"XbP dY     'P. XP                        9X .9'     Yd 9dX"+NORM
#define  F100 HIY+"'Xb X.       ' Yb.                      .dY '       .X dX'"+NORM
#define  F111 HIY+"  Yb'Y        ('Xx   .dPn.      .n9b.   xX')        Y'dY"+NORM
#define  F112 HIY+"   'b(        I .9  d9.o 9o.  .oP o.Pb  PC I        )d'"+NORM
#define  F113 HIY+"    '>       .'b 'b  "  'b.9  P.d'     d' d'.      .'"+NORM
#define  F114 HIY+"    .'       >>(dP'9.     '' '''     .P'9b)''     '"+NORM
#define  F115 HIY+"             '. >b.d'b,.          ..d'b.d' .'"+NORM
#define  F116 HIY+"              .   V. d'''?bo..odP'''b .V   .<"+NORM
#define  F117 HIY+"               .    '.'(Xx XxYyPdX('.'    .<"+NORM

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
    set_short(GRN+"Blood"+BOLD+"raven"+NORM);
    set_long(
GRN+"Blood"+BOLD+"raven"+NORM+" has been crafted by Graum, with ore extracted from deep within the Dark Tunnels.\n"+
"The "+GRN+"emerald"+NORM+" hue of the steel edge has been forged in dragon's flame, to create a keen razor\n"+
"sharp Valerian blade.  On one side of the blade is engraved a constellation chart of heavenly\n"+
"bodies, on the other side is a topographical map of mountains, forests, plains and rivers.\n"+ 
"A twirling 'Dragon' glyph is engraved upon the guard, hilt and scabbard each being a different\n"+
"hue. A rich "+GRN+"green emerald"+NORM+" rests in the pommel surrounded by four ribs giving the impression of a\n"+
"dragon's claw clutching it.  "+GRN+"Blood"+BOLD+"raven"+NORM+" is capable of cutting through magical Dragon wards and \n"+ 
"Draconic beings.  The faint "+GRN+"emerald"+NORM+" hue flows from the hilt over the razor-sharp blade absorbing\n"+
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
    write(GRN+"\nBlood"+BOLD+"raven"+NORM+" slices "+attacker->query_name()+" with deadly grace!\n"+
    "                              "+attacker->query_name()+" recoils with fear and horror.\n"+NORM);
    say(environment()->query_name()+" descends upon "+attacker->query_name()+" with "+GRN+"Blood"+BOLD+"raven"+NORM+"!\n"+
    "                                                       "+attacker->query_name()+" recoils with fear and horror.\n"+NORM);
  attacker->hit_player(2+random(2), "other|physical");
  }

  if(fire==0){
    if(!attacker) return 1;
    write(GRN+"Blood"+BOLD+"raven"+NORM+" poised above your head unleashes a deadly rain of "+BOLD+RED+"fire.\n"+F1+"\n"+F2+"\n"+F3+"\n"+F4+"\n"+F5+"\n"+F6+"\n"+F7+"\n"+F8+"\n"+NORM);
    say(environment()->query_name()+" holds "+environment()->query_possessive()+GRN+"Blood"+BOLD+"raven"+NORM+" poised above "+attacker->query_name()+"'s head "+BOLD+RED+"FIRE.\n"+NORM);
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

   swordhit=random(999999);
   if(!random(1) && check_race(attacker)){ /* This Weapon Attack is only really for NecroSan Might trigger 1 in a billion times otherwise */
       if(!attacker) return 1;

        tell_room(environment(this_player()),
HIC+"Chaos is unleashed!!!!!!!\n"+NORM+""+
F81+"\n"+F82+"\n"+F83+"\n"+F84+"\n"+F85+"\n"+F86+"\n"+F87+"\n"+F88+"\n"+
F89+"\n"+F90+"\n"+F91+"\n"+F92+"\n"+F93+"\n"+F94+"\n"+F95+"\n"+F96+"\n"+NORM);
        tell_room(environment(this_player()),
F97+"\n"+F98+"\n"+F99+"\n"+F100+"\n"+F111+"\n"+F112+"\n"+F113+"\n"+F114+"\n"+
F115+"\n"+F116+"\n"+F117+"\n"+NORM);
 attacker->hit_player(75+random(50), "other|light"); /* Only affects Specific Mobs in My area sword is designed to light up to kill these mobs */
      return 1;
   }
}

check_race(object ob) {
  if(
    CO(ob,"id","zombie-dragon") ||
    CO(ob,"id","necrosen") ) return 1;
  else return 0;
}
