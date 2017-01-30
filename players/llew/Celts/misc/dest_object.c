reset(arg) {
   if(arg) return;
   kill();
}

kill() {
   object ob,ob2;
   ob=first_inventory();
   while(ob) {
      ob2=next_inventory(ob);
      destruct(ob);
      ob2=ob;
   }
   call_out("kill",600);
}
