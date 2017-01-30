inherit "obj/weapon";
int i;
reset(arg) {
::reset(arg);
if(arg) return;
       set_alias("sword");
       set_name("Jewel Sword");
       set_short("Jewel Sword");
  set_long("A beautiful sword covered with precious gems.\n"+
      "There seems to be something written on the hilt.\n"+
      "Type: help jewel sword  to read.\n");
       set_class(14);
       set_weight(4);
       set_value(10000);

set_hit_func(this_object());

 call_other(this_object(), "set_save_flag", 0);
}
weapon_hit(attacker) {
i=random(50);

if (i>35) {
say(this_player()->query_name()+"'s Jeweled Sword spews a gulf of fire!\n");
write("The jeweled Blade spews a stream of fire!\n");
return 10;
  }
return 7;
}
init() {
  ::init();
 add_action("whirl_wind","whirlwind");
  add_action("whirl_wind", "wwind");
 add_action("death", "death");
 add_action("help", "help");
}

whirl_wind(str) {
   object ob, obj1;
   int exp;
  if(this_player()->query_sp() < 30) {
 write("You do not have enough magical energy for this.\n");
  return 1;
}
  if(!str) {
  write("Who do you want to Chop up?\n");
  return 1;
}
  ob = present(lower_case(str), environment(this_player()));
  if(!ob) {
  write("That object is not here!\n");
  return 1;
  }
ob->hit_player(random(20)+15);
   call_other(this_player(), "add_spell_point", -30);
  present(ob, environment(this_player()))->attacked_by(this_player());
 write("You call apon the magical energy of ths sword to send it\n"+
"whirling into motion faster than the eye can see.  You chop down\n"+
 "down your oppenent in a flury of attacks!\n");
say(this_player()->query_name() + " whirls the Jewel Blade in fast\n"+
"deadly strokes. "+ this_player()->query_name() +"'s blade shreds "+capitalize(str)+" into little pieces.\n");
    this_player()->add_exp(exp);
   return 1;
}
 death(str) {
   int dmg;
 object ob;
    int exp;
 if(this_player()->query_sp() < 100) {
   write("You do not have enough magical energy to do this.\n");
  return 1;
}
 if(!str) {
   write("Destroy who?\n");
}
  ob = present(lower_case(str), environment(this_player()));
  if(!ob->query_npc()){
  write("Nice try!\n You can't use this spell on Players!\n");
   return 1;
 }
   if(!ob) {
   write("That object is not here!\n");
   return 1;
   }
   if(!(this_player()->query_attack())) {
   write("You must be attacking first!\n");
           return 1;
     }
  if(this_player()->query_real_name()=="pavlik") {
   call_other(this_player(), "add_spell_point", -100);
   dmg = ob->query_hp();
    call_other(ob, "add_hit_point", -10000);
     this_player()->add_exp(exp);
      destruct(this_object());
write("You gather your magical power about you.  Concentrating\n"+
  "all your energy on your target, you hurl your blade at it's\n"+
  "heart. The sword strike deep into "+capitalize(str)+"'s heart.\n"+
  "The Jewel Sword then blows up into thousands of pieces" +
"\ntaking "+capitalize(str)+" with it!\n");

 say("A beautiful jeweled sword is launched into the air...it speeds\n"+
"straight into the body of "+capitalize(str)+" where the blade glows\n"+
"for a moment, then exploades into thousands of pieces taking "+
  capitalize(str)+" with it!\n");
return 1;
}

   write("I'm sorry but this function has been removed until i can\n"+
  "work the bugs out of it..Whirlwind still works perfectly fine and\n"+
   "the Natural WC of this weapon makes it worth while...this will\n"+
   "be fixed ASAP.    thanks, PAV\n");
        return 1;
  }
help(str) {
 if(str == "jewel sword"){
 write("This is the Jewel Blade.  A very Powerful and\n"+
 "Dangerous weapon.  The Jewel blade has two major functions:\n"+
 "Whirlwind (target).   Costs 30sp, sends the Blade into a\n"+
 "whirlwind, doing substantial damage to the unlucky target.\n\n"+
"You can use: wwind <target> also.\n"+
"Death (target).   Costs 100sp and will also requires the destruction\n"+
"if this object.  It will outright kill the target.\n"+
"Even without these magical abilites you can still wield and fight\n"+
"with the blade, however these abilites make it a truly awesome weapon!\n");

  return 1;
}
}
