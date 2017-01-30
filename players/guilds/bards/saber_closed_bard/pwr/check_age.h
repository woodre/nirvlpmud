/*
 * Age check
 *
 */

check_age(str)  {
int a;

  if(!str)   a = TP->query_age();
  else a = find_player(str)->query_age();

  if(a/43200)  {
  write(a/43200 +" days ");
  a = a - (a/43200)*43200;
        }
  if(a/1800)  {
  write(a/1800 +" hours ");
  a = a - (a/1800)*1800;
        }
  if(a/30)  {
  write(a/30 +" minutes ");
  a = a - (a/30)*30;
        }
  write(a*2 +" seconds\n");
        }
