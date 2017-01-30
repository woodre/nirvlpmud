inherit "obj/weapon.c";
#include "/players/jareel/define.h"
#include "/players/jareel/ansi.h"

 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("great staff");
    set_alias("kendrane");
    set_short(HIR+"Kendrane"+NORM+", Legendary Great Staff of the "+RED+"Red Goddess"+NORM+" "+HIK+"["+NORM+BOLD+"Evocation and Power"+NORM+HIK+"] "+NORM);
   set_type("staff");
    set_long(
"\n"+
"\n");
    set_class(10);
    set_weight(2);
    set_value(20000);
    set_hit_func(this_object());
}

weapon_hit() {
  if(!MEAT) return 0; 
  skill_hit();
  if(!MEAT) return 0;
  if(random(TPXL) > random(13))  {
  say(TPN+
"  "+MEATN+"  "+GEN+" \n");
  write(
" "+MEATN+"\n");
  return 4;
   }
  return 1;
}
 
skill_hit() {
  object meat;
  meat = this_player()->query_attack();
  if(!meat) return 1;
  if(random(TPI) > random(90)) int_hit(meat);  /* Staff Will Fire Special*/ 
  if(random(TPM) > random(90)) mag_hit(meat);  /* Staff Will Fire Special*/
return 1;
}

mag_hit(object ob) {
  int lev; string name;
  lev = TPL + (TPXL/2);
  if(!ob) return;
  name = ob->query_name();  
    get_message();
    get_message(); /* Maybe Randomise this so it shoots 3-6 mssles */
    get_message();  
    get_message();
    get_message();
  return 1; }
 
int_hit(object ob) {
  int lev; string name;
  lev = TPL + (TPXL);
  if(!ob) return;
  name = ob->query_name();
    get_message2();
  ob->hit_player(lev/9, "magical"); /* Do A few Crater Shots with this Switch */
  return 1; }

mapping ac_effects;
    
wil_hit(object ob) {
  int oac; string name;
  if(!ob) return;
  name = ob->query_name();
  oac = ob->query_ac();
  if(!oac) return 1;
  if(oac < 10) return 1;
  if(ob->query_interactive()) { ob->heal_self(-5); return 1; }
  
  if(!ac_effects) ac_effects=([]);
  if(ac_effects[ob]) {
    ac_effects[ob]--;
  } else {
    ac_effects[ob]=-1;
  }
  ob->RegisterArmor(this_object(),({"magical",ac_effects[ob],10,"Magic_Block"}));
  return 1; }
  
Magic_Block(){
  int i;
  i = 1;
  if(i==1){
    tell_room( environment(TO), 
	MEATN+"'s "+HIM+"magic"+NORM+BOLD+BLINK+" sparks"+NORM+" off "+TPN+"'s "+BLU+"staff"+NORM+" as he spins and block the attack.\n"+NORM);
  return 0;}
  return 0;} 

 
  
get_message(object ob)
{
  int lev; string name;
  lev = TPL + (TPXL/2);
  if(!ob) return;
  name = ob->query_name();
if(environment(TP)){
	  switch(random(6))
      {

         case 0:
         {
         	
       tell_room(environment(TP),
               TPN+"'s missile flies straight into test. , a "+RED+"direct"+NORM+" hit!\n");
			     ob->hit_player(lev/7, "magical");
			return 1;
         	break;
         }
         
         case 1: 
         {
		 

       tell_room(environment(TP),
              TPN+"magic missile "+HIR+"hits"+NORM+" test..\n");
			    ob->hit_player(lev/8, "magical");
			return 1;  
         	break;
         }
         
         case 2:
         {
         	

       tell_room(environment(TP),
              TPN+"'s missile "+HIC+"grazes"+NORM+" test.\n");
			    ob->hit_player(lev/10, "magical");
			return 1;  
         	break;
         }
         
         case 3: 
         {
		 

        tell_room(environment(TP),
              TPN+"'s missle fizzles ...what a dud!\n"); 
		    return 1; 
         	break;
         }
         
         case 4: 
         {
		 

       tell_room(environment(TP),
               TPN+"'s missile flies straight into test. , a "+RED+"direct"+NORM+" hit!\n");
			     ob->hit_player(lev/7, "magical");
			return 1;
         	break;
         }
         
         case 5: 
         {	
         	

       tell_room(environment(TP),
               TPN+"'s missile flies straight into test. , a "+RED+"direct"+NORM+" hit!\n");
			     ob->hit_player(lev/7, "magical");
			return 1;
         	break;
         }
         
         default: 
         {
		 

       tell_room(environment(TP),
              TPN+"'s magic missile "+HIR+"hits"+NORM+"test..\n",  );
			    ob->hit_player(lev/8, "magical");
			return 1;  
         	break;
         }
         
	}

}}

get_message2()
{
if(environment(TP)){
	  switch(random(6))
      {

         case 0:
         {
         	
       tell_room(environment(TP),
               TPN+"'s missile flies straight into test. , a "+RED+"direct"+NORM+" hit!\n");
			return 1;
         	break;
         }
         
         case 1: 
         {
		 

       tell_room(environment(TP),
              TPN+"magic missile "+HIR+"hits"+NORM+" test..\n");
			return 1;  
         	break;
         }
         
         case 2:
         {
         	

       tell_room(environment(TP),
              TPN+"'s missile "+HIC+"grazes"+NORM+" test.\n");
			return 1;  
         	break;
         }
         
         case 3: 
         {
		 

        tell_room(environment(TP),
              TPN+"'s missle fizzles ...what a dud!\n"); 
		    return 1; 
         	break;
         }
         
         case 4: 
         {
		 

       tell_room(environment(TP),
               TPN+"'s missile flies straight into test. , a "+RED+"direct"+NORM+" hit!\n");
			return 1;
         	break;
         }
         
         case 5: 
         {	
         	

       tell_room(environment(TP),
               TPN+"'s missile flies straight into test. , a "+RED+"direct"+NORM+" hit!\n");
			return 1;
         	break;
         }
         
         default: 
         {
		 

       tell_room(environment(TP),
              TPN+"'s magic missile "+HIR+"hits"+NORM+"test..\n",  );
			return 1;  
         	break;
         }
         
	}

}}  
  
no_exp_effect() { return 1; }   /* keep the sword from lowering the exp value */
