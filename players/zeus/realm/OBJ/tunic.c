inherit "obj/armor";

reset(arg){
   ::reset(arg);

   set_name("tunic");
   set_short("Leather tunic");
  set_long(
"This is a very old leather tunic.  It has seen many battles, and each\n"+
"and every one is visible upon it.  In some places it is multilayered,\n"+
"and although it probably won't provide much protection, it ought\n"+
"to be somewhat warm.\n");
  set_type("armor");
  set_ac(2);
  set_weight(1);
  set_value(1000);
}
