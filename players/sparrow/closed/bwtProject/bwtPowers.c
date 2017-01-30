#include <ansi.h>

void
bwtCleansing(object att) { 
  int stu, soa;
  object user;
  user = environment(this_object());
  tell_object(user,
    HIW+"["+HIG+"+"+HIW+"]"+NORM+GREEN+" Your "+HIK+name+NORM+GREEN+
    " siphons power from your digestive system!\n"+NORM);
  stu = user->query_stuffed();
  soa = user->query_soaked();
  if(stu > 5) { 
    user->add_stuffed(-5);
    this_object()->add_bwtPower(5);
  }
  else if(stu > 0) {
    user->add_stuffed(-stu);
    this_object()->add_bwtPower(stu);
  }
  if(soa > 5) {
    user->add_soaked(-5);
    this_object()->add_bwtPower(5);
  }
  else if(soa > 0) {
    user->add_soaked(-soa);
    this_object()->add_bwtPower(soa);
  }
  return;
}

void
bwtDisease(object att) {
  object poison, user, room;
  user = environment(this_object());
  room = environment(user);
  if(random(100) > 20){ 
    return; 
  }  
  if(!present(att, room) {
      return;
  }
  if(!present("poison", att)){
    tell_object(att, RED+"You begin to feel feverish!\n"+NORM);
    tell_object(user, 
      HIW+"["+HIY+"-"+HIW+"]"+NORM+YEL+" Your "+HIK+name+NORM+YEL+" infuses "+HBRED+
      "pestilence"+NORM+YEL+" into the body of "+ATT->query_name()+"!"+NORM+"\n");
    poison = clone_object("/players/sparrow/closed/bwtProject/obj/poison.c");
    poison->set_duration(random(5) + 1);
    poison->set_damage(random(6) + 5);    
    move_object(poison, att);
  }
return;
}

void
bwtCorrupt(object att) { 
  object user;
  user = environment(this_object());
  if(random(100) > 20) { 
    return;
  }
  if(this_object()->query_bwtPower() > this_object()->query_bwtLevel()*5) {
    return;
  }
  tell_object(user, 
    HIK+"["+HIR+"E"+HIK+"]"+NORM+RED+" Your "+HIK+name+NORM+RED+" fills you with "+
    HIK+HBRED+"HATRED"+NORM+RED+" of "+att->query_name()+"!"+NORM+"\n");
  user->add_alignment(-20*this_object()->query_bwtLevel());
  return;
}

void
bwtLife(object att) { 
  object user;
  user = environment(this_object());
  if(random(100) > 20) { 
    return;
  }
  tell_object(user,  
    HIW+"["+HIC+"+"+HIW+"]"+NORM+CYAN+" Your "+HIK+name+NORM+CYAN+
    " infuses you with "+HIK+"DARK HEALING"+NORM+CYAN+"!\n"+NORM);
  user->add_hit_point(random(6) + 5);
  return;
}

void
bwtMana(object att){ 
  object user;
  user = environment(this_object());
  if(random(100) > 20) { 
    return;
  }
  tell_object(user,
    HIW+"["+HIM+"+"+HIW+"]"+NORM+MAG+" Your "+HIK+name+NORM+MAG+" infuses you with "+
    HIK+"DARK MANA"+NORM+MAG+"!\n"+NORM);
  user->add_spell_point(random(6) + 5);
  return;
}

void
bwtSpeed(object att) {
  int dam;
  string message;
  object user;
  user = environment(this_object());
  if(random(100) > 20) { 
    return; 
  }
  if(!present(att, environment(user))) { 
    return; 
  }
  dam = random(10) + 15;
  message = this_object()->query_message_hit(dam);
  tell_room(environment(user),
  HIK+user->query_name()+"'s form "+HBCYN+" B L U R S "+HIK+"!!!!"+NORM+"\n");
  this_object()->set_gen_bonus(dam);
  tell_object(user,"You "+message[1]+" "+att->query_name()+""+message[0]+".\n");
  tell_object(att, user->query_name()+" "+message[1]+" you"+message[0]+".\n");
  tell_room(environment(user), 
    user->query_name()+" "+message[1]+" "+att->query_name()+message[0]+".\n", ({user, att}));
  return;
}

void
bwtDarkBalance(object user) {
  int num, hp, sp, msp, mhp;
  hp = user->query_hp();
  sp = user->query_sp();
  mhp = me->query_mhp();
  msp = me->query_msp();
  if(!random(3)) {
    if(hp > (sp + 2) && !(hp > msp)) {
      num = hp - sp;
      num = num / 2;
      user->add_hit_point(-num);
      user->add_spell_point(num);
      tell_object(user,  
        HIW+"["+HIB+"="+HIW+"]"+NORM+BLUE+" You feel the power of "+HIK+
        "DARK BALANCE"+NORM+BLUE+"!\n"+NORM);
    }
    if(sp > (hp + 2) && !(sp > mhp)) {
      num = sp - hp;
      num = num / 2;
      me->add_hit_point(num);
      me->add_spell_point(-num);
      tell_object(user,  
        HIW+"["+HIM+"="+HIW+"]"+NORM+MAG+" You feel the power of "+HIK+
        "DARK BALANCE"+NORM+MAG+"!\n"+NORM); 
    }
  }
  return;
}

void
bwtComboAttack(object att) {
  string loc, severity, action;
  int dam;
  dam = 0;
if(random(100) > 30){
    switch(random(10) + 1){
      case 10:   
        loc = "head";   
        break; 
      case 6..9: 
        loc = "chest";    
        break; 
      case 3..5: 
        loc = "arm";      
        break; 
      case 1..2: 
        loc = "leg";      
        break; 
      default:   
        loc = "head";  
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
    
    switch(random(10)) {
      case 9:
        severity = HBRED+"SLAUGHTERS"+NORM;
        dam1 = dam1 + 4;
        break;
      case 5..8:
        severity = HIR+"MAIMS"+NORM;
        dam1 = dam1 + 2;
        break;
      case 2..4:
        severity = RED+"destroys"+NORM;
        dam1 = dam1 + 1;
        break;
      default:
        severity = "punishes";
    }
    tell_room(environment(USER),
    capitalize(USER->query_name())+" "+severity+" "+att->query_name()+" "+action+" "+loc+"!\n");
    return dam1;
}

