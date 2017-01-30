 
 
 
inherit "obj/treasure";
 
 
string TSTR;
reset(arg) {
 
   if (arg) return;
 
    set_id("thing");
    set_alias("projectile");
    set_short("A thing (you can name it)");
    set_long("To name this thing, 'name <string>'.\n");
    set_value(0);
    set_weight(0);
 
}

query_value(){ return 100; }
 
name(str) {
string who;
 
   if (environment(this_object()) != this_player()) return 0;
   if (str == "?") {
      write("name <string> : names the projectile.\n");
      return 1;
   }
   TSTR=str;
   if (call_other(this_player(), "query_gender") == "male") who = "his";
   else who = "her";
   say(call_other(this_player(), "query_name") + " names "+who+" projectile\n");
   return 1;
}
 
short() {
     if(!TSTR){
        return "A thing";
}
     return TSTR;
}
 
 
long() {
 
   if (TSTR)  {
      write(TSTR+"\n");
      write("To name this thing, 'name <string>'.\n");
   } else {
      write("A generic projectile;  use projectile ? to get help msg.\n");
   }
   return 1;
}
 
 
init() {
   ::init();
   add_action("name","name");
}
