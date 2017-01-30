#include "/players/jareel/define.h"
#include <security.h>

inherit "/obj/treasure.c";
reset(arg){
    if(arg) return;
    set_id("can");
     set_short(BOLD+"Can of Woop-Ass"+NORM+"\n");
     set_long(HIW+"A can of WOOP-ASS!!!!!!!."+NORM+"\n");
     set_weight(0);
     set_value(0); }
init() {
    ::init();
if(TP->query_level() > 20) {
    add_action("attack_it", "for");
    add_action("cmd_at","at");
    add_action("cmd_att","att");
    add_action("cmd_bugs","bugs");
    add_action("force_us","force");
    add_action("echo_channel","echochan");
    add_action("cmd_ecreate","ecreate");
}}

attack_it(str){
           string a,b;
           string att1, att2;
           sscanf(str, "%s %s", att1, att2);
           a = present(att1, environment(this_player()));
           b = present(att2, environment(this_player()));
           b->attack_object(a); 
           a->attack_object(b);
return 1;
}

int cmd_at(string str)
{
  object other_player;
  object old_room;
  string cmd, who;
  
  if(!str) return 0;
  if((int)this_player()->query_level() < 21)
    return 0;
    
  if (sscanf(str, "%s %s", who, cmd) != 2) 
  {
    write("Usage: 'at <player> <cmd>'\n");
    return 1;
  }

  other_player = find_living(who);
  if(!other_player) 
  {
    write("There is no living creature named " + who + ".\n");
    return 1;
  }

  old_room = environment(this_player());
  move_object(this_player(), environment(other_player));
  command(cmd, this_player());
  move_object(this_player(), old_room);
  return 1;
}

cmd_att(str)
{
  object *list;
  int ll,hl,age_n,age_n2, i, z, x;
  int id_t,a,t;
   string option,gen;
   list=users();
   t = sizeof(list);
   for(i=0; i<sizeof(list); i++) {
      if(list[i]->query_invis() > 55 && this_player()->query_level() < list[i]->query_level())
         t -=1;
   }
   write("There are now " + t + " players");
   write("\n");
   write("Name\t\t\tAttacking\n");
   write("......................................\n");
i =0;
   while(i < sizeof(list)) {
      string sn, ip, sd, sh;
      object obply, plob;
         if(list[i]->query_invis() < 21 || (list[i]->query_invis() > 55 && this_player()->query_level() >= list[i]->query_level()))
            {
            sn=capitalize(list[i]->query_real_name());
            plob = find_player(sn);
            sn = capitalize(sn);
            if(list[i]->query_ghost() == 1) {
               sn = "ghost of " + sn;
            }
               obply=list[i]->query_attack();
               if(obply)
               ip=obply->query_name();
               if(!obply) ip="nothing";
                write(sn+"\t\t"+ip+"\t");
              if(obply)
               write(obply);
               write("\n");
         }
   i += 1;
   x = 0;
}
return 1;
}
#define REP "/obj/user/reports/report_tool"

int cmd_bugs(string str)
{
  object rep;
  if((int)this_player()->query_level() < 21) {
    return 0;
  }
  if(rep = present("report_tool", this_player())) {
    return (int)rep->start_report("bug");
  }
  if((rep = find_object(REP)) && environment(rep) && 
     environment(rep)->is_player()) {
    write((string)environment(rep)->query_real_name()+
      " already has the reporter.\n");
    return 1;
  }
  call_other(REP, "???");
  rep = find_object(REP);

  move_object(rep, this_player());
  rep->start_report("bug");
  return 1;
}

force_us(cmd) {
   if(this_player() != this_object())
  if((int)this_player()->query_level() < 21) {
    tell_object(this_object(), call_other(this_player(), "query_name") +
                " tried to force you to " + cmd + ".\n");
    return;
  }
  tell_object(this_object(), call_other(this_player(), "query_name") +
              " forced you to '" + cmd + "'.\n");
  command(cmd);
}





#pragma strict_types
#pragma save_types

int
echo_channel(string str) {
  string message, channel;
  int count;

  if (this_player()->query_level() < 21)
    return 1;
  if (sscanf(str, "%s %s", channel, message) != 2) {
    write("Echo what on what channel?\n");
    return 1;
  }
  count = emit_channel(channel, message + "\n");
  write(format("You echo " + message + " to " + count +
    " people on channel " + channel + "."));
  return 1;
}

int cmd_ecreate()
{
   object ob;
   if(!(ob=present("e-creator", this_player()))) {
      ob = clone_object("/bin/soul/editor");
      move_object(ob, this_player());
   }

}


