#include "../defs.h"

status main(string str, object PO, object User)
{
  TOU " You commune with "+BOLD+CAP((string)PO->query_symbiote())+""+NORM+"....\n\n"+
      " You are filled with knowledge of the following abilities:\n"+
      " "+BOLD+"Power:           Level:"+NORM+"\n"+
      " "+HIB+"fixit"+NORM+"          "+HIW+"    -      - Report a bug, typo, recommendation to Fred."+NORM+"\n"+
      " "+HIB+"absorb"+NORM+"             "+HIW+"-      - Absorb a corpse into your link giving it energy."+NORM+"\n"+
      " "+HIB+"fatal"+NORM+"          "+HIW+"    -      - A fatal to finish your opponent."+NORM+"\n");
  if(User->QL > 4)
    TOU " "+HIB+"changeform"+NORM+"         "+HIW+"5      - Allows you to become one with your symbiotic link."+NORM+"\n");
  if(User->QL > 6)
    TOU " "+HIB+"webslam"+NORM+"            "+HIW+"7      - Momentarily capture a target and do some damage\n"+
        "                             to them with a slam."+NORM+"\n");
  if(User->QL > 7)
    TOU " "+HIB+"link"+NORM+" "+BOLD+"<power>"+NORM+"       "+HIW+"8+     - Numerous powers that allow you to call on your\n"+
        "                             symbiotic link for assistance. Use link alone to\n"+
        "                             see a full listing."+NORM+"\n");
  if(User->QL > 11)
    TOU " "+HIB+"bite"+NORM+"              "+HIW+"12      - A series of damaging bites."+NORM+"\n");
  if(User->QL > 13)
    TOU " "+HIB+"web"+NORM+"               "+HIW+"14      - Will freeze a monster in place with a sticky web."+NORM+"\n");
  if(User->QL > 14)
    TOU	" "+HIB+"threat"+NORM+"            "+HIW+"15      - The threat list of current pkers on."+NORM+"\n"+
        " "+HIB+"webslam <#>"+NORM+"       "+HIW+"15      - Same as the old, but use a number up to 40 in sps\n"+
        "                             to increase its power."+NORM+"\n");
  if(User->QEL > 7)
    TOU	" "+HIB+"hypermode"+NORM+"         "+HIW+"19+8    - A frenzied series of dangerous attacks."+NORM+"\n");
  
  TOU "      "+BOLD+"---------------------------------------------------"+NORM+"\n"+
      " "+HIB+"supplant"+NORM+"                  "+HIW+"- Allows you to speak normally while changed."+NORM+"\n"+
      " "+HIB+"save"+NORM+"                      "+HIW+"- Guild save."+NORM+"\n"+
      " "+HIB+"rip_out_symbiote"+NORM+"          "+HIW+"- Will remove you from the guild with a great\n"+
      "                             deal of pain involved."+NORM+"\n"+
      " "+HIB+"mp"+NORM+"                        "+HIW+"- Will give current MP"+NORM+"\n");
  return 1;
}
