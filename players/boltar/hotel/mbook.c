

short()
{
     return "A large and heavy book";
}

query_value()
{
        return 3;
}

  query_weight() {   return 200; }
long()
{
write("The book opens as you look at it, it reads as follows:\n");
write("  There will be NO rembursements for lost items.\n");
write("  You may invite other players into your room from the lobby\n");
write("  by using 'invite <name>' inside your room.\n");
write("  Checkout of your room with 'checkout'\n");
}

init() {
  add_action("read","read");
}



get() {
      write("The book is too heavy and is attached to the counter.\n");
    return 0;
}
read(str){
   if (str!="book")
     return 0;
   call_other("players/boltar/hotel/motel", "list_guests",0);
   return 1;
}
id(str) { return str=="book"; }


