inherit "room/room";
 
reset(arg){
 
 if(!arg){
 
 set_light(1);
  short_desc="Volcano Core";
 long_desc=
"You have appeared in the core of a volcano. Poisonous gasses swirl about\n"+
"you and the heat is nearly unbearable. You are standing on what appears\n"+
"to be a thin layer of hardened lava. If you don't escape soon, you know\n"+
"you will die. There is a hole in the lava-rock a short distance away. The\n"+
"volcano walls are unscaleable.\n";
 
items=({
"volcano","You are in the core of a semi-active volcano\n"
"gasses","Acidic, poisonous gasses are swirling about you\n"
"hole","Your facial skin peels off as you look into this hole. The heat is\n"+
"unbearable here but in the brief instance that you were able to look, you\n"+
"saw what appeared to be a glowing portal in the lava below. Do you dare\n"+
"to dive into the inferno?\n"
          });
 
dive (arg)  {
if (arg == "into the inferno") {
write (
"You throw yourself headlong into the inferno! Fire burns over your body as\n"+
"you approach the lava below. You lose consciousness.\n");
hit_player(this_player(), (random (50)+ 10));
move_object(this_player(),"/players/snow/elem/inferno.c");
write(
"\n"+"\n"+"You wake up in a strange shadowy place.\n");
return 1;
}}
  }   }
 
 
