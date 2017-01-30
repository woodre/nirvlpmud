inherit "obj/armor";
reset(arg) 
{
   ::reset(arg);
if (arg) return;
   set_name("chainmail");
  set_alias("elven chainmail");

set_short("Elven Chainmail");

set_long(
"This is finely crafted elven chainmail. It provides excellent protecrtion and does not weigh very much.\n");
   set_type("armor");
   set_ac(3);
   set_weight(1);
   set_value(3000);
}
