inherit "/obj/weapon.c";
#include "/players/zeus/closed/all.h"

reset(arg) {
   ::reset(arg);
   if (arg) return;

  set_name("scythe");
  set_short("A menacing scythe");
  set_value(1000+random(3000));
  set_weight(1+random(4));
  set_class(15+random(6));
  set_hit_func(TO);
}

long(){
  if(class_of_weapon < 18)
  {
    long_desc =
"This is a very beautiful scythe.  The steel blade is perfectly smooth,\n"+
"and almost seems to be wrapped in a shadow.  As you stare into it,\n"+
"it seems to ripple softly, mesmerizing you.\n";
  }
  else
  {
    long_desc =
"This is a very beautiful scythe.  The steel blade is perfectly smooth,\n"+
"and almost seems to be wrapped in a shadow.  As you stare into it,\n"+
"it seems to ripple softly, mesmerizing you.  It is a very menacing\n"+
"and deadly weapon.\n";
  }
  ::long();
}

int weapon_hit(object x){
  if(random(100)<=10) {
  write("\nYou rip open "+x->QN+" with your scythe!\n\n");
  say("\n"+environment()->QN+
	  " rips open "+x->QN+" with "+ENV->POS+" scythe!\n\n");
return 6; }
}

query_save_flag(){    return 1; }
