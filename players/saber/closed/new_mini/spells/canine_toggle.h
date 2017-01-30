/*
 *  A toggle for the CanineKin line.  (v2.0)
 *
 */

canine_toggle()  {
object ob, ob2;
int flag_check;
  ob = present("canine_obj", TP);
  flag_check = ob->query_canine_flag();

  if(flag_check > 0)  {
    ob->set_canine_flag(0);
write("You lower your head to the ground, covering your ears with your paws.\n");
    return 1;
        }

  if(flag_check < 1)  {
    ob->set_canine_flag(1);  
write("Perking your ears up, you begin listening for other Canines.\n");
    return 1;
        }
        }
