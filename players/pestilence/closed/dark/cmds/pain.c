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

 if(this_player()->query_guild_rank() < 1){ write("You can't use this spell yet.\n"); return 1; }
  if(this_player()->query_spell_dam()) return 1;
  if (this_player()->query_sp() < (10 + str_bonus)) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  if (!str && !this_player()->query_attack()) {
    write(""+HIK+"Pain"+NORM+" who???\n");
    return 1;
  }
  if (this_player()->query_attack())
    target = (object)this_player()->query_attack();
  else
    target = present(str, environment(this_player()));
  if (!target) {
    write(""+HIK+"Pain"+NORM+" who???\n");
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
    target->do_damage(({Dam1}), ({"other|physical"}));
	this_player()->set_spell_dam(1);
  }    
  else
    return 0;
switch(Dam1){
case 23..400:
bash_mess1 = "You unleash an "+HIW+"INTENSE"+NORM+" amount of "+HIK+"P A I N"+NORM+" into "+tname+"'s body.\n"+tname+" crumbles under the immense "+HIK+"P A I N\n"+NORM;
bash_mess2 = this_player()->query_name()+" unleashes an "+HIW+"intense"+NORM+" amount of "+HIK+"P A I N"+NORM+" into "+tname+"'s body.\n"+tname+" crumbles under the immense "+HIK+"P A I N\n"+NORM;
break;
case 17..22:
bash_mess1 = "You unleash a "+HIR+"GREAT"+NORM+" amount of "+HIK+"P A I N"+NORM+" into "+tname+"'s body.\n"+tname+" crumbles under the "+HIK+"P A I N\n"+NORM;
bash_mess2 = this_player()->query_name()+" unleashes a "+HIR+"GREAT"+NORM+" amount of "+HIK+"P A I N"+NORM+" into "+tname+"'s body.\n"+tname+" crumbles under the "+HIK+"P A I N\n"+NORM;
break;
case 12..16:
bash_mess1 = "You unleash a "+HIY+"GOOD"+NORM+" amount of "+HIK+"P A I N"+NORM+" into "+tname+"'s body.\n"+tname+" crumbles under the "+HIK+"P A I N\n"+NORM;
bash_mess2 = this_player()->query_name()+" unleashes a "+HIY+"GOOD"+NORM+" amount of "+HIK+"P A I N"+NORM+" into "+tname+"'s body.\n"+tname+" crumbles under the "+HIK+"P A I N\n"+NORM;
break;
case 5..11:
bash_mess1 = "You unleash a FAIR amount of "+HIK+"P A I N"+NORM+" into "+tname+"'s body.\n"+tname+" tries to shake off the "+HIK+"P A I N\n"+NORM;
bash_mess2 = this_player()->query_name()+" unleashes a FAIR amount of "+HIK+"P A I N"+NORM+" into "+tname+"'s body.\n"+tname+"  tries to shake off the "+HIK+"P A I N\n"+NORM;
break;
case 1..4: 
bash_mess1 = "You unleash "+HIK+"P A I N"+NORM+" into "+tname+"'s body.\n"+tname+" seems to shake off the "+HIK+"P A I N\n"+NORM;
bash_mess2 = this_player()->query_name()+" unleashes "+HIK+"P A I N"+NORM+" into "+tname+"'s body.\n"+tname+" seems to shake off the "+HIK+"P A I N\n"+NORM;
default:
bash_mess1 = "You try to unleash "+HIK+"P A I N"+NORM+" into "+tname+"'s body but seem to miss.\n";
bash_mess2 = this_player()->query_name()+" tries to unleash "+HIK+"P A I N"+NORM+" into "+tname+"'s body but seem to miss.\n";
break;
}

  this_player()->add_spell_point(-(10 + str_bonus));
  write(bash_mess1);
  say(bash_mess2);
  return 1;
}
