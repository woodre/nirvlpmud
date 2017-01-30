/*
 *  A toggle for the Gypsy Kin line.  (v2.0)
 *
 */

gypsy_toggle()  {
object ob, ob2;
int flag_check;
  ob = present("gypsy_obj", TP);
  flag_check = ob->query_gypsy_flag();

  if(flag_check > 0)  {
    ob->set_gypsy_flag(0);
    write("You turn your medallion so that the runes face towards you.\n");
    return 1;
        }

  if(flag_check < 1)  {
    ob->set_gypsy_flag(1);  
    write("You turn your medallion so that the runes face away from you.\n");
    return 1;
        }
        }
