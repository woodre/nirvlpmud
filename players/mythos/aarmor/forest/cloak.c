/***************************************
*    This armor has a back lash type of
*    attack. ac 3, 4% chance of occuring
*    attacker takes random(8)  nonsavable
*
*    approved by saber
****************************************/


inherit "obj/armor";
reset(arg){
  ::reset(arg);
  if(arg) return;
  set_name("cloak");
  set_short("A Feathered Cloak");
  set_type("armor");
  set_long("This is a cloak of feathers- if you\n"+
           "look closely you notice the feathers \n"+
            "are razor sharp!\n");
  set_ac(3);
  set_weight(1);
  set_value(3000);
}

init() {
  ::init();
 remove_call_out("lash");
  call_out("lash",10);
}

lash() {
  if(worn) {
  if(environment(this_object())->query_attack()) {
    if(4 > random(100)) {
      (environment(this_object())->query_attack())->heal_self(-random(8));
      tell_object(environment(this_object())->query_attack(),
                 "Some feathers from the cloak stick to you.\n"+
                 "Suddenly you realize the feathers are razor sharp!\n"+
                  "You take damage!\n");
      tell_room(environment(environment(this_object())),
                  "Razor sharp feathers fly around as damage is deflected!\n");
      }
      call_out("lash",15);
      return 1;}
      call_out("lash", 10); /* Added by Maledicta 1.01 */
      return 1;}
      call_out("lash",10);
   return 1;}
   
query_save_flag() {return 1;}
