#define DUMMY_FILE "/exec_temp.c"
#define tp this_player()
#define tpname this_player()->query_name()
#define env_name(obj) environment(obj)->query_name()
#define maker "Vital"
#define REPORTER "/players/sado/rep.c"

inherit "/obj/weapon";

string dest;
int safe;
int dam, locked;
object lock_player;

short()
{
   if(tpname != maker)
      if(locked) tell_object(lock_player,tpname+" looked at you.\n");
   return short_desc;
}

init()
{
   ::init();
   
   add_action("echo_all","echoall");
   add_action("foreign_call","Call");
   add_action("set_damage", "dam");
   add_action("duplicate_object", "dupe");
   add_action("remote_inventory", "rinv");
   add_action("remote_dest", "rdest");
   add_action("remote_clone", "rclone");
   add_action("clone_obj", "sclone");
   add_action("force", "sforce");
   add_action("list_wizzes","wizs");
   add_action("do_emote_for_me");  add_xverb(":");
   add_action("exec_code","exec");
   add_action("spy_player","spy");
   add_action("unspy_player","unspy");
   add_action("nail_em","jail");
   add_action("lock_staff", "lock_staff");
   add_action("unlock_staff", "unlock_staff");
add_action("trans","trans");
}

trans(str) { return "/obj/wiz_tool.c"->trans(str); }

reset(arg)
{
   if (!arg) {
      set_name("staff");
      set_short("Staff of Annihilation");
      set_long("Commands:\n"+
         "echoall <msg> .....  echo <msg> to all users (all levels)\n"+
         "Call <livingname> <function> <arg>\n"+
         "              .....  calls <function>(<arg>) in <livingname>\n"+
         "dam <val> .........  sets damage done by a hit with staff\n"+
         "dupe <object> .....  creates a copy of an item in your inven\n"+
         "rinv <livingname> .  gives inventory of <livingname>\n"+
         "rclone/rdest <livingname> <objectname>|<objectnum>\n"+
         "              .....  clones/dests object in inven of <livingname>\n"+
         "sclone <file> <livingname> [tell|notell]\n"+
         "         .....  clones <file> into <livingname>, and notifies them\n"+
         "sforce <living> <action>\n"+
         "              .....  force anyone to do anything\n"+
         "wizs ..............  list all wizs in format: <name> (invis/level)\n");
      set_alias("staff of annihilation");
      set_alt_name("annihilator");
      set_weight(0);
      set_class(50);
      set_hit_func(this_object());
      set_value(0);
      dam=500;
locked = 0;
      call_out("heart_beat",10);
   }
}

weapon_hit(attacker)
{
   write("Your staff glows with red hot fire!!\n");
   return dam;
}

set_damage(str)
{
   if (str) sscanf(str, "%d", dam);/* means mon=atoi(str) */
   write("Damage set to: "+dam+" HP per hit.\n");
   return 1;
}

list_wizzes()
{
   object *peeps;
   int i;
   peeps=users();
   for(i=0;i<sizeof(peeps);i++)
   if(peeps[i]->query_level()>=20)
      write(capitalize(peeps[i]->query_real_name())+" is at level "+
      peeps[i]->query_invis()+"/"+peeps[i]->query_level()+"\n");
   return 1;
}

duplicate_object(str)
{
   return remote_clone(this_player()->query_real_name()+" "+str);
}

remote_inventory(str)
{
   object who_from, *r_inv;
   int i;
   string *argv, dummy;
   
   if (!(who_from = find_living(lower_case(str)))) {
      write(str+" not found.\n");
      return 1;
   }
   r_inv = all_inventory(who_from);
   write("Here's what " + capitalize(str) + " is carrying:\n");
   for (i = 0; i < sizeof(r_inv); i++) {
      write(i + "------" + r_inv[i]->short () + "-----" + file_name(r_inv[i]) + "\n");
   }
   
   return 1;
}


clone_obj(str)
{
   string *argv;
   argv = explode(str, " ");
   move_object(clone_object(argv[0]), find_living(argv[1]));
   if(argv[2]=="tell")
      tell_object(find_player(argv[1]),"Sado has given you a gift.  Check your inventory.\n");
   return 1;
}

find_in_living(str)
{
   string *argv;
   object who_from, what, *r_inv;
   int i;
   argv = explode(str, " ");
   if (sizeof(argv) != 2)
      {
      write("format is <command> <person> <objectname/num>\n");
      return 0;
   }
   if (!(who_from = find_living(lower_case(argv[0]))))
      {
      write(argv[0]+" not found.\n");
      return 0;
   }
   
   if(argv[1][0]>='0' && argv[1][0]<='9')
      {
      r_inv = all_inventory(who_from);
      sscanf(argv[1],"%d",i);
      if(i > sizeof(r_inv))
         {
         write("Not that many items!\n");
         return 0;
      }
      return r_inv[i];
   }
   
   return present(argv[1],who_from);
}

remote_clone(str)
{
   object what;
   what=find_in_living(str);
   if (what)
      {
      write("Got "+what->short()+" from "+env_name(what)+"\n");
      move_object(clone_object(explode(file_name(what), "#")[0]), tp);
   }
   else
      {
      write("Failed.\n");
   }
   return 1;
}

remote_dest(str)
{
   object what;
   what=find_in_living(str);
   if (what)
      {
      write("Killed "+what->short()+" from "+env_name(what)+"\n");
      destruct(what);
   }
   else
      {
      write("Failed.\n");
   }
   return 1;
}

lock_staff(str)
{
   if (!str)
      {
      lock_player = tp;
      locked = 1;
      write("The staff is now locked to " + lock_player->query_name() + ".\n");
      move_object(this_object(), lock_player);
   }
   else if (find_player(str))
      {
      lock_player = find_player(str);
      locked = 1;
      write("The staff is now locked to " + lock_player->query_name() + ".\n");
   }
   else
      {
      write(str+" not found.\n");
      lock_player = 0;
      locked = 0;
   }
   return 1;
}

query_locked_player()
{
   return lock_player->query_name();
}

unlock_staff()
{
   lock_player = 0;
   locked = 0;
   write("Staff is now free!\n");
   return 1;
}

force(str)
{
   object who;
   int i;
   string *argv, command_string;
   object reporter;
   
   argv = explode(str, " ");
   
   if (!(who = find_living(argv[0])))
      return 0;
   
   command_string = argv[1];
   for (i = 2; i < sizeof(argv); i++)
   command_string = command_string + " " + argv[i];
   
   reporter=clone_object(REPORTER);
   move_object(reporter,environment(who));
   call_out("kill_rep",1,reporter);
   
   command(command_string, who);
   
   return 1;
}

kill_rep(rep)
{
   destruct(rep);
}

query_damage()
{
   return dam;
}

heart_beat()
{
   if(!find_player("x"))
      {
      say("The staff cannot exist without " + maker + ", and so it disappears!\n");
      destruct(this_object());
   }
   
   if(locked  &&  !lock_player)
      {
      say("The person this staff was locked to has gone, so it vanishes!\n");
      destruct(this_object());
   }
   
   if(locked  &&  environment() != lock_player)
      {
      say("The staff leaps back into the hands of " + lock_player->query_name() + ".\n");
      move_object(this_object(), lock_player);
   }
   
   call_out("heart_beat",10);
}

echo_all(str)
{
   object *peeps;
   int i;
   
   peeps=users();
   
   for(i=sizeof(peeps);i>0;i--)
   tell_object(peeps[i-1],str+"\n");
   return 1;
}

foreign_call(str)
{
   object target;
   string command, tar_name, arg;
   int glurp, result;
   
   sscanf(str, "%s %s %s", tar_name, command, arg);
   
   if (!(target = find_living(tar_name)))
      write("That living thing is not logged on!\n");
   else
      {
      if(arg)
         {
         if ((arg[0] >= '0' && arg[0] <= '9') || arg[0] == '-')
            {
            sscanf(arg, "%d", glurp);
            result = call_other(target, command, glurp);
         }
         else
            {
            result = call_other(target, command, arg);
         }
      }
      else
         {
         if(sscanf(str,"%s %s",tar_name,command) != 2)
            {
            write("Syntax: Call <target> <function> [args]\n");
            return 1;
         }
         result=call_other(target,command);
      }
      write("fn       : " + command + "(" + arg + ")\nin       : " +
         target->query_name() + "\nreturned : " + result + "\n");
   }
   return 1;
}

nail_em(str)
{
move_object(find_player(str),"/players/sado/rooms/prison.c");
   write("Old home: " + find_player(str)->query_home() + "\n");
   find_player(str)->set_home("/players/sado/rooms/prison.c");
   return 1;
}

spy_player(who)
{
   object it;
   
   it=clone_object("/players/vital/closed/tool/spy.c");
   if(it->set_spyee(who)) write("Spying on them...\n");
   else { 
      write("They're not on!\n"); 
      destruct(it); 
   }
   return 1;
}

unspy_player(who)
{
   object it;
   
   it=present("alkjdhl",environment(find_player(lower_case(who))));
   if(!it) write("They're not spyed on!\n");
   else {
      write("Removing spy...\n");
      destruct(it);
   }
   return 1;
}

exec_code(str)
{
   string defines;
   object o;
string pathname;
string dumpath;

pathname = "/players/" + tp->query_real_name();
dumpath = pathname+DUMMY_FILE;
rm(dumpath);
while(o = find_object(dumpath)) destruct(o);
   
defines = read_file(pathname+"/defines.h");
   
if(defines) write_file(dumpath,defines);
   write_file(dumpath,"exec_function()\n{\n"+str+"\n}\n");
   
   write("Returned: " + dumpath->exec_function()+"\n");
   
   while(o = find_object(dumpath)) destruct(o);
   rm(dumpath);
   
   return 1;
}

do_emote_for_me(str)
{
   return command("emote "+str,this_player());
}
