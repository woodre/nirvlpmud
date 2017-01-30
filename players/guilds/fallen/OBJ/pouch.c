inherit "/obj/treasure.c";
#include "../all.h"
int feather, pearl, bone_powder, leaf, root, orb, liquid, gem;
int web, sgem, blossom, geode;

reset(arg){
    if(arg) return;

    /* Inititalize values to 0  */
    feather = 0;        pearl = 0;
    bone_powder = 0;    leaf = 0;
    root = 0;           orb = 0;
    liquid = 0;         gem = 0;
    web = 0;            sgem = 0;
    blossom = 0;        geode = 0;

    set_id("guild_comp_pouch");
    set_alias("pouch");
    set_short("A leather pouch");
    set_weight(1);
    set_save_flag(3);
}

/*  [addition] -Forbin 2005.6.12 made value return pouch + contents value (minus 20%),
				 you will never get more than 1000+random(400) anyway.  */
int query_value() 
{
    return (((400 + (feather * 100) + (bone_powder * 600) + (root * 800) + (liquid * 500) +
	  (web * 400) + (blossom * 1000) + (pearl * 1000) + (leaf * 1000) + (orb * 400) +
	  (gem * 2000) + (sgem * 6000) + (geode * 200)) * 80) / 100);
}

int query_real_value() 
{
    return (400 + (feather * 100) + (bone_powder * 600) + (root * 800) + (liquid * 500) +
      (web * 400) + (blossom * 1000) + (pearl * 1000) + (leaf * 1000) + (orb * 400) +
      (gem * 2000) + (sgem * 6000) + (geode * 200));
}
/*  [end addition] -Forbin 2005.06.02  */

void init(){
    ::init();
    add_action("stock_cmd", "wizstock");
    add_action("merge_cmd", "merge");
}

long(){
    write(
      "This is a leather pouch.  You can use it to hold your spell\n"+
      "components.  It looks rather new, and very well made.\n");
    if(this_player()->query_guild_name() == "fallen")
	write("If you have multiple pouches you can 'merge' them into one.\n"+
	  "You may also store the pouch and its contents in a locker.\n");
    if(!feather && !bone_powder && !root && !liquid && !web && !gem
      && !blossom && !pearl && !leaf && !orb && !sgem && !geode)
	write("The pouch is empty.\n");
    else
	write("The pouch contains:\n\n");
    if(feather > 0)
    {
	if(feather > 1)
	    write("\t* "+feather + " crows feathers.\n");
	else
	    write("\t* "+feather + " crows feather.\n");
    }
    if(pearl > 0)
    {
	if(pearl > 1)
	    write("\t* "+pearl + " black pearls.\n");
	else
	    write("\t* "+pearl + " black pearl.\n");
    }
    if(bone_powder > 0)
    {
	if(bone_powder > 1)
	    write("\t* "+bone_powder + " bags of bone powder.\n");
	else
	    write("\t* "+bone_powder + " bag of bone powder.\n");
    }
    if(leaf > 0)
    {
	if(leaf > 1)
	    write("\t* "+leaf + " black leaves.\n");
	else
	    write("\t* "+leaf + " black leaf.\n");
    }
    if(root > 0)
    {
	if(root > 1)
	    write("\t* "+root + " dark roots.\n");
	else
	    write("\t* "+root + " dark root.\n");
    }
    if(orb > 0)
    {
	if(orb > 1)
	    write("\t* "+orb + " dark orbs.\n");
	else
	    write("\t* "+orb + " dark orb.\n");
    }
    if(liquid > 0)
    {
	if(liquid > 1)
	    write("\t* "+liquid + " bottles of black liquid.\n");
	else
	    write("\t* "+liquid + " bottle of black liquid.\n");
    }
    if(gem > 0)
    {
	if(gem > 1)
	    write("\t* "+gem + " ruby red gems.\n");
	else
	    write("\t* "+gem + " ruby red gem.\n");
    }
    if(web > 0)
    {
	if(web > 1)
	    write("\t* "+web + " spider webs.\n");
	else
	    write("\t* "+web + " spider web.\n");
    }
    if(sgem > 0)
    {
	if(sgem > 1)
	    write("\t* "+sgem + " shadow gems.\n");
	else
	    write("\t* "+sgem + " shadow gem.\n");
    }
    if(blossom > 0)
    {
	if(blossom > 1)
	    write("\t* "+blossom + " ash blossoms.\n");
	else
	    write("\t* "+blossom + " ash blossom.\n");
    }
    if(geode > 0)
    {
	if(geode > 1)
	    write("\t* "+geode + " geodes.\n");
	else
	    write("\t* "+geode + " geode.\n");
    }
    if(feather || bone_powder || root || liquid || web || gem ||
      blossom || pearl || leaf || orb || sgem || geode)
	write("\n");
}

status stock_cmd(){
    if(TP->query_level() < 21) return 0;
    write("You stock your pouch with goodies.\n");
    say(TP->QN+" stocks "+TP->POS+" pouch with goodies.\n");
    feather = random(100);      pearl = 100;
    bone_powder = 100;  leaf = 100;
    root = 100;         orb = 100;
    liquid = 100;	      gem = 100;
    web = 100;          sgem = 100;
    blossom = 100;      geode = random(100);
    write_file("/players/guilds/fallen/log/pouch_stock",
      ctime(time())+" - "+capitalize((string)TP->QRN)+"  "+TP->query_level()+
      "+"+TP->query_extra_level()+"\n");
    return 1;
}

status merge_cmd(string str){
    object *inv, newpouch, x;
    int i, c, size, *quantity;
    if(str != "pouch" && str != "pouches") return 0;
    if(environment(this_object()) != this_player()) return 0;
    if(!present("guild_comp_pouch 2", this_player()))
	return (write("You only have one component pouch.\n"), 1);
    if((string)this_player()->query_guild_name() != "fallen" &&
      this_player()->query_level() < 21)
	return 0;
    inv = all_inventory(this_player());
    i = 0;
    c = 0;
    size = sizeof(inv);
    quantity = ({0,0,0,0,0,0,0,0,0,0,0,0,});
    while(i < size)
    {
	if((x=inv[i]) && (int)x->is_zeus_comp_pouch())
	{
	    c++;
	    quantity[0]  += (int)x->query_feather();
	    quantity[1]  += (int)x->query_pearl();
	    quantity[2]  += (int)x->query_bpowder();
	    quantity[3]  += (int)x->query_leaf();
	    quantity[4]  += (int)x->query_root();
	    quantity[5]  += (int)x->query_orb();
	    quantity[6]  += (int)x->query_liquid();
	    quantity[7]  += (int)x->query_gem();
	    quantity[8]  += (int)x->query_sgem();
	    quantity[9]  += (int)x->query_web();
	    quantity[10] += (int)x->query_blossom();
	    quantity[11] += (int)x->query_geode();
	    if(x != this_object())
		destruct(x);
	}
	i++;
    }

    newpouch = clone_object("/players/guilds/fallen/OBJ/pouch.c");
    newpouch->buy_feather(quantity[0]);
    newpouch->buy_pearl(quantity[1]);
    newpouch->buy_bpowder(quantity[2]);
    newpouch->buy_leaf(quantity[3]);
    newpouch->buy_root(quantity[4]);
    newpouch->buy_orb(quantity[5]);
    newpouch->buy_liquid(quantity[6]);
    newpouch->buy_gem(quantity[7]);
    newpouch->buy_sgem(quantity[8]);
    newpouch->buy_web(quantity[9]);
    newpouch->buy_blossom(quantity[10]);
    newpouch->buy_geode(quantity[11]);

    move_object(newpouch, this_player());
    this_player()->recalc_carry();
    write("You cast a shadow upon the pouches...  "+
      "The "+c+" pouches become 1.\n");
    this_player()->add_weight(-local_weight);
    destruct(this_object());
    return 1;
}

query_feather(){ return feather; }
use_feather(){ feather--; }
buy_feather(int x){ feather += x; }

query_pearl(){ return pearl; }
use_pearl(){ pearl--; }
buy_pearl(int x){ pearl += x; }

query_bpowder(){ return bone_powder; }
use_bpowder(){ bone_powder--; }
buy_bpowder(int x){ bone_powder += x; }

query_leaf(){ return leaf; }
use_leaf(){ leaf--; }
buy_leaf(int x){ leaf += x; }

query_root(){ return root; }
use_root(){ root--; }
buy_root(int x){ root += x; }

query_orb(){ return orb; }
use_orb(){ orb--; }
buy_orb(int x){ orb += x; }

query_liquid(){ return liquid; }
use_liquid(){ liquid--; }
buy_liquid(int x){ liquid += x; }

query_gem(){ return gem; }
use_gem(){ gem--; }
buy_gem(int x){ gem += x; }

query_sgem(){ return sgem; }
use_sgem(){ sgem--; }
buy_sgem(int x){ sgem += x; }

query_web(){ return web; }
use_web(){ web--; }
buy_web(int x){ web += x; }

query_blossom(){ return blossom; }
use_blossom(){ blossom--; }
buy_blossom(int x){ blossom += x; }

query_geode(){ return geode; }
use_geode(){ geode--; }
buy_geode(int x){ geode += x; }


int is_zeus_comp_pouch() { return 1; }

/*  [addition] -Forbin 2005.6.12 to support saving.  */
string locker_arg() { 

    return "&F&"+feather+"&BP&"+bone_powder+"&R&"+root+"&L&"+liquid+"&W&"+web+"&B&"+blossom+"&P&"+pearl+
    "&LF&"+leaf+"&O&"+orb+"&G&"+gem+"&SG&"+sgem+"&GE&"+geode+"";	
}

void locker_init(string arg) { 
    int t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12;
    sscanf(arg, "&F&%d&BP&%d&R&%d&L&%d&W&%d&B&%d&P&%d&LF&%d&O&%d&G&%d&SG&%d&GE&%d", t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12);
    feather = t1;        pearl = t7;
    bone_powder = t2;    leaf = t8;
    root = t3;           orb = t9;
    liquid = t4;         gem = t10;
    web = t5;            sgem = t11;
    blossom = t6;        geode = t12;
}

status restore_thing(string arg) { 
    restore_object(arg); 
    return 1; 
}

status save_thing(string arg) { 
    save_object(arg); 
    return 1; 
}

status generic_object() { 
    return 1; 
}
/*  [end addition] -Forbin 2005.06.02  */
