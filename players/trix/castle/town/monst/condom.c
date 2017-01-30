inherit "obj/armor";
init(){
   add_action("don","wear");
   add_action("wear", "jkjkjkjk");
   add_action("remove", "remove");
   add_action("take_off", "unwear");
}
reset(arg){
   ::reset(arg);
   set_short("A condom");
   set_long("This is a colored condom.  It's somewhat protective.\n");
   set_ac(1);
   set_weight(1);
   set_value(100);
   set_alias("condom");
   set_name("condom");
   set_type("armor");
}

don(arg){
   string sex;
   if(!arg){
      return 0;
   }
   if(arg!= "condom"){
      return 0;
   }
   if(arg == "condom"){
      sex=this_player()->query_gender();
      if (sex == "male"){
         command("jkjkjkjk condom",this_player());
         return 1;
      }
      else{
         write("Sorry.  You don't have anywhere to put it.\n");
         return 1;
      }
   }
}
