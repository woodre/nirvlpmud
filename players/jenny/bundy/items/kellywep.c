/*
 * seems to average 10 points of damage per round on a monster with no ac,
 * drawbacks, 2% chance each round of hurting the wielder for 6+random(8) hp.
* drawbacks, 2% chance each round of hurting the wielder for 6+random(8) spell points.
 *            2% chance each round of making the wielder drop the weapon, if luck is 15 or less.
 */
inherit "/obj/weapon.c";
#include "/players/jenny/define.h"
object ob;
int x;
int y;
int ouch;
reset(arg) {
::reset(arg);
    if(arg) return;
    set_name("equipment");
    set_alias("extermination equipment");
set_type("bow");
    set_short(CYN+"extermination equipment"+NORM);  
    set_long(
     "This is the extermination equipment Kelly Bundy took with her\n"+
     "when she left her job as "+RED+"The Verminator"+NORM+".  The tank looks like\n"+
     "it has plenty of deadly gas left.  Maybe you could wield this thing.\n");

set_hit_func(this_object());
set_class(16);
set_value(4200);
set_weight(4);
}
init() { 
::init();
add_action("wielding","wield");
}

weapon_hit(attacker) {
ob = TP->query_attack();
x = random(50);
ouch = 6+random(8);
y = 5+random(10);

if(x < 10 && ob->query_hp() > y) {
say(RED+""+TPN+" sprays "+ob->query_name()+" in the face with poison."+NORM+"\n",ob);
write(""+RED+"You spray "+ob->query_name()+" in the face with poison."+NORM+"\n");
tell_object(ob, ""+RED+""+TPN+" sprays you in the face with poison."+NORM+"\n"); 
/* A CHANGE FOR DO DAMAGE */
ob->do_damage( ({ y }), ({ "other|poison" }) );
return 1; }
if(x == 43 && TP->query_attrib("luc") < 16) {
write(YEL+"The extermination equipment comes unstrapped and falls to the ground."+NORM+"\n");
command("drop extermination equipment",TP);
return 1; }
if(x == 44) {
write(YEL+"The poison fumes sap some of your energy away."+NORM+"\n");
TP->add_spell_point(-ouch);
return 1; }
if(x == 42) {
write(HIG+"You choke on the poison fumes."+NORM+"\n");
command("cough",TP);
command("cough",TP);
command("cough",TP);
/* A CHANGE FOR DO DAMAGE */
    TP->do_damage( ({ ouch }), ({ "other|poison" }) );
return 1;  }
}
wielding(arg) {
if(!arg) { return 0; }
if(arg == "equipment" | arg == "extermination equipment") {
write(""+CYN+"You strap on the extermination equipment."+NORM+"\n");
say(""+CYN+""+TPN+" straps on the extermination equipment."+NORM+"\n");
return 0; }
}
