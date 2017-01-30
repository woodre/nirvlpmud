inherit "obj/food";
 
reset(arg) {
  if(arg) return;
  set_name("apple");
  set_alias("apple");
  set_weight(1);
  set_value(25);
  set_strength(10);
  set_short("A magical Apple");
  set_long("This is a magical Apple because if you eat it\n"+
            "it will heal you!  DUH!\n\n");
  set_eater_mess("You take a bite of the red juicy crispy apple...\n");
  set_eating_mess(" eats a Machintosh Apple.\n");
}      
