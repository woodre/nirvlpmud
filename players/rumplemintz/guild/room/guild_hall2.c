/* Guild Hall - Druids
 * 1/15/2007 - Rumplemintz@Nirvana
 */

#include "../DEFS"

inherit DROOM;

void reset(int arg){
   if(arg) return;
   ::reset(arg);
   set_short(GRN, "At the Druid advancement hall");
   set_long(GRN,"\n"+
"You have entered the Druid Advancement Hall.  It is here where\n"+
"you can exchange your experience points to Druid guild points.\n"+
"You can also type \"list\" to get a list of commands.\n");
   set_exit_color(CYN);
   dest_dir = ({
      "/players/rumplemintz/guild/guild_hall", "west"
   });
}

int list(string str){
   if(str) return 0;
   write(" Commands you can do:\n"+
         " ------------------------------------------------------\n"+
         " Cost ..... Check the costs of advancing\n"+
         " Swap ..... Swap <x> experience for <x> guild experience\n"+
         " Unjoin ... Unjoin the guild (loosing all guild levels!)\n"+
         " ------------------------------------------------------\n\n");
   return 1;
}

int unjoin(){
   int exp, minus;
   if((string)this_player()->query_guild_name() != "druid"){
      write("You are not a member of the Druid guild.\n");
      return 1;
   }
   log_file("druid_unguild",
            this_player()->query_real_name()+" had "+
            this_player()->query_guild_exp()+" guild exp when "+
            this_player()->query_pronoun()+" unjoined.\nThe Time is: "+
            ctime(time())+"\n------------------------------\n");
   exp = (int)this_player()->query_exp();
   minus = exp/2;
   this_player()->add_exp(-minus);
   this_player()->set_title("[Druid TRAITOR!]");
   this_player()->set_al_title("[Don't Trust me!]");
   this_player()->set_guild_name(0);
   this_player()->set_guild_exp(0);
   this_player()->set_guild_rank(0);
   this_player()->set_guild_file(0);
   write("You have just unjoined the Druid guild.\n");
   return 1;
}

int cost(){
   write(
  "  Costs to advance in the guild (in exp)\n"+
  "  --------------------------------------\n"+
  "  Level 1 ......................... Free\n"+
  "  Level 2 .......................... 500\n"+
  "  Level 3 ......................... 1250\n"+
  "  Level 4 ......................... 2250\n"+
  "  Level 5 ......................... 3750\n"+
  "  Level 6 ......................... 5750\n"+
  "  Level 7 ......................... 8250\n"+
  "  Level 8 ........................ 11250\n"+
  "  Level 9 ........................ 14750\n"+
  "  Level 10 ....................... 19750\n"+
  "  Level 11 ....................... 26750\n"+
  "  Level 12 ....................... 35250\n"+
  "  Level 13 ....................... 45250\n"+
  "  Level 14 ....................... 56750\n"+
  "  Level 15 ....................... 71750\n"+
  "  Level 16 ....................... 90250\n"+
  "  Level 17 ...................... 112250\n"+
  "  Level 18 ...................... 137750\n"+
  "  Level 19 ...................... 167750\n"+
  "  Level 20 .......................207750\n"+
  "  --------------------------------------\n"+
  "  You currently have:    "+this_player()->query_guild_exp()+" Druid experience points.\n"+
  "  If you have enough to advance, contact the Grand Master Druid.\n");
   return 1;
}

int swap(int amount){
   int a, x, y, z;
   if((string)this_player()->query_guild_name() != "druid"){
      write("You are not a member of the Druid guild.\n");
      return 1;
   }
   if(!amount){
      write("How much do you want to swap?\n");
      return 1;
   }
   sscanf(amount, "%d", x);
   y = (int)this_player()->query_exp();
   z = (int)this_player()->query_level();
   switch(z){
      case 1: a=0; break;
      case 2: a=1000; break;
      case 3: a=1500; break;
      case 4: a=2250; break;
      case 5: a=3375; break;
      case 6: a=5000; break; 
      case 7: a=7500; break;
      case 8: a=11000; break;
      case 9: a=17000; break;
      case 10: a=25000; break;
      case 11: a=40000; break;
      case 12: a=60000; break;
      case 13: a=90000; break;
      case 14: a=130000; break;
      case 15: a=200000; break;
      case 16: a=300000; break;
      case 17: a=600000; break;
      case 18: a=900000; break;
      case 19: a=1200000; break;
      case 20: a=1500000; break;
      case 21: a=1900000; break;
      case 22: a=2400000; break;
      case 23: a=3000000; break;
      case 24: a=3600000; break;
      case 25: a=4300000; break;
      case 26: a=5100000; break;
      case 27: a=6000000; break;
      case 28: a=7000000; break;
      case 29: a=8100000; break;
      case 30: a=9500000; break;
      default: a=0; break;
   }
   if(y-x < a){
      write("You do not have enough exp to swap that much.\n");
      write("You may swap a total of "+(y-a)+".\n");
      return 1;
   }
   if(x < 1){
      write("You may not swap negative exp.\n");
      return 1;
   }
   log_file("druid_swaps",
            this_player()->query_real_name()+" just swapped "+x+
            "exp.\nThe Time is: "+ctime(time())+
            "\n------------------------------\n");
   this_player()->add_exp(-x);
   this_player()->set_guild_exp(this_player()->query_guild_exp()+x);
   write("Swap complete.\n");
   return 1;
}

void init(){
   ::init();
   add_action("unjoin", "unjoin");
   add_action("swap",   "swap");
   add_action("cost",   "cost");
   add_action("list",   "list");
}
            
