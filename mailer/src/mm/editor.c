/*
 * MELKONIAN Marc - 13410425
 * editor.c - Manage external editor to compose/reply to e-mails
 * Date: 04 May 2015
 */

#include "editor.h"

/* static functions */
static char* create_tmp_file(email* em);
static char* get_editor_path();
static char* reply_subject(char* s);
static char* reply_text(email* em);
static char* reply_date(char* date);

/* Get editor executable path */
static char*
get_editor_path()
{
        int sz = 256;
        char* path = malloc(sz);
        if (!path) {
                return NULL;
        }

        FILE* F = popen("which vi", "r");
        if (!F) {
                return NULL;
        }
        fgets(path, sz, F);
        path[strlen(path)-1] = '\0';
        pclose(F);
        return path;
}

/* Format a subject for a reply */
static char*
reply_subject(char* s)
{
        const char* pre = "Re: ";
        char* res = malloc(strlen(s) + strlen(pre) + 1);
        memset(res, 0, strlen(s)+strlen(pre)+1);
        if (!res) {
                return NULL;
        }
        sprintf(res, "%s%s", pre, s);
        return res;
}

/* Format the content of an e-mail for a reply */
static char*
reply_text(email* em)
{
        char* re_date = reply_date(em->header->date);
        char* re_content = str_replace(em->text, "\n", "\n| ");
        char* template = "On ,  wrote:\n| ";
        char* from = em->header->from;

        char* res = calloc(strlen(re_date) + strlen(re_content) +
                           strlen(template) + strlen(from) + 1, 1);
        if (!res) {
                return NULL;
        }

        sprintf(res, "On %s, %s wrote:\n| %s", re_date, from, re_content);

        return res;
}

/* Format the date for a reply */
static char*
reply_date(char* date)
{
        return substr(date, 4, strlen(date) - 11); /* strip GMT offset */
}

/* Create an unique temporary file in /tmp */
static char*
create_tmp_file(email* em)
{
        int fd;
        char tmp[] = "/tmp/tmp_XXXXXX";
        fd = mkstemp(tmp);

        if (fd == -1) {
                return NULL;
        }

        char* nm = malloc(strlen(tmp));
        if (!nm) {
                return NULL;
        }

        strncpy(nm, tmp, strlen(tmp));

        FILE* F = fopen(nm, "w");
        if (!F) {
                return NULL;
        }

        if (em != NULL) {
                char* re_subj = reply_subject(em->header->subject);
                char* re_content = reply_text(em);
                fprintf(F, "RECIPIENT:%s\nSUBJECT:%s\n%s\n%s",
                        em->header->from,
                        re_subj,
                        EMAIL_COMPOSE_SEPARATOR,
                        re_content);
                free(re_subj);
                free(re_content);
        } else {
                fprintf(F, "RECIPIENT:\nSUBJECT:\n%s\n",
                        EMAIL_COMPOSE_SEPARATOR);
        }

        fclose(F);
        return nm;
}

/*
 * Launch editor and write an e-mail by editing a temporary file
 * TODO: manage reply message (populate subject, recipient(s)…)
 */
char*
compose_message(email* em)
{
        int status, t;
        pid_t pid;
        FILE* F;
        char* filenm, * content;

        filenm = create_tmp_file(em);
        if (!filenm) {
                return NULL;
        }

        pid = fork();

        if (pid < 0) {          /* fork failure */
                perror("fork");
                return NULL;
        } else if (pid == 0) {  /* child */
                char* path = get_editor_path();
                if (!path) {
                        return NULL;
                }

                t = execl(path, "vi", filenm, (char*)NULL);
                free(path);
                if (t == -1) {
                        return NULL;
                }
        } else {                /* parent */
                t = waitpid(pid, &status, 0);
                if (t != pid) {
                        return NULL;
                }

                F = fopen(filenm, "r");
                if (F == NULL) {
                        fprintf(stderr, "Cannot open file: %s\n", filenm);
                        return NULL;
                }

                fseek(F, 0, SEEK_END);
                long f_sz = ftell(F);
                fseek(F, 0, SEEK_SET);

                content = malloc(f_sz + 1);
                fread(content, f_sz, 1, F);
                fclose(F);

                content[f_sz] = '\0';

                return content;
        }
        return NULL;
}

#ifdef DEBUG
int
main()
{
        char* path = get_editor_path();
        printf("Editor path: %s\n", path);
        free(path);

        char* s = "Mon sujet";
        char* s2 = reply_subject(s);
        printf("reply_subject: %s => %s\n", s, s2);
        free(s2);

        char* content = compose_message(NULL);
        printf("Email content:\n%s\n", content);
        free(content);
        return 0;
}
#endif
