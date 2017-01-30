#include "/players/wocket/closed/ansi.h"
#include "def.h"
#include "/players/feldegast/std/colorize.h"

static string arg;
static string type;
static string spellname;
string sect;
string *spell_list;


static int castingtime;
static int spcost;
static int hpcost;
static int coincost;
int practicepoints;
int muffled;
int pagenumber;

static object mage;
static object spell;
static object target;
object guildroom;

id(str){ return (str == "spellbook" || str == "mageguildob" || str == GUILD_ID || str == "yackreceiver" || str == "no_spell"); }
get(){ return 0; }
drop(){ return 1; }
weight(){ return 0; }
value(){ return 0; }

short(){  
string SPC;  
  SPC = get_typecolor(sect);  
  return SPC+"A leather bound spellbook"+NORM; 
}

long(){  
int i,a;
object page;  
  page = first_inventory(this_object());
  write("This is a fine leather-bound book.  Age has obviously taken\n"+
        "its toll upon the outer covering, with cracks running through-\n"+
        "out.  Silk ribbons billow from its edges, marking well kept\n"+
        "secrets and spells.  Light whisps around it, radiating the most\n"+
        "gentle of auras.  It becons to be 'read'.\n");
  write("    The book contains:\n");
  write(YEL+"Index\n"+OFF);
  for(i=0,a=sizeof(spell_list);i<a;i++){
    write(YEL+capitalize(spell_list[i])+"\n"+OFF);
    i++;
  }
}

reset(){
  set_heart_beat(1);
  castingtime = -2;
  spell_list = ({});
}

init(){
  mage = this_player();
  if(!restore_object(SAVEDIR+mage->query_real_name()))
    save_book();
  if(mage->is_player()){
    add_action("rippage","rip");
    add_action("sewpage","sew");
    add_action("cast","cast");
    add_action("read","read");
    add_action("refocus","refocus");
    add_action("cmd_hook");
    add_xverb("");
    CHANNELD->resetchannel();
    mage->set_guild_name("sorcerer");
  }
}

cmd_hook(str){
  string temp;
  string arg1,arg2;
  if(str) str = colorize(str);
  if(castingtime > -1){
    write("You break your focus and lose your spell.\n");
    clear_spell();
  }
  if(sscanf(str,"%s %s",arg1,arg2) != 2){
    arg1 = str;
  }
  temp = "/players/wocket/mages/cmds/"+arg1+".c";
  if(file_size(temp) > 0){
    if(temp->cmd(arg2))
       return 1;
  }
  return 0;
}

heart_beat(){
  object target;
  int failrate;
    castingtime --;
    if(castingtime > -1){
      say("Casting...\n");
      if(castingtime == 0 && spell){
        if(check_spell()){
          spell->add_cost(mage);
          failrate = 25 - ((mage->query_attrib("wil")+mage->query_attrib("int"))/2);
          if(sect == type) failrate = 0;
          if(random(100) < failrate){
            say("Something goes wrong.\nYour spell fizzles.\n");
            clear_spell();
          }
        else {
          say("-----\n");
          spell->cast_spell(mage,arg);
          practicepoints += spell->query_ppgain();
          say("-Practicepoint added: "+practicepoints+"----\n");
          clear_spell();
        }
      }
    }
  }
  mage->add_spell_point(2);
}

cast(str){
  int i,a;
  object page;
  string tar;
  string SPC;
 
  if(this_player()->query_dead()){
    notify_fail("You have no control over magic as a spirit.\n");
    return 0;
  }
  if(!str){
    notify_fail("What would you like to cast?\n");
    return 0;
  }
  if(sscanf(str,"%s at %s",spellname,tar) != 2)
    if(sscanf(str,"%s on %s",spellname,tar) != 2)
      if(sscanf(str,"%s upon %s",spellname,tar) != 2) 
        spellname = str;
  if(spellname == "spell"){
    notify_fail("Which spell would you like to cast?\n");
    return 0;
  }
  i = member_array(spellname,spell_list);
  if(i == -1){
    notify_fail("You do not know how to cast "+spellname+".\n");
    return 0;
  }
  if(mage->test_dark()){
    notify_fail("You can not see your spell book.\n");
    return 0;
  }
  spell = SPELLDIR+spell_list[i+1]+".c";
  arg = tar;
  if(!check_spell())
    return 1;
  if(mage->query_sp() < spcost + 5){
    notify_fail("You do not have enought mana to cast "+spellname+".\n");
    clear_spell();
    return 0;
  }
  if(mage->query_weapon()){
    notify_fail("You cannot cast a spell while wielding a weapon.\n");
    clear_spell();
    return 0;
  }
  if(mage->query_head_armor()){
    object badarmor,head_armor;
    string *types;
    head_armor = mage->query_head_armor();
    types = ({ "armor","helmet","boots","ring","amulet","shield","misc", });
    i = 0;
    a = sizeof(types);
    while(!badarmor && i<a){
         badarmor = head_armor->test_type(types[i]);
         i++;
    }
    if(badarmor){
      notify_fail("You cannot cast a spell while wear armor.\n");
      clear_spell();
      return 0;
    }
  }
  mage->add_spell_point(-5);
  SPC = get_typecolor(type);
  write("You intone some ancient words.\n");
  say(mage->query_name()+" intones some ancient words.\n");
  write(SPC+"["+NORM+"You begin to cast "+spellname+SPC+"]"+NORM+".\n");
  return 1;
}

check_spell(){
  set_spell(spell);
  if(mage->query_sp() < spcost){
    write("You do not have enough mana to cast "+spellname+".\n");
    clear_spell();
    return 0;
  }
  if(mage->query_hp() < hpcost){
    write("You do not have enough health to cast "+spellname+".\n");
    clear_spell();
    return 0;
  }
  if(mage->query_money() < coincost){
    write("You do not have enough money for components to cast "+spellname+".\n");
    clear_spell();
    return 0;
  }
  if(spell->check_spell(mage,arg))
    return 1;
  clear_spell();
  return 0;
}

set_spell(spell){
  spcost = spell->query_spcost();
  hpcost = spell->query_hpcost();
  coincost = spell->query_coincost();
   castingtime = spell->query_time();
  type = spell->query_type();
}

clear_spell(){
  spcost = 0;
  hpcost = 0;
  coincost = 0;
  spell = 0;
  target = 0;
  type = 0;
  castingtime = -1;
}

get_target(arg){
  if(!arg && mage->query_attack())
    return mage->query_attack();
  if(arg && present(arg,environment(mage)))
    return present(arg,environment(mage));
  if(arg && present(arg,mage))
    return present(arg,mage);
  return 0;
}

target_ok(target){
  if(target->is_player() && !target->query_interactive())
    return 0;
  if(target == mage->query_attack())
    return 1;
  if(target->is_npc())
    return 1;
  if(target == mage)
    return 0;
  if(environment(target)->GUILD_PK())
    return 1;
  if(target->query_fight_area() && mage->query_fight_area())
    return 1;
  if(target->query_pl_k() && mage->query_pl_k())
    return 1;
  return 0;
}

rippage(str){
  int i;
  string str2;
  object page;
  if(!str){
    notify_fail("What would you like to rip?\n");
    return 0;
  }
  if( (str != ("spell" || "page")) && member_array(str,spell_list) == -1){
    notify_fail("That page is not in your spellbook.\n");
    return 0;
  }
  if(str == "spell" || str == "page")
    i = 0;
  else
     i = member_array(str,spell_list);
  page = clone_object(SPELLDIR+spell_list[i+1]+".c");
  if(page){
    move_object(page,mage);
    write("You rip "+str+" from the book.\n");
    spell_list -= ({ spell_list[i],spell_list[i+1], });
    pagenumber -= page->query_pages();
    save_book();
    return 1;
  }
  notify_fail("You could'nt find "+str+" in the book.\n");
  return 0;
}

sewpage(str){
  int i;
  string str2;
  object page;
  if(!str){
    notify_fail("What would you like to sew?\n");
    return 0;
  }
  page = present(str,this_player());
  if(page && page->query_w_spell()){
    if(pagenumber + page->query_pages() > 50){
      write("Your book can not carry that many pages.\n");
      return 1;
    }
    page->set_weight(0);
    this_player()->recalc_carry();
    write("You sew "+str+" into your book.\n");
    str  = page->query_spellname();
    str2 = implode(explode(str," "),"_");
    spell_list += ({ str,str2 });
    pagenumber += page->query_pages();
    destruct(page);
    save_book();
    return 1;
  }
  notify_fail("You can't sew "+str+" into the book.\n");
  return 0;
}

read(str){
  int i;
  object page;
  if(!str){
    notify_fail("What would you like to read?\n");
    return 0;
  }
  i = member_array(str,spell_list);
  if(i != -1){
    page = SPELLDIR+spell_list[i+1]+".c";
    page->long();
    return 1;
  }
  str = implode(explode(str," "),"_");
  if(file_size("/players/wocket/mages/docs/"+str) > 0){
    cat("/players/wocket/mages/docs/"+str);
    return 1;
  }
  notify_fail("You couldn't find that to read.\n");
  return 0;
}

refocus(){
 write("You wipe your mind of all and refocus your energies.\n");
 clear_spell();
 CHANNELD->resetchannel();
 set_heart_beat(1);
  return 1;
}

set_title(){
  string title;
  switch(sect){
    case "sum":   title = HIB+"the Warlock"+NORM; break;
    case "enc":   title = HIY+"the Enchanter"+NORM; break;
    case "nec":   title = HIM+"the Necromancer"+NORM; break;
    case "sor":   title = HIR+"the Sorcerer"+NORM; break;
    case "ill":   title = HIC+"the Illusionist"+NORM; break;
    case "gen":   title = CYN+"the Mage"+NORM;break;
    default:      title = "the Magician"+NORM; break;
   }
  mage->set_title(title);
}

get_typecolor(str){
  string color;
  switch(str){
    case "sum":   color = HIB; break;
    case "enc":   color = HIY; break;
    case "nec":   color = HIM; break;
    case "sor":   color = HIR; break;
    case "ill":   color = HIC; break;
    case "gen":   color = CYN; break;
    default: color = ""; break;
  }
  return color;
}

add_practicepoints(i){ practicepoints = practicepoints+i; }
set_practicepoints(i){ practicepoints = i; }
set_sect(str){ sect = str; }
set_muffle(i){ muffled = i; }
set_pagenumber(i){ pagenumber = i; }
set_guildroom(obj){ guildroom = obj; }

query_practicepoints(){ return practicepoints; }
query_sect(){ return sect; }
query_muffled(){ return muffled; }
query_guildroom(){ return guildroom; }

save_book(){
  save_object(SAVEDIR+mage->query_real_name());
  write(HIR+"Guild object saved...\n"+NORM);
}  

query_prevent_shadow(){ return 1; }
