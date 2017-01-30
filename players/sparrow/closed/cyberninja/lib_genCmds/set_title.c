#include "../DEFS.h"
#include DEFS_GLEVELS
#include DEFS_OFFICES


main(str)
{
  int i, a, lv;
  string new_title, new_pretitle;
  string *titlelist;

  lv = (int)IPTP->query_art_level() + (int)IPTP->guild_lev();
  titlelist = get_titles(lv);

  if(!str)
  {
    write_titles(titlelist);
    return 1;
  }

  if("list" == str)
  {
    write_titles(titlelist);
    return 1;
  }

  sscanf(str, "%d", a);
  i = member_array(a, titlelist);
  if(-1 == i)
  {
    notify_fail("That is not a valid option.\n");
    return 0;
  }

  new_title = titlelist[i+1];
  new_pretitle = get_pretitle(lv);
  this_player()->set_pretitle(new_pretitle);
  this_player()->set_title(new_title);
  write("Your new pretitle is: "+new_pretitle+"\n");
  write("Your new title is: "+new_title+"\n");
  return 1;
}


string* get_titles(int lv)
{
  string sphere, wiz_title, stone;
  int title_count;
  string *titlelist;

  stone = (string)IPTP->query_stone();
  title_count = 0;
  titlelist = ({ });

  if(lv > 0) {
    titlelist += ({ title_count+1, "the " + TITLE_MIN,});
    title_count++;
  }
  if(lv > 4){
    titlelist += ({ title_count+1, "the " + BOLD+MAGENTA+TITLE_MD1+OFF,});
    title_count++;
  }
  if(lv > 9){
    titlelist += ({ title_count+1, "the " + BOLD+BLUE+TITLE_MD2+OFF,});
    title_count++;
  }
  if(lv > 15){
    titlelist += ({ title_count+1, "the " + BOLD+GREEN+TITLE_MD3+OFF,});
    title_count++;
  }
  if(lv > 22){
    titlelist += ({ title_count+1, "the " + BOLD+RED+TITLE_MD4+OFF,});
    title_count++;
   }
  if(lv >= 27){
    titlelist += ({ title_count+1, "the " + WHITE+TITLE_MAX+OFF,});
    title_count++;
  }

  switch(stone)
  {
  case "opal":
    titlelist += ({ title_count+1,
      "the "+MAGENTA+capitalize(OPAL)+" of Cybernetica"+OFF,});
    title_count++; 
    break;
  case "jade":
    titlelist += ({ title_count+1,
      "the "+GREEN+capitalize(JADE)+" of Cybernetica"+OFF,});
    title_count++; 
    break;
  case "onyx":
    titlelist += ({ title_count+1,
      "the "+BOLD+BLUE+capitalize(ONYX)+" of Cybernetica"+OFF,});
    title_count++; 
    break;
  case "emerald":
    titlelist += ({ title_count+1,
      "the "+BOLD+GREEN+capitalize(EMERALD)+" of Cybernetica"+OFF,});
    title_count++;
    break;
  case "ruby":
    titlelist += ({ title_count+1,
      "the "+BOLD+RED+capitalize(RUBY)+" of Cybernetica"+OFF,});
    title_count++;
    break;
  case "pearl":
    titlelist += ({ title_count+1,
      "the "+BOLD+CYAN+capitalize(PEARL)+" of Cybernetica"+OFF,});
    title_count++;
    break;
  case "sapphire":
    titlelist += ({ title_count+1,
      "the "+BOLD+BLUE+capitalize(SAPPHIRE)+" of Cybernetica"+OFF,});
    title_count++;
    break;
  case "diamond":
    titlelist += ({ title_count+1,
      "the "+BOLD+capitalize(DIAMOND)+" of CyberNetica"+OFF,});
    title_count++;
    break;
  default: break;
  }

  sphere = (string)IPTP->query_sphere();
  if(IPTP->guild_wiz() || sphere)
  {
    wiz_title = (string)call_other(OFFICED, "findSphere", TP, sphere);
    titlelist += ({ title_count+1, "the "+RED+wiz_title+OFF,});
    title_count++;
  }

  titlelist += ({title_count+1, "the "+YELLOW+"CyberNinja"+OFF,});
  title_count++;

  if(IPTP->query_nohonor())
  {
    title_count = 1;
    titlelist = ({title_count, "the "+RED+"Renegade"+OFF});
  }

  return titlelist;
}


string get_pretitle(int lv)
{
  if(lv >= MAX_COMBO_LEVEL) return MAX_COMBO_LEVEL_PRETITLE;
  if(lv >= SENIOR)          return SENIOR_PRETITLE;
  if(lv >= MIDLEVEL)        return MIDLEVEL_PRETITLE;
  return LOWLEVEL_PRETITLE;
}


void write_titles(string *titlelist)
{
  int i,a;
  write("A list of titles you may choose from:\n");
  for(i=0,a=sizeof(titlelist);i<a;i++)
  {
    write("\t["+BOLD+titlelist[i]+OFF+"]\t"+titlelist[i+1]+"\n");
    i++;
  }
  write("Usage: set_title <number>\n");
}
