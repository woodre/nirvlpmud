inherit "/players/mizan/core/object.c";

reset(arg)
{
   ::reset(arg);
   if(arg) return;


   set_get(0);
   set_short("A long wooden sign");
   set_long("The sign reads:\n\n"+
  "Llanfairpwllgwyngyllgogerychwyrndrobwillllantysiliogogogoch, Wales. 10km.\n");

   set_name("sign");

   set_read("The sign reads:\n\n"+
  "Llanfairpwllgwyngyllgogerychwyrndrobwillllantysiliogogogoch, Wales. 10km.\n");

   set_smell("The sign smells like dirt.\n");
   set_taste("The sign tastes like dirt!\n");
}



