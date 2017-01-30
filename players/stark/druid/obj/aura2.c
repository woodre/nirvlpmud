#include "/players/stark/defs.h"
inherit "obj/armor";
int TIME;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_id("aura");
  set_alias("skin_of_bark");
  set_short("Bark Skin");
  set_long("Druid Bark Skin");
  set_ac(0);
  set_type("druid");  /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(0);
  set_value(0);
  TIME=400;
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
	write("Your second skin cracks and falls off.\n");
	call_out("die",0);
	return 1;
}
die(){
	destruct(TO);
}




do_special(owner){
int i;
i=random(20);
	if(i==2){
		tell_object(owner, "The harder bark skin softens the blow.\n");
		return 1;
	}

	if(i<13){
		return 1;
	}
}



