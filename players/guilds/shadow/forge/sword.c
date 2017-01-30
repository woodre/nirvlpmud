inherit"obj/weapon";

reset(arg) {
   if(arg) return;

   set_class(12);
   set_name("sword");
   set_value(0);
   set_short("A Shadow Sword");
   set_long("This is a Shadow Sword.  It appears to be a fine sword, made "+
            "from\nvery dark steel.\n");
   set_weight(2);
}
