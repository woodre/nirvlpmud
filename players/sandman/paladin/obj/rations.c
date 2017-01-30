
inherit "/obj/treasure";
int ration_eaten;

id(str) { return str == "rations"; }

reset() { set_save_flag(1); }

long()
{
  write("A sack of "+ (11 - ration_eaten) +" iron rations.\n");

}

short() { return "A sack of iron rations"; }
drop() {
        write("The rations decay on the ground.\n");
	destruct(this_object());
	return 1;
	}

init()

{
  add_action("eat"); add_verb("eat");
}

eat(arg)
{
  if (arg=="ration")
  {
    if (call_other(this_player(), "eat_food", 20))
    {
      say(call_other(this_player(),"query_name") + " eats an iron ration.\n");
       write("You eat an iron ration.\n");
      if (ration_eaten == 10) { write("You ate the last one.\n"); }
      else { write("There are " + (10 - ration_eaten) + " rations left.\n"); }
      call_other(this_player(),"heal_self",30);
      ration_eaten++;

      if (ration_eaten > 10) { 
        this_player()->add_weight(-1);
        destruct(this_object()); 
      }
      return 1;
    }
    return 1;
  } else { return 0; }
}


get() { return 1; }

query_weight() { return 1; }

query_value() { return 1500; }


 
