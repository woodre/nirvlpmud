shield_bonus(){
	int abonus;
	int bbonus;
	int cbonus;
	int dbonus;
	int total;
	int dod2;
	int parryb;
	int dwcheck;
	string m1;
	string m2;
	string m3;
	abonus = 0;
	bbonus = 0;
	cbonus = 0;
	dbonus = 0;
	
	if(set_light(0) > 0 || skills[70]){
		if(skills[32] && offhand){
			if(random(100) < skills[32]*12){
				switch(random(skills[32] * 15) + 1 + random(skills[6] * 2)){
               case 141..1000:
               abonus += random(8) + 4;
               break;
               case 95..140:
					abonus += random(6) + 3;
              	break;
					case 85..94:
					abonus += random(4) + 3;
					break;
					case 70..84:
					abonus += random(3) + 2;
					break;
					case 1..69:
					abonus += random(2) + 1;
					break;
					default:
					abonus = 0;
					break;
				}
				if(abonus){
					switch(abonus){
						case 12..1000: m1 = " Godlike"; break;
						case 7..11: m1 = " Perfect"; break;
						case 4..6: m1 = "n excellent"; break;
						case 2..3: m1 = " good"; break;
                  case 1: m1 = " decent"; break;
						default: m1 = " decent"; break;
					}
					skill_tier[32] += 1;
					
					tell_object(USER, HIW+"["+HIR+"Offhand Parry"+HIW+"] "+NORM+""+
					"You make a"+m1+" offhanded parry with your "+offhand_name+".\n");
				}
			}
		}
		
		if(skills[31] && USER->query_weapon()){
			if(random(100) < skills[31]*12){
				skill_tier[31] += 1;
				
				if (blunt_check(USER->query_weapon())) parryb = skills[1];
				else if(edged_check(USER->query_weapon())) parryb = skills[2];
				else if(polearm_check(USER->query_weapon())) parryb = skills[3];
				else if(exotic_check(USER->query_weapon())) parryb = skills[5];
				else if(small_check(USER->query_weapon())) parryb = skills[6];
				
				switch(random(skills[31] * 15) + 1 + random(parryb * 2)){
					case 95..1000:
					bbonus += random(6);
					break;
					case 85..94:
					bbonus += random(5);
					break;
					case 70..84:
					bbonus += random(4);
					break;
					case 50..69:
					bbonus += random(3);
					break;
					case 1..49:
					bbonus += random(2);
					break;
					default:
					bbonus = 0;
					break;
				}
				if(bbonus){
					switch(bbonus){
						case 5:
						tell_object(USER,
							HIR+"("+HIW+"Parry"+HIR+")"+NORM+" You quickly lash out with your "+WEPN+"...\n"+
						"        The air is filled with a loud clash as you make a perfect parry!\n");
						break;
						case 4:
						tell_object(USER,
							HIR+"("+HIW+"Parry"+HIR+")"+NORM+" You lower slightly and bring your "+WEPN+" up...\n"+
						"        There is a loud clang as you partially deflect most of the attack!\n");
						break;
						case 3:
						tell_object(USER,
							HIR+"("+HIW+"Parry"+HIR+")"+NORM+" You turn to meet the attack with your "+WEPN+" up...\n"+
						"        You manage to turn the attack slightly.\n");
						break;
						case 2:
						tell_object(USER,
							HIR+"("+HIW+"Parry"+HIR+")"+NORM+" Your "+WEPN+" darts out to parry...\n"+
						"        The force of the attack is lessened.\n");
						break;
						case 1:
						tell_object(USER,
							HIR+"("+HIW+"Parry"+HIR+")"+NORM+" You quickly attempt to parry with your "+WEPN+"...\n"+
						"        Your "+WEPN+" barely turns the attack of your enemy.\n");
						break;
						default:
						tell_object(USER,
							HIR+"("+HIW+"Parry"+HIR+")"+NORM+" You quickly attempt to parry with your "+WEPN+"...\n"+
						"        Your "+WEPN+" barely turns the attack of your enemy.\n");
						break;
					}
				}
			}
		}
		
		
		if(skills[33] && shield_check()){
			if(random(100) < skills[33]*12){
				skill_tier[33] += 1;
				
				switch(random(skills[33] * 15) + 1){
					case 141..10000:
					cbonus += random(6) + 4;
					break;
					case 121..140:
					cbonus += random(5) + 4;
					break;
					case 106..120:
					cbonus += random(4) + 3;
					break;
					case 95..105:
					cbonus += random(3) + 3;
					break;
					case 85..94:
					cbonus += random(3) + 2;
					break;
					case 70..84:
					cbonus += random(3) + 1;
					break;
					case 25..69:
					cbonus += random(2) + 1;
					break;
					case 1..24:
					cbonus += 1;
					break;
					default:
					cbonus = 0;
					break;
				}
				if(cbonus){
					switch(cbonus){
						case 15..1000:
						m2 = " Perfect";
						break;
						case 8..14:
						m2 = "n excellent";
						break;
						case 2..7:
						m2 = " good";
						break;
						case 1:
						m2 = " decent";
						break;
						default:
						m2 = " poor";
						break;
					}
					tell_object(USER,
					HIW+"[ "+NORM+BOLD+"Shield Block"+HIW+" ]"+NORM+" You make a"+m2+" block with your shield.\n");
				}
			}
		}
		if(skills[30]){
			if(skills[30] > 5){
				dod2 = skills[30] - 5;
				if(USER->query_local_weight() < 25 &&
					random(1750) < (dod2 * 18) - USER->query_local_weight()){
					skill_tier[30] += 30;
					tell_object(USER,
						"\n\n     "+HIW+"-   [  "+HIR+"D"+HIW+" - "+HIR+"O "+HIW+"- "+HIR+""+
					"D "+HIW+"-  "+HIR+"G "+HIW+"- "+HIR+"E"+HIW+"  ]  -"+NORM+"\n\n");
					dbonus += 10000;
				}
				else if(random(1750) < 90 - USER->query_local_weight()){
					skill_tier[30] += 30;
					tell_object(USER,
						"\n\n     "+HIW+"-   [  "+HIR+"D"+HIW+" - "+HIR+"O "+HIW+"- "+HIR+""+
					"D "+HIW+"-  "+HIR+"G "+HIW+"- "+HIR+"E"+HIW+"  ]  -"+NORM+"\n\n");
					dbonus += 10000;
				}
			}
			else{
				if(random(1750) < (skills[30] * 18) - USER->query_local_weight()){
					skill_tier[30] += 30;
					tell_object(USER,
						"\n\n     "+HIW+"-   [  "+HIR+"D"+HIW+" - "+HIR+"O "+HIW+"- "+HIR+""+
					"D "+HIW+"-  "+HIR+"G "+HIW+"- "+HIR+"E"+HIW+"  ]  -"+NORM+"\n\n");
					dbonus += 10000;
				}
			}
		}
  if(monk && random(100) < USER->query_attrib("ste")){
      dbonus += USER->query_attrib("ste") / 5;
      }    
		total = abonus + bbonus + cbonus + dbonus;
		return total;
	}
	return 0;
}
