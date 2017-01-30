#include "../x.h"

inherit GUILDROOM;

static string guild_name;
static string name;

string *members;
string *colors;
int    *energy;

void reset(status x)
{
 if(x) return;
 short_desc = "the energizer";
 long_desc = "the energizer\n"+
             "you may list, energize, or extract crystals\n";
 members = ({ });
 energy  = ({ });
 colors  = ({ });

 restore_object(N_SAVE+"g-energizer");
}

void init()
{
 ::init();
 add_action("cmd_list", "list");
 add_action("cmd_extract", "extract");
}

status is_member(string nm)
{
 if(!restore_object("pfiles/"+nm[0..0]+"/"+nm) ||
    guild_name != GUILDNAME)
  return 0;
 guild_name = "";
 name  = "";
 return 1;
}

status query_crystal(string mbr)
{
 if(is_member(mbr) && member_array(mbr,members)>-1)
  return 1;
}

void set_crystal(string mbr, int nrg, string col, string ha, string la)
{
 int x;
 if(!is_member(mbr))
  return;
 if((x=member_array(mbr,members))==-1)
 {
  members += ({ mbr });
  energy += ({ nrg });
  colors += ({ col });
 }
 else
 {
  energy[x] = nrg;
  colors[x] = col;
 }

 save_object(N_SAVE+"g-energizer");
}

void delete_crystal(string mbr)
{
 int x;
 if(!is_member(mbr))
  return;
 if((x=member_array(mbr,members))==-1)
  return;

 members -= ({ members[x] });
 energy -= ({ energy[x] });
 colors -= ({ colors[x] });

 save_object(N_SAVE+"g-energizer");
}

int cmd_list()
{
 int    x, y;
 string num;
 write("\n\n");
 write(HIK+"<<>> <> <<>> <> <<< >>> <> <<>> <> <<>>\n"+NORM);
 write("  "+BLU+"............"+NORM+" "+HIW+"crystals "+NORM
           +BLU+"............\n\n"+NORM);

 y = sizeof(members);

 for(x=0;x<y;x++)
 {
  num = ""+energy[x]+"";
  write((x+1)+": "+pad(CAP(members[x]),15)+" : "+HIB+num+NORM+"\n");
 }
 write("\n");
 write(HIK+"<<>> <> <<>> <> <<< >>> <> <<>> <> <<>>\n"+NORM);
 write("\n\n");
 return 1;
}

int cmd_extract(string str)
{
 if(!str)
 {
  if(query_crystal((string)TP->RN))
   TO->extract_crystal((string)TP->RN);
  else
   write("Usage: 'extract <name>'\n");
  return 1;
 }
  
 if(str == "crystal" || str == "focus crystal")
 {
  write("Don't be so vague.\n"+
        "Type 'extract <name>'.\n");
  if((string)TP->query_guild_name() == GUILDNAME)
   write("Just type 'extract' to extract your own.\n");
  return 1;
 }

 if(!is_member(str))
  write(CAP(str)+" isn't even a Rat of NIMH.\n");

 else if(!query_crystal(str))
  write(CAP(str)+"'s crystal is not stored here.\n");

 else TO->extract_crystal(str);

 return 1;
}

void extract_crystal(string nm)
{
 object ob;
 int    x;

 x = member_array(nm, members);

 ob = CO(N_OBJ+"crystal");
 ob->set_master(members[x]);
 ob->set_color(colors[x]);
 ob->set_energy(energy[x]);

 if(transfer(ob, TP))
 {
  write("You can't carry it!\n");
  return;
 }

 write((string)ob->query_hi_ansi());

 if(nm == (string)TP->RN)
  write("\n\t\tYou have extracted your crystal.\n");
 else
  write("\n\t\tYou have extracted "+CAP(nm)+"'s crystal.\n");

 write(NORM);

 say(TP->QN+" pulls a "+(string)ob->query_hi_ansi()+"Focus Crystal"+NORM
  +" from the Energizer.\n");

 write_file(N_LOG+"crystals", ctime()[4..15]+
  " [e] "+(string)TP->RN+" ("+nm+")\n");

 delete_crystal(nm);
}

void remove_object()
{
 save_object(N_SAVE+"g-energizer");
}

status NIMHENERGIZER() { return 1; }
