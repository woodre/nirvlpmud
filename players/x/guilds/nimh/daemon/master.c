#include "../x.h"

static object *rats;
string *banned;
static object *holes;

inherit N_EFUN;

void reset(status x)
{
 if(x) return;
 holes = ({ });
 rats = ({ });
 call_out("autosave", 1800);
 banned = ({ "jenner","justin","nicodemus","brutus","timmy",
              "frisbee","frisby","sarah","sara","brisby","brisbee",
              "jonathan","johnathan","mrages","ages","jeremy","dragon",
              "fitzgibbons","fitzgibbon","sullivan"}); /* all chars from nimh */
}

void add_rat(object ob) { rats += ({ ob }); }

void delete_rat(object ob)
{
 int x;
 if((x = member_array(ob, rats)) > -1)
  rats -= ({ ob });
}

object * query_rats() { return rats; }

status query_rat(object ob)
{
 return (member_array(ob, rats) > -1);
}

status is_feline(object ob)
{
 if(present("feline_obj",ob) || ob->id("bobcat") ||
    ob->id("cheetah") || ob->id("cat") || ob->id("cougar") ||
    ob->id("grimalkin") || ob->id("jaguar") || ob->id("kitten") ||
    ob->id("kitty") || ob->id("leopard") || ob->id("lion") ||
    ob->id("lynx") || ob->id("malkin") || ob->id("mouser") ||
    ob->id("ocelot") || ob->id("panther") || ob->id("puma") ||
    ob->id("puss") || ob->id("pussy") || ob->id("tabby") ||
    ob->id("tiger") || ob->id("tomcat"))
  return 1;
}

void feline_sense(object gob, object play)
{
 int    s, *nums;
 int f_flag;
 object ob, oc, *fp;
 string output;

 if(!(fp=(object*)gob->query_felines_present()) || !sizeof(fp))
  fp = ({ });
 else f_flag = 1;

 nums = ({ });
 s = sizeof(fp);

 while(s--)
  if(!objectp(fp[s]) || !present(fp[s], ENV(play)))
   nums += ({ s });

 s = sizeof(nums);

 while(s--)
 {
  if(sizeof(fp) <= 1) fp = ({ });
  else fp -= ({ fp[nums[s]] });
 }

 ob = first_inventory(ENV(play));

 output = "";
 while(ob)
 {
  oc = next_inventory(ob);
  if(living(ob) && is_feline(ob) && ob->short() &&
   member_array(ob, fp) == -1)
  {
    output += "   !!! "+CAP((string)ob->short())+" !!!\n";
   fp += ({ ob });
  }
  ob = oc;
 }

  if(strlen(output))
  {
    TL(play, HIR+"\
\n       [ FELINE SENSE ]\n"+NORM);
    TL(play, output+"\n");
    if(!play->query_invis() || !play->short())
     TR(ENV(play),(string)play->QN+"'s ears perk up!\n",({play}));
     if(!random(3))
      TR(ENV(play),(string)play->QN+" wiggles "+possessive(play)+" nose.\n",({play}));
  }
 if(!sizeof(fp) && f_flag)
  TL(play, HIB+"\n\
[FELINE SENSE]"+NORM+": No current threat.\n");

 gob->set_felines_present(fp);
}

status ok_name(string nm) {
 return (member_array(nm, banned) == -1);
}

varargs status broadcast(string msg, status flag)
{
 if(!rats || !sizeof(rats))
  return 0;
 if(msg)
 {
  int    x, y, z;
  object rat, gob;
  string me;
  me = (string)TP->QN;
  if(flag)
   msg = HIY+"*"+NORM+msg+"\n";
  else if(msg[0] == ':')
   msg = HIG+"*"+HIC+me+" "+NORM+msg[1..strlen(msg)-1]+"\n";
  else if(msg[0] == '>')
   msg = HIM+"*"+NORM+msg[1..strlen(msg)-1]+" <"+HIC+me+NORM+">\n";
 else
   msg = HIR+"*"+HIC+me+":"+NORM+" "+msg+"\n";
  y = sizeof(rats);
  for(x = 0; x < y; x ++)
   if(rat=rats[x])
   {
    if(rat == TP) z = 1;
    tell_object(rat, "\n  "+msg);
   }
   if(!z) write("\n  "+msg);
  return 1;
 }
}

void autosave()
{
 int s;
 s = sizeof(rats);
 while(s--)
  if(rats[s] && interactive(rats[s]))
  {
   TL(rats[s], HIW+"Autosaving...\n"+NORM);
   command("save", rats[s]);
  }
 call_out("autosave", 1800);
}

object * query_holes() { return holes; }
void add_hole(object x)
{
 if(member_array(x, holes) == -1)
  holes += ({ x });
}
void delete_hole(object x)
{
 int y;
 if((y = member_array(x, holes)) > -1)
  holes -= ({ holes[y] });
}

status query_hole(object x)
{
 return (member_array(x, holes) > -1);
}

status is_rat(object ob)
{
 return (ob && living(ob) && ob->is_player() && (string)ob->query_guild_name() == GUILDNAME);
}
