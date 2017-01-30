/*
//     a new monster.c to inherit
//     [v] 2001
//    ~  For a rundown of everything included, ask
//    ~  for a copy of the documentation.
//
// 07/04/06 Earwax: made it so mobs will wander 3 times, then stop
// if they haven't come in contact with a player before that point.
// Having 100 mobs or more all wandering the entire length of a 
// reboot is eating entirely too many resources needlessly.
*/

/* 07/04/06 Earwax: OMFG what the fuck is this bullshit, fuck using
 * weak_types, there is no fucking need here, someone remind me to
 * fix this shit.  Using weak_types is quite possibly the single 
 * biggest thing fucking this mud right now.
 */
#pragma weak_types

#define TIMESWANDEREDLIMIT 3

inherit "/obj/monster";

/* Global Variables */
int TimesWandered; /* track how many times we wandered */
mixed *WanderInfo; /* Save the parameters for wandering */


#define WEPSHAD "/players/vertebraker/closed/std/offwield"

mapping Attributes, Wimpy, Aggressive, Alliance;

#if 0 /* Rumplemintz */
object OffwieldShadow;
#endif

void wander_away(mixed *data);
void CallForHelp(int c);

mixed
basename(object ob)
{
    string a, b;
    if(!ob) return;
    sscanf(file_name(ob), "%s#%s", a, b);
    return a;
}

void
set_aggro(int flag, int perc, int chance)
{
    Aggressive["flag"] = flag;
    Aggressive["health"] = perc;
    Aggressive["chance"] = chance;
}

void
load_stats(int tmpWc, int tmpAc, int tmpHp)
{
   set_wc(tmpWc);
   set_ac(tmpAc);
   set_hp(tmpHp);
}

void
load_default_attribs(int tmp)
{
    Attributes = ([ "str" : tmp,
                    "mag" : tmp,
                    "luc" : tmp,
                    "sta" : tmp,
                    "pie" : tmp,
                    "int" : tmp,
                    "wil" : tmp,
                    "ste" : tmp ]);
}

void
set_level(int tmp)
{
    int z, tmpAc;
    ::set_level(tmp);
    if((tmp > 0) && (tmp < 15))
    {
      if(tmp == 1 || tmp == 2)
        tmpAc = 3;
      else if(tmp == 3 || tmp == 4)
        tmpAc = 4;
      else if(tmp == 5 || tmp == 6)
        tmpAc = 5;
      else if(tmp == 7)
        tmpAc = 6;
      else if(tmp == 8 || tmp == 9)
        tmpAc = 7;
      else if(tmp == 10)
        tmpAc = 8;
      else if(tmp == 11 || tmp == 12)
        tmpAc = 9;
      else if(tmp == 13)
        tmpAc = 10;
      else if(tmp == 14)
        tmpAc = 11;
      load_stats((4 + tmp), (tmpAc), (tmp * 15));
    }
    else if((tmp > 14) && (tmp < 21))
    {
      z = (20 - (tmp));
      load_stats((30 - (z * 2)), (17 - z), (500 - (50 * z)));
    }
    else if(tmp == 21)
      load_stats(34, 19, 600);
    else if((tmp > 21) && (tmp < 26))
    {
      z = (25 - (tmp));
      load_stats((44 - (z * 2)), (23 - z), (1000 - (100 * z)));
    }
    else if(tmp == 26)
      load_stats(46, 24, 1200);
    else if(tmp == 27)
      load_stats(48, 25, 1500);
    else if(tmp == 28)
      load_stats(52, 26, 1800);
    else if(tmp == 29)
      load_stats(55, 28, 2000);
    else if(tmp == 30)
      load_stats(60, 30, 2500);
    load_default_attribs(tmp);
    return;
}

void
query_attrib(string str)
{
    string *k;
    int x;

    k = keys(Attributes);


    if((x = member_array(str, k)) == -1)
      return 0;

    else return Attributes[k[x]];
}

void
init()
{
    if ( present("GlobalPlayerId", this_object()) )
    {
      if (find_call_out("wander_away") && WanderInfo && sizeof(WanderInfo))
        call_out("wander_away", WanderInfo[0], ({ WanderInfo[0], WanderInfo[1], WanderInfo[2] }));
      TimesWandered = 0;
    }
    if(!this_object()) return;
    ::init();
    if(!this_object()) return;
#if 0 /* Rumplemintz */
 if(this_player() == this_object())
    add_action("cmdOffwield","offwield");
#endif
}

#if 0 /* Rumplemintz */
mixed
cmdOffwield(string str)
{
    object a;

    if(this_player() != this_object()) return 0;
    a = present(str, this_object());

    if(!this_player() || (this_player() == this_object()) ||
       ((int)this_player()->query_level() > 19))
    {
      OffwieldShadow = clone_object(WEPSHAD);
      OffwieldShadow->start_shadow(a);
      offwield(a);
    }

    return 1;
}

object
query_offwielding()
{
    return second_weapon;
}

/* mixed */
void /* Rumplemintz */
stop_offwielding()
{
    ::stop_offwielding();
    if(!second_weapon && OffwieldShadow)
      OffwieldShadow->end_shadow();
}
#endif

void
reset(int arg)
{
    if(arg) return;
    ::reset();
#if 0 /* Rumplemintz */
    add_action("cmdOffwield","offwield");
#endif

    Attributes = ([ "str" : 1, "mag" : 1, "wil" : 1, "int" : 1, 
                    "pie" : 1, "ste" : 1, "luc" : 1, "sta" : 1 ]);
    Wimpy = ([ ]);
    Aggressive = ([ ]);
    Alliance = ([ ]);
}

status
set_attrib(string str, int amt)
{
    if(Attributes[str])
    {
      Attributes[str] = amt;
      return 1;
    }
    return 0;
}

void
set_wimpy(int health, int chance, string preferred, string msg)
{
    Wimpy["health"] = health;
    Wimpy["chance"] = chance;
    Wimpy["direct"] = preferred;
    Wimpy["msg"] = msg;
}

void
WimpyOut()
{
    int x;
    string *dd;
    object EnvOb;
    
    dd = (mixed)environment()->query_dest_dir();
    
    x = random(sizeof(dd));
    if(Wimpy["msg"])
      tell_room(environment(), Wimpy["msg"]);    
    else if(cap_name)
      tell_room(environment(),
        cap_name + " runs away...\n");
    EnvOb = environment();
    EnvOb->init();
    command(dd[x]);
    if(EnvOb == environment()) command(dd[x + 1]);
}

set_wander(int beats, int cflag, string *blocked_dirs)
{
    if(!blocked_dirs) blocked_dirs = ({ "meaty" });
    WanderInfo = ({ beats, cflag, blocked_dirs });
    call_out("wander_away", beats, 
      ({ beats, cflag, blocked_dirs }));
}

void
wander_away(mixed *data)
{
    int beats, combat, i, z, a, c;
    string *blocked_dirs, *aval, *dump, tmp, cmd;

    TimesWandered++;
    if (!present("GlobalPlayerId", this_object()) && TimesWandered > TIMESWANDEREDLIMIT)
      return;
    beats = data[0];
    combat = data[1];
    blocked_dirs = data[2];

    if(!combat && attacker_ob) return;


    if(!environment()) return;
    aval = (mixed)environment()->query_dest_dir();

    if(!aval || !sizeof(aval))
    {
      random_move();
      return;
    }
    
    dump = ({ });
    for(z = 0; z < sizeof(aval); z ++)
      if(stringp(aval[z]))
      if(!sscanf(aval[z], "%s/%s", tmp, tmp) &&
          member_array(aval[z], blocked_dirs) == -1)
        dump += ({ aval[z] });

    a = random(sizeof(dump));
    cmd = dump[a];
    environment()->init();
    command("" + cmd + "", this_object());

    while(remove_call_out("wander_away") != -1);
    call_out("wander_away", beats, ({ beats, combat, blocked_dirs }));
}

void
AttackAny()
{
    int x;
    object *Objects;

    Objects = all_inventory(environment());

    for(x = 0; x < sizeof(Objects); x ++)
    {
      if((status)Objects[x]->is_player() && interactive(Objects[x]))
      {
        attack_object(Objects[x]);
        return;
      }
    }
}

void
init_aggressive()
{
    int x;
    object *Objects;

    Objects = all_inventory(environment());

    if(Aggressive["chance"] >= random(101))
    {

      for(x = 0; x < sizeof(Objects); x ++)
        if((status)Objects[x]->is_player())
        if(Aggressive["health"] >  
            (((int)Objects[x]->query_hp() * 100) /
             ((int)Objects[x]->query_mhp())))
          if((status)Objects[x]->is_player() &&
            (interactive(Objects[x])))
          {
            attack_object(Objects[x]);
            return;
          }
 
      if(!attacker_ob) 
        AttackAny();
    }
}    

void
heart_beat()
{
    object EnvOb;

    if(!environment()) return;

    if(attacker_ob) 
    {
      if(function_exists("get_spell_mess1", this_object()))
        spell_mess1 = (string)this_object()->get_spell_mess1();
      if(function_exists("get_spell_mess2", this_object()))
        spell_mess2 = (string)this_object()->get_spell_mess2();
    }
    ::heart_beat();

    if(!environment()) return;
    if(attacker_ob && present(attacker_ob, environment()))
      if((Wimpy["health"] >= ((hit_point * 100) / max_hp)) &&
       (Wimpy["chance"] && (Wimpy["chance"] > random(100))))
      {
        EnvOb = environment();
        if(Wimpy["direct"])
          command(Wimpy["direct"], this_object());
        if(environment() == EnvOb)
          WimpyOut();
      }
     
    if(!attacker_ob && Aggressive["flag"])
      init_aggressive();
     
}

void
set_assist(string path, int beats, int atatime, int total)
{

    if(path[strlen(path) - 2.. strlen(path) - 1] == ".c")
      path = path[0..strlen(path) - 3];
    if(path[0] == '/')
      path = path[1..strlen(path) - 1];

    Alliance["path"] = path;
    Alliance["beats"] = beats;
    Alliance["now"] = atatime;
    Alliance["total"] = total;

    if(!beats) Alliance["beats"] = 1;

    while(remove_call_out("CallForHelp") != -1);
    call_out("CallForHelp", beats, 0);
}

void
CallForHelp(int count)
{
    int x, local_cnt;
    object Ob, *obs;

    if(sizeof(Alliance) && count >= Alliance["total"])
      return;
    if(sizeof(Alliance) && environment() && 
       Alliance["total"])
    {
      obs = all_inventory(environment());
    
      for(x = 0; x < sizeof(obs); x ++)  
        if(basename(obs[x]) == Alliance["path"]) 
          local_cnt ++;
    
      if(Alliance["now"] && (local_cnt < Alliance["now"]))
      {
        Ob = clone_object(Alliance["path"]);
        move_object(Ob, environment());
        if(function_exists("answer_assist", Ob))
          Ob->answer_assist(this_object());
        count ++;
      }
    }

    if(!Alliance["beats"]) Alliance["beats"] = 1;

    while(remove_call_out("CallForHelp") != -1);
    call_out("CallForHelp", Alliance["beats"], count);
}

long() {
    if (desc_ob) {
        call_other(desc_ob,"monster_long",0);
        return;
    }

/* aoooo
if (gender)
    write(short_desc + " ("+gender+")\n");
*/
    write (long_desc);
    if(hit_point < max_hp/10) {
      write(cap_name+" is in very bad shape.\n");
      return;
    }
    if(hit_point < max_hp/5) {
      write(cap_name+" is in bad shape.\n");
      return;
    }
    if(hit_point < max_hp/2) {
      write(cap_name+" is somewhat hurt.\n");
      return;
    }
    if(hit_point < max_hp - 20) {
      write(cap_name+" is slightly hurt.\n");
      return;
    }
    write(cap_name+" is in good shape.\n");
}

object
load()
{
    return this_object();
}
