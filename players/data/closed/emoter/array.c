inherit "obj/treasure";
#define USER environment()
#define USERN USER->query_real_name()
#define CAP 110
string *items; /* Name of emotes */
int amount;    /* To self */
  
reset(arg) {
if(arg) return;
  set_id("tester");
    set_alias("tester");
    set_weight(0);
    set_value(0);
  amount = allocate(CAP+100);
set_short("tester");
        set_long(
        "A stick that is used to bonk people on the head. It is once said that \n"+
        "you get bonked on the head with this, your soul is forever gone, and \n"+
        "you will do whatever this pimp says for you to do. If you want freedom \n"+
        "then you better get to work. \n");
        
    }






init(){
	if(!environment()) return;
	if(!this_player()) return;
	if(this_player() != environment()) return;
	
	restore_object("players/data/closed/emoter/list");
	
	add_action("review_list", "list_em");
	add_action("make_em", "make_em");
	add_action("delete_item", "delete_em");
	add_action("withdraw_item",   "withdraw_em");
   add_action("example_em",   "example_em");
   add_action("share_emoter", "share_em");	

}

review_list(){
	int i;
	int y;
	y = 1;
	if(sizeof(items) < 1){ write("No items available.\n"); return 1; }
	write("items:\n");
	for(i = 0; i < sizeof(items); i++){
		write(y+")  "+items[i]+"\n");
		y += 1;
	}
	return 1;
}

delete_item(str){
	int emnum;
	
	if(!str){ write("Remove which?\n"); return 1; }
	if(sizeof(items) < 1){ write("No items to remove.\n"); return 1; }
	if(member_array(str, items) < 0){
		write("That item does not exist.\n");
		return 1;
	}
	emnum = member_array(str, items);

	write("Removing "+items[emnum]+"...\n");
	items -= items[emnum];
	save_object("players/data/closed/emoter/list");
	write("Done.\n");
	return 1;
}


make_em(str){
	if(!str){ write("What is the name of the item?\n"); return 1; }
	
	if(sizeof(items) > 2){
		write("You have no more room in your bag.\n");
		return 1;
	}
   if(items)
	if(member_array(str, items) >= 2){
      write("You already have that item.  remove_em first.\n");
      return 1;
      }
	if(!items) items = ({ str });
	else items += ({ str });
	
	save_object("players/data/closed/emoter/list");
	
	write("Creating "+str+".\n");
		input_to("amount");
	return 1;
}

amount(){
int amount;
string str;
	if(!amount){ write("How many?\n"); 
	return 1; 
	}
	
	if(sizeof(amount) > 1){
		write("You have ran out of "+str+".\n");
		return 1;
	}
    if(amount)
	if(member_array(str, amount) >= 100){
      write("You cant hold anymore "+str+".\n");
      return 1;
      }
	  if(!amount) amount = ({ amount });
	else amount += ({ amount });
	
	save_object("players/data/closed/emoter/list");
	
	write("Creating "+amount+".\n");
	return 1;
	}


withdraw_item(str){
	int i;
	int amount;
	string items;
	if(!str){ write("Take what out??\n"); return 1; }
	if(sizeof(items) < 1){ write("No items to remove.\n"); return 1; }
	if(member_array(str, items) < 0){
		write("That item does not exist.\n");
		return 1;
	if(!amount) {
	write ("How many "+str+ "do you want to take out?\n");
	return 1;
	}
	
	}
	i = member_array(str, amount);
if(items[i] == str && amount[i] == amount) {
	write("Removing "+items[i]+amount[i]+"...\n");
	amount - amount[i];
	save_object("players/data/closed/emoter/list");
	write("Done.\n");
	return 1;
}
}