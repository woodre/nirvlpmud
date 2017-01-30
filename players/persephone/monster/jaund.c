inherit "obj/monster";
#include "/players/persephone/rooms.h"
object slave;
reset(arg) {
  ::reset(arg);
    if(arg) return;
      set_name("jaundice");
      set_alias("shopkeeper");
      set_short("Jaundice The Slave Trader");
      set_long("Jaundice the most renowned slave trader in all\n"+
               "in all of Nirvana.  He looks like the type\n"+
               "of person you would not want to kill in fact\n"+
               "it is rumoured he can kill people in one blow\n"+
               "with his bare hands.\n");
      set_level (50);
      set_wc (80);
      set_ac (40);
      set_hp(4000);
      set_al(-1000);
      set_aggressive(0);
      set_gender ("male");
      set_chance(100);
      set_spell_dam(100);
        set_spell_mess1("Jaundice begins to choke his foe");
        set_spell_mess2("Jaundice grabs you around the neck and starts choking you.");
      set_chat_chance(50);
      load_chat("Jaundice says: My slaves are the best around.\n");
      load_chat("Jaundice asks: You do want a slave don't you???\n");
      load_chat("Jaundice states: Come on I do not have all day.\n");
      load_chat("Jaundice looks down at his books and scribbles something\n");
      load_chat("Jaundice goes to the back of the shop and pokes a slave.\n");
      load_chat("Jaundice pounds the desk and glares at you.\n");
}
init (){
 ::init();
  add_action("purchase","purchase");
  add_action("purchase","buy");
}
purchase(str){
  if(str=="slave"||str=="serf"||str=="servant"){
    if (TPL->query_money()<5000){
      write("Jaundice says: You cannot afford to buy the slave\n");
  return 1;
  }
  TPL->add_money(-5000);
  slave = clone_object("/players/persephone/closed/slav.c");
  move_object(slave,environment(TOB));
  write("Jaundice brings out your slave and says you are lucky\n" +
        "this is the last one and cackles before throwing down\n" +
        "a smoke bomb and disappearing\n\n");
  destruct(TOB);
return 1;
  }
  write("Jaundice looks at you enquiring if you want to buy something\n");
return 1;
}
  
