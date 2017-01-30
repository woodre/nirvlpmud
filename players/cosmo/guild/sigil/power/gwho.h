#define LINER MAG+"-------------------------->>>  "+HIW+title+ \
          NORM+MAG+"  <<<--------------------------"+NORM

gwho_cmd(string str){
int i, lvl, xlvl;
string header, extra, title;
string state, room, area, owner, junk;
object *list;
  i=0;
  list=filter_array(users(), "filter_invis", this_object());
  if(!str) str == "";
  switch(str){
    case "sigil":{ list = filter_array(list, "filter_sigil", this_object());
                   header = "Sigil ";
                   title = "Sigilists";
                   break; }
    default:{ header = "Guild ";
              title = " Nirvana ";
              break; }
  }
  write("\n"+LINER+"\n");
  write(BOLD+"   Name          Status    Level   "+header+
        "            Location"+NORM+"\n");
  while(i<sizeof(list)){
    state = "";
    write(pad(i+1,3));
    write(pad(capitalize(list[i]->query_real_name()),14));

    if(list[i]->query_invis()) state += "I ";
    if(list[i]->query_pl_k() || list[i]->query_fight_area())
      state += "PK ";
    if(environment(list[i])->realm()=="NT") state += "NT";
    write(pad(state,10));

    lvl = list[i]->query_level();
    xlvl = list[i]->query_extra_level();
    if(lvl > 19 || !xlvl) write(pad(lvl,8));
    else write(pad(lvl+"+"+xlvl,8));

    switch(str){
      case "sigil":{ extra=present("SIGIL_OB",list[i])->query_type(); break; }
      default:{ extra=list[i]->query_guild_name(); break; }
    }
    if (!extra) extra="none";
    write(pad(capitalize(extra),18));

    if(environment(list[i])) {
      if(list[i]->query_level() > 19) room = "A Higher Plane";
      else {
        room = file_name(environment(list[i]));
        sscanf(room,"%s/%s/%s",area,owner,junk);
        if (area=="room")  room = "Downtown Nirvana";
        else  room = capitalize(owner)+"'s Realm";
      }
    }
    else room = "Lost in Space";
    write(room);

    write("\n");
    i++;
  }
  write("\n");
  return 1;
}
