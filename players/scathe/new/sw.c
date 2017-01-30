inherit "obj/treasure";

reset(arg)   {
   if(arg) return;

   set_id("A Steveweiser");
   set_alias("beer");
   set_alias("steveweiser");
   set_short("An ice cold Steveweiser in a can");
   set_long("A fine beverage enjoyed by Stone Cold Steve Austin.\n"+
   "It is cold and looks mighty refreshing.  You better watch out\n"+
   "for Stone Cold, he doesn't want like to share!\n");
   set_weight(1);
   set_value(200);
}
