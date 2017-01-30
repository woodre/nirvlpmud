#include <ansi.h>
#define USER environment()
#define TP this_player()
#define POS query_possessive()
#define OBJ query_objective()
#define PRO query_pronoun()
inherit "players/maledicta/weapon/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;
set_name("broadsword");
set_alias("broadsword of balance");
set_short(HIW+"T"+HIK+"he "+HIW+"B"+HIK+"roadsword of "+HIW+"B"+HIK+"alance"+NORM);
set_long(
"  This is the famed Broadsword of Balance. It is made of some unknown\n"+
"magical material and looks quite deadly. There are some inscriptions\n"+
"along the blade.  This broadsword was made especially for the mortal\n"+
"Wulfgar.\n");
set_hit_func(this_object());
set_type("sword");  
set_class(20);
set_weight(1);
set_value(2000);
set_two_handed_wep(1);
set_no_break(1);
add_special_fun("/players/sparrow/closed/powers/speed.c");
add_special_fun("/players/sparrow/closed/powers/life.c");
add_special_fun("/players/sparrow/closed/powers/cleansing.c");
add_special_fun("/players/sparrow/closed/powers/disease.c");
add_special_fun("/players/sparrow/closed/powers/mana.c");
add_special_fun("/players/sparrow/closed/powers/evil.c");
 
message_hit = ({
  HIR+"hacked"+NORM," into a bloody, squirming mess on the floor",
  RED+"sliced"+NORM, " with a critical strike",
  RED+"diced"+NORM, " into tiny, pathetic little pieces",
  HIW+"pierced"+NORM, " deeply, causing great pain",
  HIW+"chopped"+NORM, " with a mad surgeon's grace",
  "slapped", " viciously with the flat of the blade",
  "cut", " lightly across the chest"
  });
  }


weapon_hit(ob){
int lev, xlev, hp, sp, mhp, msp, num, dam1, combo;
  string loc, severity, action;
  object me, att, ATT, corpse;
  me = USER;
  lev = me->query_level();
  xlev = me->query_extra_level();
  hp = me->query_hp();
  sp = me->query_sp();
  mhp = me->query_mhp();
  msp = me->query_msp();
  att = ob;
  if(this_object()->query_class() == 20 && environment(me)->query_light() < 1) {
    this_object()->set_class(25);
  }
  if(this_object()->query_class() == 24 && environment(me)->query_light() > 0) {
    this_object()->set_class(20);
  }
  if(lev < 10) {
    return 0;
  }
  if(!present("head", environment(me))){
  if(me->query_attack() && att->query_hp() < 50){
    if((att->query_hp()*10)/(att->query_mhp()) < 1 && att->is_npc()){
      
      tell_room(environment(me),
      
        me->query_name()+" screams in delight as the broadsword quivers...\n\n"+
        HIK+"    "+HBRED+"------ - -- --- C U T --- -  ------ ------"+NORM+"\n\n"+
        "      "+att->query_name()+"'s head rolls to the ground.\n");
      
        corpse = clone_object("obj/treasure");
        corpse->set_id("head");
        corpse->set_short("the head of "+att->query_name()+"");
        corpse->set_long("This is the head of "+att->query_name()+". It was chopped off\n"+
                     "by "+me->query_name()+"'s Broadsword of Balance.\n");
        corpse->set_weight(1);
        corpse->set_value(1000);
        corpse->set_save_flag(1);
        move_object(corpse, environment(me));
      
        att->do_damage(({(att->query_hp())+20}), ({"other|evil"}));
        return 50;
      }
    }
  }
  if(!random(3)) {  /* 30% chance of balance */
    if(hp > (sp + 2) && !(hp > msp)) {
      num = hp - sp;
      num = num / 2;
      me->add_hit_point(-num);
      me->add_spell_point(num);
      tell_object(environment(this_object()),  
      HIW+"["+HIB+"="+HIW+"]"+NORM+BLUE+" You feel the power of "+HIK+"DARK BALANCE"+NORM+BLUE+"!\n"+NORM);
    }
    if(sp > (hp + 2) && !(sp > mhp)) {
      num = sp - hp;
      num = num / 2;
      me->add_hit_point(num);
      me->add_spell_point(-num);
      tell_object(environment(this_object()),  
      HIW+"["+HIM+"="+HIW+"]"+NORM+MAG+" You feel the power of "+HIK+"DARK BALANCE"+NORM+MAG+"!\n"+NORM); 
    }
  }
  if(random(100) > 25){
    combo = random(5);
    while(combo > 0) {
      switch(random(10) + 1){
        case 10:   
          loc = "head";  
          dam1 = random(10) +1;  
          break; 
        case 7..9: 
          loc = "chest"; 
          dam1 = random(7) +1;   
          break; 
        case 4..6: 
          loc = "arm";   
          dam1 = random(7) + 1;   
          break; 
        case 2..3: 
          loc = "leg";   
          dam1 = random(7) + 1;   
          break; 
        case 1:
          loc = "groin";
          dam1 = random(7) + 1;   
          break;           
        default:   
          loc = "head";  
          dam1 = random(10) + 1;   
      }
      switch(random(10)) {
        case 9:
          severity = HBRED+"SLAUGHTERS"+NORM;
          dam1 = dam1 + 4;
          break;
        case 6..8:
          severity = HIR+"MAIMS"+NORM;
          dam1 = dam1 + 4;
          break;
        case 5:
          severity = YEL+HBBLU+"MUTiLATES"+NORM;
          dam1 = dam1 + 4;
          break;
        case 3..4:
          severity = RED+"destroys"+NORM;
          dam1 = dam1 + 4;
          break;
        case 2:
          severity = RED+"pummels"+NORM;
          dam1 = dam1 + 4;
          break;
        default:
          severity = "punishes";
      }
      switch(random(7)) {
        case 0:
          action = "with a viscious stab to the";
          break;
        case 1:
          action = "with a clean slash to the";
          break;
        case 2:
          action = "with a deadly strike to the";
          break;
        case 3:
          action = "with a suprise strike to the";
          break;
        case 4:
          action = "with a brutal combination to the";
          break;
        case 5:
          action = "with a series of slashes to the";
          break;
        default:
          action = "with a focused attack to the";
      }
      tell_room(environment(USER),
      capitalize(USER->query_name())+" "+severity+" "+att->query_name()+" "+action+" "+loc+"!\n");
      if(dam1 > att->query_hp()) {
        dam1 = att->query_hp() - 1;
      }
      att->do_damage(({dam1}), ({"physical"}));
      combo = combo -1;
    }
  }
   
return 0;
}

     
get(){ 
  if(this_player()) {
    if(this_player()->query_real_name() != "wulfgar" && TP->query_level() < 20){
      write("You are unable to grasp such a powerful artifact!\n");
      return 0;
    }
    return 1;
  }
}

