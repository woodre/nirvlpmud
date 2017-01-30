#include "/players/stark/defs.h"
inherit "obj/armor";
int TIME;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_id("aura");
  set_alias("granite_skin");
  set_short("Granite Skin");
  set_long("Druid Granite Skin");
  set_ac(0);
  set_type("druid");  /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(0);
  set_value(0);
  TIME=50;
  set_heart_beat(1);
}

get() { return 1; }

heart_beat(){
	TIME --;
    if(!TIME){
		call_out("drop",0);
	}
}
drop() {
   command("remove aura",this_player());
	write("Your skin softens again.\n");
	call_out("die",0);
	return 1;
}
die(){
	destruct(TO);
}




do_special(owner){
int i;
i=random(10);
	if(i==0){
		tell_object(owner, "Your skin deflects off much of the attack\n");
		return 5;
	}
}


