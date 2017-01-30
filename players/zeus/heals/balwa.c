/* balwa [alco] - 50 hp/sp intox 12  3 shot,  2100 base */

inherit "obj/treasure.c";
#include "/players/zeus/closed/all.h"
#define TQL (int)this_player()->query_level()
int drinks;
string sht;

reset(arg) {
  if(arg) return;
  drinks = 3;
}

id(str){ return str == "rum" || str == "balwa" || str == "bottle";  }

short(){ 
 if(!sht)
         if(drinks == 3)
                 sht = "A full bottle of balwa rum";
         if(drinks == 2)
                 sht = "A half full bottle of balwa rum";
         if(drinks == 1)
                 sht = "An almost empty bottle of balwa rum";
 return sht;
}

long(){    write(
"This is a bottle of balwa rum.  The long necked bottle is made of a dark\n"+
"green glass, and has an engraving of a fruit on the front.  The balwa rum\n"+
"is a very dark red.  ");
	if(drinks == 3)
        write("The bottle of balwa rum has three 'drink's left.");
    else if(drinks == 2)
		write("The bottle of balwa rum has two 'drink's left.");
    else if(drinks == 1)
		write("The bottle of balwa rum has one 'drink' left.");
	write("\n");
}

is_heal(){			return "alcohol";  }
query_potence(){	return 35;      }
query_save_flag(){	return 1;       }
query_value(){		return (drinks * 400); }
get(){				return 1;       }
query_weight(){		return 1;       }


void init(){
        ::init();
        add_action("drink_cmd", "drink");
}

status drink_cmd(string str){
	int NM, i, f, s, t;
	if(environment(TO) != TP) return 0;
	if(!str){   write("Drink what?\n");   return 1; }
    if(str == "rum" || str == "balwa" || str == "balwa rum")
	{
    if(!call_other(TP,"drink_alcohol", 10)) return 1;
 
write("You take a long drink of balwa rum...   The strong liquid burns\n"+
          "as it goes down.  ");
	if(drinks == 3)
		write("There are two drinks left.\n");
	if(drinks == 2)
		write("There is one drink left.\n");
	if(drinks == 1)
		write(BOLD+"You toss away the bottle.\n"+NORM);
  say(TP->QN+" takes a drink of a balwa rum.\n");
  drinks -= 1;
  TP->heal_self(50);
  i = (int)TP->query_intoxination()*100 / (TQL+3);
  f = (int)TP->query_stuffed()*100 / (TQL*8);
  s = (int)TP->query_soaked()*100 / (TQL*8);
  t = (int)TP->query_infuse()*100 / ((TQL*9)/2);
  if(TP->checkNM())
	  NM = 1;
  write(GRN+"\t HP ["+TP->query_hp()+"/"+TP->query_mhp()+"]  ");
  if(NM)
	  write("SP [???/"+TP->query_msp()+"]  ");
  else
  	  write("SP ["+TP->query_spell_point()+"/"+TP->query_msp()+"]  ");
  write("I "+i+"%  ");
  write("F "+f+"%  ");
  write("S "+s+"%  ");
  write("T "+t+"%\n"+NORM);
  if(!drinks)
        destruct(TO);
  call_other(TP,"recalc_carry");
  return 1; }
}
