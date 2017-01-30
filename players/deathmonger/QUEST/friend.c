
id(str){ return str == "friend" || str == "symbol"; }
query_save_flag(){ return 1; }
short(){ return "Symbol of Friendship of the Myconids"; }
long(){
write("Written in some odd fungal writing is: This is our friend.\n");
}
get(){ return 1; }
drop(){ destruct(this_object()); return 1; }
