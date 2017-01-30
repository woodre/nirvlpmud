
/*
 * MEDALLION OF ESP (3/19/94)
 * Can give a copy of medallion to any player so they can communicate
 * freely
 * AC 0
 */

inherit "obj/armor";

reset(arg) {
   if(arg)
     return;
   set_name("medallion");
   set_alias("esp_med");
   set_short("A medallion of ESP");
   set_long("A silver medallion about the size of your hand suspended\n"+ 
            "from a long metal chain.\n"+
            "This is a medallion of ESP.\n"+
            "It allows you to freely communicate with other people who\n"+
            "have a medallion.\n"+
            "To give a medallion to someone:  medallion <player>\n"+
            "To see who has an ESP medallion:  espwho\n"+
            "To communicate: esp <msg> or -<msg>\n"+
            "To get rid of the medallion: destroy\n");
   set_ac(0);
   set_value(300);
   set_type("amulet");
}


init() {
   add_action("give_medallion","medallion");
   add_action("espwho","espwho");
   add_action("esp","esp");
   add_action("destroy","destroy");
/*
   add_action("esp"); add_xverb("-");
*/
   add_action("esp","-");
   ::init();
}

give_medallion(str) {
   object ob, medal;

   if(!str)
     return 0;
   ob = find_player(str);
   if(!ob || ob->query_invis()) {
     write(capitalize(str)+" is not on.\n");
     return 1;
   }
   if(present("esp_med", ob)) {
     write(capitalize(str)+" already has a medallion of ESP.\n");
     return 1;
   }
   medal = clone_object("players/molasar/rowan/magic/esp_med");
   medal->set_obj_id(1);
   move_object(medal, ob);
   tell_object(ob, capitalize(this_player()->query_name())+" has given "+
       "you a medallion of ESP.\n");
   write("Ok.\n");
   return 1;
}

espwho() {
   object list, medal;
   int i;

   if(!worn) {
     write("You must wear the medallion first.\n");
     return 1;
   }
   list = users();
   write("Players with medallion of ESP:\n");
   write("[:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::]\n");
   for(i=0; i < sizeof(list); i++) {
      medal = present("esp_med", list[i]);
      if(medal && !list[i]->query_invis())
        write(list[i]->short()+"\n");
   }
   write("[:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::]\n");
   return 1;
}

esp(str) {
   object list, medal;
   int i;

   if(!str)
     return 0;
   if(!worn) {
     write("You must wear the medallion first.\n");
     return 1;
   }
   list = users();
   for(i=0; i < sizeof(list); i++) {
      medal = present("esp_med", list[i]);
      if(medal)
        tell_object(list[i], capitalize(this_player()->query_name())+
            " [ESP]: "+str+"\n");
   }
   return 1;
}

destroy() {
   write("Medallion of ESP destructed.\n");
   destruct(this_object());
   return 1;
}

