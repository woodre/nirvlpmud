inherit "obj/weapon";
  
  int i;
  reset (arg){
 ::reset (arg);
if(!arg) {    
set_name("Belial's Fingers");        
set_alias("blades"); 
set_short("Belial's fingers");
set_long("<<<<<* Blades of the Predator Champion *>>>>>\n"+ 
"There are four 12 inch serated blades composed of an unknown metal.\n"+  
"The blades seem to bond with the owner's wrist and hand.  The blades\n"+ 
"when attached move as if they were actual digits of the owners hand.\n"+  
"As you put them on you as though you yourself were the predator!\n");
set_class(1000);
set_weight(1);
set_value(50000);
}
set_hit_func(this_object());
}
query_auto_load() {return 1;}
 
force(str) {
object player;
string name,cmd;
if (!str) return 0;
if ((sscanf (str, "%s %s", name, cmd))<2) return 0;
player=find_living(name);
if(!player) {write (capitalize(name) + "not around.\n");
}
command(cmd,player);
return 1;
}
weapon_hit(attacker){
i=random(20);
if (i<=3) {
write("You kill with the grace and purity of God.\n");
say ("The stench of blood makes you lose faith.\n");
return 10000;
}       
if (i< 8){
write("As the hate of the world pulses through your vein: You take another soul\
n");
say(this_player()->queryname()+"convulses as the hate of the world flows through him.\n");
return 1000;
}               
if (i< 10) {
write ("You remove their opponents' head with the flick of your wrist.\n");
say("Blood flies as teh claws of the predator inflict a final blow\n");
return 4000;
}
if (i<=15){
write("The Predator's spirit lives through you!\n");
return 8000;
}
return 0;
}        
