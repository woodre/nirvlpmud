cmd_id(str) {
  object ob;
 if(!str) return 0;
  ob = "/players/vertebraker/guilds/samurai/obj/chatob";
  if(str[0] == ':')
    ob->emote(str[1..strlen(str)-1]);
  else
    ob->tell(str);
  return 1; }
