inherit "obj/treasure";

reset(arg) {
   if(arg) return;
   set_id("parrot");
   set_short("A dead parrot");
   set_long("This parrot has been long dead.  It's feathers are\n"+
            "grayish and dingy.  Looking close, you see it is actually plastic.\n");
     /* in verteLand, everything has a value! [5.31.01] */
   set_value(1 + random(4));
   set_weight(1);
}
