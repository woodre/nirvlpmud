inherit "obj/monster";

reset(arg){

set_name("guard");
set_alias("body guard");
set_short("A HUGE body guard");
set_long("One of numerous body guards"+
         " that roam the grounds of Graceland\n");
set_ac(0);
set_level(15);
set_al(-75);
set_aggressive(0);
set_chat_chance(50);
set_hp(250);
load_chat("Guard yells: STOP!!!!\n");
load_chat("Guard yells:  Get out of here."+
          " Elvis isn't taking any vistors today\n");
call_out("move_function",random(30),0);
::reset(0);
}


move_function(){

object ob;
int n, i;
i = random(3500);
 
   ob = first_inventory(this_object());
   if (i>3400) {
      say("The guard feeling the stress of working for Elvis turns his\n");
      say("Uzi on himself blowing his brains out sending \n");
      say("blood and flesh all over you.\n");
      destruct(ob);
      destruct(this_object());
   }
n = random(8);
   if(n == 0 || n ==7)
     init_command("north");
    if(n == 1 || n == 2)
   init_command("south");
   if(n == 4 || n == 6)
     init_command("west");
   if(n == 5 || n == 3)
   if(n==5)
     init_command("east");
    call_out("move_function",random(30),0);
return 1;
}
