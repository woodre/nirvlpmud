#define TPN this_player()->query_name()
#define ATN attacker->query_name()
  object part;
  int i;
inherit"obj/weapon";
reset(arg) {
  ::reset(arg);
   if(arg) return;
set_name("disc");
set_alias("disk");
set_short("Tron's deadly disc *glowing*");
set_long("Tron's disc glows a neon blue.\n"+
         "It may be a usefull weapon in the REAL WORLD,\n"+
         "Tron benefitted from the use of this powerful device\n"+
         "more than once.\n"+
         "With it, he was able to conquer the evils in the Master Computer\n"+
         "and let freedom reign... Go now, In faith, Tron will follow.\n");
set_value(10);
set_class(21);
set_hit_func(this_object());
}
  weapon_hit(attacker) {
   if(attacker->is_pet()){
   attacker->add_hit_point(-50);
} 
 i = random(100);
  if(i > 97){
write("You throw the disc in the direction of "+ATN+".\n");
write("the disc leaves your hand, and glides twords "+ATN+".\n");
write(ATN+" looks at the disc coming at them, "+ATN+" is unable to move\n");
write("out of the way of the speeding disc.\n");
write(ATN+"'s arm falls off and hits the ground with a **THUD**.\n");
say(TPN+" throws their disc in the direction of "+ATN+".\n");
say("the disc leaves their hand, and glides twords "+ATN+".\n");
say(ATN+" sees at the disc coming at them, "+ATN+" is unable to move\n");
say("out of the way of the speeding disc.\n");
say(ATN+"'s arm falls off and hits the ground with a **THUD**.\n");

attacker->heal_self(-random(20));
return 3;
}
 if((i>94)&&(i<97)){
write("You throw the disc in the direction of "+ATN+".\n");
write("the disc leaves your hand, and glides twords "+ATN+".\n");
write(ATN+" looks at the disc coming at them, "+ATN+" is unable to move\n");
write("out of the way of the speeding disc.\n");
write(ATN+"'s leg falls off and hits the ground with a **THUD**.\n");
say(TPN+" throws their disc in the direction of "+ATN+".\n");
say("the disc leaves their hand, and glides twords "+ATN+".\n");
say(ATN+" sees at the disc coming at them, "+ATN+" is unable to move\n");
say("out of the way of the speeding disc.\n");
say(ATN+"'s leg falls off and hits the ground with a **THUD**.\n");

attacker->heal_self(-random(20));
return 3;
}
 if((i>20)&&(i<22)){
write("You throw the disc in the direction of "+ATN+".\n");
write("the disc leaves your hand, and glides twords "+ATN+".\n");
write(ATN+" looks at the disc coming at them, "+ATN+" is unable to move\n");
write("out of the way of the speeding disc.\n");
write(ATN+"'s nose falls off and hits the ground with a **THUD**.\n");
say(TPN+" throws their disc in the direction of "+ATN+".\n");
say("the disc leaves their hand, and glides twords "+ATN+".\n");
say(ATN+" sees at the disc coming at them, "+ATN+" is unable to move\n");
say("out of the way of the speeding disc.\n");
say(ATN+"'s nose falls off and hits the ground with a **THUD**.\n");

attacker->heal_self(-random(20));
return 3;
}
 if((i>30)&&(i<33)){
write("You throw the disc in the direction of "+ATN+".\n");
write("the disc leaves your hand, and glides twords "+ATN+".\n");
write(ATN+" looks at the disc coming at them, "+ATN+" is unable to move\n");
write("out of the way of the speeding disc.\n");
write(ATN+"'s pubic hairs fall off and hits the ground making no sound.\n");
say(TPN+" throws their disc in the direction of "+ATN+".\n");
say("the disc leaves their hand, and glides twords "+ATN+".\n");
say(ATN+" sees at the disc coming at them, "+ATN+" is unable to move\n");
say("out of the way of the speeding disc.\n");
say(ATN+"'s pubic hairs fall off and hits the ground making no sound.\n");

attacker->heal_self(-random(10));
return 3;
}
 if((i>40)&&(i<43)){
write("You throw the disc in the direction of "+ATN+".\n");
write("the disc leaves your hand, and glides twords "+ATN+".\n");
write(ATN+" looks at the disc coming at them, "+ATN+" is unable to move\n");
write("out of the way of the speeding disc.\n");
write(ATN+"'s intestine falls out and hits the ground ...**SPLAT**\n");
say(TPN+" throws their disc in the direction of "+ATN+".\n");
say("the disc leaves their hand, and glides twords "+ATN+".\n");
say(ATN+" sees at the disc coming at them, "+ATN+" is unable to move\n");
say("out of the way of the speeding disc.\n");
say(ATN+"'s intestines falls out and hits the ground ...**SPLAT**\n");

attacker->heal_self(-random(20));
return 3;
}
 if((i==69) || (i==68)){
if(random(14)){
write("You throw the disc in the direction of "+ATN+".\n");
write("the disc leaves your hand, and glides twords "+ATN+".\n");
write(ATN+" looks at the disc coming at them, "+ATN+" is unable to move\n");
write("out of the way of the speeding disc.\n");
write(ATN+"'s scalp falls off and floats to the the ground.\n");
say(TPN+" throws their disc in the direction of "+ATN+".\n");
say("the disc leaves their hand, and glides twords "+ATN+".\n");
say(ATN+" sees at the disc coming at them, "+ATN+" is unable to move\n");
say("out of the way of the speeding disc.\n");
say(ATN+"'s scalp falls off and floats to the ground.\n");

attacker->heal_self(-random(125));
}
return 3;
}
if (i >= 70 && i <= 79) {
if(random(50) < 13){
write("You throw the disc in the direction of "+ATN+".\n");
write("the disc leaves your hand, and glides twords "+ATN+".\n");
write(ATN+" looks at the disc coming at them, "+ATN+" moves\n");
write("out of the way of the speeding disc.\n");
write("The disc circles around "+ATN+" and flies right AT you!\n");
write("You fly and panic, but cannot get out of the way.\n");
say(TPN+" throws their disc in the direction of "+ATN+".\n");
say("the disc leaves their hand, and glides twords "+ATN+".\n");
say(ATN+" sees at the disc coming at them, "+ATN+" moves\n");
say("out of the way of the speeding disc.\n");
say(ATN+" laughs at the disc flies back twords "+TPN+".\n");
say(TPN+" screams as their disc flies back and cuts them deep.\n");
this_player()->add_hit_point(-55);
return 1;
}
return -6;
}
 if (i < 14){
write("You pull your pants down and moon "+ATN+".\n");
write(ATN+" sees you, and falls down laughing, allowing you to get\n");
write("a second atack in.\n");
write("You MASSACRE "+ATN+" into tiny fragments.\n");
say(TPN+" pulls their pants down, and moons "+ATN+".\n");
say(ATN+" starts to laugh so hard they aren't paying attention,\n");
say("allowing "+TPN+" to get a quick second attack in.\n");
say(TPN+" >>MASSACRES<< "+ATN+" into tiny fragments.\n");
attacker->heal_self(-random(10));
return 6;
}
return 2;
}
