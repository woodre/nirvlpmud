#include <esc.h>
int vampchan,polychan;
init() {
add_action("shard_chan","shard_chan");
add_action("vamp_chan","vamp_chan");
add_action("gpe","sharde");
add_action("gpt","shard");
add_action("telepathy","vamp");
add_action("poly_chan","poly_chan");
add_action("polyguild_tell","poly");
}
reset(arg) {
if (arg) return;
polychan = 1;
}

id(str) {
 return str=="robe" || str=="mrobe"|| str == "BLAH" || str == "instrument" || 
        str=="bard_obj" || str == "guild_obj" || str == "pro_object"||
        str=="shardak_mark" || str=="mark" || str == "guild_object" || 
        str == "Implants" || str == "implant" || str=="either implants" ||
        str=="implants"||str=="CyberNinja Implants"|| 
        str=="nooneelse vampire fangs" || str == "Mizan-guild-object" ||
        str=="vampirefangs" || str=="vampire fangs" || str=="fangs" ||
        str=="guild item" || str=="guild_item" ||
        str=="guild_obj" || str=="guild obj" || str=="guild item: fangs" ||
        str=="mark" || str=="guild_object" || str=="key" || str=="monk robe"||
        str=="soul-undead"||str=="life"||str=="GUILD" || str == "V-GUILD";
}
short(){
  return "The Guild room key.";
 }
get(){return 1;}
shard_chan(str) {
if(str=="on") {
"/players/vertebraker/closed/shardak/daemons/channel"->register(this_player(),({"[Servants]","{Servants}"}));
write("shard channel on");
}
if(str=="off") {
"/players/vertebraker/closed/shardak/daemons/channel"->deregister(this_player(),({"[Servants]","{Servants}"}));
write("shard channel off");
}
return 1;
}
gpe(str) {
string msg;
msg = capitalize(this_player()->query_real_name())+" " + str + "\n";
"/players/vertebraker/closed/shardak/daemons/channel"->broadcast(msg,1,"{Servants}");
return 1;
}
gpt(str) {
string msg;
msg = capitalize((string) this_player()->query_real_name()) +" speaks: " +str + "\n";
"/players/vertebraker/closed/shardak/daemons/channel"->broadcast(msg,1,"{Servants}");
return 1;
}
vamp_chan(str) {
if(str=="on") {
vampchan = 1;
write("vamp channel on");
}
if(str=="off") {
vampchan = 0;
write("vamp channel off");
}
return 1;
}
query_telepathy() { return vampchan; }

telepathy(str) {
  int i;
  object stuff;
  string who, player_list;
if(!str) {
  write("What did you want to say?\n");
  return 1; }
player_list = users();
for(i = 0; i < sizeof(player_list); i++) {
  stuff = present("vampire fangs", player_list[i]);
    if (stuff) {
      if (stuff->query_telepathy())
        if (this_player()->query_invis() > 0)
          tell_object(player_list[i],
            ":[ Someone =>>"+str+"\n");
        else
          tell_object(player_list[i],
            ":[ "+capitalize(this_player()->query_real_name())+"=>>"+str+"\n");
    }
}
return 1;
}
poly_chan(str) {
if(str=="on") {
polychan = 0;
write("poly channel on");
}
if(str=="off") {
polychan = 1;
write("poly channel off");
}
return 1;
}
query_muffle() { return polychan; }
polyguild_tell(str)
{
   object ob, gob, pet;
   string temp,temp2,temp3,temp4;
   int v;
   if(!str) {write("You must give a message.\n");return 1;}
   gob = this_object();
   if(!gob){return 0;}
   if(!temp2){ temp2 = "vibe";   }
   if(sscanf(str, ":%s", temp) == 1) {
      if(this_player()->query_invis() > 38)
         temp = ">> (" + temp2 + ")" + ESC + "[0m Someone " + temp + "\n";
      else temp = ">> (" + temp2 + ")" + ESC + "[0m " +
         capitalize(this_player()->query_real_name()) + " " + temp + "\n";
   } else {
      if(this_player()->query_invis() > 38) temp = ">> Someone " + temp2 + "s:" + ESC + "[0m " + str + "\n";
      else temp = ">> " + capitalize(this_player()->query_real_name()) + " " + temp2 + "s:" + ESC + "[0m " + str + "\n";
   }
   temp = format(temp, 70);
   ob = users();
   pet = find_living("mizPet");
   if(pet)
   {
       pet->parse_guild_tell(this_player(), str);
       pet->parse_guild_tell(this_player(), str);
   }

   polyguild_echo(ESC + "[1m" + ESC + "[34m" + temp);
   return 1;
}
polyguild_echo(str){
   object ob;
   int v;
   ob = users();
   for(v = 0; v < sizeof(ob); v++)  {
      object oc;
      string od;
      oc = present("Mizan-guild-object", ob[v]);
      if(oc && oc->query_original() && !oc->query_muffle())
      {
         tell_object(ob[v], str);
      }
   }
}
query_original() { return 1; }

