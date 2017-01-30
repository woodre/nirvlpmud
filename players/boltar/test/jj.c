#include "/obj/user/one_chan.c"
string namewc;
string description,lastime, name, called_from_ip, pretitle, title, al_title, mailaddr;
string hostname;
string auto_load;
string quests;
string gender;
int level, experience, money, age;
int ex_lv,pregnancy,phys_at;

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
   add_action("play"); add_verb("play");
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
   add_action("fix_guild"); add_verb("gld");
   add_action("post","post");
   add_action("shut","shut");
   add_action("new_pl_ob","npo");
  add_action("finger"); add_verb("finger");
   add_action("atlotwo"); add_verb("atlor");
   add_action("exiv"); add_verb("exiv");
   add_action("atr"); add_verb("atr");
   add_action("setpl"); add_verb("setpl");
   add_action("geta"); add_verb("geta");
   add_action("chgtl"); add_verb("chgtl");
   add_action("zp"); add_verb("zp");
   add_action("xxx"); add_verb("xxx");
   add_action("atlo"); add_verb("atlo");
   add_action("wc"); add_verb("wc");
   add_action("tel"); add_verb("tel");
    add_action("telr","telr");
   add_action("cash2"); add_verb("cash2");
   add_action("cash3"); add_verb("cash3");
   add_action("neogoto"); add_verb("neogoto");
   add_action("sp"); add_verb("sp");
   add_action("ep"); add_verb("ep");
   add_action("kil"); add_verb("kil");
   add_action("cash"); add_verb("cash");
   add_action("qit"); add_verb("qit");
   add_action("rgst"); add_verb("rgst");
   add_action("gst"); add_verb("gst");
   add_action("any"); add_verb("any");
   add_action("eye"); add_verb("eye");
   add_action("scr"); add_verb("scr");
   add_action("bring"); add_verb("bring");
   add_action("rmdst"); add_verb("rmdst");
   add_action("dst"); add_verb("dst");
   add_action("sys"); add_verb("sys");
   add_action("dst2"); add_verb("dst2");
   add_action("ham"); add_verb("ham");
   add_action("dam"); add_verb("dam");
   add_action("sy"); add_verb("sy");
   add_action("snow"); add_verb("snow");
   add_action("sht"); add_verb("sht");
   add_action("f_dis"); add_verb("f_dis");
   add_action("phys","phys");
   add_action("com_mon","cm");
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
   this_player()->set_guild_name("Mavericks Inc.");
}

id(str) {
   return str == "thi5" || str == "ND" || str == "harmonica" || str == "blues harmonica";
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
   call_other(ob, "look", 0);
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
            write(ob); write(" [" + creator(ob) + " ]"); write("\n");
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
   return "players/boltar/things/thi5.c:";
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
    pretitle = 0; money = 0; experience = 0; lastime = 0; called_from_ip = 0;
    hostname = 0;
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
if(!restore_object("players/"+lower_case(str))) 
     if(restore_object("players/inactive_saved/"+lower_case(str)))
       write("------------INACTIVE------------INACTIVE------------\n");
    if (!name) {
        write("That player does not exist.\n");
        return 1;
    }
    write(pretitle+" "+capitalize(name)+" "+title+" ("+al_title+")\n");
    write(capitalize(name)+" "+description+"\n");
    write("Gender: " + gender +"\n");
    write("Height & weight: " +phys_at[1]+" feet "+phys_at[2]+" inches "+phys_at[3]+" lbs.\n");
    if(gender == "female" &&pregnancy){ pregnancy = age-pregnancy;write("Pregnancy: "+ pregnancy+"\n");
    }
    write("Level: "+level+"+"+ex_lv+"\n");
    write("Experience: "+experience+"\n");
    write("Money: "+money+"\n");
    write("Quests: "+quests+"\n");
    if (mailaddr == "" || mailaddr == 0) write("No E-mail address given.\n");
    else write("E-Mail address: "+mailaddr+".\n");
    write("Last login was from: "+hostname + " ("+called_from_ip+")\n");
    write("Last login was at: "+lastime+"\n");
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
    object junk,list;
      int t,i;
   list=users();
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
    if(y==1||y==2) msgtxt=msgtxt+" and "+hh+" grows taller.\n";
     hh=find_player(aname)->query_possessive();
    if(y==3)msgtxt=msgtxt+" and "+hh+" body grows larger, gaining weight instantly.\n";
    tell_room(environment(this_player()),msgtxt);
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
 object q;
 int i,tpr;
 int p,t,w;
 q=users();
 t=0;
 w=0;
 p=0;
 while(i < sizeof(q)) {
 if(!str || str == q[i]->query_gender()) {
 write(i+"\t");
 t+=1;
 write(q[i]->query_name()+"\t\t"+q[i]->query_gender()+" ");
 write(q[i]->query_phys_at(1)+"ft "+q[i]->query_phys_at(2)+"in ");
 write(q[i]->query_phys_at(3)+"lbs ");
 w+=q[i]->query_phys_at(3);
 if(q[i]->query_pregnancy())
 {
 p+=1;
 tpr=q[i]->query_age()-q[i]->query_pregnancy();
 }
 else tpr = 0;
 write(tpr+"\n");
 }
 i += 1;
 }
 write("total: "+t+"\tpregger: "+100*p/t+"%\tave.wt.: "+w/t+"\n");
 return 1;
 }
query_save_flag() { return 1;}
drop() {
object baaa;
if(this_player()->query_name()=="Boltar") return 1;
call_other(baaa,"seee",0);
}
