#include <ansi.h>
inherit "obj/weapon";
#define stuff environment(this_object())
#define att who
#define attn who->query_name()
#define tp this_player()
#define tpg this_player()->query_guild_name()
#define tpp this_player()->query_attrib("pie")
#define tpn this_player()->query_name()
#define tpw this_player()->query_attrib("wil")
#define tps this_player()->query_attrib("ste")
#define tpsr this_player()->query_attrib("str")
#define gl environment(this_object())->query_guild_rank()

int i;
object who;
reset(arg) {
   ::reset(arg);
   if(arg) return;
    set_short("A blade named Retribution");
    long_desc = "This blade was forged from the finest steel and it glows with a Holy\nLight. You can tell by looking at it that in the right hands\nit would be a weapon of great power. You think\na knight might be able to wield this sword and dole out\nGod's justice to the wicked.\n";
    set_alias("retribution");
    set_class(17);
    set_weight(3);
    set_value(100000);
    set_hit_func(this_object());
    call_out("setstuff",1);
}

query_save_flag() { return 0;}
init(){
add_action("check_wield","wield");
add_action("setstuff","setstuff");
if(wielded) {
   add_action("nope", "so");
   add_action("nope", "sonic");
   add_action("nope", "fi");
   add_action("nope", "fireball");
   add_action("nope", "sh");
   add_action("nope", "shock");
   add_action("nope", "mi");
   add_action("nope", "missile");
}
}

check_wield(str){
if(living(environment(this_object()))){
if(str == "retribution" && tpg != "Knights Templar") {
	write("You are not a Knight!\n");
	write("The weapon glows red hot, injuring you.\n");
	this_player()->heal_self(-20);
	write("God frowns upon you.\n");
	return 1;
}
if(str != "retribution") {
	::wield(str);
	return 1;
}
write("The blade shines brilliantly as you grip it.\n");
write("You feel as if God himself has smiled upon you.\n");
write("You feel inspired to deal out God's Retribution to the"+
      " wicked.\n");
::wield("retribution");
init();
return 1;
setstuff();
}
}

weapon_hit(attacker) {
who = attacker;
if(gl < 4) {
  i=random(10);
}
if(gl < 7) {
  i=random(9);
}
if(gl > 7) {
  i=random(8);
}

if(i == 0) {
	write("You deftly deal your foe a stunning blow.\n");
	tell_object(attacker, tpn+" deals you a stunning blow with "+
	            "the help of God's "+YELLOW+"Retribution"+NONE+
                    ".\n");
	say(tpn+" deals a stunning blow to "+attacker->query_name()+
            " with the help of God's "+YELLOW+"Retribution"+NONE+
            ".\n");
	return 9;
}
if(i == 1) {
	write("The will of God surrounds you, helping you to "+
              "deal a deadly blow to "+attacker->query_name()+
              ".\n");
        tell_object(attacker, "An aura of power and will surrounds "+
                    tpn+" as you are dealt a deadly blow.\n");
        say("An aura surrounds "+tpn+" as "+tpn+" deals "+attn+
            " a deadly blow.\n");
        return 11;
}
if(i == 2) {
	write("The will of God overcomes you, causing you to "+
              "lose your concentration.\n");
        write("Retribution cuts you for your carelessness.\n");
        tp->heal_self(-10);
}
if(i == 3) {
	write("You impale your opponent on your blade.\n");
        tell_object(attacker, tpn+" impales you on a blade named "+
                    "Retribution.\n");
        return 5;
}
}



extra_look(){
if(wielded && living(environment(this_object()))){
return YELLOW+"God's spirit surrounds "+environment(this_object())->query_name()+NONE; 
}
return "";
}

setstuff(){
if(gl < 4) {
     this_object()->set_class(16);
     this_object()->set_short("A blade named Retribution <Spirited>");
     return 1;
}
if(gl < 7) {
     this_object()->set_class(18);
     this_object()->set_short("A blade named Retribution <<Holy>>");
     return 1;
}
this_object()->set_class(20);
this_object()->set_short("A blade named Retribution <<<Divine>>>");
return 1;
}

nope() {
if(wielded) {
write("Your concentration on dealing out God's Retribution is so great that you cannot cast that spell at the moment.\n");
return 1;
}
}


