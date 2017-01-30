/************************************
*   ac1 armor (helmet)  has backlash
*   occurs 10% attacker gets 
*    random(3)  nonsaveable
*
*    approved by saber
************************************/


inherit "obj/armor";
reset(arg){
  ::reset(arg);
  if(arg) return;
  set_name("horns");
  set_short("A Set of Horns");
  set_type("helmet");
  set_long("Curved horns of great power.\n");
  set_ac(1);
  set_weight(1);
  set_value(3500);
}


init() {
  ::init();
remove_call_out("lash");
  call_out("lash",10);
}

lash() {
  if(worn) {
  if(environment(this_object())->query_attack()) {
    if(10 > random(100)) {
       environment(this_object())->query_attack()->hit_player(1 + random(3), "magical");
      tell_object(environment(this_object())->query_attack(),
                 "You feel great pain as the horns skewer through you!\n");
      tell_room(environment(environment(this_object())),
"You see "+  capitalize((environment()->query_attack())->query_name())+
    " scream in agony as "+(environment(this_object())->query_attack())->query_pronoun()+
                 " is impaled on the horns!\n");
      }
      call_out("lash",15);
      return 1;}
      call_out("lash", 10); /* Added by Maledicta 1.01 */
      return 1;}
      call_out("lash",10);
   return 1;}
   
