inherit "obj/armor";
reset(arg){
   ::reset(arg);
call_out("duh",9);
call_out("duhh",8);
call_out("duhhh",4);
   set_short("Basic Armor");
   set_long("This is a basic armor.\n");
   set_ac(4);
   set_weight(3);
   set_value(5000);
   set_alias("basic");
   set_name("basic");
   set_type("armor");
}
duh()
{
if (!environment()) return 1;
tell_object(environment(this_object()),"It gone.\n");
destruct(this_object());
return 1;
}
duhh()
{
   if(!environment()) return 1;
   tell_object(environment(this_object()),"It almost gone.\n");
   return 1;
}
duhhh()

{
   if(!environment()) return 1;
   tell_object(environment(this_object()),"Its sorta gone.\n");
   return 1;
}
