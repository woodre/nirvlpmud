#include "defs.h"

status main(string str, int guild_rank) {
  string me, item;
  int class;
  object itemob;
   
    me = (string)this_player()->query_name();

     if(guild_rank < 18) {
       write("You must have a guild ranking of 18 to use this command.\n");
       return 1;
     }
     if(!str || str == "weapon" || str == "armor") {
       write("Usage:  assess weapon/armor <item>\n");
       return 1;
     }
     if(sscanf(str, "weapon %s", item) == 1) {
       itemob = present(item, this_player());
       if(!itemob) {
         write("The "+item+" is not in your possession.\n");
         return 1;
       }
       if(call_other(this_player(),"query_spell_point") < 30) {
         write("You are too low on power.\n");
         return 1;
       }
       class = (int)call_other(itemob, "weapon_class", 0);
       if(class == 0) {
         write("You have trouble evaluating this weapon.\n");
         say(capitalize(me)+" looks befuddled.\n");
         return 1;
       }
       call_other(this_player(),"add_spell_point", -30);
       say(me+" studies the "+item+" carefully.\n");
       if(class < 4) {
         write("The "+item+" is a very bad weapon.\n");
         return 1;
       }
       if(class < 8) {
         write("The "+item+" is a bad weapon.\n");
         return 1;
       }
       if(class < 12) {
         write("The "+item+" is an average weapon.\n");
         return 1;
       }
       if(class < 16) {
         write("The "+item+" is a good weapon.\n");
         return 1;
       }
       if(class < 18) {
         write("The "+item+" is a very good weapon.\n");
         return 1;
       }
       if(class <= 20) {
         write("The "+item+" is an extremely good weapon.\n");
         return 1;
       }
       if(class > 20) {
         write("The "+item+" is an excellent weapon.\n");
  write_file(LOGPATH+"ILLEGAL",
              "Illegal weapon:  "+capitalize((string)this_player()->query_real_name())+
              " assessing "+call_other(itemob,"short")+" ("+creator(itemob)+")\n");
         return 1;
       }
       return 1;
     }
     if(sscanf(str, "armor %s", item) == 1) {
       itemob = present(item, this_player());
       if(!itemob) {
         write("The "+item+" is not in your possession.\n");
         return 1;
       }
       if(call_other(this_player(),"query_spell_point") < 30) {
         write("You are too low on power.\n");
         return 1;
       }
       class = (int)call_other(itemob, "armor_class", 0);
       if(class == 0) {
         write("You have trouble evaluating this armor.\n");
         say(capitalize(me)+" looks befuddled.\n");
         return 1;
       }
       call_other(this_player(),"add_spell_point", -30);
       if(class == 1 || class == 2) {
         write("The "+item+" is average armor.\n");
         return 1;
       }
       if(class == 3) {
         write("The "+item+" is good armor.\n");
         return 1;
       }
       if(class == 4) {
         write("The "+item+" is very good armor.\n");
         return 1;
       }
       if(class > 4) {
         write("The "+item+" is excellent armor.\n");
         write_file("/players/angel/GUILD/ILLEGAL",
              "Illegal armor:  "+capitalize((string)this_player()->query_real_name())+
              " assessing "+call_other(itemob,"short")+" ("+creator(itemob)+")\n");
         return 1;
       }
       return 1;
     }
     write("Usage:  assess weapon/armor <item>\n");
     return 1;
}
