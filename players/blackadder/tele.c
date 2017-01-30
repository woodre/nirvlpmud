
id(str) {
   return str == "tele";
}

short() {
   return "tele";
}

query_value()
{
   return 0;
}

long() {
   write("A teleporter.\n");
}

reset(arg) {
   if (arg)
      return;
}

teleport(str) {
   object ob;
   object ob1;
   ob = find_living(str);
   if (!ob) {
      write("Not home.\n");
      return 1;
   }
   ob1 = environment(ob);
   move_object(this_player(),file_name(ob1));
   return 1;
}

init() {
   add_action("teleport","teleport");
}

get() {
   return 1;
}

query_weight() {
   return 1;
}
