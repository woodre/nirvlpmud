/*
 *  A toggle for the Goth Kin line.  (v2.0)
 *
 */

gothic_toggle()  {
object ob, ob2;
int flag_check;
  ob = present("gothic_obj", TP);
  flag_check = ob->query_gothic_flag();

  if(flag_check > 0)  {
    ob->set_gothic_flag(0);
    write("You renounce your standing within the gothic community.\n"+
        "You will no longer hear your Gothic kin recite.\n");
    return 1;
        }

  if(flag_check < 1)  {
    ob->set_gothic_flag(1);  
    write("You reclaim your standing within the gothic community.\n");
    return 1;
        }
        }
