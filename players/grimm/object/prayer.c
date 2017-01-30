int wait;
object ob;
id(str) { return "vampy"; }
get() { return 1; }
init() {
  set_heart_beat(1);
  ob = this_player();
}
heart_beat() {
  wait = wait + 1;
  if(wait == 3) 
     tell_object(ob,"\nMighty quester, You must help my village.  Long ago\n");
  if(wait ==6)
    tell_object(ob,"a mighty vampire name Malachi invaded this once lovely town.\n");
  if(wait==9)
    tell_object(ob,"He killed hundreds till finally the town went barron, with\n");
  if(wait==12)
    tell_object(ob,"only a few settlers left who refused to give in to evil.\n");
  if(wait==15)
    tell_object(ob,"You must seek out these people, they contain information\n");
  if(wait==17)
    {
    if(!present("vamp_amulet",ob))
      {
      tell_object(ob,"that would prove to be valuable.  For now, take this amulet\n");
      }
    else
      tell_object(ob,"that would prove to be valuable.  Go now\n");
    }
  if(wait==20)
    tell_object(ob,"and remember, light will conquer darkness!\n");
  if(wait == 20) {
    set_heart_beat(0);
    destruct(this_object());
  }
}
