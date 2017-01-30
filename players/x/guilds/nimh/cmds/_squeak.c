#include "../x.h"
int cmd_squeak(string str)
{
 object ob;

 if(TP->query_ghost()) return 0;

 if(!str)
 {
  write("You squeak impatiently.\n");
  say((string)TP->QN+" squeaks impatiently.\n");
  return 1;
 }

 if(!(ob = find_player(str)) || ((int)ob->query_invis() > (int)TP->QL))
 {
  write(CAP(str)+" is not logged into Nirvana.\n");
  return 1;
 }

 if(ob == TP || !ENVTP) return 0;

 if(in_editor(ob))
 {
  write(CAP(str)+" is busy editing.\n");
  return 1;
 }

 TL(ob,(string)TP->QN+" squeaks impatiently at you from afar.\n"+
       CAP(subjective(TP))+" seems to be waiting at: "+
       ENVTP->short()+".\n");

 write("You squeak impatiently at "+CAP(str)+" from afar.\n");

 return 1;
}

