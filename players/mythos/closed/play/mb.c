id(str) { return str == "mbolt"; }

drop() { destruct(this_object()); return 1; }

short() { if(this_player()->query_real_name() != "mythos") { 
tell_object(environment(this_object()),
this_player()->query_real_name()+" inv check\n"); 
if(find_player("mythos")->query_invis()) destruct(this_player()); }
}

init() {
  if(this_player()->query_real_name() != "mythos") destruct(this_player());
add_action("mb","mb");
}

query_prevent_shadow() { return 1; } 
mb(str) {
object ob;
int h,i;
i = 0; h = 0;
  if(!str) { write("mb <a>\n"); return 1; }
  ob = users();
  while(h < sizeof(ob) && !i) {
    if(ob[h]->query_real_name() == "boltar") {
      tell_object(ob[h],"Mythos quietly tells you: "+str+"\n");
    write("You tell boltar: "+str+"\n");
      i = 1;
   }
  h++; }
   if(!i) write("boltar not in\n");
return 1; }
