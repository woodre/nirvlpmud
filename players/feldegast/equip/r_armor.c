/*
Runic armor
by Feldegast@Nirvana
10-2-2000
*/
#include "defs.h"
inherit "/obj/armor.c";

int activated;

int query_runic() {
  return 1;
}

int rune_check() {
  object ob;
  int count;
  ob = first_inventory(this_player());
  while(ob) {
    if(ob->query_runic() && ob->query_worn())
      count++;
    ob = next_inventory(ob);
  }
  if(count==7)
    return 1;
  else
    return 0;
}

void set_runes(int x) {
  object ob;
  ob = first_inventory(this_player());
  if(x==1)
    write(BOLD+"As you strap on the final piece, the runes on your armor\n"+
          "start to glow with an unearthly light.\n"+NORM);
  while(ob) {
    if(ob->query_runic()) {
      ob->set_activated(x);
      if(x==1)
        write((string)ob->query_short()+CYN+" flashes as it activates!\n"+NORM);
    }
    ob = next_inventory(ob);
  }
}

void set_activated(int x) {
  activated = x;
}

wear(str)
{
    object ob;
    object guild, invob;  /* For paladin additions */
    int tmp;
    

    if (!id(str))
	return 0;
    if (environment() != this_player()) {
	write("You must get it first!\n");
	return 1;
    }
    if(present("notarmor",this_player())) {
       write("For some reason you are unable to wear armor.\n");
       return 1;
    }
    if (worn) {
	write("You are already wearing it!\n");
	return 1;
    }
    next = 0;
/* BEGIN PALADIN ADDITION */
/* If the paladin has an off-wielded weapon they cannot wear shields! */
   invob = first_inventory(this_player());
   while(invob) {
     guild = invob->query_offwielded();
     if(guild && type == "shield") {
       write("You have an offwielded weapon!\n");
       return 1;
     }
     invob = next_inventory(invob);
   }
/* END PALADIN ADDITION */
    if(!protect)
       protect = "physical";
    set_params(protect,ac,res,special);
    ob = call_other(this_player(), "wear", this_object(), silently, type, params);
    if(ob) {
	worn_by = this_player();
	worn = 1;
        if(rune_check())
          set_runes(1);
	return 1;
    }
    write("You already have an armor of class " + type + ".\n");
    return 1;
}

remove(str) {
    if (!id(str))
	return 0;
    if (!worn) {
	return 0;
    }
    call_other(worn_by, "stop_wearing",this_object(), type, silently);
    worn_by = 0;
    worn = 0;
    set_runes(0);
    return 1;
}

string query_short() {
  return short_desc;
}
