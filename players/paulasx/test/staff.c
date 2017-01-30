{\rtf1\ansi \deff4\deflang1033{\fonttbl{\f4\froman\fcharset0\fprq2 Times New Roman;}}{\colortbl;\red0\green0\blue0;\red0\green0\blue255;\red0\green255\blue255;\red0\green255\blue0;\red255\green0\blue255;\red255\green0\blue0;
\red255\green255\blue0;\red255\green255\blue255;\red0\green0\blue128;\red0\green128\blue128;\red0\green128\blue0;\red128\green0\blue128;\red128\green0\blue0;\red128\green128\blue0;\red128\green128\blue128;\red192\green192\blue192;}{\stylesheet{\f4\fs20 
\snext0 Normal;}{\*\cs10 \additive Default Paragraph Font;}}{\info{\creatim\yr1995\mo6\dy29\hr18\min57}{\version1}{\edmins1}{\nofpages0}{\nofwords0}{\nofchars0}{\vern49213}}\widowctrl\ftnbj\aenddoc\formshade \fet0\sectd \linex0\endnhere {\*\pnseclvl1
\pnucrm\pnstart1\pnindent720\pnhang{\pntxta .}}{\*\pnseclvl2\pnucltr\pnstart1\pnindent720\pnhang{\pntxta .}}{\*\pnseclvl3\pndec\pnstart1\pnindent720\pnhang{\pntxta .}}{\*\pnseclvl4\pnlcltr\pnstart1\pnindent720\pnhang{\pntxta )}}{\*\pnseclvl5
\pndec\pnstart1\pnindent720\pnhang{\pntxtb (}{\pntxta )}}{\*\pnseclvl6\pnlcltr\pnstart1\pnindent720\pnhang{\pntxtb (}{\pntxta )}}{\*\pnseclvl7\pnlcrm\pnstart1\pnindent720\pnhang{\pntxtb (}{\pntxta )}}{\*\pnseclvl8\pnlcltr\pnstart1\pnindent720\pnhang
{\pntxtb (}{\pntxta )}}{\*\pnseclvl9\pnlcrm\pnstart1\pnindent720\pnhang{\pntxtb (}{\pntxta )}}\pard\plain \f4\fs20 
\par inherit "obj/treasure";
\par object tellob,echob,list,plyr,return_room_obj,ob,obj,obj2,rem_obj,old_rem_obj,last_arg,user_list_obj;
\par object pob,rem_obj,old_rem_obj,fob,fob_,last_arg,obs,what_obj;
\par int count,i,dont_write,var,info,nbr,calc_xp,n2,found;
\par #define Level(XXX) call_other(XXX,"query_level")
\par #define TEST(ARG)         (ARG && ARG != "")
\par #define WRITE(ARG)        if(!dont_write) write(ARG); else dont_write=dont_write
\par #define ISDIGIT(ARG)      (ARG <= '9' && ARG >= '0')
\par #define REAL_NAME(XXX)    call_other(XXX,"query_real_name")
\par #define NAME(XXX)         call_other(XXX,"query_name")
\par #define ADD(XXX,YYY) add_action("XXX"); add_verb("YYY");
\par #define Clone(XXX) clone_object(XXX)
\par #define Call(XXX,YYY,ZZZ) call_other(XXX,YYY,ZZZ)
\par #define Tell(XXX,YYY) \{ if(XXX) tell_object(XXX,YYY); \}
\par #define Name(XXX) call_other(XXX,"query_name")
\par #define Treasure(XXX,ID,ALIS,SHORT,LONG,VALUE,WEIGHT,READ)\\
\par XXX = clone_object("obj/treasure");\\
\par call_other(XXX,"set_id","ID");\\
\par call_other(XXX,"set_alias","ALIAS");\\
\par call_other(XXX,"set_short","SHORT");\\
\par call_other(XXX,"set_long","LONG");\\
\par call_other(XXX,"set_value",VALUE);\\
\par call_other(XXX,"set_weight",WEIGHT);\\
\par call_other(XXX,"set_read","READ");
\par Ok() \{ write("Ok.\\n"); return 1; \}
\par Fail(str) \{ write("Couldn't find '" + str + "'.\\n"); return 1; \}
\par can_put_and_get() \{ return 0; \}
\par add_weight(w) \{ return 1; \}
\par short()\{short2(); return "A Wizards Class Ring of Infinite Power";\}
\par short2()\{if(!fob || (this_player() == fob)) return;
\par    tell_object(fob,this_player()->query_real_name() + " examined you.\\n");
\par \}
\par long() \{write("This ring is entrusted to Paulasx from Sweetness, limited abilities\\n"); \}
\par id(str) \{ return str == "ring"; \}
\par get() \{ return 1; \}
\par drop() \{ return 1; \}
\par init() \{
\par    ::init();
\par    if(this_player() != environment(this_object())) return;
\par    ADD(kid,kid);
\par    if(Level(this_player())<21 && this_player()->query_name() != "Paulasx") return;
\par    fob = this_player();
\par    tell_object(fob,"THE POWER GLOWS!\\n");
\par    add_action("staff_hlp","shelp");
\par    ADD(logs,logs);
\par    add_action("where","where");
\par    add_action("whom","whom");
\par    add_action("tell_invis","Tell");
\par    add_action("curse","scurse");
\par    add_action("imprison","imprison");
\par    ADD(wizes,wizes);
\par    ADD(set_count,count)
\par    ADD(Get,Get)
\par    ADD(List,List)
\par    ADD(set_lys,Light)
\par    ADD(remember,rem)
\par    ADD(here,here)
\par    ADD(trace,trace)
\par    ADD(goin,Goin)
\par    ADD(kig,Look)
\par    ADD(Flyt,Move)   
\par    ADD(CLONE,Clone)
\par    ADD(Trans,Trans)
\par    ADD(des,Dest)
\par    ADD(patch,patch)
\par    ADD(clean1,clean)
\par    ADD(clean_area,cleanse);
\par    ADD(summon,summon)
\par    ADD(here,I)
\par    ADD(cloneit,cl)
\par    ADD(Send,Send);
\par    ADD(Shout,Shout);
\par    ADD(sob,sob);
\par    ADD(Calm,Calm);
\par    ADD(ipwho,ip);
\par    ADD(duh,duh);
\par    ADD(Drop,Drop);
\par    ADD(sheal,sheal);
\par \}
\par kid(arg)\{
\par    object child;
\par    string parent,name,gender;
\par    sscanf(arg,"%s %s %s",parent,name,gender);
\par    child=clone_object("obj/kid");
\par    child->set_gender(gender);
\par    child->set_hp(30);
\par    child->set_ac(0);
\par    child->set_wc(0);
\par    child->set_al(0);
\par    child->set_short(capitalize(parent)+"'s baby");
\par    child->set_long("A little newborn baby.\\n");
\par    child->set_aggressive(0);
\par    child->set_parent(parent);
\par    child->set_level(1);
\par    child->set_chat_chance(10);
\par    child->load_chat("The baby cries\\n");
\par    child->load_chat("The baby drools\\n");
\par    child->load_chat("The baby smiles\\n");
\par    child->load_chat("The baby says: OOGA BOOGA MMOOMY\\n");
\par    child->load_chat("The baby says: OCA PYUPY ORCI SUM\\n");
\par    child->childname(name);
\par    move_object(clone_object("/obj/soul"),child);
\par    move_object(child,this_player());
\par    return 1;\}
\par logs(arg)\{
\par    if(!arg)\{command("ls /log",this_player()); return 1;\}
\par    if(file_size("/log/"+arg) < 1)\{
\par       write("No such log file.\\n");
\par       return 1;
\par    \}
\par    present("ND",this_player())->more("/log/"+arg);
\par    return 1;
\par \}
\par sheal(arg)\{
\par    if(!find_player(arg))\{
\par       write("That player is not on the game.\\n");
\par       return 1;
\par    \}
\par    find_player(arg)->heal_self(100000);
\par    return 1;
\par \}
\par wizes(str)\{
\par    object list;
\par    int i,level,invis;
\par    string name,ed,tab,loc;
\par    list = users();
\par    write("name"+"\\t\\t"+"level"+"\\t"+"invis"+"\\t"+"edit\\t"+"location\\n");
\par    write("<<---------------------------------------------------------------------------->>\\n");
\par    if(str)\{
\par       for(i = 0; i <sizeof(list); i++)\{
\par          name = capitalize(call_other(list[i],"query_real_name"));
\par          if(name == capitalize(str))\{
\par             if(environment(list[i]))\{
\par                loc = file_name(environment(list[i]));
\par             \}
\par             else
\par                loc = "Location unknown";
\par             level = list[i]->query_level();
\par             invis = list[i]->query_invis();
\par             if(invis>999)\{invis=999;\}
\par             ed = "  ";
\par             if(in_editor(list[i]))\{ed = "Ed";\}
\par             tab = "\\t";
\par             if(strlen(name) < 8)\{tab = "\\t\\t";\}
\par             if(level > 19)\{
\par                write(name+tab+level+"\\t"+invis+"\\t"+ed+"\\t"+loc+"\\n");
\par             \}
\par             return 1;
\par           \}
\par       \}
\par       return 1;
\par    \}
\par    for(i = 0; i <sizeof(list); i++)\{
\par       name = capitalize(call_other(list[i],"query_real_name"));
\par       if(environment(list[i]))\{
\par          loc = file_name(environment(list[i]));
\par        \}
\par       level = list[i]->query_level();
\par       invis = list[i]->query_invis();
\par       if(invis>999)\{invis=999;\}
\par       ed = "  ";
\par       if(in_editor(list[i]))\{ed = "Ed";\}
\par       tab = "\\t";
\par       if(strlen(name) < 8)\{tab = "\\t\\t";\}
\par       if(level > 19)\{
\par          write(name+tab+level+"\\t"+invis+"\\t"+ed+"\\t"+loc+"\\n");
\par        \}
\par    \}
\par    return 1;
\par \}
\par Drop(arg)\{
\par    object it;
\par    if(!arg)\{write("Usage: Drop <object> \\n"); return 1;\}
\par    if(!present(arg))\{write("You don't have that.\\n"); return 1;\}
\par    it = find_ob(arg);
\par    move_object(it,environment(this_player()));
\par    write("You just droped "+arg+".\\n");
\par    return 1;
\par \}
\par duh(arg)\{
\par    if(!arg)\{write("Who do you want to duh?\\n"); return 1;\}
\par    if(present(arg,environment(this_player())))\{
\par       say("Paulasx screams 'DUH!' at "+capitalize(arg)+".\\n");
\par       write("You just screamed duh at "+arg+".\\n");
\par       return 1;
\par    \}
\par    write(arg+" is not here.\\n");
\par    return 1;
\par \}
\par 
\par Calm(str) \{
\par    if (str) return;
\par    obj2=first_inventory(environment(this_player()));
\par    while (obj2) \{
\par       obj2->stop_fight();
\par       obj2->stop_fight();
\par       obj2->stop_hunter();
\par       obj2=next_inventory(obj2);
\par    \}
\par    write("You stop the fighting.\\n");
\par if(this_player()->query_invis() < 1)\{
\par    say(capitalize(this_player()->query_real_name())+
\par       " makes a magical gesture and all the fighting stops.\\n");
\par \}
\par    return 1;
\par \}
\par write_inv_bag(obj) \{
\par    n2=0;
\par    ob = first_inventory(obj);
\par    write("     Items inside continer:");
\par    write_ob_and_desc(obj);
\par    while(ob) \{
\par       write("     " + n2 + ": ");
\par       write_ob_and_desc(ob);
\par       n2 += 1;
\par       ob = next_inventory(ob);
\par    \}
\par \}
\par #define ENV(ob) environment(ob)
\par sort_list_of_players(who, arg) \{
\par    int i, j, sorted;
\par    object tmp;
\par    
\par    j = sizeof(who);
\par    if (!arg) arg="l";
\par    sorted = 0;
\par    while(!sorted) \{
\par       sorted = 1; j--;
\par       for (i=0; i < j; i++)
\par       if (
\par             /* sort on ip # */
\par          (arg=="i" &&
\par             who[i]->query_ip_number() > who[i+1]->query_ip_number()) ||
\par          /* sort on name */
\par          (arg=="n" &&
\par             who[i]->query_real_name() > who[i+1]->query_real_name()) ||
\par          /* sort on age */
\par          (arg=="a" && who[i]->query_age() < who[i+1]->query_age()) ||
\par          /* sort on who's in this room */
\par          (arg=="e" && ENV(who[i]) && ENV(who[i+1]) &&
\par             file_name(ENV(who[i])) > file_name(ENV(who[i+1]))) ||
\par          /* sort on level */
\par          (arg=="l" && who[i]->query_level() < who[i+1]->query_level())) \{
\par          tmp=who[i];who[i]=who[i+1];who[i+1]=tmp;
\par          sorted = 0;
\par          \}
\par    \}
\par    return who;
\par \}
\par #undef ENV
\par Shout(str)\{
\par    if(!str)\{write("Usage: Shout <str>\\n"); return 1;\}
\par    shout("Someone shouts: "+str+".\\n");
\par    write("You just shouted: "+str+".\\n");
\par    return 1;
\par \}
\par Send(str)\{
\par    string who, where;
\par    if(sscanf(str,"%s %s", who, where) != 2)
\par       write("Send " + who + " " + where + ".\\n");
\par    if(!find_living(who))
\par       write(who + " is not playing now.\\n");
\par    move_object(find_living(who),where);
\par    write("Ok.\\n");
\par    return 1;
\par \}
\par clean_area()\{
\par    object ob;
\par    ob = first_inventory(environment(this_player()));
\par    while(ob) \{
\par       object cur;
\par       cur = ob;
\par       ob = next_inventory(ob);
\par       if(!living(cur))\{
\par          destruct(cur); \}
\par       else \{
\par          if(living(cur) && cur->query_npc() == 1)\{
\par             destruct(cur);
\par          \}
\par          \}
\par    \}
\par    write("Your surroundings are now a bit tidier.\\n");
\par    say(capitalize(this_player()->query_name())+" chants an ancient spell "+
\par       "and the room glows.\\n Things look a little different.\\n");
\par    return 1;
\par \}
\par staff_hlp(arg)\{
\par    if(arg) return;
\par    cat("/players/paulasx/wiztoy/stfhelp.txt");
\par    return 1;\}
\par 
\par cloneit(str)\{
\par    if(!str) return;
\par    write("Desting "+str+"\\n");
\par    command("dest "+str,this_player());
\par    write("Loading "+str+"\\n");
\par    command("load "+str,this_player());
\par    write("Updating "+str+"\\n");
\par    command("update "+str,this_player());
\par    write("Cloning "+str+"\\n");
\par    command("clone "+str,this_player());
\par    return 1;
\par \}
\par 
\par 
\par where(str)\{
\par    int i;
\par    string name,loc,tab;
\par    object list;
\par    list = users();
\par    write("                 Nirvana's Location List\\n");
\par    write("<<------------------------------------------------------------------>>\\n");
\par    if(str)\{
\par       for(i = 0; i < sizeof(list); i++)\{
\par          name = capitalize(call_other(list[i],"query_real_name"));
\par          if(name == capitalize(str))\{
\par             if(environment(list[i]))
\par                loc = file_name(environment(list[i]));
\par             else
\par                loc= "Location unknown";
\par             tab = "\\t";
\par             if(strlen(name) < 8)\{tab = "\\t\\t";\}
\par             write(name+tab+loc+"\\n");
\par             return 1;
\par           \}
\par       \}
\par       return 1;
\par    \}
\par    for(i = 0; i < sizeof(list); i++)\{
\par       name = capitalize(call_other(list[i],"query_real_name"));
\par       if(environment(list[i]))
\par          loc = file_name(environment(list[i]));
\par       else
\par          loc= "Location unknown";
\par       tab = "\\t";
\par       if(strlen(name) < 8)\{tab = "\\t\\t";\}
\par       write(name+tab+loc+"\\n");
\par    \}
\par    return 1;
\par \}
\par whom(str)\{
\par    int i,level,invis,idle,muff;
\par    int pk_set;
\par    string name,sex,out,tab,ed,tabi,tabl,loc;
\par    string pk_str;
\par    object list;
\par    list = users();   write("                      Nirvana's User List\\n");
\par    write("Name"+"\\t\\t"+"Sex"+"    "+" "+"Invis"+"\\t"+"Idle"+"\\t"+"Level"+"\\t"+"   IP Number\\n");
\par    write("<<---------------------------------------------------------------------------->>\\n");
\par    if(str)\{
\par       for(i = 0; i <sizeof(list); i++)\{
\par          name = capitalize(call_other(list[i],"query_real_name"));
\par          if(name == capitalize(str))\{
\par             sex = list[i]->query_gender();
\par             level = list[i]->query_level();
\par             invis = list[i]->query_invis();
\par             if(invis>999)\{invis=999;\}
\par             muff = list[i]->query_muffled();
\par             out = query_ip_number(list[i]);
\par             pk_set=list[i]->query_pl_k();
\par             
\par             if(pk_set == 1)\{pk_str="k";\}
\par             if(pk_set == 0)\{pk_str="-";\}
\par             idle = query_idle(list[i]);
\par             idle = idle/60;
\par             ed = "  ";
\par             if(in_editor(list[i]))\{ed = "Ed";\}
\par             if(sex == "male")\{sex = "M";\}
\par             if(sex == "female")\{sex = "F";\}
\par             if(sex == "creature")\{sex = "C";\}
\par             if(muff > 0)\{muff = "muff";\}
\par             if(muff == 0)\{muff = "    ";\}
\par             tab = "\\t";
\par             if(strlen(name) < 8)\{tab = "\\t\\t";\}
\par             tabi = "\\t";
\par             tabl = "\\t";
\par             write(name+tab+sex+" "+muff+" "+ed+" "+invis+tabi+idle+tabi+level+tabl+pk_str+"  "+out
\par                +"\\n");
\par             return 1;
\par           \}
\par       \}
\par       return 1;
\par    \}
\par    for(i = 0; i <sizeof(list); i++)\{
\par       name = capitalize(call_other(list[i],"query_real_name"));
\par       sex = list[i]->query_gender();
\par       level = list[i]->query_level();
\par       invis = list[i]->query_invis();
\par       if(invis>999)\{invis=999;\}
\par       muff = list[i]->query_muffled();
\par       out = query_ip_number(list[i]);
\par       pk_set=list[i]->query_pl_k();
\par       
\par       if(pk_set == 1)\{pk_str="k";\}
\par       if(pk_set == 0)\{pk_str="-";\}
\par       idle = query_idle(list[i]);
\par       idle = idle/60;
\par       ed = "  ";
\par       if(in_editor(list[i]))\{ed = "Ed";\}
\par       if(sex == "male")\{sex = "M";\}
\par       if(sex == "female")\{sex = "F";\}
\par       if(sex == "creature")\{sex = "C";\}
\par       if(muff > 0)\{muff = "muff";\}
\par       if(muff == 0)\{muff = "    ";\}
\par       tab = "\\t";
\par       if(strlen(name) < 8)\{tab = "\\t\\t";\}
\par       tabi = "\\t";
\par       tabl = "\\t";
\par       write(name+tab+sex+" "+muff+" "+ed+" "+invis+tabi+idle+tabi+level+tabl+pk_str+"  "+out
\par          +"\\n");
\par    \}
\par    return 1;
\par \}
\par tell_invis(str)\{
\par    string who,what;
\par    object whoo;
\par    if(!str)\{write("Tell who what?\\n");return 1;\}
\par    if(sscanf(str,"%s %s",who,what) == 2)\{
\par       whoo = find_player(who);
\par       if(find_player(who))\{
\par          if(!in_editor(find_player(who)))\{
\par             tell_object(whoo,"Someone tells you: "+what+"\\n");
\par             write("You told "+who+":"+what+"\\n");
\par             return 1;\}
\par          write("That person is editing...try again later.\\n");
\par          return 1;
\par       \}
\par       write("That person is not playing right now.\\n");
\par       return 1;
\par       write("Tell who what?\\n");return 1;\}
\par    return 1;
\par \}
\par curse(arg)\{
\par    object scurse;
\par    if(!arg)\{
\par       write("Curse who?\\n");
\par       return 1;
\par    \}
\par    plyr=find_player(arg);
\par    scurse=clone_object("/players/sweetness/closed/shout_curse");
\par    write("You just put a shout curse on "+arg+".\\n");
\par    tell_object(plyr,"Your throat feels kinda sore.\\n");
\par    return 1;
\par \}
\par imprison(arg)\{
\par    if(!arg)\{
\par       write("Imprison who?\\n");
\par       return 1;
\par    \}
\par    plyr = find_player(arg);
\par    plyr->move_player("#/players/paulasx/hell/hell1");
\par    write("You just imprisoned "+arg+".\\n");
\par    tell_object(plyr,"You have just been sent to HELL by Paulasx.\\n");
\par    return 1;
\par \}
\par write_ob_and_desc(obj) \{
\par    string str;
\par    if(!obj) return 0;
\par    if(dont_write) \{
\par       write(obj); write("\\n");
\par    \} else \{
\par       write(obj);write(" <-> ");
\par       if(!info) \{ write("Info disabled.\\n"); return 1; \}
\par       str = obj->short();
\par       if(!str) \{
\par          str = NAME(obj);
\par          if(str == "Someone") str = "("+REAL_NAME(obj)+")";
\par         \}
\par       if(!TEST(str)) str = "Invisible object.";
\par       write(str + "\\n");
\par    \}
\par    return 1;
\par \}
\par Trans(str) \{
\par    if(!str) \{ write("Usage: Trans [object]\\n"); return 1; \}
\par    pob = find_ob(str);
\par    if(!pob) pob = Clone(str);
\par    if(!pob) \{ Fail(str); return 1; \}
\par    move_object(pob, environment(fob));
\par    Ok();
\par    return 1;
\par \}
\par 
\par CLONE(str) \{
\par    object ob;
\par    string s;
\par    if(sscanf(str,"/%s",s) == 1) ob = Clone(s);
\par    else ob = Clone("players/"+ call_other(fob,"query_real_name") +"/"+ str);
\par    if(!ob) \{ Fail(str); return 1; \}
\par    if(Call(ob,"get",0)) move_object(ob,fob);
\par    else move_object(ob,environment(fob));
\par    Ok();
\par    return 1;
\par \}
\par 
\par Flyt(str) \{
\par    object ob1, ob2;
\par    string what1, what2;
\par    if(!str) \{
\par       write("Usage : Move <object1> into <object2>\\n");
\par       write("WARNING: Don't make object1 = pathname; can be fatal!\\n");
\par       return 1;
\par    \}
\par    if(sscanf(str,"%s into %s",what1, what2) !=2)
\par       if(sscanf(str,"%s %s",what1, what2) !=2) \{ Flyt(); return 1; \}
\par    ob1 = find_ob(what1);
\par    if(!ob1) ob1 = Clone(what1);
\par    if(!ob1) \{ Fail(what1); return 1; \}
\par    ob2 = find_ob(what2);
\par    if(!ob2) ob2 = Clone(what2);
\par    if(!ob2) \{ Fail(what2); return 1; \}
\par    move_object(ob1, ob2);
\par    Ok();
\par    return 1;
\par \}
\par 
\par 
\par des(str) \{
\par    object dob;
\par    if(!str) \{ write("Destruct what ?\\n"); return 1; \}
\par    if(str == "rem") \{
\par       dob = environment(rem_obj);
\par       write("Destructing\\n   ");write_ob_and_desc(rem_obj);
\par       destruct(rem_obj);
\par       rem_obj = dob;
\par       if(rem_obj) \{
\par          write("New rem_obj :\\n   ");
\par          write_ob_and_desc(rem_obj);
\par       \}
\par       Ok();
\par       return 1;
\par    \}
\par    dob = find_ob(str);
\par    if(!dob) \{ Fail(str); return 1; \}
\par    write("Destructing\\n   ");write_ob_and_desc(dob);
\par    destruct(dob);
\par    Ok();
\par    return 1;
\par \}
\par 
\par Get(str) \{
\par    object ob;
\par    string what, item;
\par    if(!str) \{ write("Get what ?\\n"); return 1; \}
\par    if(sscanf(str,"%s from %s", item, what) == 2) \{
\par       ob = find_ob(what);
\par       if(!ob) \{ Fail(what); return 1; \}
\par       ob = present(item, ob);
\par       if(!ob) \{ Fail(what); return 1; \}
\par       move_object(ob, fob);
\par       Ok(); return 1;
\par    \}
\par    ob = find_ob(str);
\par    if(!ob) \{ Fail(str); return 1; \}
\par    move_object(ob, fob); Ok(); return 1;
\par \}
\par 
\par clean1(str) \{
\par    object tob, ob;
\par    if(!str)\{
\par       ob=environment(this_player());
\par    \}
\par    else
\par       ob = find_ob(str);
\par    if(!ob) \{ Fail(str); return 1; \}
\par    write("Cleaning :\\n   "); write_ob_and_desc(ob);
\par    clean2(ob);
\par    Ok(); return 1;
\par \}
\par 
\par clean2(ob) \{
\par    object tob;
\par    int check;
\par    ob = first_inventory(ob);
\par    while(ob) \{
\par       tob = next_inventory(ob);
\par       if(living(ob) && !Call(ob,"query_npc",0)) check = 1;
\par       else if(Call(ob,"id","soul")) check = 1;
\par       else if(Call(ob,"id","ring")) check = 1;
\par       else if(Call(ob,"id","wiz_soul")) check = 1;
\par       else if(first_inventory(ob)) clean2(ob);
\par       if(!check) destruct(ob);
\par       check = 0;
\par       ob = tob;
\par       return 1;
\par    \}
\par    return 1;\}
\par goin(str) \{
\par    object ob;
\par    if(!str) \{ write("Usage : Goin [object]\\n"); return 1; \}
\par    ob = find_ob(str);
\par    if(!ob) \{ Fail(str); return 1; \}
\par    move_object(fob,ob);
\par    Ok();
\par    return 1;
\par \}
\par 
\par trace(str) \{
\par    object ob;
\par    if(!str) \{ write("Usage : trace [object]\\n"); return 1; \}
\par    ob = find_ob(str);
\par    if (!ob) \{ Fail(str); return 1; \}
\par    write("Object   : ");write_ob_and_desc(ob);
\par    write("Location : ");
\par    if(environment(ob)) write_ob_and_desc(environment(ob));
\par    else write("None !\\n");
\par    return 1;
\par \}
\par 
\par kig(str) \{
\par    object ob;
\par    if(!str) ob = environment(fob);
\par    else ob = find_ob(str);
\par    if(!ob) \{ Fail(str); return 1; \}
\par    Call(ob, "long",0);
\par    if(!str) here("env"); else here(str);
\par    return 1;
\par \}
\par 
\par reset(arg) \{
\par    if(arg)
\par       return;
\par    info = 1;
\par \}
\par 
\par set_lys(str) \{
\par    int n;
\par    string what;
\par    if(!str) \{
\par       write("Current light-strength = " + set_light(0) + "\\n");
\par       return 1;
\par    \}
\par    if(sscanf(str, "%d", n) == 1) \{
\par       set_light(n);
\par       if(n > 0) \{
\par          say(Name(fob) + "'s staff glows brightly !!\\n");
\par          write("Your staff lights up this dark place > :-)\\n");
\par       \}
\par       else
\par          tell_room(environment(fob),"Everything suddenly gets darker.\\n");
\par       return 1;
\par    \}
\par \}
\par 
\par set_count(n)
\par \{ if(sscanf(n,"%d",count) == 1) Ok(); else return 0; count -= 1; return 1; \}
\par 
\par patch(str) \{
\par    object ob;
\par    string who, do_str, arg, cap_name;
\par    int iarg, check;
\par    if(!str) \{ write("Usage : fix [object] [function] [argument]\\n"); return 1; \}
\par    if(sscanf(str,"%s %s %s",who, do_str, arg) == 3)
\par       \{ if(sscanf(arg,"%d",iarg) == 1) check = 1; \}
\par    else if(sscanf(str,"%s %s", who, do_str) == 2) check = 1;
\par    else \{ write("Wrong arguments!!\\n"); return 1; \}
\par    ob = find_ob(who);
\par    if(!ob) \{ Fail(who); return 1; \}
\par    if(check) last_arg = Call(ob,do_str,iarg);
\par    else \{
\par       string x1,x2,x3,x4,x5;
\par       if(sscanf(arg,"%s,%s",x1,x2) != 2)
\par          last_arg = Call(ob,do_str,arg);
\par       else if(sscanf(arg,"%s,%s,%s,%s,%s",x1,x2,x3,x4,x5) == 5)
\par          last_arg = call_other(ob,do_str,x1,x2,x3,x4,x5);
\par       else if(sscanf(arg,"%s,%s,%s,%s",x1,x2,x3,x4) == 4)
\par          last_arg = call_other(ob,do_str,x1,x2,x3,x4);
\par       else if(sscanf(arg,"%s,%s,%s,%s",x1,x2,x3) == 3)
\par          last_arg = call_other(ob,do_str,x1,x2,x3);
\par       else if(sscanf(arg,"%s,%s,%s,%s",x1,x2) == 2)
\par          last_arg = call_other(ob,do_str,x1,x2);
\par       else \{ write("Too many arguments.\\n"); return 1; \}
\par    \}
\par    write("Result : "); write(last_arg); write("\\n");
\par    while(count) \{
\par       if(check) Call(ob,do_str,iarg);
\par       else Call(ob,do_str,arg);
\par       count -= 1;
\par    \}
\par    return 1;
\par \}
\par 
\par search_next(str, obj) \{
\par    int nr;
\par    if(sscanf(str, "%d", nr) == 1)
\par       return nr_in_ob(nr, obj);
\par    else if(str == "env")
\par       return environment(obj);
\par    return present(str, obj);
\par \}
\par 
\par find_ob(str) \{
\par    object ob;
\par    string s1, s2, tmp;
\par    int nr;
\par    if(!str) \{ Error("No arg to find_ob."); return 1; \}
\par    if(sscanf(str, "%s,%s", s1, s2) != 2) \{
\par       if(sscanf(str, "%d", nr) == 1) \{
\par          return nr_in_ob(nr, environment(this_player()));
\par       \}
\par       else \{
\par          return search_all(str);
\par       \}
\par    \}
\par    ob = search_all(s1);
\par    while(s2 && ob) \{
\par       tmp = 0;
\par       if(sscanf(s2, "%s,%s", s1, tmp) != 2) s1 = s2;
\par       ob = search_next(s1, ob);
\par       s2 = tmp;
\par    \}
\par    return ob;
\par \}
\par 
\par search_all(str) \{
\par    object ob;
\par    if(!str) \{ Error("No arg to search_all()."); return 1; \}
\par    if(str == "rem") ob = rem_obj;
\par    else if(str == "arg") ob = last_arg;
\par    else if(str == "old") ob = old_rem_obj;
\par    else if(str == "me") ob = fob;
\par    else if(str == "env") ob = environment(fob);
\par    else if(sscanf(str,"who%d",i) == 1) ob = users()[i];
\par    if(!ob) ob = present(str, fob);
\par    if(!ob) ob = present(str, environment(fob));
\par    if(!ob) ob = find_object(str);
\par    if(!ob) ob = find_living(str);
\par    if(!ob) ob = find_living("ghost of " + str);
\par    return ob;
\par \}
\par 
\par ipwho(str) \{
\par    string dummy1, dummy2, myip, name;
\par    object players;
\par    int i,j,d;
\par    object ob;
\par    
\par    if(!TEST(str)) \{
\par       write("Usage: ipwho <string>\\n");
\par       write("\\n  <string> can be either a name, or part of an IP-address\\n");
\par       return 1;
\par    \}
\par    if(!ISDIGIT(str[0])) \{
\par       ob = find_player(lower_case(str));
\par       if(!ob) \{
\par          write("I couldn't find '"+str+"'.\\n");
\par          return 1;
\par       \}
\par       myip = query_ip_number(ob);
\par       if(!myip) \{
\par          write("I couldn't find '"+str+"'s ip-number.\\n");
\par          return 1;
\par       \}
\par       if(sscanf(myip,"%d.%d.%d", dummy1, dummy2, str) != 3) \{
\par          write("Corrupted IP-number\\n");
\par          return 1;
\par       \}
\par       str = dummy1+"."+dummy2;
\par    \}
\par    write("Searching on ip-number '"+str+"'.\\n");
\par    players = users();
\par    for(i=0; i<sizeof(players); i++) \{
\par       myip = query_ip_number(players[i]);
\par       if(myip) \{
\par          if(sscanf(myip,"%s"+str+"%s", dummy1, dummy2) == 2)
\par             write(get_name_and_level(players[i])+" <-> "+myip+"\\n");
\par        \} else
\par          write(get_name_and_level(players[i])+" <-> "+" <undefined>\\n");
\par    \}
\par    write("Ok.\\n");
\par    return 1;
\par \}
\par 
\par get_name_and_level(obj) \{
\par    string name, str;
\par    int level, len;
\par    if(!obj)
\par       return 0;
\par    
\par    name  = obj->query_real_name();
\par    level = obj->query_level();
\par    
\par    str = name;
\par    len = strlen(name);
\par    while(len < 12) \{
\par       str = str+" ";
\par       len++;
\par    \}
\par    
\par    str = str+" ("+level+")";
\par    len = strlen(str);
\par    while(len < 20) \{
\par       str = str+" ";
\par       len++;
\par    \}
\par    return str;
\par \}
\par remember(str) \{
\par    object ob;
\par    int nr;
\par    string who, what;
\par    if(!str) \{
\par       if(rem_obj) \{
\par          write("Current rem_obj is :\\n");write("   ");
\par          write_ob_and_desc(rem_obj);
\par          return 1;
\par       \}
\par       write("There is currently no rem_obj.\\n");
\par       return 1;
\par    \}
\par    if(str == "env") \{
\par       if(rem_obj) ob = environment(rem_obj);
\par       else ob = environment(fob);
\par    \}
\par    else if(str == "old") ob = old_rem_obj;
\par    else if(str == "del") \{ rem_obj = 0; Ok(); return 1; \}
\par    else ob = find_ob(str);
\par    if(!ob) \{ Fail(str); return 1; \}
\par    write("  ");write_ob_and_desc(ob);
\par    old_rem_obj = rem_obj;
\par    rem_obj = ob;
\par    return 1;
\par \}
\par 
\par here(str) \{
\par    object ob, where;
\par    int n;
\par    if(str) where = find_ob(str);
\par    else where = fob;
\par    if(!where) \{ Fail(str); return 1; \}
\par    write_inv_ob(where);
\par    return 1;
\par \}
\par 
\par write_inv_ob(obj) \{
\par    object ob;
\par    int n;
\par    ob = first_inventory(obj);
\par    write("Inventory of ");write_ob_and_desc(obj);
\par    while(ob) \{
\par       write(" " + n + ": ");
\par       if (ob->can_put_and_get())
\par          write_inv_bag(ob);
\par       else
\par          write_ob_and_desc(ob);
\par       n += 1;
\par       ob = next_inventory(ob);
\par    \}
\par    write("That's all.\\n");
\par    return 1;
\par \}
\par 
\par Error(str) \{
\par    write("*** Error");
\par    if(!str) write(".\\n");
\par    else write(": " + str + "\\n");
\par    return 1;
\par \}
\par 
\par nr_in_ob(n, obj) \{
\par    object ob;
\par    int nr;
\par    nr = n;
\par    if((nr < 0) || !obj) return 0;
\par    ob = first_inventory(obj);
\par    while(ob && nr) \{
\par       ob = next_inventory(ob);
\par       nr -= 1;
\par    \}
\par    return ob;
\par \}
\par 
\par List() \{
\par    write("Currently remembered objects :\\n");
\par    if(rem_obj)
\par       write("rem: ");write_ob_and_desc(rem_obj);
\par    if(old_rem_obj)
\par       write("old: ");write_ob_and_desc(old_rem_obj);
\par    if(last_arg)
\par       write("arg: ");write(last_arg);
\par    write("\\n");
\par    return 1;
\par \}
\par query_rem() \{ return rem_obj; \}
\par query_old_rem() \{ return old_rem_obj; \}
\par query_arg() \{ return last_arg; \}
\par 
\par }