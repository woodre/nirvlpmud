/* The code of this thing turned into a tangled mess.  See stick.2011.6.18.c */
#include "/players/jenny/define.h"
#define ME TP->query_possessive()
#define MEE TP->query_objective()
inherit "/obj/weapon.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_id("hockey stick");
  set_alias("stick");
  set_short("A Hockey Stick");
  set_long(
      "This is a very old hockey stick.  It is made of wood, and is a little heavy.\n"+
      "The word 'LOUISVILLE' is written on the shaft in bold letters.  This stick\n"+
      "belongs to Gordie Howe, and helped him score 801 career goals in the NHL.\n");
   set_weight(4);
   set_class(20);
   set_value(3500);
   set_type("staff");
  message_hit = ({
    BOLD+"speared"+NORM," in the eye",
    BOLD+"wacked"+NORM," in the throat",
    BOLD+"chopped"+NORM," over the head",           
    BOLD+"slashed"+NORM," in the groin",
    BOLD+"butt ended"+NORM," in the ribs",
    BOLD+"hacked"+NORM," on the knee",
    BOLD+"slashed"+NORM," on the hand"
  });
  set_hit_func(this_object());
}
init() {
   ::init();
}
weapon_hit(attacker) {
  int dam;
  string *message;
  int i, times;
  string tname;

  if(!attacker) return 0;
  if(!TP || TPRN == "Gordie Howe") return 0;
  if(random(100) > 75) hithim(attacker);
  if(TP->query_level() < 19) noob();
  times = 1+random(2);
  while(attacker && times--) {
    tname = (string)attacker->query_name();
    if (!tname) tname = "your target";
    dam = (int)attacker->hit_player(random(class_of_weapon), "physical");
    message = query_message_hit(dam);
    write("You "+message[1]+" "+tname+message[0]+".\n");
    say((string)this_player()->query_name()+" "+message[1]+" "+tname+message[0]+".\n");
  }
  return 1+times;
}

void hithim(object target) {
  int slapshot;
  object puck;
  slapshot = (random(30) + 80);
  if(!TP) return 0;
  puck = present("jennypuck",TP);
  if(!target || !puck) return;
  write("\nYou take a few steps back, drop a "+BLK+"puck "+NORM+"on the ground, and nail "+target->query_name()+"\nwith a "+slapshot+" mph slapshot.\n");
  say("\n"+TPN+" takes a few steps back, drops a "+BLK+"puck "+NORM+"on the ground, and nails "+target->query_name()+"\nwith a "+slapshot+" mph slapshot.\n");
  target->hit_player(10+random(6));
  transfer(puck,"/room/void");
  destruct(puck);
}

query_wear() {
  return 3*::query_wear()/4;
}

/*  Added by Fred [5-25-04]
    I'm sick of seeing newbies running around with this thing
    Start additions */

noob()
{
  int r,x,y,z,amt;
  string it,how;
  x = TP->query_level();
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
      case 3: how = "HAMMER"; break;
      case 4: how = "POUND"; break;
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
       tell_object(TP,
         "You flail "+BOLD+YEL+"wildly"+NORM+" due to your lack of experience and "+BOLD+BLK+how+NORM+" yourself in the "+it+"!\n");
       tell_room(environment(TP),
         TP->query_name()+" flails "+BOLD+YEL+"wildly"+NORM+" due to "+ME+" lack of experience and "+BOLD+BLK+how+"S "+NORM+MEE+"self in the "+it+"!\n", ({ TP }));
       if(x > 10)
       {
         TP->hit_player(1+random(x), "other|fred");
       }
       else
       {
         TP->hit_player((x*(1+random(3))), "other|fred");
       } 
       return -20;
    }
}       

/*  END ADDITIONS */