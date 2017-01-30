#include "../x.h"

inherit "obj/treasure";

static status lode;

string master;
string color;
string hi_ansi;
string lo_ansi;
static string tint;
int    energy;

void reset(status x)
{
 if(x || root()) return;
 set_id("focus crystal");
 set_alias("crystal");
 set_weight(1);
}

void set_color(string str)
{
 color = str;
 switch(color)
 {
  case "blue":   hi_ansi = HIB; lo_ansi = BLU; break;
  case "black":  hi_ansi = HIK; lo_ansi = BLK; break;
  case "yellow": hi_ansi = HIY; lo_ansi = YEL; break;
  case "green":  hi_ansi = HIG; lo_ansi = GRN; break;
  case "magenta":hi_ansi = HIM; lo_ansi = MAG; break;
  case "red":    hi_ansi = HIR; lo_ansi = RED; break;
  case "cyan":   hi_ansi = HIC; lo_ansi = CYN; break;
  case "white":  hi_ansi = HIW; lo_ansi = WHT; break;
 }
}

string query_name()
{
 return hi_ansi+"Focus Crystal"+NORM;
}

string short()
{
 return hi_ansi+"<"+lo_ansi+"["+hi_ansi+"+"+
        lo_ansi+"]"+hi_ansi+"> "+BOLD+"["+NORM+
        tint+BOLD+"]"+NORM;
}

int query_prevent_shadow()  /* i think this is right */
{
 return 1;
}

void long()
{
 write(hi_ansi+"\
The Focus Crystal is a multi-edged gemstone of\n\
impeccable craftsmanship, hewn from energy itself.\n\
It is "+NORM+tint+".\n");
}

void init()
{
 if(!lode && !root())
 {
  lode=1;
  TO->sap_energy();
 }
 ::init();
 add_action("cmd_shatter","shatter");
 add_action("cmd_charge","charge");
 add_action("cmd_energize", "energize");
}

void sap_energy()
{
 string old_tint;

 if(!ENVTO) return destruct(TO);
 if(energy > 0)
 {
 energy -= 2;

 switch(energy)
 {
  case 99999999..16000:
   tint = "wonderous";
   break;
  case 15999..13000:
   tint = "brilliant";
   break;
  case 12999..9000:
   tint = "glowing";
   break;
  case 8999..6000:
   tint = "sparkling";
   break;
  case 5999..3000:
   tint = "glimmering";
   break;
  case 2999..1000:
   tint = "faintly glowing";
   break;
  case 999..1:
   tint = "about to blink out";
   break;
  case 0:
   tint = "empty";
   break;
 }

 if(energy <= 0)
 {
  energy = 0;
  if(ENVTO->is_player())
   TL(ENVTO, "You must recharge the crystal at the Energizer.\n");
 }
 }
 call_out("sap_energy", 2);
}

int cmd_energize(string str)
{
 if(ENVTO != TP) return 0;
 if(!str || !id(str))
 {
  notify_fail("Usage: 'energize crystal'\n");
  return 0;
 }
 if(!ENVTP->NIMHENERGIZER())
 {
  write("You must go before the Energizer to properly\n"+
        "energize this crystal.\n");
  return 1;
 }

 write("You slide the "+query_name()+" firmly into the Energizer.\n");
 say((string)TP->QN+" slides a crystal into the Energizer.\n");

 ENVTP->set_crystal(master, energy, color, hi_ansi, lo_ansi);

 TR(ENVTP, "The Energizer puffs out a whisp of "+HIK+"smoke"+NORM+".\n");

 if(master == (string)TP->RN)
  write("\n\tYou have properly stored your "+query_name()+".\n\n");
 else
  write("\n\tYou have properly stored "+CAP(master)+"'s "+query_name()+".\n\n");

 destruct(TO);
 return 1;
}

int cmd_charge(string str)
{
 object ob;
 if(ENVTO != TP) return 0;
 if(!str || !(ob = present(str, ENVTP)) || !ob->is_corpse() 
    || !ob->short())
 {
  notify_fail("Usage: 'charge corpse'\n");
  return 0;
 }
 write("You place the "+query_name()+" upon "+
  (string)ob->short()+".\n");
 TR(ENVTP, (string)TP->QN+" places a crystal upon "+
  (string)ob->short()+".\n", ({ TP }));
 if((string)TP->RN == master && (energy > 0))
 {
  TR(ENVTP,"The crystal reverberates gently.\n");
  energy += (int)ob->heal_value();
 }
 else
 {
  TR(ENVTP, "Nothing happens.\n");
 }
 TR(ENVTP, (string)ob->short()+" disappears.\n");
 write("You pick up the "+query_name()+".\n");
 TR(ENVTP, (string)TP->QN+" picks up the crystal.\n");
 destruct(ob);
 return 1;
}

int cmd_shatter(string str)
{
 if(ENVTO != TP || !str) return 0;
 if(id(str))
 {
  write("Are you positive you wish to destroy this Crystal?\n"+
        "Doing so would cripple its master, "+
        (master==(string)TP->RN?"YOU":CAP(master))+"!\n");
  write("<y/n> ");
  input_to("ok_shatter");
  return 1;
 }
}

int ok_shatter(string str)
{
 if(str != "y")
  return 1;
 else
 {
  object ob, oc;
  write(BOLD + "\n* * * You shatter the Focus Crystal ! * * *\n\n" + NORM);
  tell_room(ENVTP, (string)TP->QN+" shatters a crystal.\n");
  tell_room(ENVTP,
  hi_ansi+"\n\t\
<<< Magical Shockwaves leap from the Crystal remnants! >>>\n\n"+NORM);
  ob = first_inventory(ENVTP);
  while(ob)
  {
   oc = next_inventory(ob);
   if(living(ob))
    ob->hit_player(100+random(100), "magical");
   ob = oc;
  }
  master = 0;
  destruct(TO);
  return 1;
 }
}


void set_master(string x) { master = x; }
void set_energy(int x)    { energy = x; }
void set_hi_ansi(string x) { hi_ansi = x; }
void set_lo_ansi(string x) { lo_ansi = x; }

string query_master() { return master;  }
string query_color()  { return color;   }
string query_hi_ansi(){ return hi_ansi; }
string query_lo_ansi(){ return lo_ansi; }
string query_tint()   { return tint;    }
int    query_energy() { return energy;  }

