#include "/players/pavlik/guild/mages/defs.h"
inherit "players/pavlik/guild/mages/inherit/command";

reset(arg) {
  if(arg) return;
  set_verb("mw");
  set_name("Mud Who");
  set_color_name(HIC+"Mud Who"+NORM);
  set_rank(1);
  set_descrip(
	"Display a list of all players currently on Nirvana.\n" +
	"See Also: gw\n"
  );
}


cmd()
{
  object ob, obj;
  string str, who, gname;
  int i, count;

write("\n"+
"                  -- The Denizens of Nirvana: -- \n"+
"Name:         Gen:  Lvl:  Guild:    Location: \n"+
"------------------------------------------------------------------------\
------\n");
ob = users();
for(i=0; i<sizeof(ob); i++){
  if(!environment(ob[i])){
    write("   Logging In ... \n");
  } else if(ob[i]->query_invis() < tp->query_level()){
    who = capitalize(ob[i]->query_name());
    count = strlen(who);
    count = 14 - count;
    if(ob[i]->query_pl_k() == 1)
      write(HIR+"*"+NORM);
    else
      write(" ");
    if(ob[i]->query_idle() > 120)
      write(CYN+"~"+NORM);
    else
      write(" ");
    write(who);
    while(count > 0){
      write(" ");
      count--;
    }
    str = ob[i]->query_gender()[0..0];
    str=capitalize(str);
    count = strlen(str);
    count = 4 - count;
    if(str=="M")str=HIB+"M"+NORM;
    if(str=="F")str=HIM+"F"+NORM;
    write(str);
    while(count > 0){
      write(" ");
      count--;
    }
    if(ob[i]->query_level() > 19)
      write(colour_pad(GRN+"wiz"+NORM,6));
    else if(ob[i]->query_level() >= 10000)
      write(colour_pad(HIG+"GOD"+NORM,6));
    else
      write(pad(" "+ob[i]->query_total_level(), 6));
    gname = ob[i]->query_guild_name();
    if(!gname) gname = "none";
    count = strlen(delete_colour(gname));
    count = 10 - count;
    if(gname == "mage")
      gname= CYN+"MAGE"+NORM;
     gname = colour_pad(capitalize(gname), 9);
     write(gname+" ");
    write(environment(ob[i])->short()+"\n");
  }
  }
write(
"------------------------------------------------------------------------\
------\n"+
" ["+sizeof(ob)+"] players.     * = player killer     ~ = idle\n"+
"------------------------------------------------------------------------\
------\n");
  return 1;
}


