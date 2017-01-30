inherit "obj/treasure";

reset(arg) {
  set_id("menu");
   set_short("A bar menu");
  set_long(
"This is a menu of the drinks served in the bar.  Perhaps you\n"+
"could 'read' the menu.\n");
  set_weight(1000);
  set_value(0);
}
init() {
  add_action("cmd_read","read");
}


cmd_read(str) {
  notify_fail("You can not read that!\n");
  if(!str) return 0;
  if(str!="menu" && str!="the menu") return 0;

 write("The bar menu is listed as follows:\n");   
    write("WE RESERVE THE RIGHT TO CHANGE PRICES WITHOUT NOTICE\n\n");
    write("You can order the following drinks here.\n\n");
    write("     Moontree wine       :  14 coins\n");
    write("     Cup of coffee       :  20 coins\n");
    write("     House Special       : 160 coins\n");
    write("     Gourd of sap        : 358 coins\n\n");
 
  return 1;

}
get() { return 0; }  
