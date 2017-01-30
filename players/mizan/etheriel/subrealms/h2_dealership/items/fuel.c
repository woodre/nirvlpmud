inherit "/players/mizan/core/object.c";

reset(arg)
{
   ::reset(arg);
   if(arg) return;

   set_get(1);
   set_value(100);
   set_weight(10);
   set_name("drum");
   set_alias("gasoline");

   set_short("A 55 gallon oil drum");
   set_long("This is a large, heavy tank filled with gas, instead of oil for some reason.\n"+
            "You wonder what the hell could possibly consume all this fuel in one shot!\n");

   set_read("The oil drum has the word 'Exxon' written all over it.\n");
   set_smell("The oil drum reeks of gasoline.\n");
   set_taste("The oil drum itself is cold and pungent to taste.\n");
}

query_fuel() { return 50; }