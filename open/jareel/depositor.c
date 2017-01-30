
inherit "/obj/clean";

#define TPRN this_player()->query_real_name()
#define SAVEDEPOSIT "players/jareel/bank/deposits/"
int deposit_amount;
static int amount;
static int whodeposit;
static string wholist;

id(str) { return str == "depositor"; }

drop() { return 1; }
get() { return 0; }
query_weight() { return 0; }

reset(arg) {
  if(arg) return;
  deposit_amount = 0;
  amount = 0;
    wholist = allocate(18);
    whodeposit = allocate(18);

}

init() {
  restore_object(SAVEDEPOSIT+this_player()->query_real_name());
  if(TPRN == "jareel" || TPRN == "stone" || TPRN == "konya" || TPRN == "justin" || TPRN == "bone" || TPRN == "cooper" || TPRN =="magus") add_action("deposit","deposit");
  add_action("inquire","inquire");
  add_action("deposit_list","deposit_list");
}

deposit(str) {
  if(!str) { write("Depositing how much?\n"); return 1; }
  if(!sscanf(str,"%d",amount)) return 0;
  if(amount < 0) { write("You can not do that!\n"); return 1; }
  if((this_player()->query_money()) < amount){
write("You do not have the available coins for that deposit!\n");
return 1; }
  write("You are about to deposit "+amount+" coins.\n"+
        "You do understand that this deposit is non-refundable?  <y/n> ");
  input_to("deposit_ok");
return 1; }

deposit_ok(str) {
  if(!str) {
    write("You are about to deposit "+amount+" coins.\n"+
	        "You do understand that this deposit is non-refundable?  <y/n> ");
	  input_to("deposit_ok");
   return 1; }
   if(str != "y" && str != "Y") {
     amount = 0;
	 write("Deposit has been cancelled.\n");
    return 1; }
  this_player()->add_money(-(amount));
	deposit_amount += amount;
	save_object(SAVEDEPOSIT+this_player()->query_real_name());
	write("You have deposited "+amount+" coins making your current total to be "+deposit_amount+"\n");
	amount = 0;
return 1; }

inquire() {
  write("You currently have "+deposit_amount+" coins deposited.\n");
return 1; }





creation() {
int k;
int h,start;
string meow, moo, space;
string who;
string nm;

  wholist = allocate(18);
  whodeposit = allocate(18);
 k = h = start = 0;
  meow = get_dir("/"+SAVEDEPOSIT);
  while(start < sizeof(meow)) { 
      if(sscanf(meow[start],"%s.o",who)) {
    if(restore_object(SAVEDEPOSIT+who)){
	   h = check(deposit_amount);
	    if(h != -1) { 
		  k = sizeof(wholist)-1;
		 while(k>h) {
		       wholist[k] = wholist[k-1]; 
			   whodeposit[k] = whodeposit[k-1]; 
			   k = k - 1;
		 }
		 wholist[h] = who; whodeposit[h] = deposit_amount;     
			   }
	  }
	} 
    start = start + 1;
  }
}

check(int checker) {
int j, i;
  j = 0; i = -1;
  while(j<sizeof(whodeposit) && i == -1) {
    if(whodeposit[j] < checker) { i = j; j = 1000; }
	else j = j + 1;
  }
  return i;
}
deposit_list() {
  int h, k;
  
  creation();
  write("\n --------------Deposit Top 18 List--------------\n\n");
  for(h=0;h<sizeof(wholist);h++) {
   write("          "+wholist[h]);
	write("\t\t"+whodeposit[h]);
	write("\n");
  }
  write("\n ----------------------------------------------------\n\n");
  restore_object(SAVEDEPOSIT+"jareel");
return 1; }

