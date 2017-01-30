#include <ansi.h>

string get_pretitle(object ob){
  object gob;
  if(!(gob = present("knight_object", ob)))
    return "pretitle error";
  
  if(gob->query_knighted())
    return ((string)ob->query_gender()=="male"?"Sir":"Lady");
}

string get_title(object ob){
  object gob;
  string gender;
  int    skill_pts;
  int    total_skill_pts;
  
  if(!(gob = present("knight_object", ob)))
    return "title error";
  
  gender = (string)ob->query_gender();
  
  skill_pts = (int)gob->query_skill_pts_spent();
  total_skill_pts = (int)gob->query_total_skill_pts();
  
  switch(skill_pts * 100 / total_skill_pts)
  {
    case 0:
      return "the Knave";
    case 1..5:
      return "the Young Page";
    case 6..10:
      return "the Page";
    case 11..15:
      return "the Squire";
    case 16..20:
      return "the Young Knight in Training";
    case 21..25:
      return "the Knight in Training";
    case 26..30:
      return "the Noble"+(gender=="male"?"man":"woman");
    case 31..35:
      return "the Knight";
    case 36..40:
      return "the Guardian of Faith";
    case 41..45:
      return "the Defender of Nirvana";
    case 46..50:
      return "the Paladin";
    case 51..55:
      return "the High Templar";
    case 56..60:
      return "the Sentinel of Nirvana";
    case 61..65:
      return "the Knight-Captain";
    case 66..70:
      return "the Knight-Commander";
    case 71..75:
      return "the Crusader General";
    case 76..80:
      return "the Knight "+(gender=="male"?"Lord":"Lady")
            +" Marshall";
    case 81..85:
      return "the "+(gender=="male"?"Duke":"Duchess")
            +" of Nirvana";
    case 86..90:
      return "the "+(gender=="male"?"Lord":"Lady")
            +" Protector of Nirvana";
    case 91..99:
      return "the Arch"+(gender=="male"?"duke":"duchess");
    case 100:
      return "the Legendary "+(gender=="male"?"King":"Queen");
  }
}
int main(string str){
  string pt;
  
  if(str) return 0;
  
  write(BOLD+"You set your guild title.\n"+NORM);
 
  if(pt = get_pretitle(this_player())){
    this_player()->set_pretitle(pt);
  }
  if(pt = get_title(this_player())){
    this_player()->set_title(pt);
  }
  return 1;
}