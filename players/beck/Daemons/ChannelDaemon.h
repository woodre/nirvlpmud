/* Beck's Channel Daemon */

mapping Channels;

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
