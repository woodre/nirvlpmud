inherit "/obj/weapon.c";
#include <ansi.h>
reset (arg)
{
  ::reset(arg);
  if(arg) return;

  set_name("avenger");
  set_alias("sword");
  set_short(HIW+"Pale"+HIC+" Justice"+NORM);
  set_long(
 CYN+"  The mighty blade "+HIW+"Pale"+HIC+" Justice"+NORM+CYN+".  The slender, five foot\n"+
 "blade blinds all that look at it.  It has been orged in \n"+
 "the heavens, and handed to the one person that is deserving\n"+
 "of the honor.  The gods of all that is good, created it to \n"+
 "be passed to a holy warrior so that they may vanquish the \n"+
 "many evils that plaque the land.  The hilt is wrapped with \n"+
 "an otherworld material, graning the wielder the power of the\n"+
 "light.  At the end of the hilt a tassel of "+HIY+"gold"+NORM+CYN+" hangs, adding\n"+
 "to the beauty of the blade.  The hilt is shaped like a cross\n"+
 "with a "+HIW+"pearl"+NORM+CYN+" at the end.\n"+NORM);
 
 
  set_type("sword");
  set_class(18);
  set_weight(3);
  set_value(5000);
  set_hit_func(this_object()); 
}

mixed
weapon_hit(object attacker) 
{
  
    if(random(20) > 18)
    {
     write(HIR+"\n\n            The souls trapped in the blade lash out\n");
     write(HIW+"            SIPHONING "+NORM+"the essence of the your foe.\n\n");
     say(HIR+"\n\n            The souls trapped in the blade lash out\n");
     say(HIW+"            SIPHONING "+NORM+"the essence of the your foe.\n\n");
     return 2;
    }
    if(random(20) >= 10)
    {
     write(HIB+"\n\n    From within the "+HIW+"pearl"+HIB+", the essence of the gods call forth an\n\n");
     write(YEL+BOLD+"           ~~~~~~~ L I G H T N I N G  B O L T ~~~~~~~\n\n");
     write(HIB+"            consuming your foe in a sea of fire.\n\n"+NORM);
     say(HIB+"\n\n    From within the "+HIW+"pearl"+HIB+", the essence of the gods call forth an\n\n");
     say(YEL+BOLD+"           ~~~~~~~ L I G H T N I N G  B O L T ~~~~~~~\n\n");
     say(HIB+"            consuming your foe in a sea of fire.\n\n"+NORM);
          return 4; 
    }
    if (random(10) <= 5)
    {
     write(HIM+"\n\n    As you bring down "+HIW+"Pale "+HIC+"Justice"+HIM+" the gods judge your foe\n\n");
     write("                        "+BLINK+HIW+" G    "+HIC+"Y\n");
     write("                        "+HIW+"  U  "+HIC+"T\n");
     write("                        "+HIW+"   I"+HIC+"L\n");
     write("                        "+HIC+"   I"+HIW+"L\n");
     write("                       "+HIC+"   U"+HIW+"  T\n");
     write("                       "+HIC+"  G   "+HIW+" Y\n\n"+NORM);
     write(HIR+"           as it CLEAVES through your foe.\n\n"+NORM);
     say(HIM+"\n\n    As you bring down "+HIW+"Pale "+HIC+"Justice"+HIM+" the gods judge your foe\n\n");
     say("                        "+BLINK+HIW+" G    "+HIC+"Y\n");
     say("                        "+HIW+"  U  "+HIC+"T\n");
     say("                        "+HIW+"   I"+HIC+"L\n");
     say("                        "+HIC+"   I"+HIW+"L\n");
     say("                       "+HIC+"   U"+HIW+"  T\n");
     say("                       "+HIC+"  G   "+HIW+" Y\n\n"+NORM);
     say(HIR+"           as it CLEAVES through your foe.\n\n"+NORM);

     return 5;
    }
    if (random (50) < 20)
    {
      write(HIY+"\n\n       The demon screams in agony as\n");
      write("            "+BWHT+BLU+"       |      "+NORM+"\n");
      write("            "+BWHT+BLU+"     |   |    "+NORM+"\n");
      write("            "+BWHT+BLU+"--HOLY LIGHT--"+NORM+"\n");
      write("            "+BWHT+BLU+"     |   |    "+NORM+"\n");
      write("            "+BWHT+BLU+"       |      "+NORM+"\n");
      write(HIY+"           burns their skin\n"+NORM);
      say(HIY+"\n\n       The demon screams in agony as\n");
      say("            "+BWHT+BLK+"       |      "+NORM+"\n");
      say("            "+BWHT+BLK+"     |   |    "+NORM+"\n");
      say("            "+BWHT+BLK+"--HOLY LIGHT--"+NORM+"\n");
      say("            "+BWHT+BLK+"     |   |    "+NORM+"\n");
      say("            "+BWHT+BLK+"       |      "+NORM+"\n");
      say(HIY+"           burns their skin\n"+NORM);
      return 1;
    }
}

  
