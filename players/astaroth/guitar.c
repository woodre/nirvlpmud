inherit "obj/weapon";
reset(arg) {
   if(!arg) 
      ::reset(arg);
   set_name("guitar");
   set_class(18);
   set_weight(4);
   set_value(4000);
   set_short("An Ibanez guitar");
   set_long("It belongs to Joe Satriani and is used to awesome playing.\n" +
      "It is deadly in the right hands.\n" +
      "");
}
