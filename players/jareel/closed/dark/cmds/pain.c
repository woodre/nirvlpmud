#include "/players/pestilence/ansi.h"

main(str)
{
   object victim;
   string b1,b2;
   string bash_mess1;
   string bash_mess2;
   int Dam1, str_bonus;
   str_bonus = present("dknight_ob",this_player())->query_combat();
   Dam1 = (1+ str_bonus)/2 +random(10); 

 
    if(this_player()->query_spell_dam()) return 1;
    if (!str && !this_player()->query_attack()){
        write(""+HIK+"Pain"+NORM+" who???\n");
        return 1; }
if(this_player()->query_guild_rank() < 1){ write("You can't use this spell yet.\n"); return 1; }
   if (str) victim = present(str, environment(this_player()));
     else {
      victim = this_player()->query_attack();
      if(victim && !present(victim, environment(this_player())))
        victim = 0;
     } 
   if(!str && !victim) return 0;
   if(!victim) { write("That is not here.\n"); return 1; }

   if (!living(victim)) {
      write("You cannot attack that!\n");
      say(this_player()->query_name() + " foolishly tries to attack "+ str+"\n");
      return 1;
   }

switch(Dam1){
case 23..400:
bash_mess1 = "You unleash an "+HIW+"INTENSE"+NORM+" amount of "+HIK+"P A I N"+NORM+" into "+victim->query_name()+"'s body.\n"+victim->query_name()+" crumbles under the immense "+HIK+"P A I N\n"+NORM;
bash_mess2 = this_player()->query_name()+" unleashes an "+HIW+"intense"+NORM+" amount of "+HIK+"P A I N"+NORM+" into "+victim->query_name()+"'s body.\n"+victim->query_name()+" crumbles under the immense "+HIK+"P A I N\n"+NORM;
break;
case 17..22:
bash_mess1 = "You unleash a "+HIR+"GREAT"+NORM+" amount of "+HIK+"P A I N"+NORM+" into "+victim->query_name()+"'s body.\n"+victim->query_name()+" crumbles under the "+HIK+"P A I N\n"+NORM;
bash_mess2 = this_player()->query_name()+" unleashes a "+HIR+"GREAT"+NORM+" amount of "+HIK+"P A I N"+NORM+" into "+victim->query_name()+"'s body.\n"+victim->query_name()+" crumbles under the "+HIK+"P A I N\n"+NORM;
break;
case 12..16:
bash_mess1 = "You unleash a "+HIY+"GOOD"+NORM+" amount of "+HIK+"P A I N"+NORM+" into "+victim->query_name()+"'s body.\n"+victim->query_name()+" crumbles under the "+HIK+"P A I N\n"+NORM;
bash_mess2 = this_player()->query_name()+" unleashes a "+HIY+"GOOD"+NORM+" amount of "+HIK+"P A I N"+NORM+" into "+victim->query_name()+"'s body.\n"+victim->query_name()+" crumbles under the "+HIK+"P A I N\n"+NORM;
break;
case 5..11:
bash_mess1 = "You unleash a FAIR amount of "+HIK+"P A I N"+NORM+" into "+victim->query_name()+"'s body.\n"+victim->query_name()+" tries to shake off the "+HIK+"P A I N\n"+NORM;
bash_mess2 = this_player()->query_name()+" unleashes a FAIR amount of "+HIK+"P A I N"+NORM+" into "+victim->query_name()+"'s body.\n"+victim->query_name()+"  tries to shake off the "+HIK+"P A I N\n"+NORM;
break;
case 1..4: 
bash_mess1 = "You unleash "+HIK+"P A I N"+NORM+" into "+victim->query_name()+"'s body.\n"+victim->query_name()+" seems to shake off the "+HIK+"P A I N\n"+NORM;
bash_mess2 = this_player()->query_name()+" unleashes "+HIK+"P A I N"+NORM+" into "+victim->query_name()+"'s body.\n"+victim->query_name()+" seems to shake off the "+HIK+"P A I N\n"+NORM;
default:
bash_mess1 = "You try to unleash "+HIK+"P A I N"+NORM+" into "+victim->query_name()+"'s body but seem to miss.\n";
bash_mess2 = this_player()->query_name()+" tries to unleash "+HIK+"P A I N"+NORM+" into "+victim->query_name()+"'s body but seem to miss.\n";
break;
}
say(bash_mess2);
Dam1 *= 900; Dam1 /= 1000;
this_player()->spell_object(victim,"pain", Dam1,10,
bash_mess1,
bash_mess2,
"");
this_player()->set_spell_dtype("other|evil");
if(this_player()->query_real_name() == "pestilence") tell_object(this_player(), "TOTAL IS: "+Dam1+" and your combat is "+str_bonus+".\n");
return 1;
}
