inherit "/players/mizan/core/object.c";

reset(arg)
{
   ::reset(arg);
   if(arg) return;


   set_get(0);

   set_short("A beat-up, old sofa");
   set_long("  This is a beat-up, dirty old sofa that looks like it was hauled\n"+
      "  off the street and rescued from certain doom. For whatever reason,\n"+
      "  it is now here, in Mizan's office.\n");

   set_name("sofa");


   set_smell("The sofa smells a lot like.. graham crackers.\n");
   set_taste("The sofa tastes quite like... dusty graham crackers.\n");
}
