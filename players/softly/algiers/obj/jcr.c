#include "/players/softly/closed/ansi.h"
inherit "/obj/treasure.c";

int x, etime;
string emote;
object seeker;

reset(arg)
{
  if(arg) return;

  set_id("jcroot");
  set_short("John the Conqueror Root");
  set_alias("root");
  set_long("\This fresh John the Conqueror root has\n\
gnarled appearance but a spicy fragrance of cedarwood,\n\
cinnamon, and nutmeg.  You need only carry it, but it's\n\
effects are limited.\n");
  set_weight(1);
  set_value(350);

}

init() 
{ 
  ::init(); 
  if(!etime && environment() && environment()->is_player())
  { 
      etime = time();
      call_out("ego_boost", 6, environment());
  } 
}

ego_boost(object seeker)
{
  if(!seeker)
    {
      destruct(this_object());
      return;
    }
  if(time() > (etime + 600))
    {
      tell_object(seeker, "The root has worn out.  It vaporizes.");
      destruct(this_object());
      this_player()->recalc_carry();     
      return; 
    }

  switch(random(10))
    {
    case 0: emote ="\n\n"+
              "\tYour muscles swell and bulge.  You feel\n"+
	      "\tstronger, and strangely more powerful.\n\n";
    break;
      
    case 1: emote ="\n\n"+
              "\tYour attractiveness increases.  Your flesh glows\n"+
	      "\tand there is a slight flush to your body.\n\n";
    break;

    case 3: emote ="\n\n"+
              "\tThere is increased tension in your loins.\n\n";
    break;
    
    case 4: emote ="\n\n"+
              "\tYou feel the need to abandon fighting and seek\n"+
	      "\tout the company of someone attractive to you.\n\n";
    break;

    case 5: emote ="\n\n"+
              "\tYou breathe more quickly, tasting the air.\n\n";
    break;

    case 6: emote ="\n\n"+
              "\tYou lick your pouting lips. They twitch\n"+
	      "\tlongingly, seeking.\n\n";
    break;

    case 7: emote ="\n\n"+
              "\tYour hands open and close quickly.  Your\n"+
	      "\tmuscles tense, urgently seeking release.\n\n";
    break;

    case 8: emote ="\n\n"+
              "\tSmall beads of moisture appear on your face\n"+
	      "\tand your body.\n\n";
    break;

    case 9: emote ="\n\n"+
              "\tPressure builds in your groin.\n\n";
    break;
    }

  tell_object(seeker, emote);
  x = random(60);
  call_out("ego_boost",x, seeker);

}

drop() { return 1; }
get() { return 1; }
