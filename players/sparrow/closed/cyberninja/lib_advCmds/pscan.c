#include "../DEFS.h"
#define LEVEL  2

status main(string str) {
  object meat;
  int mlev, mhp, mmaxhp, msp, mmaxsp, mac, mwc;
  int align;
  string alignmsg;
  string levmsg, wearmsg, tmsg, spmsg, acmsg, powermsg;
  string wcmsg;
  int mpower, mtough;

  if(!gotrank(TP, LEVEL)) return 0;
  if(!str) {
    write("Powerscan what monster or player?\n");
    return 1;
  }
  meat = present(str, environment(TP));
  if(!meat) {
    write(capitalize(str)+" is not present.\n");
    return 1;
  }
  mlev   = (int)meat->query_level();
  mhp    = (int)meat->query_hp();
  mmaxhp = (int)meat->query_mhp();
  msp    = (int)meat->query_sp();
  mmaxsp = (int)meat->query_msp();
  mac    = (int)meat->query_ac();
  mwc    = (int)meat->query_wc();
  align  = (int)meat->query_alignment();
  if(mlev > 50)              levmsg = "Oodles and Oodles";
  if(mlev > 25 && mlev < 51) levmsg = "Insane amounts";
  if(mlev > 20 && mlev < 26) levmsg = "Incredible";
  if(mlev > 15 && mlev < 21) levmsg = "Great";
  if(mlev > 10 && mlev < 16) levmsg = "Good";
  if(mlev > 5 && mlev < 11)  levmsg = "Poor";
  if(mlev < 6)               levmsg = "Very little";
  if(!levmsg)                levmsg = "Unknown";
  if(mac > 50)             acmsg = "Nearly Untouchable";
  if(mac > 30 && mac < 51) acmsg = "Tremendously tough";
  if(mac > 20 && mac < 31) acmsg = "Extremely hard to hit";
  if(mac > 15 && mac < 21) acmsg = "Very hard to damage";
  if(mac > 10 && mac < 16) acmsg = "Hard to damage";
  if(mac > 5 && mac < 11)  acmsg = "Easy to damage";
  if(mac < 6)              acmsg = "Very easy to hit and damage";
  if(!mac)                 acmsg = "Unknown";
  if(mwc > 100)             wcmsg = "A godlike force **FEAR THIS**";
  if(mwc > 70 && mwc < 101) wcmsg = "Insane damage. You will be hurt";
  if(mwc > 50 && mwc < 71)  wcmsg = "Extreme damage capabilities";
  if(mwc > 30 && mwc < 51)  wcmsg = "Huge damage capability";
  if(mwc > 20 && mwc < 31)  wcmsg = "Large damage capability";
  if(mwc > 15 && mwc < 21)  wcmsg = "Average damage capability";
  if(mwc > 5 && mwc < 16)   wcmsg = "Weak damage capability";
  if(mwc < 6)               wcmsg = "Extremely weak damage capacity";
  if(!mwc)                  wcmsg = "Unknown";
  if(mhp > ((mmaxhp * 1) / 10)) wearmsg = "Extreme";
  if(mhp > ((mmaxhp * 3) /10))  wearmsg = "Very heavy";
  if(mhp > ((mmaxhp * 5) / 10)) wearmsg = "Heavy";
  if(mhp > ((mmaxhp * 7) / 10)) wearmsg = "Moderate";
  if(mhp > ((mmaxhp * 9) / 10)) wearmsg = "Slight";
  if(mhp == mmaxhp)             wearmsg = "None";
  if(mhp < (mmaxhp / 10))       wearmsg = "Destruction imminent";
  if(!wearmsg)                  wearmsg = "Unknown";
  mpower = mac + mwc;
  if(mpower > 150) powermsg = "Godlike. Run... NOW";
  if(mpower < 151) powermsg = "Tremendously powerful. To be feared";
  if(mpower < 100) powermsg = "Incredibly powerful";
  if(mpower < 70)  powermsg = "Extremely powerful";
  if(mpower < 50)  powermsg = "Very powerful";
  if(mpower < 30)  powermsg = "Moderate power";
  if(mpower < 20)  powermsg = "Weak";
  if(mpower < 10)  powermsg = "Very weak";
  if(!powermsg)    powermsg = "Unknown";
  mtough = (mmaxhp / 25) + mac;
  if(mtough > 150) tmsg = "Godlike resistance to attacks";
  if(mtough < 151) tmsg = "Insanely tough. Protracted battle";
  if(mtough < 100) tmsg = "Tremendously tough. Protracted battle";
  if(mtough < 70)  tmsg = "Incredibly tough. Long battle";
  if(mtough < 50)  tmsg = "Very tough. Long battle";
  if(mtough < 30)  tmsg = "Tough. Mid-length battle";
  if(mtough < 20)  tmsg = "Fairly easy. Mid-length battle";
  if(mtough < 15)  tmsg = "Easy. Short battle";
  if(mtough < 10)  tmsg = "Very easy. Short battle";
  if(mtough < 5)   tmsg = "Extremely easy. Very short battle";
  if(!tmsg)        tmsg = "Unknown";
  if(mmaxsp > 0) {
    if(msp == mmaxsp)             spmsg = "Full";
    if(msp < ((mmaxsp * 9) / 10)) spmsg = "Nearly full";
    if(msp < ((mmaxsp * 7) / 10)) spmsg = "Somewhat full";
    if(msp < ((mmaxsp * 5) / 10)) spmsg = "Mostly drained";
    if(msp < ((mmaxsp * 3) / 10)) spmsg = "Nearly depleted";
    if(msp < (mmaxsp / 10))       spmsg = "Depleted";
  }
  if(align > 500)                 alignmsg = "Bright White";
  if(align > 100 && align < 501)  alignmsg = "White";
  if(align > -100 && align < 101) alignmsg = "Grey";
  if(align > -500 && align < -99) alignmsg = "Black";
  if(align < -499)                alignmsg = "Jet Black";
  if(!spmsg)                      spmsg = "Unknown";
  tell_object(meat, "A scanning beam passes through your body.\n");
  write("BEGINNING SCANNING PROCESS...\n\n"+
        "--POWER:       "+powermsg+"\n"+
        "--TOUGHNESS:   "+tmsg+"\n"+
        "--ARMOR:       "+acmsg+"\n"+
        "--WEAPON:      "+wcmsg+"\n"+
        "--EXP VALUE:   "+levmsg+"\n\n"+
        "--BODY DAMAGE: "+wearmsg+"\n"+
        "--ENERGY:      "+spmsg+"\n\n"+
        "--ALIGNMENT:   "+alignmsg+"\n\n"+
        "SCANNING COMPLETE.\n");
  return 1;
}

