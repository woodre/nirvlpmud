inherit "obj/monster";
#include "/players/persephone/rooms.h"
object didy;
reset(arg) {
  ::reset(arg);
    if(arg) return;
      set_name("slave");
      set_short("A Miserable Looking Slave");
      set_long("This slave must be the poorest looking piece\n"+
               "of flesh you have ever seen.  His eyes are dull\n"+
               "and he looks almost like skin and bones.\n");
      set_level (5);
      set_wc (15);
      set_ac (7);
      set_hp(75);
      set_al(0);
      set_aggressive(0);
      set_gender ("male");
      set_chat_chance(40);
      set_a_chat_chance(80);
      load_chat("The slave says: Have pity on me I am worhtless.\n");
      load_chat("The slave sighs: I use to be important in this town\n");
      load_chat("The slave breaks down and cries\n");
      load_chat("The slave says: If you free me I might be able to help\n");
      load_chat("The slave looks at you forelornly and pleads.\n");
      load_a_chat("The slave whimpers\n");
      load_a_chat("The slave says you will never free Stormhold now\n");
}
second_life(){
  grubble=clone_object("players/persephone/closed/nyny");
   move_object(grubble, TPL);
  ::second_life();
}
init(){
 ::init();
  add_action("free","free");
  add_action("free","release");
  add_action("follow","follow");
}
free(str){
 if (str=="slave"||str=="servant"||str=="serf"){
  write ("The slave bows to you and thanks you telling you\n" +
         "that he was once the son of the mayor of Stormhold.\n");
  didy = clone_object("/players/persephone/closed/didy.c");
  move_object(didy,TPL);
  destruct(TOB);
  return 1;
 }
 write ("Who do you want to free? \n");
 return 1;
}
follow(str){
 if (str=="me"){
  write("The slave sulks at your command and sits down refusing\n" +
        "to move\n");
  say(CAPTPLNM + " seems to have bought a disobedient slave\n");
  return 1;
 }
 write ("The Slave says: who do you want me to follow\n");
 return 1;
}

