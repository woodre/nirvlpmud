#define POSS environment(this_object())->query_possessive()
inherit "/players/saber/armor/armor3.c";
reset(arg){
   ::reset(arg);
   set_name("gothic_dance");
   set_short();
   set_long();
   set_type("dance");
   set_ac(1);
   set_weight(0);
   set_value(0);
call_out("count_down", random(750) + 25);
call_out("dance_time", random(30) + 10);
}
drop() {return 1;}
get() {return 1;}

count_down()  {
object ob;
  ob = environment(this_object());
tell_room(environment(ob),
    environment(this_object())->query_name()+" looks depressed and stops dancing.\n");
command("drop gothic_dance", environment(this_object()));
remove_call_out("count_down");
remove_call_out("dance_time");
destruct(this_object());
  return 1;
        }

dance_time()  {
int temp;
string dance;
object ob;
  ob = environment(this_object());
  temp = random(10);
  if(temp == 0)  dance = "moves "+POSS+" arms slowly about "+POSS+" body";
  if(temp == 1)  dance = "sways slowly to unheard music";
  if(temp == 2)  dance = "spirals slowly";
  if(temp == 3)  dance = "steps slowly about the chamber in a trancelike motion";
  if(temp == 4)  dance = "steps fowards, twists about and steps forward again";
  if(temp == 5)  dance = "spirals "+POSS+" hands in front of "+POSS+" face";
  if(temp == 6)  dance = "wraps "+POSS+" hands over "+POSS+" head and sways slowly";
  if(temp == 7)  dance = "moves with the grace of a cat in a series of measured, twisting steps";
  if(temp == 8)  dance = "sways and spins with languid grace";
  if(temp == 9)  dance = "moves with a lackadaisical grace to unheard music";

tell_room(environment(ob),
  environment(this_object())->query_name()+" "+dance+".\n");
call_out("dance_time", random(50) + 10);
  return 1;
        }
