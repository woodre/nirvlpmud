/******* Cone attack: Splits damage between attacker and alt attacker ****/
cone_att() {
object target;
int damage, damage2; 
string sm1, sm2, sm3, sm4;
string msg, msg2, msg3;
int plvl;
string place;

  if(USER->query_ghost()) return 0;
  if(USER->query_spell_dam()) return 1;
  if(!AT){
    write("You can only use this while in combat!\n");
    return 1;
  }
  plvl = TPGO->query_plevel();
  if(USER->query_sp() < plvl + 10){
    write("Your magical energies are too weak for that.\n");
    return 1;
  }
  damage = random(plvl); 
  damage2 = random(plvl);
  sm1 = query_dam1_msg(damage);
  sm3 = query_dam1_msg(damage2);
  sm2 = query_dam2_msg("c");
  sm4 = query_dam2_msg("c");
  place = TPGO->query_location();
  write(BOLD+"You invoke the power of the sigil on your "+place+"..."+NORM+"\n\n");
  write(QMI("cone1")+"\n");
  tell_room(environment(USER),
     USER->query_name()+"'s "+place+" begins to "+QMI("color")+"glow"+NORM+"...\n"+
     QMI("cone2")+USER->query_name()+"!\n", ({USER}));
  write("You "+sm1+" "+AT->query_name()+" with a "+sm2+".\n");
  if(AAT && AAT != AT)
    write("You "+sm3+" "+AAT->query_name()+" with a "+sm4+".\n");
  tell_room(environment(USER),
     USER->query_name()+" "+sm1+" "+AT->query_name()+" with a "+sm2+".\n", ({USER}));
  if(AAT && AAT != AT)
    tell_room(environment(USER),
       USER->query_name()+" "+sm2+" "+AAT->query_name()+" with a "+sm4+".\n", ({USER}));
  if(AAT && AAT != AT)
    AAT->hit_player(damage2);
  msg = "";
  msg2 = "";
  msg3 = "";
  if(AT)
    USER->spell_object(AT, QMI("cname"), damage, (plvl + 10), msg, msg2, msg3);
  return 1;
}
