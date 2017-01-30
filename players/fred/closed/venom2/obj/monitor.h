

print_monitor(){
tell_object(USER,
BOLD+"["+HIR+USER->query_hp()+NORM+"/"+HIR+USER->query_mhp()+NORM+BOLD+"] ["+HIG+USER->query_sp()+NORM+"/"+HIG+USER->query_msp()+NORM+BOLD+"] "+
   NORM+"MP "+gcolor+mp+NORM+" "+
	"F "+gcolor+USER->query_stuffed()*100/(USER->query_level()*8)+NORM+"% "+
	"S "+gcolor+USER->query_soaked()*100/(USER->query_level()*8)+NORM+"% "+
	"I "+gcolor+USER->query_intoxination()*100/(USER->query_level()+3)+NORM+"% "+
   "T "+gcolor+USER->query_infuse()*100/(USER->query_level()*9)/2+NORM+"% ");
   if(USER->query_attack()){
   tell_object(USER,
   HIM+"AHP "+ATT->query_hp()*10/ATT->query_mhp()+"/10"+NORM+"\n");
   }
   else{
   tell_object(USER, "\n");
   }
if(hypermode){
tell_object(USER, BOLD+"["+gcolor+"Hypermode"+NORM+BOLD+"]  "+NORM);
 }
if(regen){
tell_object(USER,
 BOLD+"["+HIB+"Regeneration"+NORM+" ("+total_tentacles("regeneration")+")"+BOLD+"]  "+NORM);
}
if(burnoff){
tell_object(USER,
 BOLD+"["+HIG+"Burnoff"+NORM+" ("+total_tentacles("burnoff")+")"+BOLD+"]  "+NORM);
}
if(burnoff || regen || hypermode) tell_object(USER, "\n");
return 1;
}
 
guild_monitor_only(){ return 1; }

new_mon(str){
if(!str){ USER->print_monitor();
  /* if(burnoff)
	write(BOLD+"["+HIG+"Burnoff "+total_tentacles("burnoff")+NORM+BOLD+"] ");
	if(regen)
	write(BOLD+"["+HIB+"Regeneration "+total_tentacles("regeneration")+NORM+BOLD+"] ");
	write("\n"); */
   }
else{
	USER->cmd_monitor(str);
   }
		return 1;
}

