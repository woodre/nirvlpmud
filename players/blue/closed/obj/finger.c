#define TP this_player()
#define THIS_FILE "/players/blue/closed/obj/finger.c"
#define LEVEL TP->query_level()
#define CAP(x) capitalize(x)

int  level, hit_point, max_hp, ex_lv, spell_points;
int max_spell, experience;
int strength, stamina, will_power, magic_aptitude;
int piety, stealth, luck, intelligence;
int guild_rank, guild_name, guild_exp;
string title, pretitle, al_title, quests, lastime;
int quest_point, age, ghost, is_invis;
int stuffed, soaked;


finger_me(name) {
   object ob;
   if(!name) {
      write("Usage: 'pfinger <player>'.\n");
      return 1;
   }
   level = 0;
   restore_object("players/"+name);
   if(!level) {
      write("No such player or access denied.\n");
      return 1;
   }
   if(is_invis && ( level > LEVEL ) ) {
      write("No such player or access denied.\n");
      return 1;
   }
   ob = find_player(name);
   if(ob && ob->query_invis() && ob->query_level() > LEVEL) {
      write("No such player or access denied.\n");
      return 1;
   }
   write("Information received and accessible...\n\n");
   write(pretitle +" "+CAP(name)+" "+title+" "+al_title+"\n");
   write("\n");
   write("Level: "+level+"\tExtra Level: "+ex_lv+"\n");
   write("hp: <"+hit_point+"/"+max_hp+">\tsp: <"+spell_points+"/"+max_spell+">\t");
   write("quest: <"+quest_point+">\n");
   write("exp:<"+experience+"> \tguild:<");
   if(guild_name) write(guild_name+" ("+guild_rank+", "+guild_exp+")>\n");
      else write("None>\n");
   write("\n");
   write("sr("+strength+")st("+stamina+")wp("+will_power+")ma("+magic_aptitude);
                write(")p("+piety+")sl("+stealth+")lu("+luck+")in("+intelligence+")\n");
   write("\n");
   if(quests)
      write(quests+"\n");
   else write("No quests solved.\n");
   write("\n");
   write(CAP(name) +" is "+get_age(age)+ " old.\n");
   if(ob) {
      write("That player is currently logged in.\n");
     if(ob->query_ghost()) write(CAP(name)+" is a ghost.\n");
   } else {
      write("Last login was at "+lastime+".\n");
      if(ghost) write(CAP(name)+" is a ghost.\n");
   }
   return 1;
}

id(str) { return str=="finger" || str == "blue-finger"; }
short() { return "A Wizard's Finger"; }
long() { 
   if(this_player()&&this_player()->query_level() > 20) {
      write("This is a wizards finger.  Type 'pfinger <player> to finger a"+
       " player, or\n'givefinger <player> to give another wiz a copy.\n");
   } else
   write("This is a wizard's finger, a powerful finger device.\n"); 
}
get() { return 1; }

reset(arg) {
   if(arg) return;

}

init() {

   if(LEVEL < 21) destruct(this_object());

   add_action("finger_me", "pfinger");
   add_action("give_finger","givefinger");

}

query_auto_load() {
   return THIS_FILE+":";
}

init_arg(str) {
   return 1;
}

get_age() {
   int days, hours, minutes;
   days = age / 43200;
   hours = (age - (days * 43200))/1800;
   minutes = (age - (days * 43200) - (hours * 1800))/30;
   if(days) return days+" days, "+hours+" hours, "+minutes+" minutes";
   if(hours) return hours+" hours, "+minutes+" minutes";
      else return minutes +" minutes";
}

give_finger(str) {
   object who;
   if(!str) {
      write("usage: 'givefinger <player>'.\n");
      return 1;
   }
   who = find_player(str);
   if(!who) {
      write("No such player on the game.\n");
      return 1;
   }
   if(present("blue-finger", who)) {
      write("That player already has a finger device.\n");
      return 1;
   }
   move_object(clone_object(THIS_FILE), who);
   write("Ok.\n");
   tell_object(who, "You now have a wizards finger.\n");
   return 1;
}
