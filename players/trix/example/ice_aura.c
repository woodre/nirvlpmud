inherit "obj/armor";
init(){
   add_action("don","wear");
    add_action("wear", "jkjkjkjk");
    add_action("remove", "remove");
    add_action("take_off", "unwear");
}
reset(arg){
   ::reset(arg);
   set_short("Icy aura");
   set_long("This is a aura of frost that hugs the\n"+
      "body and may be donned as armor. The\n"+
      "extreme cold it radiates protects its\n"+
      "wearer like no other. Due its nature,\n"+
      "only women may (don) it.\n");
   set_ac(4);
   set_weight(1);
   set_value(10000);
   set_alias("icy aura");
   set_name("aura");
   set_type("armor");
}
don(arg){
   string sex;
   if(!arg){
      return 0;
   }
   if(arg!= "aura"){
      return 0;
   }
   if(arg == "aura"){
      sex=this_player()->query_gender();
      if (sex == "female"){
         command("jkjkjkjk aura",this_player());
         return 1;
      }
      else{
         write("Sorry, but that would not fit you properly.\n");
         return 1;
      }
   }
}
