inherit "obj/weapon";
reset(arg) {
::reset(arg);
        if(!arg) {
               set_name("idcard");
set_alias("card");
                set_class(5);
               set_value(10);
               set_weight(2);
              set_alias("card");
               set_short("A ID card");
set_long("An IIT student ID card.\n");
set_hit_func(this_object());
}
}
weapon_hit(attacker)
  {
if(random(100) < 20) 
{
return 5;
}
}
