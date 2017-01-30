#include "std.h"
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();
extra_init() {
  add_action("sit","sit");
 }




/*


*/

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset(){
    object kirk;
    if(!present("kirk")) {

        object rifle,w_hit_pr;
       kirk = clone_object("obj/monster");
       call_other(kirk, "set_id","kirk");
       call_other(kirk, "set_name", "captain kirk");
       call_other(kirk, "set_alt_name","kirk");
       call_other(kirk, "set_short", "Captain Kirk");
       call_other(kirk, "set_long", "Captain James T. Kirk"); 
       call_other(kirk, "set_ac", 13);
       call_other(kirk, "set_wc", 23);
       call_other(kirk, "set_level", 17);
       call_other(kirk, "set_al",75);
       call_other(kirk, "set_hp",450);
       call_other(kirk, "set_spell_mess2","he shoots you with a phuzzer!!!\n");
       call_other(kirk, "set_chance",50);
       call_other(kirk, "set_spell_dam",50);
       call_other(kirk, "set_aggressive",0);
       call_other(kirk, "set_chat_chance",40);
      call_other(kirk,"load_chat","Captain Kirk says: I`M the REAL captain of the Enterprise!!!\n");
     call_other(kirk,"load_chat","Captain Kirk says: Captain Picard is a wimpy french freak!!\n");
move_object(kirk,this_object());
       rifle = clone_object("obj/weapon");
       w_hit_pr = clone_object("players/rich/w_hit_pr.c");
       call_other(rifle,"set_name","phaser rifle");
       call_other(rifle,"set_class",14);
       call_other(rifle,"set_weight",4);
       call_other(rifle,"set_value",1125);
       call_other(rifle,"set_alt_name","rifle");
       call_other(rifle,"set_alias","hey_mon");
       call_other(rifle,"set_short","A phaser rifle");
       call_other(rifle,"set_long","A very nasty looking phaser.\n");
       call_other(rifle,"set_hit_func",w_hit_pr);
       move_object(rifle,kirk);
    }
}



/*



*/


ONE_EXIT("players/rich/hall5u.c", "south",
    "Main Bridge",
            "This is the Main Bridge,you see the various bridge\n" +
            "stations for all departments going \n" +
            "around the bridge.In the center you see the \n" +
            "captain`s chair,helm and navigations\n" +
            "Before you you see The CAPTAIN`S chair.\n",
           1)
realm(){return "enterprise";}
sit(str) {
 string onword,com;
   if(str==0) {
     write("Try sitting ON something.\n");
     return 1;
     }
   sscanf(str,"%s %s",onword,com);
    if(onword==0) {
      write("Type sit on chair.\n");
      return 1;
      }
     if (onword!="on") {
        write("Try sitting ON chair.\n");
        return 1;
        }
     if (com!="chair") {
       write("Try sit on CHAIR.\n");
       return 1;
     }
    add_action("help","help");
    add_action("activate","activate");
    add_action("comm","comm");
    add_action("move1","move");
    add_action("trans","trans");
    add_action("beam","beam");
    write("You sit down in the Captain's Chair and look down to the panel\n");
    write("on the armrest of your chair.For more info type 'help'\n");
  return 1;
   }
help() {
    write("You see a screen light up on the armrest.\n");
    write("COMMAND             ACTION\n");
    write("trans person        transports a person to the bridge.\n");
    write("beam #             beams you to a choice of rooms.\n");
    write("For a list of destinations type 'beam dest`\n");
    write("comm message        communicates a message to anyone on the ship.\n");
    write("activate computer or viewscreen\n");
    write("   computer activates the library computer,\n");
    write("   viewscreen activates the viewscreen.\n");
    write("move                moves the beam up point to the ship.\n");
    return 1;
    }
activate(str) {
     if(str==0) {
      write("Activate something.\n");
      return 1;
         }
     if(str=="computer") {
        write("Library computer is now activated.\n");
        write("You can now access stats on living objects.\n");
        write("To access type compute name.\n");
        /*
        add_action("compute","compute");
	*/
         return 1;
      } else if(str=="viewscreen") {
        write("Viewscreen on.\n");
        write("You may now view the environment of a living object.\n");
        write("To access type view name.\n");
        add_action("view","view");
        return 1;
      } else {
        write("Activate either the computer or the viewscreen.\n");
        return 1;
      }
  }
compute(str) {
 object ob;
      if(str==0) {
        write("compute something.\n");
        return 1;
      }
    ob=find_living(str);
      if(ob==0) {
           write("The computer readout is displayed on screen.\n");
           write("No such being is currently listed as living in\n");
           write("our computer banks.\n");
           return 1;
         }
     if(call_other(ob,"query_level",0)>=21) {
          write("The computer readout is displayed on the screen.\n");
          write("That person is a wizard and is protected from this computer.\n");
          return 1;
        }
      write("The computer readout is displayed on the screen.\n");
    write( call_other( ob, "query_name", 0 ) + "\n");
    write("Level:\t" + call_other( ob, "query_level", 0) + "\n");
    write("HP:\t" + call_other( ob, "query_hp", 0) + "\n");
   write( "AC:\t" + call_other(  ob, "query_ac", 0  ) + "\n");
   write("WC:\t" + call_other(ob,"query_wc",0) + "\n");
    return 1;
    }
view(str) {
    object ob,ob1;
      string str1;
    if(str==0) {
      write("View someone.\n");
      return 1;
    }
    ob=find_living(str);
     if(ob==0) {
        write("No such thing is currently alive.\n");
        return 1;
       }
     ob1=environment(ob);
     str1=file_name(ob1);
       if(call_other(ob,"query_level",0)>=21) {
        write("You do not have the power to view a wizard.\n");
        return 1;
        }
   if(ob->query_invis()){ write("The viewport is unable to locate them.\n"); return 1; }
        write(str+ " is currently located at:\n");
        move_object(this_player(),str1);
        command("look",this_player());
        move_object(this_player(),this_object());
        return 1;
    }
move1(str) {
    if(str==0) {
       write("Move 'ship`\n");
       return 1;
    }
    if(str!="ship") {
       write("Move 'ship`\n");
       return 1;
       }
   write("You tell navigations to change orbit.\n");
   write("Navigator says: Aye aye sir!!\n");
   call_other("players/rich/castle","init1",0);
   call_other("players/rich/castle","reset",0);
   return 1;
  }
comm(str) {
   object who,ob;

      int count;
      string me,onword;
    if(str==0) {
       write("Comm message.\n");
       return 1;
       }
        who=users();
         count=0;
           while(count<sizeof(who)) {
  if(who[count]->query_level() > 1)
            if(call_other(who[count],"query_level",0)<21) {
          if(call_other(environment(who[count]),"realm")=="enterprise") {
            tell_object(who[count],"You here the comm panel whistle.\n");
            tell_object(who[count],"A voice from the comm panel says:\n");
            tell_object(who[count],str);
            tell_object(who[count],"\n");
             return 1;
            }
 }
             count+=1;
  }


      write("Done.\n");
      return 1;
}
beam(arg) {
     string dest;
      int d,i,e;
     dest=allocate(11);
       dest[0]="players/rich/bridge";
       dest[1]="room/pub2";
       dest[2]="room/south/sshore10";
       dest[3]="room/wiz_hall";
       dest[4]="room/shop";
       dest[5]="room/clearing";
       dest[6]="room/giant_path";
       dest[7]="room/adv_guild";
       dest[8]="room/plane8";
       dest[9]="room/ruin";
       dest[10]="room/church";
    if(arg=="dest") {
        i=1;
         write("You current choice of destinations is:\n");
         while(i<11) {
           write(i);
           write(".    ");
           write(dest[i]);
           write("\n");
           i+=1;
         }
            write("To go to any of these destinations type beam #.\n");
            return 1;
         }
      d=sscanf(arg,"%d",e);
      if(!intp(e)) 
        {
         write("Beam number.\n");
         return 1;
       }
     if(e<1||e>10) {
        write("The destination # must be between 1 and 10.\n");
        return 1;
     }
        if(e==0) {
          write("Beam between numbers 1 and 10.\n");
          return 1;
           }
        write("You feel yourself being sucked into the transporter beam.\n");
        move_object(this_player(),dest[e]);
        say(this_player()->query_name());
        say(" appears in a dazzling burst of light and sound.\n");
        return 1;
  }
trans(str) {
    object ob,ob1;
     string str1;
      if(str==0) {
        write("Trans someone.\n");
        return 1;
        }
      ob=find_player(str);
         if(ob==0) {
           write("No such person is alive at this time.\n");
           return 1;
          }
       if(ob == this_player()){
           write("You cannot Transport yourself.\n");
           return 1;
           }
        if(environment(ob)->realm() == "NT" || environment(ob)->realm() == "NM"){ write("You are unable to get a lock on them.\n");  return 1; }
          if(call_other(ob,"query_level",0)>=21) {
             write("You cannot transport a wizard.\n");
             return 1;
              }
         ob1=clone_object("players/rich/trans");
          str1=call_other(this_player(),"query_name",0);
            call_other(ob1,"set_play",str1);
            call_other(ob1,"set_play1",this_player());
            move_object(ob1,ob);
            return 1;
          }
