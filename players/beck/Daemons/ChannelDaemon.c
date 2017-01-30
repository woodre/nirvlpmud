/* Beck's Channel Daemon */

mapping Channels;
mapping ChannelHistory;

void AddChannel(string channel_name, object player){
   object *players;
   int i;
   if(Channels == 0){ Channels = ([ ]); }
   if(!(players = Channels[channel_name])){
      Channels[channel_name] = ({ player });
   }
   players = Channels[channel_name];
   if (member_array(player, players) < 0) {
      if ((i = member_array(0, players)) < 0)
         Channels[channel_name] += ({ player });
      else
         players[i] = player;
   }
}

RemoveChannel(string channel_name, object player){
   object *players;
   if(Channels == 0){ Channels = ([ ]); }
   if(players = Channels[channel_name]){
      Channels[channel_name] -= ({ player });
   }
   else{
      return;
   }
}

ChannelMessage(string channel, string msg){
   int i;
   object *targets;
   if(Channels == 0)
      Channels = ([]);
   /* next line by vert */
   if(!Channels[channel]) Channels[channel] = ({ });
   targets = Channels[channel];
   for(i=0; i<sizeof(targets); i++){
      if(targets[i]){
         if(environment(targets[i])){
            if(!targets[i]->QMuffles()){
               if(environment(targets[i])->is_player() || environment(targets[i])->RangerNPC() )
                  tell_object(environment(targets[i]),msg);
               else
                  tell_object(targets[i],msg);
            }
         }
         else
            Channels[channel] -= ({targets[i]});
       }
      else
         Channels[channel] -= ({targets[i]});
   }
   AddChannelHistory(channel, msg);
}

ChannelWho(string channel){ return Channels[channel]; }

void AddChannelHistory(string channel_name, string message){
   string *messages;
   
   if(ChannelHistory == 0){ ChannelHistory = ([ ]); }
   if(!(messages = ChannelHistory[channel_name])){
      ChannelHistory[channel_name] = ({ message });
   }
   messages = ChannelHistory[channel_name];

   if(sizeof(messages) >= 19)
      messages -= ({ messages[0] });
   messages += ({ message });

   ChannelHistory[channel_name] = messages;

   
}

ChannelHistory(string channel_name){
   string *messages;
   int i;
   if(ChannelHistory == 0)
      ChannelHistory = ([]);
   if(!ChannelHistory[channel_name]) 
      ChannelHistory[channel_name] = ({ });

   messages = ChannelHistory[channel_name];

   write("Channel History: "+channel_name+"\n");
   write("----------------------------------------\n");

   for(i=0; i<sizeof(messages); i++){
      /*Using write since this would be a player only command */
      write(messages[i]);
   }
   
   write("----------------------------------------\n");

   return 1;
}

   
