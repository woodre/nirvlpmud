
object ob;
id(str){ return str == "shadower"; }
get(){ return 1; }
init(){
   add_action("wibble", "wibble");
   add_action("womble", "womble");
   add_action("quit", "quit");
}

wibble(str){
   string a, b;
   write("Prepare to wibble...\n");
   if(sscanf(str, "%s %s", a, b)){
      write("No spaces allowed, sorry.\n");
      return 1;
   }
   ob = clone_object("players/deathmonger/shadow");
   ob->set_name(str);
   ob->set_cap_name(capitalize(str));
   ob->set_short(str);
   ob->set_long(str);
   ob->shadow_player(this_player());
   command("refresh", this_player());
   return 1;
}

womble(){
   object frog;
   frog = ob;
   if(!frog) { write("No ob.\n"); return 1; }
   ob->stop_shadow();
   command("refresh", this_player());
   write("Terminating shadow.\n");
   return 1;
}

quit(){
   if(ob){
     write("Try getting rid of your shadow first.\n");
     return 1;
   }
   else return 0;
}
