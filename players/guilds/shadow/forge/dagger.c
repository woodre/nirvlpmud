inherit"obj/weapon";

reset(arg) {
   if(arg) return;

   set_class(8);
   set_name("dagger");
   set_value(0);
   set_short("A Shadow Dagger");
   set_long("This is a Shadow Dagger.  It appears to be a good dagger, made "+
            "from\nvery dark steel.\n");
   set_weight(3);
}
