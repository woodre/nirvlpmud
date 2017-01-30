/* Fairly basic storable weapon.  Wc 18 weight 2, numerous specials, plus
   a bonus for fighting low(er) level monsters.  Found on /players/zeus/
   /museum/NPC/mutant.c.  Gives the appearance of dual hits   
   Approved by:  Snow  [3.4.00]  */
/*
// 2005.08.20 -Forbin
// Changes:
//   changed return 5 to return 7 and return 0-6 to return of 3 - 12
*/
#include <ansi.h>
inherit "/obj/weapon.c";
string *atk2;

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("knuckle blades");
  set_short("The "+BOLD+BLK+"Knuckle"+NORM+HIW+" blades "+
    NORM+"of Jerek the Mutant");
  set_type("dagger");
  set_long(
    "These blades used to be attached to the mutant Jerek.  Having taken\n"+
    "them from his corpse, they can now be used as a weapon.  Five blades\n"+
    "on each hand protrude out from a band that can be held by making a\n"+
    "fist.  Each blade has a very sharp serrated edge.\n");
  set_value(4072);
  set_weight(2);
  set_class(18);
  set_hit_func(this_object());
  message_hit=({
    RED+"horribly mutilated"+NORM, " with the knuckle blades",
    BOLD+BLK+"ripped open"+NORM+" a gaping wound in", "",
    BOLD+BLK+"hacked "+NORM+"and"+BOLD+BLK+" slashed"+NORM+" into", "",
    HIW+"tore"+NORM+" apart", "",
    HIW+"slashed"+NORM, "",
    "cut", "",
    "grazed", "",
  });
}

short(){
string heh;
 
heh = "The "+BOLD+BLK+"Knuckle"+NORM+HIW+" blades "+NORM+"of "; 

if(environment()){
 if(environment()->is_player()) heh += environment()->query_name()+"";
 else heh += "Jerek the Mutant";
 }
else heh += "Jerek the Mutant";

if(broke) heh += " [BROKEN]";
if(wielded) heh += " (wielded)";
 return heh;
 }


id(str) { return (::id(str) || str == "daggers" || str == "blades"); }
/*
id(str){ return str == "blades" || str == "knuckle blades" ||
                str == "daggers" || str == "dagger"; }
*/

string second(int a)  /* dual hit messages */
{
  if(a >= 30)
    atk2 = ({message_hit[0],message_hit[1]});
  else if(a > 26)
    atk2 = ({message_hit[2],message_hit[3]});
  else if(a > 20)
    atk2 = ({message_hit[4],message_hit[5]});
  else if(a > 14)
    atk2 = ({message_hit[6],message_hit[7]});
  else if(a > 8)
    atk2 = ({message_hit[8],message_hit[9]});
  else if(a > 4)
    atk2 = ({message_hit[10],message_hit[11]});
  else
    atk2 = ({message_hit[12],message_hit[13]});
}

int weapon_hit(object y){
  if(!random(4))
  {
    tell_object(environment(),
      "You lunge at "+y->query_name()+" with your knuckle blades.\n");
    tell_room(environment(environment()),
      environment()->query_name()+" lunges at "+y->query_name()+
      " with "+environment()->query_possessive()+
      " knuckle blades.\n", ({ environment() }));
  }
  else if(!random(4))
  {
    tell_object(environment(),
      "You jump at "+y->query_name()+", slashing with your knuckle blades.\n");
    tell_room(environment(environment()),
      environment()->query_name()+" jumps at "+y->query_name()+
      ", slashing with "+environment()->query_possessive()+
      " knuckle blades.\n", ({ environment() }));
  }
  else if(!random(4))
  {
    tell_object(environment(),
      "You spin with your knuckle blades extended.\n");
    tell_room(environment(environment()), environment()->query_name()+
      " spins with "+environment()->query_possessive()+
      " knuckle blades extended.\n", ({ environment() }));
  }
  else if(!random(4))
  {
    tell_object(environment(),
      "You descend upon "+y->query_name()+".\n");
    tell_room(environment(environment()), environment()->query_name()+
      " descends upon "+y->query_name()+".\n", ({ environment() }));
  }
  if(!random(5))  /* 20% return of 5 */
  {
    tell_object(environment(),
      "You slash into "+y->query_name()+" with your knuckle blades.\n"+
      RED+"Blood "+NORM+
      "begins to pour from "+y->query_name()+"'s wounds.\n");
    tell_room(environment(environment()),
      environment()->query_name()+" slashes into "+y->query_name()+
      " with "+environment()->query_possessive()+
      " knuckle blades.\n", ({ environment() }));
    return 7;
  }
  else if(!random(3))  /* dual hit, return of 0-6 */
  {
    if(!y->query_ghost())
    {
      int a;
      a = random(31);
      second(a);
      tell_object(environment(), 
        "You "+atk2[0]+" "+y->query_name()+atk2[1]+".\n");
      tell_room(environment(environment()), environment()->query_name()+
        " "+atk2[0]+" "+y->query_name()+atk2[1]+".\n", ({ environment() }));
      return (3 + (a / 3));
    }
  }
  else if(y->query_level() < 17 && !random(2))  /* low level return 0-2 */
    return random(3);
}

