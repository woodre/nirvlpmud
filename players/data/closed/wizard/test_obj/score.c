#include "/players/maledicta/closed/w/sdefine.h"
#define CSC RED+"~"+HIR+"{}"+NORM
#define SCS HIR+"{}"+NORM+RED+"~"+NORM


main(string str, object gob, object player)
{

	tell_object(USER, "   "+CSC+CSC+CSC+CSC+CSC+CSC+CSC+CSC+CSC+HIW+"{  Warrior"+
	"  }"+NORM+SCS+SCS+SCS+SCS+SCS+SCS+SCS+SCS+SCS+NORM+"\n");
	tell_object(USER, "    "+USER->short()+"\n");
	tell_object(USER, "    Level "+pad(USER->query_level()+"+"+USER->query_extra_level(), 30)+"");
	
	tell_object(USER, "   Food ["+BOLD+USER->query_stuffed()*100/(USER->query_level()*8)+NORM+"%]\n");
	tell_object(USER, "    Exp   "+pad(USER->query_exp(), 30)+"");
	tell_object(USER, "   Soak ["+BOLD+USER->query_soaked()*100/(USER->query_level()*8)+NORM+"%]\n");
	tell_object(USER, "    Coins "+pad(USER->query_money(), 30)+"");
	tell_object(USER, "   Intox["+BOLD+USER->query_intoxination()*100/(USER->query_level()+3)+NORM+"%]\n\n");
	tell_object(USER, "             "+HIR+"HPS "+HIW+"["+USER->query_hp()+"/"+USER->query_mhp()+"]"+NORM+"    "+
	"         "+HIR+"END "+HIW+"["+USER->query_sp()+"/"+USER->query_msp()+"]"+NORM+"\n");
	tell_object(USER, "   "+NORM+CSC+CSC+CSC+CSC+CSC+CSC+CSC+CSC+CSC+CSC+CSC+CSC+CSC+CSC+CSC+CSC+CSC+CSC+CSC+CSC+CSC+CSC+RED+"~"+NORM+"\n");
	tell_object(USER, "    Prof Lvl ["+GOB->query_glvl()+"]\t");
	if(GOB->query_glvl() < 56){
   tell_object(USER, "Prof Exp ["+GOB->query_gxp()+"/"+GOB->get_etl(GOB->query_glvl())+"]\t");
   }
   else{
   tell_object(USER, "Prof Exp ["+HIR+"MAX"+NORM+"]\t");
   }
 	tell_object(USER, "Skill Pts ["+GOB->query_skill_pts()+"]\n");
	tell_object(USER, "   "+NORM+CSC+CSC+CSC+CSC+CSC+CSC+CSC+CSC+CSC+CSC+CSC+CSC+CSC+CSC+CSC+CSC+CSC+CSC+CSC+CSC+CSC+CSC+RED+"~"+NORM+"\n");
	tell_object(USER, "    ");
	show_age(player);
	tell_object(USER, "\n");
	if(USER->query_quest_point())
	tell_object(USER, "    QPS      ["+USER->query_quest_point()+"]\n");
	USER->check_fight_area();
	if(USER->query_fight_area()){
		tell_object(USER, "    "+HIR+"PK Area"+NORM+"       \n");
	}
	else{
		tell_object(USER, "    "+HIB+"NON-PK Area"+NORM+"   \n");
	}
	tell_object(USER, "   "+NORM+CSC+CSC+CSC+CSC+CSC+CSC+CSC+CSC+CSC+CSC+HIW+"{ "+HIR+"<"+
	" >"+HIW+" }"+NORM+SCS+SCS+SCS+SCS+SCS+SCS+SCS+SCS+SCS+SCS+NORM+"\n");
	tell_object(USER, HIW+"   Type 'skills' for a listing.\n");   
   if(GOB->query_glvl() > 40 && GOB->prof_check())
   tell_object(USER, HIB+"   Type 'skills2' for a listing of add-on skills.\n"+NORM);
   if(GOB->query_monk())
   tell_object(USER, HIB+"   Type 'monk' for help on the Monk Profession.\n"+NORM); 
   tell_object(USER, "\n\n\n"+NORM);
	
	return 1;
}


show_age(object player) {
	int i;
	
	tell_object(USER, "Age ["+HIW);
	i = USER->query_age();
	if (i/43200) {
		tell_object(USER, i/43200 + " days ");
		i = i - (i/43200)*43200;
	}
	if (i/1800) {
		tell_object(USER, i/1800 + " hours ");
		i = i  - (i/1800)*1800;
	}
	if (i/30) {
		tell_object(USER, i/30 + " minutes ");
		i = i - (i/30)*30;
	}
	tell_object(USER, i*2 + " seconds"+NORM+"]\n");
}
