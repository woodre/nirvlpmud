/*  droot [stuff] - 65pt hp only intox 16  1306 */

inherit "obj/treasure.c";
#include "/players/zeus/closed/all.h"
#define TQL (int)this_player()->query_level()
int shots;
string sht;

reset(arg) {
  if(arg) return;
  shots = 3;
}

id(str){ return str == "root" || str == "dragons root";  }
short(){ 
 if(!sht)
	 if(shots == 3)
		 sht = "Dragons root "+HIC+"[3]"+NORM;
	 if(shots == 2)
		 sht = "Dragons root "+HIC+"[2]"+NORM;
	 if(shots == 1)
		 sht = "Dragons root "+HIC+"[1]"+NORM;
 return sht;
}
long(){    write(
"This is a tasty dragons root.  It has been cleaned off and looks very\n"+
"good to 'eat'.  ");
	 if(shots == 3)
		 write("There are three more bites.\n");
	 else if(shots == 2)
		 write("There are two more bites.\n");
	 else if(shots == 1)
		 write("There is one more bite.\n");
}


is_heal(){  return "food";  }
query_potence() { return 35; }
query_save_flag() { return 1; }
query_value() { return (shots * 333); }

void init(){
	::init();
	add_action("read_cmd", "eat");
}

status read_cmd(string str){
	int NM, i,f,s,t;
	if(environment(TO) != TP) return 0;
	if(!str){
		write("Eat what?\n");
		return 1; }
	if(str == "root" || str == "dragons root"){
  if(!call_other(this_player(),"eat_food", 16)) return 1;
  TP->add_hit_point(65);
  i = (int)TP->query_intoxination()*100 / (TQL+3);
  f = (int)TP->query_stuffed()*100 / (TQL*8);
  s = (int)TP->query_soaked()*100 / (TQL*8);
  t = (int)TP->query_infuse()*100 / ((TQL*9)/2);
  write("You take a bite of dragons root.\n");
  write(HIC+"\t HP ["+TP->query_hp()+"/"+TP->query_mhp()+"]  ");
  if(NM)
	  write("SP [???]/"+TP->query_msp()+"]  ");
  else
  write("SP ["+TP->query_spell_point()+"/"+TP->query_msp()+"]  ");
  write("I "+i+"%  ");
  write("F "+f+"%  ");
  write("S "+s+"%  ");
  write("T "+t+"%\n"+NORM);
  say(TP->QN+" eats some dragons root.\n");
  shots -= 1;
  if(!shots) {
	  write(
	"\nYou eat the last of the dragons root.\n");
	  destruct(TO);
  }
  call_other(TP,"recalc_carry");
  return 1;
	}
}

get() { return 1; }
query_weight() { return 1; }

