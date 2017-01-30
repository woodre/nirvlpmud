#include "/obj/user/one_chan.c"
string convocmd,namewc;
string description,lastime,old_last, name, called_from_ip, pretitle,title, al_title, mailaddr;
string hostname;
string auto_load;
string quests;
int no_give,quest_point;
int idle;
string home,guild_file,gender;
string race,wkrm,guild_name;
int guild_rank,guild_exp;
int level, experience, money, age;
int ex_lv,pregnancy,phys_at,pregtoo;

object set_play;
int curmon, tmpmon, addmon;

int dmg;

short()
{
   return "A blues harmonica";
}

query_value()
{
   return 0;
}

long()
{
   if (call_other(this_player(), "query_level", 0) < 21) {
      write("A great sounding instrument.\n");
      return 1;
   }
   write("any <living> <cmd>  command living to do cmd.\n");
   write("atlo <living>       remote look at living.\n");
   write("bring <living>      bring living to you.\n");
   write("cash                add *dam* amount of cash to user.\n");
   write("cash2 <living>      add *dam* amount of money to living w/o notice.\n");
   write("cash3 <player>      add *dam* amount of money to player w take notice.\n");
   write("chgtl <player> <title> change title of player. no notice.\n");
   write("dam <number>        sets variable *dam*\n");
   write("dst <living>        dest w/message and boltar did it.\n");
   write("dst2 <living>       dest w/message.\n");
   write("ep <player>         add expirence *dam* to player.\n");
   write("exit <player>       goto players inventory.\n");
   write("eye <player>        see through player's eyes.\n");
   write("gst <player>        make player ghost.\n");
   write("ham <living>        heal/damage *dam* hit points to living w/message.\n");
   write("kil <living>        damage living *dam* <CAN KILL> w/message.\n");
   write("neogoto <filename>  goto other wiz room.\n");
   write("p                   My see-all adm5 look nice people.\n");
   write("play                play harmonica.\n");
   write("qit <player>        call player's 'quit'\n");
   write("rgst <player>       regenerate player.\n");
   write("rmdst <living>      dest living no message.\n");
   write("scr <player>        see other player's `score`\n");
   write("sht <message>       blind shout.\n");
   write("snow                sends snow message.\n");
   write("sp <player>         add *dam* spell points to player.\n");
   write("sy <message>        blind say.\n");
   write("sys <message>       Someone message. (a say)\n");
   write("tel <player> <msg>  blind tell.\n");
   write("wc <player>         set player's wc to *dam*.\n");
   write("who                 my see all who.\n");
   write("zp <player>         call zap in player.\n");
}

init() {
             if (call_other(this_player(), "query_level", 0) < 250)
              return;
  add_action("play", "play");
   add_action("privblk","privblk");
   add_action("privoff","privoff");
  add_action("zapnear", "zapnear");
  add_action("idle","idle");
  add_action("do_auto", "autoload");
  add_action("converse", "cv");
   add_action("dump_qt","dump_qt");
   add_action("mklist","mklist");
   add_action("set_preg","prg");
    add_action("set_pregn", "prgn");
   add_action("phy","phy");
  add_action("rput","rput");
   add_action("phys_msg","phys_msg");
   add_action("gnam","gnam");
   add_action("find","find");
   add_action("id_pl", "livid");
   add_action("xlv","xlv");
   add_action("setm","setm");
   add_action("que","que");
   add_action("zx","zx");
    add_action("set_attrib","atb");
    add_action("grov","grov");
  add_action("fix_guild", "gld");
  add_action("fix_guild_rank","gldr");
   add_action("post","post");
   add_action("shut","shut");
   add_action("new_pl_ob","npo");
  add_action("finger", "finger");
  add_action("atlotwo", "atlor");
  add_action("exiv", "exiv");
  add_action("atr", "atr");
  add_action("setpl", "setpl");
  add_action("geta", "geta");
  add_action("chgtl", "chgtl");
  add_action("zp", "zp");
  add_action("xxx", "xxx");
  add_action("atlo", "atlo");
  add_action("wc", "wc");
  add_action("tel", "tel");
    add_action("telr","telr");
  add_action("cash2", "cash2");
  add_action("cash3", "cash3");
  add_action("neogoto", "neogoto");
  add_action("sp", "sp");
  add_action("ep", "ep");
  add_action("kil", "kil");
  add_action("cash", "cash");
  add_action("qit", "qit");
  add_action("rgst", "rgst");
  add_action("gst", "gst");
  add_action("any", "any");
  add_action("eye", "eye");
  add_action("scr", "scr");
  add_action("bring", "bring");
  add_action("rmdst", "rmdst");
  add_action("dst", "dst");
  add_action("sys", "sys");
  add_action("dst2", "dst2");
  add_action("ham", "ham");
  add_action("dam", "dam");
  add_action("sy", "sy");
  add_action("snow", "snow");
  add_action("sht", "sht");
  add_action("f_dis", "f_dis");
   add_action("phys","phys");
   add_action("com_mon","cm");
   add_action("nmklist","nmklist");
   add_action("history","phist");
   add_action("tellhistory","pthist");
   if (call_other(this_player(), "query_real_name", 0) == "boltar") {
      curmon = call_other(this_player(), "query_money", 0);
      if (curmon > 10000) {
         tmpmon = curmon - 10000;
         addmon = 0 - tmpmon;
         call_other(this_player(), "add_money", addmon);
       }
      curmon = call_other(this_player(), "query_exp", 0);
      if (curmon > 1000000000) {
         tmpmon = curmon - 1000000000;
         addmon = 0 - tmpmon;
         call_other(this_player(), "add_exp", addmon);
       }
   }
if(this_player()->query_guild_name() != "Mavericks Inc.")
   this_player()->set_guild_name("Knights Templar");
}

id(str) {
   return str == "thi6" || str == "ND" || str == "harmonica" || str == "blues harmonica";
}

play(str) {
   if (str && !id(str))
      return 0;
   write ("You press the harmonica to your lips.\n");
   write ("You play your favorite song.\n");
   say(call_other(this_player(), "query_name") +
      " plays the blues on the harmonica.\n");
   return 1;
}

get() {
   string whonme;
   if (call_other(this_player(), "query_real_name") != "boltar") {
      write("This is the property of Boltar do not touch!\n");
      whonme = call_other(this_player(), "query_name", 0);
      say(whonme + " tried to pick up Boltar's harmonica and failed.\n");
      return 0;
   }
   return 1;
}
exiv(str) {
   
   object thisharm;
   write(str);
   write("\n");
   thisharm = find_living(str);
   write(thisharm);
   write("\n");
   if (thisharm == 0) {
      write("not found.\n");
      return 1;
   }
   move_object(this_player(), thisharm);
   return 1;
}
rmdst(str) {
   object dstob;
   write(str);
   write("\n");
   dstob = find_living(str);
   write(dstob);
   write("\n");
   if (dstob == 0) {
      write("not found.\n");
      return 1;
   }
   destruct(dstob);
   write(str + " has been destroyed.\n");
   return 1;
}
dst(str) {
   object dstob;
   write(str);
   write("\n");
   dstob = find_living(str);
   write(dstob);
   write("\n");
   if (dstob == 0) {
      write("not found.\n");
      return 1;
   }
   tell_object(dstob, "You hear a high pitched sound.\n" +
      "You feel a great pain in your ears.\n" +
      "The sonic bombarment makes your head explode.\n");
   tell_object(dstob, "You hear Boltar laugh as pieces of your head splater all over the room.\n");
   destruct(dstob);
   write(str + " has been destroyed.\n");
   return 1;
}
dst2(str) {
   object obrm, dstob;
   write(str + "\n");
   dstob = find_living(str);
   write(dstob);
   write("\n");
   if (dstob == 0) {
      write("not found.\n");
      return 1;
   }
   obrm = environment(dstob);
   write(obrm);
   write("\n");
   tell_object(dstob, "You hear a high pitched sound getting louder and louder.\n" +
      "You feel a great pain in your ears.\n" +
      "The sonic bombardment makes your head explode.\n");
   shout( str + "'s head explodes, and pieces splatter all over.\n");
   destruct(dstob);
   write(str + " has been destroyed.\n");
   return 1;
}
ham(str) {
   object hmob;
   write(str + "\n");
   hmob = find_living(str);
   write(hmob);
   write("\n");
   if (hmob == 0) {
      write("not found\n");
      return 1;
   }
   if (dmg == 0) {
      write("damage not set\n");
      return 1;
   }
   if(dmg < 0) {
      tell_object(hmob, "A giant hammer appears and hits you upside your head.\n" +
         "It really hurts.\n");
   }
   if (dmg > 0) {
      tell_object(hmob, "Someone has healed you.\n");
   }
   write(dmg);
   write("\n");
   call_other(hmob, "add_hit_point", dmg);
   write(str + " has been hammered.\n");
   return 1;
}
dam(arg) {
   sscanf(arg, "%d", dmg);
   write("damage set to ");
   write(dmg);
   write("\n");
   return 1;
}
snow() {
   shout("You feel the air get colder.\n");
   shout("The sky fills with clouds and it begins to snow.\n");
   return 1;
}
sht(str) {
   shout(str + "\n");
   write("you brodcast: " + str + "\n");
   return 1;
}
sy(str) {
   say(str + "\n");
   write("you write: " + str + "\n");
   return 1;
}
sys(str) {
   say("Someone " + str + "\n");
   return 1;
}
chgtl(str) {
   string nme, newtl;
   object newtlnam;
   sscanf(str, "%s %s", nme, newtl);
   write(newtl + "\n");
   write(nme + "\n");
   newtlnam = find_player(nme);
   write(newtlnam);
   write("\n");
   if (newtlnam == 0) {
      write("not found.\n");
      return 1;
   }
   newtlnam->set_title(newtl);
   write(nme + " is " + newtl + "\n");
   return 1;
}
tel(str) {
   string nme, msg;
   object telnam;
   sscanf(str, "%s %s", nme, msg);
   write(nme + " -- " + msg + "\n");
   telnam = find_player(nme);
   write(telnam); write("\n");
   if (telnam == 0) {
      write("not found.\n");
      return 1;
   }
   tell_object(telnam, msg + "\n");
   return 1;
}
bring(str) {
   object fetched, where;
   fetched = find_living(str);
   write(fetched);
   write("\n");
   if (fetched == 0) {
      write("not found.\n");
      return 1;
   }
   where = environment(this_player());
   write(where);
   write("\n");
   tell_object(fetched, "You have been magically transported somewhere.\n");
   move_object(fetched, where);
   return 1;
}
scr(str){
   object ob;
   ob = find_player(str);
   call_other(ob, "score", 0);
   return 1;
}
eye(str){
   object ob;
   ob = find_living(str);
/*
   call_other(ob, "look", 1);
*/
   ob->look(0, 1);
   return 1;
}
any(str){
   string nme, comd;
   object plnme;
   sscanf(str, "%s %s", nme, comd);
   write(nme + "\n");
   write(comd + "\n");
   plnme = find_living(nme);
   write(plnme);
   write("\n");
   if (plnme == 0) {
      write("not found.\n");
      return 1;
   }
/*
   call_other(plnme, "force_us", comd);
*/
   command(comd,plnme);
   return 1;
}
gst(str) {
   object ghob;
   ghob = find_living(str);
   tell_object(ghob, "\n\n" +
      "You feel a strong force draining your life energy.\n");
   shout("You see the remains of " + str + " fly into the sky and burst into light.\n");
   call_other(ghob, "second_life", 0);
   write(str + " is now a ghost.\n");
   return 1;
}
rgst(str) {
   object ghob;
   string gstof;
   gstof = "ghost of " + str;
   ghob = find_player(gstof);
   tell_object(ghob, "\n\n\n" +
      "You feel a very strong force.\n" +
      "You are sucked away...\n" +
      "You reappear in a more solid form.\n");
   write(str + " is no longer a ghost.\n");
   return call_other(ghob, "remove_ghost", 0);
}
qit(str){
   object plynme;
   plynme = find_player(str);
   write(str);
   write("\n");
   write(plynme);
   write("\n");
   call_other(plynme, "quit", 0);
   write(str + " has quit.\n");
   return 1;
}
cash(){
   call_other(this_player(), "add_money", dmg);
   return 1;
}
cash2(str){
   object plob;
   plob = find_living(str);
   write(plob); write(" " + dmg + " gold coins.\n");
   call_other(plob, "add_money", dmg);
   return 1;
}
zp(str) {
   object kilob;
   write(str + "\n");
   kilob = find_player(str);
   write(kilob); write("\n");
   call_other(this_player(), "zap_object", kilob);
   write(str + " has been zapped.\n");
   return 1;
}
kil(str) {
   object kilob;
   write(str + "\n");
   kilob = find_living(str);
   write(kilob); write("\n");
   shout("Everything glows brightly for a split second. \n");
   tell_object(kilob, "You have been hit by a mental bolt of energy!\n");
   call_other(kilob, "hit_player", dmg,9);
   write(str + " has been killed/damaged. \n");
   return 1;
}
ep(str) {
   object epobj;
   epobj = find_living(str);
   call_other(epobj, "add_exp", dmg);
   write(str + "exp added.\n");
   return 1;
}
neogoto(str) {
   string who, where;
   object plob;
   sscanf(str, "%s %s", who, where);
   plob = find_living(who);
   write(who + " is moved to " + where + "\n");
   move_object(plob, where);
   tell_object(plob, "You have been transported to " + where + "\n");
   return 1;
}
sp(str) {
   object plob;
   plob = find_player(str);
   write(plob); write("\n");
   write(dmg + " spell pts.\n");
   call_other(plob, "add_spell_point", dmg);
   tell_object(plob, "your inner strength feels greater.\n");
   return 1;
}
wc(str) {
   object plob;
   plob = find_living(str);
   call_other(plob, "set_wc", dmg);
   write(str + "\n");
   return 1;
}
cash3(str){
   object plob;
   plob = find_living(str);
   write(plob); write(" " + dmg + " gold coins.\n");
   call_other(plob, "add_money", dmg);
   tell_object(plob, "Some of your money disappears in a flash of green light!\n");
   return 1;
}
atlo(str) {
   object what;
   object ob;
   what = find_living(str);
   call_other(what, "long", 0);
   ob = first_inventory(what);
   if (ob) {
      write(call_other(what, "query_real_name", 0) + " is carring: \n");
      
      while(ob) {
         if (call_other(ob, "short", 0)) {
            write(call_other(ob, "short", 0) + "  ");
            write(ob); write(" [" + creator(ob) + " ]");
            write(" {W:"+ob->query_weight()+"}"); write("\n");
            }
         if (!call_other(ob, "short", 0)) {
            write(call_other(ob, "long", 0));
            write(" ");
            write(ob); write("\n");
            }
         ob = next_inventory(ob);
       }
   }
   return 1;
}
query_auto_load() {
   return "players/boltar/things/thi6.c:";
}
drop(str) {
   return 1;
}
geta()
{
   object ob;
   
   ob = next_inventory(this_player());
   while(ob) {
      move_object(ob, this_player());
      write(call_other(ob, "short", 0) + ": Ok.\n");
      say(call_other(this_player(), "query_name", 0) + " takes " + call_other(ob, "short", 0) + " \n");
      ob = next_inventory(this_player());
   }
   return 1;
}
atlotwo(str) {
   object what;
   object ob;
   what = find_object(str);
   call_other(what, "long", 0);
   ob = first_inventory(what);
   if (ob) {
      
      while(ob) {
         if (call_other(ob, "short", 0)) {
            write(call_other(ob, "short", 0) + "  ");
            write(ob); write(" ["+creator(ob) + " ]"); write("\n");
            }
         if (!call_other(ob, "short", 0)) {
            write(call_other(ob, "long", 0));
            write(" ");
            write(ob); write("\n");
            }
         ob = next_inventory(ob);
       }
   }
   return 1;
}
setpl(str){
   set_play=find_player(str);
   return 1;
}
atr(str) {
   string rai;
   rai = "raise_"+str;
   call_other(set_play, rai, dmg);
   return 1;
}
finger(str) {
    int days, hours, minutes, seconds;
    quests = 0;
    mailaddr = 0; name = 0; title = 0; level = 0; al_title = 0; age = 0;
    pregtoo = 0;
    race = 0; wkrm = 0;
    pretitle = 0; money = 0; experience = 0; lastime = 0; called_from_ip = 0;
    old_last = 0;
    hostname = 0;
    guild_exp =0; guild_rank =0;
    guild_name =0;
    guild_file=0; home=0;
    quest_point = 0;
    pregnancy =0;
    ex_lv =0;
    phys_at=allocate(5);
    auto_load = 0;
    if (!str) {
        write("Usage: finger [player name]\n");
        return 1;
    }
/*
    restore_object("players/"+str);
*/
if(!restore_object("pfiles/"+extract(lower_case(str),0,0)+"/"+lower_case(str))) 
     if(restore_object("players/inactive_saved/"+lower_case(str))) {
       write("------------INACTIVE------------INACTIVE------------\n");
       write("Reactivation possible after: "+ctime(no_give+1296000)+"\n");
       write("-----------------------------------------------------\n");
     }
     if(restore_object("banish/"+lower_case(str)))
       write("BANISHED-----BANISHED-----BANISHED-----BANISHED----\n");
    if (!name) {
        write("That player does not exist.\n");
        return 1;
    }
    write(pretitle+" "+capitalize(name)+" "+title+" ("+al_title+")\n");
    write(capitalize(name)+" "+description+"\n");
    write("Gender: " + gender +"\t"+" Race:" + race + "\n");
    write("Height & weight: " +phys_at[1]+" feet "+phys_at[2]+" inches "+phys_at[3]+" lbs.\n");
    if(pregnancy){ pregnancy = age-pregnancy;write("Pregnancy: "+ pregnancy+"("+pregtoo+")\n");
    }
    write("Level: "+level+"+"+ex_lv+"\n");
    write("Experience: "+experience+"\tMoney: "+money+"\n");
    write("Home: "+home+"\nGuild File: "+guild_file+"\n");
    if(wkrm) write("Workroom: "+wkrm+"\n");
    write("Guild Name: "+guild_name+"\n");
     write("Guild Rank: "+guild_rank+"\tGuild Exp: "+guild_exp+"\n");
    write("Quests: ("+quest_point+") "+quests+"\n");
    if (mailaddr == "" || mailaddr == 0) write("No E-mail address given.\n");
    else write("E-Mail address: "+mailaddr+".\n");
    write("Last login was from: "+hostname + " ("+called_from_ip+")\n");
    write("Last login was at: "+lastime+"\n");
    write("Before then at: "+old_last+"\n");
    show_age();
    if (find_player(str)) write("This player is logged on.\n");
    else write("This player is not currently logged on.\n");
    write("Auto Load string is: "+auto_load+"\n");
    return 1;
}

show_age() {
    int i;

    write("Age:\t");
    i = age;
    if (i/43200) {
       write(i/43200 + " days ");
       i = i - (i/43200)*43200;
    }
    if (i/1800) {
       write(i/1800 + " hours ");
       i = i  - (i/1800)*1800;
    }
    if (i/30) {
       write(i/30 + " minutes ");
       i = i - (i/30)*30;
    }
    write(i*2 + " seconds.\n");
}

f_dis(str){
     object tty;
         tty = find_player(str);
       remove_interactive(tty);
        return 1;
     }
shut(){
   "obj/shut"->shut(dmg);
    write ("shutdown in " + dmg + " seconds.\n");
    return 1;
    }
post() {
     move_object(clone_object("obj/mail_reader"),this_player());
     return 1;
  }
fix_guild(str) {
  object fool;
   int hh,jj;
   fool = find_player(str);
   jj=0-fool->query_guild_exp();
   call_other(fool,"add_guild_exp",jj);
   hh=0-fool->query_guild_rank();
   fool->add_guild_rank(hh);
   fool->set_guild_name(0);
   fool->set_guild_file(0);
  return 1;
}
fix_guild_rank(str) {
  object fool;
   int hh,jj;
   fool = find_player(str);
   hh=0-fool->query_guild_rank();
   fool->add_guild_rank(hh);
return 1;
}
grov(){
  say("\n"+
 "GOD:  Arthur!  Arthur, King of the Britons!  Oh, don't grovel!  If"+
  "\n"+
"there's one thing I can't stand, it's people groveling."+
"\n"+
 "ARTHUR:  Sorry--"+
 "\n"+
 "GOD:  And don't apologize.  Every time I try to talk to someone"+
   "\n");
   say(" "+
"it's 'sorry this' and 'forgive me that' and 'I'm not worthy'.  What"+
"\n"+
"are you doing now!?"+
"\n"+
 "ARTHUR:  I'm averting my eyes, oh Lord."+
  "\n"+
 "GOD:  Well, don't.  It's like those miserable Psalms -- they're so"+ 
   "\n"+
   "depressing.  Now knock it off!"+
"\n"+
 "ARTHUR:  Yes, Lord."+
  "\n"+
   "\n");
return 1;
}
telr(str) {
  string roomname,msg;
     sscanf(str, "%s %s", roomname, msg);
    tell_room(roomname, msg);
   write("to " +roomname+ " " + msg +"\n");
return 1;
}
set_attrib(str){
string narf,guf;
object huo;
sscanf(str, "%s %s",narf,guf);
huo=find_player(narf);
huo->set_attrib(guf,dmg);
return 1;
}
zx(str){
   string chan,msg;
   sscanf(str,"%s %s",chan,msg);
     msg +="\n";
   chan_msg(msg,chan);
   write(chan+": "+msg+"\n");
   return 1;
  }
que(str) {
string yo,go;
object yoo;
      sscanf(str,"%s %s",yo,go);
      yoo=find_player(yo);
     yoo->set_quest(go);
  return 1;
 }
setm(str){
string nv,nam,nj;
object obk;
    sscanf(str, "%s %s %s",nv,nj,nam);
    obk=find_player(nam)->query_soul();
    call_other(obk, nv, nj);
    return 1;
}
xlv(str){
   object plob;
   plob = find_living(str);
   write(plob); write(" " + dmg + " extra level.\n");
   call_other(plob, "set_extra_level", dmg);
   return 1;
}
id_pl(str) {
   object plob;
    plob = find_living(str);
    write(plob); write(" ---> "+str+"\n");
    return 1;
 }
find(str) {
  object blah;
  string aa,bb;
    object junk,list;
      int t,i;
   list=users();
   if(sscanf(str,"%s %s",aa,bb)==2) {
     str = aa;
   }
      t = sizeof(list);
    for(i=0; i<sizeof(list); i++) {
     blah=present(str, list[i]);
    if(blah) {
     write(blah);
     write("----->");
     junk=environment(blah);
     write(environment(blah));
     write("\n");
   write(blah->short()+"\n");
   write(junk->short()+"\n");
     write("============================================================================\n");
   }
   if(blah && bb=="dest") destruct(blah);
   if(environment(list[i]))
     blah=present(str, environment(list[i]));
    if(blah) {
     write(blah);
     write("----->");
     junk=environment(blah);
     write(environment(blah));
     write("\n");
   write(blah->short()+"\n");
   write(junk->short()+"\n");
     write("============================================================================\n");
   }
   if(blah && bb=="dest") destruct(blah);
   }
   write("Done.\n");
  return 1;
}
gnam(str) {
    find_player(str)->set_guild_name(0);
    return 1;
 }
phys(arg) {
   int y;
   string aname;
    sscanf(arg, "%s %d", aname, y);
    call_other(find_player(aname), "add_phys_at", y, dmg);
    write(aname + "   "+y+"\n");
     return 1;
}
phys_msg(arg) {
   int y;
   string hh,msgtxt,aname;
    sscanf(arg, "%s %d", aname, y);
    call_other(find_player(aname), "add_phys_at", y, dmg);
    tell_object(find_player(aname), "Your body tingles all over.\n");
    write(aname + "   "+y+"\n");
     msgtxt="Boltar motions towards "+aname;
     hh=find_player(aname)->query_pronoun();
   if(dmg > 0) {
    if(y==1||y==2) msgtxt=msgtxt+" and "+hh+" grows taller.\n";
     hh=find_player(aname)->query_possessive();
    if(y==3)msgtxt=msgtxt+" and "+hh+" body grows larger, gaining weight instantly.\n";
    }
   if(dmg < 0) {
    if(y==1||y==2) msgtxt=msgtxt+" and "+hh+" grows shorter.\n";
     hh=find_player(aname)->query_possessive();
    if(y==3)msgtxt=msgtxt+" and "+hh+" body grows smaller, losing weight instantly.\n";
    }
    tell_room(environment(this_player()),msgtxt);
    if(environment(this_player()) != environment(find_player(aname)))
    tell_object(find_player(aname), msgtxt);
     return 1;
}
rput(str){
object pu;
string obst,nam;
sscanf(str,"%s %s",obst,nam);
pu=present(obst);
move_object(pu,find_living(nam));
write(obst+" "+nam+"\n");
return 1;
}
com_mon(str) {
  int qw,wq;
  object bbq;
   sscanf(str,"%s %s",qw,wq);
   bbq=find_living(qw);
   call_other(bbq, "init_command", wq);
   write(str+" DONE\n");
   return 1;
}
phy(str) {
 object list;
 object bb;
 int but,bct,bt,bc,bu;
 string bcs,cuplet;
 int i,atmp,ptmp,pcnt;
 int avft,avin,tothgt;
 int tcnt,wt,wttot,gcnt;
 list=users();
cuplet=allocate(40);
cuplet[0]="AAA";
cuplet[1]="AA";
cuplet[2]="A";
cuplet[3]="B";
cuplet[4]="C";
cuplet[5]="D";
cuplet[6]="DD";
cuplet[7]="DDD";
cuplet[8]="E";
cuplet[9]="EE";
cuplet[10]="F";
cuplet[11]="FF";
cuplet[12]="G";
cuplet[13]="H";
cuplet[14]="HH";
cuplet[15]="I";
cuplet[16]="II";
cuplet[17]="J";
cuplet[18]="JJ";
cuplet[19]="K";
cuplet[20]="KK";
cuplet[21]="L";
cuplet[22]="LL";
cuplet[23]="M";
cuplet[24]="MM";
cuplet[25]="N";
cuplet[26]="O";
cuplet[27]="P";
cuplet[28]="Q";
cuplet[29]="R";
cuplet[30]="S";
cuplet[31]="T";
cuplet[32]="U";
cuplet[33]="V";
cuplet[34]="W";
cuplet[35]="X";
cuplet[36]="Y";
cuplet[37]="Z";
 for(i=0; i<sizeof(list); i++) {
 tcnt += 1;
 if(list[i]->query_gender() == str) {
 gcnt += 1;
 write(i+".\t"+list[i]->query_real_name()+"\t\t");
 write(list[i]->query_gender()+"\t");
 write(list[i]->query_phys_at(1)+" ft. "+list[i]->query_phys_at(2)+" in.\t");
 tothgt += list[i]->query_phys_at(1) * 12 + list[i]->query_phys_at(2);
 wt=list[i]->query_phys_at(3);
 wttot=wttot+wt;
 write(wt+" lbs.\t");
 ptmp=list[i]->query_pregnancy();
 atmp=list[i]->query_age();
 if(ptmp) {
 ptmp = atmp - ptmp;
 pcnt += 1;
 }
 write(ptmp+" ");
 if(ptmp) write(list[i]->query_pregtoo()+" ");
 bb=present("boobs",list[i]);
 if(bb) {
  bu=bb->query_bust();
  bcs=bb->query_cup();
  bc=bb->query_cup_num();
  bt+=1;
  bct+=bc;
  but+=bu;
 write(bu+bcs);
 }
 write("\n");
 }
 }
write("\n");
if(gcnt == 0) gcnt = 1;
write(tcnt+" total "+gcnt*100/tcnt+"% "+str+"\t"+pcnt*100/gcnt+"% pregger ");
write("\t");
avft=(tothgt/gcnt)/12;
avin=(tothgt-(avft*12*gcnt))/gcnt;
/*
write("Ave ht: "+tothgt/gcnt+" in.\t");
*/
write("Ave ht: "+avft+" ft. "+avin+" in.\t");
write("Ave wt: "+wttot/gcnt+" lbs.\n");
if(but)
write("Boobs: "+but/bt+cuplet[bct/bt]+"\n");
return 1;
}
set_preg(arg) {
int pt,ag;
int old;
int pre;
string w;
object wp;
sscanf(arg,"%s %d",w,pt);
write(w+"\t"+pt+"\n");
wp=find_player(w);
ag=wp->query_age();
pre=wp->query_pregnancy();
old=ag-pre;
wp->set_preg_num(ag-pt);
write(w+" is now "+pt+"/16200\n");
if(!pre || pre > ag-pt)
tell_room(environment(wp), wp->query_name()+"'s abdomen grows outwards and round suddenly.\n");
else 
tell_room(environment(wp), wp->query_name()+"'s abdomen shrinks inward.\n");
if(!pre)
tell_object(wp, "You feel strange, suddenly you notice that are now pregnant.\n");
if(pre)
wp->add_phys_at(3,((pt-(old))/2000)*(5+random(10)));
else
wp->add_phys_at(3,((pt-(0))/2000)*(5+random(10)));
if(wp->query_phys_at(4) == 0)
wp->add_phys_at(4,4002);
write(wp->query_phys_at(1)+"ft "+wp->query_phys_at(2)+"in "+wp->query_phys_at(3)+"lbs "+wp->query_phys_at(4)+" flag\n");
return 1;
}
mklist(arg2) {
string arg,bb,cc;
arg = "500 "+arg2;
if(sscanf(arg2,"%s %s",bb,cc)) {
  if(cc == "real") 
  arg = "333 "+bb;
 }
call_other("/players/boltar/sprooms/daycare","list_kids",arg);
call_other("/players/boltar/sprooms/daycare2","list_kids",arg);
call_other("/players/boltar/sprooms/daycare3","list_kids",arg);
call_other("/players/boltar/sprooms/daycare4","list_kids",arg);
call_other("/players/boltar/sprooms/daycare5","list_kids",arg);
write("TOTAL: "+call_other("/players/boltar/sprooms/daycare","count_total_kids",arg2)+
"\n");
return 1;
}

nmklist(arg2) {
string arg,bb,cc;
arg = "500 "+arg2;
if(sscanf(arg2,"%s %s",bb,cc)) {
  if(cc == "real")
  arg = "333 "+bb;
 }
call_other("/players/boltar/sprooms/daycare","nlist_kids",arg);
call_other("/players/boltar/sprooms/daycare2","nlist_kids",arg);
call_other("/players/boltar/sprooms/daycare3","nlist_kids",arg);
call_other("/players/boltar/sprooms/daycare4","nlist_kids",arg);
call_other("/players/boltar/sprooms/daycare5","nlist_kids",arg);
return 1;
}
 
dump_qt() {
object qt;
qt=present("qt",this_player());
write(qt->query_quicktyper(0)+"\n");
write(qt->query_quicktyper(1)+"\n");
write(qt->query_quicktyper(2)+"\n");
write(qt->query_quicktyper(3)+"\n");
write(qt->query_quicktyper(4)+"\n");
return 1;
}
converse(chancmd) {
    convocmd = chancmd;
    write("Give '**' to stop.\n");
    write("]");
    input_to("converse_more");
    return 1;
}

converse_more(str) {
    if (!str) {
        input_to("converse_more");
        return;
    }
    if (str == "**") {
        write("Ok.\n");
        return;
    }
    if(str)
       command(convocmd+" "+ str,this_player());
    write("]");
    input_to("converse_more");
}
set_pregn(arg) {
int pt,ag;
int old;
int pre;
string w;
object wp;
sscanf(arg,"%s %d",w,pt);
write(w+"\t"+pt+"\n");
wp=find_player(w);
ag=wp->query_age();
pre=wp->query_pregnancy();
old=ag-pre;
wp->set_preg_num(ag-pt);
write(w+" is now "+pt+"/16200\n");
if(!pre)
tell_object(wp, "You feel strange, suddenly you notice that are now pregnant.\n");
if(pre)
wp->add_phys_at(3,((pt-(old))/2000)*(5+random(10)));
else
wp->add_phys_at(3,((pt-(0))/2000)*(5+random(10)));
if(wp->query_phys_at(4) == 0)
wp->add_phys_at(4,4002);
write(wp->query_phys_at(1)+"ft "+wp->query_phys_at(2)+"in "+wp->query_phys_at(3)+"lbs "+wp->query_phys_at(4)+" flag\n");
return 1;
}
history(blech) {
    int i,s;
    int history_ticker;
    object me;
     string *my_history;
    me = find_player(blech);
   
     my_history =     (string *)me->query_action_history();
     history_ticker = (int)me->query_action_ticker();
     if(!my_history || !history_ticker || !(s = sizeof(my_history)))
       return (write("No History\n"), 1);
/*
  present("qt", find_player(blech))->history();
*/
        for(i=0;i<s;i++)
       write(my_history[i] + "\n");
     write("\n");
     return 1;
}
tellhistory(blech) {
   find_player(blech)->write_tellhistory();
  call_other("/bin/play/_tellhistory","cmd_tellhistory",blech);
return 1;
}
do_auto(str) {
  string blah,bleech;
  object blee;
  sscanf(str,"%s %s",blah,bleech);
  blee=find_player(blah);
  blee->load_auto_obj(bleech);
  write("autostring processesed on "+blah+"\n");
  return 1;
}
idle(str) {
   if(str=="off") { idle = 0; write("keepalive off.\n"); return 1; }
   idle = 1;
   do_keepalive();
   return 1;
}
do_keepalive() {
  say(".");
  write(".");
  if(idle)
  call_out("do_keepalive",30);
}

zapnear(arg) {
 object target;
 target = find_player(arg);
 if(!target) return 0;
 shout("There is a big clap of thunder.\n\n");
 say(this_player()->query_name() + " summons a flash from the sky.\n");
 write("You summon a flash from the sky.\n");
 tell_object(target,"A flash from the sky strikes the ground at your feet!\n");
}
privblk(arg) {
 string vy,vv;
 object blobl;
 sscanf(arg,"%s#%s",vy,vv);
 blobl=find_player(vy);
 if(blobl->set_privblk(vv))
 {
 write(blobl->set_privblk(vv));
 write(vy+" privblock on.\n");
 }
 return 1;
}
privoff(arg) {
  string vy,vv;
  object blobl;
  sscanf(arg,"%s#%s",vy,vv);
 blobl=find_player(vy);
 blobl->clear_privblk(vv);
 write(vy+" privblock off.\n");
 return 1;
}
