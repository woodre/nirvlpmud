/* added ::reset(); and set_type - weight changed to 2.  
    verte 6.19.01 */

/* Value changed from 1000 to 300. Wc from 17 to 15. It's a pencil, a special pencil, but a pencil nonetheless. -Snow 2/00 */
/* approved by mythos on 10/26/95   please talk to him if there is a problem  */

inherit "obj/weapon.c";
reset(arg) {
    if (arg) return;
    ::reset(); /* moved here by verte */
    set_name("pencil");
    set_alias("pencil");
set_short("A Sharp Pencil");
set_long("A long sharp pencil, looks like it could be deadly...\n");
    set_type("knife"); /* added by verte */
    set_class(15);
    set_weight(2);
    set_value(300);
    set_hit_func(this_object());
}
weapon_hit(attacker){
int w,n,ahp;
/* Added by Snow 4/99 */
  if(!this_player() || !this_player()->is_player()) return 0;
   if(call_other(this_player(), "query_attrib", "str") > random(50)) {
write("You jab your enemy in the eye with your sharp pencil.\n");
   n=random(10);
write("The Pencil is covered with the blood of your enemy!\n");
      return n;
   }
   return;
}
