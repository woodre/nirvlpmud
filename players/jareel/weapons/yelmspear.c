#include "/obj/ansi.h"
inherit "/obj/weapon.c";
#define CHANCE (10 + (this_player()->query_extra_level()/5))
#define ME this_player()->query_possessive()
#define MEE this_player()->query_objective()

int chance;
object ob;
int limit = 2;  
  reset(arg) {
    ::reset(arg);
    if(arg) return;

    set_id("yelm");
    set_alias("yelm spear");
    set_short(YEL +"A "+ HIY +"legendary"+ NORM + YEL +" spear of "+ HIY +"Yelm"+ NORM);
    set_long(
       "This is forged in the searing hot blast furnace of the sun god Yelm.\n"+
       "A razor sharp edge atop of a long perfectly balanced shaft makes for\n"+
       "the perfect weapon of destruction.\n");
    set_weight(1);
    set_class(20);
    set_value(3500);
    set_type("spear");
    message_hit = ({ 
      HIY+"thrusts"+NORM," in the eye",
      HIY+"stabbed"+NORM," in the chest",
      HIY+"chopped"+NORM," in the arm",           
      HIY+"impaled"+NORM," in the stomach",
      HIY+"stabbed"+NORM," in the body",
      HIY+"slashed"+NORM," in the knee",
      HIY+"sweeped"+NORM," in the leg"
      });
     set_hit_func(this_object());
}

     init() {
       ::init();
}

weapon_hit(attacker) {
  int i, dam, ret;
  string m1, m2;
  string name;
  string *msg;

  if (!attacker || !environment() || !environment(attacker))
    return 0;
 if(!this_player()) return 0;
  if (this_player()->query_real_name() == "doran" || (this_player() != environment(this_object())))
    return 0;
  
  if (chance < random(100)) {
    chance = CHANCE;
    attacker->hit_player(random(10), "magical");
    return random(5);
  }

  if (this_player()->query_level() < 19) noob();
  if (!random(5) && !environment()->is_kid())
    this_player()->heal_self(-(random(10)));

  name = attacker->query_name();
  dam = class_of_weapon+random(5);

  msg = query_message_hit(random(dam));
  m1 = msg[1];
  m2 = msg[0];
  tell_object(this_player(), "You "+m1+ " " + name+""+m2+".\n");
  if (attacker)
    tell_object(attacker, this_player()->query_name()+" "+m1+" you"+m2+".\n");
  tell_room(environment(this_player()), this_player()->query_name()+" "+m1+" "+name+m2+".\n", ({ attacker, this_player() }) );

  attacker->do_damage( ({ dam }), ({ "physical" }) );
  chance = (chance * 2) / 3;
  ret = weapon_hit(attacker);
  return (ret > 5 ? 5 : ret);
}

noob()
{
  int r,x,y,z,amt;
  string it,how;
  x = this_player()->query_level();
  y = random(10);
  r = random(6);
  z = 1+random(x);  
    switch(y)
    {
      case 0: it = "shoulder"; break;
      case 1: it = "arm"; break;
      case 2: it = "mid section"; break;
      case 3: it = "leg"; break;
      case 4: it = "head"; break;
      case 5: it = "shin"; break;
      case 6: it = "foot"; break;
      case 7: it = "thigh"; break;
      case 8: it = "face"; break;
      case 9: it = "ankle"; break;
    }
    switch(r)
    {
      case 0: how = "CRACK"; break;
      case 1: how = "SMACK"; break;
      case 2: how = "GOUGE"; break;
      case 3: how = "SLASH"; break;
      case 4: how = "CUT"; break;
      case 5: how = "WHACK"; break;
    }
    if(x < 6)            amt = 9;
    if(x > 5 && x < 8)   amt = 7;
    if(x > 7 && x < 11)  amt = 6;
    if(x > 10 && x < 14) amt = 5;
    if(x > 13 && x < 17) amt = 4;
    if(x > 16)           amt = 3;
    if((z*amt) > random(100))
    {
  tell_object(this_player(),
    "You flail "+BOLD+YEL+"wildly"+NORM+" due to your lack of experience and "+BOLD+BLK+how+NORM+" yourself in the "+it+"!\n");
  tell_room(environment(this_player()),
  this_player()->query_name()+" flails "+BOLD+YEL+"wildly"+NORM+" due to "+ME+" lack of experience and "+BOLD+BLK+how+"S "+NORM+MEE+"self in the "+it+"!\n", ({ this_player() }));
  if(x > 10)
    {
    this_player()->hit_player(1+random(x), "other|jareel");
    }
  else
    {
    this_player()->hit_player((x*(1+random(3))), "other|jareel");
    } 
  return -20;
  }
}