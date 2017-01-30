inherit "obj/armor";
#include "/players/jareel/define.h"
#include "/players/jareel/ansi.h"
#define ATT USER->query_attack()
#define USER environment(this_object())

reset(arg) {
 ::reset(arg);
  if(arg) return; 

  set_name("necklace");
  set_id("necklace");
  set_alias("pendent");
  set_weight(0); /* Its a Necklace */
  set_type("necklace");
  set_short(HIK+"Pendent of Truth"+NORM);
  set_long(
   ""+HIK+"The rune of Truth rests on a delicate chain.  Protective powers\n"+
   "empower this small charm, granting its wearer protection against\n"+
   "the most physical of attacks."+NORM+"\n");

  set_ac(0);
  set_res(2);
/* Don't use set_params for physical
  set_params("physical",1,0,"true_block");
*/
}

    do_special(){
      int i;
          i = random(7);
      if(i==1){
         tell_room(environment(USER),
           "\n"+HIK+" <"+NORM+BLU+"<>"+NORM+HIK+">      "+NORM+"An aura of "+HIK+"Truth"+NORM+" surrounds "+environment()->query_name()+"'s body "+NORM+HIK+"      <"+NORM+BLU+"<>"+HIK+">\n\n"+NORM);
         return 0;}
         return 0;}  
