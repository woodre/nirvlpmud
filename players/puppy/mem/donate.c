#define SAVEDONATE "players/puppy/mem/proom/"
int donate_amount;
static int amount;
static int whodonate;

id(str) { return str == "donate"; }

drop() { return 1; }
get() { return 0; }
query_weight() { return 0; }

reset(arg) {
  if(arg) return;
  donate_amount = 0;
  amount = 0;

}

init() {
  restore_object(SAVEDONATE+this_player()->query_real_name());
  add_action("donate","donate");
  add_action("balance","balance");
}

donate(str) {
  if(!str) { write("Donating how much?\n"); return 1; }
  if(!sscanf(str,"%d",amount)) return 0;
  if(amount < 0) { write("You can not do that!\n"); return 1; }
  if((this_player()->query_money()) < amount){
write("You do not have the available coins for that donation!\n");
return 1; }
  write("You are about to donate "+amount+" coins.\n"+
        "You do understand that this donation is non-refundable?  <y/n> ");
  input_to("donate_ok");
return 1; }

donate_ok(str) {
  if(!str) {
    write("You are about to donate "+amount+" coins.\n"+
	        "You do understand that this donation is non-refundable?  <y/n> ");
	  input_to("donate_ok");
   return 1; }
   if(str != "y" && str != "Y") {
     amount = 0;
	 write("Donation has been cancelled.\n");
    return 1; }
  this_player()->add_money(-(amount));
	donate_amount += amount;
	save_object(SAVEDONATE+this_player()->query_real_name());
	write("You have donated "+amount+" coins making your current total to be "+donate_amount+"\n");
	amount = 0;
return 1; }

balance() {
  write("You currently have "+donate_amount+" coins donated.\n");
return 1; }



