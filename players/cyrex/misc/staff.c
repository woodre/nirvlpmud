object fob,rem_obj,old_rem_obj,last_arg;
#define Name(XXX) call_other(XXX,"query_name");
#define Call(XXX,YYY,ZZZ) call_other(XXX,YYY,ZZZ);

short(){return "A wizard staff";}
long(){write("This is a newbie wizard staff.\n");}
id(str){return str == "staff";}
get(){return 1;}
drop(){return 1;}
init(){
   if(this_player()->query_level() < 21) {return;}
   fob = this_player();
   add_action("staff_help","shelp");
   add_action("echo","echo");
   add_action("echo_all","eall");
   add_action("trans","trans");
   add_action("move_into","Move");
   add_action("Get","Get");
   add_action("goin","goin");
}
staff_help(){
   cat("/players/arthur/staff_help");
   return 1;}
echo (str){
   if(!str){write("Usage: echo <str> \n"); return 1;}
   say(str+"\n");
   write("Ok.\n");
   return 1;
}
echo_all(str){
   if(!str){write("Usage: eall <str> \n"); return 1;}
   shout(str+"\n");
   write("Ok.\n");
   return 1;
}
trans(arg){
   object plyr;
   if(!arg){
      write("Usage: trans <player> \n"); return 1;}
   plyr=find_player(arg);
   if(!plyr){write("Couldn't find "+arg+"\n"); return 1;}
   move_object(plyr,environment(this_player()));
   write("You trans "+arg+".\n");
   tell_object(plyr,"You are drawn somewhere.\n");
   write("Ok.\n");
   return 1;
}
move_into(str){
   object ob1, ob2;
   string what1, what2;
   if(!str) {
      write("Usage: move <object1> into <object2>\n");
      write("WARNING: Don't make object1 = pathname; can be fatal!\n");
      return 1;
   }
   if(sscanf(str,"%s into %s",what1, what2) !=2)
      if(sscanf(str,"%s %s",what1, what2) !=2) { move_into(); return 1; }
   ob1 = find_ob(what1);
   if(!ob1) {write("Couldn't find "+what1+"\n"); return 1; }
   ob2 = find_ob(what2);
   if(!ob2) {write("Couldn't find "+what2+"\n"); return 1; }
   move_object(ob1, ob2);
   write("Ok.\n");
   return 1;
}
Get(str){
   object ob;
   string what, item;
   if(!str) { write("Usage: Get <object> \n"); return 1; }
   if(sscanf(str,"%s from %s", item, what) == 2) {
      ob = find_ob(what);
      if(!ob) {write("Can't find that object.\n"); return 1; }
      ob = present(item, ob);
      if(!ob) {write("Can't find that object.\n"); return 1; }
      move_object(ob, fob);
      write("Ok.\n");
      return 1;
   }
   ob = find_ob(str);
   if(!ob) {write("Can't find that object.\n"); return 1; }
   move_object(ob, fob);
   write("Ok.\n");
   return 1;
}
goin(str){
   object ob;
   if(!str) { write("Usage : Goin [object]\n"); return 1; }
   ob = find_ob(str);
   if(!ob) {write("Couldn't find "+str+"\n"); return 1; }
   move_object(fob,ob);
   write("Ok.\n");
   return 1;
}
find_ob(str) {
   object ob;
   string s1, s2, tmp;
   int nr;
   if(!str) { Error("No arg to find_ob."); return 1; }
   if(sscanf(str, "%s,%s", s1, s2) != 2) {
      if(sscanf(str, "%d", nr) == 1) {
         return nr_in_ob(nr, environment(this_player()));
      }
      else {
         return search_all(str);
      }
   }
   ob = search_all(s1);
   while(s2 && ob) {
      tmp = 0;
      if(sscanf(s2, "%s,%s", s1, tmp) != 2) s1 = s2;
      ob = search_next(s1, ob);
      s2 = tmp;
   }
   return ob;
}

search_all(str) {
   object ob;
   if(!str) { Error("No arg to search_all()."); return 1; }
   if(str == "rem") ob = rem_obj;
   else if(str == "arg") ob = last_arg;
   else if(str == "old") ob = old_rem_obj;
   else if(str == "me") ob = fob;
   else if(str == "env") ob = environment(fob);
   if(!ob) ob = present(str, fob);
   if(!ob) ob = present(str, environment(fob));
   if(!ob) ob = find_object(str);
   if(!ob) ob = find_living(str);
   if(!ob) ob = find_living("ghost of " + str);
   return ob;
}

search_next(str, obj) {
   int nr;
   if(sscanf(str, "%d", nr) == 1)
      return nr_in_ob(nr, obj);
   else if(str == "env")
      return environment(obj);
   return present(str, obj);
}
nr_in_ob(n, obj) {
   object ob;
   int nr;
   nr = n;
   if((nr < 0) || !obj) return 0;
   ob = first_inventory(obj);
   while(ob && nr) {
      ob = next_inventory(ob);
      nr -= 1;
   }
   return ob;
}
query_rem() { return rem_obj; }
query_old_rem() { return old_rem_obj; }
query_arg() { return last_arg; }
