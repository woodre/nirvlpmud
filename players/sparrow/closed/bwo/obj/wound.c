#include <ansi.h>
inherit "obj/treasure";
string part;
int infection, rank;

short() {
  return 0;
}
long() {}
get() { return; }
drop() { return 1; }
id(str) { return str=="BWOwound"; }

void init() {
  if (!this_object()) return;
  if(!part) { part = "chest"; }
  if(!rank) { rank = 10; }
}

/* 
 * Function name: wink_out()
 * Description:   This function causes the globe of darkness to
 *                "wink out" (destruct)
 * Arguments:     none
 * Returns:       void
 */
void 
heal_it(){
  tell_room(environment(environment()), 
    "The wound on "+environment()->query_name()+"'s "+part+" has scabbed over");
  if(infection == 1) tell_room(environment(environment())," and the infection has subsided");
  tell_room(environment(environment()), ".\n");
  destruct(this_object());
  return;
}

int query_infection() {
  if(infection) { 
    return 1;
  }
  return 0;
}

void start_wound(string x, int y) {
  part = x;
  rank = y;
  call_out("heal_it", random(rank)+rank);
  call_out("bleed", 1);
  return;
}

void bleed() {
  string *msg;
  string mn;
  int dam;
  mn = (string)environment()->query_name();
  msg = ({RED+"Blood"+NORM+" POURS from the wound on "+mn+"'s "+part+"!\n",
          "The wound on "+mn+"'s "+part+HIR+" squirts blood"+NORM+" with every heartbeat!\n",
		  mn+"'s "+part+" is covered with "+RED+"BLOOD"+NORM+" from the garish gash in it!\n",
		  HIR+"Blood"+NORM+" splashes the floor from the wound on "+mn+"'s "+part+"!\n"});
  dam = 5 + random(rank/2);
  tell_room(environment(environment()), "["+HIG+dam+NORM+"] "+msg[random(sizeof(msg))]);
  environment()->hit_player(dam, 0);
  call_out("bleed", 1);
}

void start_infection() {
  remove_call_out("heal_it");
  call_out("heal_it", random(rank)+rank);
  infection = 1;
  call_out("infected", 1);
  return;
}  

void infected(){
  string *msg;
  string mn;
  int dam;
  mn = (string)environment()->query_name();
  dam = 3+random(rank/3);
  msg = ({"Puss "+YEL+"oozes"+NORM+" out of the wound on "+mn+"'s "+part+"!\n",
          "The gash in "+mn+"'s "+part+" bubbles with "+YEL+"greenish-yellow fluid"+NORM+"!\n",
		  "The area around "+mn+"'s wound has turned a reddish color from "+BOLD+"infection"+NORM+"!\n",
		  mn+"'s "+part+" smells terrible from the "+YEL+"infection!\n",
		  mn+" begins to look "+BOLD+"flushed"+NORM+" and "+BOLD+"feverish"+NORM+" from the infected wound!\n"});
  tell_room(environment(environment()), "["+HIY+dam+NORM+"] "+msg[random(sizeof(msg))]);
  environment()->hit_player(dam, "other|poison");
  call_out("infected", 2);  
}

void increase_duration() {
  remove_call_out("heal_it");
  call_out("heal_it", random(rank)+rank);
}