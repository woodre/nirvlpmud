/*
 * Shardak guild (tm) Dragnar/John
 * Log master by Balowski, April 8th '95
 * Initial revision
 * Logging device for rudimentary security with tasks
 */
#define ERROR "/players/dragnar/guild/log/error"
#define LOG "/players/dragnar/guild/log/note"

status
log_task(int task, object by_ob)
{
    string	    head, by, who;
    string	    wiz;

    head= "log_task() in quest master: ";

    /* determine name of beneficiary */
    who= (string) environment(previous_object())->query_real_name();

    /* determine name of benefactor */
    if (by_ob->is_player())
	by= (string) by_ob->query_real_name();
    else
	by= file_name(by_ob);

    if (!sscanf(file_name(by_ob), "players/%s/", wiz) || 
	(wiz != "balowski" && wiz != "dragnar")) {
	write_file(ERROR, head + "Illegal solve. " + by + "\t-> " + who +
		   "\ttask " + task + "\n");
	return 0;
    }
    write_file(LOG, head + "Task " + task + " solved by " + who + "\n");
    return 1;
}
