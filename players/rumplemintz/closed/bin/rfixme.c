#include <ansi.h>

#define TITLE ""+HIB+"is"+HIR+" working"+HIG+" on"+HIY+" stuff"+NORM+""
#define LDTITLE ""+HIB+"is"+HIR+" working on "+HIY+"LD"+ NORM +"!!"
#define TITLE2 ""+HIY+"you're looking for?"+NORM+""
#define TITLE3 ""+HIR+"needs a new tarball!"+NORM+""
#define TITLE4 "|"
#define NITITLE ""+HIY+"is a Knight who says 'Ni'!"+NORM+""
#define ALIGNTITLE ""+HIG+"Still Druish"+NORM+""
#define LDALTITLE ""+HIG+"nirvana.beanos.com 3505"+NORM+""
#define ALIGNTITLE2 ""+HIB+"I can see it in your eyes"+NORM+""
#define ALIGNTITLE3 ""+HIB+"Mizan? Boltar?"+NORM+""
#define ALIGNTITLE4 ""+HIG+"They'rrrrreee GREAT!"+NORM+""
#define NIALIGNTITLE ""+HIR+"Ni!"+NORM+""
#define ALIGNMENT 0
#define PRETITLE 0
#define PRETITLE2 ""+HIY+"Hello?! Is it"+NORM+""
#define PRETITLE3 ""+HIG+"R - R - R - R - R - R -"+NORM+""

#define NIKKITITLE ""+HIW+"the "+BLK+"Vampiric "+HIW+"Seductress of "+RED+"S"+HIW+"w"+RED+"i"+HIW+"t"+RED+"z"+HIW+"e"+RED+"r"+HIW+"l"+RED+"a"+HIW+"n"+RED+"d"+NORM+""
#define NIKKIPRE "It's a dog eat dog world and I'm wearing Milkbone underwear."

varargs int rfixme(string new) {
  object ob;

  if (new == "nikki") {
    ob = find_player("nikki");
    if (!ob) {
      write("Can't find Nikki\n");
      return 0;
    }
    ob->set_title(NIKKITITLE);
    ob->set_pretitle(NIKKIPRE);
    command("save silent", ob);
    write("Fixed Nikki.\n");
    return 1;
  }
  if (new == "hello") {
    this_player()->set_title(TITLE2);
    this_player()->set_al_title(ALIGNTITLE2);
    this_player()->set_pretitle(PRETITLE2);
  }
  else if (new == "tarball") {
    this_player()->set_title(TITLE3);
    this_player()->set_al_title(ALIGNTITLE3);
    this_player()->set_pretitle(PRETITLE);
  }
  else if (new == "LD") {
    this_player()->set_title(LDTITLE);
    this_player()->set_al_title(LDALTITLE);
    this_player()->set_pretitle(PRETITLE);
  }
  else if (new == "flakes") {
    this_player()->set_title(TITLE4);
    this_player()->set_al_title(ALIGNTITLE4);
    this_player()->set_pretitle(PRETITLE3);
  }
  else if (new == "ni") {
    this_player()->set_title(NITITLE);
    this_player()->set_al_title(NIALIGNTITLE);
    this_player()->set_pretitle("");
  }
  else {
    this_player()->set_title(TITLE);
    this_player()->set_pretitle(0);
    this_player()->set_al_title(ALIGNTITLE);
  }
    this_player()->heal_self(50000000);
    this_player()->add_intoxination(-50000000);
    if(this_player()->query_frog()) this_player()->frog_curse(0);
    command("save silent", this_player());
    write("Fixed.\n");
    return 1;
}
