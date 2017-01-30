/*
*  The Blade chat line.  (v2.0)
*  By Saber.
*/


/*  The Power Ranger Talk Channel   */

ranger_talk(str)  {
   object member, list;
   int i;
   string temp;
   member = present("ranger_object", this_player());
   if(!str){
      write("You try and speak into your communicator, but nothing comes out of your mouth.\n");
      return 0;        
   }
   temp = BOLD+WHITE+"["+OFF+GREEN+"Ranger"+OFF+BOLD+WHITE+"] "+OFF+CAPNAME+" says:";
   if(this_player()->query_invis()){
      temp = BOLD+WHITE+"["+OFF+GREEN+"Ranger"+OFF+BOLD+WHITE+"] "+OFF+"Someone says:";
   }
   temp = temp+" "+str;
   temp = temp+"\n";
   list = users();
   for(i = 0; i < sizeof(list); i++)  {
      member = present("ranger_object", list[i]);
      if(member && !member->query_muff()){
         tell_object(list[i], temp);
      }
   }
   return 1;
}

ranger_emote(str)  {
   object member, list;
   int i;
   string temp;
   member = present("ranger_object", this_player());
   if(!str){
      write("You try and speak into your communicator, but nothing comes out of your mouth.\n");
      return 0;        
   }
   temp = BOLD+WHITE+"["+OFF+GREEN+"Ranger"+OFF+BOLD+WHITE+"] "+OFF+capitalize(this_player()->query_real_name());
   if(this_player()->query_invis()){
      temp = BOLD+WHITE+"["+OFF+GREEN+"Ranger"+OFF+BOLD+WHITE+"] "+OFF+"Someone";
   }
   temp = temp+" "+str;
   temp = temp+"\n";
   list = users();
   for(i = 0; i < sizeof(list); i++)  {
      member = present("ranger_object", list[i]);
      if(member && !member->query_muff()){
         tell_object(list[i], temp);
      }
   }
   return 1;
}
