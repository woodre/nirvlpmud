#include "/players/pestilence/ansi.h"
inherit "/obj/weapon.c";
#define CHANCE (10 + (this_player()->query_extra_level()/5))

#define ME this_player()->query_possessive()
#define MEE this_player()->query_objective()

/* Global Variables */
int chance;
object ob;
int limit = 3;  

  reset(arg) {
    ::reset(arg);
    if(arg) return;

    set_id("leg");
    set_alias("queen leg");
    set_short(""+HIY+"Queen Ant's leg"+NORM+"");
    set_long(
"This is one of the large rear legs of the "+HIY+"Queen Ant"+NORM+".\n"+
"The leg is long and seems very flexible.  It also appears to act as\n"+
"if it's still alive.  There is a "+CYN+"magical"+NORM+" aura surrounding the leg.\n");
    set_weight(2);
    set_class(18);
    set_value(8000);
    set_type("polearm");
    /* 10/07/05 Earwax: These need further work. */
    /* 10/07/05 Earwax: These need further work. */
    message_hit = ({ 
    ""+HIR+"impaled"+NORM+""," through the heart",  
    ""+RED+"destroyed"+NORM+""," into small pieces",
    ""+HIK+"devastated"+NORM+""," into a pile of pulp",
    ""+HIK+"crushed"+NORM+""," over the head with the leg",
    ""+HIK+"punctured"+NORM+"","'s left lung",
    ""+BLU+"jabbed"+NORM+""," in the arm",
    ""+BLU+"prodded"+NORM+""," in the eye",
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
  if (this_player()->query_real_name() == "mondar" || (this_player() != environment(this_object())))
    return 0;
  
  if (chance < random(100)) {
    chance = CHANCE;
write(""+HIY+"The Queen ant's leg moves like it's alive"+NORM+".\n"+
      "The leg digs itself deep into "+attacker->query_name()+"'s flesh leaving "+RED+"blood"+NORM+" flowing everywhere.\n");
say(""+HIY+"The Queen ant's leg moves like it's alive"+NORM+".\n"+
"The leg digs itself deep into "+attacker->query_name()+"'s flesh leaving "+RED+"blood"+NORM+" flowing everywhere.\n");
    attacker->hit_player(random(10), "magical");
    return random(5);
  }

  /* Do mean things if it's a kid or a noob */
  if (this_player()->query_level() < 19) noob();
  if (!random(5) && !environment()->is_kid())
    this_player()->heal_self(-(random(10)));

  name = attacker->query_name();
  dam = class_of_weapon+random(5);

  /* Get the hit message. */
  msg = query_message_hit(random(dam));
  m1 = msg[1];
  m2 = msg[0];
  tell_object(this_player(), "You "+m1+ " " + name+""+m2+".\n");
  if (attacker)
    tell_object(attacker, this_player()->query_name()+" "+m1+" you"+m2+".\n");
  tell_room(environment(this_player()), this_player()->query_name()+" "+m1+" "+name+m2+".\n", ({ attacker, this_player() }) );

  /* Do damage, recurse. */
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
         this_player()->hit_player(1+random(x), "other|fred");
       }
       else
       {
         this_player()->hit_player((x*(1+random(3))), "other|fred");
       } 
       return -20;
    }
}       
