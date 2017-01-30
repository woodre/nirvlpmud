#include "/players/stark/defs.h"
inherit "obj/armor";
int TIME;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_id("aura");
  set_alias("thorned_wall");
  set_short("Wall of Thorns");
  set_long("Druid Wall of Thorn");
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
	write("The wall of thorn crumbles down.\n");
	call_out("die",0);
	return 1;
}
die(){
	destruct(TO);
}




do_special(owner){
int i;
i=random(20);
	if(i==0 &&
	this_player() &&                     /* Make sure there is somebody to hit! */
	this_player()!=owner &&              /* So the owner doesn't hit himself. */
	this_player()->query_hp() > 50) {    /* So the attacker doesn't kill himself. */
		tell_object(owner, "Vines of thorns lash out from around you at strike out at "+this_player()->query_name()+"!\n");
		write("Thorns lash out at "+this_player()->query_name()+"!\n");
		this_player()->hit_player(50);
		owner->hit_player(15);
		return 0;
	}

	if(i==1){
		tell_object(owner, "The walls harden around you to protect you!\n");
		return 0;
	}

	if(i<5){
		return 2;
	}
}
