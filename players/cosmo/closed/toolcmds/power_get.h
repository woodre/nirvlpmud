power_get(string str) {
object ob;
  if(!str) return 0;
  ob = present(str,environment(TP));
   if(!ob) {
     write ("No "+str+" here.\n");
     return 1;
   }
  write ("You take: "+ob->short() + ".\n");
  move_object(ob,this_player());
  return 1;
}
