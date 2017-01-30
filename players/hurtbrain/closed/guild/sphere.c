inherit "obj/monster";

object here;
string com_str;
int flag;

reset(arg){
   ::reset(arg);
   if(arg) return;
        set_race("undead");
        set_hp(10000);
        set_long("You are hidden in your soul! A sphere protects you.\n") ;
	set_name("sphere");
        set_ac(10000);
        set_al(0);
        set_wc(0);
        set_level(1);
        enable_commands();
        here=this_object();
        call_out("fol",1);
}

init()  {
    /*
    ::init();
    if(play->environment()!=here) 
    {
       tell_object(play,"hey <"+play->environment()->short()+">\n");
       return 1;
    }
    */
    set_heart_beat(1);
    flag=0;
    add_action("drop"); add_verb("drop");
    add_action("look"); add_verb("look");
    add_action("look"); add_verb("l");
    add_action("examine"); add_verb("examine");
    add_action("examine"); add_verb("exa");
    add_action("examine"); add_verb("la");
    add_action("go_up"); add_verb("u");
    add_action("go_down"); add_verb("d");
    add_action("go_north"); add_verb("n");
    add_action("go_south"); add_verb("s");
    add_action("go_west"); add_verb("w");
    add_action("go_east"); add_verb("e");
    add_action("go_northwest"); add_verb("nw");
    add_action("go_northeast"); add_verb("ne");
    add_action("go_southwest"); add_verb("sw");
    add_action("go_southeast"); add_verb("se");
}

drop(str)  {
if(str=="a_pass")  {
        flag=1;
        return 1;
        }
        if(!flag)
                {
                write("You can't drop anything here!\n");
                return 1;
                }
        return 0;
        }

set_com(str)  { com_str=str; return 1; }

go_north() {
    environment(here)->set_com("gimme_what");
    command("north",find_living("morph_"+here->query_info())); 
    return 1;
}

go_south() {
    environment(here)->set_com("gimme_what");
    command("south",find_living("morph_"+here->query_info()));
    return 1;
}

go_east() {
    environment(here)->set_com("gimme_what");
    command("east",find_living("morph_"+here->query_info()));
    return 1;
}

go_west() {
    environment(here)->set_com("gimme_what");
    command("west",find_living("morph_"+here->query_info()));
    return 1;
}

go_northwest() {
    environment(here)->set_com("gimme_what");
    command("northwest",find_living("morph_"+here->query_info()));
    return 1;
}

go_northeast() {
    environment(here)->set_com("gimme_what");
    command("northeast",find_living("morph_"+here->query_info()));
    return 1;
}

go_southwest() {
    environment(here)->set_com("gimme_what");
    command("southwest",find_living("morph_"+here->query_info()));
    return 1;
}

go_southeast() {
    environment(here)->set_com("gimme_what");
    command("southeast",find_living("morph_"+here->query_info()));
    return 1;
}

go_up() {
    environment(here)->set_com("gimme_what");
    command("up",find_living("morph_"+here->query_info()));
    return 1;
}

go_down() {
    environment(here)->set_com("gimme_what");
    command("down",find_living("morph_"+here->query_info()));
    return 1;
}

examine(str) {
    return look("at " + str);
}

look(str) {
    object ob, ob_tmp;
    string item,it;
    int max;
    if (!str) {
        call_other(environment(find_living("morph_"+here->query_info())), "long");
        ob = first_inventory(environment(find_living("morph_"+here->query_info())));
        max = 20;
        while(ob && max > 0) {
            if (ob != find_living("morph_"+here->query_info())) {
                string short_str;
                short_str = call_other(ob, "short");
                if (short_str) {
                    max -= 1;
                    write(short_str + ".\n");
                    it = short_str;
                }
            }
            ob = next_inventory(ob);
        }
        return 1;
    }
    if (sscanf(str, "at %s", item) == 1 || sscanf(str, "in %s", item) == 1) {
        item = lower_case(item);
        ob = present(item, find_living(here->query_info()));
        if (!ob)
            ob = present(item,environment(find_living("morph_"+here->query_info())));
        if (!ob)  {
            tell_object(find_living(here->query_info()),"There is no " + item + " here.\n");
            return 1;
        }
        it = item;
        call_other(ob, "long", item);
        if (!call_other(ob, "can_put_and_get", item))
            return 1;
        if (living(ob)) {
            object special;
            special = first_inventory(ob);
            while (special) {
                string extra_str;
                extra_str = call_other(special, "extra_look");
                if (extra_str)
                    tell_object(find_living(here->query_info()),extra_str + ".\n");
                special = next_inventory(special);
            }
        }
        ob_tmp = first_inventory(ob);
        while (ob_tmp && call_other(ob_tmp, "short") == 0)
            ob_tmp = next_inventory(ob_tmp);
        if (ob_tmp) {
            if (living(ob))
                tell_object(find_living(here->query_info()),"\t" + capitalize(item) + " is carrying:\n");
            else
                tell_object(find_living(here->query_info()),"\t" + capitalize(item) + " contains:\n");
        }
        max = 20;
        ob = first_inventory(ob);
        while (ob && max > 0) {
            string sh;
            sh = call_other(ob, "short");
            if (sh)
                tell_object(find_living(here->query_info()),sh + ".\n");
            ob = next_inventory(ob);
            max -= 1;
        }
        return 1;
    }
    tell_object(find_living(here->query_info()),"Look AT something, or what?\n");
    return 1;
}

query_npc()  {
        return 0;
        }

query_pl_k()  {
        return 0;
        }

attack_object(obj)  {
        return 1;
        }

attacked_by(obj)  {
        return 1;
        }

fol()  {
        object who;
        object next,prox;
        if(!present(here->query_info(),here))
                {
                who=find_living(here->query_info());
                move_object(here,environment(who));
                move_object(who,here);
                }
        next=first_inventory(here);
while(next)  {
        prox=next_inventory(next);
                if((next->query_npc() || next->query_interactive()) && next!=find_living(here->query_info()))
        move_object(next,environment(environment(here)));
                next=prox;
}
	if(!call_other(find_living(here->query_info()),"query_interactive"))  {
		move_object(find_living(here->query_info()),environment(here));
		destruct(here);
        	return 1;
	}
        call_out("fol",1);
        return 1;
        }

catch_tell(str)  {
        string arg;
        sscanf(str,capitalize(here->query_info())+"%s",arg);
        if(str)
	{
	  if(arg==" left the game.\n")
	   { 
	     destruct(environment(here));
	     destruct(here);
           }
	  call_other(environment(here),"set_say",arg);
        }
        return 1;
        }
