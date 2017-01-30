/****************************************
*    This armor has a back lash type of
*    attack. ac 1, 15% chance of occuring
*    attacker  takes random(8)  nonsavable
*
*    approved by saber
****************************************/


#define MEAT environment(this_object()->query_attack())
inherit "obj/armor";
reset(arg){
  ::reset(arg);
  if(arg) return;
  set_name("lightning");
  set_alias("warfan");
  set_short("A Warfan");
  set_type("misc");
  set_long("This warfan is made of a strange blue metal.  The design on\n"+
           "it is that of the Kanji for lightning.\n");
  set_arm_light(1);
  set_ac(1);
  set_weight(1);
  set_value(4000);
    call_out("lash",10);
}


lash() {
object a;
/*
a = present(MEAT, (environment(environment(this_object()))));
*/
  if(!environment(this_object())) return 1;
   if(!environment(environment(this_object()))) {
     call_out("lash",10);
   return 1; }
  if(worn) {
  if(environment(this_object())->query_attack()) {
    if(15 > random(100)) {
     /*     Added to stop people getting hit not in the room...Fred 10-10-03 */
    /*
     if(!a)
       {
         call_out("lash",10);
         return 1;
       }
     */
      environment()->query_attack()->hit_player(1+random(7), "other|electric");
      tell_object(environment(this_object())->query_attack(),
        "You get a nasty shock as "+environment(this_object())->query_name()+
                 " blocks with the warfan!\n");
      tell_room(environment(environment(this_object())),
    (environment(this_object())->query_attack())->query_name()+
                " cries out in pain as electricity surges through "+
            (environment(this_object())->query_attack())->query_objective()+"!\n");
      }
      call_out("lash",15);
      return 1;}
      return 1;}
      call_out("lash",10);
   return 1;}

