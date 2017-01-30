inherit "/obj/armor";
#include "/players/pavlik/closed/colors.h"
#include "/players/pavlik/guild/mages/obj/cmd_check"
#define LIMIT 10
/*
    Speedster Code orginally done by Hurtbrain
    Modified by Pavlik for usage in the Mages Guild
    (orginal code = /players/hurtbrain/obj/newspeed.c)
    VERSION 1.1
*/
int k;
string backp,bpatt,patt,ggg;
string comment;
object obj;

id(str){
  return ::id(str)||str=="hat"||str=="wiz_hat"||str=="mage_hat";
}

reset(arg) {
  ::reset(arg);
        if(arg) return;
  set_name("wizard's hat");
  set_alias("hat");
  set_type("helmet");
  set_short(HIB+"Wizard's Hat"+NORM);
  set_ac(1);
patt=allocate(10);
bpatt=allocate(10);
backp=allocate(10);
comment=allocate(10);
restore_object("players/pavlik/guild/mages/players/hat/"+lower_case(this_player()->query_real_name()));
}

long(){
  write(
  "A Wizard's Hat.  This is a beat up old shapeless Hat.  A truly powerful\n"+
  "wizard can utilize the secret powers of this misshapen artifact.\n"+
  "Type '"+MAG+"info hat"+NORM+"' for commands.\n");

/* added by mizan 2009 jul 10 so ppl can discard of the hat */
  write("Type 'tosshat' to make this hat disappear.\n");
  return;
}


init() {
    add_action("go","go");
    add_action("back","back");
    add_action("rev","rev");
    add_action("add","add");
    add_action("del","del");
    add_action("path","show");
    add_action("ref","newhat");
    add_action("info_hat","info");
    add_action("comment","comment");
    add_action("tosshat","tosshat");
}

tosshat()
{
	write("You toss the hat into the air, and it disappears forever.\n");
	say(this_player()->query_name() + " tosses a beat-up old hat into the air, and it disappears!\n");
	destruct(this_object());
	return 1;
}

comment(str)  {
        int num;
        string comms;
  if(!mage_check())  return 0;
        if(!str || sscanf(str,"%d %s",num,comms)!=2)  
                {
                notify_fail("No such pattern in the hat.\n");
                return 0;
                }
        if(num<1 || num>k)   {
                notify_fail("No such pattern in the hat.\n");
                return 0;
                }
        if(comms=="none")  {
                write("You reset comment number "+num+".\n");
                comment[num-1]="";
                }
        else  {
                comment[num-1]=comms;
                write("Comment to pattern number "+num+" set to: \n"+comms+".\n");
                }
        save_object("players/pavlik/guild/mages/players/hat/"+lower_case(this_player()->query_real_name()));
        return 1;
        }

ref()  {
	int num;
  if(!mage_check()) return 0;
	move_object(clone_object("/players/pavlik/guild/mages/obj/wiz_hat"),this_player());
  write(
  "You take off your Wizard's hat and throw it on the ground.\n"+
  "You jump up and down on the hat a couple times and then pick\n"+
  "it up and place it back on your head.\n"+
  "Aaah - much better!\n");
  say(capitalize(this_player()->query_name())+
  " takes off his Wizard's Hat and throws it on the ground.\n"+
  capitalize(this_player()->query_name())+
  " jumps up and down on the hat a couple times then picks it\n"+
  "up and places the shapeless mass back on his head.\n"+
  capitalize(this_player()->query_name())+" smiles happily.\n");
        for(num=0;num<k;++num) {
                backp[num]=volta(patt[num]);
                }
	save_object("players/pavlik/guild/mages/players/hat/"+lower_case(this_player()->query_real_name()));
	destruct(this_object());
	return 1;
}

rev(str)  {
        int num,con;
  if(!mage_check()) return 0;
        obj=this_player();
        if(!str || !sscanf(str,"%d",num))  return 0;
        if(num<1 || num>k)   {
                notify_fail("No such pattern in the hat.\n");
                return 0;
                }
        ggg=bpatt[num-1];
	write("Executing path: "+ggg+".\n");
        funza();
        return 1;
}

back(str)  {
        int num,con;
  if(!mage_check())  return 0;
        obj=this_player();
        if(!str || !sscanf(str,"%d",num))  return 0;
        if(num<1 || num>k)   {
                notify_fail("No such pattern in the hat.\n");
                return 0;
                }
        ggg=backp[num-1];
	write("Executing path: "+ggg+".\n");
        funza();
        return 1;
}

go(str) {
        int num;
  if(!mage_check())  return 0;
        obj=this_player();
      if(!str)
        return 0;
      if(!sscanf(str, "%d", num))
        ggg = str;
      else {
        if(num<1 || num>k)   {
                notify_fail("No such pattern in the hat.\n");
                return 0;
                }
        ggg=patt[num-1];
      }
	write("Executing path: "+ggg+".\n");
        funza();
        return 1;
}

funza()  {
        string path;
        int cont;
        int number;
        number=5;
        for(cont=0;cont<number;++cont)  {
          if(sscanf(ggg,"%s,%s",path,ggg)==2)  {
            if(obj->query_level() < 20)
              cmd_check(path);
            else command(path, obj);
          } else {
            if(obj->query_level() < 20)
              cmd_check(ggg);
            else command(ggg, obj);
            tell_object(obj,"Done.\n");
            return 1;
          }
        }
        call_out("funza",1);
        return 1;
}


add(str)  {
  if(!mage_check())  return 0;
        if(!str)  {
                notify_fail("What do you want to add?\n");
                return 0;
                }
        if(k>9)   {
                notify_fail("The hat is full.\n");
                return 0;
                }
        patt[k]=str;
        bpatt[k]=gira(str);
        backp[k]=volta(str);
        ++k;
        write("Path number "+k+": "+str+" added.\n");
	save_object("players/pavlik/guild/mages/players/hat/"+lower_case(this_player()->query_real_name()));
        return 1;
}

del(str)  {
        int num;
  if(!mage_check())  return 0;
        if(!str || (!sscanf(str,"%d",num)) || (num>k) || (num<1))  {
                notify_fail("What do you want to delete from the hat?\n");
                return 0;
                }
        write("You deleted the path number "+num+".\n");
        for(num;num<k;++num)  {
                patt[num-1]=patt[num];
                bpatt[num-1]=bpatt[num];
                }
        --k;
        patt[k]="";
        bpatt[k]="";
        backp[k]="";
	save_object("players/pavlik/guild/mages/players/hat/"+lower_case(this_player()->query_real_name()));
        return 1;
}

path()  {
        int num;
  if(!mage_check())  return 0;
        if(!k)  {
                write("No pattern in the hat.\n");
                return 1;
                }
    write("Your hat contains the Patterns: \n");
        for(num=0;num<k;++num)  {
           write((num+1));
           if(comment[num])
            write(" ("+comment[num]+")");
           write(" : "+patt[num]+".\n");
                }
        return 1;
}

gira(str) {
        int cont;
        string pri,sec,rets;
        cont=1;
        rets="";
        while(cont!=0)  {
                cont=0;
                sec=str;
                str="";
                while(sscanf(sec,"%s,%s",pri,sec)==2)  {
                        if(cont!=0)
                                str+=",";
                        str+=pri;
                        ++cont;
                        }
                rets+=sec;
                if(cont!=0)
                        rets+=",";
                }
        return rets;
}

volta(str) {
        int cont;
        string pri,sec,rets;
        cont=1;
        rets="";
        while(cont!=0)  {
                cont=0;
                sec=str;
                str="";
                while(sscanf(sec,"%s,%s",pri,sec)==2)  {
                        if(cont!=0)
                                str+=",";
                        str+=pri;
                        ++cont;
                        }
                if(sec=="e")
                        sec="w";
                else if(sec=="w")
                        sec="e";
                else if(sec=="n")
                        sec="s";
                else if(sec=="s")
                        sec="n";
                else if(sec=="ne")
                        sec="sw";
                else if(sec=="nw")
                        sec="se";
                else if(sec=="se")
                        sec="nw";
                else if(sec=="sw")
                        sec="ne";
                else if(sec=="u")
                        sec="d";
                else if(sec=="d")
                        sec="u";
                rets+=sec;
                if(cont!=0)
                        rets+=",";
                }
        return rets;
}

mage_check(){
  if(!present("mageobj", this_player())){
    write("This is just a beat-up old hat.\n"+
          "It is worthless to you.\n");
    return 0;
    }
  if(this_player()->query_guild_rank() < 1){
    write("This hat is too powerful for you!\n"+
          "You better put it back where it belongs.\n");
    return 0;
    }
  return 1;
}

get() { return 1; }

query_weight() { return 0; }

query_value() { return 0; }

drop() { return 1; }
