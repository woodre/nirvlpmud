inherit "obj/weapon";
  
  int i;
  reset (arg){
 ::reset (arg);
if(!arg) {    
set_name("Pred blades");
set_alias("blades"); 
set_short("Predator blades");
set_long("<<<<<* Blades of the Predator Champion *>>>>>\n"+ 
"There are four 12 inch serated blades composed of an unknown metal.\n"+  
"The blades seem to bond with the owner's wrist and hand.  The blades\n"+ 
"when attached move as if they were actual digits of the owners hand.\n"+  
"As you put them on you as though you yourself were the predator!\n");
set_class(18);
set_weight(4);
/* Changed value from 50,000 to 1,000. These values are ridiculous. -Snow */
set_value(1000);
set_type("exotic");
}
set_hit_func(this_object());
}
query_save_flag() {return 1;}
 
weapon_hit(attacker){
i=random(40);
if (i<1) {
write("You kill with the grace and purity of God.\n");
say ("The stench of blood makes you lose faith.\n");
this_player()->heal_self(-3-random(10));
return 12;
}       
if (i< 4){
write("As the hate of the world pulses through your vein: You take another soul\n");
say(this_player()->query_name()+" convulses as the hate of the world flows through him.\n");
this_player()->heal_self(-random(8));
return 8;
}               
if (i< 8) {
write ("You remove their opponents' head with the flick of your wrist.\n");
say("Blood flies as the claws of the predator inflict a final blow\n");
return 5;
}
if (i<=10){
write("The Predator's spirit lives through you!\n");
return 2;
}
return 0;
}        
