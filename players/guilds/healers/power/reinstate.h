reinstate(int lvl,int pi,string who,string typ) {
   object targ;
   object spell;
   int spm,hpm;
   spm = hpm = 0;
   if(!who) { write("Who do you wish to reinstate?\n"); return 1; }
   if(!typ) 
   {
     write("What stat do you wish to reinstate?\n"+
           "  <sta,str,mag,ste,wil,luc,int,pie>\n"); 
     return 1; 
   }

   if(typ != "sta" && typ != "mag" && typ != "wil" && typ != "ste" &&
      typ != "str" && typ != "luc" && typ != "pie" && typ != "int") 
   {
     write("What stat do you wish to reinstate?\n"+
           "  <sta,str,mag,ste,wil,luc,int,pie>\n"); 
     return 1; 
   }

   if(!(targ=present(who,etp))) 
   {
     write("That person is not here!\n");
     return 1; 
   }

   if(!living(targ)) { write("You may only cast upon something living.\n"); return 1; }

   if(targ->query_invis() > tl) 
   {
     write("That person is not here!\n"); 
     return 1;
   }

   if(targ->query_ghost()) { write("You can not cast upon a ghost!\n"); return 1; }
   if(targ->query_level() > 19)  { write("You can not cast upon a wiz!\n"); return 1; }
   if(targ->query_real_name() == "guest") { write("Guest may not be healed.\n"); return 1; }
   if(targ == tp) { write("You may not cast this upon yourself!\n"); return 1; }
   if(reinstate_var[1] > tsp) { write("You are low on energy.\n"); return 1; }
   if(reinstate_var[2] > thp) { write("You are low on physical energy.\n"); return 1; }
   if(reinstate_var[3] > tp->query_exp()) { write("You are low on exp.\n"); return 1; }
   if(reinstate_var[4] > tp->query_money()) { write("You are low on money.\n"); return 1; }

   if(!check(lvl,pi,reinstate_var[6],reinstate_var[7],reinstate_var[8])) 
   {
     write("Your Reinstatement spell fails!\n");
     return 1; 
   }

   if(targ->query_guild_name()=="polymorph") 
   {
     write(targ->query_name()+"'s extradimensional nature repels your spell.\n");
     return 1;
   }

   if(present("reinstate_spell",targ))
   {
     write("That person already has a reinstate spell.\n");
     return 1;
   }

   tp->add_spell_point(-reinstate_var[1]);
   tp->add_hit_point(-reinstate_var[2]);

   if(present("mythos_healer",targ)) 
   {
     if(hob) tp->add_xp(-2 * reinstate_var[3]);
     else tp->add_exp(-2 * reinstate_var[3]);
   }
   else {
     if(hob) tp->add_xp(-reinstate_var[3]);
     else tp->add_exp(-reinstate_var[3]); 
   }

   tp->add_money(-reinstate_var[4]);

/* Laff!  No.  - Feldegast 1-2-00
   call_other(targ,"raise_"+typ,1);
*/
   spell = clone_object(root+"obj/reinstate_spell.c");
   spell->start(targ,typ,lvl/10);   

   write("You intone for a moment and touch "+
         capitalize(targ->query_real_name())+" lightly with your palm.\n");
   say(tp->query_name()+" intones for a moment and lightly touches "+
       targ->query_name()+" with a palm.\n");
   tell_object(targ,"You feel great heat pass from the "+
               tp->query_name()+"'s palm into you!\n");

   tell_room(etp,"\n\t\t\t>  > C R A C K <  <\n\n"+targ->query_name()+" and "+
                 tp->query_name()+" are both flung backwards by an invisible force!\n");
   tell_object(targ, "\nYour "+typ+" has been reinstated.\n");
   write("\nYou have reinstated "+who+"'s "+typ+"\n");
   return 1; 
}
