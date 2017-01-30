/*
 *  A way to shut up the master mini guild line.  (v2.0)
 *
 */

master_toggle()  {
object ob, ob2;
int flag_check;
  ob = present("base_obj",environment(this_object()));
  flag_check = ob->query_master_flag();
  if(flag_check > 0)  {
  ob2 = first_inventory(environment(this_object()));
    while(ob2)  {
      if(ob2->query_mini() == "base_obj")  {
      ob2->set_master_flag(0);     }
      ob2 = next_inventory(ob2);   }
  write("You turn off the master chat line.\n");
  return 1;
        }
  if(flag_check < 1)  {
  ob2 = first_inventory(environment(this_object()));
    while(ob2)  {
      if(ob2->query_mini() == "base_obj")  {
      ob->set_master_flag(1);     }
      ob2 = next_inventory(ob2);   }
  write("You turn on your master chat line.\n");
  return 1;
        }
        }
