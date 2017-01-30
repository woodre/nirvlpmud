/*
A whip that does extra damage. It is wc15 with max extra of 7 (1 in 10 chance)
*/
 
#define TP this_player()
#define TPN capitalize(TP->query_name())
#define MEAT TP->query_attack()
#define MEATN capitalize(MEAT->query_name())
 
inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("metal whip");
    set_alias("whip");
    set_short("A Metal Whip");
    set_long(
"This whip was forged of some sort of malleable metal. Flames alternate\n"+
"with bitter blue cold in running along its length.\n");
    set_class(15);
    set_weight(1);
    set_value(1000);
    set_hit_func(this_object());
}
weapon_hit() {
int W;
    W = random(50);
  if(W > 24 && W < 35) {
flame_burn();
return 2;
  }
  if(W > 34 && W < 45) {
cold_burn();  
return 2;
   }
  if(W > 44) {
flame_cold();
return 2;
  }
       return;
}
 
flame_burn() {
  say("Flame burns along the length of "+TPN+"'s Metal Whip!\n");
  write("Flame burns along the length of your Metal Whip!\n");
call_other(MEAT,"heal_self",-2);
return 1;
}
 
cold_burn() {
  say("Blue cold crackles along the length of "+TPN+"'s Metal Whip!\n");
  write("Blue cold crackles along the length of your Metal Whip!\n");
call_other(MEAT,"heal_self",-2);
return 1;
}
 
flame_cold() {
  say(
"Fire and Ice smash down on "+MEATN+" from a crack of "+TPN+"'s Metal Whip!\n");
  write(
"Fire and Ice smash down on "+MEATN+" from a crack of your Metal Whip!\n");
call_other(MEAT,"heal_self",-5);
return 1;
}
