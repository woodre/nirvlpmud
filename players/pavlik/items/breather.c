inherit "obj/armor";
int hooked, air;
reset(arg){
 ::reset(arg);
 if(arg) return;
 set_short("A breathing apparatus");
 set_long(
 "A heavy iron helmet with a circular glass visor.  The bowl shaped helmet\n"+
 "has several long hoses protruding from the top.\n");
 set_ac(0);
 set_weight(3);
 set_value(1500);
 set_alias("apparatus");
 set_name("breathing apparatus");
 set_type("helmet");
 hooked = 0; air = 10;
}

set_hooked(h){ hooked = h; }
query_hooked(){ if(!worn) hooked = 0; return hooked; }
set_air(i){ air = i; }
add_air(i){ air += i; if(air > 20) air = 20; }
query_air(){ return air; }
