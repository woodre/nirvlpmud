/* Chestguard of Health */

#include "/players/jareel/define.h"
inherit "obj/armor";

int heal;
int amt;
int cgsave;

reset(arg){
if(arg) return;
set_name("guard");
set_alias("chestguard");
set_short(HIK+"Demon Guard"+NORM+" ["+HIY+"Sun Forged"+NORM+"]");
set_ac(1);
set_type("chest");
set_weight(1);
set_light(1);
set_value(2000);
heal = 1;
cgsave = 0;
amt = 0;
set_heart_beat(1);
}

long()
{
  long_desc = 
  "A guard forged in the Sun fire of Yelm.  This ancient\n"+
  "practice unleashes magical properties of chaotic flesh.\n";  
  if(heal)
    long_desc += "The demon guard is ready for use.\n";
  ::long();
}

init(){
  ::init();
  add_action("rub_it", "rub");
  }

rub_it(str){
  if(!worn){ write("You must be wearing it!\n"); return; }
  if(!str){ write("rub what?\n"); return; }
  if(str == "guard" || str == "chestguard"){
   if(!heal){ write("The Chestguard is recharging...\n");
              return 1;
            }
   this_player()->heal_self(50);
   heal = 0;
   set_heart_beat(1);
   if(!random(1000)){
      cgsave = 1;
   }
   write(HIY+"As you rub the guard, you feel a healing warmth\n"+
         "pass from it to your body.\n"+NORM);
   return 1;
   }
write("Rub what?\n");
return;
}

heart_beat(){
  amt += 1;
if(!worn) return;
if(heal){
  set_heart_beat(0);
  return;
  }
if(amt > 120){
  heal = 1;
  amt = 0;
  tell_object(environment(),
  "\nThe guard "+HIY+"glows"+NORM+" briefly.\n\n");
  set_heart_beat(0);
  }
}

query_save_flag(){ return cgsave; }

locker_arg(){ return ""+heal; }
locker_init(arg){ heal = atoi(arg);  }
restore_thing(str){ restore_object(str); return 1; }
save_thing(str){ save_object(str); return 1; }
generic_object(){ return 1; }
