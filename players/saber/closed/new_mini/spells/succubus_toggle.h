/*
 *  A toggle for the succubus line.  (v2.0)
 *
 */

succubus_toggle()  {
object ob, ob2;
int flag_check;
  ob = present("succubus_obj", TP);
  flag_check = ob->query_succubus_flag();

  if(flag_check > 0)  {
    ob->set_succubus_flag(0);
    write("You will no longer hear the sweet whispers of your sisters...\n");
    return 1;
        }

  if(flag_check < 1)  {
    ob->set_succubus_flag(1);  
    write("You will again hear the sweet whispers of your sisters...\n");
    return 1;
        }
        }
