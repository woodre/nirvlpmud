inherit "obj/armor";
reset(arg){
   ::reset(arg);

   set_name("slave collar");
   set_short("A slave's collar");
   set_alias("collar");
   set_long("A black leather slave's collar. This collar designates ownership by\n"+
        "another. It has a small tag hanging from it that reads:\n\n"+
          "             Property of Daranath\n\n");
   set_type("amulet");
   set_ac(1);
   set_weight(1);
   set_value(450);
}
