/*
 *  A toggle for the feline line.  (v2.0)
 *
 */

meow_toggle()  {
object ob, ob2;
int flag_check;
  ob = present("meow_obj", TP);
  flag_check = ob->query_meow_flag();

  if(flag_check > 0)  {
    ob->set_meow_flag(0);
    write("You stop listening to the caterwauling of the felines...\n");
    return 1;
        }

  if(flag_check < 1)  {
    ob->set_meow_flag(1);  
    write("You again hear the caterwauling of the felines.\n");
    return 1;
        }
        }
