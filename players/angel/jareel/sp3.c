#include "/players/jareel/ansi.h"
#include "/players/jareel/define.h"
inherit "/obj/weapon.c";

int light;
int bladesharp;
int energize;
int moonglow;
int MAGIC;
id(str) { return str=="sword" || str=="scimitar"; }

reset(arg){
   ::reset(arg);
   if(arg) return 1;
   
   set_alt_name("scimitar");
   get_short();
   set_class(17);
   set_type("sword");
   set_weight(2);
   set_value(8000);
   set_long(
      "\n"+
      "\n"+
      "\n"+
      "\n");
   
   set_read("\n"+
      ""+RED+"We have enchanted your weapon with several powers, may the Red-Goddess guide your blade.\n\n"+
      "   "+BOLD+MAG+"moonglow"+NORM+"           10sp\n"+
      "   "+BOLD+MAG+"storm"+NORM+"              25sp\n"+
      "   "+BOLD+MAG+"bladesharp"+NORM+"         50sp\n"+
      "               -"+RED+"The Creator Makers"+NORM+"\n"+ 
      "\n");
   
   wield(str)
   {
      if(!id(str)) return 0;
      if(wield) return 0;
      if(this_player()->query_extra_level() < 20){
         write("Your not expierienced enough yet.\n");
         return 1;
         }
      ::wield(str);
      write("You wield the scimitar.\n");
      return 1;
   }
   
   set_hit_func(this_object());
}

weapon_hit(attacker){
   int i;
   if(energize != 1){
      return 0;
   }
   
   i = random(14);
   if(i<5){
      tell_room(environment(this_player()),
         "\n\n"+
         CYN+BLINK+" E N E R G Y"+NORM+" flows over the blade.\n\n");
      return 7;
   }
   if(i==13){
      write("\nThe scimitar's"+BOLD+MAG+" scarlet sheen pulsates"+NORM+" as it slashes into "+this_player()->query_attack()->query_name()+".\n\n");
      return 8;
   }
}

init(){
   ::init();
   add_action("moon_glow","moonglow");
   add_action("sword_blast","storm");
   add_action("bladesharp","bladesharp");
   
   
}

check_wielded(){
   if(this_player()->query_weapon() == this_object()){
      return 1;
   }
   else {
      notify_fail(BOLD+"You must be wielding the sword to use its powers.\n"+NORM);
      return 0;
   }}

check_magic(){
   int i;
   i = this_player()->query_attrib("int");
   if(i > 20) i = 20;
   if(i < 0) i = 0;
   return i;
}

bladesharp(){
   int time;
   MAGIC = check_magic();
   if(check_wielded() == 0) return 0;
   if(this_player()->query_spell_point() < 50){
      notify_fail(BOLD+"You lack the energy to charge the scimitar.\n"+NORM);
      return 0;
   }
   
   this_player()->add_spell_point(-50);
   energize = 1;
   
   get_short();
   time = ((500+random(500))*MAGIC)/20;
   call_out("remove_energy",time);
   write("\nYou invoke the bladesharp matrix.\n\n"+
      "        "+CYN+BLINK+"E N E R G Y "+NORM+"flows over your blade.\n\n");
   return 1;
}

remove_energy(){
   write("The scimitar's glow fades.\n");
   say("The glow from the scimitar fades.\n");
   energize = 0;
   get_short();
   return 1;
}


static sword_blast(str){
   int dam;
   string at_msg,vi_msg,rm_msg;
   MAGIC = check_magic();
   if(check_wielded() == 0) return 0;
   if(!this_player()->query_attack()){
      notify_fail(BOLD+"You must be in combat to summon the storm.\n"+NORM);
      return 0;
   }
   
   if(this_player()->query_spell_point() < 25){
      notify_fail(BOLD+"You lack the energy to call the storm.\n"+NORM);
      return 0;
   }
   
   at_msg = ""+BOLD+"The legendary spear of Yelm unleashes itself...."+NORM+"\n\n"+
   "                                                       "+BOLD+HIY+" ,___  ____"+NORM+"\n"+
   "            "+YEL+".__________________    ______________    "+BOLD+HIY+"__/   /__\\  '\\"+NORM+"\n"+ 
"            "+YEL+"||_"+HIY+"\\"+NORM+YEL+"_"+HIY+"\\"+NORM+YEL+"_"+HIY+"\\"+NORM+YEL+"_"+HIY+"\\\\"+NORM+YEL+"________"+MAG+"|==|"+YEL+"__"+HIY+"\\"+NORM+YEL+"__"+HIY+"\\"+NORM+YEL+"__"+HIY+"\\"+NORM+YEL+"_____"+MAG+"|==|"+BOLD+HIY+"__ "+RED+"- --"+HIY+"___"+RED+" --"+BOLD+HIY+" >"+NORM+"     \n"+
"                                                       "+BOLD+HIY+"\\___\\  /__,/"+NORM+" \n"+
"\n\n\n"+BOLD+"                                                 .........Solar energy burns flesh"+NORM+"\n\n";
vi_msg = "A swarm of meteors smashes into you.\n";
rm_msg = this_player()->query_name()+" invokes crimson runes, energy flows over the blade.\n";
dam = (random(25)+10);
this_player()->spell_object(this_player()->query_attack(),"blast",dam,28,at_msg,vi_msg,rm_msg);

return 1;
}

moon_glow(){
int time;
MAGIC = check_magic();
if(check_wielded() == 0) return 0;
if(this_player()->query_sp() < 10){
notify_fail("You lack energy to use this power.\n");
return 0;
}

this_player()->add_spell_point(-10);
set_light(1);
light = 1;
write("The sword glows an eerie scarlet glow\n");
say("Light fills the room.\n");
time = (1200*MAGIC)/20;
call_out("light_stop",time);
get_short();
return 1;
}

light_stop(){
write("The "+BOLD+MAG+"Scarlet Scimitar"+NORM+" glow shimmers and fades.\n");
say("The glow of the "+BOLD+MAG+"Scarlet Scimitar"+NORM+" fades.\n");
set_light(-1);
light = 0;
get_short();
}

get_short(){
string str;
str = ""+BOLD+MAG+"Scarlet Scimitar"+NORM+"";

if(light == 1){
  str += ""+HIK+"  ["+BOLD+MAG+" Glowing "+BOLD+HIK+"]"+NORM+"";
}

if(energize == 1){
  str += ""+RED+" [ "+CYN+" Energized "+RED+" ]"+NORM+"";

}
set_short(str);
}
