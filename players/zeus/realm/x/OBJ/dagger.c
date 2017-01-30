inherit "/obj/weapon.c";
#include "/players/zeus/closed/all.h"

reset(arg) {
   ::reset(arg);
   if (arg) return;

  set_name("dagger");
  set_short("A steel dagger");
  set_value(1700);
  set_weight(2);
  set_class(16+random(4));
  set_hit_func(TO);
}

long(){
  if(class_of_weapon < 18)
  {
    long_desc =
"This is a deadly looking steel dagger.  It has a rather long blade,\n"+
"and a comfortable leather grip.  There are numerous dings and\n"+
"scratches running all along it.\n";
  }
  else
  {
    long_desc =
"This is a deadly looking steel dagger.  It has a rather long blade,\n"+
"and a comfortable leather grip.  There are numerous dings and\n"+
"scratches running all along it.  The blade is extremely sharp.\n";
  }
  ::long();
}

int weapon_hit(object target){
  if(random(100)<=15)
  {
  write("You slash your enemy with the dagger!\n");
  say(environment()->QN+
	  " slashes "+ENV->POS+" enemy with "+ENV->POS+" dagger!\n");
  return 6; 
  }
}

query_save_flag(){    return 1; }

