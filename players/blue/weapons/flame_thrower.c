inherit"obj/weapon";

reset(arg) {
   
   if(!arg) {

   set_name("thrower");
   set_alias("flame thrower");
   set_short("A HUGE flame thrower");
   set_long(
"This is a massive weapon of huge power.  A constant small flame licks the\n"+
"end of the long barrel, with a slight hissing sound.  There is a trigger"+
"on\nthe handle, and it seems like its use is pretty...straightforward.\n");
   set_class(19);
   set_weight(10);
   set_value(2000);
   }
}

