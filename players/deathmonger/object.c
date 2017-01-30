
string name, short_desc, long_desc;

id(str){ return str == name; }

set_name(str){ name = str; }
set_short(str){ short_desc = str; }
set_long(str){ long_desc = str; }


short(){ return short_desc; }
long(){
   write(long_desc);
}
