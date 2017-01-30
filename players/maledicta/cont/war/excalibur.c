/*  This is a one time weapon that can be gained by killing the
    goblin king.  Its tough, but hey...11,000 goblins need to
    be killed and then the king. */

#include "/players/maledicta/ansi.h"

inherit "players/maledicta/weapon/weapon.c";
#define USER environment()
#define TP this_player()
#define POS query_possessive()
#define OBJ query_objective()
#define PRO query_pronoun()

reset(arg){
  ::reset(arg);
  if (arg) return;
set_name("excalibur");
set_short(BLU+"Exca"+HIB+"lib"+NORM+BOLD+"ur"+NORM);
set_hit_func(this_object());
set_type("sword");  
set_class(19);
set_weight(2);
set_value(200000);
set_no_break(1);
set_two_handed_wep(1);
}


long(){ 
write(
"  This is the legendary sword Excalibur. Legend says it was\n"+
"forged during the Age of Dreams in a far away land. Its\n"+
"blade is a shimmering mithril steel, wavering and with an\n"+
"undiminished power from the ancient times. Excalibur has\n"+
"always served the cause of good, and cannot be used in an\n"+
"evil way. The weapon has the ability to release the spirits\n"+
"from a corpse by '"+HIW+"dissolve"+NORM+"'ing them.\n"+
"This is a one or two handed weapon. 'wield <wep> with both hands'\n"+
"This weapon cannot be broken.\n");
return 1;
}


query_hits(){ return 0; }

init(){
  ::init();
  add_action("decorpse", "dissolve");
  }

decorpse(str){
        object corpse;
        int cvalue;
        string extra;
        
        if(USER->query_ghost()) return 0;
        
        corpse = present("corpse", environment(USER));
        
        if(!corpse){
          write("There is no corpse.\n");
          return 1;
          }
        if(corpse->query_corpse_level() < 1){
          write("You cannot dissolve that, it is useless.\n");
          return 1;
          }
        
        if(sscanf(file_name(corpse),"obj/corpse%s",extra)!=1) return 1;
        
   tell_room(environment(USER),
   HIW+USER->query_name()+" slides "+USER->query_possessive()+" sword into a corpse...\n"+
   HIW+"A fine "+HIB+"Blue Mist"+HIW+" rises from the corpse and into the air."+NORM+"\n");
   tell_object(USER, HIB+"You are healed as the soul passes through you"+HIW+"..."+NORM+"\n");    
        cvalue = corpse->query_corpse_level() * 2;
        USER->add_hit_point(cvalue);
        destruct(corpse);
        return 1;
        }
query_save_flag(){ return 0; }

weapon_hit(attacker){

  if(USER->query_alignment() < -40){ 
  tell_object(USER,
  BLU+"Exca"+HIB+"lib"+NORM+BOLD+"ur"+NORM+HIW+" stops shimmering..."+NORM+"\n"); 
  return -20;
  }

  if(attacker->query_alignment() > 40){ 
  tell_object(USER,
  BLU+"Exca"+HIB+"lib"+NORM+BOLD+"ur"+NORM+HIW+" stops shimmering..."+NORM+"\n"); 
  return -20;
  }

  if(undead_check(attacker) && random(100) < 40){
  tell_object(USER,
  "As "+BLU+"Exca"+HIB+"lib"+NORM+BOLD+"ur"+NORM+HIW+" touches the unholy flesh of "+attacker->query_name()+""+
  " there is a flash of "+NORM+BOLD+"< "+HIY+"Light"+NORM+BOLD+" >"+NORM+"\n"+
  HIW+"Dead flesh peels and pops as it burns!!!"+NORM+"\n");
  attacker->heal_self(-(random(6) + 5));
  return 5;
  }

  if(attacker->query_alignment() < -500 && random(100) < 50){
  tell_object(USER,
  BLU+"Exca"+HIB+"lib"+NORM+BOLD+"ur"+NORM+" hums with might as it cuts easily through "+attacker->query_name()+"!\n");
  return 7;
  }

  if(random(100) < 10){
  USER->heal_self(5 + random(4));
  tell_object(USER,
  BLU+"Exca"+HIB+"lib"+NORM+BOLD+"ur"+NORM+HIW+" heals you..."+NORM+"\n"); 
  }
  return 0;
}
 

undead_check(ob){
if(call_other(ob,"id", "undead") || call_other(ob, "id", "skeleton") ||
   call_other(ob, "id", "spirit") || call_other(ob, "id", "wraith") ||
   call_other(ob, "id", "dracula") || call_other(ob, "id", "vampire") ||
   call_other(ob, "id", "zombie") || call_other(ob, "id", "banshee") ||
   call_other(ob, "id", "ghost") || call_other(ob, "id", "revenant") ||
   call_other(ob, "id", "mummy") || call_other(ob, "id", "dracolich") ||
   call_other(ob, "id", "lich") || call_other(ob, "id", "ghoul") ||
   call_other(ob, "id", "frankenstein") || call_other(ob, "id", "corpse"))
   return 1;
else return 0;
}    
