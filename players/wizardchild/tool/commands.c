commands() {
  write("Commands:\n");
  write("commands               This listing\n");
  write("place <who> <where>    Move a player somewhere\n");
  write("hand <who> <filename>  Give an object to someone\n");
  write("Irm [filename]         Filename view of your room/other room\n");
  write("I [who]                Filename view of you/other player\n");
  write("force <who> <what>     Force someone to do something\n");
  write("calm                   Stop all fighting\n");
  write("chr <who>              Send someone to the church\n");
  write("pris <who>             Place someone in the local prison\n");
  write("money [amt]            Give yourself some $$$ (default:80k)\n");
  write("destp <who> <what>     Dest something in someone's inv\n");
  write("destp <who> F<fname>   Dest something in someone's inv by filename\n");
 
  write("drop! <item>           Power-drop\n");
  write("get! <item>            Power-get\n");
  write("bring <who>            Bring a player to you\n");
  write("trans <who>            Same as bring\n");
  write("heal [amt]             Heal yourself (default:100k)\n");
  return 1;
}
