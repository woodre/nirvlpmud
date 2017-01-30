int flag;
int num;
object obj,newobj;
object env;
string strq; 
string strp; 
id(str) { return str == "dynamite"; }

reset() {
strq="You can prime it. Run away after you do it!"; 
strp="A bunch of dynamite";
num=5;
flag=1;
}

long() { write("This is a bunch of dynamite.\n"+
"\n                __________  \\ /\n"+
"               ()__T_N_T__)--* -\n"+
"                            / \\ \n"+
strq+"\n"); }

short() { return strp;}

init() {
     add_action("prime", "prime");
}

pil()  {
	string str;
	if(num == 0)   {
   		tell_room(env,"The dynamite explodes!\nYou are smashed to the ground and something hits you hard!\n");
		call_other(this_object(),"boom",);
                }
        else    {
                tell_room(env,".."+num+"..\n");
    		strp="A bunch of primed dynamite (left: "+num+" seconds)";
  		--num;
		}
        call_out("pil",1);
}

boom()   {
	object ppl,ppl1;
	move_object(this_object(),obj);
	ppl = first_inventory(env);
		while(ppl) {
			ppl1 = next_inventory(ppl);
			if(ppl==obj)
				ppl->hit_player(30);
			else if((ppl->query_npc()==1) || ((ppl->query_pl_k()==1) && (obj->query_pl_k()==1)))
				{
				call_other(obj,"attacked_by",ppl);
				ppl->hit_player(30);
				}
    			ppl = ppl1;
    			}
                destruct(this_object());
}

prime (arg) {
        if ((arg != "dynamite") || (num<5)){
                notify_fail("What do you want to prime?\n");
                return 0;
                }
    env=environment(this_player());
    newobj=this_object();
    tell_room(env,call_other(this_player(),"query_name")+" primed the dynamite! Run away! You'll be hit in...\n");
    strq="It's been primed by "+call_other(this_player(),"query_name")+". Run away!!";
    obj=this_player();
    command("drop dynamite",this_player());
    flag=0;
    call_out("pil",1);
    return 1;
}

get() { return flag; }

query_weight() { return 0; }

query_value() { return 1000; }

drop() { return 0; }

