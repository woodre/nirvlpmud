inherit "obj/weapon.c";

#include "/players/pestilence/ansi.h"
#define tp this_player()->query_name()
#define TP this_player()
int w, i;

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name(""+MAG+"Donatello"+NORM+"'"+MAG+"s"+NORM+" Bo Staff");
  set_alias("staff");
  set_short(""+MAG+"Donatello"+NORM+"'"+MAG+"s"+NORM+" Bo Staff");
  set_long(
    "This weapon is a well balanced, slender, wooden polearm with with a leather grip\n");
  set_type("blunt");
  set_class(20);
  set_weight(3);
  set_value(2500);
  set_hit_func(this_object());
  message_hit=({
    ""+HIR+"AnNHiLaTeS"+NORM+""," with the mighty bo staff", 
    ""+RED+"iMpAlEd"+NORM+"","'s lung with a mighty thrust",
    ""+HIK+"WhAcKeD"+NORM+"","with a heftly swing",
    ""+RED+"CrUsHeS"+NORM+""," in the chest",
    ""+RED+"hItS"+NORM+""," with a decent blow",
    ""+BLU+"grazed"+NORM+""," with a slight attack",
    ""+BLU+"BoNkS"+NORM+""," with a pathetic attack",
  });
}

weapon_hit(attacker){
  int SMACKMEWITHASTICK;
  int TURTLE_TURBO;
  int BOSTICKSTRIKE;
  int BOSTICK;
    TURTLE_TURBO = random (10);
    SMACKMEWITHASTICK = random(40);
	BOSTICKSTRIKE = random(40);
	BOSTICK = random(40);
	
  if(SMACKMEWITHASTICK>15)  { /*Some Extra Damage Negligable */
    say(        MAG+"Donatello"+NORM+"'"+MAG+"s"+NORM+" staff crushes through flesh and bone spewing "+HIR+"blood"+NORM+" everywhere.\n");
    write(YEL+"\n  ())))))))))))))))))))))))))))"+WHT+"[///////]"+YEL+")))))))))))))))))))))))))))))            \n"+NORM+"\n");
    return (1+ random(3));
  }
  if (TURTLE_TURBO==0){ /* Extra Random Attack */
    if(!attacker) return 1;
	  write("\n"+BOLD+BLINK+"    INSERT TURTLE SPEED SPAM HERE\n                        With blurring speed you rush your adversary\n\n "+NORM);
	  say(environment()->query_name()+" TURTLE SPEED SPAM HERE"+NORM+"\n");
        TP->attack();
    return 1;
  }
  
  if(BOSTICKSTRIKE>12){
    if(!attacker) return 1;
      write(YEL+BLINK+"NINJA BOSTICKSTRIKE SPAM11111111111111111111\n"+NORM);
      BLINK+say(environment()->query_name()+"NINJA BOSTICKSTRIKE SPAM\n"+NORM);
        attacker->hit_player(4+random(4)+random(4)+random(4), "physical");
  }
  
  if(BOSTICK>12){
    if(!attacker) return 1;
      write(YEL+BLINK+"NINJA BOSTICKSTRIKE SPAM22222222222222222222222222\n"+NORM);
      BLINK+say(environment()->query_name()+"NINJA BOSTICKSTRIKE SPAM\n"+NORM);
        attacker->hit_player(4+random(4)+random(4)+random(4), "physical");
  }
  
return 0;
}