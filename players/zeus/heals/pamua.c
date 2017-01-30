/* pamua [stuff] - 65pt sp only 3 shot at intox 16 1306 coins base*/

inherit "obj/treasure.c";
#include "/players/zeus/closed/all.h"
#define TQL (int)this_player()->query_level()
int bites;
string sht;

reset(arg) {
  if(arg) return;
  bites = 3;
}

id(str){ return str == "fruit" || str == "pamua";  }

short(){ 
 if(!sht)
         if(bites == 3)
                 sht = "A whole pamua fruit";
         if(bites == 2)
                 sht = "A partially eaten pamua fruit";
         if(bites == 1)
                 sht = "A mostly eaten pamua fruit";
 return sht;
}

long(){    write(
"This is a palm-sized red and orange pamua fruit.  It is somewhat plump\n"+
"and extremely juicy.  A small green stem is protruding from its top.\n");
	if(bites == 3)
        write("The pamua fruit is perfectly round and ready to bite into.");
    else if(bites == 2)
		write("The pamua fruit has a few large bites missing from it.");
    else if(bites == 1)
write("Most of the pamua fruit has been eaten, only one bite remains.");
	write("\n");
}

is_heal(){			return "food";  }
query_potence(){	return 35;      }
query_save_flag(){	return 1;       }
query_value(){		return (bites * 333); }
get(){				return 1;       }
query_weight(){		return 1;       }


void init(){
        ::init();
        add_action("bite_cmd", "eat");
}

status bite_cmd(string str){
	int NM,i,f,s,t;
	if(environment(TO) != TP) return 0;
	if(!str){   write("Eat what?\n");   return 1; }
    if(str == "fruit" || str == "pamua" || str == "pamua fruit")
	{
    if(!call_other(this_player(),"eat_food", 16)) return 1;
 
    write("You take a few big bites out of the tasty pamua fruit...\n"+
          "You feel energized, and rather full.  ");
	if(bites == 3)
		write("There are two servings left.\n");
	if(bites == 2)
		write("There is one serving left.\n");
	if(bites == 1)
		write(BOLD+"You finish off the pamua fruit.\n"+NORM);
  say(TP->QN+" takes a bite of a pamua fruit.\n");
  bites -= 1;
  TP->add_spell_point(65);
  i = (int)TP->query_intoxination()*100 / (TQL+3);
  f = (int)TP->query_stuffed()*100 / (TQL*8);
  s = (int)TP->query_soaked()*100 / (TQL*8);
  t = (int)TP->query_infuse()*100 / ((TQL*9)/2);
  if(TP->checkNM())
	  NM = 1;
  write(HIC+"\t HP ["+TP->query_hp()+"/"+TP->query_mhp()+"]  ");
  if(NM)
	  write("SP [???/"+TP->query_msp()+"]  ");
  else
  	  write("SP ["+TP->query_spell_point()+"/"+TP->query_msp()+"]  ");
  write("I "+i+"%  ");
  write("F "+f+"%  ");
  write("S "+s+"%  ");
  write("T "+t+"%\n"+NORM);
  if(!bites) 
        destruct(TO);
  call_other(TP,"recalc_carry");
  return 1; }
}
