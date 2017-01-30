inherit "obj/armor";
reset(arg){
   ::reset(arg);
   set_short("Gold Ring");
set_long("This is a soft glowing gold ring.\n");
   set_ac(1);
   set_weight(1);
   set_value(300);
   set_alias("ring");
   set_name("ring");
   set_type("ring");
}
init(){
   ::init();
   add_action("heal", "heal");
}
heal(str)
{
   if(!str || str == "") return;
   if(str == "me")
   {
this_player()->heal_self(100);
{
   write("You are healed by the power of Nightshade!\n");
}
  destruct(this_object());
   return 1;
}
}
