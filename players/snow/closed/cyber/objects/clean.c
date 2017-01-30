int no_clean;
clean_up() {
   if (no_clean) return 1;
  if(environment(this_object())) {
    if (call_other(environment(this_object()), "query_npc",0)){
      return 1;
    }
   if (call_other(environment(this_object()), "query_interactive",0))
    return 1;
  }
    if(this_object()->query_npc())
    dest_inv();
/*
    destruct(this_object());
*/
    destruct(file_name(this_object()));
    destruct(this_object());
    return 1;
    }
dest_inv(){
     object list_no;
  int t,k;
   list_no = allocate(70);
  list_no = all_inventory(this_object());
  k = sizeof(list_no);
   t=0;
   while(t < k){
/*
      destruct(list_no[t]);
*/
      destruct(file_name(list_no[t]));
      destruct(list_no[t]);
      t += 1;
   }
   return 1;
}
set_no_clean(arg){
  no_clean=arg;
}
