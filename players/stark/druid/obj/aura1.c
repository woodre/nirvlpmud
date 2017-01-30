#include "/players/stark/defs.h"
inherit "obj/armor";
int TIME;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_id("aura");
  set_alias("aura_of_leaves");
  set_short("Aura of Leaves");
  set_long("Druid Aura of Leaves");
  set_ac(0);
  set_type("druid");  /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(0);
  set_value(0);
  TIME=100;
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
	write("The leaves flutter to the ground.\n");
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
		tell_object(owner, "The leaves dampen some of the attack.\n");
		return 1;
	}

	if(i<5){
		return 1;
	}
}


