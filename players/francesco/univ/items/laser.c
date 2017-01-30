#include "/players/francesco/univ/ansi.h"
inherit "obj/weapon";
int delay;
int actual_time;
string str;
short() {
   string tmp_short;
    if(this_player())
    if (call_other(this_player(), "query_level", 0) > 30) {
      tmp_short = short_desc + "  < wc " + class_of_weapon + ","+eff_wc + " >";
   if (broke) tmp_short = short_desc + " [BROKEN]";
      if (wielded)
         return tmp_short + " (powered on)";
      return tmp_short;
     }
 if(wielded && broke) return short_desc + " [BROKEN] (powered on)";
 if(broke) return short_desc + " [BROKEN]";
    if (wielded)
        if(short_desc)
            return short_desc + " (powered on)";
    return short_desc;
}
long() {
   int wear;
   if (environment() && !living(environment())) 
  {
  write("Just a small tube, with a little orifice at one end.  It shows also\n"+
        "some engravings on it: 'Laser beam, caution'.  You feel like you\n"+
        "could 'grab' it, but it might be very dangerous.\n");
        return 1;
  }
else write("The little container of this portable laser shows three buttons\n"+
       "on it:  the "+HIG+"green"+NORM+" one is for 'power on', the "+HIR+"red"+NORM+" one is for \n'power off' "+
       "while the "+HIY+"yellow"+NORM+" one can be used for 'trigger' and \nthus likely give extra hits. "+
       "It might be a very deadly tool if \nthe proper functions were used.\n");
        wear=query_wear();
        if(wear < 40) write("It is completely functional.\n");
        if(wear > 39 && wear < 100) write("It is well effective.\n");
        if(wear > 99 && wear < 200) write("It still works well.\n");
        if(wear > 199 && wear < 400) write("It often misses its functionality.\n");
        if(wear > 399) write("It should be repaired soon.\n");

       return 1;
}



reset(arg){
  ::reset(arg);
  if (arg) return;
   
message_hit = ({
	"pulverized"," into a pile of dust",
	"cut"," into thin slices",
	"vaporized","'s leg",
	"melted","'s arm",
        "eroded","'s hand",
	"burned","'s skin",
	"made"," blind for a second",
	});

set_name("laser");
set_alias("laser");
set_alt_name("laser");
set_short(""+HIW+"A portable LASER"+NORM);

set_type("sword");
  set_class(18);
  set_weight(2);
  set_value(2500);
  /* converted to laser damage by illarion may 05
  set_hit_func(this_object());
  */
  set_params("other|laser",0,"laser_hit");
}



laser_hit(attacker){
int W;
W = random(13);
if(W>9)  {
say(
HIW+
"\n        ZZZZZ   OOOOOOO   TTTTTTTT\n"+
  "          ZZ   OO     OO     TT\n"+
  "         ZZ   OO       OO    TT\n"+
  "        ZZ     OO     OO     TT\n"+
  "       ZZZZZ    OOOOOOO      TT\n\n"+NORM);
write(
HIW+
"\n        ZZZZZ   OOOOOOO   TTTTTTTT\n"+
  "          ZZ   OO     OO     TT\n"+
  "         ZZ   OO       OO    TT\n"+
  "        ZZ     OO     OO     TT\n"+
  "       ZZZZZ    OOOOOOO      TT\n\n"+NORM);
  this_player()->add_spell_point(-2);
  return 7;
   }


if(W<1)  {
say(
HIR+
"\n        ZZZZZ     TTTTTTTT\n"+
  "          ZZ         TT\n"+
  "         ZZ          TT\n"+
  "        ZZ           TT\n"+
  "       ZZZZZ         TT\n\n"+NORM);
write(
"\n        ZZZZZ     TTTTTTTT\n"+
  "          ZZ         TT\n"+
  "         ZZ          TT\n"+
  "        ZZ           TT\n"+
  "       ZZZZZ         TT\n\n"+NORM);
  this_player()->add_spell_point(-1);
  return 4;
   }
return;
}




init() {
 
add_action("grab_object", "grab");
if(this_player() != environment(this_object())) 
  return; 

  add_action("trigger","trigger");
  add_action("power","power");
/*  add_action("poweroff");
  add_verb("poweroff");
  add_action("poweron","wield");
  add_action("poweroff","unwield");
*/
}

query_wear() {
  int wear;
  wear = 4*misses/4 + 5*hits/18;
  return wear;
}

power(str) {
   if(present("notweapon", this_player())){ write("You are not allowed to use weapons.\n"); return 1; }
   if(!str) {write("Power on or Power off?\n");return 1;}
   if(str=="on")
   {
      if(this_player()->query_level() < 7) { 
         write("I am sorry, You are not high enough level to use this powerful laser.\n"); 
      return 1; }

    if (wielded) {
        write("You have already powered the laser on!\n");
        return 1; }

    if(wield_func)
        if(!call_other(wield_func,"wield",this_object())) 
            return 1;
    wielded_by = this_player();
  /* weapon param passing added by illarion may 05 */
    call_other(this_player(), "wield", this_object(),silentwield,params);
    wielded = 1;
    write("You push the green button of your laser and it is then powered on.\n");
    say(this_player()->query_name()+" pushes the green button of the laser and it is powered on.\n");
    return 1;
   }  
   if(str=="off")
   {
   if (environment() != this_player()) return 0;
   if (!wielded) {write("Your laser hadnt powered on yet!\n");return 1;}
   call_other(this_player(), "stop_wielding");
       wielded = 0;
       wielded_by = 0;
    write("You push the red button of your laser and it is then powered off.\n");
    say(this_player()->query_name()+" pushes the red button of the laser and it is powered off.\n");

   return 1;
   }  
}

trigger(str) {
  
  
  
  object attacker;
  attacker=this_player()->query_attack();
  
  if(wielded == 0) { write("Please, power on the laser before using the yellow button\n"); 
  return 1; }
  
  if(this_player()->query_sp() < 2) { write("You are out of spell points, please heal yourself\n"); 
  return 1; }
  
  if(!attacker) { write("You aren't fighting anybody!\n"); 
  return 1; }

  actual_time = time();
  if(actual_time - delay <= 1)
  return 1;
    if(this_player()->query_spell_dam()) { write("You are already using energy to power a spell.\n"); return 1; }

  this_player()->spell_object(attacker,"laser blast",random(13)+4,9,
        "You push the yellow button of your laser and its\n"+
        "power is temporarily raised by 50 watts.\n","You are hit by a laser.\n",
        this_player()->query_name()+" pushes the yellow button of the laser and\n"+
        attacker->query_name()+" is hit by an amplified laser beam.\n");


/*   
  write("\nYou push the yellow button of your laser and its\n"+
        "power is temporarily raised by 50 watts.\n\n");
  say(this_player()->query_name()+" pushes the yellow button of the laser.\n");
  
  attacker->heal_self(-random(13)-4); 

  this_player()->add_spell_point(-9);
*/
  delay = time();
  return 1; }


get() { 
       object ob;
       if(!environment()) return 1;
       ob = present("mike", environment()); 
       if(!ob) return 1; 
       write("The laboratory technician yells:  \n"+
              "You are not entitled to use that laser!\n");
       ob->attack_object(this_player());
        return 0;
      }

grab_object(str) {
       if(!str) { notify_fail("Grab what?\n"); return 0; }
         command("get "+str, this_player());
       return 1; 
      }
