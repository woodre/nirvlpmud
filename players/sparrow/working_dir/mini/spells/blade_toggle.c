/*
 *  A toggle for the Blade line.  (v2.0)
 *
 */

blade_toggle()  {
object ob, ob2;
int flag_check;
  ob = present("blade_obj", TP);
  flag_check = ob->query_blade_flag();

  if(flag_check > 0)  {
    ob->set_blade_flag(0);
    write("You decide not to listen to your boasting companions.\n");
    return 1;
        }

  if(flag_check < 1)  {
    ob->set_blade_flag(1);  
    write("You decide that those braggarts might have something to say.\n");
    return 1;
        }
        }
