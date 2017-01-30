dest_all(str) {
   object *people;
   int n, size;
   people = users();
   n = 0;
   size = sizeof(people);
   while(n < size) {
      while(present("rock", people[n])) destruct(present("rock", people[n]));
      n++;
   }
   write("Done.\n");
}
