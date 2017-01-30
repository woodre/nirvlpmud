inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;
   set_name("teeth");
  set_alias("teeth");
  set_short("teeth");
  set_long("The teeth are shining white, and very sharp.\n"+
    "They gleam in the light.\n"+"\nYou  T R E M B L E  as you behold"
+"them.\n\n");
  set_class(30);
  set_weight(1);
  set_value(300);
  set_hit_func(this_object());
}
 weapon_hit(attacker){
int W;
W = random(22);
if(W>11)  {
  say("The TEETH tear into the flesh of their foe.\n"+
    "\nBlood spurts everywhere.\n\n");
   write("You slice into your foe's flesh, tearing chunks of meat out.\n"+
"Blood from your foe spurts everywhere.\n"
+"\n       Feels GOOD doesn't it?\n\n");
return(random(100));
    }
   return;
}
