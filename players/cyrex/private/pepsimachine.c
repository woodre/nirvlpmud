/* Lancer's Pepsi Machine */

   string name;

reset(arg) {
   if (arg) return;
   name = 0;
}

id(str) { return (str == "machine"); }
short() { return ("Pepsi Machine"); }
long() {
   write("  This machine is operated and maintained by Lancer.  You can\n"+
         "select from a variety of drinks.  More will be added later.\n"+
         "                                              \n"+
         " 1. Pepsi                      :   25 coins\n"+
         " 2. Coke                       :   25 coins\n"+
         " 3. 7-Up                       :   25 coins\n"+
         "                                              \n"+
         "Type 'push #' to select.\n");
}

init() {
   object temp;

   add_action("push", "push");
}

push(str) {
   object temp;
  write("Sorry this machine is out of order.\n");
return 1;
   if (!str) {
      write("push a number\n");
      return 1;
   }
   if(str == "1")
     hands(25, clone_object("/players/lancer/private/pepsi"));
   else if(str == "2")
     hands(25, clone_object("/players/lancer/private/coke"));
   else if(str == "3")
     hands(25, clone_object("/players/lancer/private/7up"));
   else {
      write("Please select 1 to 3 only.\n");
   }
   return 1;
}

hands(money, ob)
{
  if ((this_player()->query_money()) < money) {
    write("Sorry, you don't have enough coins.\n");
    return 1;
   }
  this_player() -> add_money(-money);
  say("The machine makes a funny wierd noise and\n"+"hands "+
     capitalize(this_player()->query_real_name())+" a "+ob->short()+".\n",
      this_player());
  write("The noisy machine\n"+"hands "+
      "you a "+ ob->short()+".\n");
  move_object(ob, this_player());
  return 1;
 }
