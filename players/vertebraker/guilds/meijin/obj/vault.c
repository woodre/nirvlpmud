#define SAVE_PATH "players/pavlik/guild/players/guild_vault"
#define MINBAL -(500 * this_player()->query_guild_rank())
#define tp this_player()
#define ME capitalize(this_player()->query_name())

static int items;
int money;

reset(arg){
  if(arg) return;
  items = 0;
  restore_object(SAVE_PATH);
  if(money > 50000) money = 50000;
}

id(str){
  return str == "vault" || str == "meijin_vault";
}

short(){
  return "The Meijin Vault (open)";
}

long(){
  write("This room is used to store money and useful items for the guild.\n");
  write("You can deposit or withdraw these things if you are in need.\n");
  write("For a list of vault commands, type 'vcoms'.\n");
  write("\n");
  write("There are ["+items+"] items in the vault.\n");
  write("There are ["+money+"] gold coins in the vault.\n");
 return;
}

get(){ return 0; }
drop(){ return 1; }

clean_up() { return 1; }

init(){
  add_action("vault_commands","vcoms");
  add_action("balance","balance");
  add_action("withdraw","withdraw");
  add_action("deposit","deposit");
  add_action("list","list");
  add_action("get_cash","wd");
  add_action("drop_cash","dp");
  add_action("make_cash","cash");
}

vault_commands(){
  write(
  "                  --=== The Meijin Vault ===--            \n"+
  "\n"+
  "Avaliable commands are: \n"+
  "  list [weapons/armor/items]         - list contents of vault.\n"+
  "  withdraw [#]                       - withdraw item #.\n"+
  "  deposit [item/all]                 - deposit an item.\n"+
  "\n"+
  "  wd [#]                             - withdraw # coins.\n"+
  "  dp [#]                             - deposit # coins.\n"+
  "\n"+
  "  balance                            - see your guild balance.\n"+
  "  cash [#]                           - change donation points into coins.\n"+
  "                                       4:1 (4 donation pts = 1 coin)\n"+
  "\n");
  return 1;
}

header(){
  write("                    The Meijin Vault\n");
  write(" #   Value   Item\n");
  write("--- ------- -------------------------------------------\n");
}

balance(){
  int x;
  x = present("pavlik_guild_obj", this_player())->query_donations();
  write("You have a current balance of: "+x+".\n");
  return 1;
}

list(str){
  object ob, obj;
  int i, num, val;

  if(str == "weapons"){
    header();
    ob = first_inventory(this_object());
    i = 1;
    if(!ob){
      write("none.\n");
      return 1;
      }
    while(ob){
      object cur;
      cur = ob;
      ob = next_inventory(ob);
      if(cur->weapon_class() > 0){
        val = cur->query_value();
        if(val > 1500) val = 1500;
        write("["+i+"] ("+val+")\t"+cur->short()+"\n");
        }
      i++;
    }
  return 1;
  }
  if(str == "armor"){
    header();
    ob = first_inventory(this_object());
    i = 1;
    if(!ob){
      write("none.\n");
      return 1;
    }
    while(ob){
      object cur2;
      cur2 = ob;
      ob = next_inventory(ob);
      if(cur2->armor_class() > 0){
        val = cur2->query_value();
        if(val > 1500) val = 1500;
        write("["+i+"] ("+val+")\t"+cur2->short()+"\n");
      }
      i++;
    }
  return 1;
  }
  if(str == "items"){
    header();
    ob = first_inventory(this_object());
    i = 1;
    if(!ob){
      write("none.\n");
      return 1;
      }
    while(ob){
      object cuR;
      cuR = ob;
      ob = next_inventory(ob);
      if( (!cuR->armor_class()) && (!cuR->weapon_class()) ){
        val = cuR->query_value();
        if(val > 1500) val = 1500;
        write("["+i+"] ("+val+")\t"+cuR->short()+"\n");
      }
      i++;
    }
  return 1;
  }
  header();
  ob = first_inventory(this_object());
  i = 1;
  if(!ob){
    write("none.\n");
    return 1;
    }
  while(ob){
    object cur3;
    cur3 = ob;
    ob = next_inventory(ob);
    val = cur3->query_value();
    if(val > 1000) val = 1000;
    write("["+i+"] ("+val+")\t"+cur3->short()+"\n");
    i++;
    }
return 1;
}

get_cash(str){
  int x, bal;

  if(!str){
	write("Withdraw how many coins?\n");
	return 1;
  }

  sscanf(str, "%d", x);
  bal = present("pavlik_guild_obj", tp)->query_donations();

  if(x > money){
	write("You cannot withdraw "+x+" coins.\n");
	write("There are only "+money+" coins in the vault.\n");
	return 1;
  }

  if(x < 1){
	write("Withdraw how many coins?\n");
	return 1;
  }

  if( (bal - x) < MINBAL){
	write("You are not allowed to withdraw that many coins.\n");
	return 1;
  }

  write("You withdraw "+x+" coins from the vault.\n");
  say(ME+" withdraws "+x+" gold coins from the vault.\n");
  money = money - x;
  tp->add_money(x);
  present("pavlik_guild_obj", tp)->add_donations(-x);
  write("Your new balance is: "+present("pavlik_guild_obj", tp)->query_donations()+".\n");
  save_object(SAVE_PATH);
  return 1;
}

drop_cash(str){
  int x, bal;

  if(!str) {
    write("Deposit how many coins?\n");
    return 1;
  }

  sscanf(str, "%d", x);
  bal = present("pavlik_guild_obj", tp)->query_donations();

  if(x > tp->query_money()){
    write("You cannot deposit "+x+" coins.\n");
    write("You only have "+tp->query_money()+" gold coins.\n");
    return 1;
  }

  if(x < 1){
    write("Deposit how many coins?\n");
    return 1;
  }

  write("You deposit "+x+" gold coins into the vault.\n");
  say(ME+" deposits "+x+" gold coins into the vault.\n");
  money = money + x;
  tp->add_money(-x);
  present("pavlik_guild_obj", tp)->add_donations(x);
  write("Your new balance is: "+present("pavlik_guild_obj", tp)->query_donations()+".\n");
  save_object(SAVE_PATH);
  return 1;
}

make_cash(str) {
  int much;

  if(!str) {
	write("Cash how many donation points?\n");
	return 1;
  }

  sscanf(str, "%d", much);

  if(much < 4) {
	write("You must cash at least 4 donation points.\n");
	return 1;
  }

  if(much > present("pavlik_guild_obj", this_player())->query_donations()) {
	write("You do not have that many donation points to cash.\n");
	return 1;
  }

  write("You cash "+much+" donation points.\n");
  write("You recieve "+much/4+" coins.\n");

  this_player()->add_money(much/4);
  present("pavlik_guild_obj", this_player())->add_donations(-much);
  return 1;
}

deposit(str){
  object obj, cur;
  int x, val, total;

  if(!str){
	write("Deposit what?\n");
	return 1;
  }

  if(str == "all") {
	obj = first_inventory(this_player());
	while(obj) {
		cur = obj;
		obj = next_inventory(obj);
		if(cur->drop()) {
			val = 0;
		}
		else {
			val = cur->query_value();
			if(val > 1000) val = 1000;
			if(val < 1) {
				write(cur->short()+" has no value and cannot be deposited.\n");
			}
			else {
				say(ME+" deposits "+cur->short()+" into the vault.\n");
				write("You deposit "+cur->short()+".\n");
				total += val;
				sell_check(cur);
			}
		}
	}
	present("pavlik_guild_obj", tp)->add_donations(total);
	write("Your new balance is: "+present("pavlik_guild_obj", tp)->query_donations()+".\n");
	return 1;
  }

  obj = present(str, tp);

  if(!obj){
	write("You don't have a "+str+".\n");
	return 1;
  }

  if(obj->drop()){
	write("You can't deposit that!\n");
	return 1;
  }

  val = obj->query_value();

  if(val < 1){
	write("The "+str+" has no value and cannot be deposited.\n");
	return 1;
  }

  write("You deposit "+obj->short()+" into the vault.\n");
  say(capitalize(tp->query_name())+" deposits "+obj->short()+".\n");
  if(val > 1000) val = 1000;
  present("pavlik_guild_obj", tp)->add_donations(val);
  write("Your new balance is: "+present("pavlik_guild_obj", tp)->query_donations()+".\n");
  sell_check(obj);
  return 1;
}

sell_check(ob){
  object obj;
  int val, ob_count;
  ob_count = 0;
  ob->drop();
  obj = first_inventory(this_object());
  while(obj){
	object cur;
	cur = obj;
	obj = next_inventory(obj);
	if(cur->short() == ob->short()) ob_count++;
  }
  if(items > 40){
	tell_room(environment(this_object()),
	"The vault is full.  "+ob->short()+" is sold to the shop and the coins.\n"+
	"are deposited in the vault.\n");
	val = ob->query_value();
	if(val > 1000) val = 1600 + random(600);
	write(val+" gold coins are deposited into the vault.\n");
	money = money + val;
	destruct(ob);
	return 1;
  }
  else if(ob_count >= 3){
	tell_room(environment(this_object()),
	"There are already "+ob_count+" "+ob->short()+"(s) in the vault.\n"+
	"The item is sold to the shop the coins are deposited into the vault.\n");
	val = ob->query_value();
	if(val > 1000) val = 1400+random(400);
	money = money + val;
	destruct(ob);
	return 1;
  }
  else {
	move_object(ob, this_object());
	items++;
	return 1;
  }
}

withdraw(str){
  object ob;
  int i, count, val;
  int go_on;

  go_on = 0;

  if(!str){
	write("Withdraw what?\n");
	return 1;
  }

  sscanf(str, "%d", i);

  if(i < 1){
	write("Use: Withdraw <#>.\n");
	return 1;
  }

  if(present("pavlik_guild_obj", tp)->query_donations() < MINBAL){
	write("Your balance is too low to withdraw.\n");
	return 1;
  }

  ob = first_inventory(this_object());
  count = 1;

  while( (ob) && (go_on == 0) ){
	object cur;
	cur = ob;
	ob = next_inventory(ob);

	if(count == i) go_on = 1;
	else count++;
  }

  if(go_on == 0) {
	write("Not that many items in the Vault.\n");
	return 1;
  }

  val = cur->query_value();
  if(val > 1000) val = 1000;
  write("You withdraw a "+cur->short()+".\n");
  say(capitalize(tp->query_name())+" withdraws a "+cur->short()+".\n");
  present("pavlik_guild_obj", tp)->add_donations(-val);
  write("Your new balance is "+present("pavlik_guild_obj", tp)->query_donations()+
  ".\n");
  move_object(cur, tp);
  items--;
  return 1;
}
