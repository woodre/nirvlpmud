string desc;
int wc,ac;
reset(arg) {
    if (arg)
	return;
}
short(){return "A curse";}
long(){write("You can't see a curse.\n");}
id(str) {return str == "curse" || str == "item_curse";}
set_wc(w) { wc = w;}
set_ac(a){ ac = a;}
query_wc(){ return wc; }
query_ac(){ return ac;}
