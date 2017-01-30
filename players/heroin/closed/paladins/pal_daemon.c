 /* ------ *Paladin Tell* ----------- */
 paladin_tell(str) {
         object ob, guild, pal;
         int i, one;
         string me, mess;
  
 me = this_player();
 pal = this_object();
 if(!str) {
         Write("Tell Paladins what?\n");
         return 1;
        }
 mess = "["+capitalize(me->query_real_name())+"]: "+str;
 ob = users();
 for(i = 0; i < sizeof(ob); i++) {
         guild = present("amulet", ob[i]);
         if(guild && guild->query_muffled() == 0) {
 tell_object(ob[i],"[" + capitalize(me->query_real_name()) +"]: " +str+"\n");
 }
 return 1;
 }
 }
  
 /*-------- Paladin Emote ------------ */
 merch_emote(str) {
         object ob, guild;
         int i, x;
         string me;
    
 me = this_player()->query_name();
 if(!str) {
         write("Usage: me <emote string>\n");
         return 1;
         }
 x= random(6);
 ob = users();
 for(i = 0; i < sizeof(ob); i++) {
         guild = present("watch", ob[i]);
                 if(guild && guild->query_muffled() == 0) {
         if(x > 3)
                 tell_object(ob[i],"\n->> "+me+" "+str+"\n");
         else
                 tell_object(ob[i],"\n"+me+" "+str+"\n");
         }
 }
 return 1;
 }
  
 /*              Set start to a paladin room                 */
  set_starting() {
      object target;
   
  target = this_player();
  target->set_home("players/heroin/closed/paladins/main_hall.c");
  write("Starting point: Paladin Sanctuary.\n");
  return 1;
  }
 /* --- Paladin talk (say?) --- */
  paladin_say(str){
          object ob, room;
  
  if(!str){
         write("Say what?\n");
          return 1; 
         }
  room = environment(this_player());
  ob = first_inventory(room);
  while(ob){
          object cur;
          cur = ob;
          ob = next_inventory(ob);
  if(cur->query_npc() != 1){
 
  if(cur->query_npc() != 1){
                  if(present("amulet", cur))
                          if(cur == this_player())
                                  write("You say to your fellow paladins: "+str+"\n");
                          else
                                  tell_object(cur, capitalize(this_player()->query_name())+" monk_says: "+
                                              str+"\n");
                  else
                          tell_object(cur, capitalize(this_player()->query_name())+" says: "+
                                  msay(str)+"\n");
                  }
         }
  return 1;
  }  
