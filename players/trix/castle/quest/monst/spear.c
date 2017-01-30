inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
   set_name("spear");
   set_alt_name("steel spear");
   set_alias("steelspear");
   set_short("A steel spear");
   set_long("This is a steel forged spear, used by the guards of the Buried Land.\n");
   set_class(15); /* From wc11 to wc15 for thematic reasons. -Feldegast 9-23-00 */
   set_weight(1);
   set_value(500);
}
