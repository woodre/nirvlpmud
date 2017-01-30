#include "/players/fred/defines.h"
#define cown cow->query_name()
#define PRO TP->query_pronoun()
inherit "/obj/weapon.c";

reset (arg) {
  ::reset(arg);
  if(arg) return;

  set_name("saber");
  set_short("Saber of "+RED+"Bloodletting"+NORM);
  set_long(
 "  A large wicked looking saber with a long arched blade.\n"+
 "Small symbols are carved into the handle which is formed\n"+
 "from finely crafted marble which adds to its weight.\n");
  set_type("sword");
  set_class(18);
  set_weight(3);
  set_value(2100);
  set_hit_func(TO);
  }
  weapon_hit(cow){
   int q;
   q = random(200);
   if(q > 14){
     int b, p, z;
     string squishy, gooie;
     b = random(10);
     p = random(10);
     z = environment(this_object())->query_level();
     z /= 3;
      switch(b){
       case 0: squishy = " cuts deeply into "+capitalize(cown)+"'s flesh."+NORM+""; break;
       case 1: squishy = " gouges "+capitalize(cown)+" leaving deep gashes."+NORM+""; break;
       case 2: squishy = "'s eyes fill with rage as "+PRO+" attacks "+capitalize(cown)+"!"+NORM+""; break;
       case 3: squishy = " grins wickedly as "+POS+" saber strikes a devastating blow."+NORM+""; break;
       case 4: squishy = " lets out a loud yell as the saber slices through the air."+NORM+""; break;
       case 5: squishy = " slices frantically at "+capitalize(cown)+" in a brilliant display of fighting."+NORM+""; break; 
       case 6: squishy = " laughs demonically."+NORM+""; break;
       case 7: squishy = " wipes some splattered blood off his brow."+NORM+""; break;
       case 8: squishy = " sneers at "+capitalize(cown)+NORM+""; break;
       case 9: squishy = " spins the saber around with deadly grace."+NORM+""; break; }
      switch(p){
       case 0: gooie = " cut deeply into "+capitalize(cown)+"'s flesh."+NORM+""; break;
       case 1: gooie = " gouge "+capitalize(cown)+" leaving deep gashes."+NORM+""; break;
       case 2: gooie = "r eyes fill with rage as you attack "+capitalize(cown)+"!"+NORM+""; break;
       case 3: gooie = " grin wickedly as your saber strikes a devastating blow."+NORM+""; break;
       case 4: gooie = " let out a loud yell as the saber slices through the air."+NORM+""; break;
       case 5: gooie = " slice frantically at "+capitalize(cown)+" in a brilliant display of fighting."+NORM+""; break; 
       case 6: gooie = " laugh demonically."+NORM+""; break;
       case 7: gooie = " wipe some splattered blood off your brow."+NORM+""; break;
       case 8: gooie = " sneer at "+capitalize(cown)+NORM+""; break;
       case 9: gooie = " spin the saber around with deadly grace."+NORM+""; break; }
     write(BOLD+BLK+"You"+gooie+"\n");
     say(BOLD+BLK+TPN+squishy+"\n");
     return (1+random(z));
    }
   if(q < 15){
     if(!present("happyfamilygoodtime", cow)){
       write(BOLD+BLK+"     You plummet your Saber deep into "+NORM+YEL+capitalize(cown)+"'s "+NORM+BOLD+BLK+"stomach\n");
       write("           leaving a large open "+NORM+RED+"wound"+NORM+BOLD+BLK+"."+NORM+"\n");
       say("     "+BOLD+BLK+TPN+" plummets "+POS+" Saber deep into "+NORM+YEL+capitalize(cown)+"'s "+NORM+BOLD+BLK+"stomach\n");
       say("             leaving a large open "+NORM+RED+"wound"+NORM+BOLD+BLK+"."+NORM+"\n");
       MO(CO("players/fred/misc/wound.c"), cow);
     return (1+random(q));
    }
   }
  }
