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
  set_name("glove");
  set_alias("elemental glove");
  set_short(HIY+HBBLU+"Glove of Elemental Fury"+NORM);
  set_long("  CONFIDENTIAL\n");
  set_hit_func(this_object());
  set_type("knife");  
  set_class(5);
  set_params("other|fire",10,0);
  set_params("other|water",10,0);
  set_params("other|ice",10,0);
  set_params("other|electric",10,0);
  set_params("other|earth",10,0);
  set_params("other|wind",10,0);
  set_weight(1);
  set_value(2000);
  set_no_break(1);
  add_special_fun("/players/sparrow/closed/powers/speed.c");
  add_special_fun("/players/sparrow/closed/powers/life.c");
  add_special_fun("/players/sparrow/closed/powers/cleansing.c");
  add_special_fun("/players/sparrow/closed/powers/disease.c");
  add_special_fun("/players/sparrow/closed/powers/mana.c");
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
  if(lev < 10) {
    return 0;
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
  if(!random(4)) {
    int x,y;
    y = 0;
    x = random(3) + 1;
    while(x >= y) {
    switch(random(6)) {
      case 0:
        tell_room(environment(me),
        me->query_name()+" points the Glove of Elemental Fury at "+att->query_name()+".\n"+
        "Shards of "+HIC+"razor sharp ice"+NORM+" strike "+att->query_name()+" from all angles!\n");
        att->do_damage(({(random(5)+5)}), ({"other|ice"}));
      break;
      case 1:
        tell_room(environment(me),
        me->query_name()+" swings the Glove of Elemental Fury above his head.\n"+
        "A "+HIB+"blade of water"+NORM+" slashes "+att->query_name()+" across the chest!\n");      
        att->do_damage(({(random(5)+5)}), ({"other|water"}));
      break;
      case 2:
        tell_room(environment(me),
        me->query_name()+" thrusts the Glove of Elemental Fury straight up into the air.\n"+
        "A "+HIR+"column of fire"+NORM+" decends upon "+att->query_name()+" from the heavens!\n");
        att->do_damage(({(random(5)+5)}), ({"other|fire"}));
      break;
      case 3:
        tell_room(environment(me),
        me->query_name()+" points the Glove of Elemental Fury at "+att->query_name()+".\n"+
        "A "+HIY+"ball of lightning"+NORM+" strikes "+att->query_name()+" with a loud CRACK!\n");
        att->do_damage(({(random(5)+5)}), ({"other|electric"}));
      break;
      case 4:
        tell_room(environment(me),
        me->query_name()+" waves the Glove of Elemental Fury at "+att->query_name()+".\n"+
        att->query_name()+" is blown backward by a strong "+HIW+"gust of wind"+NORM+"!\n");
        att->do_damage(({(random(5)+5)}), ({"other|wind"}));
      break;
      case 5:
        tell_room(environment(me),
        me->query_name()+" drives the Glove of Elemental Fury into the ground.\n"+
        HIK+"Several large stones"+NORM+" strike "+att->query_name()+" from all angles!\n");
        att->do_damage(({(random(5)+5)}), ({"other|earth"}));
      break;
    }
    y++;
  }
  }
  return 0;
}

     
get(){ 
if(this_player())
if(this_player()->query_real_name() != "wulfgar" && TP->query_level() < 20){
write("You are unable to grasp such a powerful artifact!\n");
return 0;
}
return 1;
}

