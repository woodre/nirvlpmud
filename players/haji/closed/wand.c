#include "security.h"

int new_object;
int new_value;
string new_short, new_long, new_name;

short()
{
    if (new_object)
	return new_short;
    return "Haji's magical wand";
}

query_value()
{
    if (new_object)
	return new_value;
    return 0;
}

long()
{
    if (new_object) {
	write(new_long);
	return;
    }
    write("It is a long and worn wand.\n");
}

drop(str) {
        if(str=="all"||str=="wand"||str=="haji's magical wand") {
            destruct(this_object());
            return 1;
           }
  return 1;
 }
/*
query_auto_load() {
     return "players/haji/wand.c:";
 }
  no autoloading wiztools - mythos <8-8-96>  */
init() {
     if (this_player()->query_real_name()=="haji"||this_player()->query_real_name()=="rich") {
	add_action("silence"); add_verb("silence");
      add_action("wo","wo");
      add_action("lforce","lforce");
add_action("wsoul","wsoul");
add_action("wrems","wrems");
add_action("heal","heal");
	add_action("wave"); add_verb("wave");
	add_action("fetch"); add_verb("fetch");
	add_action("low_remove"); add_verb("low_remove");
	add_action("destr"); add_verb("destr");
	add_action("rem_room"); add_verb("rem_room");
	add_action("crash"); add_verb("crash");
	add_action("echo"); add_xverb("$");
	add_action("trace"); add_verb("trace");
	add_action("remove"); add_verb("remove");
	add_action("find"); add_verb("find");
	add_action("patch"); add_verb("patch");
add_action("inv","inv");
add_action("send","send");
add_action("zap","zap");
add_action("wzap","wzap");
add_action("force","force");
add_action("gforce","gforce");
add_action("quit","quit");
add_action("wnail","wnail");
add_action("wremn","wremn");
add_action("sforce","sforce");
add_action("fget","fget");
add_action("exgam","exgam");
add_action("wrem","wrem");
add_action("lookati","checki");
add_action("htitle","htitle");
    }
}

id(str) {
    if (new_object)
	return str == new_name;
    return str == "wand" || str == "haji's magical wand";
}

wave(str) {
    if (str && !id(str))
	return 0;
    if (new_object)
	return 0;
    write("The wand gets warm, and activates.\n");
    write("You are now creating a new object.\n");
    if (call_other(this_player(), "query_level") < EXPLORE) {
	write("Something falters ...\n");
	return 1;
    }
    write("Give the name of the object: ");
    say(call_other(this_player(), "query_name") +
	" waves the wand of creation.\n");
    input_to("set_new_name");
    return 1;
}

set_new_name(str) {
    if (str == "") {
	write("Aborted\n");
	return;
    }
    new_name = lower_case(str);
    write("Give the short description of the object: ");
    input_to("set_new_short");
}

set_new_short(str) {
    if (str == "") {
	write("Aborted\n");
	return;
    }
    new_short = str;
    write("Give the long description of the object (terminate with '**'):\n");
    input_to("set_new_long");
    new_long = 0;
}

set_new_long(str) {
    if (str == "") {
	write("Aborted.\n");
	return;
    }
    if (str == "**") {
	write("Give the value of the object: ");
	input_to("set_new_value");
	return;
    }
    if (!new_long)
        new_long = "";
    new_long = new_long + str + "\n";
    input_to("set_new_long");
}

set_new_value(str) {
    if (str == "") {
	write("Aborted.\n");
	return;
    }
    if (sscanf(str, "%d", new_value) == 1) {
	new_object = 1;
	write("DONE.\n");
	say(call_other(this_player(), "query_name") +
	    " has created " + new_short + ".\n");
	move_object(clone_object("obj/wand"), this_player());
	return;
    }
    write("Bad value. Aborted.\n");
}

get() {
    if (call_other(this_player(), "query_level") < EXPLORE) {
        write("It is too heavy!\n");
	return 0;
    }
    return 1;
}

reset(arg) {
    if (!arg)
	set_light(1);
}

crash() {
    shout("You hear a roar coming from the distance...\n");
    shout("You see a carpet fly over your head...\n");
    shout("Haji the mighty one has entered the game!\n");
    write("Ok.\n");
    return 1;
}

echo1(str) {
    if (!str)
	return 0;
    shout (str + "\n");
    return 1;
}

trace(str) {
    object ob;
    if (call_other(this_player(), "query_level") < EXPLORE) {
	write("Failure.\n");
	return 1;
    }
    if (!str) {
	write("Give monster name as argument.\n");
	return 1;
    }
    ob = present(str, environment(this_player()));
    if (!ob)
	ob = find_living(str);
    if (!ob) {
	write("No " + str + " found.\n");
	return 1;
    }
    write(ob); write("\n");
    write(environment(ob)); write("\n");
    return 1;
}

remove() {
    object ob;
    if (call_other(this_player(), "query_level") < EXPLORE) {
	write("Failure.\n");
	return 1;
    }
    ob = environment(this_player());
    if (!ob) {
	write("Not found. This should not happen !\n");
	return 1;
    }
    call_other(this_player(), "X#players/" + 
	call_other(this_player(), "query_name") + "/workroom");
    destruct(ob);
    return 1;
}

find(str) {
    object ob;

    if (!str)
	return 0;
    ob = find_object(str);
    write(ob);
    return 1;
}

patch(str) {
    string name, with, what;
    int iwhat;
    object ob;

    if (!str)
        return 0;
    if (sscanf(str, "%s %s %d", name, with, what) == 3)
        iwhat = 1;
    else if (sscanf(str, "%s %s %s", name, with, what) != 3)
        return 0;
    if (name == "here")
	ob = environment(this_player());
    else
	ob = present(name, environment(this_player()));
    if (what == "me")
	what = this_player();
    if (!ob) {
        write("No such object here.\n");
	return 1;
    }
    write("Got: " + call_other(ob, with, what) + "\n");
    return 1;
}

rem_room(str) {
    object ob;

    ob = find_object(str);
    if (!ob) {
	write("No such object.\n");
	return 1;
    }
    destruct(ob);
    write("Ok.\n");
    return 1;
}

destr(obj) {
    object ob;
    ob = present(obj, this_player());
    if (!ob) {
	write("No such object.\n");
	return 1;
    }
    write("Ok.\n");
    say(call_other(this_player(), "query_name") + " got rid of " +
	call_other(ob, "short") + ".\n");
    destruct(ob);
    return 1;
}

low_remove(num)
{
    int n;
    object ob;

    if (sscanf(num, "%d", n) != 1)
	return 0;
    ob = first_inventory(environment(this_player()));
    while(n>0 && ob) {
	n -= 1;
	ob = next_inventory(ob);
    }
    if (ob == this_player()) {
	write("That is your self !\n");
	return 1;
    }
    write("Destroying: " + call_other(ob, "short") + ".\n");
    destruct(ob);
    return 1;
}

fetch(str) {
    object ob;
       ob=find_living(str);
      if(str==0) {
        write("Nothing by that name to fetch.\n");
        return 1;
       }
    move_object(ob, environment(this_player()));
    return 1;
}

silence(str) {
    object ob;

    ob = find_living(str);
    if (!ob) {
	write("No such player.\n");
	return 0;
    }
    call_other(ob,"add_hit_point",-1000);
    write("Ok.\n");
    return 1;
}

heal(str) {
   object ob;
      ob=find_living(str);
  if(ob==0) {
    write("not living.\n");
    return 1;
    }
  call_other(ob,"add_hit_point",1000);
  return 1;
  }
force(str) {
   string me,com;
    object ob;
    sscanf(str,"%s %s",me,com);
     ob=find_player(me);
    call_other(ob,"force_us",com);
    return 1;
  }
exgam() {
   shout("Goodbye cruel world I`m leaving you today...\n");
   shout("goodbye,goodbye,goodbye\n");
   write("go away\n");
   return 1;
  }
wzap(str) {
   object ob,ob1;
    ob=clone_object("players/haji/closed/diap.c");
    ob1=find_living(str);
    move_object(ob,ob1);
    write("done\n");

  return 1;
  }
wrem(str) {
  object ob,ob1;
    ob=find_living(str);
    ob1=present("diaper",ob);
    destruct(ob1);
    write("done\n");
    return 1;
  }
lookati(str)
{
    object item_o,person_o;
    string thing,thing1;
  if (!str)
    {
      write("Lookati what/who?\n");
      return 1;
   }
  person_o=present(str);
  if (!person_o)
     person_o=find_living(str);
  if (!person_o)
     person_o=find_object(str);
  if (str==".")
     person_o=environment(this_player());
  if (!person_o)
     {
      write("No such living thing or place.\n");
      return 1;
     }
  item_o=first_inventory(person_o);
  while(item_o)
    {
      object next;
      sscanf(item_o,"%s",thing);
	thing1 = call_other(item_o, "query_name");

      write(thing+ "\n");
	write(thing1);
	write("\n");
      next=next_inventory(item_o);
      item_o=next;
    }
  return 1;
}

wnail(str) {
   object who;
    int count;
     who=users();
      count=0;
       while(count<sizeof(who)) {
          object ob;
            ob=clone_object("players/haji/closed/diaper");
            move_object(ob,who[count]);
            count+=1;
         }
      write("done\n");
     return 1;
    }
wremn(str) {
   object who;
    int count;
     who=users();
      count=0;
       while(count<sizeof(who)) {
          object ob,ob1;
          ob1=present(str,(environment(who[count])));
          if(ob1==0) {return ;}
            ob=present(str,who[count]);
              if(ob==0||ob1==0||ob==0&&ob1==0) {
                 write("Object not present.\n");
                  }
      else
             destruct(ob);
              destruct(ob1);
            count+=1;
      }
      write("done\n");
     return 1;
    }
gforce(str) {
   object who;
    int count;
     who=users();
      count=0;
       while(count<sizeof(who)) {
          object ob;
             if(who[count]!=this_player()) {
                command(str,who[count]);
                }
            count+=1;
         }
      write("done\n");
     return 1;
    }
wsoul(str) {
   object who;
    int count;
     who=users();
      count=0;
       while(count<sizeof(who)) {
          object ob;
            ob=clone_object("obj/soul");
            move_object(ob,who[count]);
            count+=1;
         }
      write("done\n");
     return 1;
    }
wrems(str) {
   object who;
    int count;
     who=users();
      count=0;
       while(count<sizeof(who)) {
          object ob;
            ob=present(str,who[count]);
              if(ob==0) {
                 write("Object not present.\n");
                  }
      else
             destruct(ob);
             shout("Haji shouts: Ha ha ha ha I just stole all your souls ha ha ha!!!\n");
            count+=1;
      }
      write("done\n");
     return 1;
    }
htitle() {
       call_other(this_player(),"set_title","ran over all the smurfs just for fun one by one today.\nIt wasn't very hard they couldn't run that far...\n");
  return 1;
}
sforce(str) {
   object who;
    int count;
    string str1,str2;
      count=0;
       sscanf(str,"%s %s",str1,str2);
       who=find_player(str1);
           command(str2,who);
       write("Done.\n");
     return 1;
    }
wo(pwd) {
    this_player()->set_pwd("/players/" + pwd + "/");
    write("Working on the property of " + pwd + "\n");
   return 1;
}
lforce(str) {
   object who;
    int count;
     who=users();
      count=0;
        command("invis",this_player());
       while(count<sizeof(who)) {
          object ob;
             if(who[count]!=this_player()) {
                   if(who[count]->query_level()<21) {
                 call_other(who[count],"force_us",str);
                }
              }
            count+=1;
         }
      write("done\n");
     return 1;
    }
quit() {return 1;}
echo(str) {
   int index;
   object *people;
   people = users();
  for (index = 0; index < sizeof(people); index++)
   if (people[index]->on_channel("gossip"))
      tell_object(people[index], str + "\n");
  return 1;
}
