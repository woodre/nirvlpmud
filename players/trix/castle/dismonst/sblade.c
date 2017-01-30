/* Raised from wc10 to wc15 -Feldegast 9-23-00 */
inherit "obj/weapon";

reset(arg){
   if(arg) return;
   ::reset(arg);
   set_name("switchblade");
   set_alt_name("blade");
   set_alias("blade");
   set_short("A switchblade");
   set_long("A nice looking pentagram , it could hurt if thrown on your face.\n");
   set_class(15);
   set_weight(2);
   set_value(240);
}
