/*
 *  A toggle for the Kender Kin line.  (v2.0)
 *
 */

kender_toggle()  {
object ob, ob2;
int flag_check;
  ob = present("kender_obj", TP);
  flag_check = ob->query_kender_flag();

  if(flag_check > 0)  {
    ob->set_kender_flag(0);
    write("You stuff wax into your ears.\n");
    return 1;
        }

  if(flag_check < 1)  {
    ob->set_kender_flag(1);  
    write("You remove the wax from your ears.\n");
    return 1;
        }
        }
