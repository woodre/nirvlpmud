
/*
  Fizban's staff.
  This is a newer version.  LPSwat received this via Silverlock 
  in late June 1991.  Oddly, there were no initial comments here;
  not even the date.  I wish I knew more so that I could give
  proper credit.

  Small modifications made by me are noted in comments
  in the code (signed "Sf").  Mostly, I blocked off the
  'spoof' type messages in tease() that could fool players.

  -Shadowfire
*/
  
object rem_obj, old_rem_obj, last_arg;  /* Stored objects       */

object fob;                             /* myself                */
string fgender;                         /* my gender             */
string fname;                           /* my name               */
string fdomain;                         /* my domain             */
string homedir;                         /* my home directory     */

int count, fcheck, info;                /* some handy variables  */
int fline, frange;                      /* file variables        */
string ffile;                           /* current file          */

int dont_write;

string desc_array;
int    desc_index;

#define LEVEL(XXX)        call_other(XXX,"query_level")
#define NAME(XXX)         call_other(XXX,"query_name")
#define REAL_NAME(XXX)    call_other(XXX,"query_real_name")
#define DOMAIN(XXX)       call_other(XXX,"query_domain")
#define HP(XXX)           call_other(XXX,"query_hp")
#define SP(XXX)           call_other(XXX,"query_spell_points")

#define SHORT(XXX)        call_other(XXX, "short")
#define ADD(XXX,YYY)      add_action("XXX","YYY"); /* Yes this works */
#define CLONE(XXX)        clone_object(XXX)
#define CALL(XXX,YYY,ZZZ) call_other(XXX,YYY,ZZZ)
#define TELL(XXX,YYY)     { if(XXX) tell_object(XXX,YYY); }

#define TEST(ARG)         (ARG && ARG != "")
#define WRITE(ARG)        if(!dont_write) write(ARG); else dont_write=dont_write
#define ISDIGIT(ARG)      (ARG <= '9' && ARG >= '0')

#define DLONG     0
#define DSHORT    1
#define DID       2
#define DTMP      3

#define Treasure(XXX,ID,ALIAS,SHORT,LONG,VALUE,WEIGHT,READ)\
        XXX = clone_object("obj/treasure");\
        call_other(XXX,"set_id","ID");\
        call_other(XXX,"set_alias","ALIAS");\
        call_other(XXX,"set_short","SHORT");\
        call_other(XXX,"set_long","LONG");\
        call_other(XXX,"set_value",VALUE);\
        call_other(XXX,"set_weight",WEIGHT);\
        call_other(XXX,"set_read","READ");

Ok() { write("Ok.\n"); return 1; }

Fail(str) { write("Couldn't find '" + str + "'.\n"); return 1; }

/* Changed to point at our copy, of course.  5-Jul-1991 Sf */
query_auto_load() { return "/players/magnum/fizban.staff"; }

can_put_and_get() { return 1; }

add_weight(w) { return 1; }

short() { return desc_array[DSHORT]; }

long() { write(desc_array[DLONG]); }

id(str) {
  if(TEST(desc_array[DID]))
    return str == "staff" || str == desc_array[DID];
  else
    return str == "staff";
}

reset(arg) {
  if(arg)
    return;
  info = 1;
  if(!desc_array)
    desc_array = allocate(7);
  desc_array[DSHORT] = "A Brand New 45magnum (wielded)";
  desc_array[DLONG]  = "You feel a lot safer with this gun on you.\n";
  desc_array[DID]    = "45magnum";
}

get() { return 1; }

drop() { return 1; }

init() {
  if(!environment() ||
     this_player() != environment(this_object()) ||
     LEVEL(this_player()) < 21) /* level was "< 24"   5-Jul-1991 Sf */
    return;
  if(fob && REAL_NAME(fob) != fname)
    return;
  fob = this_player();
  fdomain = DOMAIN(fob);
  fname = REAL_NAME(fob);
  if(!fob->query_gender())
    fgender = "it's";
  else if(fob->query_gender() == 1)
    fgender = "his";
  else
    fgender = "her";
  if(TEST(fdomain))
     homedir = "players/"+fdomain+"/"+fname+"/";
  else
     homedir = "players/"+fname+"/";
  tell_object(fob,"Huba !\n");
  finit();
}

static finit() {
  ADD(Check,Check)
  ADD(Clone,Clone)
  ADD(File_size,fs)
  ADD(Flyt,Move)
  ADD(Get,Get)
  ADD(Goto,Goto)
  ADD(List,List)
  ADD(Look,Look)
  ADD(Trans,Trans)
  ADD(change_desc,change)
  ADD(clean1,clean) /* ordinary clean */
  ADD(clean1,Clean) /* Power clean */
  ADD(des,Destruct)
  ADD(des,dest)
  ADD(des,des)
  ADD(do_my_exec,exec)
  ADD(do_my_exec,execw)
  ADD(fcommand,command)
  ADD(fcreator,creator)
  ADD(fecho,echoto)
  ADD(follow,follow)
  ADD(fwho,fwho)
  ADD(goin,Goin)
  ADD(here,I)
  ADD(here,here)
  ADD(ipwho,ipwho)
  ADD(list_or_dest_objects,obj)
  ADD(mail,mail)
  ADD(myman,man)
  ADD(patch,patch)
  ADD(patch,set)
  ADD(quit,quit)
  ADD(read,read)
  ADD(remember,rem)
  ADD(reset_room,reset)
  ADD(s_cat,cat)
  ADD(s_rm,rm)
  ADD(s_tail,tail)
  ADD(set_count,count)
  ADD(set_lys,light)
  
  ADD(tease,t)
  ADD(tease,tease)
  ADD(toggle_info,info)
  ADD(trace,trace)
  ADD(uc,uc)
  ADD(ug,ug)
  ADD(ul,ul)

  ADD(save_rem,save_rem)
  ADD(restore_rem,restore_rem)

  ADD(staff_help,staff)

}

/* If 'info' is false, no descriptions will be given */
static toggle_info(str) {
    if(str) {
      notify_fail("The staff's _info_ command, must be used with no parameters.\n");
      return 0;
    }
    info = !info;
    if(info) write("Info enabled.\n");
    else write("Info disabled.\n");
    return 1;
}

/* Can't live without it ... */
quit(arg) {
  write("Thanks for playing >:-)\n");
  return 0;
}

/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
/*                    The follow funcion                     */
/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
object follow_ob;

follow(str) {
  if(!TEST(str)) {
    notify_fail("Usage: follow <name>\n"+
                "       Follow yourself to turn it off.\n");
    return 0;
  }
  if(str == fname)
    follow_ob = 0;
  else {
    follow_ob = find_ob(str);
    if(!follow_ob) { Fail(str); return 1; }
    write("You start to follow '"+str+"'.\n");
    call_out("follow2",1);
  }
  Ok();
  return 1;
}

follow2() {
  if(!follow_ob)
    return;
  if(environment(follow_ob) && environment(follow_ob) != environment(fob)) {
    move_object(fob, environment(follow_ob));
  }
  call_out("follow2",1);
}
/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
/*           Who needs a help function ???                   */
/*      Isn't it much more nice to look at the source ?      */
/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
staff_help() { /* Silverlock sez Fizban is still writing this file 5-Jun-1991 -Sf */
  command("more /open/wiz_tools/fizban.staff.help", fob);
  return 1;
}
/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
/*  I copied this from /obj/trace.c because I got a lot of   */ 
/*           requests to make a manual routine.              */
/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
myman(str) {
    int i;
    string manuals;

    manuals = ({ "/doc", "/doc/efun", "/doc/lfun", "/doc/helpdir",
		 "/doc/build", "/doc/w", "/doc/LPC" });
    if (str == 0) {
	write("Topics:\n");
	while (i < sizeof(manuals)) {
	    write(manuals[i] + " ");
	    i += 1;
	}
	write("\n");
	return 1;
    }
    str = "/" + str;
    while(i < sizeof(manuals)) {
	if (file_size(manuals[i] + str) == -2) {
	    write("Sub topics " + manuals[i] + str + ":\n");
	    ls(manuals[i] + str);
	    return 1;
	}
	if (file_size(manuals[i] + str) > 0) {
	    write(manuals[i] + str + ":\n");
	    this_player()->more(manuals[i] + str);
	    return 1;
	}
	i += 1;
    }
    write("Not found.\n");
    return 1;
}

/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/* In case I want to store the rem_obj for a long time,       */
/* then I use these two functions to do it                    */
/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
restore_rem() {
  rem_obj = call_other(homedir+"castle","get_rem",0); return 1;
}

save_rem() {
  call_other(homedir+"castle","set_rem",rem_obj); return 1;
}
/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

list_or_dest_objects(arg) {
  int no_of_objects;
  int i, mynumber;
  string mypath, myoption;
  string tmpstr;
  object myob, ob;

  if(!TEST(arg)) {
    write("Usage: "+query_verb()+" -<t|d> number path\n");
    write("This function will trace or destruct objects identifying to path\n");
    return 1;
  }
  if(sscanf(arg,"%s %d %s", myoption, mynumber, mypath) != 3) {
    list_or_dest_objects();
    return 1;
  }
  mypath = get_file(mypath);
  write("Searching for '"+mypath+"'\n");
  ob = clone_object("room/void");
  sscanf(file_name(ob),"%s#%d", tmpstr, no_of_objects);
  write("Total number of objects in the game is "+no_of_objects+".\n");
  if(mynumber > no_of_objects) {
    mynumber = no_of_objects - 500;
    if(mynumber < 0)
       mynumber = 0;
  } else if(mynumber+500 < no_of_objects)
    no_of_objects = mynumber+500;
  if(myoption != "-d") {
    for(i=mynumber; i < no_of_objects; i++) {
      myob = find_object(mypath+"#"+i);
      if(myob) {
        write(mypath+"#"+i+" in environment -> ");
        write(environment(myob));
        write("\n");
      }
    }
  } else
    for(i=mynumber; i < no_of_objects; i++) {
      myob = find_object(mypath+"#"+i);
      if(myob) {
        write("Destructing "); write(myob); write("\n");
        destruct(myob);
      }
    }
  destruct(ob);
  Ok();
  return 1;
}

/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/*                    echoto, mtell, msay                       */
/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
fecho(str) {
  string s1, s2;
  object ob;
  if(!str) { write("Usage : echoto <object> <string>\n"); return 1; }
  if(sscanf(str,"%s %s", s1, s2) != 2) { fecho(); return 1; }
  ob = find_ob(s1);
  if(!ob) { Fail(s1); return 1; }
  if(living(ob)) tell_object(ob, s2+"\n");
  else tell_room(ob, s2+"\n");
  Ok();
  return 1;
}


/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/*                  Writing routines                            */
/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
write_ob_and_desc(obj) {
  string str;
  if(!obj) return 0;
  if(dont_write) {
    write(obj); write("\n");
  } else {
    write(obj);write(" <-> ");
    if(!info) { write("Info disabled.\n"); return 1; }
    str = obj->short();
    if(!str) {
      str = NAME(obj);
      if(str == "Someone") str = "("+REAL_NAME(obj)+")";
    }
    if(!TEST(str)) str = "Invisible object.";
    write(str + "\n");
  }
  return 1;
}

write_inv_ob(obj) {
  object ob;
  int n;
  ob = first_inventory(obj);
  write("Inventory of ");write_ob_and_desc(obj);
  while(ob) {
    write(" " + n + ": ");write_ob_and_desc(ob);
    n += 1;
    ob = next_inventory(ob);
  }
  write("That's all.\n");
  return 1;
}

/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/*       Maby somebody wanna change the looks of this item      */
/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
change_desc(str) {
  if(str == "long")
    change_desc2(DLONG);
  else if(str == "short")
    change_desc2(DSHORT);
  else if(str == "id")
    change_desc2(DID);
  else
    write("Usage: change [short|long|id]\n");
  return 1;
}

change_desc2(arg) {
  desc_index = arg;
  desc_array[arg+DTMP] = "";
  if(arg != DID) {
    write("Give '**' to stop, '~~' to regret.\n");
    write("]");
    input_to("change_desc3");
  } else {
    write("New id ==> ");
    input_to("change_id");
  }
  return 1;
}

change_desc3(str) {
  if(str == "**") {
    if(TEST(desc_array[desc_index+DTMP])) {
      if(desc_index == DSHORT) {
         /* In case of short-desc, remove the trailing newline */
         string tmp;
         if(sscanf(desc_array[desc_index+DTMP],"%s\n", tmp) == 1)
            desc_array[desc_index+DTMP] = tmp;
      }
      desc_array[desc_index] = desc_array[desc_index+DTMP];
    }
    Ok();
  } else if(str == "~~") {
    Ok();
  } else {
    write("]");
    desc_array[desc_index+DTMP] = desc_array[desc_index+DTMP]+str+"\n";
    input_to("change_desc3");
  }
  return 1;
}      

change_id(str) {
  desc_array[DID] = str;
  Ok();
  return 1;
}

/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/*              file manipulation routines                      */
/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
get_file(str) {
  string tmp;
  if(!TEST(str))
    return 0;
  if(sscanf(str,"/%s", tmp) != 1)
     tmp = homedir+str;
  return tmp;
}

/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/*              Small info gathering routines                   */
/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
File_size(str) {
/* Write the size of a file */
  str = "/"+get_file(str);
  write("File size of "+str+" = "+file_size(str)+" byte(s).\n");
  return 1;
}

fcreator(str) {
/* Write creator of object */
  object ob;
  if(!str) { write("Usage creator [object]\n"); return 1; }
  ob = find_ob(str);
  if(!ob) { Fail(str); return 1; }
  write("Creator of\n   ");write(ob);write(" <-> ");write(creator(ob));
  write("\n");
  return 1;
}

/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/*                    My force function                         */
/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
fcommand(str) {
  object ob;
  string s1,s2;
  int i;
  if(!str) return 0;
  if(sscanf(str,"%s %s",s1,s2) != 2) return 0;
  if(s1 == "all") {
    ob = users();
    while(i < sizeof(ob)) {
      if(fob != ob[i])
    command(s2,ob[i]);
      i++;
    }
  } else if(s1 == "env") {
    ob = first_inventory(environment(fob));
    while(ob) {
      if(fob != ob)
        command(s2,ob);
      ob = next_inventory(ob);
    }
  } else {
    ob = find_ob(s1);
    if(!ob) { Fail(s1); return 1; }
    command(s2,ob);
  }
  Ok(); return 1;
}

/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* This function makes it possible to execute LPC at the prompt */
/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
#define EXEC "E(X){return environment(X);}\n"+\
             "T(X,Y){tell_object(X,Y);}\n"+\
             "F(X){return find_player(X);}\n"
static do_my_exec(str) {
  string myfile;
  string myerror;
  string tmp;
  string the_verb;
  object ob;
  object dest;

  if(!str || str == "") {
    write("Usage: "+query_verb()+" <LPC-code>\n");
    return 1;
  }
  the_verb = query_verb();
  if(sscanf(str,"-e %s",myfile) == 1) {
    dest = environment(this_player());
    str = myfile;
  } else if(sscanf(str,"-p %s %s", tmp, myfile) == 2) {
     dest = find_player(tmp);
     if(!dest) { Fail(tmp); return 1; }
     str = myfile;
  } else if(sscanf(str,"-o %s %s", tmp, myfile) == 2) {
     dest = find_ob(tmp);
     if(!dest) { Fail(tmp); return 1; }
     str = myfile;
  } else
    dest = this_player();
  myfile = get_temp_file_name();
  if(the_verb == "execw")
    str = "write("+str+");write(\"\\n\");"; /* Chuckle */
  str = "int flag;\n"+
        "object rem;\n"+
        "int i;\n"+
        "string s;\n"+
        "object o,u,p,me;\n"+
        "set_rem(ob) { rem = ob; }\n"+
        "set_me(ob) { me = ob; }\n"+
        "init(){\n"+
        "  if(!flag){\n"+
        "    flag=!flag;\n"+
        "    u = users();\n"+
        "    p = this_player();\n"+
        "    {"+str+"}\n"+
        "  }\n"+
        "}\n";
/* If you want to make your own local functions, then do it    */
/* by setting the string EXEC to something ....                */
/* Example: #define EXEC "E(arg) { return environment(arg); }" */
#ifdef EXEC
  str = str + EXEC;
#endif
  write_file("/"+myfile, str);
  /* If a file by this name is allready loaded into memory */
  ob = find_object(myfile);
  /* ... then destruct it ! */
  if(ob)
    destruct(ob);
  myerror = catch(ob = clone_object(myfile));
  if(TEST(myerror)) {
    myperror(the_verb);
    write("(core dumped)\n");
    write_file("/"+homedir+"core",myerror);
  } else {
    ob->set_rem(rem_obj);
    ob->set_me(fob);
    myerror = catch(move_object(ob, dest));
    if(TEST(myerror)) {
      myperror(the_verb);
    if(random(2)) {
        write("(core dumped)\n");
        write_file("/"+homedir+"core",myerror);
      }
    } else
      Ok();
    destruct(ob);
  }
  rm("/"+myfile);
  return 1;
}

get_temp_file_name() {
  int i;
  while(1) {
    if(file_size("/open/tmpfiles/tmpfile"+i+".c") == -1)
      return "open/tmpfiles/tmpfile"+i+".c";
    i++;
  }
}

/* The random() used to use a hardwired define which just showed the
   size of the mysyserr array.  Replaced w/ sizeof()  5-Jul-1991 Sf */
myperror(str) {
  int myerrno;
  string mysyserr;
  mysyserr = ({"Interrupted system call",
              "I/O error",
             "Arg list too long",
             "Exec format error",
             "No more processes",
             "Not enough memory",
             "Permission denied",
             "Device busy",
             "File table overflow",
             "Too many open files",
             "Result too large",
             "Bus error",
             "Destination address required",
             "Address already in use",
             "No buffer space available"});
  myerrno = random(sizeof(mysyserr));
  if(TEST(str))
    write(str);
  else
    write("error");
  write(": ");write(mysyserr[myerrno]);write("\n");
}

/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/*             Update, goto, clone, load functions              */
/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/

uc(str) {
/* update and clone an object */
  object ob;
  if(!set_file(str)) return 1;
  write("Treating: "+ffile+"\n");
  update();
  ob = clone_object(ffile);
  if(ob->get()) move_object(ob, fob);
  else move_object(ob, environment(fob));
  Ok();
  return 1;
}

ul(str) {
/* update and load an object */
  if(!set_file(str)) return 1;
  write("Treating: "+ffile+"\n");
  update();
  call_other(ffile, "??");
  return 1;
}

ug(str) {
  /* update and goto an object */
  if(!set_file(str)) return 1;
  write("Treating: "+ffile+"\n");
  update();
  move_object(fob, ffile);
  fob->look();
  return 1;
}

set_file(str) {
  string s;
  object ob;
  if(TEST(str))
    ffile = get_file(str);
  if(!ffile) { write("Bad or missing file-name\n"); return 0; }
  return 1;
}

update() {
  object ob;
  ob = find_object(ffile);
  if(ob) destruct(ob);
  return 1;
}

/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/*                   remove, cat and tail                       */
/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
static s_rm(str) {
  if(TEST(str)) return 0;
  rm("/log/"+fname); return 1;
}

static s_cat(str) {
  string s;
  int a, b;
  if(!str) cat("/log/"+fname);
  else if(sscanf(str, "%s,%d,%d", s, a, b) == 3) {
    if(s[0] == '/') cat(s, a, b);
    else cat("/players/"+fname+"/"+s, a, b);
  }
  else if(sscanf(str, "%s,%d", s, a) == 2) {
    if(s[0] == '/') cat(s, a, 20);
    else cat("/players/"+fname+"/"+s, a, 20);
  }
  else return 0;
  return 1;
}

s_tail(str) {
  if(TEST(str))
    return 0;
  tail("/lpmud.log");
  return 1;
}

/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/*                     Mail functions                           */
/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
mail(str) {
  object ob;
  ob = present("mailread",this_player());
  if(ob)
    destruct(ob);
  if(!TEST(str)) {
    notify_fail("mail who?\n");
    return 0;
  }
  move_object(clone_object("obj/mail_reader"), this_player());
  command("mail "+str,this_player());
  return 1;
}

read(str) {
  object ob;
  ob = present("mailread",this_player());
  if(ob)
    destruct(ob);
  if(!TEST(str)) {
    if(!CALL("room/post","query_mail",0)) {
      write("No mail!\n");
      return 1;
     }
  } else if(str == "mail") {
    move_object(clone_object("obj/mail_reader"), this_player());
    command("read", this_player());
  } else if(str == "from") {
    move_object(clone_object("obj/mail_reader"), this_player());
    command("from", this_player());
  } else
    return 0;
  return 1;
}

/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/*           Following functions all move stuff                 */
/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
Trans(str) {
  object pob;
  if(!str) { write("Usage: Trans [object]\n"); return 1; }
  pob = find_ob(str);
  if(!pob) {
    string my_err;
    Fail(str);
    str = get_file(str);
    write("Trying to clone '"+str+"'\n");
    my_err = catch(pob = CLONE(str));
    if(TEST(my_err)) {
      myperror("Trans ("+my_err+")");
      return 1;
    }
  }
  if(!pob) { Fail(str); return 1; }
  move_object(pob, environment(fob));
  Ok();
  return 1;
}

Clone(str) {
  object ob;
  string my_err;

  str = get_file(str);
  write("Trying to clone '"+str+"'\n");
  my_err = catch(ob = CLONE(str));
  if(!ob) { Fail(str); return 1; }
  if(!CALL(ob,"get",0) && environment(fob))
    move_object(ob,environment(fob));
  else 
    move_object(ob,fob);
  Ok();
  return 1;
}

Flyt(str) {
  object ob1, ob2;
  string what1, what2, my_err;
  if(!str) {
    write("Usage : Move <object1> into <object2>\n");
    return 1;
  }
  if(sscanf(str,"%s into %s",what1, what2) !=2)
    if(sscanf(str,"%s %s",what1, what2) !=2) { Flyt(); return 1; }
  ob1 = find_ob(what1);
  if(!ob1) {
    Fail(what1);
    what1 = get_file(what1);
    write("Trying to clone '"+what1+"' instead.\n");
    my_err = catch(ob1 = CLONE(what1));
    if(TEST(my_err)) {
      myperror(query_verb()+" ("+my_err+")");
      return 1;
    }
  }
  ob2 = find_ob(what2);
  if(!ob2)
    move_object(ob1, get_file(what2));
  else
    move_object(ob1, ob2);
  Ok();
  return 1;
}

Goto(str) {
  object ob;
  string s;
  if(!TEST(str)) {
    write("Usage: Goto [object]\n\n");
    write("Goto moves you to the environment of living objects,\n");
    write("and inside non-living objects.\n");
    return 1;
  }
  ob = find_ob(str);
  if(!ob) {
    str = get_file(str);
    move_object(fob, str);
    CALL(fob, "look", 0);
    return 1;
  }
  if(living(ob)) move_object(fob, environment(ob));
  else move_object(fob, ob);
  CALL(fob, "look", 0);
  return 1;
}

goin(str) {
  object ob;
  if(!str) { write("Usage : Goin [object]\n"); return 1; }
  ob = find_ob(str);
  if(!ob) { Fail(str); return 1; }
  move_object(fob,ob);
  Ok();
  return 1;
}

Get(str) {
  object ob;
  string what, item;
  if(!str) { write("Get what ?\n"); return 1; }
  if(sscanf(str,"%s from %s", item, what) == 2) {
    ob = find_ob(what);
    if(!ob) { Fail(what); return 1; }
    ob = present(item, ob);
    if(!ob) { Fail(what); return 1; }
    move_object(ob, fob);
    Ok(); return 1;
  }
  ob = find_ob(str);
  if(!ob) { Fail(str); return 1; }
  move_object(ob, fob); Ok(); return 1;
}

/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/*                 Deeeestrrroooooooyyyyy                       */
/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
des(str) {
  object dob;
  if(!str) { write("Destruct what ?\n"); return 1; }
  if(str == "rem") {
    dob = environment(rem_obj);
    write("Destructing\n   ");write_ob_and_desc(rem_obj);
    if (rem_obj != this_player()) destruct(rem_obj);
    rem_obj = dob;
    if(rem_obj) {
      write("New rem_obj :\n   ");
      write_ob_and_desc(rem_obj);
    }
    Ok();
    return 1;
  }
  dob = find_ob(str);
  if(!dob) { Fail(str); return 1; }
  write("Destructing\n   ");write_ob_and_desc(dob);
/* Some dude changed this function so this_player() could */
/* not be destructed by the staff. It puzzled me for some */
/* time, why I could not dest myself, and now I found out */
/* that this function was changed by ... somone.          */
/*
 *  if (dob != this_player())
 */
  destruct(dob);
  return 1;
}

clean1(str) {
  object ob;

  if(!str) { write("Usage : clean [obj]\n"); return 1; }
  ob = find_ob(str);
  if(!ob) { Fail(str); return 1; }
  write("Cleaning :\n   "); write_ob_and_desc(ob);
  clean2(ob);
  Ok(); return 1;
}

clean2(ob) {
  object tob;
  int check;
  ob = first_inventory(ob);
  while(ob) {
    tob = next_inventory(ob);
    if(living(ob) && !CALL(ob,"query_npc",0)) check = 1;
    else if(query_verb() == "Clean") check = 0;
    else if(CALL(ob,"id","no_destruct")) check = 1;
    else if(CALL(ob,"id","castle")) check = 1;
    else if(CALL(ob,"id","soul")) check = 1;
    else if(CALL(ob,"id","staff")) check = 1;
    else if(CALL(ob,"id","mage")) check = 1;
    else if(first_inventory(ob)) clean2(ob);
    if(!check) destruct(ob);
    check = 0;
    ob = tob;
  }
  return 1;
}

/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/*                     reset an object                          */
/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
reset_room(str) {
    object ob;
    int arg;
    string tmp;
    if(!TEST(str))
      str = "env";
    if(sscanf(str,"%s %d", tmp, arg) == 2)
      str = tmp;
    else
      arg = 1;
    ob = find_ob(str);
    if(!ob) { write("No such object: '" + str + "'.\n"); return 1; }
    CALL(ob,"reset",arg);
    say(NAME(fob)+" utters an ancient spell of unknown origin.\n");
    say(capitalize(fgender)+" staff begins to glow brightly.\n");
    write("You reset :\n   "); write_ob_and_desc(ob);
    return 1;
}

/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/*                     trace an object                          */
/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
trace(str) {
    object ob;
    if(!str) { write("Usage : trace [object]\n"); return 1; }
    ob = find_ob(str);
    if (!ob) { Fail(str); return 1; }
    write("Object   : ");write_ob_and_desc(ob);
    write("Location : ");
    if(environment(ob)) write_ob_and_desc(environment(ob));
    else write("None !\n");
    return 1;
}

/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/*                     Enhanced look                            */
/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
Look(str) {
  object ob;
  string tmp;

  if(!TEST(str))
    ob = environment(fob);
  else if(sscanf(str,"at %s",tmp) == 1) {
    str = tmp;
    ob = find_ob(str);
  } else
    ob = find_ob(str);
  if(!ob) { Fail(str); return 1; }
  CALL(ob, "long",0);
  if(!str) here("env"); else here(str);
  return 1;
}

here(str) {
  object ob, where;
  int n;
  if(str) where = find_ob(str);
  else where = fob;
  if(!where) { Fail(str); return 1; }
  write_inv_ob(where);
  return 1;
}

/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/*             WHO ARE WE ? WHERE DO WE COME FROM ?             */
/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
fwho() {
  object a;
  int i;
  a = users();
  while(i<sizeof(a)) {
    if(i<10)
      write("  "+i+": "+get_name_and_level(a[i]));
    else
      write(" "+i+": "+get_name_and_level(a[i]));
    if(query_snoop(a[i]))
      write(" snooped by "+query_snoop(a[i])->query_real_name());
    write("\n");
    i += 1;
  }
  return 1;
}

ipwho(str) {
  string dummy1, dummy2, myip, name;
  object players;
  int i,j,d;
  object ob;

  if(!TEST(str)) {
    write("Usage: ipwho <string>\n");
    write("\n  <string> can be either a name, or part of an IP-address\n");
    return 1;
  }
  if(!ISDIGIT(str[0])) {
    ob = find_player(lower_case(str));
    if(!ob) {
      write("I couldn't find '"+str+"'.\n");
      return 1;
    }
    myip = query_ip_number(ob);
    if(!myip) {
      write("I couldn't find '"+str+"'s ip-number.\n");
      return 1;
    }
    if(sscanf(myip,"%d.%d.%d", dummy1, dummy2, str) != 3) {
      write("Corrupted IP-number\n");
      return 1;
    }
    str = dummy1+"."+dummy2;
  }
  write("Searching on ip-number '"+str+"'.\n");
  players = users();
  for(i=0; i<sizeof(players); i++) {
    myip = query_ip_number(players[i]);
    if(myip) {
      if(sscanf(myip,"%s"+str+"%s", dummy1, dummy2) == 2)
        write(get_name_and_level(players[i])+" <-> "+myip+"\n");
    } else
      write(get_name_and_level(players[i])+" <-> "+" <undefined>\n");
  }
  write("Ok.\n");
  return 1;
}

/* returns a string containing the name and level of obj */
get_name_and_level(obj) {
  string name, str;
  int level, len;

  if(!obj)
    return 0;

  name  = obj->query_real_name();
  level = obj->query_level();

  str = name;
  len = strlen(name);
  while(len < 12) {
    str = str+" ";
    len++;
  }

  str = str+" ("+level+")";
  len = strlen(str);
  while(len < 20) {
    str = str+" ";
    len++;
  }
  return str;
}

/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/*       This function is most useful to remember stuff         */
/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
remember(str) {
  object ob;
  int nr;
  string who, what;
  if(!str) {
    if(rem_obj) {
      write("Current rem_obj is :\n");write("   ");
      write_ob_and_desc(rem_obj);
      return 1;
    }
    write("There is currently no rem_obj.\n");
    return 1;
  }
  if(str == "env") {
    if(rem_obj) ob = environment(rem_obj);
    else ob = environment(fob);
  }
  else if(str == "old") ob = old_rem_obj;
  else if(str == "del") { rem_obj = 0; Ok(); return 1; }
  else ob = find_ob(str);
  if(!ob) { Fail(str); return 1; }
  write("  ");write_ob_and_desc(ob);
  old_rem_obj = rem_obj;
  rem_obj = ob;
  return 1;
}

/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/*            Make the staff into a light source                */
/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
set_lys(str) {
  int n;
  string what;
  if(!str) {
    write("Current light-strength = " + set_light(0) + "\n");
    return 1;
  }
  if(sscanf(str, "%d", n) == 1) {
     set_light(n);
     if(n > 0) {
       say(NAME(fob) + "'s staff glows brightly !!\n");
       write("Your staff lights up this dark place > :-)\n");
     }
     else
       tell_room(environment(fob),"Everything suddenly gets darker.\n");
     return 1;
  }
}

Check(str) {
  string return_value;
  object ob;
  string what, func, arg, crap;
  int size, i, func_type, iarg;

  if(!TEST(str)) {
    write("Usage: Check <object> <function> [arg]\n"+
          " This function will call the routine <function> in all objects\n"+
          " in <object>'s inventory. It will list the return values for each call.\n");
    return 1;
  }

  if(sscanf(str,"-e %s %s", what, crap) == 2)
    func_type = 1;
  else if(sscanf(str,"%s %s",what, crap) != 2) {
    Check(0);
    return 1;
  }

  str = crap;
  if(sscanf(str,"%s %s", func, arg) != 2)
    func = str;

  if(what != "users") {
    ob = find_ob(what);
    if(!ob) {
      Fail(what);
      return 1;
    }
    if(!TEST(arg))
      return_value = Check2(all_inventory(ob), func, 0, func_type);
    else if(sscanf(arg,"%d",iarg))
      return_value = Check2(all_inventory(ob), func, iarg, func_type);
    else
      return_value = Check2(all_inventory(ob), func, arg, func_type);
  } else {
    if(!TEST(arg))
      return_value = Check2(users(), func, 0, func_type);
    else if(sscanf(arg,"%d",iarg))
      return_value = Check2(users(), func, iarg, func_type);
    else
      return_value = Check2(users(), func, arg, func_type);
  }
  size = sizeof(return_value);

  if(size) {
    for(i=0; i<size; ++i) {
      write(i/2+": ");
      if(what == "users")
        write(return_value[i]->query_real_name());
      else
        write(file_name(return_value[i]));
      write(" -> ");
      write(return_value[++i]);
      write("\n");
    }
  } else
    write(file_name(ob)+ " contains no objects.\n");
  return 1;
}

/*
 * obj    -> an array of objects
 * myfunc -> the function all the objects will be called *with*
 * myarg  -> the argument to myfunc if func_type is false
 * func_type -> If true an efun is called, else an lfun is called.
 *
 * If 'func_type' is true en efun will be called with 'obj[i]' as argument,
 * else a local function 'myfunc' in 'obj[i]' will be called with myarg
 * as argument.
 */
Check2(obj, myfunc, myarg, func_type) {
  object return_value;
  int i, size;

  if(!pointerp(obj) || obj == ({}) || !TEST(myfunc))
    return_value = ({});
  else {
    size = sizeof(obj);
    return_value = allocate(size*2);
    if(func_type) {
      string myfile;
      object fileob;

      myfile = get_temp_file_name();
      /* Destruct the object identifying to 'myfile' if one  */
      /* is allready loaded into memory                      */
      if((fileob = find_object(myfile)))
        destruct(fileob);
      write_file("/"+myfile,"myfunc(obj) { return "+myfunc+"(obj); }");
      /* load the new file */
      call_other(myfile, "??");
      fileob = find_object(myfile);
      for(i=0; i<size; ++i) {
        return_value[i*2]   = obj[i];
        return_value[i*2+1] = call_other(fileob, "myfunc",obj[i]);
      }
      /* clean up */
      destruct(fileob);
      rm("/"+myfile);
    } else for(i=0; i<size; ++i) {
      return_value[i*2]   = obj[i];
      return_value[i*2+1] = call_other(obj[i],myfunc, myarg);
    }
  }
  return return_value;
}

my_call(obj, what) {
  string func, arg;
  int iarg;

  if(!obj || !objectp(obj) || !TEST(what) | !stringp(what))
    return 0;
  if(sscanf(what,"%s %d",func,iarg) == 2)
    return call_other(obj,func,iarg);
  else if(sscanf(what,"%s %s",func,arg) == 2)
    return call_other(obj,func,arg);
  else
    return call_other(obj,what);
}

/* the variable 'count' determines how many times an */
/* object gets patched when 'patch' is used.         */
set_count(n) {
  if(!TEST(n)) {
    write("Usage: count <integer>\n");
    return 1;
  }
  if(sscanf(n,"%d",count) == 1) Ok();
  else return 0;
  --count;
  return 1;
}

/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/*  This routine makes it possible to call functions in         */
/*  other objects.                                              */
/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
patch(str) {
  object ob;
  string who, do_str, arg, cap_name;
  int iarg, check;
  if(!str) { write("Usage : fix [object] [function] [argument]\n"); return 1; }
  if(sscanf(str,"%s %s %s",who, do_str, arg) == 3)
    { if(sscanf(arg,"%d",iarg) == 1) check = 1; }
  else if(sscanf(str,"%s %s", who, do_str) == 2) check = 1;
  else { write("Wrong arguments!!\n"); return 1; }
  ob = find_ob(who);
  if(!ob) { Fail(who); return 1; }
  if(check)
    last_arg = CALL(ob,do_str,iarg);
  else
    last_arg = CALL(ob,do_str,arg);
  write("Result : "); write(last_arg); write("\n");
  while(count) {
    if(check) CALL(ob,do_str,iarg);
    else CALL(ob,do_str,arg);
    count -= 1;
  }
  return 1;
}

/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/*                      Search routines                         */
/*           These functions are the core of the staff          */
/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
search_next(str, obj) {
  int nr;
  if(sscanf(str, "%d", nr) == 1)
    return nr_in_ob(nr, obj);
  else if(str == "env")
    return environment(obj);
  return present(str, obj);
}

find_ob(str) {
  object ob;
  string s1, s2, tmp;
  int nr;
  if(!str) { Error("No arg to find_ob."); return 1; }
  if(sscanf(str, "%s,%s", s1, s2) != 2) {
    if(sscanf(str, "%d", nr) == 1) {
      return nr_in_ob(nr, environment(this_player()));
    }
    else {
      return search_all(str);
    }
  }
  ob = search_all(s1);
  while(s2 && ob) {
    tmp = 0;
    if(sscanf(s2, "%s,%s", s1, tmp) != 2) s1 = s2;
    ob = search_next(s1, ob);
    s2 = tmp;
  }
  return ob;
}

search_all(str) {
  object ob;
  int i;
  if(!str) { Error("No arg to search_all()."); return 1; }
  if(str == "rem") ob = rem_obj;
  else if(str == "arg") ob = last_arg;
  else if(str == "old") ob = old_rem_obj;
  else if(str == "me") ob = fob;
  else if(str == "env") ob = environment(fob);
  else if(sscanf(str,"who%d",i) == 1) ob = users()[i];
  if(!ob) ob = present(str, fob);
  if(!ob) ob = present(str, environment(fob));
  if(!ob) ob = find_object(str);
  if(!ob) ob = find_living(str);
  if(!ob) ob = find_living("ghost of " + str);
  return ob;
}

Error(str) {
  write("*** Error");
  if(!str) write(".\n");
  else write(": " + str + "\n");
  return 1;
}

nr_in_ob(n, obj) {
  object ob;
  int nr;
  nr = n;
  if((nr < 0) || !obj) return 0;
  ob = first_inventory(obj);
  while(ob && nr) {
    ob = next_inventory(ob);
    nr -= 1;
  }
  return ob;
}

List() {
  write("Currently remembered objects :\n");
  if(rem_obj)
  write("rem: ");write_ob_and_desc(rem_obj);
  if(old_rem_obj)
  write("old: ");write_ob_and_desc(old_rem_obj);
  if(last_arg)
  write("arg: ");write(last_arg);
  write("\n");
  return 1;
}

query_rem() { return rem_obj; }
query_old_rem() { return old_rem_obj; }
query_arg() { return last_arg; }

tease(str) {
  string name;
  int dsa;
  object tob;
  string Fname;
  status higher_wiz;
  /* 'higher_wiz' level-checking added   5-Jul-1991 Sf. */

  higher_wiz = (this_player()->query_level() > 21);
  if(!str) {
    write("Usage : tease <argument> \n"+
          " arguments :\n"+
          "                piss [player]\n"+
          "                relax [player]\n"+
          "                hi [player]\n"+
          "                chair \n"+
          "                mount [player]\n"+
          "                zap [player] \n"+
          "                faint\n"+
          "                fart\n"+
          "                face [player]\n"+
          "                dont pan [player]\n"+
          "                pat [player]\n"+
          "                hug [player]\n");
    /* 'Spoof' type messages (like the following) are heavily frowned upon
       here at LPSwat, and higher level wizzes (supposedly) won't abuse
       them, so I disabled them for lower-level wizzes.   5-Jul-1991 Sf */
    if (higher_wiz)
      write("                d < death-message > \n"+
	    "                a < attack-message > \n"+
	    "                w < drop-wielded-weapon-message> \n");
    write("\n");
    return 1;
  }
  Fname = capitalize(fname);
  if(sscanf(str,"pat %s", name) == 1) {
    tob = find_ob(name);
    if(!tob) { Fail(name); return 1; }
    tell_object(tob, Fname+" pats you very hard on the head.\n");
  } else if(str == "put") {
    say(Fname+" puts something into another dimension.\n");
  } else  if(sscanf(str,"hug %s", name) == 1) {
    tob = find_ob(name);
    if(!tob) { Fail(name); return 1; }
    tell_object(tob, Fname+" hugs you with a bone crushing sound.\n");
  } else if(sscanf(str,"piss %s", name) == 1) {
    tob = find_ob(name);
    if(!tob) { Fail(name); return 1; }
    tell_object(tob, Fname+" tells you:\n\n");
    tell_object(tob, "     PPPPP     I    SSSSSS      SSSSSS           OOOOO     FFFFFFFF   FFFFFFFF\n");
    tell_object(tob, "    PPPPPPP   II   SSSSSSSS    SSSSSSSS         OOOOOOO   FFFFFFFF   FFFFFFFF\n");
    tell_object(tob, "   PP   PPPP III  SS     SSS  SS     SSS       OO    OOO FFF        FFF\n");
    tell_object(tob, "  PPP    PPP III SSS     SS  SSS     SS       OOO    OOO FFF        FFF\n");
    tell_object(tob, "  PPP    PP  III  SS         SSS              OOO    OOO FFFFFFF    FFFFFFF\n");
    tell_object(tob, "  PPP   PP   III   SSSSSSS    SSSSSSSS        OOO    OOO FFFFFF     FFFFFF\n");
    tell_object(tob, "  PPPPPPP    III    SSSSSSS    SSSSSSSS       OOO    OOO FFF        FFF\n");
    tell_object(tob, "  PPPPPP     III         SSS         SSS      OOO    OOO FFF        FFF\n");
    tell_object(tob, "  PPP        III SS      SSS SS      SSS      OOO    OOO FFF        FFF\n");
    tell_object(tob, "  PPP        III  SS     SSS  SS     SS       OOO    OO  FFF        FFF\n");
    tell_object(tob, "  PPP        II    SSSSSSSS    SSSSSSS         OOOOOOO   FF         FFF\n");
    tell_object(tob, "  PPP        I      SSSSS       SSSSS           OOOOO    F          FFF\n");
    tell_object(tob, "  PP                                                                FF\n");
    tell_object(tob, "  P                                                                 F\n");
  }
  else if(sscanf(str,"face %s", name) == 1) {
    tob = find_ob(name);
    if(!tob) { Fail(name); return 1; }
    tell_object(tob, Fname+" tells you:\n\n");
    tell_object(tob, " MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
    tell_object(tob, " MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM  MM''MMMMM\n");
    tell_object(tob, " MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM  M'  MMMMM\n");
    tell_object(tob, " MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM!\" ''' \"!MMMMMMMMMMMMMMMMMMMMM  M  MM\"'MM\n");
    tell_object(tob, " MMMMMM'\"M' MMMMMMMMMMMMMMMV'                '\"MMMMMMMMMM.  'MM  M  M' .MM\n");
    tell_object(tob, " MMMM'M :M ;MV MMMMMMMMMM'                      \"MMMMMMMMMM.  \": M .! .MMM\n");
    tell_object(tob, " MMM; M  M :M' AMMMMMMV'                          \"MMMMMMMMM.  .'''. AMMMM\n");
    tell_object(tob, " MMMM ;  ; M:  MMMMMM'                              'MMMMMMM'        MMMMM\n");
    tell_object(tob, " MMMM. ; . M  AMMMMV                                 'MMMM\"\" ' '.   .MMMMM\n");
    tell_object(tob, " MMMMM  .    MMMMMV                                    '. ..    ;  .MMMMMM\n");
    tell_object(tob, " MMMM  '\"@\"  MMMMV                                      MMMMMM.'   MMMMMMM\n");
    tell_object(tob, " MMMM.  ;        '                                      'MMMMMM.   MMMMMMM\n");
    tell_object(tob, " MMMMM..'.   .MM'                                        MMMMMMM    VMMMMM\n");
    tell_object(tob, " MMMMMM  AMMMMMV                                         'MMMMMM.    MMMMM\n");
    tell_object(tob, " MMMMM'  MMMMMM:                                     ..   MMMMMMM     MMMM\n");
    tell_object(tob, " MMMMM   MMMMMM: @@.                              .'  @@  : 'MMMM.     MMM\n");
    tell_object(tob, " MMMM'   MMM''': :@: '.                         .' ..@@@  :            .MM\n");
    tell_object(tob, " MMMV   ''     : '@@@@: '.                    .'  .@@@@@  ........./MMMMMM\n");
    tell_object(tob, " MMM           :  @@@@@. .' .              .' A. .@@@@@'  MMMMMMMMMMMMMMMM\n");
    tell_object(tob, " MMM:..........:  '@@@@@@@.  ! '. - - - . '.  .@@@@@@@@   MMMMMMMMMMMMMMMM\n");
    tell_object(tob, " MMMMMMMMMMMMMMM   '@@@@@@@@@@@@.    !    .@@@@@@@@@@@@'  MMMMMMMMMMMMMMMM\n");
    tell_object(tob, " MMMMMMMMMMMMMMMM   '@@@@@@@@@@@@@...@@'..@@@@@@@@@@@@'  AMMMMMMMMMMMMMMMM\n");
    tell_object(tob, " MMMMMMMMMMMMMMMMA   '@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   .MMMMMMMMMMMMMMMMM\n");
    tell_object(tob, " MMMMMMMMMMMMMMMMMA    @@@@@@@@@@@@\"'O'OOOO'@@@@@@@'   .MMMMMMMMMMMMMMMMMM\n");
    tell_object(tob, " MMMMMMMMMMMMMMMMMMA    '@@@@@@@VOOOOOOO.OOO @@@V     AMMMMMMMMMMMMMMMMMMM\n");
    tell_object(tob, " MMMMMMMMMMMMMMMMMMMMA     '@@@@OOOOOOOOO.OOO@'     .MMMMMMMMMMMMMMMMMMMMM\n");
    tell_object(tob, " MMMMMMMMMMMMMMMMMMMMMMA        '.@@.OOOOO.OO     .AMMMMMMMMMMMMMMMMMMMMMM\n");
    tell_object(tob, " MMMMMMMMMMMMMMMMMMMMMMMMA.          OOOOO OOOO .MMMMMMMMMMMMMMMMMMMMMMMMM\n");
    tell_object(tob, " MMMMMMMMMMMMMMMMMMMMMMMMMMMA..      OOOOOOOOOOOMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
    tell_object(tob, " MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMOOOOOOOOOO.MMMMMMMMMMMMMMMMMMMMMMMMMM\n");
    tell_object(tob, " MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM OOOOOOO.MMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
    tell_object(tob, " MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM---MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
    tell_object(tob, " MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
    tell_object(tob, " MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
  }
  else if(sscanf(str,"dont pan %s", name) == 1) {
    tob = find_ob(name);
    if(!tob) { Fail(name); return 1; }    
    tell_object(tob, Fname+" tells you:\n\n");
    tell_object(tob, "                DDDDDD   OOOOO  N     N     ''  TTTTTTT \n");
    tell_object(tob, "                 D    D O     O N     N     ''     T    \n");
    tell_object(tob, "                 D    D O     O NN    N     '      T    \n");
    tell_object(tob, "                 D    D O     O N N   N    '       T    \n");
    tell_object(tob, "                 D    D O     O N  N  N            T    \n");
    tell_object(tob, "                 D    D O     O N   N N            T    \n");
    tell_object(tob, "                 D    D O     O N    NN            T    \n");
    tell_object(tob, "                 D    D O     O N     N            T    \n");
    tell_object(tob, "                DDDDDD   OOOOO  N     N            T    \n");
    tell_object(tob, "\n");
    tell_object(tob, "                PPPPPP     A    N     N  IIIII   CCCCC  \n");
    tell_object(tob, "                 P    P   A A   N     N    I    C     C \n");
    tell_object(tob, "                 P    P  A   A  NN    N    I    C       \n");
    tell_object(tob, "                 P    P A     A N N   N    I    C       \n");
    tell_object(tob, "                 PPPPP  AAAAAAA N  N  N    I    C       \n");
    tell_object(tob, "                 P      A     A N   N N    I    C       \n");
    tell_object(tob, "                 P      A     A N    NN    I    C       \n");
    tell_object(tob, "                 P      A     A N     N    I    C     C \n");
    tell_object(tob, "                 P      A     A N     N  IIIII   CCCCC  \n");
  }
  else if(sscanf(str,"hi %s", name) == 1) {
    tob = find_ob(name);
    if(!tob) { Fail(name); return 1; }
    tell_object(tob,Fname+" tells you:\n\n");
    tell_object(tob, "          ******      *****     ***************\n");
    tell_object(tob, "         *    **     *   **    *             **\n");
    tell_object(tob, "        *    * *    *   * *   *             * *\n");
    tell_object(tob, "       *    *  *   *   *  *  *             *  *\n");
    tell_object(tob, "      ******   *  ******  * ***************  *\n");
    tell_object(tob, "      ******   *  ******  * *************** *\n");
    tell_object(tob, "      ******   *  ******  * ****************\n");
    tell_object(tob, "      ******   *  ******  *    ********  *\n");
    tell_object(tob, "      ******************  *    ********  *\n");
    tell_object(tob, "      ******************  *    ********  *\n");
    tell_object(tob, "      ******************  *    ********  *\n");
    tell_object(tob, "      ******   * *******  *    ********  ****\n");
    tell_object(tob, "      ******  *  *******  *    ******** *   *\n");
    tell_object(tob, "      ****** *   ******* *  ************** *\n");
    tell_object(tob, "      *******    ********   ***************\n");
    tell_object(tob, "      ******     *******    **************\n");
  }
  else if(sscanf(str,"relax %s", name) == 1) {
    tob = find_ob(name);
    if(!tob) { Fail(str); return 1; }
    tell_object(tob, Fname+" tells you:\n\n");
    tell_object(tob, "      *******  ****** **       **    **    **\n");
    tell_object(tob, "      ******** ****** **      ****   **    **\n");
    tell_object(tob, "      **    ** **     **     **  **   **  **\n");
    tell_object(tob, "      **    ** **     **    **    **   ****\n");
    tell_object(tob, "      ******** *****  **    **    **    **\n");
    tell_object(tob, "      *******  *****  **    ********    **\n");
    tell_object(tob, "      **  **   **     **    ********   ****\n");
    tell_object(tob, "      **  **   **     **    **    **  **  **\n");
    tell_object(tob, "      **   **  ****** ***** **    ** **    **\n");
    tell_object(tob, "      **    ** ****** ***** **    ** **    **\n");
  }
  else if(str == "faint") say(Fname+" faints from confusion.\n");
  else if(str == "fart") say(Fname+" farts in your general direction.\n");
  else if(higher_wiz && str == "d") say("\nYou die.\nYou have a strange feeling.\nYou can see your own dead body from above.\n\n");
    else if(higher_wiz && str == "a") {
      int n;
      n = random(7);
      if(n == 0)
	say("The invisible stalker tickled you in the stomach.\n");
      if(n == 1)
	say("The invisible stalker grazed you.\n");
      if(n ==2)
	say("The invisible stalker hit you.\n");
      if(n == 3)
	say("The invisible stalker hit you hard.\n");
      if(n == 4)
	say("The invisible stalker hit you very hard.\n");
      if(n == 5)
	say("The invisible stalker smash you with a bone crushing sound\n");
      if(n == 6)
	say("The invisible stalker missed you.\n");
    }
    else if(higher_wiz && str == "w") say("You drop your wielded weapon.\n");
  else if(str == "chair") {
    say(Fname+" magically creates a rocking chair and sits down.\n");
    write("You create a chair and sit down.\n");
  }
  else if(sscanf(str, "mount %s", name) == 1) {
    say(Fname+" magically creates a whip, mounts " + capitalize(name) +  " and rides into the sunset.\n");
    write("You mount " + capitalize(name) + "\n");
  }
  else if(higher_wiz && sscanf(str,"zap %s", name) == 1) {
    tob = find_ob(name);
    if(!tob) { Fail(name); return 1; }
    tell_object(tob, Fname+" summons a flash from the sky.\n\n" +     
                     "You die.\n" +
                     "You have a strange feeling.\n" +
                     "You can see your own dead body from above.\n\n");
    write("You 'zap' " + capitalize(name) + "\n");
  }
  else { tease(); return 1; }
  Ok();
  return 1;
}
force_load() { return 1; }

