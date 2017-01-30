/* Inherited from Vaxman (open file ebow) for the wield_func */
/*  Editing help from Rigs :)  */
 
inherit"/obj/weapon";
 
reset(){
/*
  ::create();
*/
   set_alias("shotgun");
   set_name("nerf shotgun");
   set_alt_name("gun");
   set_short("Nerf Shotgun");
   set_long(
     " This is the Nerf Pump-Action Shotgun.  It rapidly fires little nerf balls"+
  "\n"+
     " with precision and accuracy.  An excellent ballistic weapon for newbies."+
"\n"+
     " It is lightweight, yet effecient.\n"+
     " You can 'pump' it, to show monsters you mean business.\n"+
     " You can 'twirl' it, to look cool.\n"+
     " It also allows you to 'pop' other players on the Mud.\n");
   set_class(11);
   set_value(200);
   set_weight(2);
   set_hit_func(this_object());
   set_wield_func(this_object());
}
 
weapon_hit(attacker){
   if(random(5) == 2 ){
     write("POP!!POP!!POP!!  The Nerf Shotgun unloads a barrage on "+
attacker->query_name()+".  POP!!POP!!POP!!\n");
     say("POP!!POP!!POP!!  The nerf shotgun unloads a barrage of Screaming Yellow"+
" Nerf Balls from Hell on "+attacker->query_name()+".\n"+
     "POP!!POP!!POP!!POP!!POP!!POP!!POP!!\n");
     return 6;
   }
}
 
damage() { return 0; }
 
wield(ob){
    write("Your eyes glimmer with mischief as you wield the Nerf Shotgun.\n");
    say(this_player()->query_name()+"'s eyes glimmer with mischief as a Nerf Sho"+
"tgun is wielded.\n");
    return 1;
}
 
init(){
  ::init();
  add_action("pop","pop");
  add_action("pump","pump");
  add_action("twirl","twirl");
}
 
pop(str){
  object who;
  if (!str) {
    write("You 'pop' yourself in the head a few shots, POP POP POP!!!\n");
    return 1;
  }
  if(!find_living(str)){
    write("Thats nice, try and blow away someone not on, DON'T think SO!!\n");
    return 1;
  }
  who = find_living (str);
  if(who == this_player()) {
    write("You 'pop' yourself in the head a few shots, POP POP POP!!!\n");
    return 1;
  }
  if ( (who->query_level() > 20) && (this_player()->query_level() < 21) ) {
    write("Are you crazed???  You think better of it and pop yourself instead.\n"+
"\n");
    pop(this_player()->query_real_name());
    return 1;
  }
  tell_object(who, "POP!!POP!!POP!!! You are knocked to the floor by a barage of"+
 "Screaming Yellow\n"+
    "  Nerf Balls from Hell.\n"+
    "You hear "+this_player()->query_name()+" laugh loudly in the distance.\n");
  write("You pump up the Nerf Shotgun and proceed to blow "+capitalize(str)+
" away!!!\n"+
    "You hear a yelp of pain as you realize you have struck your target...repeat"+
"edly!\n");
  say("Hundreds of Screaming Yellow Nerf Balls from Hell fly into the room\n"+
    "   and in a continuous stream pelt "+capitalize(str)+ "!!\n"+
  "As the barrage stops, you can barely make out "+this_player()->query_name()+
"'s hideous laughter\n"+
    "    over "+capitalize(str)+"'s whimpering.\n");
  return 1;
}
 
pump() {
  write("You slowly and menacingly pump the shotgun...\n");
  say(this_player()->query_name()+" slowly and menacingly pumps the Nerf Shotgun"+
 "a few times.\n");
   return 1;
}
 
twirl() {
  write("You slickly and cooly twirl the shotgun about...\n");
  say(this_player()->query_name()+" slickly and cooly twirls the Nerf Shotgun ab"+
"out.\n");
  return 1;
}
