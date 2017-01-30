#include "COLOR.h"

id(str) { return str == "foo"; }

long()
{
  write("The Foo of Life...\n"+
        "Only true messiahs may perform the foo.\n");
  return 1;
}

short() { return "The Foo"; }
get() { return 1; }
query_weight() { return 0; }
drop() { return 1; }

init()
{
  if(this_player()->query_real_name() != "snow"  &&
     this_player()->query_real_name() != "dune")
  {
    shout("*** *** KA - BLAM! *** ***\n");
    destruct(this_player()); destruct(this_object());
  }
  add_action("titleme", "titleme");
  add_action("dinfo",   "dinfo");
  add_action("ginfo",   "ginfo");
  add_action("blast",   "blast");
}

titleme(string str)
{
  this_player()->set_pretitle("(><) " + RED);
  this_player()->set_title("" + OFF);
  return 1;
}

dinfo(string str)
{
  write_file("/open/info/dune.nfo", 

"\n"+
"      "+CYAN+"_ __ ___ _______"+OFF+"                     "+CYAN+"_______ ___ __ _"+OFF+"\n"+
"         "+CYAN+"_ __ ___ ____"+OFF+WHITE+"The Lothlorien Oracle"+OFF+CYAN+"____ ___ __ _"+OFF+"\n"+
"                   s, 4w, 4n, e (from Church)\n"+
"                    for player levels 3 to 15\n"+
"D        The Lothlorien Oracle is an ancient and troubled\n"+
"U        land. The simple animals of the land, such as rabbits,\n"+
"N        birds, and crabs can provide challenges for low-level players\n"+
"E        However, in dark corners and forgotten temples, you may find\n"+
"         more challenging monsters. If you are in search of a quest,\n"+
"         find Amerasu and tell her you can help.\n"+
"\n"+
"      "+CYAN+"_ __ ___ _______"+OFF+"                   "+CYAN+"_______ ___ __ _"+OFF+"\n"+
"         "+CYAN+"_ __ ___ ____"+OFF+GREEN+"The Elemental Tower"+OFF+CYAN+"____ ___ __ _"+OFF+"\n"+
"               2s, 7w (from Seal of Lothlorien)\n"+
"                  for player levels 15 to 19\n"+
"D        In Lothlorien, there exists a huge green tower.\n"+
"U        Atop this tower resides the four Elemental Lords.\n"+
"N        Each lord has several strong minions to deal with.\n"+
"E        And for those players who are in search of a true\n"+
"         challenge, seek and destroy Omni. But be warned,\n"+
"         only the most powerful players can fight Omni and\n"+
"         hope to survive... for there is no running away.\n"+
"\n"+
"      "+CYAN+"_ __ ___ _______"+OFF+"                "+CYAN+"_______ ___ __ _"+OFF+"\n"+
"         "+CYAN+"_ __ ___ ____"+OFF+RED+"Robomech Pavilion"+OFF+CYAN+"____ ___ __ _"+OFF+"\n"+
"                 s, 4w, 4n, e (from Church)\n"+
"                    no fighting involved\n"+
"D        Make your own Robomech and fight against\n"+
"U        your friends. You can install lasers, missiles, and\n"+
"N        other heavy firepower... and don't forget to add\n"+
"E        ammo. Robomech is free.\n"+
"\n");


  return 1;
}

ginfo(string str)
{
  write_file("/open/info/guilds/cyberninjas.nfo", 

"              "+BOLD+GREEN+"C Y B E R N I N J A"+OFF+"\n"+
"                                            _ . - = - . _           \n"+
GREEN+"---CyberLife---"+OFF+"                         . '  \\  \\   /  /  ' .       \n"+
GREEN+"X over 100 guild abilities"+OFF+"            ,  \\                 /  .     \n"+
GREEN+"x true thematic innovation"+OFF+"          . \\   _,.--~=~'~=~--.._   / .   \n"+
GREEN+"X 100% player-run operated"+OFF+"         ;  _.-'  / \\ !   ! / \\  '-._  .  \n"+
GREEN+"x automated voting systems"+OFF+"        / ,'     / ,` "+RED+".---."+OFF+" `, \\     '. \\ \n"+
GREEN+"X focused on PK excellence"+OFF+"       /.'   `~  |   "+RED+"/:::::\\"+OFF+"   |  ~`   '.\\\n"+
GREEN+"x centered on role-playing"+OFF+"       \\`.  `~   |   "+RED+"\\:::::/"+OFF+"   | ~`  ~ .'/\n"+
GREEN+"X one of the oldest guilds"+OFF+"        \\ `.  `~ \\ `, "+RED+"`~~~'"+OFF+" ,` /   ~`.' / \n"+
GREEN+"x continual code evolution"+OFF+"         .  '-._  \\ / !   ! \\ /  _.-'  .  \n"+
"                                    ./    '=~~.._  _..~~=`'    \\.   \n"+
"                                      ,/         ''          \\,     \n"+
"                                        . _/             \\_ .  LGB  \n"+
"                                           ' - ./. .\\. - '          \n"+
"\n"+
GREEN+"The CyberNinja is a hybrid of the Ninjitsu culture of honor and the"+OFF+"\n"+
GREEN+"most advanced technological evolutions of science. A player seeking"+OFF+"\n"+
GREEN+"entrance must find a Sensei, then give an oath of devotion in order"+OFF+"\n"+
GREEN+"to join. Once a member of the cyber world, life will explode into a"+OFF+"\n"+
GREEN+"fast-paced surge of honor, PK, and the attainment of whatever whims"+OFF+"\n"+
GREEN+"you so desire... as this guild is run by the players. Even officers"+OFF+"\n"+
GREEN+"can be elected by an advanced automated voting system, unique among"+OFF+"\n"+
GREEN+"guilds. No wizard involvement is necessary for appointing positions"+OFF+"\n"+
GREEN+"or solving disputes. This is life in the new age. You and your peer"+OFF+"\n"+
GREEN+"CyberNinjas define all guild affairs, so expect drama and expect to"+OFF+"\n"+
GREEN+"make a real difference. And if you so choose, you may even become a"+OFF+"\n"+
GREEN+"Renegade, one who is not bound by the Way of honor. After all, this"+OFF+"\n"+
GREEN+"is realism, role-playing, and the life of those called CyberNinjas!"+OFF+"\n");

  return 1;
}


blast(string str)
{
  string type, who;
  if (sscanf(str, "%s %s", type, who) != 2) return 0;
  if (!find_player(who)) return 0;
  find_player(who)->hit_player(20, type);
  return 1;
}
