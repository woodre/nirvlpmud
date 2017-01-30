#include "/players/catacomb/saiyan/def.h"

Score()
{
  write(HIY+"]====================================["+NORM+"\n");
  write(HIW+TPN+", the Saiyan Warrior\n");
  write("Level "+LVL+"+"+XLVL+"\n");
  write("HP "+HP+"/"+MHP+"  MP "+SP+"/"+MSP+"      I["+TOX+"%]\n");
  write("Experience:"+XP+"          F["+STUFF+"%]\n");
  write("Money:"+CASH+"                 S["+SOAK+"%]\n"); 
  write("\n");
  write("Type '"+RED+"saiyan"+HIW+"' for help\n"+NORM+"\n");
  write(HIY+"]====================================["+NORM+"\n");
  return 1;
}  