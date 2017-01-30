/*  ac 2 type misc...   heals wearer for a limited time..    */
/*  can be 'cash'ed in for 4000+random(4000) coins           */

inherit "obj/armor";
#include "/players/zeus/closed/all.h"
int power_life, money;

reset(arg){
  ::reset(arg);
   if(arg) return;

   power_life = 2000+random(4000);

   set_name("gloves");
   set_short("Black Shadowninja gloves");
   set_type("ring");
   set_ac(2);
   set_weight(1);
   set_value(1400);
   set_heart_beat(1);
}

long(){
	write(
"These are a pair of black ninja gloves.  They are of the utmost quality,\n"+
"and are in perfect condition.  Small gray stripes run down each of the\n"+
"fingers, and converge on the top of each hand.  A tiny emblem has been\n"+
"sewn into the bottom of each glove, the symbol of the Shadowninja.  The\n"+
"pair of black ninja gloves can be 'cash'ed in for a nominal sum of money.\n");
	if(power_life > 2000)
		write("The gloves are glowing with a powerful dark energy.\n");
	if(power_life > 1500 && power_life <= 2000)
		write("The gloves are glowing with a strong dark energy.\n");
	if(power_life > 1000 && power_life <= 1500)
		write("The gloves are glowing with a dark energy.\n");
	if(power_life > 500 && power_life <= 1000)
		write("The gloves are glowing with a weak dark energy.\n");
	if(power_life > 100 && power_life <= 500)
		write("The gloves are glowing with a very weak dark energy.\n");
	if(power_life > 0 && power_life <= 100)
		write("The gloves are glowing with an extremely weak dark energy.\n");
	if(power_life == 0)
		write("The gloves have been drained of all their dark energy.\n");
}

query_save_flag(){    return 1; }

void init(){
	::init();
	add_action("cash_cmd", "cash");
}

status cash_cmd(string str){
	if(!str) return 0;
	if(!present(TO, TP)) return 0;
	if(str == "ninja gloves" || str == "gloves"){
		money = 4000+random(4000);
		write("You cash in the ninja gloves for "+money+" coins.\n");
		TP->add_money(money);
		destruct(TO);
		return 1;
	}
	return 1;
}


void heart_beat(){
    if(!environment()) 
            return ;
	if(!environment()->is_npc()){
		if(!worn) 
            return ;
		if(power_life <= 0)
			return ;
		power_life--;
		if(!random(50)){
			tell_object(environment(),
	"Energy surges from the gloves into your body...\n");
			environment()->heal_self(15);
			power_life -= 20;
		}
	}
}
