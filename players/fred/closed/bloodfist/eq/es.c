inherit "/obj/weapon.c";
#include "/players/zeus/closed/all.h"
#define ES +BOLD+BLK+"Der EngelSense"+NORM+
object you;
#define ME capitalize((string)you->query_name())
int wear, a, b, funcd;
string *hits1, *hits2;  /* combat msgs */

reset(arg) {
  ::reset(arg);
  if (arg) return;

  funcd = 0;
  set_name("der engelsense");
  set_alias("scythe");
  set_short(BOLD+BLK+"Der EngelSense"+NORM);
  set_type("polearm");
  set_value(3429);
  set_weight(4);
  set_class(18);
  set_hit_func(this_object());

  message_hit=({
    "plunged "ES" into"," bringing blood gushing forth",
    "tore open"," with a brutal blow from "ES"",
    "ripped into"," with "ES" grazing bone",
    "slashed open"," with "ES" drawing blood",
    "slashed"," with "ES"",
    "cut"," with "ES"",
    "grazed"," with "ES"",
    "missed","",
  });
}

id(str){ return str == "scythe" || str == "engelsense" ||
                str == "der engelsense"; }

query_dest_flag(){    return 1; }

long(){
  wear = ::query_wear();
  if(wear > 99)
  {
    long_desc = 
"The legendary scythe EngelSense.  The handle of the weapon is a solid\n"+
"piece of dark wood, however bands of a lighter wood almost appear to\n"+
"be woven into it.  Running all along the handle are detailed carvings,\n"+
"many of which depict angels wielding scythes such as this.  You can see\n"+
"places on the handle where it is beginning to wear from use.  The blade\n"+
"of the weapon is very long, almost excessively so.  The edge of the\n"+
"blade is tapered and jagged.  Looking at it closely bits of flesh can\n"+
"be seen clinging to it.  Etched into both sides of the blade is an\n"+
"unfamiliar symbol.  Spatters of blood mar the flawless weapon.\n"+
"Nevertheless, EngelSense truly is a captivating weapon.\n";
  }
  else
  {
    long_desc =
"The legendary scythe EngelSense.  The handle of the weapon is a solid\n"+
"piece of dark wood, however bands of a lighter wood almost appear to\n"+
"be woven into it.  Running all along the handle are detailed carvings,\n"+
"many of which depict angels wielding scythes such as this.  The blade\n"+
"of the weapon is very long, almost excessively so.  The edge of the\n"+
"blade is tapered and jagged.  Etched into both sides of the blade is\n"+
"an unfamiliar symbol.  EngelSense truly is a captivating weapon.\n";
  }
  ::long();
}

weapon_class()  /* true wc based on wear */
{
  wear = ::query_wear();
  if(wear > 399)                 /* well worn */
    return 10;
  if(wear > 199 && wear < 400)   /* worn */
    return 14;
  if(wear > 99 && wear < 200)    /* somewhat worn */
    return 18;
  if(wear > 39 && wear < 100)    /* a little worn */
    return 19;
  if(wear < 40)                  /* like new */
    return 20;
}

void define_arrays()
{
  funcd = 1;
  hits1 =({
    ME+" spins with "ES" extended.\n",
    ME+" spins with "ES", slashing in an upwards arc.\n",
    ME+" spins with "ES", slashing in a downwards arc.\n",
    ME+" steps forward, swinging "ES" through the air.\n",
    ME+" steps backward, swinging "ES" defensively.\n",
    ME+" leaps backward defensively.\n",
    ME+" rolls to the left, slashing low through the air.\n",
    ME+" rolls to the right, slashing low through the air.\n",
    ME+" slashes with "ES" arcing through the air.\n",
    ME+" rips "ES" violently through the air.\n",
    ME+" gracefully spins, slashing with "ES".\n",
    ME+" cuts upward through the air with "ES".\n",
    ME+" dances gracefully with "ES" extended.\n",
  });

  hits2 =({
    "You spin with "ES" extended.\n",
    "You spin with "ES", slashing in an upwards arc.\n",
    "You spin with "ES", slashing in a downwards arc.\n",
    "You step forward, swinging "ES" through the air.\n",
    "You step backward, swinging "ES" defensively.\n",
    "You leap backward defensively.\n",
    "You roll to the left, slashing low through the air.\n",
    "You roll to the right, slashing low through the air.\n",
    "You slash with "ES" arching through the air.\n",
    "You rip "ES" violently through the air.\n",
    "You gracefully spin, slashing with "ES".\n",
    "You cut upward through the air with "ES".\n",
    "You dance gracefully with "ES" extended.\n",
  });
}

int weapon_hit(object v){
  if(!v) return 0; /* added by v */
  you = environment();
  if(!funcd) define_arrays();
  a = random(sizeof(hits1));
  b = random(15);
  tell_room(environment(you), hits1[a], ({ ENV }));
  tell_object(environment(), hits2[a]);

  switch(b)
  {
  case 0..2:
    tell_room(environment(you), ME+
      " dances swiftly...\n\n"+ME+
      " flies up from beneath "+v->QN+" slashing in a broad arc!\n"+
      RED+"\tA spray of blood fills of the air.\n\n"+NORM, ({ you }));
    tell_object(environment(), "You dance swiftly...\n\n"+
      "You fly up from beneath "+v->QN+" slashing in a broad arc!\n"+
      RED+"\tA spray of blood fills the air.\n\n"+NORM);
    return 2;
    break;
  case 3:
    tell_room(environment(you), 
      ME+" spins with "ES" extended...\n\n"+BOLD+BLK+
      "The blade rips through "+v->QN+
      " as blood spurts onto the ground.\n\n"+NORM, ({ you }));
    tell_object(environment(),
      "You spin with "ES" extended...\n\n"+BOLD+BLK+
      "The blade rips through "+v->QN+
      " as blood spurts onto the ground.\n\n"+NORM);
    return 1;
    break;
  case 4:
    tell_room(environment(you), RED+
      "Blood"+NORM+" drips from "ES" onto the ground.\n"+NORM,
      ({ you }));
    tell_object(environment(), RED+
      "Blood"+NORM+" drips from "ES" onto the ground.\n"+NORM);
    break;
  case 5:
    tell_room(environment(you), "\nAs "+
      ME+" swings "ES" through the air... \n\t\t\t\t\t"+
      RED+"Blood splatters everywhere!\n\n"+NORM, ({ you }));
    tell_object(environment(),
      "\nAs you swing "ES" through the air... \n\t\t\t\t\t"+
      RED+"- Blood splatters everywhere! -\n\n"+NORM);
    break;
  case 6..15:
    break;
  }
  return 1;
}


