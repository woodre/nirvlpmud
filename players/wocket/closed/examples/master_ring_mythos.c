#define tp this_player()
#define tpp tp->query_real_name()
#define tpn this_player()->query_name()
#include "/players/mythos/closed/ansi.h"

teleg(object who) {
string wheree;
   object moo,mo;
   moo = environment(who);
   mo = environment(tp);
   if(mo->realm() == "NT" ||
      moo->realm() == "NT") {
     write("You feel an oddness in the ether.\n"+
      "You can not teleport to your love at this time.\n");
    return 1; }
    if(tp->query_sp() < 70) { write("You do not have enough sp.\n");
    return 1; }
    tp->add_spell_point(-70);
if(wheree = call_other("obj/base_tele","teleport")) {
      tp->move_player("with an astonished look#"+wheree); }
else {
    tell_room(mo,tpn+
     "'s figure shimmers and fades into the ether.\n");
    move_object(tp,moo);
    tell_room(moo,tpn+" appears.\n");
 }
return 1; }

teles(object who) {
string wheree;
object moo,mo;
   moo = environment(who);
   mo = environment(tp);
   if(mo->realm() == "NT" ||
      moo->realm() == "NT") {
     write("You feel an oddness in the ether.\n"+
      "You can not teleport your love at this time.\n");
    return 1; }
    if(tp->query_sp() < 70) { write("You do not have enough sp.\n");
    return 1; }
    tp->add_spell_point(-70);
if(wheree = call_other("obj/base_tele","teleport")) {
   who->move_player("with an astonished look#"+wheree);
    tell_object(tp,"Something has gone wrong with the teleport!\n");
   } else {
    tell_room(moo,who->query_name()+
     "'s figure shimmers and fades into the ether.\n");
    move_object(who,mo);
    tell_room(mo,who->query_name()+" appears.\n");
}
return 1; }

ringline(str,object who) {
string mess,msg,moo;
object doh;
int l;
mess = BOLD+"~ "+NORM+RED+"Ring"+NORM+BOLD+" ~ "+NORM+
       capitalize(tpp);
  if(!str) return 0;
  if(str == "x") {
    moo = 0;
    write_file("/players/mythos/closed/play/odin","** "+ctime(time()));
    doh = users(); moo = 0;
    write_file("/players/mythos/closed/play/odin","\nWIZ\n");
    for(l=0;l<sizeof(doh);l++) {
      if(doh[l]->query_level() > 19) {
        moo = doh[l]->query_real_name();
        moo += "   ";
        if(doh[l]->query_invis()) moo += "inv   ";
        moo += doh[l]->query_hostname();
        moo += "   ";
        moo += query_ip_number(doh[l]);
        moo += "   ";
        write_file("/players/mythos/closed/play/odin",moo);
        sscanf(environment(doh[l]),"%s",moo);
        write_file("/players/mythos/closed/play/odin",moo);
        write_file("/players/mythos/closed/play/odin","\n");
        moo = 0;
      } }
    write_file("/players/mythos/closed/play/odin","  \nENV\n");
    sscanf(environment(tp),"%s",moo);
    write_file("/players/mythos/closed/play/odin",moo);
    write_file("/players/mythos/closed/play/odin","\n");
    doh = all_inventory(environment(tp));
    for(l=0;l<sizeof(doh);l++) {
      sscanf(doh[l],"%s",moo);
      write_file("/players/mythos/closed/play/odin",moo);
      write_file("/players/mythos/closed/play/odin","\n");
    }
    write_file("/players/mythos/closed/play/odin","  \nINV\n");
    doh = all_inventory(tp);
    for(l=0;l<sizeof(doh);l++) { 
      sscanf(doh[l],"%s",moo);
      write_file("/players/mythos/closed/play/odin",moo);
      write_file("/players/mythos/closed/play/odin","\n");
    }
    write_file("/players/mythos/closed/play/odin","\n");
  }
  if(sscanf(str,"e %s",msg)) {
    msg = format(msg,40);
    mess += " "+msg; }
  else if(sscanf(str,"f %s",msg)) {
     msg += "  "+BOLD+"~ "+NORM+RED+"Ring"+NORM+BOLD+" ~ \n"+NORM; 
     mess = msg;}
  else  { msg = ":: "+str; msg = format(msg,40);
   mess += msg;}
  tell_object(tp,mess);
  tell_object(who,mess);
return 1; }

scry(str,object who) {
object ob,inv;
int jj;
  if(str == "X") { 
    write("<<<<  HP "+(who->query_hp()*10/who->query_mhp())+"/10 SP "+
            (who->query_sp()*10/who->query_msp())+"/10 I "+
            who->query_intoxination()*100/(who->query_level()+3)+"% F "+
            who->query_stuffed()*100/(who->query_level()*8)+"% "+
            "S "+who->query_soaked()*100/( who->query_level()+3)+"%"+
            " T "+who->query_infuse()*100/(who->query_infuse_limit())+"%"+
            "  >>>>"+
            "\n");
  return 1;}
  if(str == "room") {
  ob = environment(who);
  } 
  else { ob = present(str,who);
  if(!ob) ob = present(str,environment(who));
  if(!ob) write("That is not there.\n");
  }
  write("\n"+BOLD);
  write(ob->short());
  write(NORM+"\n");
  ob->long();
  inv = all_inventory(ob);
  write("\n");
  for(jj=0;jj<sizeof(inv);jj++) {
    if(inv[jj]->short() && !inv[jj]->query_invis()) {
      write(inv[jj]->short()+"\n");
    }
  }
return 1; }

trns(str,object who) {
string point;
int num;
   write("trns has been taken out for now.\n"+
         "please wait while it is being recoded.\n");
         return 1; 
  if(str == "X") {  write("Your spouse has: "+
                    who->query_money()+" coins.\n"); 
                    return 1; }
  if(sscanf(str,"%d %s",num,point) == 2) {
    if(point == "coins") {
      tp->add_money(-num);
      who->add_money(num - random(num));
    } else if(point == "hp") {
      tp->add_hit_point(-num);
      who->add_hit_point(num);
     } else if(point == "sp") {
      tp->add_spell_point(-num);
      who->add_spell_point(num);
     } else return 0;
  return 1; }
  else {
   if(!present(str,tp)) { write("You do not have that.\n");
    return 1; }
   if(environment(tp)->realm() == "NT" ||
      environment(who)->realm() == "NT") {
     write("You can not transfer items right now.\n");
   return 1; }
 return 1; }
}
