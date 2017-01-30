/* Copy of staff given by Daranath, to help teach coding  JUN-10-2002  */

#include "/players/wocket/closed/ansi.h"
inherit "/obj/weapon.c";
int charge;
int light;
int MAGIC;
reset(arg){
  ::reset(arg);
  if(arg) return 1;
set_alt_name("staff");
get_short();
set_class(16);
set_type("staff");
set_weight(6);
set_value(4000);
set_long("This giant oak staff belongs to the magus.  There is a deep purple orb\n"+
"set upon the top held by a pewter dragon.  The tail swirls down along the\n"+
"staff making excellent grips.  The staff shimmers with power.  There is a\n"+
"small inscription carved into the staff.\n");

set_read(""+
"Carved deep within the oak staff many symbols lay hidden among the chips.\n"+
"Through strong concentration the images begin to take shape revealing the\n"+
"powers which the staff may be used for...\n"+
"      /*-      staff_heal                              25sp\n"+
"      ())      staff_light                             10sp\n"+
"      >#<      staff_blast                             15sp\n"+
"      {\\|      staff_charge                            40sp\n"+
"Suddenly your concentration breaks and you can not decipher any more.\n");


set_hit_func(this_object());
}

weapon_hit(attacker){
int i;
if(charge != 1){
  return 0;
}
i = random(13);
if(i<3){
tell_room(environment(this_player()),"\nThe staff begins to shake violently then suddenly...\n"+
      this_player()->query_attack()->query_name()+" ignites as...\n\n"+
      HIB+"                 L I G H T N I N G\n"+ 
          "                   F L A S H E S\n\n"+NORM+
      "from the orb of the staff.....\n");
return 7;
}
if(i<7){
write("\nThe staff"+HIC+" GLOWS"+NORM+" as it "+HIB+"SMASHES"+NORM+" into "+this_player()->query_attack()->query_name()+".\n\n");
return 5;
}

}

init(){
  ::init();
    add_action("powers","staff_powers");
    add_action("staff_heal","staff_heal");
    add_action("staff_light","staff_light");
    add_action("staff_blast","staff_blast");
    add_action("staff_charge","staff_charge");
}

check_wielded(){
  if(this_player()->query_weapon() == this_object()){
    return 1;
  }
  else {
  notify_fail("You must be wielding the staff to use its powers.\n");
  return 0;
}}

check_magic(){
int i;
  i = this_player()->query_attrib("int");
  if(i > 20) i = 20;
  if(i < 0) i = 0;
return i;
}

powers(){
write("You look deep into the orb and see:\n\n"+
      HIC+"staff_heal"+NORM+"              25sp\n"+
      HIY+"staff_light"+NORM+"             10sp\n"+
      HIG+"staff_blast"+NORM+"             15sp\n"+
      HIB+"staff_charge"+NORM+"            40sp\n"+
      "\nThen the images fade...\n");
return 1;
}

staff_charge(){
int time;
MAGIC = check_magic();
if(check_wielded() == 0) return 0;
if(this_player()->query_spell_point() < 40){
  notify_fail("You lack the energy to charge the staff.\n");
  return 0;
}
this_player()->add_spell_point(-40);
charge = 1;
get_short();
time = ((300+random(300))*MAGIC)/20;
call_out("remove_charge",time);
write("You concentrate intently upon the orb of the staff.  Electricity crackles as\n"+
      "your magic drains into the staff, charging it.  The staff gives off a soft\n"+
      "whisping of light.\n");
return 1;
}

remove_charge(){
write("The charge of the staff fades.\n");
say("The charge of the staff fades.\n");
charge = 0;
get_short();
return 1;
}


staff_heal(){
int heal;
MAGIC = check_magic();
if(check_wielded() == 0) return 0;
if(this_player()->query_sp() < 20){
notify_fail("You lack the power to heal yourself.\n");
return 0;
}
this_player()->add_spell_point(-20);
heal = (15*MAGIC)/20;
this_player()->add_hit_point(heal);
write("Energy flows from your hand into the staff.\nThe staff "+HIC+"COOLS"+NORM+" as healing energy surges into you.\n");
say(this_player()->query_name()+"'s staff glows "+HIC+"blue"+NORM+".\n");
return 1;
}

static staff_blast(str){
int dam;
string at_msg,vi_msg,rm_msg;
MAGIC = check_magic();
if(check_wielded() == 0) return 0;
if(!this_player()->query_attack()){
  notify_fail("You must be in combat to use blast.\n");
return 0;
}
if(this_player()->query_attack()->is_player()){
  notify_fail("You can not use this spell against players.\n");
return 0;
}
if(this_player()->query_spell_point() < 15){
  notify_fail("You lack the power to cast blast.\n");
  return 0;
}
at_msg = "You point the oak staff at "+this_player()->query_attack()->query_name()+".\nThe staff gleams as a "+HIG+"BLAST"+NORM+" of energy slams into "+this_player()->query_attack()->short()+".\n";
vi_msg = "A blast of "+HIG+"GREEN"+NORM+" energy smashes into you.\n";
rm_msg = this_player()->query_name()+" fires a blast of "+HIG+"GREEN"+NORM+" energy.\n";
dam = (30*MAGIC)/20;
this_player()->spell_object(this_player()->query_attack(),"blast",random(dam),15,at_msg,vi_msg,rm_msg);

return 1;
}


staff_light(){
int time;
MAGIC = check_magic();
if(check_wielded() == 0) return 0;
if(this_player()->query_sp() < 10){
notify_fail("You lack the power to light the staff.\n");
return 0;
}
this_player()->add_spell_point(-10);
set_light(1);
light = 1;
write("Energy flows from your hand into the staff.\nThe staff "+HIY+"GLEAMS"+NORM+" as light fills the room.\n");
say("Light fills the room.\n");
time = (700*MAGIC)/20;
call_out("light_stop",time);
get_short();
return 1;
}


light_stop(){
write("The light of the staff fades.\n");
say("The light of the staff fades.\n");
set_light(-1);
light = 0;
get_short();

}

get_short(){
string str;
str = "The "+MAG+"Magus"+NORM+" great oak staff";
if(light == 1){
  str += " ("+HIY+"lit"+NORM+")";
}
if(charge == 1){
  str += " ("+BLU+"charged"+NORM+")";
}
set_short(str);
set_long("This giant oak staff belongs to the magus.  There is a deep purple orb\n"+
"set upon the top held by a pewter dragon.  The tail swirls down along the\n"+
"staff making excellent grips.  The staff shimmers with power.  There is a\n"+
"small inscription carved into the staff.\n");
}

query_save_flag(){ return 1; }
