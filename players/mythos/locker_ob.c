#define eo environment(this_object())
#define tp this_player()
#define COST 0
#define SAVE "players/mythos/lockers/"
#define MAX 5
#define WEP_MAX 18
string *shelf;
string *shelf_name;
string *shelf_short;
string *shelf_var; /* Feldegast 1/30/01 */
int *wear;

id(str) { return str == "locker_ob"; }

reset(arg) {
  if(arg) return;
  shelf = allocate(MAX);
  shelf_name = allocate(MAX);
  shelf_short = allocate(MAX);
  wear = allocate(MAX);
  shelf_var = allocate(MAX);
}

drop() { return 1; }

init() {
  if(eo == tp) {
    if(!restore_object(SAVE+tp->query_real_name())) 
       save_object(SAVE+tp->query_real_name());
    add_action("store","store");
    add_action("retrieve","retrieve");
    add_action("clear","clear");
    add_action("list","list");
  }
}

list() {
  int j,i;
  i = 0;
  write("\nItems in storage:\n");
  for(j=0; j < MAX; j++) {
    if(shelf[j]) {
      write("\tID: "+shelf_name[j]+" Desc: "+shelf_short[j]+"\n"); 
      i = 1; 
    }
  }
  if(!i) write("\tThere is nothing in storage.\n");
  return 1; 
}

store(str) {
   int i,j;
   object targ;
   string filename;
   i = 0; j = -1;
   while(i < MAX) {
     if(!shelf[i]) { j = i; i = MAX; }
     else i += 1;
   }
   if(j == -1) { write("No locker space available.\n"); return 1; }
   if(!str) { write("Store what?\n"); return 1; }
   if(!(targ = present(str,tp))) {
     write("You do not have that item.\n");
     return 1; 
   }
   if(targ->query_save_flag() || !targ->query_weight() || !targ->short() ||
      targ->drop() || !targ->get() || targ->query_auto_load()) { 
      write("That item cannot be stored.\n");
      return 1; 
   }
   if(tp->query_exp() < COST) {
     write("You do not have enough xp.\n");
     return 1; 
   }
   tp->add_exp(-COST);
   tp->reset(1);

   /* Feldegast 1/30/01 */
   if(targ->query_save_flag()==2) { 
     write("That item cannot be stored here.\n");
     return 1;
   }

   sscanf(object_name(targ),"%s#%s",filename);
   if(filename == "obj/armor" || filename == "obj/armour" ||
      filename == "obj/weapon" || filename == "obj/treasure" ||
      filename == "obj/generic_heal") {
     write("It doesn't fit.\n");
     return 1;
   }
   shelf[j] = filename;

   /* Feldegast 1/30/01 */
   shelf_var[j] = targ->locker_arg(); 

   command("drop "+str,tp);
/* if(targ) added by Verte, in case item dests on destruct.
    [5.24.01] */
   if(targ)
   {
     shelf_short[j] = (string)targ->short();
     shelf_name[j] = str;
     wear[j] = (string)targ->query_wear();
     save_object(SAVE + tp->query_real_name());
     destruct(targ);
     write(str + " has been saved.\n");
   }
    else write(str + " has NOT been saved.\n");
    return 1;
}

retrieve(str) {
  int i,j;
  int mo;
  object targ;
  string err;
  mo = 0;
  if(!str) { write("Retrieve what?\n"); list(); return 1; }
  if((j=member_array(str,shelf_name)) == -1) { 
    write("That is not something you can retrieve.\n");
  return 1; }
/*  Catch errors -Bp
  targ = clone_object(shelf[j]);
*/
  if ( err = catch(targ = clone_object(shelf[j])) ) {
    write("Somehow the object you have tried to retrieve has gone bad.\n"+
     "We apologize for this inconveniance and would like to reimburse you.\n");
    shelf[j] = shelf_name[j] = shelf_short[j] = wear[j] = 0;
    save_object(SAVE+tp->query_real_name());
    tp->add_exp(COST);
    write("You have recieved "+COST+" exp.\n");
    return 1;
  }
  if(!targ) {
    write("Somehow the object you have tried to retrieve has gone bad.\n"+
     "We apologize for this inconveniance and would like to reimburse you.\n");
    shelf[j] = shelf_name[j] = shelf_short[j] = wear[j] = 0;
    save_object(SAVE+tp->query_real_name());
    tp->add_exp(COST);
    write("You have recieved "+COST+" exp.\n");
    return 1;
  }
  if(!tp->add_weight(targ->query_weight())) {
    write("You cannot carry anymore.\n"); 
    destruct(targ);
    return 1; 
  }

  /* Feldegast 1/30/01 */
  if(shelf_var[j]) targ->locker_init(shelf_var[j]); 

  write("You retrieve "+targ->short()+"\n");
  say(tp->query_name() + " retrieves a "+targ->short()+"\n");
  move_object(targ,tp);
  if(targ && wear[j]) targ->add_wear(wear[j]);


  shelf[j] = shelf_name[j] = shelf_short[j] = wear[j] = shelf_var[j] = 0;
  save_object(SAVE+tp->query_real_name());
  return 1; 
}

/*

deposit(str) {
  int n,m;
  if(!str) { write("How much do you wish to deposit?\n"); return 1; }
  if(!sscanf(str,"%d",n)) return 0;
  if(gold + n > LIMIT) n = LIMIT - gold;
  if(tp->query_money() < n) { write("You do not have that much to deposit!\n");
  return 1; }
  if(tp->query_exp() < n/2) { write("You do not have enough xp\n"); return 1; }
  tp->add_money(-n);
  tp->add_exp(-n/2);
  tp->reset(1);
  m = 2 + random(14);
  gold = gold + n + n*m/100;
  save_object(SAVE+tp->query_real_name());
  write(n+" amount has been deposited.\n");
  write("The Newbie Locker Fund System [NLFS] has matched "+m+
        "% of your deposit.\nThe total amount saved is: "+gold+" coins.\n");
  write("Thank you.\n");
return 1; }

withdraw(str) {
  int n;
  if(!str) { write("How much do you wish to withdraw?\n"+
                   "Current account stands at: "+gold+"\n");
             return 1; }
  if(!sscanf(str,"%d",n)) return 0;
  if(n > gold) n = gold; 
  gold = gold - n;
  save_object(SAVE+tp->query_real_name());
  tp->add_money(n);
  write("You withdraw "+n+" amount\nYour account is now :"+gold+"\n");
  write("Thank you.\n");
return 1; }
*/

clear() {
  write("This will clear out all items saved in your lockers.\n");
  write("Ok <y/n>? ");
  input_to("clear_ok");
  return 1; 
}

clear_ok(str) {
  if(!str) {
    write("Ok <y/n>? ");
   input_to("clear_ok");
  return 1; }
  if(str != "y" && str != "n") {
    write("Ok <y/n>? ");
  input_to("clear_ok");
  return 1; }
  if(str == "n") { write("aborting...\nAction aborted\n"); return 1; }
  write("Clearing lockers...\n");
  shelf = allocate(MAX);
  shelf_name = allocate(MAX);
  shelf_short = allocate(MAX);
  wear = allocate(MAX);
  save_object(SAVE+tp->query_real_name());
  write("Cleared.\n");
  return 1; 
}
