/*
 *  A toggle for the Servents of Larn line.  (v2.0)
 *
 */

larn_toggle()  {
object ob, ob2;
int flag_check;
  ob = present("larn_obj", TP);
  flag_check = ob->query_larn_flag();

  if(flag_check > 0)  {
    ob->set_larn_flag(0);
    write("You close your mind to the universe...\n");
    return 1;
        }

  if(flag_check < 1)  {
    ob->set_larn_flag(1);  
    write("You open your mind to the universe...\n");
    return 1;
        }
        }
