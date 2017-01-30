/* woo.c
  Alternative to people
  Lets you select which stats you wish to see
  "woo help" has a list of options
*/
#include "/players/vital/closed/headers/vital.h"
#include <ansi.h>

#define is_arg(str) (str == "ip" || str == "h" || str == "lev" || str == "xlev" \
|| str == "xlev" || str == "age" || str == "env" || str == "room" || str == "pk" \
|| str == "pty" || str == "hp" || str == "sp" || str == "xp" || str == "cash" || \
str == "gn" || str == "gr" || str == "gx" || str == "gf" || str == "atk" || str \
== "aatk" || str == "weap" || str == "wc" || str == "ac" || str == "ix" || str == \
"stf" || str == "soak" || str == "invs")
 
#define DEFAULT ({"ip","age","lev","env"})
#include "/players/vital/closed/headers/vital.h"
 
mapping pstat, aligns, header;
string color;
int x;
 
cmd_woo(str) { return woo(str); }

main(str) {
    string line,*args,*argc;
    string *custom,ctmp;
    object u,us;
    int i, so,ui,uso,num_users, mylev;
    int ci,cso;
    status do_format;
    x = (random(13)+1);
    switch(x) {
        case 1: color = RED; break;
        case 2: color = YEL; break;
        case 3: color = GRN; break;
        case 4: color = BLU; break;
        case 5: color = CYN; break;
        case 6: color = MAG; break;
        case 7: color = HIR; break;
        case 8: color = HIY; break;
        case 9: color = HIG; break;
        case 10: color = HIB; break;
        case 11: color = HIC; break;
        case 12: color = HIM; break;
        case 13: color = HIW; break;
    }
    if(this_player()->query_level() < 20) return 0;
    if(str == "help") return print_help();
    args = ({ });
    custom = ({ });
    args += ({ "name" });
    if(str == "" || !str) args += DEFAULT;
    else {
        argc = explode(str, " ");
        for(i = 0, so = sizeof(argc); i < so; i++) {
            if(argc[i] == "D") args += DEFAULT;
            else if(sscanf(argc[i], "[%s]", ctmp)) {
                custom += ({ ctmp });
               ctmp = 0;
            }
            else if(is_arg(argc[i])) args += ({ argc[i] });
            else
            write("Illegal arg: "+argc[i]+"\n");
        }
    }
    mylev = this_player()->query_level();
    for(ui = 0, uso = sizeof(u = users()), num_users = 0; ui < uso; ui++) {
        if(u[ui]->query_invis() < 55 || mylev > u[ui]->query_level())
        num_users++;
    }
    write("There are currently "+num_users+" users.\n");
    line = ""; 
    cso = sizeof(custom);
    for(i = 0, so = sizeof(args); i < so; i++) {
        line += header[args[i]];
        if(i != so-1 || cso > 0) line += " ";
    }
    if(cso) {
        for(ci = 0; ci < cso; ci++) {
            line += "["+custom[ci]+"]";
            if(ci != cso-1) line += " ";
        }
    }
    if(strlen(line) > 80) {
        do_format = 1;
       line = format(line);
    }
    write(line+"\n");
    write(color+pad("",80,'-')+NORM+"\n");
    for(ui = 0; ui < uso; ui++) {
        us = u[ui];
        if(us->query_invis() > 55 && us->query_level() > mylev) continue;
        line = "";
        for(i = 0; i < so; i++) {
            line += add_portion(us, args[i]);
            if(i != so-1 || cso) line += " ";
        }
        for(ci = 0; ci < cso; ci++) {
            line += call_other(us, "query_"+custom[ci]);
            if(ci != cso-1) line += " ";
        }
        if(do_format) line = format(line);
        write(line+"\n");
    }
    write("\n"+color+pad("",80,'-')+NORM+"\n");
    write("Symbols:  . - idle  @ - ghost  # - invis  * - editing\n");
    return 1;
}

reset(arg) {
    if(arg) return ;
    pstat = (["h":"query_hostname","lev":"query_level",
"xlev":"query_extra_level","xp":"query_exp","cash":"query_money","gn":
"query_guild_name","gr":"query_guild_rank","gx":"query_guild_exp","gf":
"query_guild_file","wc":"query_wc","ac":"query_ac","ix":"query_intoxination",
"stf":"query_stuffed","soak":"query_soaked","invs":"query_invis"]);
    aligns = (["h":25,"lev":-8,"xlev":-8,"xp":-8,"cash":-6,"gn":10,"gr":-5,
"gx":-8,"gf":30,"wc":-2,"ac":-2,"ix":-2,"stf":-3,"soak":-3,"invs":-3]);
    header = (["ip":"    Address    ","h":"        Hostname         ","lev":" Level ",
"xlev":"Ex. Lev.","age":"Age","env":"  Location                   ","room":
"  Room                        ","pk":"Pk ","pty":"Pty","hp":" HP/MHP","sp":
" SP/MSP","xp":"  Exp.  ","cash":" Money  ","gn":"Guild Name","gr":"GRank",
"gx":"Guild XP","gf":"          Guild File          ","atk":"  Attack Name  ",
"aatk":"Alt Attack Name","weap":"Weap. Name","wc":"WC","ac":"AC","ix":"IX",
"stf":"STF","soak":"SOA","invs":"Inv","idle":"Idl","name":"  Name         "]);
}

print_help() {
    int i,so;
    write("Options:\n");
    write("D      -Print all default options\n");
    write("ip     -Print ip #'s\n");
    write("h      -Print hostnames\n");
    write("lev    -Print levels\n");
    write("xlev   -Print extra levels\n");
    write("age    -Print brief age\n");
    write("env    -Print environment filename\n");
    write("room   -Print environment short\n");
    write("pk     -Print player killer status\n");
    write("pty    -Print party status\n");
    write("hp     -Print hp/maxhp\n");
    write("sp     -Print sp/maxsp\n");
    write("xp     -Print xp\n");
    write("cash   -Print money\n");
    write("gn     -Print guild name\n");
    write("gr     -Print guild rank\n");
    write("gx     -Print guild xp\n");
    write("gf     -Print guild file\n");
    write("atk    -Print attack name\n");
    write("aatk   -Print alt attack name\n");
    write("weap   -Print weapon name\n");
    write("wc     -Print weapon class\n");
    write("ac     -Print armor class\n");
    write("ix     -Print intox\n");
    write("stf    -Print stuffed\n");
    write("soak   -Print soaked\n");
    write("invs   -Print invis level\n");
    write("idle   -Print idle time\n");
    write("[f]    -Display return of function query_f\n");
    write("Defaults:\n");
    for(i = 0, so = sizeof(DEFAULT); i < so; i++)
      write(" "+DEFAULT[i]);
      write("\n");
    return 1;
}

add_portion(user, arg) {
    string out;
    int x;
    object o;
    if(arg == "idle") {
        x = query_idle(user);
        if(!x) out = "    ";
        else if(x < 60) out = pad(x+"s", -3);
        else out = pad((x/60)+"m", -3);
    } else if(arg == "name") {
        out = capitalize(user->query_real_name());
        if(query_idle(user) > 120) out = "."+out;
        if(user->query_ghost()) out = "@"+out;
        if(in_editor(user)) out = "*"+out;
        if(user->query_invis()) out = "#"+out;
        out = pad(out, 15);
    } else if(arg == "ip") {
        out = pad(query_ip_number(user), 15);
    } else if(arg == "env" || arg == "room") {
        if(o = environment(user)) 
        out = pad((arg=="env"?file_name(o):o->short()), 30);
        else out = pad("location unknown", 30);
    } else if(arg == "pk") {
        out = pad((user->query_pl_k() ? "Yes":"No"), 3);
    } else if(arg == "pty") {
        out = pad((present("party object",user)?"Yes":"No"), 3);
    } else if(arg == "atk") {
        if(o = user->query_attack()) out = pad(o->query_name(), 15);
        else
        out = pad("Not fighting", 15);
    } else if(arg == "aatk") {
        if(o = user->query_alt_attack())
        out = pad(o->query_name(), 15);
        else 
        out = pad("Not fighting", 15);
    } else if(arg == "weap") {
        if(o = user->query_weapon())
        out = pad(o->query_name(), 10);
        else
        out = pad("No weapon", 10);
    } else if(arg == "hp") {
        if(user->query_level() > 20) out = pad("Wizard",-7);
        else out = pad(user->query_hp(), -3)+"/"+pad(user->query_mhp(), -3);
    } else if(arg == "sp") {
        if(user->query_level() > 20) out = pad("Wizard",-7);
        else out = pad(user->query_sp(), -3)+"/"+pad(user->query_msp(), -3);
    } else if(arg == "age") {
        x = user->query_age();
        if(x/43200) out = pad((x/43200)+"d", -3);
        else if(x/1800) out = pad((x/1800)+"h", -3);
        else if(x/30) out = pad((x/30)+"m", -3);
        else out = pad((x*2)+"s", -3);
    } else {
        out = call_other(user, pstat[arg]);
        out = pad(out, aligns[arg]);
    }
    return out;
}
