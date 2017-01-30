/* square.c
 * The game's analogous room.c
 * This is inherited by all the squares.
 * You could rewrite this and mbin.c and all the _squares, and create an
 * entirely different game.
 */
#include "path.h"

string name;
string long_desc;

int price;
int *rent; /* 0 houses up to hotel */

short() { return name; }
long() {
  int num,i;
  object ob;

  write(PAD(name,27));
  num=MAIN->num_square(file_name(this_object()));
  write(PAD("Square: "+num,-15)+"\n");
  if(long_desc) write(long_desc);
  if(price) write(PAD("Price: "+MONEYSIGN+price,15));
  ob = TPMOBJ;
   if(ob && (ob=MAIN->query_owner(num,ob->query_gamename())))
    write(PAD("Owner: "+ob->query_cname(),-27)+"\n");
  else write("\n");
  write("--> You can go forward (f) or backward (b)\n");
  if(!ob || TP->query_brief()) return 1;
  num=ob->query_house(num);
  if(num==MORTGAGED) WRITE("MORTGAGED\n");
  if(num==OWNED) WRITE("\n");;
  if(num==0) WRITE("(Monopoly)\n");
  if(num==5) WRITE("      _______\n"
      +"     /_______\\\n"
      +"     | Hotel |\n"
      +"     |_______|\n");
  if(num<1 || num>4) WRITE("SQUARE ERROR.  Tell Jubal.\n");
  for(i=0;i<num;i++) write("    _");
  write("\n ");
  for(i=0;i<num;i++) write("  /_\\");
  write("\n ");
  for(i=0;i<num;i++) write("  |_|");
  write("\n");
  return 1;
}

init() {
  if(set_light(0)<1) set_light(10);
  add_action("forward","forward");
  add_action("forward","f");
  add_action("backward","backward");
  add_action("backward","b");
}

bounce(i) {
  int num,tmp;

  move_object(TP,this_object());
  if(i==1) return land();
  if(!TP->query_brief()) write("You bounce on the square: "+name+"\n");
  say(NAME+" bounces by this square.\n");
  num=MAIN->num_square(file_name(this_object()));
  if(num==-1)
    WRITE("Error in looking this square up! (shouldn't happen)\n");
  if(i>BOUNCE_MAX) {
    tmp=num+i-BOUNCE_MAX;  /* start of bounce (with BOUNCE_MAX-1) */
    if(tmp>SQSZ) /* we can't skip go - let it take care of the bounce max */
      return MAIN->square_file(0)->bounce(num+i-SQSZ);
    if(!TP->query_brief()) write("You skip ahead\n");
    MAIN->square_file(tmp)->bounce(BOUNCE_MAX);
    return;
  }
  MAIN->square_file(num+1)->bounce(i-1);
}

land() {
  object owner;
  int rt,i;
  string str;

  i=MAIN->num_square(file_name(this_object()));
  if(i==-1) WRITE("This square doesn't exist!\n");
  owner=MAIN->query_owner(i,TPMOBJ->query_gamename());
  str="";
  rt=0;

  if(owner)
    if(owner==TPMOBJ)
      str="  ("+({"its","his","her"})[TP->query_gender()]+" own square)";
    else {
      str=" owned by: "+owner->query_cname();
      if(owner->query_house(i)==MORTGAGED) str+="  (Mortgaged)";
      else {
        rt=calc_rent(owner);
        write("--You land on "+name+str+"  and pay "+MS+rt+"\n");
        SHOUT(NAME+" lands on "+name+str+"  and pays "+MS+rt+"\n");
        say(NAME+" lands on this square.\n");
        tell_object(owner->query_player(),
                    "++"+NAME+" pays you "+MS+rt+" in rent\n");
        TPMOBJ->set_square(file_name(this_object()));
        TPMOBJ->add_cash(-rt);
        owner->add_cash(rt);  /* WHAT IF TP DOESN'T HAVE IT?? */
        return;
      }
    }

  if(owner==TPMOBJ) write("You land on: "+name+" (yours).\n");
  else write("You land on: "+name+str+".\n");
  SHOUT(NAME+" lands on "+name+str+"\n");
  say(NAME+" lands on this square.\n");
  TPMOBJ->set_square(file_name(this_object()));
}

/* for show_property in MBIN */
rent_for(i) {
  if(i==UNOWNED || i==MORTGAGED) return 0;
  if(i==OWNED) return rent[0];
  if(i==MONOPOLY) return 2*rent[0];
  return rent[i];
}
query_price() { return price; }
query_housecost() {
  int i,m;
  i=MAIN->num_square(file_name(this_object()));
  if((m=MAIN->num_monopoly(i))==0 || m==100 || m==200) return 0;
  return ((i-i%10)/10+1)*50;
}

calc_rent(owner) {
  int i,j,m,*mon,tmp,tmp2;

  i=MAIN->num_square(file_name(this_object()));
  if(i==-1) return !write("This square doesn't exist!\n");
  if(owner->query_house(i)==MORTGAGED) return 0;
  m=MAIN->num_monopoly(i);
  if(m==0) WRITE("Error!  This square shouldn't be owned!\n");
  if(m==100) {
    mon=MAIN->monopoly(i);
    tmp2=0;
    for(tmp=0;tmp<sizeof(mon);tmp++)
      if(owner->query_house(mon[tmp])!=UNOWNED) tmp2++;
    return ({25,50,100,200})[tmp2];
  }
  if(m==200) {
    mon=MAIN->monopoly(i);
    for(tmp=0;tmp<sizeof(mon);tmp++)
      if(owner->query_house(mon[tmp])!=UNOWNED) tmp2=1;
    write("You roll dice for landing on a Utility.\n");
    i=random(6)+1;   j=random(6)+1;
    MBIN->show_dice(i,j);
    if(tmp2) return (i+j)*10;
    return (i+j)*4;
  }
  return rent_for(owner->query_house(i));
}

forward() {
  int num;
  num=MAIN->num_square(file_name(this_object()));
  if(num==-1) FAIL("You need to be on a monopoly square.\n");
  TP->move_player("for the next square#"+MAIN->square_file(num+1));
  return 1;
}
 
backward() {
  int num;
  num=MAIN->num_square(file_name(this_object()));
  if(num==-1) FAIL("You need to be on a monopoly square.\n");
  TP->move_player("in the direction of the previous square#"
                  +MAIN->square_file(num-1));
  return 1;
}

