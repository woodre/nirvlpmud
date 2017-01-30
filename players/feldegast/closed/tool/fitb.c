object room;

void reset(int arg) {
  if(arg) return;
  this_object()->start();
}

void start()
{
  room=find_object("/players/maledicta/workroom");
  if(!room) return;
  shadow(room,1);
}

void stop()
{
  shadow(room,0);
  destruct(this_object());
}

string short()
{
  if(!this_player()) return "";
  if((string)this_player()->query_real_name()=="maledicta")
    return (string)room->short();
  else
    return "Maledicta's Workroom";
}
