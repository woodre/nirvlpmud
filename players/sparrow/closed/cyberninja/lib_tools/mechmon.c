#include "../DEFS.h"


status main(string str)
{
  /* An enhancement to show if mech is alive or lost.
     Also allows retrieval of lost mechs. */
  object mech;
  string msg;

  if (!IPTP->item_mechmon()) return 0;

  if (!str)
  {
    write("Usage: mechmon [info|beamin]\n");
    return 1;
  }

  str = lower_case(str);
  mech = find_living("mech"+TP->query_real_name());

  if (str != "info" && str != "beamin")
  {
    write("Usage: mechmon [info|beamin]\n");
    return 1;
  }

  if (!mech)
  {
    write("You do not have a mech.\n");
    return 1;
  }

  if (str == "info")
  {
    msg = "You have a "+BOLD+mech->query_name()+OFF+" mech.\n";
    if (present(mech, environment(TP)))
    {
      msg += "Your mech is with you.\n";
    }
    else
    {
      if (environment(mech) && environment(mech)->short())
      {
        msg += "Your mech is located at:  "+environment(mech)->short()+"\n";
      }
      else
      {
        msg += "Your mech is lost somewhere.\n";
      }
    }
  }

  if (str == "beamin")
  {
    if (present(mech, environment(TP)))
    {
      msg += "Your mech is already with you.\n";
    }
    else
    {
      move_object(mech, environment(TP));
      msg = "You type in several coordinates on your monitor keypad.\n"+
            "Within moments, a semi-translucent haze erupts out of a\n"+
            "thunderous wormhole burst.\n"+
            YELLOW+"Your mech beams in!"+OFF+"\n";
    }
  }

  write(msg);

  return 1;
}
