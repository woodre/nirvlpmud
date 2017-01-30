inherit "obj/armor";
init(){
   add_action("don","wear");
   add_action("wear", "jkjkjkjk");
   add_action("remove", "remove");
   add_action("take_off", "unwear");
}
reset(arg){
   ::reset(arg);
   set_short("A leather jumpsuit");
   set_long("This is a black leather jumpsuit , a very sexy dress and nice to be worn in disco.\n");
   set_ac(3);
   set_weight(1);
   set_value(1500);
   set_alias("suit");
   set_name("jumpsuit");
   set_type("armor");
}

don(arg){
   string sex;
   if(!arg){
      return 0;
   }
   if(arg!= "jumpsuit"){
      return 0;
   }
   if(arg == "jumpsuit"){
      sex=this_player()->query_gender();
      if (sex == "female"){
         command("jkjkjkjk jumpsuit",this_player());
         return 1;
      }
      else{
         write("Ahahaha, naaaaa, it would look horrible on you.\n");
         return 1;
      }
   }
}
