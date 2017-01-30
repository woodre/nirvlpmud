
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
    write_file("/players/fred/closed/bloodfist/log/personal/"+
      environment(previous_object())->query_real_name(),
      ctime()[4..15]+" You advanced "+
      "your guild level to "+previous_object()->query_glevel()+".\n");
  else if(type == 2) 
    write_file("/players/fred/closed/bloodfist/log/personal/"+
      environment(previous_object())->query_real_name(),
      ctime()[4..15]+
      " You advanced your attributes.\n");
  else if(type == 3) 
    write_file("/players/fred/closed/bloodfist/log/personal/"+
      environment(previous_object())->query_real_name(),
      ctime()[4..15]+" You advanced "+
      "your weapon level to "+misc+".\n");
  else if(type == 4)
    write_file("/players/fred/closed/bloodfist/log/personal/"+
      environment(previous_object())->query_real_name(),
      ctime()[4..15]+" "+message+"\n");
      return 1;
}

/* This command is never to be called manually by the user */
status logit(string str)
{
  int a,b,c;
  string name;
  if(!previous_object()->query_log()) return 0;
  a = (int)previous_object()->query_attrib_lvl();
  c = (int)environment(previous_object())->query_extra_level();
  name = capitalize((string)environment(previous_object())->query_real_name());
  if(str == "alvl")
  {
    write_file("/players/fred/closed/bloodfist/log/alvl",
      ctime()[4..15]+" "+pad(name, 13)+
      pad(environment(previous_object())->query_level()+"+"+c,7)+
      " "+pad(a,4)+previous_object()->query_glevel()+" {"+
      previous_object()->query_chosen_exp(0)+","+
      previous_object()->query_chosen_exp(1)+","+
      previous_object()->query_chosen_exp(2)+","+
      previous_object()->query_chosen_exp(3)+"}\n");
    player_log(2,0,""); /* log it for player to see */
  }
  else if(str == "glvl")
  {
    b = (int)previous_object()->query_glevel();
    write_file("/players/fred/closed/bloodfist/log/glvl",
      ctime()[4..15]+" "+pad(name, 13)+
      pad(environment(previous_object())->query_level()+"+"+c,8)+
      pad(b,3)+pad(a,4)+"{"+
      previous_object()->query_chosen_exp(0)+","+
      previous_object()->query_chosen_exp(1)+","+
      previous_object()->query_chosen_exp(2)+","+
      previous_object()->query_chosen_exp(3)+"}\n");
    player_log(1, 0, ""); /* log for player to see */
  }
  else if(str == "wlvl")
  {
    if(!environment(previous_object())->query_weapon()) /* should never happen */
    {
      write_file("/players/fred/closed/bloodfist/log/err",
        ctime(time())+" - "+pad(name, 12)+" advanced wlvl w/o wep.\n");
    }
    else {
      a = (int)previous_object()->query_if_chosen(environment(previous_object())->query_weapon());
      if(a < 0) return 1; /* should never happen, can only advance chosen weps */
      b = (int)previous_object()->query_chosen_lvl(a);
      write_file("/players/fred/closed/bloodfist/log/wlvl",
        ctime()[4..15]+" "+pad(name, 13)+
        pad(environment(previous_object())->query_level()+"+"+c,7)+
        " "+pad(b,3)+previous_object()->query_glevel()+" {"+
      previous_object()->query_chosen_exp(0)+","+
      previous_object()->query_chosen_exp(1)+","+
      previous_object()->query_chosen_exp(2)+","+
      previous_object()->query_chosen_exp(3)+"}\n");
      player_log(3, b, ""); /* log advancement for player */
    }
  }
  return 1;
}

