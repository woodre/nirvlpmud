inherit "obj/treasure";

reset(arg) {
   if(arg) return;
   set_id("arm");
   set_alias("potato_arm");
   set_short("A plastic arm");
   set_long("The plastic arm looks like it may belong to a... potato?\n");
   set_value(30);
   set_weight(1);
}
