/* kalowa [soak] - 50 hp/sp intox 12 w/ 3 shots for 2100 base */

inherit "obj/treasure.c";
#include "/players/zeus/closed/all.h"
#define TQL (int)this_player()->query_level()
int swigs;
string sht;

reset(arg) {
  if(arg) return;
  swigs = 3;
}

id(str){ return str == "nectar" || str == "kalowa" || str == "bottle";  }

short(){ 
 if(!sht)
         if(swigs == 3)
                 sht = "A full bottle of kalowa nectar";
         if(swigs == 2)
                 sht = "A partially full bottle of kalowa nectar";
         if(swigs == 1)
                 sht = "A nearly empty bottle of kalowa nectar";
 return sht;
}

long(){
	if(swigs == 3)
        write(
"This is a small, clear glass bottle filled with the golden nectar of\n"+
"the kalowa fruit.  Looking at the nectar, tiny black seeds can be seen\n"+
"floating in it.  There are three 'swigs' of nectar left in the bottle.\n");
    else if(swigs == 2)
		write(
"This is a small, clear glass bottle half full of the golden nectar of\n"+
"the kalowa fruit.  Looking at the nectar, tiny black seeds can be seen\n"+
"floating in it.  There are two 'swigs' of the nectar left in the bottle.\n");
    else if(swigs == 1)
		write(
"This is a small, clear glass bottle containing a little bit of the golden\n"+
"nectar of the kalowa fruit.  Looking at the nectar, tiny black seeds can\n"+
"be seen floating in it.  There are two 'swigs' left in the bottle.\n");
}

is_heal(){			return "soak";  }
query_potence(){	return 35;      }
query_save_flag(){	return 1;       }
query_value(){		return (swigs * 330); }
get(){				return 1;       }
query_weight(){		return 1;       }


void init(){
        ::init();
        add_action("swig_cmd", "swig");
}

status swig_cmd(string str){
	int NM,i,f,s,t;
	if(environment(TO) != TP) return 0;
	if(!str){   write("Swig what?\n");   return 1; }
    if(str == "nectar" || str == "kalowa" || str == "kalowa nectar")
	{
    if(!call_other(TP,"drink_soft", 10)) return 1;
 
    write("You take a small swig of the kalowa nectar...\n"+
          "The thick liquid fills you with energy.  ");
	if(swigs == 3)
		write("There are two swigs left.\n");
	if(swigs == 2)
		write("There is one swig left.\n");
	if(swigs == 1)
		write(BOLD+"You toss the bottle away.\n");
  say(TP->QN+" takes a swig of kalowa nectar.\n");
  swigs -= 1;
  TP->heal_self(50);
  i = (int)TP->query_intoxination()*100 / (TQL+3);
  f = (int)TP->query_stuffed()*100 / (TQL*8);
  s = (int)TP->query_soaked()*100 / (TQL*8);
  t = (int)TP->query_infuse()*100 / ((TQL*9)/2);
  if(TP->checkNM())
	  NM = 1;
  write(NORM+GRN+"\t HP ["+TP->query_hp()+"/"+TP->query_mhp()+"]  ");
  if(NM)
	  write("SP [???/"+TP->query_msp()+"]  ");
  else
  	  write("SP ["+TP->query_spell_point()+"/"+TP->query_msp()+"]  ");
  write("I "+i+"%  ");
  write("F "+f+"%  ");
  write("S "+s+"%  ");
  write("T "+t+"%\n"+NORM);
    if(!swigs)
        destruct(TO);
  call_other(TP,"recalc_carry");
  return 1; }
}
