#include "/players/maledicta/ansi.h"
inherit "obj/armor";

int heal;
int amt;
int cgsave;

reset(arg){
if(arg) return;
set_name("guard");
set_alias("chestguard");
set_short(HIW+"Chestguard of "+HIG+"Health"+NORM);
/*
set_long(
  "This is a lightweight guard that fits over the\n"+
  "shoulder by a small chain and protects the heart.\n"+
  "It has a rune that can be rubbed along its surface.\n");
*/
set_ac(1);
set_type("chest");
set_weight(1);
set_params("magical",1,0,0); /* ill */
set_value(2000);
heal = 1;
cgsave = 0;
amt = 0;
set_heart_beat(1);
}

long()
{
  long_desc = 
  "This is a lightweight guard that fits over the\n"+
  "shoulder by a small chain and protects the heart.\n"+
  "It has a rune that can be rubbed along its surface.\n";  
  if(heal)
    long_desc += "The chestguard is ready for use.\n";
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
   write("As you rub the chestguard, you feel a healing warmth\n"+
         "pass from it to your body.\n");
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
  "\nThe Chestguard of Health "+HIG+"glows"+NORM+" briefly.\n\n");
  set_heart_beat(0);
  }
}

query_save_flag(){ return cgsave; }

/* Added by Fred to save the heal value when stored. 7-28-03 */
locker_arg(){ return ""+heal; }
locker_init(arg){ heal = atoi(arg);  }
restore_thing(str){ restore_object(str); return 1; }
save_thing(str){ save_object(str); return 1; }
generic_object(){ return 1; }
