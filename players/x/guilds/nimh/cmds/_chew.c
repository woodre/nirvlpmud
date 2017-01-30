#include "../x.h"

int cmd_chew(string str)
{
 object ob, x;
 if(!str)
 {
  write("Usage: 'chew <item>'\n");
  return 1;
 }

 if(!(ob = present(str, TP)) || !ob->short())
 {
  write("You may only chew items in your inventory.\n");
  return 1;
 }

 if(ob->drop())
 {
  write("You may not chew that.\n");
  return 1;
 }

 if(ob->query_nimh_chewed())
 {
  write("That item has already been significantly chewed.\n");
  return 1;
 }

 write("You grab ahold of "+(string)ob->short()
  +" and chew on it quite rapidly.\n");
 say((string)TP->QN+" pulls "+(string)ob->short()+" up to "+possessive(TP)
  +"  mouth and chews on it quite rapidly.\n");

 x = clone_object(N_OBJ+"chew_shadow");

 x->start_shadow(ob);

 write("You have made your mark upon "+(string)ob->short()+".\n");
 return 1;
}
