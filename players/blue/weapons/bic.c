inherit"obj/weapon";

reset(arg) {
   object ob;

   if(!arg) {

   set_name("bic");
   set_weight(1);
   set_value(1000);
   set_class(14);
   set_alias("lighter");
   set_short("A bic lighter");
   set_long("It has a round cylnder that makes sparks when you turn it."+
   "there is also a\nbutton on the side that lets gas out.  Hmmm...\n");
   }
}
id(str) { return (::id(str) || str=="bic lighter"); }
