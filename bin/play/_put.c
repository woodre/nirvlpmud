#include <security.h>

int cmd_put(string str)
{
    int i;
    string item;
    string container;
    object item_o;
    object container_o;
    string power;

    if (!str)
	  {
  	  write("Put what in what ? \n");
  	  return 1;
	  }
	  
	  power = 0;
	  
    if ((int)this_player()->query_level() >= ITEM_OVER)
      if (sscanf(str,"! %s",power) == 1)
      {
        str = power;
	      power = "!";
      }
      
    if (this_player()->test_dark())
	    return 1;
    
	  if (sscanf(str, "%s in %s", item, container) != 2)
	  {
	    write("Put what in what?\n");
	    return 1;
    }
    container = lower_case(container);
    container_o = present(container, this_player());
    if (!container_o)
	    container_o = present(container, environment(this_player()));
    if (!container_o)
    {
	    write("There are no " + container + "s here!\n");
	    return 1;
    }
    if(!container_o->can_put_and_get() && !power)
    {
	    write((string)container_o->query_name()+" can't hold anything!\n");
	    return 1;
    }
    if(item == "all")
    {
      object a, b;
      a = first_inventory(this_player());
      while(a)
      {
        b = next_inventory(a);
        if(a->query_wep_shadow())
       write("A glitch in the matrix prevents it.\n");
        else if(a->query_name() && !a->drop())
        {
          write((string)a->short()+" ... ");
          cmd_put((string)a->query_name()+" in "+container);
        }
        a = b;
      }
      return 1;
    }
    item = lower_case(item);
    item_o = present(item, this_player());
    if (!item_o)
    {
	    write("You don't have " + item + "!\n");
	    return 1;
    }
    if (item_o == container_o)
    {
      write("You can't put something inside itself!\n");
	    return 1;
    }
    if (call_other(item_o, "prevent_insert") && !power)
    {
      write("You can't put "+item+" in anything!\n");
	    return 1;
    }
    if (call_other(item_o, "drop", 0) && !power)
    {
      write("You can't drop "+item+"!\n");
	    return 1;
    }
    if (!item_o)
    {
      write("You don't have "+item+"!\n");
      return 1;
    }
    i =(int)item_o->query_weight();

    if((item_o->can_put_and_get()) && !item_o->is_armor() && !item_o->is_weapon())
    {
      write("You can't put a container inside another container.\n");
      return 1;
    }
    
    if(item_o->query_wep_shadow()) {
    write("A glitch in the matrix prevents it.\n");
    return 1;
  }
    if (call_other(container_o, "add_weight", i) || power)
    {
	    call_other(environment(item_o), "add_weight", -i);
	    move_object(item_o, container_o);
	    this_player()->checked_say(
	     (string)this_player()->query_name() 
	     + " puts the " + item + " in the " + container + ".\n");
	    write("Ok.\n");
	    this_player()->set_it(item);
	    return 1;
    }
    write("There is not any more room for that!\n");
    return 1;
}
