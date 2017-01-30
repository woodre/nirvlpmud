#define ENVO environment(this_object())
inherit "obj/armor";
reset(arg){
   ::reset(arg);
   set_name("sangre");
   set_short("Sangre, the hoplite shield");
   set_alias("shield");
   set_long(
"Sangre is a blood red hoplite shield nearly 2 meters in length. \n"+
"As you peer closer, you see the surface of the shield shimmer \n"+
"and writh in a dreadfully familiar pattern. You can feel your \n"+
"heart beat faster from adreneline pumping through your veins.\n"+
"The shield seems to adjust its movements to match the rapid \n"+
"THUMP THUMP THUMP THUMP\n"+
"of your heart... You quickly look away.\n");
   set_type("shield");
   set_ac(3);
   set_weight(5);
   set_value(15000);
   call_out("sangre",20);
}
 
sangre() {
int W;
if(worn) {
  W = random(20);
  if(W > 6) {
say("Sangre adds a little blood to your body!\n");
call_other(ENVO,"add_hit_point",(random(5)));
call_other(ENVO,"add_spell_point",-(random(2)));
call_out("sangre",20);
return 1;
     }
if(W < 1) {
say("Sangre sucks some life from you!\n");
call_other(ENVO,"add_hit_point",(-(random(6))));
call_out("sangre",20);
return 1;
   }
call_out("sangre",20);
return 1;
  }
call_out("sangre", 50);
return 1;
}
