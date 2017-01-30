#pragma strict_types
#include <ansi.h>
#include "../RangerDefs.h"

/*  Allows players to blast objects for some guild power */
/*         --- by Cosmo on 2/21/97 ---                   */

/* addition 2003.03.21 -Forbin added color based on ranger ansi */

#define ROOM_OB present(str,environment(this_player()))
#define INV_OB present(str,this_player())

status
RangerPower(string str, string type)
{
  object ob;
  int val;
  int val2;
  if(!str)
  {
    tell_object(this_player(),
      "Zordon tells you: \"What do you want to blast?\"\n");
    return 1;
  }
  if(!ROOM_OB && !INV_OB)
  {
    tell_object(this_player(),
      "Zordon tells you: \"That is not present to be blasted.\"\n");
    return 1;
  }
  if(str == "scroll")
  {
    tell_object(this_player(),
      "Zordon tells you: \"Sorry no more donating miniguild scrolls.\"\n");
    return 1;
  }
/*  No more Power Cap --Vital Friday, July 6, 2007
  if(MASTER->QPowerPoints(type) > 17249)
  {
    tell_object(this_player(),
      "Zordon tells you: \"Guild Power is Full already.\"\n");
    return 1;
  }
*/
  if(this_player()->query_level() > 19 && this_player()->is_player())
  {
    tell_object(this_player(),
      "Zordon tells you: \"Stop trying to help the players.\"\n");
    return 1;
  }
  if (ROOM_OB)
  {
    if(!ROOM_OB->get() || living(ROOM_OB))
    {
      tell_object(this_player(),
        "Zordon tells you: \"You can't blast that!\"\n");
      return 1;
    }
    if(ROOM_OB->query_weight() > 100)
    {
      tell_object(this_player(),
        "Zordon tells you: \"You can't blast that!\"\n");
      return 1;
    }
    ob = ROOM_OB;
  }
  else if (INV_OB)
  {
    if (INV_OB->drop() > 0)
    {
      tell_object(this_player(),
        "Zordon tells you: \"You can't blast that!\"\n");
      return 1;
    }
    ob = INV_OB;
    say(this_player()->query_name() + " drops the " + str +
      " on the ground and takes aim.");
    say("\n");
    write("You set the " + str + " on the ground.");
    write("\n");
  }
  if(!ob) return 1;
  val = (int) ob->query_value();
  if(val > 4000)
  {
    val = 4000;
  }
  val2 = ((val)/20);
  val2 += random((val)/10);
  if(val2 < 5)
  {
    val2 = 5;
  }
  if(val == 0){ val2 = 0; }
  if(str == "corpse")
  { 
    val2 = ((int) ob->query_exp_worth() / 4000 + ( (int)ob->heal_value() * 3 ));
    if( val2 > 1000 )
          val2 = 1000; 
  }
  MASTER->APowerPoints(val2,type);

  say(this_player()->query_name() + " draws " +
    this_player()->query_possessive() + 
    " blaster, pulls the trigger, and disintegrates\nthe "+str+" with a"+
    " single pulse of "+COMM->QRangerAnsi()+COMM->COLOR+" light"+OFF+".");
  say("\n");
  write("You pull out your blaster and with one swift motion, you blow the\n"+
    str+" into smithereens.\n");
  tell_object(this_player(),
    "Zordon tells you: \"You have donated " + val2 +
    " Power Points to the Guild.\"\n");
  destruct(ob);
  return 1;
}

int
QMax(){ return 1; }

status
QRangerInfo() { return 1; }

status
RangerInfo()
{
  write("\
  The Power Rangers\' skills are fueled by power generated and \n\
donated by the members themselves.  As a Power Ranger its your \n\
duty and call to donate things for power when you can to help \n\
support the continuing battle to vanquish all evil from the galaxy.\n\n\
Syntax:\n\
  donate <item>       <item> can be a corpse or most any object with\n\
                      a worth greater than 5.\n\n");
  return 1;
}
