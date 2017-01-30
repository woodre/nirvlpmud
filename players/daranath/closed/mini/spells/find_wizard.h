/*
 *  A spell that will tell a player what wizards are on (visible only)
 *  For the Servants of Larn version 2.0
 *
 */

find_wizard()  {

  int b;
  object ob;

  ob = users();

  write("\n**************************************");
  write("\n* Deities within the Realms of Magic *");
  write("\n**************************************");
  write("\n*                                    *");
  write("\n");

  for(b=0; b<sizeof(ob); b+=1)   {
  if(ob[b]->query_invis() == 0)  {
  if(ob[b]->query_level() > 20)  {

  write("*     ");
  write(pad(ob[b]->query_name(),31));
  write("*\n");
        }
        }
        }

  write("*                                    *");
  write("\n**************************************\n");
  return 1;
        }
