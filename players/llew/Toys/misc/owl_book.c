inherit "obj/treasure";

reset(arg) {
   if(arg) return;
   set_id("book");
   set_short("A wooden bound book");
   set_long("The oak covered pages are the treasure of Owls.\n");
   set_value(100);
   set_weight(1);
   set_read("You can't understand any of the owl script, but perhaps you could sell the book.\n");
   set_dest_flag(1);
}
