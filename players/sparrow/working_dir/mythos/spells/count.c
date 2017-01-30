int con;

id(str) { return str == "count"; }
drop() {return 1;}
get() { return 0;}

set_count(n) { con = n;}
query_count() { return con; }
