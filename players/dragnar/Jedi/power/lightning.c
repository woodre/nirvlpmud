#include <ansi.h>
#include "defs.h"

#define COST 0

inherit CMDBASE;

main(string str) {
  object lightning, ob;
  int damage;
  string mess;

  skill_type = "telepathy";
  if(skill_check(9)) return 1;
  if(delay_check()) return 1;
  if( cp_check( COST ) ) return 1;
  ob = start_attack(str);
  if( !ob ) return 1;
  if( cp_check( COST ) ) return 1;

  if (USER->test_dark())  return 1;

  if(!PO->query_darkside()) PO->adj_goodness_pool(-random(5));

  if(ob->query_ac() > 9){
    tell_object(ob,
    "Your armor glows brightly as the lightning dances across its surface. You feel extreme pain!\n");
  }
  tell_room(environment(USER),
    "Lightning leaps from "+USER->query_name()+"'s fingertips!\n",({USER}));
  damage = SKILL + random(30);
  switch(damage) {
    case 32..100:
      mess = ""+YEL+"\n"+
      "                            ___ _ _\n"+
      "                        ______________ _ _ \n"+
      "                   ______________ ___ ___ _________\n"+
      "                       _______ ___________ _ _ \n"+
      "                          ______________ _\n"+
      "                            _  ___ _"+NORM+"\n";
      tell_object(USER,
      "You put "+ob->query_name()+" into extreme agony as Lightning leaps from\n"+
      "your fingertip's and strikes them!\n");
      tell_object(ob,
      "You feel extreme agony as Lightning leaps from "+USER->query_name()+"'s fingertips!\n");
    break;
    case 22..31:
      mess = ""+YEL+"\n\n"+
      "                             ___ _ \n"+
      "                        __________ _ _ ___\n"+
      "                   _________ ______ ________ _\n"+
      "                       ________ _____ _\n"+
      "                              _ ___ _"+NORM+"\n";
      tell_object(USER,
      "You send "+ob->query_name()+"'s body into spasm's as lightning from your fingertips\n"+
      "washes over them!\n");
      tell_object(ob,
      "Your body is sent into spasm's as lightning from "+USER->query_name()+" washes over you!\n");
      break;
    case 16..21:
      mess = ""+YEL+"\n\n\n"+
             "                             _____ _ _\n"+
             "                         _________ __ ____ __\n"+
             "                         _ ______ _________ _\n"+
             "                            ___ _ ___ _"+NORM+"\n";
      tell_object(USER,
      "Tendrils of electricity strike out at "+ob->query_name()+"!\n");
      tell_object(ob,
      "You feel pain as tendrils of electricity strike you!\n");
      break;
    case 9..15:
      mess = ""+YEL+"\n\n\n"+
             "                            ____ __\n"+
             "                          _______ __ _ _\n"+
             "                            ___ __ _ "+NORM+"\n";
      tell_object(USER,
      "Lightning lashes out from your fingertips, hitting "+ob->query_name()+"!\n");
      tell_object(ob,
      "Lightning lashes out at you from "+USER->query_name()+"'s fingertips, hitting you!\n");
      break;
    default:
      mess = ""+YEL+"\n\n\n"+
             "                            __ __ ____\n"+
             "                           ___ _  __ ___ _ "+NORM+"\n";
      tell_object(USER,
      "A small stream of lightning leaps from your fingertips, grazing "+ob->query_name()+"!\n");
      tell_object(ob,
      "A small stream of lightning leaps from "+USER->query_name()+"'s fingertips, grazing you!\n");
      break;
  }
  tell_object(USER, mess);
  tell_object(ob, mess);
  tell_object(USER, "\t\t\t\tDamage: "+damage+".\n");
  previous_object()->adj_cp(-COST);
  previous_object()->set_force_delay(8);
  this_player()->spell_object(ob, "lightning", damage, 0, "");
  if(!ob->is_lightning()){
    lightning = clone_object("/players/dragnar/Jedi/obj/lightning.c");
    lightning->set_victim(ob);
    lightning->set_time(random(SKILL)+5);
  }
  return 1;
} 
