#include "std_old.h"
#include "tune.h"

#define GEMOTE(x) write("Zherin "+x)
#define GSPEAK(x) write("Zherin says: "+x)
#define GWRITE(x) write("             "+x)

/* log advancements and attributes*/
#define LOG_ADVANCE

/* directory for log files */
#define LOGPATH "/players/hawkeye/closed/monk/"

/* Formats columns nicely */
justify(str, len) { return extract(str+"                      ",0,len-1); }

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);

extra_reset(arg) {
   object board, monk;
   if(arg)
     return;

   monk = clone_object("obj/monster");
   monk->set_name("zherin");
   monk->set_alias("monk");
   monk->set_short("Zherin, the Training Master of Monks");
   monk->set_long("Zherin is a sturdy man in his mid forties.\n"+
	  "He is clad in practice armor and carries a large shield\n"+
          "and sword. Zherin is in charge of training monks to ensure\n"+
	  "that they are at the peak of their capabilities.\n");
   monk->set_level(40);
   monk->set_hp(25000);
   monk->set_wc(40);
   monk->set_ac(20);
   monk->set_al(1000);
   monk->set_ep(100);
   move_object(monk, this_object());
}

#undef EXTRA_INIT
#define EXTRA_INIT\
add_action("train","train");\
if(this_player() && !this_player()->query_npc()) {\
  if(this_player()->query_level() < 20 &&\
     !restore_object("players/hawkeye/closed/monk/members/"+\
      this_player()->query_real_name())) {\
    write("Only Monks and Wizards may access this room.\n");\
    move_object(this_player(), "/players/hawkeye/closed/guild/entrance");\
    return 1;\
  }\
}

ONE_EXIT("players/hawkeye/closed/guild/advance", "up",
   "The Monk Advancement Area",
   "worthy of the higher levels.\n"+
   "          raise <str,sta,wil,mag,pie,ste,luc,int>\n", 1)

int next_level;
int next_exp;
int level;
int exp;
string title;         
object player_ob;


#define MAX_MOD 20              /* maximum combat modifier */
#define MAX_PRO 20

/*
 * For raising combat modifiers
 */

train(str) {
   object guild;
   string what;
   int spell, lvl;
   int cost;
     int mod;

   guild = present("statobj", this_player());
   if(!guild) {
     GSPEAK("I can only train Monks.\n");
     return 1;
   }
   if(!str || sscanf(str, "%s", what) != 1) {
     GSPEAK("I can help increase your spell efficiency.\n");
     GWRITE("Would you like me to train you in <mkick>, <flame>\n");
     GWRITE("<blast>,<chop>,<hurl>,<cash>,<crush>,<lightning>\n");
     GWRITE("<tornado>, or <staff>?\n");
     return 1;
   }
   if(what != "blast" && what != "chop" && what != "mkick"
      && what != "hurl" && what != "cash" && what != "flame" && what != "crush"
      && what != "lightning" && what != "tornado"
      && what != "staff"){
     GSPEAK("Type 'train' to see what I can train you in.\n");
     return 1;
   }
   lvl = this_player()->query_level(); 
   spell = guild->query_stat(what);
   if(spell >= MAX_MOD) {
     GSPEAK("You can not train in that skill anymore.\n");
     return 1;
   }
   if(mod >= (lvl + 5)) {
     GSPEAK("You must be of a higher level before I can train you.\n");
     return 1;
   }
   cost = get_cost("mod", mod);
   if(this_player()->query_money() < cost) {
     GSPEAK("You do not have enough money to cover the training fee of\n");
     GWRITE(cost+" gold pieces.\n");
     return 1;
   }
   this_player()->add_money(-cost);
   guild->set_combat_mod(what, (mod+1));
   GEMOTE("bows deeply and then looks around.\n");
   GEMOTE("picks up an old spell book and blows the dust off of it.\n");
   GEMOTE("turns to the page with "+what+" on it and tells you to begin reading.\n");
   if((mod+1) < 20) 
   GSPEAK("You are getting much better, but still have much to learn.\n");
   if((mod +1) == 20)
   GSPEAK("Congratulations! You have Mastered "+what+". Use your powers wisely.\n");
   write("Your "+what+" spell skill is now "+(mod+1)+".\n");
#ifdef LOG_TRAINING     
   write_file(LOGPATH+"PLAYERS", 
      capitalize(this_player()->query_real_name())+" advanced spell "+
      "skill <"+what+"> to "+(mod+1)+" => "+ctime(time())+"\n");
#endif     
   guild->save_statsl();
   return 1;
}

/*
 * For raising weapon proficiencies
 */

cost_for_training() {
   int sword, flail, lance, mace, axe;
   int shield, dual, mounted;
   object guild;

   guild = present("guild_medal", this_player());
   if(!guild) {
     GSPEAK("I can only train monks!\n");
     return 1;
   }
   sword = guild->query_weapon_pro("sword");
   flail = guild->query_weapon_pro("flail");
   lance = guild->query_weapon_pro("lance");
   mace = guild->query_weapon_pro("mace");
   axe = guild->query_weapon_pro("axe");
   shield = guild->query_combat_mod("shield");
   dual = guild->query_combat_mod("dual");
   mounted = guild->query_combat_mod("mounted");
   write(justify("Proficiency",20)+justify("Cost (gp)",10));
     write(justify(" ",10));
     write(justify("Combat Method",25)+justify("Cost (gp)",10)+"\n"); 
   write(justify("===========",20)+justify("=========",10));
     write(justify(" ",10));
     write(justify("=============",25)+justify("=========",10)+"\n");  
   write(justify("Sword:",20)+justify(get_cost("pro",sword),10));
     write(justify(" ",10));
     write(justify("Shield & Sword:",25)+
			       justify(get_cost("mod",shield),10)+"\n");
   write(justify("Flail:",20)+justify(get_cost("pro",flail),10));
     write(justify(" ",10));
     write(justify("Dual Weapons:",25)+
				 justify(get_cost("mod",dual),10)+"\n");
   write(justify("Lance:",20)+justify(get_cost("pro",lance),10));
     write(justify(" ",10));
      write(justify("Mounted:",25)+justify(get_cost("mod",mounted),10)+"\n");
   write(justify("Mace:",20)+justify(get_cost("pro",mace),10)+"\n");
   write(justify("Axe:",20)+justify(get_cost("pro",axe),10)+"\n");
   return 1;
}

int cost_str;

get_cost(what, str) {
   if(!cost_str){
     cost_str = allocate(20);
	
     cost_str[19]  =    6675;
     cost_str[18]  =    6100;
     cost_str[17]  =    5550; 
     cost_str[16]  =    5025;
     cost_str[15]  =    4525;
     cost_str[14]  =    3950;
     cost_str[13]  =    3500;
     cost_str[12]  =    3075;
     cost_str[11]  =    2675;
     cost_str[10]  =    2300;
     cost_str[9]   =    1950;
     cost_str[8]   =    1625;
     cost_str[7]   =    1325;
     cost_str[6]   =    1050;
     cost_str[5]   =     825;
     cost_str[4]   =     625;
     cost_str[3]   =     450;
     cost_str[2]   =     300;
     cost_str[1]   =     175;
     cost_str[0]   =      75;
   }
   if(what == "pro" && str < MAX_PRO)  /* weapon proficiency */
     return cost_str[str]/5;  /* divide it by the number of weapon types */
   if(what == "mod" && str < MAX_PRO)
     return cost_str[str]/3;    /* divide it by the # of combat methods */
				/* do not include standard combat method */
   return "AT MAX";
}

