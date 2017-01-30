id(str) { return "workroom";}
   short(){return "Haji's Workroom";}
   object owner,owner1,work,room,me;
        long(){
    write("This is Haji's new and improved workroom.\n");
    write("The only obvious exit is south.\n");
   }
   object invite;
    int enter,shield,messages,transport;
    string name,prison;
init() {
      remob();
      own();
     set_heart_beat(1);
    if(this_player()->query_real_name()=="haji"||this_player()->query_real_name()=="rich") {
   add_action("new_people","q");
   add_action("sdon","sdon");
   add_action("sdoff","sdoff");
   add_action("beam","beam");
   add_action("sstat","sstat");
   add_action("etrans","etrans");
   add_action("etrano","etrano");
   add_action("prison","prison");
   add_action("free1","free1");
   add_action("pstat","pstat");
   add_action("estat","estat");
   add_action("mess","mess");
   add_action("note","note");
   add_action("eject","eject");
   add_action("invite","invite");
   add_action("recon","recon");
   add_action("recoff","recoff");
   add_action("recstat","recstat");
   add_action("view","view");
   add_action("move1","ship");
        own();
        begin();
        return 1;
       } else {
          if(shield==0) {
             recmes();
            write("Haji has his shield up now and would not like to be disturbed.\n");
            move_object(this_player(),"players/boltar/X.c");
            return 1;
            }
/*
          if(!present("haji")||!present("rich")) {
          write("You do not have permission to be here.\n");
          move_object(this_player(),"players/boltar/X.c");
          return 1;
         }
*/
     }
            if(!present("haji")) {
                  me=find_player("rich");
                  if(in_editor(me)) {
                    recmes();
                    write("Rich is busy editing right now.\n");
                    move_object(this_player(),"players/boltar/X.c");
                    return 1;
                  }
         }
                me=find_player("haji");
                if(in_editor(me)) {
                  recmes();
                  write("Haji is busy editing right now.\n");
                  move_object(this_player(),"players/boltar/X.c");
                  return 1;
    }
      add_action("south","south");
      add_action("de","dest");
      add_action("de","destruct");
      add_action("south","s");
}
static new_people() {
   string who,name,location;
   int level,invis,counter,spacing,scounter,iidle;
   string slevel,sinvis,sidle;
   write("Name           level   invis    idle      location\n");
   write("----------     -----   -----    ----      ------------\n");
   who=users();
   counter=0;
   while (counter < sizeof(who)) {
      name=who[counter]->query_real_name();
      name=capitalize(name);
      if (in_editor(who[counter]))
         name="->" + name;
      while (strlen(name) < 15)
         name+=" ";
      level=who[counter]->query_level();
      spacing=level;
      slevel=" ";
      scounter=0;
      while (spacing > 9) {
         scounter+=1;
         spacing/=10;
      }
      scounter=7-scounter;
      while (scounter > 0) {
         slevel+=" ";
         scounter-=1;
      }
      invis=who[counter]->query_invis();
      spacing=invis;
      scounter=0;
      while (spacing > 9) {
         scounter+=1;
         spacing/=10;
      }
      sinvis=" ";
      scounter=7-scounter;
      while (scounter > 0) {
         sinvis+=" ";
         scounter-=1;
      }
      iidle=query_idle(who[counter]);
      spacing=iidle;
      sidle=" ";
      scounter=0;
      while (spacing > 9) {
         scounter+=1;
         spacing/=10;
      }
      scounter=7-scounter;
      while (scounter > 0) {
         sidle+=" ";

         scounter-=1;
      }
      if (environment(who[counter]))
         location=file_name(environment(who[counter]));
      else
         location="Nowhere";
      if (!location)
         location="";
      write(name + level + slevel + invis + sinvis + iidle + sidle +
         location + "\n");
      counter+=1;
   }
   return 1;
}
static sdon() {
   shield=0;
   write("Shields on.\n");
   return 1;
   }
static sdoff() {
   shield=1;
   write("Shields off.\n");
    return 1;
   }
static sstat() {
   if(shield==0) {
      write("Shield is on.\n");
      return 1;
       }
      write("Shield is down.\n");
      return 1;
   }
static etrans() {
      transport=0;
      write("Emergency transport system on.\n");
      return 1;
        }
static etrano() {
      transport=1;
      write("Emergency transport system off.\n");
      return 1;
      }
static estat() {
      if(transport==1) {
        write("Emergency transport system off.\n");
        return 1;
         }
       write("Emergency transport system on.\n");
       return 1;
      }
static heart_beat() {
      if(transport==0) {
         object trans;
          trans=find_player("haji");
           if(trans==0) {
             trans=find_player("rich");
              if(trans==0) {
                  return 1;}
             }
            if(!present(trans)) {
              move_object(trans,this_object());
              tell_object(trans,"You have been transported home safely.\n");
              sdon();
              etrans();
              begin();
              return 1;
              }
           return 1;
       }
      return 1;
     }
begin() {
    object o1,o2,o3,o4,o5;
   call_other(this_player(),"destruct_inventory",0);
    o1=clone_object("players/haji/closed/log.c");
    o2=clone_object("players/haji/closed/sn.c");
    o3=clone_object("players/haji/closed/wand.c");
    o4=clone_object("players/nooneelse/black/vampire_fangs");
    o5=clone_object("players/grimm/closed/obj/badge");
    move_object(o4,this_player());
    move_object(o5,this_player());
     move_object(o1,this_player());
     move_object(o2,this_player());
     move_object(o3,this_player());
/*
     if(!present("hat",this_player())) {
        o4=clone_object("players/haji/closed/hat.c");
        move_object(o4,this_player());
      }
*/
     sstat();
     estat();
    recstat();
   return 1;
   }
remob() {
      object rob1,rob2;
       int n;
       string str,str1;
       rob1=first_inventory(this_object());
       n=call_other(rob1,"query_npc",0);
        while(rob1) {
          rob2=next_inventory(rob1);
          if(!living(rob1) || n==1) {
           str=file_name(rob1);
           log_file("haji.mess",str);
           log_file("haji.mess","\n");
          destruct(rob1);
           rob1=rob2;
            n=0;
          }
      n=0;
      rob1=rob2;
   }
      }
static invite(str) {
     invite=find_player(str);
      tell_object(invite,"You have been invited to haji's workroom.\n");
      shield=1;
      move_object(invite,this_object());
      say(invite->query_real_name());
      say(" arrives.\n");
      shield=0;
      return 1;
   }
own() {
 }
/*
  owner=find_player("rich");
      if(owner==0) {
         owner1=find_player("haji");
            if(owner1==0) {
              write(owner+owner1);
              write("Haji is not on write now so you shouldn't be here.\n");
              move_object(this_player(),"players/boltar/X.c");
              return 1;
             }
          }
         }
*/
static eject(str) {
   if(str=="all") {
        call_other(this_object(),"init1",0);
        call_other(this_object(),"reset",0);
       write("Done");
       return 1;
   }
   invite=find_player(str);
     tell_object(invite,"You have been removed from Haji's workroom.\n");
     move_object(invite,"room/well");
     sdon();
      return 1;
  }
static beam(arg) {
     string dest;
      int d,i,e;
     dest=allocate(11);
       dest[0]="players/rich/bridge";
       dest[1]="room/post";
       dest[2]="room/south/sshore10";
       dest[3]="room/wiz_hall";
       dest[4]="room/shop";
       dest[5]="room/adv_inner";
       dest[6]="room/adv_guild";
       dest[7]="players/rich/trans_room";
       dest[8]="players/haji/entrance";
       dest[9]="room/ruin";
       dest[10]="room/church";
    if(arg=="dest") {
        i=0;
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
     if(e<0||e>10) {
        write("The destination # must be between 0 and 10.\n");
        return 1;
     }
        if(e<0) {
          write("Beam between numbers 1 and 10.\n");
          return 1;
           }
        write("You feel yourself being sucked into the transporter beam.\n");
        move_object(this_player(),dest[e]);
        say(this_player()->query_name());
        say(" appears in a dazzling burst of light and sound.\n");
        return 1;
  }
south() {
    call_other(this_player(),"move_player","leaves#room/church");
    return 1;
 }
static recon() {
  enter=0;
   write("You will see when someone tries to enter.\n");
   return 1;
   }
static recoff() {
   enter=1;
   write("Silent mode on.\n");
   return 1;
   }
static recstat() {
   if (enter==0) {
      write("You will see when someone tries to enter.\n");
      return 1;
     }
     write("Silent mode on.\n");
     return 1;
   }
static recmes() {
   if(enter==0) {
       say(this_player()->query_real_name());
       say(" was here.\n");


     }
     }
reset(arg) {}
static view(str) {
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
        write(str+ " is currently located at:\n");
        call_other(this_player(),"move_player","#" + str1);
        move_object(this_player(),this_object());
        return 1;
    }
move1() {
   write("You tell navigations to change orbit.\n");
   write("Navigator says: Aye aye sir!!\n");
     call_other("players/rich/castle","init1",0);
     call_other("players/rich/castle","reset",0);
   return 1;
  }
init1() {
      own();
     set_heart_beat(1);
    if(this_player()->query_real_name()=="haji"||this_player()->query_real_name()=="rich") {
   add_action("new_people","q");
   add_action("sdon","sdon");
   add_action("sdoff","sdoff");
   add_action("beam","beam");
   add_action("sstat","sstat");
   add_action("etrans","etrans");
   add_action("etrano","etrano");
   add_action("estat","estat");
   add_action("mess","mess");
   add_action("note","note");
   add_action("eject","eject");
   add_action("invite","invite");
   add_action("recon","recon");
   add_action("recoff","recoff");
   add_action("recstat","recstat");
   add_action("view","view");
   add_action("move1","ship");
        own();
        begin();
        return 1;
       } else {
          if(shield==0) {
             recmes();
            write("Haji has his shield up now and would not like to be disturbed.\n");
            move_object(this_player(),"players/boltar/X.c");
            return 1;
            }
/*
          if(!present("haji")||!present("rich")) {
          write("You do not have permission to be here.\n");
          move_object(this_player(),"players/boltar/X.c");
          return 1;
         }
*/
     }
            if(!present("haji")) {
                  me=find_player("rich");
                  if(in_editor(me)) {
                    recmes();
                    write("Rich is busy editing right now.\n");
                    move_object(this_player(),"players/boltar/X.c");
                    return 1;
                  }
         }
                me=find_player("haji");
                if(in_editor(me)) {
                  recmes();
                  write("Haji is busy editing right now.\n");
                  move_object(this_player(),"players/boltar/X.c");
                  return 1;
    }
      add_action("south","south");
      add_action("south","s");
}
de(str) {
    if (str=="haji"||str=="rich") {
         say(this_player()->query_real_name());
         say(" foolishly tries to dest the wrong person.\n");
         write("Nice try buddy.\n");
         destruct(this_player());
         return 1;
         }
      return 1;
  }
static prison(str) {
  object ob,owner;
    ob=find_player(str);
       if(!ob) {
          prison=str;
          log_file("haji.mess",str + " has been imprisoned.\n");
          log_file("haji",str);
          log_file("haji","#\n");
          call_other("players/haji/closed/pri","set_up");
          return 1;
        }
     else {
     move_object(ob,"players/haji/closed/pri.c");
     call_other("players/haji/closed/pri.c","set_prison",str);
     tell_object(ob,"You have been imprisoned for being a pain in the ass.\n");
     owner=find_player("haji");
      if(!owner) {
        owner=find_player("rich");
      }
     tell_object(owner,"Prison done.\n");
     prison=str;
     log_file("haji.mess",str + " has been imprisoned\n");
     log_file("haji",str);
     log_file("haji","#\n");
     return 1;
     }
   }
query_prison() {
    return prison;
  }
static free1() {
      prison=0;
     return 1;
 }
pstat() {
    write("Prison status: ");
    write(prison + " is imprisoned.\n");
    return 1;
  }
