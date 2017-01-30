id(str) { return str == "myth"; }

drop() { return 1; }

init() {
   if(this_player()->query_level() < 100) destruct(this_object());
  add_action("moo","moo");
}

moo(str) {
object ob;
int h,i;
  ob = users();
   if(!str) { write("moo <str>\n"); return 1; }
  h = 0;
i = 0;
   while(h<sizeof(ob) && i != 69) {
   if(ob[h]->query_real_name() == "mythos") {
   tell_object(ob[h],"Arrina says: "+str+"\n");
   write("you say "+str+" to mythos.\n");
   i = 69; }
  h = h + 1;
}
   if(i != 69) write("mythos not in\n");
return 1; }
