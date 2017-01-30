inherit "/obj/weapon.c";

id(str) { return str=="sickle"; }
void reset(int arg) {
   ::reset(arg);
   if(arg) return;
   set_name("sickle");
   set_short("A plastic sword");
   set_long(
      "This is a plastic sword.  It is used by kids around the world\n" +
      "to pretend they are real fighters.\n"
   );
   set_type("sword");
   set_class(200);
   set_weight(2);
   set_value(0);
}
