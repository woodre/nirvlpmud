inherit "obj/weapon";
#include "/players/pain/color.h"

#define REV_PURPLE REV_MAGENTA

#define stuff environment(this_object())
#define tp this_player()
#define tpn this_player()->query_name()
#define tpw this_player()->query_attrib("wil")
#define tps this_player()->query_attrib("ste")
#define tpsr this_player()->query_attrib("str")
#define tpl this_player()->query_level()

reset(arg) {
	::reset(arg);
	if(arg) return;

	set_name("Widowmaker");
        set_alias("widowmaker");
        set_type("sword"); /* Forbin 2005.02.16 */
        set_short("the Widowmaker, the sword of the Berserker");
        set_long("This is a long, sharp blade that has made many a widow!\n");
	set_class(21);
	set_weight(5);
	set_value(100000);
	set_hit_func(this_object());
}


/*  Commented out by Fred [4-19-05]
init(){
	add_action("check_wield","wield");
}

check_wield(str) {
if(str == "widowmaker") {
	::wield("widowmaker");
	setstuff();
	return 1;
	}
}
*/

weapon_hit(attacker) {
int i;
object who;

who = attacker;
i=random(10);
	if (i>4) {
		write("You run your blade across your opponent's body!\n");
		tell_object(attacker,this_player()->query_name()+"'s blade slices through to your very soul\n");
		write("You demolish your opponant leaving him in immense pain.\n");
		return 10;
	}
	demo(who);
}

demo(object who){
int chance;
int count;
int num;
int damage;
int msg;
string attn;

/* fix by miz 2010 jul 09 - in case there is no attacker obj */
if(!who || !living(who)) attn = "Someone";
else attn = who->query_name();
/* end fixes */

damage = 10+random(20);
chance = random(100);

  if(!who) return;
if(chance < random(40)) {
	num = random(5);
    if(damage > 15 && num > 2){
        write("The "+MAG+"Widowmaker"+END+" inflicts pain upon you.\n");
        environment(this_object())->hit_player(damage);
    }
	while( count < num){
		msg = random(5);
		if(msg == 1){
			write("You thrust your blade into your opponent's "+
                               "stomache and twist it.\n");
 			say(tpn+" thrusts Widowmaker into "+attn+"'s "+
                            "stomache and then twists it.\n");
		}
		if(msg == 2){
			write("You run your blade across your opponent's "+
			      "head.\n");
			say(tpn+" runs Widowmaker across "+attn+"'s "+
                            "head.\n");
		}
		if(msg == 3){
			write("You deftly slice your opponent's upper arm.\n");
			say(tpn+" deftly slices "+attn+"'s upper arm.\n");
		}
		if(msg == 4){
			write("You stab your opponent with "+MAG+"Widowmaker"+
			      END+".\n");
			say(tpn+" stabs "+attn+" with "+MAG+"Widowmaker"+END+
			    ".\n");
		}
		if(msg == 0){
			write("You impale your opponent with "+MAG+
			      "Widowmaker"+END+".\n");
			say(tpn+" impales "+attn+" with "+MAG+"Widowmaker"+
			    END+".\n");
		}
		who->hit_player(damage/4);
		count++;
	}
	return 5;
}
return 5;
}


extra_look(){
	if(wielded && living(environment(this_object()))){
		return MAG+"The Berserker Spirit surrounds "+environment(this_object())->query_name()+END;
	}
	return "";
}

/*  Commented out by Fred [4-19-05]
setstuff(){
	if(!environment(this_object())) return 1;
	if(!living(environment(this_object()))) return 1;
	this_object()->set_short(environment(this_object())->query_name()+
	    "'s "+REV_PURPLE+"Widowmaker"+END);
	return 1;
}

wield(str) { setstuff(); return ::wield(str); }
*/

/* Added by Fred to fix wield problems [4-19-05] */

short()
{
  string str;
  if(environment())
  {
    if(this_player()->query_level() > 40 && wielded && broke)
    {
      return environment()->query_name()+"'s "+MAG+"Widowmaker"+END+" < wc "+class_of_weapon+","+eff_wc+" > (wielded) [BROKEN]";
    }
    if(this_player()->query_level() > 40 && wielded)
    {
      return environment()->query_name()+"'s "+MAG+"Widowmaker"+END+" < wc "+class_of_weapon+","+eff_wc+" > (wielded)";
    }
    if(this_player()->query_level() > 40 && broke)
    { 
      return "the Widowmaker, the sword of the Berserker < wc "+class_of_weapon+","+eff_wc+" > [BROKEN]";
    }
    if(this_player()->query_level() > 40)
    {
      return "the Widowmaker, the sword of the Berserker < wc "+class_of_weapon+","+eff_wc+" >";
    }
    if(wielded && broke)
    {
      return environment()->query_name()+"'s "+MAG+"Widowmaker"+END+" (wielded) [BROKEN]";
    }
    if(wielded) 
    {
      return environment()->query_name()+"'s "+MAG+"Widowmaker"+END+" (wielded)";
    }
    if(broke)
    {
      return "Widowmaker, the sword of the Berserker [BROKEN]";
    }
  return "the Widowmaker, the sword of the Berserker";
  }
}
