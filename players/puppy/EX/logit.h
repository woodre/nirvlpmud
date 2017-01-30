
/* command("BflOgIt256z7d <>lvl", USER); */


/* Write a message to a file for the player to view     */
/* type 1 = guild level - called from advance()         */
/* type 2 = attributes - called from check_attribs()    */
/* type 3 = weapon - called from wlc()                  */
/* type 4 = custom message to be used for misc purposes */
/* type 5 = pk log, called from kill_check() in gob.c   */
status player_log(int type, int misc, string message)
{
  if(type == 1) 
    write_file("/players/zeus/closed/bloodfist/log/personal/"+
      User->query_real_name(), ctime()[4..15]+" You advanced "+
      "your to guild level "+PO->query_glevel()+".\n");
  else if(type == 2) 
    write_file("/players/zeus/closed/bloodfist/log/personal/"+
      User->query_real_name(), ctime()[4..15]+
      " You advanced your attributes.\n");
  else if(type == 3) 
    write_file("/players/zeus/closed/bloodfist/log/personal/"+
      User->query_real_name(), ctime()[4..15]+" You advanced "+
      "your weapon level to "+misc+".\n");
  else if(type == 4)
    write_file("/players/zeus/closed/bloodfist/log/personal/"+
      User->query_real_name(), ctime()[4..15]+" "+message+"\n");
}

/* This command is never to be called manually by the user */
status logit(string str)
{
  int a,b,c;
  if(!PO->query_log()) return 0;
  a = (int)PO->query_attrib_lvl();
  c = (int)User->query_extra_level();
  if(str == "alvl")
  {
    write_file("/players/zeus/closed/bloodfist/log/alvl",
      ctime()[4..15]+" "+pad(Name, 13)+
      pad(User->query_level()+"+"+c,7)+" "+pad(a,4)+PO->query_glevel()+
      " {"+PO->query_chosen_exp(0)+","+PO->query_chosen_exp(1)+","+
      PO->query_chosen_exp(2)+","+PO->query_chosen_exp(3)+"}\n");
    player_log(2,0,""); /* log it for player to see */
  }
  else if(str == "glvl")
  {
    b = (int)PO->query_glevel();
    write_file("/players/zeus/closed/bloodfist/log/glvl",
      ctime()[4..15]+" "+pad(Name, 13)+
      pad(User->query_level()+"+"+c,8)+pad(b,3)+pad(a,4)+"{"+
      PO->query_chosen_exp(0)+","+PO->query_chosen_exp(1)+","+
      PO->query_chosen_exp(2)+","+PO->query_chosen_exp(3)+"}\n");
    player_log(1, 0, ""); /* log for player to see */
  }
  else if(str == "wlvl")
  {
    if(!User->query_weapon()) /* should never happen */
    {
      write_file("/players/zeus/closed/bloodfist/log/err",
        ctime(time())+" - "+pad(Name, 12)+" advanced wlvl w/o wep.\n");
    }
    else {
      a = (int)PO->query_if_chosen(User->query_weapon());
      if(!a) return 1; /* should never happen, can only advance chosen weps */
      b = (int)PO->query_chosen_lvl(a);
      write_file("/players/zeus/closed/bloodfist/log/wlvl",
        ctime()[4..15]+" "+pad(Name, 13)+pad(User->query_level()+"+"+c,7)+
        " "+pad(b,3)+PO->query_glevel()+" {"+
      PO->query_chosen_exp(0)+","+PO->query_chosen_exp(1)+","+
      PO->query_chosen_exp(2)+","+PO->query_chosen_exp(3)+"}\n");
      player_log(3, b, ""); /* log advancement for player */
    }
  }
  return 1;
}

