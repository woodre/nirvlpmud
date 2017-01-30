inherit "/obj/weapon.c";
int bullets;
reset(arg){
     int bullets;
     bullets = 0;
     set_name("sternmeyer");
     set_alias("11mm");
       set_short("Sternmeyer Type 35\n");
     set_long("This is the Sternmeyer Type 35 11mm handgun.  Its rugged\n"+
              "design and powerful stopping power make it an excellant\n"+
              "street weapon.  Just shoot <monster> to fire it.\n");
     set_class(7);
     set_value(450);
     set_weight(2);
}
init() {
::init();
    add_action("shoot","shoot");}
    
shoot(str){
	if(!present(str,environment(this_player()))) {
	write("Sorry they are not here idiot!\n");
	say(this_player()->query_real_name() + " is an idiot.\n");
	return 1;
	} else {
    object target;
   target=present(find_living(str), environment(this_player()));
    if(!str) { write("Who do you wish to shoot?\n"); return 1;}
    if(!target->query_npc()){write("You can't shoot players!\n");
    return 1;}
    if(bullets <= 0){write("You are out of ammo.\n"); return 1;}
     if(!target) {write("What were you planning to shoot Idiot?\n"); return 1;}
    call_other(target,"heal_self",-random(5)+1);
    write("You fire the Sternmeyer.\n");
    call_other(target, "attacked_by", this_player());
    target->attack_object(this_player());
    say("BOOM!!!\n");
    bullets = bullets -1;
    return 1;
}
}
load(){
   bullets = 8;
}
