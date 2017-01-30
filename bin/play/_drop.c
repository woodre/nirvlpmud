#include <security.h>
int cmd_drop(mixed obj)
{
    string tmp;
    string tmp2;
    int x;
    int i;
    string power;

  if(!obj) { write("Drop what?\n"); return 1; }
    power = 0;
    if ((int)this_player()->query_level() >= ITEM_OVER)
        if (sscanf(obj,"! %s",power) == 1) {
            obj = power;
	    power = "!";
        }
    if (obj == "all") {
	this_player()->drop_all(1);
	return 1;
    }
    if(sscanf(obj, "%d coins", x) || sscanf(obj, "%d money", x) ||
       sscanf(obj, "%d gold coins", x) || sscanf(obj, "%d coin", x))
    {
      object gold;
      if(x <= 0 || (int)this_player()->query_money() < x)
        return (write("You only have " + (int)this_player()->query_money() + " coins.\n"), 1);

      gold = clone_object("/obj/money");
      gold->set_money(x);
      move_object(gold, environment(this_player()));
      this_player()->add_money(-x);
      write("You drop " + x + " " + (x == 1 ? "coin" : "coins") + ".\n");
      say(this_player()->query_name() + " drops some coins.\n");
      return 1;
    }
    if (sscanf(obj, "%s in %s", tmp, tmp2) == 2) {
        "/bin/play/_put"->cmd_put(obj);
	    return 1;
    }
    if (obj == "money" || obj == "coins") 
     if(!present("money",this_player())) {
       write("You may drop a certain amount of money, or 'all money'\n");
       return 1;
     }
     if(obj == "all coins" || obj == "all money") {
   if((int)this_player()->query_no_give()){
     write("You cannot drop money while another copy is logging in.\n");
     return 1;
     }
	this_player()->drop_all_money(1);
	return 1;
    }
    tmp = obj;
    obj = present(lower_case(obj), this_player());
    if (!obj) {
	write("That is not here.\n");
	return 1;
    }
    if (this_player()->drop_one_item(obj)) {
        this_player()->set_it(tmp);
	write("Ok.\n");
	this_player()->checked_say((string)this_player()->query_name()
	 + " drops the " + tmp + ".\n");
    }
    return 1;
}
