#include <ansi.h>

status main(string str) {
  object target;
  object victim;  
  string tname;
  string bash_mess1;
  string bash_mess2;  
  int Dam1, str_bonus;
    str_bonus = (int)present("dknight_ob",this_player())->query_combat(); 
/*  str_bonus = present("dknight_ob",this_player())->query_combat();

*/

  if (this_player()->query_guild_rank() < 3) {
    write("You are not high enough level to do that.\n");
    return 1;
  }
  if(this_player()->query_spell_dam()) return 1;
  if (this_player()->query_sp() < (10 + str_bonus)) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  if (!str && !this_player()->query_attack()) {
    write(""+HIR+"Corrupt"+NORM+" who???\n");
    return 1;
  }
  if (this_player()->query_attack())
    target = (object)this_player()->query_attack();
  else
    target = present(str, environment(this_player()));
  if (!target) {
    write(""+HIR+"Corrupt"+NORM+" who???\n");
    return 1;
  }
  if (!this_player()->query_attack()) this_player()->attack_object(target);
  if (target) {
    /* Evaluate name here, in case it gets killed before the messages
       get generated 
    str_bonus = (int)present("dknight_ob",this_player())->query_combat(); */
    Dam1 = 4 + str_bonus + (random(str_bonus)+ random(5));	
        victim = (object)this_player()->query_attack();
    tname = (string)target->query_name();
    target->do_damage(({Dam1}), ({"magic"}));
	this_player()->set_spell_dam(1);
  }    
  else
    return 0;
switch(Dam1){
 case 25..500:
bash_mess1 = HIK+"T E N D R I L S"+NORM+" of "+RED+"corruption impale"+NORM+" "+tname+" with tremendous force.\n"+tname+" screams out in Pain.\n";
bash_mess2 = HIK+"T E N D R I L S"+NORM+" of "+RED+"corruption impale "+NORM+""+tname+" with tremendous force.\n"+tname+" screams out in Pain.\n";
break;
case 17..24:
bash_mess1 = tname+" stumbles about as "+HIK+"T E N D R I L S"+NORM+" dig into "+tname+"'s SOUL.\n"+HIR+"B L O O D"+NORM+" trickles from "+tname+"'s mouth.\n";
bash_mess2 = tname+" stumbles about as "+HIK+"T E N D R I L S"+NORM+" dig into "+tname+"'s SOUL.\n"+HIR+"B L O O D"+NORM+" trickles from "+tname+"'s mouth.\n";
break;
case 10..16:
bash_mess1 = "Corruption "+NORM+RED+"tears"+NORM+" into "+tname+"'s flesh with intensity.\n"+tname+" stumbles from the blow.\n";
bash_mess2 = "Corruption "+NORM+RED+"tears"+NORM+" into "+tname+"'s flesh with intensity.\n"+tname+" stumbles from the blow.\n";
break;
case 5..9:
bash_mess1 = "Tendrils cause "+tname+" some pain.\n";
bash_mess2 = "Tendrils cause "+tname+" some pain.\n";
break;
case 1..4: 
bash_mess1 = "You lightly corrupt "+tname+"'s soul with a weak attack.\n";
bash_mess2 = this_player()->query_name()+" lightly corrupt "+tname+"'s soul with a weak attack.\n";
break;
default:
bash_mess1 = "You clumsily miss "+tname+" with a weak attempt of corruption\n";
bash_mess2 = this_player()->query_name()+" clumsily misses "+tname+" with a weak attempt of corruption.\n";
break;
}

  this_player()->add_spell_point(-(10 + str_bonus));
  write(bash_mess1);
  say(bash_mess2);
  return 1;
}
