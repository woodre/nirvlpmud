int cmd_attrib(string str)
{
 if(!str)
 {
  write("Usage: 'attrib <player>'\n");
  return 1;
 }

if(find_player(str)) {
 write("\n\tYou look at "+capitalize(str)+"'s attributes through "+possessive(find_player(str))+" eyes...\n");
 write("\n");
  "/bin/play/_score2.c"->cmd_score2(str);
}
 return 1;
}
