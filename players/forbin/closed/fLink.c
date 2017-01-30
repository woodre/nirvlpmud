/*  Forbin | Create date:  may2002.22 | Last mod:  may2002.23  */
/*
 *  used to report bugs/typos/opinions/ideas about my area
 *  logs to /players/forbin/logs/bugs.flink
 *                               typos.flink
 *                               ideas.flink
 *                               opinions.flink
 */

#include "/players/forbin/define.h"
string wf_name;
int can_i_report;

id(string str){ return str == "forbin_link_submitter"; }

short()
{
  object a, e;
  if((a = this_player()) && (e = environment()) &&
     (e == a))
  return "f"+HIW+"L"+NORM+"ink ["+HIY+"fl_help for usage"+NORM+"]";
}

init()
{
  add_action("cmdReport","f_link");
  add_action("fl_help","fl_help");
  add_action("fl_destruct","fl_destruct");
  add_action("fbug","fbug");
  add_action("ftypo","ftypo");
  add_action("fidea","fidea");
  add_action("fopinion","fopinion");
  add_action("submit","submit");
  can_i_report = 0;
}

fl_destruct()
{
  if(creator(ENVTP) != "forbin" && file_name(ENVTP) != "room/south/sforst4") 
  {
    tell_object(ENVTO, HIW+"I will destruct myself.  Thank You.\n"+NORM);
    destruct(TO);
      return 1;
  }
  tell_object(ENVTO, HIW+"\tYou may only destruct this item OUTSIDE of my area.\n"+NORM);
    return 1;
}

cmdReport()
{
  if(creator(ENVTP) != "forbin" && file_name(ENVTP) != "room/south/sforst4") 
  {
    tell_object(ENVTO, HIW+"It doesn't make much sense to use an fLink outside of\n"+
                           "Forbin's area.  I will destruct myself.  Thank You.\n"+NORM);
    destruct(TO);
      return 1;
  }
  tell_object(ENVTO, HIW+"\tConstructing link . . .\n"+NORM);
  call_out("link_established", 1);
    return 1;
}

link_established()
{
  tell_object(ENVTO, HIW+"\n\tLink established.\n\n"+NORM);
  tell_object(ENVTO, HIW+"\tWhat would you like to report to Forbin?\n"+NORM);
  tell_object(ENVTO, HIW+"\tSelect ONE of the following types.\n"+NORM);
  tell_object(ENVTO, HIW+"\t "+HIY+"fbug "+HIW+"|"+HIY+" ftypo "+HIW+"|"+HIY+" fidea "+HIW+"|"+HIY+" fopinion"+HIW+"\n"+NORM);
  can_i_report = 1;
}

fbug()
{
  if(can_i_report <= 0)
  {
    notify_fail(HIW+"\tYou have not established a link.  Type f_link.\n"+NORM); 
      return 0; 
  }
  if(can_i_report == 1)
  {
    wf_name = "bugs.flink";
    call_out("report_type", 0);
      return 1; 
  }
}

ftypo()
{
  if(can_i_report <= 0)
  {
    notify_fail(HIW+"\tYou have not established a link.  Type f_link.\n"+NORM); 
      return 0; 
  }
  if(can_i_report == 1)
  {
    wf_name = "typos.flink";
    call_out("report_type", 0);
      return 1; 
  }
}

fidea()
{
  if(can_i_report <= 0)
  {
    notify_fail(HIW+"\tYou have not established a link.  Type f_link.\n"+NORM); 
      return 0; 
  }
  if(can_i_report == 1)
  {
    wf_name = "ideas.flink";
    call_out("report_type", 0);
      return 1; 
  }
}

fopinion()
{
  if(can_i_report <= 0)
  {
    notify_fail(HIW+"\tYou have not established a link.  Type f_link.\n"+NORM); 
      return 0; 
  }
  if(can_i_report == 1)
  {
    wf_name = "opinions.flink";
    call_out("report_type", 0);
      return 1; 
  }
}

report_type()
{
  tell_object(ENVTO, HIW+"\tPlease submit your report: "+HIY+"'"+NORM+"submit "+HIY+"<"+NORM+"message"+HIY+">'\n"+NORM);
    return 1;
}

submit(str)
{
  if(can_i_report <= 0)
  {
    notify_fail(HIW+"\tYou have not established a link.  Type f_link.\n"+NORM); 
      return 0; 
  }
  if(can_i_report == 1)
  {
    if(!str) 
    { 
      tell_object(ENVTO, HIW+"\tYou must enter some text: "+NORM+"submit "+HIY+"<"+NORM+"message"+HIY+">"+HIW+".\n"+
                             "\tDesconstructing link . . .\n"+NORM);
      can_i_report = 0;
        return 1;
    } 
    write_file(LOGDIR+wf_name, ctime()[4..15]+" "+ctime()[20..23]+" "+GRN+pad(capitalize((string)this_player()->query_real_name()), 12)+NORM+" ["+HIK+""+file_name(ENVTP)+""+NORM+"]\n\t"+str+"\n");
    if(find_player("forbin") && (string)this_player()->query_real_name() != "forbin")
      {
      tell_object(find_player("forbin"), HIW+TPN+" has submitted: "+BLINK+HIY+""+wf_name[0..strlen(wf_name)-8]+""+NORM+""+HIW+".\n"+NORM);
      }
    tell_object(ENVTO, HIY+"\tYour "+wf_name[0..strlen(wf_name)-8]+" has been delivered."+NORM+"\n"+
                       HIW+"\tForbin appreciates your input.\n"+
                           "\tDesconstructing link . . .\n"+NORM);
    can_i_report = 0;
      return 1;
  }
} 

fl_help()
{
  tell_object(ENVTO, HIY+"\tThis device may be used to tell Forbin of problems with his \n"+
                         "\t"+HIY+"area.  You may submit "+HIW+"bugs"+NORM+""+HIY+", "+HIW+"typos"+NORM+""+HIY+", "+HIW+"ideas"+NORM+""+HIY+", or "+HIW+"opinions"+NORM+""+HIY+" of  \n"+
                         "\this creations.  Just type <"+HIW+""+BLINK+"f_link"+NORM+""+HIY+"> to begin, and follow   \n"+
                         "\tthe directions.  To destroy this item, type <"+HIW+"fl_destruct"+HIY+">   \n"+
                         "\t                      Thank you.                         \n"+NORM);
    return 1;
}

drop() { destruct(TO); return 1; }



