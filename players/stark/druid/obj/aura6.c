#include "/players/stark/defs.h"
inherit "obj/armor";
int TIME;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_id("aura");
  set_alias("natures_smile");
  set_short("Natures Smile");
  set_long("Druid Natures Smile");
  set_ac(0);
  set_type("druid");  /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(0);
  set_value(0);
  TIME=500;
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
	write("The glow around you gently fades.\n");
	call_out("die",0);
	return 1;
}
die(){
	destruct(TO);
}




do_special(owner){
int i;
int hop
i=random(2);
i=random(10);
	if(i==0){
		if(hop==0){
			tell_object(owner, "Your skin deflects off much of the attack\n");
			return 5;
		}
		if(hop==1){
			owner->heal_self(random(5) + 5);
			return 0;
		}
	}
}

