inherit "obj/treasure";
#include "/players/maledicta/ansi.h"
#define ENV environment(this_object())
#define HP ENV->query_hp()
#define MHP ENV->query_mhp()
#define HP ENV->query_hp()
#define HP2 (ENV->query_hp() - 30)
#define HP3 (ENV->query_hp() - 62)
#define HP4 (ENV->query_hp() - 94)
#define HP5 (ENV->query_hp() - 136)
#define HP6 (ENV->query_hp() - 168)
#define HP7 (ENV->query_hp() - 211)
#define HP8 (ENV->query_hp() - 253)
#define SP  ENV->query_sp()
#define MSP ENV->query_msp()
reset (arg) {
if(!arg){

  set_id("pester");
  set_short("");
  set_long("What?\n");
    }
  }

  init(){
  ::init();
  add_action("look", "look");
  add_action("look", "l");
  call_out("step_one", 1);
}
look(){
call_other(this_player(), "look");
tell_object(ENV,
"Darth Malice "+HIR+"Mistress of the Sith"+NORM+" (lord of evil)\n");
return 1;
}

step_one(){
tell_object(ENV, "You feel a great disturbance in the force.\n");
 remove_call_out("step_one");
 call_out("step_two", 3);
}

step_two(){
tell_object(ENV, "Malice arrives.\n");
remove_call_out("step_two");
call_out("step_three", 1);
}

step_three(){
tell_object(ENV,
"Malice wields lightsaber.\n");	
tell_object(ENV,
"Malice"+
" ignites her lightsaber with a...\n\n"+
""+HIR+"           -   -  --  --- ----  ------- SNAP HISS -------  ---- ---  --  -   -"+NORM+"\n\n\n");
remove_call_out("step_three");
call_out("step_four", 1);
}
step_four(){
tell_object(ENV,
"Malice "+HIR+"Impaled"+NORM+" you with a reverse backhand.\n"+
"You missed.\n"+
"Malice "+HIR+"Slashed"+NORM+" you with a whirlwind attack.\n");
tell_object(ENV,
"<<<<  HP "+HP+"/"+MHP+" SP "+SP+"/"+MSP+" I 0% F 0% S 0% T 0% AHP 10/10 >>>>\n");
remove_call_out("step_four");
call_out("step_five", 1);
}

step_five(){
tell_object(ENV,
""+HIR+"-[]-"+NORM+" Malice whirls about, striking you in the leg.\n"+ 
""+BOLD+""+BLK+"-+-"+HIR+" Malice launches herself into the air,"+
" deftly dodging your attack!"+NORM+"\n"+
"Malice "+HIR+"Struck"+NORM+" you with an upward cut.\n"+
"You grazed Malice.\n");
tell_object(ENV,
"<<<<  HP "+HP2+"/"+MHP+" SP "+SP+"/"+MSP+" I 0% F 0% S 0% T 0% AHP 9/10 >>>>\n");
remove_call_out("step_five");
call_out("step_six", 1);
}

step_six(){
tell_object(ENV,
""+HIR+"-[]-"+NORM+" Malice shoulder rolls left, striking you in the arm.\n"+
""+HIR+"-[]-"+NORM+" Malice swings in a long arc, you feel a burning pain in your arm.\n"+
""+BOLD+""+BLK+"-+-"+HIR+" Malice ducks low, your attack barely hitting!"+NORM+"\n"+
"Malice "+HIR+"Hit"+NORM+" you with a spinning strike.\n"+
"You missed.\n");
tell_object(ENV,
"<<<<  HP "+HP3+"/"+MHP+" SP "+SP+"/"+MSP+" I 0% F 0% S 0% T 0% AHP 9/10 >>>>\n");
remove_call_out("step_six");
call_out("step_seven", 1);
}

step_seven(){
tell_object(ENV,
""+HIR+"-[]-"+NORM+" Malice kicks you in the chest.\n"+
""+HIR+"-[]-"+NORM+" Malice falls to one foot sweeping your foot.\n"+
""+BOLD+""+BLK+"-+-"+HIR+" Malice feints right, causing you to fumble your attack!"+NORM+"\n"+
"Malice "+HIR+"Cut"+NORM+" you with a quick strike.\n"+
"You tickled Malice in the stomach.\n");
tell_object(ENV,
"<<<<  HP "+HP4+"/"+MHP+" SP "+SP+"/"+MSP+" I 0% F 0% S 0% T 0% AHP 9/10 >>>>\n");
remove_call_out("step_seven");
call_out("step_eight", 1);
}	
step_eight(){
tell_object(ENV,
""+HIR+"-[]-"+NORM+" Malice moonflips high into the air, striking you in the shoulder.\n"+
"Malice reaches out with the force, Slamming you with a telekinetic strike!\n"+
"You fall to the ground, nearly helpless.\n"+ 
"Malice "+HIR+"Impaled"+NORM+" you with a reverse backhand.\n"+
"You missed.\n");
tell_object(ENV,
"<<<<  HP "+HP5+"/"+MHP+" SP "+SP+"/"+MSP+" I 0% F 0% S 0% T 0% AHP 9/10 >>>>\n");
remove_call_out("step_eight");
call_out("step_nine", 1);
}		 
step_nine(){
tell_object(ENV,
""+HIR+"-[]-"+NORM+" "+BOLD+""+BLK+"Malice reflects your strike back at you!"+NORM+"\n"+
""+HIR+"-[]-"+NORM+" Malice follows up with a quick blow to the chest.\n"+
""+BOLD+""+BLK+"-+-"+HIR+" Malice feints right, causing you to fumble your attack!"+NORM+"\n"+
"Malice "+HIR+"Slashed"+NORM+" you with a whirlwind attack.\n"+
"You grazed Malice.\n");
tell_object(ENV,
"<<<<  HP "+HP6+"/"+MHP+" SP "+SP+"/"+MSP+" I 0% F 0% S 0% T 0% AHP 9/10 >>>>\n");
remove_call_out("step_nine");
call_out("step_ten", 1);
}
step_ten(){
tell_object(ENV,
""+HIR+"-[]-"+NORM+" "+BOLD+""+BLK+"Malice reflects your strike back at you!"+NORM+"\n"+
"Malice calls on the force, confusing her foe!\n"+
"Your mind clouds with confusion!\n"+
""+BOLD+""+BLK+"-+-"+HIR+" Malice blocks your attack!"+NORM+"\n"+
"Malice "+HIR+"Cut"+NORM+" you with a quick strike.\n"+
"You missed.\n");
tell_object(ENV,
"<<<<  HP "+HP7+"/"+MHP+" SP "+SP+"/"+MSP+" I 0% F 0% S 0% T 0% AHP 9/10 >>>>\n");
remove_call_out("step_ten");
call_out("step_eleven", 1);
}
step_eleven(){
tell_object(ENV,
""+HIR+"-[]-"+NORM+" Malice reverses her swing, striking your chest.\n"+
""+BOLD+""+BLK+"-+-"+HIR+" Malice flip spins out of your reach."+NORM+"\n"+
"Malice "+HIR+"Impaled"+NORM+" you with a reverse backhand.\n"+
"You grazed Malice.\n");
tell_object(ENV,
"<<<<  HP "+HP7+"/"+MHP+" SP "+SP+"/"+MSP+" I 0% F 0% S 0% T 0% AHP 9/10 >>>>\n");
remove_call_out("step_eleven");
call_out("step_twelve", 1);
}
step_twelve(){
tell_object(ENV,
""+HIR+"-[]-"+NORM+" Malice senses your weakness and "+HIR+"RAGES"+NORM+".\n"+
"Malice missed.\n"+
"Malice "+HIR+"Impaled"+NORM+" you with a reverse backhand.\n"+
"Malice "+HIR+"Grazed"+NORM+" you with a glancing blow.\n"+
"You hit Malice hard.\n");
tell_object(ENV,
"<<<<  HP "+HP8+"/"+MHP+" SP "+SP+"/"+MSP+" I 0% F 0% S 0% T 0% AHP 8/10 >>>>\n");
remove_call_out("step_twelve");
call_out("step_thirteen", 1);
}
step_thirteen(){
tell_object(ENV,
"\n\n\n"+
"You feel very weak as your badly damaged body falls to the ground to die.\n"+
"Your intelligence is now 19\n"+
"\nYou die.\n"+
"You have a strange feeling.\n"+
"You can see your own dead body from above.\n"+
"\nsetting hit points to 1/3 max....\n\n");
remove_call_out("step_thirteen");
call_out("step_fourteen", 1);
}
step_fourteen(){
tell_object(ENV,
"Malice collapses her lightsaber.\n");
remove_call_out("step_fourteen");
call_out("step_fifteen", 1);
}
step_fifteen(){
tell_object(ENV,
"Malice sneers.\n"+
"Malice turns three circles and is gone.\n");
destruct(this_object());		
return 1;
}			