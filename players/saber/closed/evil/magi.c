#include "/obj/clean.c"


/*
 *      THE EVIL WIZARDS FOR A BETTER NIRVANA GUILD
 *
 *        A.K.A. THE MAGI OF NIRVANA
 *
 */


int line_flag, age;
string guild_status;

reset()  {
  line_flag = 1;
        }
init()  {
object ANKH;
int CHECK;
  CHECK = (environment(this_object()))->query_level();
  if(CHECK > 20)  {
   add_action("true_env","Env");
   add_action("evil_chat","Evil");
   add_action("evil_emote","Eve");
   add_action("freeze","Freeze");
   add_action("other_list","Other");
   add_action("power_list","Power");
   add_action("strangle","Strangle");
   add_action("true_inv","Inv");
   add_action("toggle","Etoggle");
   add_action("evil_wiz","Wizards");
        }
  else  {
  write("You're not supposto have this object...\n\n"+
    "A dark mist flies in and invades your body.\n\n");
  write("You feel really sick.\n\n");
  ANKH = present("ankh_obj",this_player());
  destruct(ANKH);
  return 1;
        }
        }


int toggle()  {
  if(line_flag)  write(
    "You remove your mind from the Evil Wizard collective\n");
  else write(
    "You attune your mind to the Evil Wizard collective.\n");
  line_flag=1-line_flag;
  return 1;
        }

int query_on()  { return line_flag;}

int evil_talk(string str, int i_emote)  {
  object EVIL, person, *list;
  int i, c;
  string temp;
  EVIL = present("ankh_obj",this_player());
  if(!EVIL->query_on())  {
     notify_fail("You must place your mind within the collective.\n"+
     "Type <Etoggle> to rejoin.\n");  return 0;  }
  if(!str)  { notify_fail(
     "What do you wish to say, great one?\n");  return 0;  }
  temp = "(EVIL) "+this_player()->query_name();
  if(!i_emote) temp = temp+" says:";
  temp=temp+" "+str;
  c = 0;
  list=users();
  for(i=0; i<sizeof(list); ++i)  {
    person=list[i];
    EVIL=present("ankh_obj",person);
    if(EVIL && (int)EVIL->query_on())  {
      tell_object(person,format(temp));
      ++c;
      }
    }
    if(c==1) write("There are no other Evil Wizards online.\n");
    return 1;
        }

int evil_chat(string str) {return evil_talk(str,0); }
int evil_emote(string str) {return evil_talk(str,1); }

freeze(str)  {
object target, temp;
  if(!str)  {
    write("A demon says \"\Master, you must type <Freeze> <Player Name>\"\n"+
      "The demon cowers before you.\n\n");
    return 1;
        }
  target = find_player(str);
  if(!target)  {
    write("A demon says \"\Master, we cannot find "+capitalize(target)+"\n"+
      "The demon cowers before you.\n\n");
    return 1;
        }
  if(!present(target,environment(this_player())))  {
    write("A demon says \"\Master, the player must be closer!\"\n");
    write("The demon cowers before you.\n\n");
    return 1;
        }
  /*
  if(target->query_level() > 20)  {
  write("This power does not work verses other Evil Wizards.\n");
    return 1;
       }
  */
  temp = clone_object("/players/saber/closed/evil/freeze.c");
  move_object(temp, target);
  call_other(temp, "freeze");
  tell_room(environment(target), "\n\n"+
    this_player()->query_name()+" points at "+capitalize(str)+" and whispers a single word.\n"+
    capitalize(str)+" is trapped within a block of solid ice.\n");
  tell_object(target, "\nYou are frozen solid!\n\n");
  return 1;
        }

other_list()  {
write(
"\nOther Evil Wizard Abilities:\n\n"+
" Env      <where>         Shows the true environment of a <player>.\n"+
" Inv      <who>           Gives the true inventory of a <player>.\n"+
" Wizards                  Shows the other Evil Wizards online.\n\n");
  return 1;
        }
power_list(str)  {
  if(!str)  {
write(
"\nThe 13 Powers of the Evil Wizards for a better Nirvana:\n\n"+
" Clone    <obj> <who>     This will dispatch demons to fetch a duplicate of an\n"+
"                             object for their master/mistress.  Clone a path,\n"+
"                             an item, or an item from a player.\n"+
" Evil     <msg>           Tells a message to all other evil wizards.\n"+
"                             (Eve will emote, Etoggle to toggle)\n"+
" Fire     <who> <int>     An inferno of fire to fry the <who> for <#> damage.\n"+
" Freeze   <who>           Freeze <who> so that they cant move.\n"+
" Heal     <who>           Drain the lifeforce from a demon to heal yourself or\n"+
"                             a <creature/player>.\n"+
" Identify <obj>           Your mystic senses get the stats of an <obj>ect.\n"+
" Journey  <who> <to?>     Move <who> to <person> or <dun>geon, <chr>urch or\n"+
"                             <adv>guild by a black winged servant. (me = you)\n"+
" Peace    <obj>           Your Iron Will can stop <obj> from attacking you.\n"+
"                             If used without an <obj>, all fighting will stop.\n"+
" Soul     <who>           Lets you read from the soul of <who>.\n"+
" Soulblade                Summons a soulblade for you to use.  <wc 50>\n"+
" Steal    <obj> <who>     Send forth an imp to Steal an <obj> from <who>.\n"+
" Strangle <who>           Strangles a <player> so that they cant speak.\n"+
" Terror   <who>           This power will make any <player> run in terror.\n"+
"                             If no name is typed, all players will flee.\n");
  return 1;
        }
        }
strangle(str)  {
object target, temp;
  if(!str)  {
    write("\nA demon says \"\Master, to use that, you must type\"\n"+
      "\n      Strangle <player name>\n\n"+
  "The demon cowers before you.\n");
    return 1;
        }

  target = find_player(str);
  if(!target)  {
    write("A demon says \"\Master, we can not find "+capitalize(str)+" anywhere.\"\n"+
    "The demon cowers.\n");
    return 1;
        }

  temp = clone_object("/players/saber/closed/evil/choke.c");
  move_object(temp, target);
  call_other(temp, "choke");
  tell_room(environment(target), "\n\n"+
    capitalize(str)+" is surrounded by an aura of dark magic.\n"+
   "A pair of spectral hands appear around "+capitalize(str)+"'s neck.\n\n");
  write("You send forth your dark magic and strangle "+capitalize(str)+".\n");
  return 1;
        }

check_age(str)  {
object OBJ;
int a;
write("Age:\t");
 if(!str)  {  a = this_player()->query_age();  }
   else  {  a = age;  }
  if(a/43200)  {
  write(a/43200 +" days ");
  a = a - (a/43200)*43200;
        }
  if(a/1800)  {
  write(a/1800 +" hours ");
  a = a - (a/1800)*1800;
        }
  if(a/30)  {
  write(a/30 +" minutes ");
  a = a - (a/30)*30;
        }
  write(a*2 +" seconds.\n");
        }


save_me()  {
string file;
  file = "players/saber/closed/bards/stats/" + this_player()->query_real_name();
  if(!save_object(file))  {
  tell_object(environment(this_object()), "Error in saving guild score!\n");
   }  else   {
  tell_object(environment(this_object()), "Guild scores saved.  Party on!\n");
        }
  return 1;
        }

restore_me(name)  {
object player;
  if(!name)  {
    if(!environment(this_object()) || !environment(this_object())->query_name())  return 0;
  name = environment(this_object())->query_real_name();
        }
  player = find_player(name);
  if(!player) return 0;
  tell_object(player, "Checkin your Bard stats...\n");
  restore_object("players/saber/closed/bards/stats/" + name);
   if(guild_status == -1)  {
   write("You have been banished from the Bards.\n"+
        "Mail Saber if you don't agree.\n");
   destruct(this_object());
        }
  if(guild_status == -2)  {
    write("You have been placed on suspension from the Bards.\n"+
       "Mail Saber is you don't agree.\n");
    destruct(this_object());
        }
  return 1;
        }

true_inv(str)  {
object target, *remote;
int i;
  if(!(target = find_living(str)))  {
  write("Your Evil Wizard sight cannot find "+str+" within the realms of magic.\n");
  return 1;
        }
  remote = all_inventory(target);
  write(capitalize(str)+" is carrying:\n");
  for(i=0;i<sizeof(remote);i++)  {
  write(i+"* "+remote[i]->short()+" * "+file_name(remote[i])+"\n");
        }
  return 1;
        }

true_env(str)  {
object target, *remote;
string ace;
int i;
  move_object(clone_object("/players/saber/monsters/song.c"),str);
  target = find_living("song");
  remote = all_inventory(environment(target));
  write("In the area:\n");
  for(i=0;i<sizeof(remote);i++)  {
  write(i+"* "+remote[i]->short()+" * "+file_name(remote[i])+"\n");
        }
  destruct(target);
  return 1;
        }

evil_wiz()  {
int b;
object ob;
ob = users();


write("\n\n");
 for(b=0;b<sizeof(ob);b+=1)  {
 if(present("ankh_obj",ob[b]))  {
   write("*  ");
   write(pad(ob[b]->query_name(),15));
   write(pad(ob[b]->query_al_title(),18));
   write("\n");
        }
        }
write("\n\n");
  return 1;
        }
