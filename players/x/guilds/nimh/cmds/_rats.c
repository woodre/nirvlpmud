#include "../x.h"

inherit N_EFUN;

#define doodad   "       ^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^" 

string old_last;
string lastime;
int    level;

int cmd_rats(string str)
{
 string *q, z, j, glc, ghc;
 int x, y;
 object c;

 if(str) return 0;
 ghc = gen_hi_color();
 glc = gen_lo_color();
 y = sizeof(q = get_dir("/"+N_SAVE));

 write("\n"+glc+doodad+NORM+"\n");
 write("\n");
 write("\t\t\tThe "+ghc+"Rats"+NORM+" of "+ghc+"NIMH"+NORM+"\n");
 write("\n");
 write(glc+doodad+NORM+"\n");
 write("\n");
 for(x = 0; x < y; x ++)
 {
  old_last = 0; lastime = 0; level = 0;
  if(sscanf(q[x],"%s.o",z))
  {
   if(!restore_object("pfiles/"+z[0..0]+"/"+z))
    continue;
/*
   z = upper_case(z);
*/
   z = capitalize(z);
   write(" .. "+pad(z,13,'.')+" ");
   c = find_player(lower_case(z));
   if((c && !c->query_invis()) || 
       (c && c->query_invis() && (int)c->QL && (int)TP->QL) &&
       sscanf((string)c->query_lastime(), "%s to %s", j,j)==2)
     write(".. "+HIG+"On Since:"+NORM+" "+(string)c->query_lastime()+".\n");
   else if(c && c->query_lastime())
    write(".. "+RED+" Last On:"+NORM+" "+(string)c->query_lastime()+".\n");
   else if(level > 20 && old_last)
    write(".. "+RED+" Last On:"+NORM+" "+old_last+".\n");
   else
    write(".. "+RED+" Last On:"+NORM+" "+lastime+".\n");
  }
 }
 write("\n");
 write(glc+doodad+NORM+"\n\n");
 return 1;
}
