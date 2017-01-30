
string short, long, type;

id(str){ return str == "poison" || str == "bottle" ||
                str == short || str == type; }
short(){ return "Bottle of "+short+" poison"; }
long(){ write(long); }

set_short(str){ short = str; }
set_long(str){ long = str; }
set_poison_type(str){ type = str; }
query_poison_type(){ return type; }
/* Make a function called 'activate', no args, to do your dirty work */
