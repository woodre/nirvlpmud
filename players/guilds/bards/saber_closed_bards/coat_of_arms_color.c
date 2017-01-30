
/*
 *  Alliance object of the Paladin/Bardic guild.
 *  Based on the guild object of the Bards.
 *  From the object base.c
 *  Version 1.1 by Saber and Molasar.
 */

#include "/players/saber/closed/bards/extra.h"
#include "/players/sandman/paladin/ansi.h"

/* Alliance object which stores banished players */
#define MASTER "/players/saber/closed/bards/all_master.c"

#define OWNERS ({ "saber","molasar", })

static int line_flag;
int RANK;
string Nickname;
int color_ok;

reset()  {
  line_flag = 1;
  Nickname = "Nameless";
}

id(str) { return str == "alliance_obj" || str == "coat" || str == "arms" ||
                 str == "coat of arms"; }

drop()  { return 1; }
get()   { return 1; }
can_put_and_get()  { return 0; }

query_auto_load()  { 
   return "/players/saber/closed/bards/coat_of_arms.c:"+
          RANK+"#"+Nickname+"#"+color_ok; 
}

init_arg(str) {
   string me;
   
   sscanf(str, "%d#%s", RANK, Nickname, color_ok);
   me = this_player()->query_real_name();
   if(member_array(me, MASTER->query_banished()) != -1)
     banish();
}

short()  { return filter_color("A Coat of Arms (worn)",HIB); }

long() {
   write("This coat of arms was created as the badge of alliance\n");
   write("between the Bards and the Paladins. To defame it in words\n");
   write("or deeds is to destroy the alliance. Wear it with the honor\n");
   write("it represents.\n");
   write("Description: Azure a bend argent in sinister base a ring, in\n");
   write("             dexter chief a falcon's head sable.\n");
   write("For a list of commands: <help_alliance>\n");
}

banish() {
   write(filter_color("You have been banished from the Alliance!\n",HIR));
   write(filter_color("If you wish reinstatement mail Saber and "+
                      "Molasar.\n",HIR));
   destruct(this_object());
   return 1;
}

init()  {
   add_action("alliance_color","alliance_color");
   add_action("alliance_help","help_alliance");
   add_action("alliance_powers","a_powers");
   add_action("alliance_talk","alt");
   add_action("alliance_emote","ale");
   add_action("alliance_gone","abandon_alliance");
   add_action("alliance_kin","allies");
   add_action("alliance_update","alliance");
   add_action("emote","emote");
   add_action("Nickname","Nickname");
   add_action("succor","goportal");
   add_action("toggle","alt_toggle");
   add_action("check_time","time");
   add_action("armband_me","armband");
   if(member_array(this_player()->query_real_name(), OWNERS) != -1) {   
     add_action("all_banish","all_banish");     
     add_action("all_forgive","all_forgive");
     add_action("all_list","all_list");
   }        
}


int toggle()  {
  if(line_flag)
    write(filter_color("You pass your hand before your eyes.\n"+
                       "You will no longer hear the Alliance Line!\n",HIG));
  else 
    write(filter_color("You pass your hand before your eyes.\n"+
                       "You will now hear the Alliance Line!\n",HIG));
  line_flag=1-line_flag;
  return 1;
}

int query_on()  { return line_flag;}

int alliance_sing(string str, int i_emote)  {
  object member, person, *list;
  int i, c;
  string temp;
  
  member = present("alliance_obj",TP);
  if(!member) { notify_fail(filter_color(NO_INSTRUMENT,HIR)); return 0; }
  if(!member->query_on()) { 
    notify_fail(filter_color("You must be on the Alliance Line! "+   
                             "<alt_toggle>\n",HIR));
    return 0;   
  }
  if(!str)  { 
    notify_fail(filter_color("You say nothing across the Alliance Line!  "+
                             "<WOW>\n",HIR));
    return 0;   
  }
  temp = " "+tp;
  if(!i_emote) temp = temp+" speaks:";
  temp = temp+" "+str;
  c = 0;
  list=users();
  for(i=0; i<sizeof(list); ++i)  {
    person=list[i];
    member=present("alliance_obj",person);
    if(member && (int)member->query_on())  {
      tell_object(person,format(filter_color("-Alliance-",HIR,list[i])+temp));
      ++c;
      }
  }
  if(c==1) write(filter_color("There are no other members of the Alliance "+
                              "within the realms of magic.\n",HIR));
  return 1;
}

int alliance_talk(string str) {return alliance_sing(str,0); }
int alliance_emote(string str) {return alliance_sing(str,1); }

emote(str) {
  if(!str) {
    write(filter_color("Emote what?\n",HIR));
    return 1;
  }
  say(tp+" "+str+" \n");
  write(tp+" "+str+"\n");
  return 1;
}

alliance_help()  {
  cat("/players/saber/bards/alliance_help");
  return 1;
}

alliance_powers()  {
  cat("/players/saber/bards/alliance_powers");
  return 1;
}

succor()  {
  object ob;
  
  ob = this_player();
  if(spell(-2000,1,40,ob) ==-1) return 0;
  if(REALM !="NT")  {
    say(tp+" shouts \"\ALLIANCE\"\.\n");
    move_object(ob,"/players/saber/ryllian/portal.c");
    say(tp+" fades into view.\n");
    write(filter_color("You shout \"\ALLIANCE\"\.\n"+
                       "You are now in the chamber of portals.\n",HIG));
    call_other(this_player(), "add_spell_point", -40);
    return 1;
  }
  write(filter_color("You can not goportal from here.\n",HIR));
  return 1;
}

alliance_kin()  {
int b;
object ob;
object ob2;
object ob3;
ob = users();

write("\n");
write(" : : : : : : : : : : : : : : : : : ALLIANCE : : : : : : : : : : : : : : : : : :\n");
write(" :                                                                            :\n");
write(" :  Name         Rank  Gender  Nickname       Title                           :\n");
write(" :                                                                            :\n");
  for(b=0;b<sizeof(ob);b+=1)  {
  if(ob[b]->query_invis() == 0)  {
  if(present("alliance_obj",ob[b]))  {
ob3 = present("alliance_obj",ob[b]);
write(" : ");
if(line_flag)  {
  if(ob[b]->query_guild_name() == "bard")  {
  write("B ");
   }  else  {
  write("P ");
        }
        }
  else  {
  write("  ");
        }
write(pad(ob[b]->query_name(),13));
write(pad(ob3->query_rank(),5));
write(pad(ob[b]->query_gender(),8));
write(pad(ob3->query_Nickname(),14));
write(" ");
write(pad(ob[b]->query_title(),32));
write(":\n");
  }  }  }
write(" :                                                                            :\n");
write(" :                                                                            :\n");
write(" BARD : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : PALADIN\n\n");
return 1;
}

Nickname(str)  {
  if(!str) {
    write(filter_color("You must type in a string.\n",HIR));
    return 1;
  }
  if(str == "|") { 
    Nickname = 0;
    return 1;   
  }
  Nickname = str;
  write(filter_color("You have taken the nickname of "+str+".\n",HIG));
  return 1;
}

query_Nickname() { return Nickname; }
query_rank()  {  return RANK;  }
set_rank(r) { RANK = r; }

alliance_gone()  {
  int current;
  
  write(filter_color("You leave the Alliance!\n",HIR));
  destruct(this_object()); 
  return 1;
}

alliance_update()  {
   object new_all;

   new_all = clone_object("players/saber/closed/bards/coat_of_arms");
   new_all->set_rank(RANK);
   new_all->Nickname(Nickname);
   move_object(new_all, this_player());
   write(filter_color("Your faith in the Alliance grows stronger.\n",HIG));
   destruct(this_object());
   return 1;
}

check_time()  {
  call_other("/room/church.c","long","clock");
  write("Alliance!\n");
  return 1;
}

armband_me()  {
  move_object("/players/saber/bards/armband.c",this_player());
  write("You are now wearing the black armband of shame.\n");
  return 1;
}

/*
 * FOR BANISHING MEMBERS
 */

all_banish(str) { MASTER->banish(str); return 1; }
all_forgive(str) { MASTER->forgive(str); return 1; }
all_list() { MASTER->list_players(); return 1; }
    

/* COLOR STUFF */

alliance_color() {
   color_ok = !color_ok;
   if(color_ok)
     write("Alliance ansi color is ON!\n");
   else
     write("Alliance ansi color is OFF!\n");
   return 1;
}
query_color() { return color_ok; }

string filter_color(string str, string color, object player) {
   object coat;

   if(!player)
     player = this_player();
   coat = present("alliance_obj", player);
   if(!coat || !coat->query_color()) 
     return str;
   else
     return color+str+NORM;
}
