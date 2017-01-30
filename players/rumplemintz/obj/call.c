inherit "/obj/treasure";

void reset(int arg){
   if(arg) return;
   set_short("Boxers");
   set_long("\
      Rumplemintz's boxer shorts.\n");
}

void init(){
   ::init();
   add_action("remote_call", "rcall");
}

varargs void remote_call(mixed obj, string func, mixed data){
   if(stringp(obj)) obj = find_object(obj);
   else
      if(!objectp(obj)) return;
   
   call_other(obj, func, data);
}
