/*
 *  The Mob guild daemon.
 */

#include "mobdefs.h"

/*
 *  Mob Combat Abilities
 */

shoot(str){
     int    dmg;
     object ob, obj;

     dmg = (random(20) + 5);
     if (!str && !ATT) {
        write("Who do you want to shoot at?\n");
        return 1;
     }
     if (!str && ATT) {
        str = ATT->query_real_name();
     }
     ob = present(str, ENVTP);
     if (!ob) {
        write(capitalize(str) + "is not here.\n");
        return 1;
     }
     if (!living(ob)) {
        write("That would be a waste of a good bullet!\n");
        return 1;
     }
     write("You take aim and squeeze off a shot at " + ob->query_real_name() + ".\n");
     say(capitalize(TPN) + " shoots at " + capitalize(ob->query_real_name()) + ".\n");
     this_player()->spell_object(ob, "shoot", dmg, 0);
     if (ob && !ob->query_attack()) {
        ob->attacked_by(TP);
     }
     return 1;
}



/*
 *  Mob Title Abilities
 */

/*
 *  Mob Grafting Abilities
 */

/*
 *  Mob Misc Abilities
 */

mob_who(){
     int i;
     string state;
     object *list;

     i=0;
     list=filter_array(users(), "filter_list", this_object());
     write(" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n\
^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^\n");
     write("   who           Inv/PK/NT         where\n");
     write(" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n\
^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^\n");
     while(i<sizeof(list)){
          state = "";
          write(pad(i+1,3));
          write(pad(list[i]->query_real_name(),14));
          if(list[i]->query_invis()){
             state += "I/";
          } else { state += " /"; }
          if(list[i]->query_pl_k() || list[i]->query_fight_area()){
             state += "PK/";
          } else { state += "  /"; }
          if(environment(list[i])->query_realm()=="NT") state += "NT";
          write(pad(state,9));
          write(pad(environment(list[i])->query_short(),15));
          write("\n");
          i++;
     }
     write(" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n\
^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^\n");
     return 1;
}
int filter_list(object who){
     if(!environment(who)){ return 0; }
     if(this_player()->query_level()<who->query_invis()) return 0;
     return 1;
}



/*
 *  Mob Atmosphere Abilities
 */




howl(arg){
   if(!arg){
      write("You howl at the moon!\n");
      say(this_player()->query_name()+" howls at the moon!\n");
      return 1;
   }
   write("You howl "+arg+" at the moon!\n");
   say(this_player()->query_name()+" howls "+arg+" at the moon!\n");
   return 1;
}

