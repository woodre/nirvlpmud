inherit "obj/weapon";
int oldsp, oldhp, hp;
object owner;
int charge;
int oldcharge;
int die, attacker, pain;
reset(arg) {
::reset(arg);
        if(!arg) {
                set_name("sword");
                set_class(12);
                set_value(300);
                set_weight(5);
                set_alias("sword");
                set_hit_func(this_object());
set_short("The sword of Bone");
set_long("This is a sliver of a Skeleton dragon, the edges of it are\n"+
         "very sharp.\n");
}
}
init() {
   add_action("hp","hp"); 
}
heart_beat() { 
   int newhp, newsp, maxhp, maxsp;
   maxhp = owner->query_mhp();
   maxsp = owner->query_msp();
   newhp = owner->query_hp();
   newsp = owner->query_sp();
   if (hp && (newhp != oldhp || newsp != oldsp || oldcharge != charge)) {
      tell_object(owner,"HP: "+newhp+" ("+maxhp+")   SP: "+newsp+" ("+maxsp+")"+
         "   CHARGE: "+charge+" (800)\n");
      oldhp = newhp;
      oldcharge = charge;
      oldsp = newsp;
   }
   
}
hp() {
   write("You toggle your hp monitor ");

   hp = !hp;
   set_heart_beat(hp);
   if (hp) write("on\n");
   else write("off\n");
   return 1;
}
