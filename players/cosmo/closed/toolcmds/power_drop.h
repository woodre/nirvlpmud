power_drop(string str) {
object ob;
  if(!str) { return 0; }
  if(!present(str,TP)) {
    write("You don't have "+str+".\n");
    return 1;
  }
  else {
    ob=present(str,TP);
    move_object(ob,environment(TP));
    write("You have dropped the " +str+ ".\n");
    return 1;
  }
}
