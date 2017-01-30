/*
// 2005.08.20 -Forbin
// Changes:
//   raised the small special from return 6 to return 7
//   and changed large special from heal_self -(5 + r5), return 6 to
//   hit_player(5 + r10, "other|noblockme"), return 8
*/
inherit "/obj/weapon.c";
#include "/players/zeus/closed/all.h"
#define TQN  +target->query_name()+
#define TPO  +environment()->query_objective()+
#define TPP  +environment()->query_possessive()+

reset(arg) {
   ::reset(arg);
   if (arg) return;

  set_name("axe");
  set_alias("battle axe");
  set_type("axe");
  set_short(BOLD+"Tol'kor's Battle Axe"+NORM);
  set_long(
"This is the legendary battle axe of the ogre warrior Tol'kor.  The\n"+
"handle is made of fine wood, wrapped in bands of steel.  The head of\n"+
"the axe is gigantic, with two razor sharp edges.  Small grooves have\n"+
"been cut along the head of the axe in many places.\n");
  set_weight(5);
  set_value(3932);
  set_class(19);
  set_hit_func(this_object());
}

query_save_flag(){ if(broke) return 1;  return 0; }  /* storable */

fix_weapon()
{ 
  if(!broke) return 0;
  if(broke)
    write("This weapon is beyond repair, it cannot be fixed.\n");
  return 1;
}

weapon_breaks()
{
  if(broke) return 1;
  save_flag = 0;
  tell_object(environment(),
    "\nYou hear a loud crack as the head of your axe breaks!\n\n");
  class_of_weapon = 3;
  broke = 1;
  command("unwield "+name_of_weapon,environment());
  command("wield "+name_of_weapon,environment());
  long_desc =
"This is the legendary battle axe of the ogre warrior Tol'kor.  The\n"+
"handle is made of fine wood, wrapped in bands of steel.  The head of\n"+
"the axe is gigantic, with two razor sharp edges.  Small grooves have\n"+
"been cut along the head of the axe in many places.  There is a large\n"+
"crack running through the middle of head of the axe which makes it\n"+
"completely worthless in combat.\n";
  return 1;
}

int weapon_hit(object target){
  int type, sp1, sp2;
  type = random(4);
  sp1 = random(100);  
  sp2 = random(100); 

  if(sp1 <= 15)       /*  Small special  */
  {
    switch(type)
    {
    case 0:
      tell_object(environment(),
        "You swing the mighty battle axe into "TQN"!\n");
      tell_room(environment(ENV),
        ENV->QN+" swings "TPP" mighty battle axe into "TQN"!\n", ({ ENV }));
      break;
    case 1:
      tell_object(environment(),
        "You crunch "TQN" with your mighty battle axe!\n");
      tell_room(environment(ENV),
        ENV->QN+" crunches "TQN" with "TPP" mighty battle axe!\n", ({ ENV }));
      break;
    case 2:
      tell_object(environment(),
       "You raise your mighty battle axe into the air and lunge at "TQN"!\n");
      tell_room(environment(ENV), ENV->QN+
        " raises "TPP" mighty battle axe into the air and lunges at "TQN"!\n",
    ({ ENV }));
      break;
    case 3:
      tell_object(environment(),
        "You plunge your mighty battle axe into "TQN"!\n");
      tell_room(environment(ENV),
        ENV->QN+" plunges "TPP" mighty battle axe into "TQN"!\n", ({ ENV }));
      break;
      return 7; 
    }
  }

  if(sp2 <= 7)      /*   Big special   */
  {
    tell_room(environment(target),
      "\n"+ENV->QN+" swings "TPP" battle axe over "TPP" head and down...\n"+
      "It bites into "TQN"'s chest with a horrible...\n"+
      "\n\n\t"+RED+" <  < <   C R U N C H   > >  >"+NORM+"\n\n\n"+
      ""TQN" staggers backwards, blood pouring onto the ground....\n\n",
      ({ ENV }));
    tell_object(environment(),
      "\nYou swing your battle axe over your head and down...\n"+
      "It bites into "TQN"'s chest with a horrible...\n"+
      "\n\n\t"+RED+" <  < <   C R U N C H   > >  >"+NORM+"\n\n\n"+
      ""TQN" staggers backwards, blood pouring onto the ground....\n\n");
    target->hit_player(5 + random(10), "other|noblockme");
    return 8; 
  }
}

