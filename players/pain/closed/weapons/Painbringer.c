inherit "obj/weapon";
#include "/players/pain/color.h"
#define stuff environment(this_object())
#define att who
#define attn who->query_name()
#define tp this_player()
#define tpn this_player()->query_name()
#define tpw this_player()->query_attrib("wil")
#define tps this_player()->query_attrib("ste")
#define tpsr this_player()->query_attrib("str")
#define tpl this_player()->query_level()

int i;
object who;
reset(arg) {
   ::reset(arg);
   if(arg) return;
    set_short("the Painbringer");
    set_alias("painbringer");
	set_long("This is Pain's personal weapon of choice <<FEAR IT>>\n");
	set_class(19);
	set_weight(3);
	set_value(100000);
	set_name("Painbringer");

        set_hit_func(this_object());
	call_out("setstuff",1);
}

init(){
	add_action("check_wield","wield");
	add_action("demo","demo");
    add_action("setstuff","setstuff");
}
check_wield(str){
if(living(environment(this_object()))){
if(str == "painbringer" && tpw < 20 && tpl < 17){
	write("You have neither the will power nor the experience to wield "+
              "a weapon of such power!\n");
	say(tpn+" is humiliated at not being able to wield the "+RED+"Painbringer"+END+".\n");
	return 1;
}
if(str == "painbringer" && tpl < 17){
	write("You are too inexperienced to wield this weapon of Pain!\n");
	say(tpn+" is humiliated at not being able to wield the "+RED+"Painbringer"+END+"!\n"); 
	return 1;
}
if(str == "painbringer" && tpw < 20){
	write("You do not have the will to wield such a weapon of Pain and Death!\n");
	say(tpn+" is humiliated at not being able to wield the "+RED+"Painbringer"+END+"!\n");
	return 1;
}
if(str == "painbringer"){
    ::wield("painbringer");
write("You wield your "+RED+"Painbringer"+END+" and seem to grow in stature and power!\n");
say(tpn+" wields the "+RED+"Painbringer"+END+" and seems to grow in stature and power!\n");
setstuff();
}
}
}

weapon_hit(attacker) {
who = attacker;
  i=random(10);
  if (i>6) {
	write("You run your blade across your opponent's body!\n");
	tell_object(attacker,this_player()->query_name()+"'s blade slices through to your very soul\n");
   write("You demolish your opponant leaving him in immense pain.\n");
   return 10;
    }
demo(); 
   return 0;
}
demo(){
int chance;
int count;
int num;
int damage;
int msg;
damage = 10+random(20);
chance = random(100);
if(chance < (tps + tpsr)){
	num = random(5);
    if(damage > 15 && num > 2){
        write("The "+RED+"Painbringer"+END+" inflicts pain upon you.\n");
        environment(this_object())->hit_player(damage);
    }
	while( count < num){
		msg = random(5);
		if(msg == 1){
			write("You thrust your blade into your opponent's "+
                               "stomache and twist it.\n");
 			say(tpn+" thrusts Painbringer into "+attn+"'s "+
                            "stomache and then twists it.\n");
		}
		if(msg == 2){
			write("You run your blade across your opponent's "+
			      "head.\n");
			say(tpn+" runs Painbringer across "+attn+"'s "+
                            "head.\n");
		}
		if(msg == 3){
			write("You deftly slice your opponent's upper arm.\n");
			say(tpn+" deftly slices "+attn+"'s upper arm.\n");
		}
		if(msg == 4){
			write("You stab your opponent with "+RED+"Painbringer"+
			      END+".\n");
			say(tpn+" stabs "+attn+" with "+RED+"Painbringer"+END+
			    ".\n");
		}
		if(msg == 0){
			write("You impale your opponent with "+RED+
			      "Painbringer"+END+".\n");
			say(tpn+" impales "+attn+" with "+RED+"Painbringer"+
			    END+".\n");
		}
		att->hit_player(damage/2);
		count++;
	}
	return 5;
}
return 5;
}


extra_look(){
if(wielded && living(environment(this_object()))){
return RED+"An aura of Pain and suffering surrounds "+environment(this_object())->query_name()+END; 
}
return "";
}
setstuff(){
this_object()->set_short(environment(this_object())->query_name()+
    "'s "+RED+"Painbringer"+END);
return 1;
}

