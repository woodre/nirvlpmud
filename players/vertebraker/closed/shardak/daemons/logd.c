/*
 * Shardak guild (tm) Dragnar/John
 * Log master by Balowski, April 8th '95
 * Initial revision
 * Logging device for rudimentary security with tasks
 * rewritten to work for verte
 */
#include "../def.h"
#define ERROR (LOGDIR + "error")
#define LOG (LOGDIR + "note")

status
log_task(int task, object by_ob)
{
    string          head, by, who;
    string          wiz;

    head= "log_task() in quest master: ";

    /* determine name of beneficiary */
    who= (string) environment(previous_object())->query_real_name();

    /* determine name of benefactor */
    if (by_ob->is_player())
	by= (string) by_ob->query_real_name();
    else
	by= file_name(by_ob);

    if (!sscanf(file_name(by_ob), "players/%s/", wiz) || 
	(wiz != "vital" && wiz != "balowski" && wiz != "dragnar" && wiz != "vertebraker")) {
	write_file(ERROR, head + "Illegal solve. " + by + "\t-> " + who +
		   "\ttask " + task + "\n");
	return 0;
    }
    write_file(LOG, head + "Task " + task + " solved by " + who + "\n");
    return 1;
}
