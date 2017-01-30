get_weapon() {
  object wep;
  wep = clone_object("/players/hogath/area/items/beast/psiblade");
  move_object(wep,this_object());
  command("wield blade",this_object());
}

get_shield() {
  object armor;
  armor = clone_object("/players/hogath/area/items/beast/psishield");
  move_object(armor,this_object());
  command("wear shield",this_object());
}

cast_fire()  {
  say(tpn+" intones xar kun nop\n\n"+
        BLINK+HIR+"\tF L A M E S"+NORM+" burn you!.\n\n");
  write(tpn+" intones xar kun nop\n\n"+
       BLINK+HIR+"\tF L A M E S"+NORM+" envelop the room!.\n\n");
  at->hit_player((10+random(50)),"other|fire");
    
             }

cast_ice()   {
  say(tpn+" intones kun nep sal\n\n"+
        BLINK+HIC+"\tI C E  S H A R D S"+NORM+" stab you!\n\n");
  write(tpn+" intones kun nep sal\n\n"+
      BLINK+HIC+"\tI C E  S H A R D S"+NORM+" pummel "+atn+".\n\n");
  at->hit_player((10+random(50)),"other|ice");
    
            }

mind_blast() {
  write(tpn+" concentrates briefly\n\n"+
        BLINK+WHT+BBLU+"M E N T A L  F O R C E"+NORM+"slams into you.\n\n");
  say(tpn+" concentrates briefly\n\n"+
      BLINK+WHT+BBLU+"M E N T A L  F O R C E"+NORM+" "+atn+" staggers under the strain\n\n");
  at->hit_player((10+random(50)),"other|mental");
  
           }
multi_hit() {
  write(tpn+" "+HIR+"B "+HIB+"L "+HIC+"U "+HIW+"R "+HIM+"S "+NORM+" with demonic speed\n");
  say(tpn+" "+HIR+"B "+HIB+"L "+HIC+"U "+HIW+"R "+HIM+"S "+NORM+" with demonic speed\n");
  already_fight=0;
      attack();
  already_fight=0;
      attack();
  already_fight=0;
      attack();
            }
cast_heal() {
  write(tpn+" focuses mental energy and is "+WHT+"healed"+NORM+"!\n");
  say(tpn+" focuses metal energy and is "+WHT+"healed"+NORM+"!\n");
  heal_self(50);
  
            }
cast_regen() {
  write(tpn+" "+BOLD+"glows"+NORM+" slightly as his wounds heal faster\n");
  say(tpn+" "+BOLD+"glows"+NORM+" slightly as his wounds heal faster\n");
  heal_self(25);
  set_heal(1,10);
             }
all_out() {
  write(tpn+" puts all his fury into a vicious attack!\n");
  say(tpn+" slams "+atn+" with a vicious blow!\n");
  at->hit_player(75);
  already_fight=0;
      attack();
  already_fight=0;
      attack();
}

