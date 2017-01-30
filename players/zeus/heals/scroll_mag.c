/*  dbreath [alco] - 65pt sp only intox 16  3 shot  1306 base */

inherit "obj/treasure.c";
#include "/players/zeus/closed/all.h"
#define TQL (int)this_player()->query_level()
int shots;
string sht;

reset(arg) {
  if(arg) return;
  shots = 3;
}

id(str){ return str == "breath" || str == "drink";  }
short(){ 
 if(!sht)
	 if(shots == 3)
		 sht = "Dragons breath "+HIC+"[3]"+NORM;
	 if(shots == 2)
		 sht = "Dragons breath "+HIC+"[2]"+NORM;
	 if(shots == 1)
		 sht = "Dragons breath "+HIC+"[1]"+NORM;
 return sht;
}
long(){    write(
"This is a glass of dragons breath.  It is a tasty alcoholic beverage\n"+
"which has been around for ages.  ");
	 if(shots == 3)
		 write("The glass is full.\n");
	 else if(shots == 2)
		 write("The glass is two-thirds full.\n");
	 else if(shots == 1)
		 write("The glass is one-third full.\n");
}


is_heal(){  return "alcohol";  }
query_potence() { return 35; }
query_save_flag() { return 1; }
query_value() { return (shots * 333); }

void init(){
	::init();
	add_action("read_cmd", "drink");
}

status read_cmd(string str){
	int NM, i,f,s,t;
		if(environment(TO) != TP) return 0;
	if(!str){
		write("Drink what?\n");
		return 1; }
	if(str == "breath" || str == "dragons breath"){
  if(!call_other(this_player(),"drink_alcohol", 16)) return 1;
  TP->add_spell_point(65);
  i = (int)TP->query_intoxination()*100 / (TQL+3);
  f = (int)TP->query_stuffed()*100 / (TQL*8);
  s = (int)TP->query_soaked()*100 / (TQL*8);
  t = (int)TP->query_infuse()*100 / ((TQL*9)/2);
  write("You take a drink of dragons breath.\n");
  if(TP->checkNM())
	  NM = 1;
  write(HIC+"\t HP ["+TP->query_hp()+"/"+TP->query_mhp()+"]  ");
  if(NM)
	  write("SP [???]/"+TP->query_msp()+"]  ");
  else
  write("SP ["+TP->query_spell_point()+"/"+TP->query_msp()+"]  ");
  write("I "+i+"%  ");
  write("F "+f+"%  ");
  write("S "+s+"%  ");
  write("T "+t+"%\n"+NORM);
  say(TP->QN+" drinks some dragons breath.\n");
  shots -= 1;
  if(!shots) {
	  write(
	"\nYou finish off the drink and smash the bottle.\n");
	  destruct(TO);
  }
  call_other(TP,"recalc_carry");
  return 1;
	}
}

get() { return 1; }

query_weight() { return 1; }

