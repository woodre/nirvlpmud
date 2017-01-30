inherit "obj/armor";

reset(arg){
   ::reset(arg);

   set_name("vest");
   set_alias("bracers");
   set_short("A matching leather vest and bracers");
   set_long(
"A tough brown leather vest, tough but flexible, along with a pair of stiff\n"+
"bracers with large semi-precious gems set into them make for a formiddable\n"+
"appearance, though not the world's best protection.  A small tag on the\n"+
"inside of the vest boasts that it was provided by someone named Salmoneus\n"+
"for Hercules.\n");
   set_ac(3);
   set_weight(3);
   set_value(1000);
}
