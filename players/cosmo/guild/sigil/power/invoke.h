/********
 Main attack: equivalent of game spells. Against npc type can get a bonus
 of random(10) damage if willpower > random(500)
*********/
invoke_spell(str) {
object target;
int plvl, damage, rcrit, rcrit2;
string sm1, sm2, msg, msg2, msg3;
string place;
        
  if(USER->query_ghost()) return 0;
  if(USER->query_spell_dam()) return 1;
  if(!str && !AT) {
    write("You are not in combat.\n");
    return 1;
  }
  else if(!str && AT) target = AT;
  else target = present(str, environment(USER));
  if(!target){
    write("You don't see "+str+" here.\n");
    return 1;
  }
  if(!living(target)){
    write("You cannot attack "+str+"!\n");
    return 0;
  }
  plvl = TPGO->query_plevel();
  if(USER->query_sp() < plvl){
    write("Your magical energies are too weak for that.\n");
    return 1;
  }
  if(plvl < 21) damage = random(plvl*2);
  else damage = random(34) + 12;
  sm1 = query_dam1_msg(damage);
  sm2 = query_dam2_msg("i");
  place = TPGO->query_location();
  write("You invoke the power of the sigil on your "+place+"...\n");
  tell_room(environment(USER),
    USER->query_name()+"'s "+place+" begins to glow...\n", ({USER}));
  rcrit = random(500);
  rcrit2 = rcrit;

  /************* Critical hit or miscast **************************/
  if(USER->query_attrib("wil") > rcrit2){
    write("]"+BOLD+"CRITICAL"+NORM+"[ ");
    damage += random(10);
  }
  else if(rcrit2 > (470 + USER->query_attrib("wil"))){
    write("]"+BOLD+"MISCAST"+NORM+"[ ");
    if(damage > 10){
      damage -= random(10);
      sm1 = "grazed";
    }
    else{
      sm1 = "grazed";
      damage = 1;
    }
  }
  /****************************************************************/

  write("You "+sm1+" "+target->query_name()+" with "+sm2+".\n");
  tell_room(environment(USER),
     USER->query_name()+" "+sm1+" "+target->query_name()+" with "+sm2+".\n", ({USER}));
  msg = "";
  msg2 = "";
  msg3 = "";
  USER->spell_object(target, QMI("iname"), damage, plvl, msg, msg2, msg3);
  return 1;
}
